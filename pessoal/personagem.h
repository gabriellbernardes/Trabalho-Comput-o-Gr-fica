#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <objeto.h>

class Personagem : public Objeto
{
public:
    Model3DS *modelo;
    Personagem();
    void desenha();
    int l =0;
    int s= 0;
    int p =0;
};

#endif // PERSONAGEM_H
