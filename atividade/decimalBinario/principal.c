
#include "conversao.h"
#include <stdio.h>
  
  Fila* criaFila(){
  Fila *fila = (Fila*) malloc(sizeof(Fila));
 fila -> inicio = NULL;
 fila -> FIM = NULL;

   return fila;
  }

    Lista *iniciar (Lista *inicio, int num){
        Lista *auxiliar = (Lista*) malloc(sizeof(Lista));
        auxiliar -> n = num;
        auxiliar -> proximo = inicio;
        auxiliar -> anterior = NULL;
        if(inicio != NULL){
        inicio ->anterior = auxiliar;
        }
        return auxiliar;
    }
    void inserirInicio(Fila *fila, int num){
    fila ->inicio = iniciar(fila ->inicio, num);
    if(fila ->FIM == NULL){ 
        fila -> FIM = fila -> inicio;
    }
  }

void imprimeFila(Fila* fila){
    Lista *auxiliar = fila -> inicio;
    while(auxiliar){
     printf("%d",auxiliar -> n);
auxiliar = auxiliar -> proximo;
    }
}

void converter(Fila *fila, int num){
    int r;
    while(num > 0){
        r = num % 2;
        num = num / 2;
        inserirInicio(fila,r);
        
    }
}

int main(){

    int opcao = 0;
    Fila *fila = criaFila();

do {
    printf("\n[0]para parar");
    printf("\n[1]para converter");
    printf("\nescolha uma opcao:");
    scanf("%d",&opcao);
int numero;
switch(opcao){
case 1:
printf("digite um numero:");
scanf("\n%d",&numero);
converter(fila,numero);
imprimeFila(fila);
break;
case 0:
printf("\nopcao invalida");
break;
}
}
while(opcao != 0);

    return 0;
}