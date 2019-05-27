#ifndef OBJETO_H
#define OBJETO_H

#include <gui.h>

class Objeto
{
public:
    Vetor3D t = Vetor3D(0,0,0);
    Vetor3D a = Vetor3D(0,0,0);
    Vetor3D s = Vetor3D(1,1,1);
    float h = 0.0, g = 0.0;
    int l=0;
    bool selecionado = false;
    bool origem = false;
    int tipo;
public:
    Objeto();
    virtual void desenha();

    void Quadrado();
    void Cubo();
    void Relogio1(float s);
    void Relogio2(float s);
    void Cilindro();
    void Circulo();

};

#endif // OBJETO_H
