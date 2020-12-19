//  Bibliotecas
#include <stdio.h>
#include "sdl2/sdl2.h"

/*  Funcoes */
/*  Inicializacao e finalizacao: SDL, IMG e TTF */
//  Funcao que iniciar: SDL, IMG e TTF
void sdl2_iniciar_SDL2(void)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erro ao iniciar SDL: %s \n", SDL_GetError());
        exit(1);
    }
    if(IMG_Init(IMG_INIT_PNG) < 0)
    {
        SDL_Quit();
        printf("Erro ao iniciar IMG: %s \n", IMG_GetError());
        exit(1);
    }
    if(TTF_Init() < 0)
    {
        IMG_Quit();
        SDL_Quit();
        printf("Erro ao iniciar TTF: %s \n", TTF_GetError());
        exit(1);
    }
}

//  Funcao que finaliza: SDL, IMG e TTF
void sdl2_finalizar_SDL2(void)
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

/*  Funcoes da janela e tela */
//  Funcao que cria uma janela
SDL_Window* sdl2_criar_janela(char nome[], int largura, int altura)
{
    SDL_Window *janela = NULL;
    janela = SDL_CreateWindow(nome, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largura, altura, SDL_WINDOW_SHOWN);
    if(janela == NULL)
    {
        printf("Erro ao criar janela: %s \n", SDL_GetError());
        sdl2_finalizar_SDL2();
        exit(1);
    }
    return janela;
}

/*  Funcoes da janela e tela */
//  Funcao que cria uma janela
SDL_Window* sdl2_criar_janela(char nome[], int largura, int altura)
{
    SDL_Window *janela = NULL;
    janela = SDL_CreateWindow(nome, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largura, altura, SDL_WINDOW_SHOWN);
    if(janela == NULL)
    {
        printf("Erro ao criar janela: %s \n", SDL_GetError());
        sdl2_finalizar_SDL2();
        exit(1);
    }
    return janela;
}

//  Funcao que cria uma tela
SDL_Renderer* sdl2_criar_tela(SDL_Window *janela)
{
    SDL_Renderer *tela = NULL;
    tela = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(tela == NULL)
    {
        printf("Erro ao criar tela: %s \n", SDL_GetError());
        sdl2_fechar_janela(janela);
        sdl2_finalizar_SDL2();
        exit(1);
    }
    return tela;
}

//  Funcao que define a cor de uma tela
void sdl2_definir_cor_tela(SDL_Renderer *tela, int r, int g, int b)
{
    SDL_SetRenderDrawColor(tela, r, g, b, 255);
    SDL_RenderClear(tela);
}

//  Funcao que atualiza uma tela
void sdl2_atualizar_tela(SDL_Renderer *tela)
{
    SDL_RenderPresent(tela);
}

//  Funcao que libera memoria de uma janela
void sdl2_fechar_janela(SDL_Window *janela)
{
    SDL_DestroyWindow(janela);
    janela = NULL;
}

//  Funcao que libera memoria de uma tela
void sdl2_fechar_tela(SDL_Renderer *tela)
{
    SDL_DestroyRenderer(tela);
    tela = NULL;
}

/*  Funcoes de desenhos geometricos */
void sdl2_desenhar_retangulo(SDL_Renderer *tela, SDL_Rect retangulo, int x, int y, int largura, int altura, int r, int g, int b)
{
    SDL_SetRenderDrawColor(tela, r, g, b, 255);
    retangulo.x = x;
    retangulo.y = y;
    retangulo.w = largura;
    retangulo.h = altura;
    SDL_RenderFillRect(tela, &retangulo);
}
