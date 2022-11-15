#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    char *string = data;
    while (1) {
        printf("%s\n", string);
    }
    return NULL;
}

int main(void) {
    // TODO: create a thread

    pthread_t hello_thread;

    pthread_create(
        &hello_thread,      // pointer to a pthread_t
        NULL,               // attributes -> NULL in this course
        thread_run,         // function to execute on the thread
        "Hello"             // argument to the function
    );

    while (1) {
        printf("There\n");
    }

    pthread_cancel(hello_thread);
  

    // TODO: print the main message

    return 0;
}
