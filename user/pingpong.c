#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int p[2];
    int pid;
    char buf[10];

    pipe(p);
    pid = fork();
    if (pid < 0) {
        fprintf(1, "fork error");
        exit(1);
    }

    if (pid == 0) {
        // this is child
        pid = getpid();
        read(p[0], buf, sizeof(buf));
        fprintf(2, "pid %d received %s\n", pid, buf);
        write(p[1], "pong", 5);
    } else {
        // this is parent
        pid = getpid();
        write(p[1], "ping", 5);
        sleep(10);
        read(p[0], buf, sizeof(buf));
        fprintf(2, "pid %d received %s\n", pid, buf);
    }
    close(p[0]);
    close(p[1]);
    exit(0);
}