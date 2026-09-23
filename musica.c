#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct musica {
    char titulo[15];
    char artista[15];
    int duracao;
};

typedef struct musica* Musica;


Musica criar_musica(char titulo[15], char artista[15], int duracao) {
    Musica m = malloc(sizeof(struct musica));
    if (m != NULL) {
        strcpy(m->titulo, titulo);
        m->duracao = duracao;
        strcpy(m->artista, artista);
    }

    return m;
}

const char* get_titulo(Musica m) {
    return m ? m->titulo : NULL;
}

const char* get_artista(Musica m) {
    return m ? m->artista : NULL;
}

int get_duracao(Musica m) {
    return m ? m->duracao : -1;
}

void imprimir_musica(Musica m) {
    if (m == NULL) {
        printf("[Música Inválida]\n");
        return;
    }

    int minutos = m->duracao / 60;
    int segundos = m->duracao % 60;

    printf("==============================\n");
    printf("Titulo : %s\n", m->titulo);
    printf("Artista: %s\n", m->artista);
    printf("Duracao: %02d:%02d (%d s)\n", minutos, segundos, m->duracao);
    printf("==============================\n");
}

void liberar_musica(Musica m) {
    if (m != NULL) free(m);
}