#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main() {
    close(STDOUT_FILENO);
    int fd = open("./test.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    printf("hello world!\n");
    printf("%d\n", fd);
    return 0;
}
