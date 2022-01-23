#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h>

#define MAX_CHARACTERS 2048
#define MAX_WORDS 128

void run_command(char* command_string[]) {
    pid_t pid = fork(); 
  
    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execvp(command_string[0], command_string)) {
            perror("exec");
        }
        exit(0);
    } else {
        wait(NULL); 
        return;
    }   
}

int main() {
    for(;;) { 
        printf("isnide23:");

        char buf[MAX_CHARACTERS];
        char* command_string[MAX_WORDS];
        int i = 0;

        fgets(buf, MAX_CHARACTERS, stdin);
        char* token = strtok(buf, " \t\n\r");
        while (token != NULL) {
            command_string[i] = token;
            i++;
            token = strtok(NULL, "  \t\n\r");
        }

        command_string[i] = NULL;
        i = 0;

        if (strcmp(command_string[0], "cd") == 0) {
            if (chdir(command_string[1]) == -1) {
                perror("Error: ");
            }
        }
        else if (strcmp(command_string[0], "exit") == 0){
            exit(0);
        }    
        else {
            run_command(command_string);
        }
    }

    return 0;
}