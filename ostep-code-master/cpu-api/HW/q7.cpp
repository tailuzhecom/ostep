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
       close(STDOUT_FILENO);
       printf("child print\n");
    }
    else {
        wait(NULL);
    }

    return 0;
}
