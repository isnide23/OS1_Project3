#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h>

#define MAX_CHARACTERS 2048
#define MAX_WORDS 2048

int main(int argc, char *argv[]) {
    for(;;) { 
        printf("isnide23:\n");

        char buf[MAX_CHARACTERS];
        char* command_string[MAX_WORDS];
        int i = 0;

        fgets(buf, MAX_CHARACTERS, stdin);
        char* token = strtok(buf, " ");
        while (token != NULL) {
            printf("%s\n", token);
            command_string[i] = token;
            i++;
            token = strtok(NULL, " ");
        }

        command_string[i] = NULL;
        i = 0;

        while (command_string[i] != NULL) {
            printf("command string: %s\n", command_string[i]);
            i++;
        }

    }

    return 0;
}