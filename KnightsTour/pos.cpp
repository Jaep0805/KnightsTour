#include "pos.h"

int pos::getposx()
{
    return this->posx;
}

int pos::getposy()
{
    return this->posy;
}

void pos::setposx(int x)
{
    this->posx = x;
}


void pos::setposy(int y)
{
    this->posy = y;
}

//return the vector sum of two pos class variables
pos pos::add(pos position)
{
    pos result;
    return pos(posx + position.getposx(), posy + position.getposy());
}


