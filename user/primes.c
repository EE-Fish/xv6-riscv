#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int p_0[2], p_1[2];
    char buf[10];
    int cnt = 0;

    pipe(p_0);
    pipe(p_1);
    
    for (int i = 2; i <= 35; i++) {
        if (checkIsPrime(i) != 0) {
            cnt++;

            //This is child
            if (fork() == 0) {
                int n = read(p_0[0], buf, sizeof(buf));
                if (n == 0) {
                    
                }
            } else {
                write(p_0[1], i, sizeof(buf));
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        wait(0);
    }
    exit(0);
}

int checkIsPrime(int num) {
    if (num < 2) {
        fprintf(2, "error num");
        exit(1);
    }
    for(int i = 2; i < num; i++) {
        if (num % i != 0) {
            return 0;
        }
    }
    return 1;
}