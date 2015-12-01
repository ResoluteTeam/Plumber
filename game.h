#ifndef GAME_H
#define GAME_H

#include "button.h"
#include "label.h"
#include "graphics.h"
#include "iostream"
#include "vector"
#include "cmath"
#include "pipe.h"
#include <string>
        
class Game
{
public:
    Game();
    ~Game();
    int start();

private:
    void processEvents();
    void render();
    void update();
    
    Pipe* pipe;
    
    bool exit;
    
    bool** level1;
};

#endif // GAME_H
