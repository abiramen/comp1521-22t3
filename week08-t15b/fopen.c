#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *stream = fopen(argv[1], "r");

    if (stream == NULL) {
        printf("something went wrong :(, errno %d\n", errno);
        perror(argv[1]);

        return 1;
    }
}



