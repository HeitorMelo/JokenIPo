#include "resourcesIdx.h"
#include "screens.h"
#include "stdlib.h"
#include "raylib.h"
#include "load.h"
#include "sprites.h"
#include "canvas.h"
#include <tmx.h>
#include "stdio.h"
#include "string.h"

#include "math.h"

const int screenWidth = 1280;
const int screenHeight = 1024;

void SetActiveScreen(void (*screen)()){
    activeScreen = screen;
}

void UpdateScreen(){
    if (activeScreen != NULL)
        (*activeScreen)();
}

void mainMenu(){
    static int selecao = 0;//(0 é Play) (1 é creditos) (2 é exit)
    Texture2D* background = GetTexture(Texture_torre); 
    static Vector2 img = {0,0};//VALOR ONDE A IMAGEM DO FUNDO VAI INICIAR
    static int subir = 1;
    float tamanho = (float) screenWidth / (float)background->width; 

    if ((img.y <= -(background->height)/2)&& (subir == 1)){
        subir = 2;
    }
    if ((img.y >= 0) && (subir == 2)){
        subir = 1;
    }

    // Update
    if(subir == 1)
    img.y -= 1;
    if (subir ==2)
        img.y += 1;
    //A IMAGEM DO FUNDO DESCER
    if(IsKeyPressed(KEY_LEFT)&&(selecao>0)){
        selecao--;
    }
    if(IsKeyPressed(KEY_RIGHT)&&(selecao<2)){
        selecao++;
    }

    if(IsKeyPressed(KEY_ENTER)&&(selecao==0)){
        //PLAY
        SetActiveScreen(&FoundEnemyCanvas); //temporário
    }
    if(IsKeyPressed(KEY_ENTER)&&(selecao==1)){
        //CREDITOS
    }
    if(IsKeyPressed(KEY_ENTER)&&(selecao==2)){
        //EXIT
        QuitApplication();
    }

    //COLOCANDO A IMAGEM DE BACKGROUND ANTES DE DESENHAR TODOS OS CIRCULOS
    DrawTextureEx((*background), img,0 , tamanho, GRAY);
    

    if(selecao==0){
        DrawPropCircle(0.3, 0.5, 105, MAGENTA);
        DrawPropCircle(0.5, 0.5, 105, BLUE);
        DrawPropCircle(0.7, 0.5, 105, BLUE);
        DrawPropCircle(0.3, 0.5, 100, VIOLET);
        DrawPropCircle(0.5, 0.5, 100, DARKBLUE); 
        DrawPropCircle(0.7, 0.5, 100, DARKBLUE);
        DrawPropCenteredText("PLAY",0.3, 0.5, 40, WHITE);
        DrawPropCenteredText("CREDITS",0.5, 0.5, 40, SKYBLUE);
        DrawPropCenteredText("EXIT",0.7, 0.5, 40, SKYBLUE);
    }
    if(selecao==1){
        DrawPropCircle(0.3, 0.5, 105, BLUE);
        DrawPropCircle(0.5, 0.5, 105, MAGENTA);
        DrawPropCircle(0.7, 0.5, 105, BLUE);
        DrawPropCircle(0.3, 0.5, 100, DARKBLUE);
        DrawPropCircle(0.5, 0.5, 100, VIOLET); 
        DrawPropCircle(0.7, 0.5, 100, DARKBLUE);
        DrawPropCenteredText("PLAY",0.3, 0.5, 40, SKYBLUE);
        DrawPropCenteredText("CREDITS",0.5, 0.5, 40, WHITE);
        DrawPropCenteredText("EXIT",0.7, 0.5, 40, SKYBLUE);
    }
    if(selecao==2){
        DrawPropCircle(0.3, 0.5, 105, BLUE);
        DrawPropCircle(0.5, 0.5, 105, BLUE);
        DrawPropCircle(0.7, 0.5, 105, MAGENTA);
        DrawPropCircle(0.3, 0.5, 100, DARKBLUE);
        DrawPropCircle(0.5, 0.5, 100, DARKBLUE); 
        DrawPropCircle(0.7, 0.5, 100, VIOLET);
        DrawPropCenteredText("PLAY",0.3, 0.5, 40, SKYBLUE);
        DrawPropCenteredText("CREDITS",0.5, 0.5, 40, SKYBLUE);
        DrawPropCenteredText("EXIT",0.7, 0.5, 40, WHITE);
    }
}

void FoundEnemyCanvas(){
    static int selecao = 0;
    // Update
    if(IsKeyPressed(KEY_LEFT)&&(selecao>0)){
        selecao--;
    }
    if(IsKeyPressed(KEY_RIGHT)&&(selecao<1)){
        selecao++;
    }
    if(IsKeyPressed(KEY_ENTER)){
        switch(selecao){
            case 1:
                //item 1
                break;
            case 2:
                //item 2
                break;     
        }
    }

    ClearBackground(WHITE);
    
    // Ajuste a posição e tamanho dos retângulos
    for(int i = 0; i < 2; i++){
        Color cor = VIOLET;
        if(i == selecao){
            cor = DARKBLUE; // Muda a cor do retângulo selecionado
        }
        DrawPropRectangle(0.3 * i + 0.25, 0.73, 250, 100, cor);
    }
    DrawPropRectangle(0.03, 0.39, 450, 100, VIOLET);
    DrawPropCenteredText("RUN",0.34, 0.8, 40, WHITE);
    DrawPropCenteredText("FIGHT",0.65, 0.8, 40, WHITE);
    DrawPropCenteredText("or",0.5, 0.8, 35, BLACK);
    DrawPropRectangle(0.77, 0.13, 230, 260, VIOLET);
    DrawRectangleLines(GetScreenWidth() * 0.03, GetScreenHeight() * 0.53, 1180, 300, VIOLET);
}

void battleMenu(){
    static int selecao = 0;
    if(IsKeyPressed(KEY_LEFT)&&(selecao>0)){
        selecao--;
    }
    if(IsKeyPressed(KEY_RIGHT)&&(selecao<8)){
        selecao++;
    }
    if(IsKeyPressed(KEY_ENTER)){
        switch(selecao){
            case 1:
                //pers 1
                break;
            case 2:
                //pers 2
                break;
            case 3:
                //pers 3
                break;
            case 4:
                //pers 4
                break;
            case 5:
                //pers 5
                break;
            case 6:
                //pers 6
                break;
            case 7: 
                //pers 7
                break;
            case 8:
                //pers 8
                break;
            case 9: 
                //pers 9
                break;       
        }
    }

    // Draw
    Texture2D* background = GetTexture(Texture_torre); 
    Vector2 img = {0,0};

    DrawTextureV(*background,img , GRAY);
    DrawTexturePro(*background, (Rectangle){ 0.0f, 0.0f, (float)background->width, (float)background->height }, 
    (Rectangle){ 0, 0, screenWidth, screenHeight }, (Vector2){ 0, 0 }, 0.0f, WHITE); 

    for(int i = 0; i < 9; i++){
        Color cor = DARKBLUE;
        if(i == selecao){
            cor = BLUE; // Muda a cor do retangulo selecionado
        }
        DrawPropRectangle(0.101 * i + 0.05, 0.72, 100, 100, cor);
    }
    DrawPropRectangle(0.3, 0.03, 480, 100, DARKBLUE); // pontos
    DrawPropRectangle(0.795,0.18, 200, 270, DARKBLUE);
    DrawPropRectangle(0.64,0.3, 150, 150, DARKBLUE);
    DrawPropRectangle(0.22, 0.3, 150, 150, DARKBLUE); // oq vai aparecer o personagem 
    DrawPropRectangle(0.03, 0.18, 200, 270, DARKBLUE); // maior do canto
    DrawRectangleLines(GetScreenWidth() * 0.03, GetScreenHeight() * 0.65, 1180, 200, BLUE);
    EndDrawing();
    
}

void UpdatePlayerPosition(tmx_map *map, Rectangle *playerRect)
{
    printf("Procurando um lugar pro personagem\n");
    tmx_layer *layer = NULL;
    printf("Será se tem mapa?\n");
    if(map)
    {
        printf("Tem mapa\n");
        layer = map->ly_head;
    }
    bool achou = false;
    printf("vamos ver as camadas \n");
    while(layer && !achou)
    {
        printf("uma layer lida \n");
        if (layer->visible)
        {
            printf("uma layer visivel \n");
            if (layer->type == L_OBJGR && layer->name && strcmp(layer->name, "Pontos") == 0)
            {
                printf("uma layer de pontos \n");
                if(layer->content.objgr)
                {
                    printf("uma layer de pontos com conteudo \n");
                    tmx_object *obj = layer->content.objgr->head;
                    while (obj && !achou)
                    {
                        printf("um objeto lido \n");
                        if (obj->name && strcmp(obj->name, "Player") == 0)
                        {
                            printf("um objeto de player \n");
                            playerRect->x = obj->x;
                            playerRect->y = obj->y;
                            achou = true;
                        }
                        obj = obj->next;
                    }
                }
            }               
        }
        layer = layer->next;
    }
}

int CheckWhereToGo (tmx_map *map, Rectangle *playerRect)
{
    tmx_layer *layer = NULL;
    layer = map->ly_head;
    bool achou = false;
    while(layer && !achou)
    {
        if (layer->visible)
        {
            if (layer->type == L_OBJGR && strcmp(layer->name, "Portas") == 0)
            {
                tmx_object *obj = layer->content.objgr->head;
                while (obj && !achou)
                {
                    if (CheckCollisionRecs(*playerRect, (Rectangle){obj->x, obj->y, obj->width, obj->height}))
                    {
                        if (strcmp(obj->name, "Porta_II"))
                        {
                            return Porta_II;
                        }
                        else if (strcmp(obj->name, "Porta_III"))
                        {
                            return Porta_III;
                        }
                        else if (strcmp(obj->name, "Porta_IV"))
                        {
                            return Porta_IV;
                        }
                        else if (strcmp(obj->name, "Porta_V"))
                        {
                            return Porta_V;
                        }
                        else if (strcmp(obj->name, "Porta_VI"))
                        {
                            return Porta_VI;
                        }
                        else if (strcmp(obj->name, "Porta_VII"))
                        {
                            return Porta_VII;
                        }
                        else if (strcmp(obj->name, "Porta_VIII"))
                        {
                            return Porta_VIII;
                        }
                        else if (strcmp(obj->name, "Porta_IX"))
                        {
                            return Porta_IX;
                        }
                        else if (strcmp(obj->name, "Porta_X"))
                        {
                            return Porta_X;
                        }
                        else if (strcmp(obj->name, "Porta_XI"))
                        {
                            return Porta_XI;
                        }
                    }
                    obj = obj->next;
                }
            }               
        }
        layer = layer->next;
    }
}

void UpdateMap(tmx_map *map, Rectangle *playerRect, int *currentMap)
{
    *currentMap = CheckWhereToGo(map, playerRect);
    UpdatePlayerPosition(map, playerRect);
}

void mapCanvas (int i, tmx_map *map){
    tmx_map_free(map);
    map = GetMap(i);

	if (!map) {
		tmx_perror("Cannot load map");
        return;
	}
    render_map(map);
}
