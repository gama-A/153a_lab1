#include <stdio.h>
#include <stdlib.h>
#include "cache_model.h"

int main(int argc, char* argv[]) {

    cm_init();

    int ques = atoi(argv[1]); // 1 is part a, 2 is part b
    int cache_status = atoi(argv[2]);
    int cycles, address;
    if(ques == 1) {
        if(cache_status == 0) {
            cm_disable_cache();

            address = rand_int(CM_ADDRESS_SPACE_SIZE);

            cm_do_access(address);

            cycles = cm_get_last_access_cycles();

            printf("access cycles: %i\n", cycles);
        }
        else if(cache_status == 1) {
            cm_enable_cache();

            address = rand_int(CM_ADDRESS_SPACE_SIZE);

            cm_do_access(address);

            cycles = cm_get_last_access_cycles();

            printf("access cycles: %i\n", cycles);
        }
    }
    else if(ques == 2) {
        float p = 0.05;
        if(cache_status == 0) {
            cm_disable_cache();

            address = rand_int(CM_ADDRESS_SPACE_SIZE);

            cm_do_access(address);

            cycles = cm_get_last_access_cycles();

            printf("access cycles: %i\n", cycles);
        }
        else if(cache_status == 1) {
            cm_enable_cache();

            address = rand_int(CM_ADDRESS_SPACE_SIZE);

            cm_do_access(address);

            cycles = cm_get_last_access_cycles();

            printf("access cycles: %i\n", cycles);
        }

    }
    else if(ques == 3) {
        if(cache_status == 0) {
            for(int i = 0; i < 1000; i++) {
                cm_disable_cache();

                address = rand_int(CM_ADDRESS_SPACE_SIZE);

                cm_do_access(address);

                cycles += cm_get_last_access_cycles();
            }
            printf("average access cycles: %i\n", cycles/1000);
        }
        else if(cache_status == 1) {
            for(int i = 0; i < 1000; i++) {
                cm_enable_cache();

                address = rand_int(CM_ADDRESS_SPACE_SIZE);

                cm_do_access(address);

                cycles += cm_get_last_access_cycles();
            }
            printf("average access cycles: %i\n", cycles/1000);
        }

    }

    return(0);
}