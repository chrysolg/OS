#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Signal received: %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        sleep(1);
        kill(getppid(), SIGUSR1);
    } else {
        signal(SIGUSR1, handler);
        pause();
        printf("Parent process handling signal\n");
    }
    return 0;
}
