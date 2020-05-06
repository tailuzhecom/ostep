#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

int main() {
    int fd[2];
    if (pipe(fd) < 0) {
        cout << "pipe failed" << endl;
        exit(1);
    }
    int rc1 = fork();

    if (rc1 < 0) {
        cout << "fork failed" << endl;
    }
    else if (rc1 == 0) {
        close(fd[1]);
        char buf[1024];
        read(fd[0], buf, sizeof(buf));
        cout << "process 1: " << buf << endl;
    }
    else {
        int rc2 = fork();
        if (rc2 < 0) {
            cout << "fork failed" << endl;
        }
        else if (rc2 == 0) {
            close(fd[0]);
            string s = "hello from process 2";
            write(fd[1], s.c_str(), s.length());
        }
    }
    return 0;
}
