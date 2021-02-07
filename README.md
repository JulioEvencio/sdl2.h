# sdl2.h

Esta é a documentação do meu arquivo de cabeçalho `sdl2.h`. Este arquivo serve para facilitar o uso das funções da biblioteca SDL 2, SDL image e SDL ttf.
É necessário ter o SDL2, SDL2_image e SDL2_ttf instalado para usar este arquivo de cabeçalho. Use os seguintes comandos na hora de compilar:

`sdl2/sdl2.c -lSDL2 -lSDL2_image -lSDL2_ttf`

# Inicialização e finalização: SDL, IMG e TTF

## Iniciando SDL

`void sdl2_iniciar_SDL2(void)`

Esta é a função responsável por iniciar o SDL 2, SDL image e SDL ttf.

Ela não tem retorno e quando a inicialização é mal sucedida o programa irá encerrar automaticamente através da função `exit(1)`.

## Encerrando SDL

`void sdl2_finalizar_SDL2(void)`

Esta é a função responsável por encerrar o SDL 2, SDL image e SDL ttf.

# Funções da janela e tela

## Criar uma janela

`SDL_Window* sdl2_criar_janela(char *nome, int largura, int altura)`

Esta função cria uma janela. É necessário ter um ponteiro do tipo `SDL_Window`, de preferência apontando para NULL, para receber o endereço de memória devolvido.

### Parâmetros

`char *nome` -> uma string, isto é, um vetor de caractere do tipo char. Essa string será o nome exibido na janela.

`int largura` -> A largura da janela, isto é, seu comprimento no eixo x. A janela equivale ao quarto quadrante de um plano cartesiano
e seu comprimento definirá seu eixo x.

`int altura` -> A altura da janela, isto é, seu comprimento no eixo y. A janela equivale ao quarto quadrante de um plano cartesiano
e seu comprimento definirá seu eixo y.

## Liberar memória de uma janela

`void sdl2_fechar_janela(SDL_Window *janela)`

Esta função é responsável por liberar memória alocada na criação de uma janela, é recomendado usar antes de encerrar o programa ou quando uma janela não será mais usada. Após a liberação de memória o ponteiro vai ficar apontando para NULL.

### Parâmetros

`SDL_Window *janela` -> recebe o ponteiro apontando para uma janela já criada.

## Criar uma tela renderizada

`SDL_Renderer* sdl2_criar_tela(SDL_Window *janela)`

Esta função retorna uma tela renderizada para ser usada em uma janela.

### Parâmetos

`SDL_Window *janela` -> ponteiro para uma janela já criada.

## Liberar memória de uma tela renderizada

`void sdl2_fechar_tela(SDL_Renderer *tela)`

Esta função é responsável por liberar memória alocada na criação de uma tela renderizada, é recomendado usar antes de encerrar o programa ou quando uma tela renderizada não será mais usada. Após a liberação de memória o ponteiro vai ficar apontando para NULL.

### Parâmetros

`SDL_Renderer *tela` -> recebe o ponteiro apontando para uma tela renderizada já criada.

## Limpar a tela renderizada de uma janela

`void sdl2_limpar_tela(SDL_Renderer *tela, int r, int g, int b)`

Esta função limpar uma tela renderizada, isto é, deixa a tela em uma única cor. A cor é baseada da tabela RGB.

### Parâmetros

`SDL_Renderer *tela` -> ponteiro para a tela que deseja alterar a cor.

`int r` -> intensidade de vermelho, parte _r_ da tabela _RGB_.

`int g` -> intensidade de verde, parte _g_ da tabela _RGB_.

`int b` -> intensidade de azul, parte _b_ da tabela _RGB_.

## Atualizar uma tela renderizada

`void sdl2_atualizar_tela(SDL_Renderer *tela)`

Essa função atualiza uma tela renderizada. A atualização fará que todas alterações na tela fique visível.

### Parâmetros

`SDL_Renderer *tela` -> ponteiro para a tela que deseja atualizar.

# Funções de desenhos geométricos

## Desenhar retângulo na tela

`void sdl2_desenhar_retangulo(SDL_Renderer *tela, int x, int y, int largura, int altura, int r, int g, int b)`

Esta função desenha um retângulo em uma tela renderizada.

### Parâmetros

`SDL_Renderer *tela` -> ponteiro para a tela que deseja desenhar o retângulo.

`int x` -> coordenada x do retângulo

`int y` -> coordenada y do retângulo

`int largura` -> largura do retângulo, isto é, seu comprimento no eixo x

`int altura` -> largura do altura, isto é, seu comprimento no eixo y

`int r` -> intensidade de vermelho, parte _r_ da tabela _RGB_.

`int g` -> intensidade de verde, parte _g_ da tabela _RGB_.

`int b` -> intensidade de azul, parte _b_ da tabela _RGB_.

# Funções de arquivos .png e .jpg

## Criar uma textura a partir de arquivo .png ou .jpg

`SDL_Texture* sdl2_carregar_textura(SDL_Renderer *tela, char *arquivo)`

Esta função carregar um arquivo _.png_ ou _.jpg_ e transforma em uma textura usável para uma tela renderizada

### Parâmetros

`SDL_Renderer *tela` -> ponteiro para a tela que deseja desenhar a textura.

`char *arquivo` -> string com o nome do arquivo.

## Liberar memória de textura

`void sdl2_fechar_textura(SDL_Texture *textura)`

Esta função é responsável por liberar memória alocada na criação de uma textura, é recomendado usar antes de encerrar o programa ou quando uma textura não será mais usada. Após a liberação de memória o ponteiro vai ficar apontando para NULL.

### Parâmetros

`SDL_Texture *textura` -> um ponteiro para uma textura criada

## Desenhar textura em uma tela renderizada

`void sdl2_desenhar_textura(SDL_Renderer *tela, SDL_Texture *textura, int x, int y, int largura, int altura)`

Esta função desenha uma textura em uma tela renderizada.

### Parâmetros

`SDL_Renderer *tela` -> ponteiro para a tela que deseja desenhar a textura.

`SDL_Texture *textura` -> ponteiro que aponta para uma textura.

`int x` -> coordenada x da textura.

`int y` -> coordenada y da textura.

`int largura` -> largura da textura, isto é, seu comprimento no eixo x.

`int altura` -> largura da textura, isto é, seu comprimento no eixo y.

# Funções TTF

## Carregar fonte

`TTF_Font* sdl2_carregar_fonte(char *arquivo, int tamanho)`

Esta função carrega uma fonte _.ttf_ para ser usada em textos.

### Parâmetros

`char *arquivo` -> string com o nome do arquivo da fonte.

`int tamanho` -> tamanho da fonte.

## Liberar memória de uma fonte

`void sdl2_fechar_fonte(TTF_Font *fonte)`

Esta função é responsável por liberar memória alocada na criação de uma fonte, é recomendado usar antes de encerrar o programa ou quando uma fonte não será mais usada. Após a liberação de memória o ponteiro vai ficar apontando para NULL.

### Parâmetros

`TTF_Font *fonte` -> ponteiro para uma fonte criada.

## Exibir texto **SOLID**

`int sdl2_exibir_texto_solid(SDL_Renderer *tela, TTF_Font *fonte, char *mensagem, int x, int y, int largura, int altura, int r, int g, int b)`

Esta função exibi um texto **SOLID** em uma tela renderizada.

### Parâmetros

`SDL_Renderer *tela` -> ponteiro para a tela que deseja escrever o texto.

`TTF_Font *fonte` -> ponteiro para uma fonte criada.

`char *mensagem` -> mensagem do texto.

`int x` -> coordenada x do texto.

`int y` -> coordenada y do texto.

`int largura` -> largura do texto, isto é, seu comprimento no eixo x.

`int altura` -> largura do texto, isto é, seu comprimento no eixo y.

`int r` -> intensidade de vermelho, parte _r_ da tabela _RGB_.

`int g` -> intensidade de verde, parte _g_ da tabela _RGB_.

`int b` -> intensidade de azul, parte _b_ da tabela _RGB_.

## Exibir texto **SHADED**

`int sdl2_exibir_texto_shaded(SDL_Renderer *tela, TTF_Font *fonte, char *mensagem, int x, int y, int largura, int altura, int r, int g, int b, int R, int G, int B)`

Esta função exibi um texto **SHADED** (texto com fundo) em uma tela renderizada.

### Parâmetros

`SDL_Renderer *tela` -> ponteiro para a tela que deseja escrever o texto.

`TTF_Font *fonte` -> ponteiro para uma fonte criada.

`char *mensagem` -> mensagem do texto.

`int x` -> coordenada x do texto.

`int y` -> coordenada y do texto.

`int largura` -> largura do texto, isto é, seu comprimento no eixo x.

`int altura` -> largura do texto, isto é, seu comprimento no eixo y.

`int r` -> intensidade de vermelho, parte _r_ da tabela _RGB_.

`int g` -> intensidade de verde, parte _g_ da tabela _RGB_.

`int b` -> intensidade de azul, parte _b_ da tabela _RGB_.

`int R` -> intensidade de vermelho do fundo, parte _r_ da tabela _RGB_.

`int G` -> intensidade de verde do fundo, parte _g_ da tabela _RGB_.

`int B` -> intensidade de azul do fundo, parte _b_ da tabela _RGB_.

## Exibir texto **BLENDED**

`int sdl2_exibir_texto_blended(SDL_Renderer *tela, TTF_Font *fonte, char *mensagem, int x, int y, int largura, int altura, int r, int g, int b)`

Esta função exibi um texto **BLENDED** em uma tela renderizada.

### Parâmetros

`SDL_Renderer *tela` -> ponteiro para a tela que deseja escrever o texto.

`TTF_Font *fonte` -> ponteiro para uma fonte criada.

`char *mensagem` -> mensagem do texto.

`int x` -> coordenada x do texto.

`int y` -> coordenada y do texto.

`int largura` -> largura do texto, isto é, seu comprimento no eixo x.

`int altura` -> largura do texto, isto é, seu comprimento no eixo y.

`int r` -> intensidade de vermelho, parte _r_ da tabela _RGB_.

`int g` -> intensidade de verde, parte _g_ da tabela _RGB_.

`int b` -> intensidade de azul, parte _b_ da tabela _RGB_.
