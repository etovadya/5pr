#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log.h"
#include "redirect_errors.h"

void parse_arguments(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--users") == 0) {
            list_users();
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--processes") == 0) {
            list_processes();
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            exit(0);
        } else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--log") == 0) {
            if (i + 1 < argc) {
                redirect_output_to_file(argv[++i]);
            } else {
                fprintf(stderr, "Ошибка: Не указан путь для логирования.n");
            }
        } else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--errors") == 0) {
            if (i + 1 < argc) {
                redirect_errors(argv[++i]);
            } else {
                fprintf(stderr, "Ошибка: Не указан путь для логирования ошибок.n");
            }
        } else {
            fprintf(stderr, "Неизвестный аргумент: %s", argv[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    parse_arguments(argc, argv);
    return 0;
}

