#include <stdlib.h>
#include <stdio.h>
#define max 10
/*Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente*/

int main(){


    return 0;
}

void subyacente(int matriz[][max],int orden){
//en este caso tengo que recorrer la matriz entera debido a que el
//grafo es dirigido y no se puede almacenar en una matriz triangular 
    for(int i=0;i<orden;i++)
        for (int k=0;k<orden;k++){
            if (matriz[i][k]==1 && matriz[k][i]==0)
                matriz[k][i]=1;
        }
}
