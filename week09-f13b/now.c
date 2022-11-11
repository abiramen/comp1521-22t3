#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>

char *DATE_PATH = "/usr/bin/date";

extern char **environ;

int main(void) {
    // call posix_spawn to print date +%d-%m-%Y

    pid_t spawn_pid;

    char *spawn_argv[] = {DATE_PATH, "+%d-%m-%Y", NULL};

    if (posix_spawn(
        &spawn_pid,         // Process ID
        DATE_PATH,          // Full path to program
        NULL,               // File actions - can be NULL in this course
        NULL,               // Spawn attributes - NULL in this course
        spawn_argv,         // Arguments to the program, with NULL as the last element
        environ             // Environment variables
    )) {
        perror("posix_spawn");
        return 1;
    }

    int spawn_status;

    if (waitpid(
        spawn_pid,          // Process ID of process we are waiting for
        &spawn_status,      // Status of spawned program when completed
        0                   // Options - 0 in this course
        ) < 0) {
            perror("waitpid");
            return 1;
    }
       

    printf("hello\n");


    // call posix_spawn to print date +%T

    return 0;
}
