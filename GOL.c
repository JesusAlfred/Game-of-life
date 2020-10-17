/*
Juego de la vida por Jesús Alfredo Navarro Guzmán
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#define height 30 //alto de la malla
#define width 50 //ancho de la malla

int **crearMalla(int, int);
void setUpM(int**);
void vistaS(int**);
void actualizarV(int**, int**);
void pinicial( int **);
void copiarM(int**, int **);
void logica(int **, int **);

int main(void){
    int **Malla1, **Malla2, s=1;
    Malla1 = crearMalla(width, height);
    Malla2 = crearMalla(width, height);
    setUpM(Malla1);
    setUpM(Malla2);
    window(1, 1, width*2, height);
    pinicial(Malla1);
    do{
        if(s==1){
            logica(Malla1, Malla2);
            actualizarV(Malla1, Malla2);
            s=0;
        }else{
            logica(Malla2, Malla1);
            actualizarV(Malla2, Malla1);
            s=1;
        }
        Sleep(100);
    }while(!kbhit());
}

int **crearMalla(int w, int h){
    int **x, i;
    x = (int**)malloc(w * sizeof(int*));
    if(x == NULL){
        printf("Memeoria insuficiente");
        return NULL;
    }else{
        for (i = 0; i < w; i++){
            x[i]=(int*)malloc(h*sizeof(int));
            if(x[i] == NULL){
                printf("Memeoria insuficiente");
                return NULL;
            }
        }
    }
    return x;
}
void setUpM(int **M){
    int i, j;
    for(i = 0; i < width; i++){
        for(j = 0; j < height; j++){
            M[i][j]=0;
        }
    }
}
void vistaS(int **v){
    int i, j;
    system("cls");
    for(i = 0; i < width; i++){
        for(j = 0; j < height; j++){
            printf("%i\t", v[i][j]);
        }
        printf("\n");
    }
}
void actualizarV(int **m1, int **m2){
    int i, j;
    for (i = 0; i < width; i++){
        for (j = 0; j < height; j++){
            if(m2[i][j] != m1[i][j]){
                textcolor(m2[i][j]);
                gotoxy(i*2+1, j+1);
                cprintf("%c%c", 219, 219);
            }
        }
    }
}
void pinicial(int **M2){
    char e;
    int  x=0, y=0, x2 = 0, y2 = 0, lab;
    do{
        e = getch();
        lab = 1;
        switch (e){
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 32:
                if(M2[x][y])
                    M2[x][y] = 0;
                else
                    M2[x][y] = 1;
            default:
                lab = 0;
                break;
        }
        x=(x+(abs(x)-x)*width/2)%width;
        y=(y+(abs(y)-y)*height/2)%height;
        if(lab == 1){
            textcolor(M2[x2][y2]);
            gotoxy(x2*2+1, y2+1);
            cprintf("%c%c", 219, 219);
            textcolor(RED);
            gotoxy(x*2+1, y+1);
            cprintf("%c%c", 219, 219);
            x2 = x;
            y2 = y;
        }
    }while(e != 'q');
    textcolor(M2[x2][y2]);
    gotoxy(x2*2+1, y2+1);
    cprintf("%c%c", 219, 219);
}
void copiarM(int **M1, int **M2){
    int i, j;
    for (i = 0; i < width; i++){
        for (j = 0; j < height; j++){
            M1[i][j] = M2[i][j];
        }
    }
}
void logica(int **m1, int **m2){
    int i, j, ii, jj, contador;
    setUpM(m2);
    for (i=1; i<width-1; i++){
        for (j=1; j< height-1; j++){
            contador = 0;
            for(ii=-1; ii<2; ii++){
                for(jj=-1; jj<2; jj++){
                    if(m1[i+ii][j+jj] == 1)
                        contador++;
                }
            }
            contador-=m1[i][j];
            if(m1[i][j]==0 && contador == 3){
                m2[i][j]=1;
            }
            if(m1[i][j]==1){
                if(contador == 2 || contador ==3){
                    m2[i][j]=1;
                }else{
                    m2[i][j]=0;
                }
            }
        }
    }
}