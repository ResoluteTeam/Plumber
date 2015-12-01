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
        
        int mouseX, mouseY;
        
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        
        if ( mouseX > 66 && mouseX < 594 && mouseY > 66 && mouseY < 330 ) { 
            
            int posX, posY;

            double a, b, xx, yy;
        
            a = mouseX/66;
            b = mouseY/66;
        
            std::modf(a, &xx);
            std::modf(b, &yy);
        
            posX = (int)xx - 1;
            posY = (int)yy - 1;
            
            std::cout << mouseX << ":" << mouseY << std::endl;
            std::cout << posX << ":" << posY << std::endl;
            
            
            std::vector<Pipe*>::iterator it;
            it = pipes.begin();
            
            while ( it != pipes.end() ) {
                if ( (*it)->getRelX() == posX && (*it)->getRelY() == posY ) {
                    (*it)->rotate();
                }
            
            it++;
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
    level1 = new bool* [8];
    
    for(int count = 0; count < 8; count++) {
            level1[count] = new bool[4];
    } 
    
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
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
    
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << level1[i][j] << " " ;
                temp = new Pipe(level1[i][j], 66 + i*66, 66 + j * 66);
                temp->setRelPos(i, j);
                
                pipes.push_back(temp);
        }
        
        std::cout << std::endl;
    }
}

Game::~Game()
{
}
