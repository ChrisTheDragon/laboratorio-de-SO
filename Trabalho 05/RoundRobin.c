#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct processos
{
    int id;
    int tempo;
    int prioridade;
    int execucao;
    int espera;
    struct processos *prox_pro;

};

struct processos *iniciar_processo(int id, int tempo, int prioridade);
void mostrar_processos(struct processos *proc);
int tamanho_lista(struct processos *proc);
void RoundRobin (struct processos *proc, int quantum);
void Prioridade(struct processos *proc);

int main(void)
{
    struct processos *lista_proc, *lista_temp;

    lista_proc = iniciar_processo(1, 50, 5);
    lista_proc->prox_pro = iniciar_processo(2, 80, 4);
    lista_temp = lista_proc->prox_pro;
    lista_temp->prox_pro = iniciar_processo(3, 100, 1);
    lista_temp = lista_temp->prox_pro;
    lista_temp->prox_pro = iniciar_processo(4, 50, 10);
    lista_temp = lista_temp->prox_pro;
    lista_temp->prox_pro = iniciar_processo(5, 90, 9);
    

    mostrar_processos(lista_proc);
    printf("\n\n");

    RoundRobin(lista_proc, 10);
    
    
    return 0;
}

struct processos *iniciar_processo(int id, int tempo, int prioridade)
{
    struct processos *proc;
    proc = (struct processos*)malloc(sizeof(struct processos));

    if (proc == NULL){
        printf("\nFalha na alocação de memória\nFinalizando...\n");
        exit(1);
    }
    
    proc->id = id;
    proc->tempo = tempo;
    proc->prioridade = prioridade;
    proc->execucao = 0;
    proc->espera = 0;
    proc->prox_pro = NULL;

    return (proc);
}

void mostrar_processos(struct processos *proc)
{
    while (proc != NULL)
    {
        printf("Processo P%d, Tempo: %d, Prioridade: %d\n", proc->id, proc->tempo, proc->prioridade);
        proc = proc->prox_pro;
    }
}

int tamanho_lista(struct processos *proc)
{
    int i;
    while (proc != NULL)
    {
        i++;
        proc = proc->prox_pro;
    }
    return i;
}

void RoundRobin(struct processos *proc, int quantum)
{
    int finalizados = tamanho_lista(proc);
    struct processos *primeiro = (struct processos *)malloc(sizeof(struct processos));
    primeiro = proc;

    while (proc != NULL){
        proc->execucao = proc->tempo - quantum;
        proc = proc->prox_pro;
    }

    do{
        while (proc != NULL){
            proc->execucao = proc->execucao - quantum;
            printf("P%d, %d\n", proc->id, proc->execucao);
            proc = proc->prox_pro;
        }

        proc = primeiro;

        if(proc->execucao <= 0) {
            finalizados--;
        }

    }while(finalizados >=0 );

    free(primeiro);
    
}
