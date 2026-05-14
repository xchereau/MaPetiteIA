rmdir /S /Q Build 2>nul

mkdir Build

:: compiler les fichiers :
GCC -Wall -Wextra -Iget_mnist_data\ -c main.c -o Build\main.o
GCC -Wall -Wextra -Iget_mnist_data\ -c get_mnist_data\get_mnist_vector.c -o Build\get_mnist_vector.o

:: link files 
gcc Build\main.o Build\get_mnist_vector.o -o Build\MAPETITEIA.exe

:: build project
.\Build\MAPETITEIA.exe