#ifndef ROBO2_H
#define ROBO2_H

#include "objeto.h"


class Robo2 : public Objeto
{
public:
    Model3DS *modelo;
    Robo2();
    void desenha();
};

#endif // ROBO2_H
