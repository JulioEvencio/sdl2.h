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
