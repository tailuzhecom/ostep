#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        cout << "fork failed" << endl;
        exit(1);
    }
    else if (rc == 0) {
        cout << "child: " << x << endl;
        x = 500;
        cout << "child " << x << endl;
    }
    else {
        wait(NULL);
        cout << "parent: " << x << endl;
        x = 600;
        cout <<  "parent: " << x << endl;
    }
    return 0;
}
