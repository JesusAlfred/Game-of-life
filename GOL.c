/*
Juego de la vida por Jesús Alfredo Navarro Guzmán
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define height 20 //alto de la malla
#define width 20 //ancho de la malla

int **crearMalla(int, int);
void setUpM(**int);
void vistaS(**int);

int main(void){
    int **Malla1, **Malla2;
    Malla1 = crearMalla(width, height);
    Malla2 = crearMalla(width, height);
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
void setUpM(**int M){
    int i, j;
    for(i = 0; i < sizeof(M)/sizeof(*M), i++){
        for(j = 0; j < sizeof(*M)/sizeof(**M), j++){
            M[i][j]=0;
        }
    }
}
void vistaS(**int v){
    int i, j;
    for(i = 0; i < sizeof(M)/sizeof(*M), i++){
        for(j = 0; j < sizeof(*M)/sizeof(**M), j++){
            printf("%i\t", M[i][j]);
        }
        printf("\n");
    }
}