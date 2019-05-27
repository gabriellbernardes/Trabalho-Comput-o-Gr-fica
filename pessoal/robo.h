#ifndef ROBO_H
#define ROBO_H

#include "objeto.h"

class Robo : public Objeto
{
public:
    Model3DS *modelo;
    Robo();
    void desenha();
};

#endif // ROBO_H
