#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include "debug.h"
#include "box64context.h"
#include "dynarec.h"
#include "emu/x64emu_private.h"
#include "emu/x64run_private.h"
#include "x64run.h"
#include "x64emu.h"
#include "box64stack.h"
#include "callback.h"
#include "emu/x64run_private.h"
#include "x64trace.h"
#include "dynarec_native.h"
#include "bitutils.h"
#include "rv64_printer.h"
#include "dynarec_rv64_private.h"
#include "dynarec_rv64_functions.h"
#include "dynarec_rv64_helper.h"

uintptr_t dynarec64_660F_vector(dynarec_rv64_t* dyn, uintptr_t addr, uintptr_t ip, int ninst, rex_t rex, int* ok, int* need_epilog)
{
    (void)ip;
    (void)need_epilog;
    uint8_t opcode = F8;
    uint8_t nextop, u8, s8;
    int32_t i32;
    uint8_t gd, ed;
    uint8_t wback, wb1, wb2, gback;
    uint8_t eb1, eb2;
    int64_t j64;
    uint64_t tmp64u, tmp64u2;
    int v0, v1;
    int q0, q1;
    int d0, d1, d2;
    int64_t fixedaddress, gdoffset;
    int unscaled;
    MAYUSE(d0);
    MAYUSE(d1);
    MAYUSE(q0);
    MAYUSE(q1);
    MAYUSE(eb1);
    MAYUSE(eb2);
    MAYUSE(j64);
    switch (opcode) {
        case 0x1F:
            return 0;
        case 0x28:
            INST_NAME("MOVAPD Gx, Ex");
            nextop = F8;
            GETG;
            SET_ELEMENT_WIDTH(x1, VECTOR_SEWANY, 1);
            if (MODREG) {
                ed = (nextop & 7) + (rex.b << 3);
                v1 = sse_get_reg_vector(dyn, ninst, x1, ed, 0, dyn->vector_eew);
                v0 = sse_get_reg_empty_vector(dyn, ninst, x1, gd);
                VMV_V_V(v0, v1);
            } else {
                SMREAD();
                v0 = sse_get_reg_empty_vector(dyn, ninst, x1, gd);
                addr = geted(dyn, addr, ninst, nextop, &ed, x2, x3, &fixedaddress, rex, NULL, 0, 0);
                VLE_V(v0, ed, dyn->vector_eew, VECTOR_UNMASKED, VECTOR_NFIELD1);
            }
            break;
        case 0x38: // SSSE3 opcodes
            nextop = F8;
            switch (nextop) {
                case 0x00:
                    INST_NAME("PSHUFB Gx, Ex");
                    nextop = F8;
                    SET_ELEMENT_WIDTH(x1, VECTOR_SEW8, 1);
                    GETGX_vector(q0, 1, VECTOR_SEW8);
                    GETEX_vector(q1, 0, 0, VECTOR_SEW8);
                    v0 = fpu_get_scratch(dyn);
                    v1 = fpu_get_scratch(dyn);
                    ADDI(x4, xZR, 0b000010001111);
                    VMV_V_X(v0, x4); // broadcast the mask
                    VAND_VV(v0, v0, q1, VECTOR_UNMASKED);
                    VRGATHER_VV(v1, v0, q0, VECTOR_UNMASKED); // registers cannot be overlapped!!
                    VMV_V_V(q0, v1);
                    break;
                case 0x01 ... 0x07:
                    // pairwise opcodes are complicated, fallback to scalar.
                    return 0;
                case 0x08 ... 0x0a:
                    if (nextop == 0x08) {
                        INST_NAME("PSIGNB Gx, Ex");
                        SET_ELEMENT_WIDTH(x1, VECTOR_SEW8, 1);
                        i32 = 7;
                        nextop = F8;
                        GETGX_vector(q0, 1, VECTOR_SEW8);
                        GETEX_vector(q1, 0, 0, VECTOR_SEW8);
                    } else if (nextop == 0x09) {
                        INST_NAME("PSIGNW Gx, Ex");
                        SET_ELEMENT_WIDTH(x1, VECTOR_SEW16, 1);
                        i32 = 15;
                        nextop = F8;
                        GETGX_vector(q0, 1, VECTOR_SEW16);
                        GETEX_vector(q1, 0, 0, VECTOR_SEW16);
                    } else {
                        INST_NAME("PSIGND Gx, Ex");
                        SET_ELEMENT_WIDTH(x1, VECTOR_SEW32, 1);
                        i32 = 31;
                        nextop = F8;
                        GETGX_vector(q0, 1, VECTOR_SEW32);
                        GETEX_vector(q1, 0, 0, VECTOR_SEW32);
                    }
                    v0 = fpu_get_scratch(dyn);
                    v1 = fpu_get_scratch(dyn);
                    // absolute
                    VSRA_VI(v0, i32, q1, VECTOR_UNMASKED);
                    VXOR_VV(v1, v0, q0, VECTOR_UNMASKED);
                    VSUB_VV(v1, v0, v1, VECTOR_UNMASKED);
                    // handle zeroing
                    VMSEQ_VI(VECTOR_MASKREG, 0, q1, VECTOR_UNMASKED);
                    VXOR_VV(v0, v0, v0, VECTOR_UNMASKED);
                    VADC_VIM(v0, 0x1f, v0); // implies VECTOR_MASKREG
                    VAND_VV(q0, v1, v0, VECTOR_UNMASKED);
                    break;
                default:
                    DEFAULT_VECTOR;
            }
            break;
        case 0x6E:
            return 0;
        case 0x6F:
            INST_NAME("MOVDQA Gx, Ex");
            nextop = F8;
            SET_ELEMENT_WIDTH(x1, VECTOR_SEWANY, 1);
            if (MODREG) {
                v1 = sse_get_reg_vector(dyn, ninst, x1, (nextop & 7) + (rex.b << 3), 0, dyn->vector_eew);
                GETGX_empty_vector(v0);
                VMV_V_V(v0, v1);
            } else {
                GETGX_empty_vector(v0);
                SMREAD();
                addr = geted(dyn, addr, ninst, nextop, &ed, x2, x1, &fixedaddress, rex, NULL, 0, 0);
                VLE_V(v0, ed, dyn->vector_eew, VECTOR_UNMASKED, VECTOR_NFIELD1);
            }
            break;
        case 0x7E:
            return 0;
        case 0xEF:
            INST_NAME("PXOR Gx, Ex");
            nextop = F8;
            GETG;
            if (MODREG && gd == (nextop & 7) + (rex.b << 3)) {
                SET_ELEMENT_WIDTH(x1, VECTOR_SEWANY, 1);
                // special case
                q0 = sse_get_reg_empty_vector(dyn, ninst, x1, gd);
                VXOR_VV(q0, q0, q0, VECTOR_UNMASKED);
            } else {
                SET_ELEMENT_WIDTH(x1, VECTOR_SEWANY, 1);
                q0 = sse_get_reg_vector(dyn, ninst, x1, gd, 1, dyn->vector_eew);
                GETEX_vector(q1, 0, 0, VECTOR_SEW8);
                VXOR_VV(q0, q0, q1, VECTOR_UNMASKED);
            }
            break;
        default:
            DEFAULT_VECTOR;
    }

    return addr;
}
