/*
Juego de la vida por Jesús Alfredo Navarro Guzmán
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define height 20 //alto de la malla
#define width 20 //ancho de la malla

int **crearMalla(int, int);

int main(void){

}

int **crearMalla(int w, int h){
    int **x, i;
    x = (int**)malloc(w * sizeof(int*));
    if(x == NULL){
        printf("Memeoria insuficiente");
    }else{
        for (i = 0; i < h; i++){
            x[i]=(int*)malloc(sizeof(int));
            if(x[i] == NULL){
                printf("Memeoria insuficiente");
                break;
            }
        }
    }
    return x;
}