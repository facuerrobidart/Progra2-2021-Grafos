#include <stdlib.h>
#include <stdio.h>
#define max 20
int main(){

    return 0;
}

/* Desarrollar funciones recursivas para:
a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.
b) hallar el vértice con el mayor grado de salida, en un digrafo representado por una matriz
de adyacencia.
c) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia.
d) determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia
(triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).
e) generar un vector de registros con grado y vértice para aquellos vértices, de un grafo
almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3.*/

void generaArreglo(int matriz[][max],int grados[],int i,int j,int orden){ //i,j entran con orden-1
    if (i>=0 && j>=0){
        if (matriz[i][j]){
            grados[i]++; grados[j]++; //como solo recorro el triangulo superior tengo que sumar grado de i y de j
        }
        if (i==j) //si estoy parado sobre la diagonal, comienzo la fila de arriba 
            generaArreglo(matriz,grados,i-1,orden-1,orden);
        else //si no, me desplazo a la izquierda en la misma fila
            generaArreglo(matriz,grados,i,j-1,orden);
    }
}

int gradoSalida(int matriz[][max],int vertice,int j){ //j entra con orden-1
    if (j>=0) //debo recorrer la fila del vertice
        if (matriz[vertice-1][j])
            return 1+gradoSalida(matriz,vertice,j-1);
        else
            return gradoSalida(matriz,vertice,j-1);
    else
        return 0;
}

int gradoEntrada(int matriz[][max],int vertice,int i){//i entra con orden-1
    if (i>=0)
        if (matriz[i][vertice-1])
            return 1+gradoEntrada(matriz,vertice,i-1);
        else
            return gradoEntrada(matriz,vertice,i-1);
    else
        return 0;
}