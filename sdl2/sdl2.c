/* Bibliotecas */
#include "sdl2.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/* Inicializacao e finalizacao: SDL, IMG e TTF */
/* Funcao que iniciar: SDL, IMG e TTF */
int sdl2_iniciar(void)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return SDL2_ERRO_AO_INICIAR_SDL2;

    if(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG) < 0)
    {
        SDL_Quit();
        return SDL2_ERRO_AO_INICIAR_IMG;
    }

    if(TTF_Init() < 0)
    {
        IMG_Quit();
        SDL_Quit();
        return SDL2_ERRO_AO_INICIAR_TTF;
    }

    return SDL2_SUCESSO;
}

/* Funcao que finaliza: SDL, IMG e TTF */
void sdl2_finalizar(void)
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

/* Funcoes da janela e tela */
/* Funcao que cria uma janela com uma tela renderiazada*/
int sdl2_criar_janela(SDL_Window **janela, SDL_Renderer **tela_renderizada, char *nome, int largura, int altura)
{
    *janela = SDL_CreateWindow(
        nome,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        largura,
        altura,
        SDL_WINDOW_SHOWN
    );

    if (*janela == NULL) return SDL2_Erro_AO_CRIAR_JANELA;

    *tela_renderizada = SDL_CreateRenderer(
        janela,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (*tela_renderizada == NULL)
    {
        SDL_DestroyWindow(*tela);
        return SDL2_Erro_AO_CRIAR_TELA_RENDERIZADA;
    }

    return SDL2_SUCESSO;
}

/* Funcao que limpa a tela com uma cor especifica */
void sdl2_limpar_tela(SDL_Renderer *tela, int r, int g, int b)
{
    SDL_SetRenderDrawColor(tela, r, g, b, 255);
    SDL_RenderClear(tela);
}

/* Funcao que atualiza uma tela */
void sdl2_atualizar_tela(SDL_Renderer *tela)
{
    SDL_RenderPresent(tela);
}

/* Funcao que libera memoria de uma janela */
void sdl2_fechar_janela(SDL_Window *janela, SDL_Renderer *tela_renderizada)
{
    SDL_DestroyRenderer(tela_renderizada);
    SDL_DestroyWindow(janela);
}

/* Funcoes de desenhos geometricos */
/* Funcao que desenha um retangulo na tela */
void sdl2_desenhar_retangulo(SDL_Renderer *tela, int x, int y, int largura, int altura, int r, int g, int b)
{
    SDL_Rect retangulo = {x, y, largura, altura};

    SDL_SetRenderDrawColor(tela, r, g, b, 255);
    SDL_RenderFillRect(tela, &retangulo);
}

/* Funcoes de arquivos .png e .jpg */
/* Funcao que carrega uma imagem .png/.jpg e transforma em uma textura usavel */
SDL_Texture* sdl2_carregar_textura(SDL_Renderer *tela, char *arquivo)
{
    SDL_Surface *imagem;
    SDL_Texture *textura;

    imagem = IMG_Load(arquivo);

    if(imagem == NULL) return textura;

    textura = SDL_CreateTextureFromSurface(tela, imagem);
    SDL_FreeSurface(imagem);

    return textura;
}

/* Funcao que desenha uma textura na tela */
void sdl2_desenhar_textura(SDL_Renderer *tela, SDL_Texture *textura, int x, int y, int largura, int altura)
{
    SDL_Rect desenho = {x, y, largura, altura};

    SDL_RenderCopy(tela, textura, NULL, &desenho);
}

/* Funcao que libera memoria de uma textura */
void sdl2_fechar_textura(SDL_Texture *textura)
{
    SDL_DestroyTexture(textura);
}

/* Funcoes TTF */
/* Funcao que carrega uma fonte TTF */
TTF_Font* sdl2_carregar_fonte(char *arquivo, int tamanho)
{
    TTF_Font *fonte;

    fonte = TTF_OpenFont(arquivo, tamanho);

    return fonte;
}

/* Funcao que exibi um texto solid */
int sdl2_exibir_texto_solid(SDL_Renderer *tela, TTF_Font *fonte, char *mensagem, int x, int y, int largura, int altura, int r, int g, int b)
{
    SDL_Surface *texto;
    SDL_Texture *texto_textura;
    SDL_Color fonte_cor = {r, g, b};

    texto = TTF_RenderText_Solid(fonte, mensagem, fonte_cor);

    if(texto == NULL) return SDL2_ERRO_AO_EXIBIR_TEXTO;

    texto_textura = SDL_CreateTextureFromSurface(tela, texto);

    if(texto_textura == NULL)
    {
        SDL_FreeSurface(texto);
        return SDL2_ERRO_AO_EXIBIR_TEXTO;
    }

    SDL_Rect desenho = {x, y, largura, altura};

    SDL_RenderCopy(tela, texto_textura, NULL, &desenho);
    SDL_FreeSurface(texto);
    SDL_DestroyTexture(texto_textura);

    return SDL2_SUCESSO;
}

/* Funcao que exibi um texto shaded */
int sdl2_exibir_texto_shaded(SDL_Renderer *tela, TTF_Font *fonte, char *mensagem, int x, int y, int largura, int altura, int r, int g, int b, int R, int G, int B)
{
    SDL_Surface *texto;
    SDL_Texture *texto_textura;
    SDL_Color fonte_cor = {r, g, b};
    SDL_Color fonte_fundo = {R, G, B};

    texto = TTF_RenderText_Shaded(fonte, mensagem, fonte_cor, fonte_fundo);

    if(texto == NULL) return SDL2_ERRO_AO_EXIBIR_TEXTO;

    texto_textura = SDL_CreateTextureFromSurface(tela, texto);

    if(texto_textura == NULL)
    {
        SDL_FreeSurface(texto);
        return SDL2_ERRO_AO_EXIBIR_TEXTO;
    }

    SDL_Rect desenho = {x, y, largura, altura};

    SDL_RenderCopy(tela, texto_textura, NULL, &desenho);
    SDL_FreeSurface(texto);
    SDL_DestroyTexture(texto_textura);

    return SDL2_SUCESSO;
}

/* Funcao que exibi um texto blended */
int sdl2_exibir_texto_blended(SDL_Renderer *tela, TTF_Font *fonte, char *mensagem, int x, int y, int largura, int altura, int r, int g, int b)
{
    SDL_Surface *texto;
    SDL_Texture *texto_textura;
    SDL_Color fonte_cor = {r, g, b};

    texto = TTF_RenderText_Blended(fonte, mensagem, fonte_cor);

    if(texto == NULL) return SDL2_ERRO_AO_EXIBIR_TEXTO;

    texto_textura = SDL_CreateTextureFromSurface(tela, texto);

    if(texto_textura == NULL)
    {
        SDL_FreeSurface(texto);
        return SDL2_ERRO_AO_EXIBIR_TEXTO;
    }

    SDL_Rect desenho = {x, y, largura, altura};

    SDL_RenderCopy(tela, texto_textura, NULL, &desenho);
    SDL_FreeSurface(texto);
    sdl2_fechar_textura(texto_textura);

    return SDL2_SUCESSO;
}

/* Funcao que libera memoria das fontes */
void sdl2_fechar_fonte(TTF_Font *fonte)
{
    TTF_CloseFont(fonte);
}