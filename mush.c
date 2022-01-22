#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h>

#define MAX_CHARACTERS 2048
#define MAX_WORDS 128

int main(int argc, char *argv[]) {
    for(;;) { 
        printf("isnide23:");

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
            printf("command string %d: %s\n", i, command_string[i]);
            i++;
        }

        printf("%s\n", command_string[i]);

        execvp(command_string[0], command_string);

        printf("This line shouldn't printed if execvp() runs correctly\n");
        return 0;
    }

    return 0;
}