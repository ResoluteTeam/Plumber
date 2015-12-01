#include "game.h"

Game::Game()
{
    initwindow(650,468,"Play Plumber",100,100,true,true);
    srand(time(0));
    initPipes();
}

int Game::start()
{
    exit = false;
    
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
    setfillstyle(SOLID_FILL, COLOR(230,225,255)); 
    bar(0,0,getmaxx(),getmaxy());

    
    
    setcolor(COLOR(0,0, 150));
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    for(int i = 0; i <= 8; i++) {
        line(66 + i*66, 66, 66 + i*66, 330);       
    } 
    
    for ( int i = 0; i < 5; i++ ) {
         line(66, 66 + i*66, 594, 66 + i*66);
    }
    
    std::vector<Pipe*>::iterator it;
    it = pipes.begin();
    
    while ( it != pipes.end() ) {
     
     (*it)->draw();
     
     it++;   
    }
    
    swapbuffers();
}

void Game::update()
{
    
}

void Game::initPipes() 
{
    level1 = new bool* [4];
    
    for(int count = 0; count < 4; count++) {
            level1[count] = new bool[8];
    } 
    
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            level1[i][j] = 1;
        }
    }
    
    level1[0][0] = 0;
    level1[0][2] = 0;
    level1[0][6] = 0;
    level1[1][0] = 0;
    level1[1][2] = 0;
    level1[1][4] = 0;
    level1[1][6] = 0;
    level1[2][2] = 0;
    level1[2][4] = 0;
    level1[2][5] = 0;
    level1[3][3] = 0;
    
    Pipe *temp;
    
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << level1[i][j] << " " ;
                temp = new Pipe(level1[i][j], 66 + j*66, 66 + i * 66);
                
                pipes.push_back(temp);
        }
        
        std::cout << std::endl;
    }
}

Game::~Game()
{
}
