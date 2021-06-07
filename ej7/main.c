#include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct nodo{
    int posicion; //posicion se refiere al indice que tiene ese nodo en el vector de listas
    int peso;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;
typedef struct{
    int nodo; //nodo sería el nombre que se ve en el gráfico: puede ser de cualquier tipo
    TLista adyacentes;
}cabeceras;

int main(){


    return 0;
}

/*7. Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
c) media matriz (triángulo superior)*/

int gradoPorMatriz(int matriz[][max],int vertice,int orden){ //los vertices son numerados: 1,2,3...N
    int grado=0;

    for(int i=0;i<orden;i++){ //todas las filas están completas, cuento solo por la fila
        if (matriz[vertice-1][i])
            grado++;
    }
    return grado;
}

int gradoPorLista(cabeceras lista[],int vertice,int orden){
    int grado=0; TLista aux;
    
    
    if (vertice-1<orden){
        aux = lista[vertice-1].adyacentes;
        while (aux!=NULL)
            grado++;
        return grado;
    }else //si el nodo pedido no existe
        return -1; 
}

int gradoPorTriangulo(int matriz[][max],int vertice,int orden){
    int grado=0;
    if (vertice-1<orden){
        for(int i=0;i<vertice-1;i++)
            if (matriz[i][vertice-1])// me "muevo" por la columna del vertice
                grado++;
        for(int j=vertice-1;j<orden;j++) //me "muevo" por la fila del vertice
            if (matriz[vertice-1][j])
                grado++;
        return grado;
    }else 
        return -1;  
}