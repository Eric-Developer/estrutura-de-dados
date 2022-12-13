
#include <malloc.h>
#include <stdlib.h>
#include"combinacoes.h"
#include <stdio.h>
int insereFila(Fila* fila,int valor) {
                if (fila == NULL)
                    return 0;   
                                   
 Lista* node = (Lista*) malloc(sizeof(Lista));
 
 if (node == NULL)
    return 0;
    node -> i = valor;
    node -> proximo = NULL;
    if(fila -> Fim == NULL)
    fila -> Inicio = node;

 
   else
    fila -> Fim -> proximo = node;
    fila -> Fim = node;
    return 1; 
                }
 int removeFila(Fila* fila){
    if (fila == NULL)
    return 0;
    if(fila ->Inicio == NULL)
    return 0;
    Lista* node = fila -> Inicio;
    fila -> Inicio = fila -> Inicio -> proximo;
    if(fila ->Inicio == NULL)
    fila ->Fim = NULL;
    free(node);
    return 1;
 }
               
 Fila* criaFila(){
    Fila* fila = (Fila*) (malloc)(sizeof(Fila));
    if (fila != NULL){
    fila -> Inicio = NULL;
    fila -> Fim = NULL;
    }
    return fila;
 }
  void combinacaoDeFilaAlternada(Fila* fila1,Fila* fila2){
    if(fila1 == NULL || fila2 == NULL)
    return;
    Lista* nodeOne = fila1 ->Inicio;
    Lista* nodeTwo = fila2 ->Inicio;
    Lista* auxiliar;
    while(nodeOne != NULL && nodeTwo != NULL ){
        auxiliar = nodeOne ->proximo;
        nodeOne -> proximo = nodeTwo;
        nodeOne = auxiliar;
        auxiliar = nodeTwo -> proximo;
        nodeTwo -> proximo = nodeOne;
        nodeTwo = auxiliar;
    }
fila1 -> Fim = nodeTwo; 
  }


int filaVazia(Fila* fila){
    if(fila == NULL)
    return 1;
    if(fila ->Inicio == NULL)
    return 1;
return 0;
}


 int main(void){

    Fila* fila1 = criaFila();
    Fila* fila2 = criaFila();
   insereFila(fila1 ,1);
   insereFila(fila1 ,2);
    insereFila(fila2 ,3);
    insereFila(fila2 ,4);
    combinacaoDeFilaAlternada(fila1,fila2);
    printf("FILA:");
    while(! filaVazia(fila1) ){
    printf("%d ",fila1 -> Inicio ->i);
    removeFila(fila1);
    
   

    return 0;
 }  