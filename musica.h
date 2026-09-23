typedef struct musica* Musica;

Musica criar_musica(char titulo[15], char artista[15], int duracao);
const char* get_titulo(Musica m);
const char* get_artista(Musica m);
int get_duracao(Musica m);
void imprimir_musica(Musica m);
void liberar_musica(Musica m);
