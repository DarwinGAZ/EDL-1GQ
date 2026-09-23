#include <stdlib.h>
#include "musica.h"

struct elem {
    Musica musica;
    struct elem* prox;
};

typedef struct elem Elem;

struct lista
{
    int qtd;
    Elem* inicio;
};

typedef struct lista *Lista;

Lista criar_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li != NULL) {
        li->qtd = 0;
        li->inicio = NULL;
    }

    return li;
}

int inserir_inicio(Lista li, Musica m) {
    Elem* no = malloc(sizeof(Elem));
    if (no != NULL) {
        no->musica = m;
        no->prox = li->inicio;
        li->inicio = no;
        li->qtd++;
        return 1;
    }
    return 0;
}

int inserir_final(Lista li, Musica m){
    Elem* no = malloc(sizeof(Elem));
    if(no != NULL){
        no->musica = m;
        no->prox = NULL;
        if(li->inicio == NULL){
            li->inicio = no;
            li->qtd++;
            return 1;
        }
        Elem* aux = li->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        li->qtd++;
        return 1;
    }
    return 0;
}

int remover_inicio(Lista li){
    if(li->qtd == 0) return 0;
    Elem* aux = li->inicio;
    li->inicio = aux->prox;
    free(aux);
    li->qtd--;
    return 1;
}

Musica acessar_inicio(Lista li){
    if(li->qtd == 0) return 0;
    return li->inicio->musica;
}

int remover_final(Lista li){
    if(li->qtd == 0) return 0;
    Elem* aux = li->inicio;
    if(aux->prox == NULL){
        free(aux);
        li->inicio = NULL;
        li->qtd--;
        return 1;
    }
    Elem* ant;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }
    free(aux);
    ant->prox = NULL;
    li->qtd--;
    return 1;
}

int inserir_posicao(Lista li, Musica m, int pos) {
    if (li == NULL) return 0;
    if (pos < 0 || pos > li->qtd) return 0; 

    if (pos == 0) {
        return inserir_inicio(li, m);
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->musica = m;

    Elem* ant = li->inicio;
    for (int i = 0; i < pos - 1; i++) {
        ant = ant->prox;
    }

    no->prox = ant->prox;
    ant->prox = no;

    li->qtd++;
    return 1;
}

Musica consultar_posicao(Lista li, int pos) {
    if (li == NULL || pos < 0 || pos >= li->qtd) {
        return NULL; 
    }

    Elem* aux = li->inicio;
    for (int i = 0; i < pos; i++) {
        aux = aux->prox;
    }

    return aux->musica;
}

int remover_posicao(Lista li, int pos) {
    if (li == NULL || pos < 0 || pos >= li->qtd) {
        return 0; 
    }

    Elem* no_remover = NULL;

    if (pos == 0) {
        no_remover = li->inicio;
        li->inicio = no_remover->prox;
    } else {
        Elem* ant = li->inicio;
        for (int i = 0; i < pos - 1; i++) {
            ant = ant->prox;
        }

        no_remover = ant->prox;
        ant->prox = no_remover->prox;
    }

    liberar_musica((no_remover->musica));
    free(no_remover);

    li->qtd--;
    return 1;
}

int consultar_quantidade(Lista li) {
    if (li == NULL) return 0;
    return li->qtd;
}

void liberar_lista(Lista li) {
    if (li != NULL) free(li);
}