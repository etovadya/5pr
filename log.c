#include <stdio.h>
#include <unistd.h> // Для dup2

void redirect_output_to_file(const char *path) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        perror("Ошибка при открытии файла для логирования");
        return;
    }
    
    // Перенаправляем stdout
    if (dup2(fileno(file), STDOUT_FILENO) == -1) {
        perror("Ошибка при перенаправлении stdout");
        fclose(file);
        return;
    }
    
    // Закрываем файл, чтобы не было утечки дескрипторов
    fclose(file);
}


