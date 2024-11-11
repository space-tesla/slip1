Q.2) Write a C program to send SIGALRM signal by child process to parent process and parent process make a provision to catch the signal and display alarm is fired. (Use Kill, fork, signal and sleep system call)

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int sig) {
    printf("Alarm is fired!\n");
}

int main() {
    pid_t pid;

    signal(SIGALRM, alarmHandler);

    pid = fork();

    if (pid > 0) {
        sleep(2); 
        kill(pid, SIGALRM); 
        wait(NULL);
    } else if (pid == 0) {
        sleep(1); 
        _exit(0); 
    }

    return 0;
}

Output:
Alarm is fired!
