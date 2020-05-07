#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstring>
#include <sys/time.h>
#include <sched.h>

using namespace std;

int main() {
    int pipe1[2], pipe2[2];
    if (pipe(pipe1) < 0) {
        cout << "pipe1 failed" << endl;
        exit(1);
    }

    if (pipe(pipe2) < 0) {
        cout << "pipe2 failed" << endl;
        exit(1);
    }

    cpu_set_t mask;
    CPU_ZERO(&mask);

    CPU_SET(0, &mask);
    int n = 1000;
    int rc = fork();

    if (rc < 0) {
        cout << "fork failed" << endl;
    }
    else if (rc == 0) {
        int child_pid = getpid();
        sched_setaffinity(child_pid, sizeof(mask), &mask);

        read(pipe1[0], NULL, 0);
        write(pipe2[1], NULL, 0);
    }
    else {
        int parent_pid = getpid();
        sched_setaffinity(parent_pid, sizeof(mask), &mask);
        timeval start_tv, end_tv;
        gettimeofday(&start_tv, NULL);
        for (int i = 0; i < n; i++) {
            write(pipe1[1], NULL, 0);
            read(pipe2[0], NULL, 0);
        }
        gettimeofday(&end_tv, NULL);
        cout << "each context switch cost: " << (double)(end_tv.tv_sec * 1000000 + end_tv.tv_usec -
                (start_tv.tv_sec * 1000000 + start_tv.tv_usec)) / n << "us" << endl;
    }
    return 0;
}
