#include <stdio.h>
#include <stdlib.h>

void list_processes() {
    FILE *fp = popen("ps -eo pid,comm --sort pid", "r");
    
    if (fp == NULL) {
        perror("Ошибка при выполнении команды");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    
    pclose(fp);
}

