#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Pessoa{
    char* nome;
    char telefone[12];
    char* email;
   
}pessoa[MAX];

void exibirMenu(){
    printf("\n\tSelecione umas das opções a seguir:\n");
    printf("\t1 - Adiconar contato\n"
           "\t2 - exibir  contatos\n"
           "\t3 - Pesquisar contato\n"
           "\t0 - Sair\n\n");
}

char* alocarMemoria(int tamanho){
    char* info = NULL;
    info = (char*) malloc(sizeof(tamanho) * sizeof(char));

    if(info == NULL){
        printf("ERRO: memoria invalida");
        exit(1);
    }
    return info;
}

void cadastrarContato(int registro){
    char dados[MAX];
    printf("\n\t\tNome: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);

    pessoa[registro].nome = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].nome, dados);

    printf("\t\tTelefone: ");
    scanf("%[^\n]s", pessoa[registro].telefone);
    setbuf(stdin, NULL);

    printf("\t\tEmail: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);

    pessoa[registro].email = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].email, dados);

   
}

void listarContatos(int qtdeContatos){
    int i;
    int cont = 1;
    for(i = 0; i < qtdeContatos; i++){
        printf("\n\tContato nº: %d\n", cont++);
        printf("\tNome: %s\n", pessoa[i].nome);
        printf("\tTelefone: %s\n", pessoa[i].telefone);
        printf("\tEmail: %s\n", pessoa[i].email);
    }
    printf("\n\n");
}

void exibirContato(int indice){
    printf("\n\tNome: %s\n", pessoa[indice].nome);
    printf("\tTelefone: %s\n", pessoa[indice].telefone);
    printf("\tEmail: %s\n", pessoa[indice].email);
}

int buscarContato(int qtdeContatos, char* nomeBuscado){
    int i;

    for(i = 0; i < qtdeContatos; i++){
        if(strcmp(nomeBuscado, pessoa[i].nome) == 0)
            return i;
    }
    return -1;
}


int ler(){
    int opcao;

    printf("\n\tOpção escolhida: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    return opcao;
}

int main(){
    char nome[MAX];
    int registro = 0;
    int opcao;
    int indice;

    do{
        exibirMenu();
        opcao = ler();

        switch(opcao){
            case 1:
                cadastrarContato(registro++);
                break;
            case 2:
                listarContatos(registro);
                break;
            case 3:
                printf("\n\tNome: ");
                scanf("%[^\n]s", nome);
                indice = buscarContato(registro, nome);

                if(indice >= 0 && indice <= 99)
                    exibirContato(indice);
                else
                    printf("\n\tContato não cadastrado!");
                break;
            
            case 0:
                printf("\n\tSaindo...");
                break;
            default:
                printf("Opção inválida!");
                exibirMenu();
                opcao = ler();
        }

    }while(opcao != 0);
}