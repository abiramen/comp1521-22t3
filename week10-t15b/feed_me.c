#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define LINE_LEN 1024

void *thread_run(void *data) {
    while (1) {
        printf("Feed me input!\n");
        sleep(1);

    }

}

int main(void) {


    // TODO: create a thread
    
    pthread_t msg_thread;


    pthread_create(
        &msg_thread,
        NULL,
        thread_run,
        NULL
    );


    // TODO: print out lines
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, stdin) != NULL) {
        printf("You entered: %s", line);
    }


    pthread_cancel(msg_thread);

    return 0;
}
