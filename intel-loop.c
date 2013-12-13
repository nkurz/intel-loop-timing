#include <stdint.h>
#include <stdio.h>

#ifdef IACA
#include </opt/intel/iaca/include/iacaMarks.h>
#else
#define IACA_START
#define IACA_END
#endif

#define LOOP_COUNT (400 * 1000 * 1000)

volatile uint64_t volatile_global_counter = 0; 

#define ASM_LOAD(mem_src, reg_dst)                      \
    __asm volatile("MOV %1, %0"                           \
                 /* writes %0 */ : "=r" (reg_dst)        \
                 /*  reads %1 */ : "m" (mem_src));

#define ASM_STORE(reg_src, mem_dst)                     \
    __asm volatile("MOV %1, %0"                           \
                 /* writes %0 */ : "=m" (mem_dst)        \
                 /*  reads %1 */ : "r" (reg_src));

#define ASM_ADD(num_src, reg_dst)                       \
    __asm volatile("ADD %1, %0"                          \
                  /* writes %0 */ : "+r" (reg_dst)      \
                  /*  reads %1 */ : "ir" (num_src));

void slow_loop_in_c() {
    IACA_START;
    unsigned j;
    for (j = 0; j < LOOP_COUNT; ++j) {
        volatile_global_counter += j;
    }
    IACA_END;
}

void basic_loop_in_c() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        // c += 0  (one or more done in assembly)
        c = volatile_global_counter;
        c += i;
        volatile_global_counter = c;
    }
    IACA_END;
}

void loop_none() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_LOAD(volatile_global_counter, c);
        // ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}

void loop_0() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}

void loop_1() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_ADD(0, c);
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}

void loop_2() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}

void loop_3() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}

void loop_4() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}


void loop_5() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}


void loop_6() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}


void loop_7() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}

void loop_8() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}

void loop_9() {
    IACA_START;
    uint64_t c = 0;
    for (uint64_t i = LOOP_COUNT; i; i--) {
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_ADD(0, c);
        ASM_LOAD(volatile_global_counter, c);
        ASM_ADD(i, c);
        ASM_STORE(c, volatile_global_counter);
    }
    IACA_END;
}
 
 
int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("Usage: %s arg\n", argv[0]);
    } else if (argv[1][0] == 's') {
        slow_loop_in_c();
    } else if (argv[1][0] == 'b') {
        basic_loop_in_c();
    } else if (argv[1][0] == '0') {
        loop_0();
    } else if (argv[1][0] == '1') {
        loop_1();
    } else if (argv[1][0] == '2') {
        loop_2();
    } else if (argv[1][0] == '3') {
        loop_3();
    } else if (argv[1][0] == '4') {
        loop_4();
    } else if (argv[1][0] == '5') {
        loop_5();
    } else if (argv[1][0] == '6') {
        loop_6();
    } else if (argv[1][0] == '7') {
        loop_7();
    } else if (argv[1][0] == '8') {
        loop_8();
    } else if (argv[1][0] == '9') {
        loop_9();
    } else if (argv[1][0] == 'n') {
        loop_none();
    }
    else {
        printf("Arg '%s' not recognized\n", argv[1]);
    }

    return 0;
}
