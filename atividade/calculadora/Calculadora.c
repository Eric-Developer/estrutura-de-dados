#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int *p;    
int topo;   
int *base;  
void push (int i);
int pop (void);
 
int main()
{
  int a,b;
  char s[80];
  p = (int ) malloc (MAX*sizeof (int)); 
  if(!p) {
    printf("Erro de alocacao de memoria\n"); exit (1);
    exit(1);
  }
  topo = p;
  base = p+MAX-1;
  printf("Calculadora \n");
  do {
    printf(":");
    gets (s);
    switch (*s) {
      case '+':
        a = pop();
        b = pop();
        printf("%d\n", b+a);
        push(b+a);
        break;
      case '-':
        a = pop();
        b = pop();
        printf("%d\n", b-a);
        push(b-a);
        break;
      case '*':
        a = pop();
        b = pop();
        printf("%d\n", b*a);
        break;
      case '/':
        a = pop();
        b = pop();
        if (a==0) {
          printf("Divisao por 0\n");
          break;
        }
        printf("%d\n", b/a);
        push(b/a);
        break; 
      case '.': 
        a = pop();
        push(a);
        printf("Valor corrente no topo da pilha: %d\n", a); 
        break;
      default:
        push(atoi (s));
    }
  } while (*s!='q');
return 0;
}
void push (int i)
{
  if (p>base) {
    printf("Pilha Cheia\n");
    return;
  } 
  *p = i;
  p++;
}

pop (void) 
{
  p--;
  if (p<topo) {
    printf("Pilha Vazia\n");
    return 0;
  }
  return *p;
}
