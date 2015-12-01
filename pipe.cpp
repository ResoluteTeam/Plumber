#include "pipe.h"

Pipe::Pipe(bool typeOfFigure, int positionX, int positionY)
{
    size = 66;
    type = typeOfFigure;
    x = positionX;
    y = positionY;
    
    
    direction = rand()%3;
}   
        
void Pipe::setPosition(int positionX, int positionY)
{
    x = positionX;
    y = positionY;    
}

int Pipe::getX()
{
    return x;    
}

int Pipe::getY()
{
    return y;    
}
        
void Pipe::rotate()
{
    if(direction < 3)
        direction++;
    else direction = 0;    
}

void Pipe::rotate(int count)
{
    for(int i = 0; i < count; i++)
    {
        rotate();
    }    
}
        
void Pipe::draw()
{
//    setfillstyle(1, 1);
    if(type) // if curve
    {
        switch(direction)
        {
            
            case 0:
                {
                    rectangle(x + 18, y + 1, x + 48, y + 8);
                    rectangle(x + 57, y + 18, x + 65, y + 48);
                    
                    bar(x + 19, y + 2, x + 48, y + 8);
                    bar(x + 58, y + 19, x + 65, y + 48);
                    bar(x + 24, y + 10, x + 43, y + 43);
                    bar(x + 43, y + 24, x + 57, y + 43);
                }
            break;
            
            case 1:
                {
                    rectangle(x + 57, y + 18, x + 65, y + 48); 
                    rectangle(x + 18, y + 57, x + 48, y + 65);
                    
                    bar(x + 58, y + 19, x + 65, y + 48); 
                    bar(x + 19, y + 58, x + 48, y + 65);
                    bar(x + 43, y + 24, x + 57, y + 43);
                    bar(x + 24, y + 24, x + 43, y + 57);
                }
            break;
            
            case 2:
                {
                    rectangle(x + 18, y + 57, x + 48, y + 65);
                    rectangle(x + 1, y + 18, x + 8, y + 48);
                    
                    bar(x + 19, y + 58, x + 48, y + 65);
                    bar(x + 2, y + 19, x + 8, y + 48);
                    bar(x + 24, y + 24, x + 43, y + 57);
                    bar(x + 9, y + 24, x + 43, y + 43);
                }
            break;
            
            case 3:
                {
                    rectangle(x + 1, y + 18, x + 8, y + 48);
                    rectangle(x + 18, y + 1, x + 48, y + 8);
                    
                    bar(x + 19, y + 2, x + 48, y + 8);
                    bar(x + 2, y + 19, x + 8, y + 48);
                    bar(x + 24, y + 10, x + 43, y + 43);
                    bar(x + 9, y + 24, x + 43, y + 43);
                }
            break;
        }
    }
    
    else // if straight
    {
        if(direction == 0 || direction == 2)
        {
            //setcolor(0);
            rectangle(x + 18, y + 1, x + 48, y + 8);
            rectangle(x + 18, y + 57, x + 48, y + 65);
            rectangle(x + 23, y + 8, x + 43, y + 57);
            
            //setfillstyle(1, 1);
            bar(x + 19, y + 2, x + 48, y + 8);
            bar(x + 19, y + 58, x + 48, y + 65);
            bar(x + 24, y + 9, x + 43, y + 57);
        }
        
        else if (direction == 1 || direction == 3)
        {   
            //setcolor(0);
            rectangle(x + 1, y + 18, x + 8, y + 48);
            rectangle(x + 57, y + 18, x + 65, y + 48);
            rectangle(x + 8, y + 23, x + 57, y + 43);
            
            //setfillstyle(1, 1);
            bar(x + 2, y + 19, x + 8, y + 48);
            bar(x + 58, y + 19, x + 65, y + 48);
            bar(x + 9, y + 24, x + 57, y + 43);
            //rectangle(x )
        }    
    }
}


int Pipe::getRelX() 
{
    return relX;
}

int Pipe::getRelY() 
{
    return relY;
}
        
void Pipe::setRelPos(int x, int y) 
{
    relX = x;
    
    relY = y;
}
