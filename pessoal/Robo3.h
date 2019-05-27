#ifndef ROBO3_H
#define ROBO3_H
#include "objeto.h"


class Robo3: public Objeto
{
public:
    Model3DS *modelo;
    Robo3();
    void desenha();
};

#endif // ROBO3_H
