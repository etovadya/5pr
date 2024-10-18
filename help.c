#include <stdio.h>

void print_help() {
    printf("Использование:n");
    printf("  -u, --users       Вывести список пользователей и их домашние директорииn");
    printf("  -p, --processes   Вывести список запущенных процессовn");
    printf("  -h, --help        Вывести справкуn");
    printf("  -l PATH           Логировать вывод в указанный файлn");
    printf("  -e PATH           Логировать ошибки в указанный файлn");
}

