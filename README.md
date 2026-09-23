<h3 align="center">Gerenciador de Playlist</h3>

<div align="center">

![Status](https://img.shields.io/badge/status-Finalizado-success.svg)
![Disciplina](https://img.shields.io/badge/disciplina-Estrutura%20de%20Dados-blue.svg)
![Linguagem](https://img.shields.io/badge/linguagem-C-orange.svg)

</div>

---

<p align="center">
Projeto desenvolvido para a disciplina de Estrutura de Dados Lineares, implementando um reprodutor e gerenciador de playlist utilizando Tipos Abstratos de Dados (TAD) com Lista Encadeada.
</p>

# 📝 Sumário

- [Sobre](#sobre)
- [Objetivo](#objetivo)
- [Funcionalidades](#funcionalidades)
- [Estrutura do Projeto](#estrutura)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Instalação e Execução](#como-executar)
- [Operações e Complexidade](#complexidade)
- [Resultados da Simulação](#resultados)

# 🧐 Sobre <a name="sobre"></a>

Este projeto foi desenvolvido como atividade avaliativa da disciplina de Estrutura de Dados. O foco prático é a aplicação de conceitos fundamentais da ciência da computação em linguagem C:

- **Encapsulamento estrito (TAD)**
- **Alocação Dinâmica**
- **Controle de Reprodução**

# 🎯 Objetivo <a name="objetivo"></a>

Modelar uma lista de reprodução musical organizada via lista unicamente encadeada, suportando inserção, remoção e consulta por posição, bem como controle de faixas tocadas e cálculo dinâmico de tempo restante de execução.

# ⚙️ Funcionalidades <a name="funcionalidades"></a>

- **TAD Música:** Criação, encapsulamento de atributos (título, artista, duração), getters de acesso.
- **TAD Lista Encadeada:**
    - Inserção no início, final e em posições arbitrárias (`posicao 0` até `qtd`).
    - Remoção no início, final e por posição com liberação de nós e dados.
    - Consulta direta por índice.
    - Destruição completa da lista e de seus nós.
- **Módulo de Aplicação (`main.c`):**
    - Cadastro em lote de faixas.
    - Simulação de reprodução sequencial (`play`).
    - Contagem de músicas já reproduzidas.
    - Cálculo e atualização do tempo restante de playlist.

# ▶️ Instalação e Execução <a name="como-executar"></a>

### Pré-requisitos

- Compilador GCC instalado no sistema (Linux, macOS ou Windows com MinGW / WSL).

### Compilação e Execução

1. Clone o repositório:

```bash
git clone https://github.com/DarwinGAZ/EDL-1GQ.git
```

2. Acesse a pasta do projeto:

```bash
cd EDL-1GQ
```

3. Compile os arquivos em um executavel:

```bash
gcc -w musica.c lista.c main.c -o programa
```

4. Execute

```bash
./programa
```
