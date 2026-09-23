#include <stdio.h>
#include "musica.h"
#include "lista.h"

int pos_atual = 0;

int adicionar_musica(Lista playlist, char titulo[15], char artista[15], int duracao) {

    Musica m = criar_musica(titulo, artista, duracao);
    if (m == NULL) return 0;

    return inserir_final(playlist, m);
}

int adiciona_musica_posicao(Lista playlist, char titulo[15], char artista[15], int duracao, int pos) {

    Musica m = criar_musica(titulo, artista, duracao);
    if (m == NULL) return 0;

    return inserir_posicao(playlist, m, pos);

}

int remove_musica(Lista playlist, int pos) {
    remover_posicao(playlist, pos);
}

int tempo_restante(Lista playlist) {

    int tempo = 0;
    int qtd = consultar_quantidade(playlist);

    for (int i = pos_atual; i < qtd; i++) {

        Musica m = consultar_posicao(playlist, i);
        tempo += get_duracao(m);

    }

    return tempo;

}

int play(Lista playlist) {
    if (pos_atual >= consultar_quantidade(playlist)) {
        printf("A playlist chegou ao fim!\n");
        return 0;
    }

    Musica m = consultar_posicao(playlist, pos_atual);

    imprimir_musica(m);
  
    pos_atual++;

    return 1;
}


int musicas_reproduzidas(int pos_atual) {
    return pos_atual;
}


int main() {

    Lista playlist = criar_lista();

    adicionar_musica(playlist, "Time", "Pink Floyd", 425);
    adicionar_musica(playlist, "Heroes", "David Bowie", 367);
    adicionar_musica(playlist, "Creep", "Radiohead", 238);
    adicionar_musica(playlist, "One", "Metallica", 447);
    adicionar_musica(playlist, "Roxanne", "The Police", 192);
    adicionar_musica(playlist, "Yesterday", "The Beatles", 125);
    adicionar_musica(playlist, "Stayin Alive", "Bee Gees", 285);
    adicionar_musica(playlist, "Thriller", "Michael Jackson", 357);
    adicionar_musica(playlist, "Hysteria", "Muse", 227);
    adicionar_musica(playlist, "Clocks", "Coldplay", 307);

    printf("\nTotal de musicas cadastradas: %d\n", consultar_quantidade(playlist));
    int tempo = tempo_restante(playlist);
    printf("Tempo total da playlist: %02d:%02d (%d s)\n", tempo / 60, tempo % 60, tempo);

    play(playlist);

    play(playlist);

    play(playlist);
    
    tempo = tempo_restante(playlist);
    printf("Tempo restante para tocar: %02d:%02d (%d s)\n", tempo / 60, tempo % 60, tempo);
    printf("\nMusicas ja reproduzidas: %d\n", musicas_reproduzidas(pos_atual));

    printf("Quantidade de musicas presentes na playlist: %d\n", consultar_quantidade(playlist));
    printf("Posicao da proxima musica a ser reproduzida: %d\n", pos_atual + 1);

    liberar_lista(playlist);
    return 0;
}