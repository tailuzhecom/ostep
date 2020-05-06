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
       char *myargs[2];
       myargs[0] = strdup("/bin/ls");
       myargs[1] = NULL;
       execvp(myargs[0], myargs);
    }
    else {
        wait(NULL);
    }

    return 0;
}
