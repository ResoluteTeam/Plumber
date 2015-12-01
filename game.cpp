#include "game.h"

Game::Game()
{
    initwindow(650,468,"Play Plumber",100,100,true,true);
}

int Game::start()
{
    exit = false;
    
    int frames = 50000, i = 0;
    
    while ( !exit ) {
        delay(100);
        processEvents();
        update();
        render();
    }
    
    closegraph();
    return 0;
}

void Game::processEvents()
{
    if ( kbhit() || ismouseclick(WM_LBUTTONDOWN) )
    {      
        if(kbhit()) {
            char key = getch();
            if(key == 27) 
            {
                exit = true;
            }
        }
    }
}

void Game::render()
{
    setfillstyle(SOLID_FILL, COLOR(230,225,255)); // Выставляем стил
    bar(0,0,getmaxx(),getmaxy()); // Рисуем фон
    
    swapbuffers(); //Очистка буфера
}

void Game::update()
{
    
}

Game::~Game()
{
}
