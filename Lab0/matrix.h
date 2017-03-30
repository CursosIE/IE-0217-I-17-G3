#include <iostream>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>

struct winsize win; ///< struc para guardar las dimensiones de la terminal
#define MAX 126 ///< valor máximo en 8 bits del ultimo caracter ASCII
#define MIN 32  ///< valor mínimo en 8 bits del primer caracter ASCII

void wait(unsigned int time);

void clearScreen(int w, int h);

void printScreen();

void moveScreen();
