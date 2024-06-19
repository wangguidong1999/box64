#include "core.h"
#include "thpool.h"
threadpool thpool;
int main(int argc, const char **argv, char **env) {

    x64emu_t* emu = NULL;
    elfheader_t* elf_header = NULL;

		//threadpool thpool = thpool_init(2);
		thpool = thpool_init(2);

    if (initialize(argc, argv, env, &emu, &elf_header, 1)) {
        return -1;
    }
		int emulate_ret = emulate(emu, elf_header);

    thpool_wait(thpool);
		thpool_destroy(thpool);

    return emulate_ret;
}
