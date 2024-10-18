cmake_minimum_required(VERSION 3.10)
project(MyConsoleUtility)

set(SOURCES
	main.c 
	users.c 
	processes.c 
	help.c 
	log.c 
	redirect_errors.c 
	users.h 
	processes.h 
	help.h 
	log.h 
	redirect_errors.h
)
# Добавляем исполняемый файл
add_executable(my_console_utility ${SOURCES})

