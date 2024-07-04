#include "core.h"
#include "thpool.h"
#include <time.h>
#include <stdio.h>

threadpool thpool;
double dynarun_time = 0;
double interpreter_time = 0;
double dynarec_time = 0;

int main(int argc, const char **argv, char **env) {

    x64emu_t* emu = NULL;
    elfheader_t* elf_header = NULL;
		clock_t start, end;
		double initialize_time, emulate_time;
		//threadpool thpool = thpool_init(2);
		thpool = thpool_init(2);
		start = clock();
    if (initialize(argc, argv, env, &emu, &elf_header, 1)) {
        return -1;
    }
		end = clock();
		initialize_time = (double)(end - start) / CLOCKS_PER_SEC;

		start = clock();
		int emulate_ret = emulate(emu, elf_header);
		end = clock();
		emulate_time = (double)(end - start) / CLOCKS_PER_SEC;

		printf("initialize: %f seconds\n", initialize_time);
		printf("emulate: %f seconds\n", emulate_time);
		printf("dynarun: %f seconds\n", dynarun_time);
		printf("interpreter: %f seconds\n", interpreter_time);
		printf("dynarec: %f seconds\n", dynarec_time);

    thpool_wait(thpool);
		thpool_destroy(thpool);

    return emulate_ret;
}
