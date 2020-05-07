#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstring>
#include <sys/time.h>

using namespace std;

int main() {
    timeval start_tv, end_tv;
    gettimeofday(&start_tv, NULL);
    int n = 1000;
    for (int i = 0; i < n; i++) {
        read(1, NULL, 0);
    }
    gettimeofday(&end_tv, NULL);
    cout << "each system call cost: " << end_tv.tv_sec * 1000000 + end_tv.tv_usec - (start_tv.tv_sec * 1000000 +start_tv.tv_usec) << "us" << endl;
    return 0;
}
