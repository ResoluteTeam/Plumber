#ifndef PIPE_H
#define PIPE_H

#include "graphics.h"
//bool type, if 0 - straight, 1 - curve
//size = 66x66
//direction, if 0 - up, 1 - right, 2 - dawn, 3 - right


class Pipe {
public:
        Pipe(bool typeOfFigure, int positionX, int positionY);   
        
        void setPosition(int x, int y);
        int getX();
        int getY();
        
        void rotate();
        void rotate(int count);
        
        void draw();
        
private:
        bool type;
        int direction;
        int x, y;
        int size;
        bool filled;
};

#endif //PIPE_H
