/*
    Exemplo usando o arquivo sdl2.h
*/

//  Bibliotecas
#include <stdio.h>
#include "sdl2/sdl2.h"
#include "sdl2/sdl2.c"

int main(int argc, char *args[])
{
    /*  Variaveis SDl */
    //  Janela
    SDL_Window *janela = NULL;
    SDL_Renderer *tela = NULL;
    //  Formas geometricas
    SDL_Rect retangulo;
    //  Imagem
    SDL_Texture *zero = NULL;
    //  Texto
    TTF_Font *fonte = NULL;
    //  Evento
    SDL_Event evento;
    
    //  Iniciando SDL, IMG e TTF
    sdl2_iniciar_SDL2();

    //  Criando uma janela
    janela = sdl2_criar_janela("Meu head sdl2", 640, 480);
    if(janela == NULL)
    {
        sdl2_finalizar_SDL2();
        exit(1);
    }

    //  Criando uma tela para a janela
    tela = sdl2_criar_tela(janela);
    if(tela == NULL)
    {
        sdl2_fechar_janela(janela);
        sdl2_finalizar_SDL2();
        exit(1);
    }

    //  Carregando textura
    zero = sdl2_carregar_textura(tela, "imagem/zero.png");
    if(zero == NULL)
    {
        sdl2_fechar_tela(tela);
        sdl2_fechar_janela(janela);
        sdl2_finalizar_SDL2();
        exit(1);
    }

    //  Carregando 
    fonte = sdl2_carregar_fonte("arial.ttf", 20);
    if(fonte == NULL)
    {
        sdl2_fechar_textura(zero);
        sdl2_fechar_tela(tela);
        sdl2_fechar_janela(janela);
        sdl2_finalizar_SDL2();
        exit(1);
    }

    //  Loop do programa
    int loop = 1;
    while(loop)
    {
        //  Verificando se um evento ocorreu
        while(SDL_PollEvent(&evento) != 0)
        {
            /*  Verificando qual evento ocorreu */
            //  Usuario clicou no X da janela
            if(evento.type == SDL_QUIT)
            {
                loop = 0;
            }
        }

        /*  Logica */

        /*  Grafico */
        //  Cor da tela
        sdl2_limpar_tela(tela, SDL2_VERMELHO);

        //  Desenhando retangulo
        sdl2_desenhar_retangulo(tela, retangulo, 200, 200, 50, 100, SDL2_VERDE);

        //  Desenhando uma textura na tela
        sdl2_desenhar_textura(tela, zero, 300, 300, 50, 50);

        //  Exibindo texto
        sdl2_exibir_texto_solid(tela, fonte, "Solid...", 0, 0, 100, 50, SDL2_PRETO);
        sdl2_exibir_texto_shaded(tela, fonte, "Shaded...", 0, 51, 100, 50, SDL2_PRETO, SDL2_BRANCO);
        sdl2_exibir_texto_blended(tela, fonte, "Blended...", 0, 101, 100, 50, SDL2_PRETO);

        //  Atualizando tela
        sdl2_atualizar_tela(tela);

        /*  Delay */
        SDL_Delay(10);
    }

    /*  Encerrando programa */
    //  Fechando fontes
    sdl2_fechar_fonte(fonte);
    //  Fechando textura
    sdl2_fechar_textura(zero);
    //  Fechando janela e tela
    sdl2_fechar_tela(tela);
    sdl2_fechar_janela(janela);
    //  Finalizando SDL, IMG e TTF
    sdl2_finalizar_SDL2();

    return 0;
}
