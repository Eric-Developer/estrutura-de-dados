#include<stdlib.h> 
#include<stdio.h> 
#include<string.h> 
 #define MAX 150
  struct pilha {
    int topo;
    float vetor[MAX];
  };
  typedef struct pilha Pilha;
  
 Pilha* cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
 }
  
 void insere (Pilha* p ,float v){
    if (p -> topo == MAX){
        printf("estouro de pilha");
        exit(1);
    }
    p -> vetor [p-> topo ] = v;
    p -> topo++;

 }
 int vazia (Pilha* p){
    return(p->topo == 0);
 }
  
  
 float retira (Pilha* p){
    float v;
    if(vazia(p)){
        printf("a pilha está vazia");
        exit(1);
    }
    v = p -> vetor [p-> topo -1];
    p -> topo --;
    return v;
 }
  
  
void libera (Pilha* p){
    free(p);
}
  
 struct calculadora{
    char x[30];
    Pilha* p;
 };
 typedef struct calculadora Calculadora;

  Calculadora* cria_calculadora(char* sinal){
    Calculadora* c = (Calculadora*) malloc(sizeof(Calculadora));
    strcpy(c->x, sinal);
    c -> p = cria();
    return c;
  }

void imprime (Calculadora* t){
    printf("%.02f",t->p->vetor[t->p->topo -1]);
}
 
  void operando(Calculadora* c, float v){
    insere(c->p,v);
    
  }
  
 
//printf(c->f,v); 
 void operador(Calculadora* c, char operacao){
    float valor1, valor2, res;
    if(vazia(c->p)){
        valor2 = 0.0;
    }
    else{
        valor2 = retira(c->p);
        }
        if(vazia(c->p)){
            valor1 = 0.0;
        }
        else{
            valor1 = retira(c->p);
        }
        switch (operacao){
        case '+':
        res = valor1 + valor2;
            break;
        case '-':
        res = valor1 - valor2;

        break;
        case '*':
        res = valor1 * valor2;
        break;
        case'/':
        res = valor1 / valor2;
        break;
        
        }
insere(c->p,res);
    }
 void libera_calculadora(Calculadora* c){
    libera(c->p);
    free(c);
 }
  
 
 /* int main(void){
    char c;
    float v;
    Calculadora* calculadora;
    calculadora = cria_calculadora("%.2f");
    do {
printf("digite");
scanf(" %c",&c);

 if (c ==  '+' || c == '-' || c == '*' || c == '/'){
    operador(calculadora,c);

 }

else{
   ungetc(c,stdin);
printf("informe:");
 scanf("%f",&v);
operando(calculadora,v);
}


    }
    while(c!= ';');
imprime(calculadora);
libera_calculadora(calculadora);
return 0;

    }*/
  
  int main(){
    int opcao1 = 0;
    float valor = 0;
    char operador = ' ';
    Calculadora *calc = cria_calculadora("%2.f");

    do{

        printf("\nopcao:");
            scanf("%d",&opcao1);
        switch(opcao1){
            case 1:
            printf("valor:");
            scanf("%f",&valor);
            operando(calc,valor);
            break;
            case 2:
            printf("operador:");
            scanf("\n%c",&operador);
            operando(calc,operador);
            break;
            case 3:
            imprime(calc);
            libera_calculadora(calc);
        }

    }
    while(opcao1 != 0);
return 0;
  }
