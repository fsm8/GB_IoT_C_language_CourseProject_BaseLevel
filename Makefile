# Аргументы программы
ARGS1=-h
ARGS2=-f
ARGS3=D:\2_GB\1_3_C.Base\Course_project\Course_project_C_basic_level\temperature_small.csv
ARGS4=-m
ARGS5=11

all: 	prog.exe

prog.exe: main.o functions.o
	gcc -o prog.exe main.o functions.o

main.o : main.c functions.h
	gcc -c main.c -o main.o

functions.o : functions.c functions.h
	gcc -c functions.c -o functions.o 

# Цель запуска программы с аргументами командной строки
run: prog.exe
	prog.exe $(ARGS1) $(ARGS2) $(ARGS3) $(ARGS4) $(ARGS5)
	
clean:
	del /Q *.o *.exe

# стандартные опции команды "del" в Windows, "/Q" для удаления файлов без подтверждения удаления и "/S" для удаления каталогов и их содержимого рекурсивно.
#del -rf *.o *.exe
#Чтобы запустить программу с аргументами командной строки, вы можете выполнить следующую команду в терминале: make run