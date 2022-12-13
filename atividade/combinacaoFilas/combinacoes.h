  
struct list{
    int i;
    struct list* proximo;
};
typedef struct list Lista;

struct row {
    Lista *Inicio;
    Lista *Fim;
};
  
 typedef struct row Fila;
  
int insereFila(Fila* fila,int valor);
int removeFila(Fila* fila);
Fila* criaFila();
void combinacaoDeFilaAlternada(Fila* fila1,Fila* fIla2);
int filaVazia(Fila* fila);
  
  
