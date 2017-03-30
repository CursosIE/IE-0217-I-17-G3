#include "matrix.h"

using namespace std;


/**  @brief Función utilizada, para llevar el programa a un tiempo de espera
 *  definido por el usuario
 * @param time: Cantidad en mili segundos, los cuales el programa
 * estará en espera.
 * */
void wait(unsigned int time)
{
    usleep(time);
}

/**  @brief Esta función limpia la pantalla, eliminando cualquier caracter
 * @param w: Ancho de la terminal
 * @param h: Alto de la terminal
 * */
void clearScreen(int w, int h)
{
    int i,j;
    for(i=0;i<w;i++){
        for(j=0;j<h;j++){
                cout<<" ";
        }
    }
}


/**  @brief Imprime un caracter en pantalla
 * */
void printScreen()
{
    char c=char(rand()%(MAX-MIN + 1) + MIN); ///< caracteres aleatorios, dentro del rango ASCII
    cout<<"\033[1;32m"<<c<<"\033[0m"; // < color verde
}

/**  @brief Función que recorre la terminal
 *  mientras imprime un caracter en cada posición
 * */
void moveScreen()
{
    int w,
        h,
        col,
        col2,
        col3,
        col4,
        col5,
        col6,
        fil;
        col = rand()%win.ws_col;
        col2 = rand()%win.ws_col + 30;  //< constantes para variar el numero de filas
        col3 = rand()%win.ws_col + 15 ;
        col4 = rand()%win.ws_col + 50;
        col5 = rand()%win.ws_col + 10;
        col6 = rand()%win.ws_col + 5;
        for(w=0;w<win.ws_row;w++){
            for(h=0;h<win.ws_col;h++){
                if(h==col  || h == col2 || h==col3 || h==col3 || h==col5 || h==col6){
                printScreen();
            }
            else cout<<" ";
            wait(80);
        }
    }


}

int main(int argc, char *argv[] )
{
      clearScreen(win.ws_row, win.ws_col);
      while(1){
         ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);///< se obtiene las dimensiones de la consola
         moveScreen();
      }
      clearScreen(win.ws_row, win.ws_col);
      return(0);
}
