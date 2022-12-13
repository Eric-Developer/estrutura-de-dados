
struct list{
    int n;
    struct list *anterior;
    struct list *proximo;
};


typedef struct list Lista;
 
struct row{
    Lista *inicio;
    Lista *FIM;

};
typedef struct row Fila;
void imprimeFila(Fila* fila);

void inserirInicio(Fila *fila, int num);

Fila* criaFila();

void converter(Fila *fila, int num);
Lista *iniciar (Lista *inicio, int num);
  
  
  
  
  
  
  
  
  
  
  
  
