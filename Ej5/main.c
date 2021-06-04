#include <stdlib.h>
#include <stdio.h>
#define max 20


int main(){


    return 0;
}

/*Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice*/


int gradoSalida(int matriz[][max],int vertice,int orden){
    int cuenta=0;
    //tengo que contar los no nulos de la fila del vertice
    for(int i=0;i<orden;i++)
        if (matriz[vertice-1][i]!=0) //vertice-1 porque arranco a contar desde cero en la matriz
            cuenta++;

    return cuenta;
}

int gradoEntrada(int matriz[][max],int vertice,int orden){
    int cuenta=0;
    //cuento no nulos de la columna del vertice
    for(int i=0;i<orden;i++)
        if (matriz[i][vertice-1]!=0)
            cuenta++;

    return cuenta;
}

int gradoTotal(int matriz[][max],int vertice,int orden){
    return (gradoEntrada(matriz,vertice,orden)+gradoSalida(matriz,vertice,orden)-(matriz[vertice-1][vertice-1]!=0));
} //sumo gr entrada y gr salida pero sustraigo los bucles, porque sino se cuentan duplicados
