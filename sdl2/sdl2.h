#ifndef SDL2_H_INCLUDED
#define SDL2_H_INCLUDED

//  Bibliotecas
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/*  Constantes */
#define BRANCO 255,255,255
#define PRETO 0,0,0
#define VERMELHO 255,0,0
#define VERDE 0,255,0
#define AZUL 0,0,255

/*  Funcoes */
//  Inicializacao e finalizacao: SDL, IMG e TTF
void sdl2_iniciar_SDL2(void);
void sdl2_finalizar_SDL2(void);

#endif // SDL2_H_INCLUDED