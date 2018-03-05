#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void first(void);
static void second(void);

static jmp_buf exception_env;
static int exception_type;

int main(void) {
    char * volatile mem_buffer = NULL;

    if (setjmp(exception_env)) {

        printf("first failed, exception type: %d\n", exception_type);
    } else {

        puts("calling first");
        first();

        mem_buffer = malloc(300);
        printf("%s\n", strcpy(mem_buffer, "first succeeded"));
    }

    free(mem_buffer);

    return 0;
}

static void first(void) {
    jmp_buf my_env;

    puts("entering first"); /* reached */

    memcpy(my_env, exception_env, sizeof my_env);

    switch (setjmp(exception_env)) {
        case 3:
            puts("second failed, exception type: 3; remapping to type 1");
            exception_type = 1;

        default:
            memcpy(exception_env, my_env, sizeof exception_env);
            longjmp(exception_env, exception_type);

        case 0:
            puts("calling second"); /* reached */
            second();
            puts("second succeeded"); /* not reached */
    }

    memcpy(exception_env, my_env, sizeof exception_env);

    puts("leaving first");
}

static void second(void) {
    puts("entering second" );

    exception_type = 3;
    longjmp(exception_env, exception_type);

    puts("leaving second");
}
