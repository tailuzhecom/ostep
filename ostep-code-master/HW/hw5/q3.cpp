#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

using namespace std;

int main() {
    int rc = fork();
    if (rc < 0) {
        cout << "fork failed" << endl;
    }
    else if (rc == 0) {
       printf("hello\n");
    }
    else {
       sleep(1);
       printf("goodbye\n");
    }
    return 0;
}
