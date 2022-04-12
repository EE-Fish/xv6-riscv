#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int sleep_sec;

    if (argc != 2)
    {
        fprintf(2, "usage: sleep seconds\n");
        exit(1);
    }

    sleep_sec = atoi(argv[1]);
    if (sleep_sec > 0)
    {
        sleep(sleep_sec);
        exit(0);
    }
    fprintf(2, "Invalid intput\n");
    exit(1);
}