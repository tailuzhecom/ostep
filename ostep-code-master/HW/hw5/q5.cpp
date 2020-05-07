#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

int main() {
    int rc = fork();
    if (rc < 0) {
        cout << "fork failed" << endl;
    }
    else if (rc == 0) {
       int pid1 = wait(NULL);
       printf("child: %d\n", pid1);
    }
    else {
        int pid2 = wait(NULL);
        printf("parent: %d\n", pid2);
    }

    return 0;
}
