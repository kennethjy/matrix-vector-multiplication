gcc -o main.o -c main_test.c
gcc -o mylib.o -c mylib/mylib.c
gcc -Wall -O0 -o main.exe main.o mylib.o
main.exe
del *.o
del *.exe