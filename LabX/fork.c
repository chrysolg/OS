#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child PID: %d\n", getpid());
            break;
        } else {
            printf("Parent PID: %d\n", getpid());
        }
    }
    return 0;
}
