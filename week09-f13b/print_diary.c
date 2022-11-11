/**
 * Write a C program, print_diary.c,
 * which prints the contents of the file $HOME/.diary to stdout.
 * 
 * Be sure to handle any errors!
 * snprintf is a convenient function for constructing the pathname of the diary file.
 * (it's also pretty handy for subset3 of a certain assignment.)
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIARY_PATH "/.diary"


int main(void) {

    char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        return 1;
    }
    

    int path_len = strlen(home_dir) + strlen(DIARY_PATH) + 1;
    char *full_path = malloc(path_len * sizeof(char));


    snprintf(full_path, path_len, "%s%s", home_dir, DIARY_PATH);




    FILE *stream = fopen(full_path, "r");
    if (stream == NULL) {
        perror(full_path);
        exit(1);
    }

    int c;
    while ((c = fgetc(stream)) != EOF) {
        putchar(c);
    }

    fclose(stream);
    return 0;
}
