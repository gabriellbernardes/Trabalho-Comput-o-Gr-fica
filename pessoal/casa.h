#ifndef CASA_H
#define CASA_H

#include <objeto.h>

class Casa : public Objeto
{

public:
    Model3DS *modelo;
    Model3DS *modelo2;
    Casa();
    void desenha();
};

#endif // CASA_H
