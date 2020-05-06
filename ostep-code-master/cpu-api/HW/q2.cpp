#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

using namespace std;

int main() {
    int fd = open("./q2.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd < 0) {
        cout << "create file failed" << endl;
        exit(1);
    }

    int rc = fork();
    if (rc < 0) {
        cout << "fork failed" << endl;
    }
    else if (rc == 0) {
        string s = "child write";
        if (write(fd, s.c_str(), s.length()) < 0) {
            cout << "child write failed" << endl;
        }
    }
    else {
        string s = "parent write";
        if (write(fd, s.c_str(), s.length()) < 0) {
            cout << "parent write failed" << endl;
        }
    }
    close(fd);
    return 0;
}
