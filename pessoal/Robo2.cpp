#include "Robo2.h"

Robo2::Robo2()
{
    tipo = 6;
    modelo = new Model3DS("../3ds/robo2.3DS");
}

void Robo2::desenha()
{

    Objeto::desenha();



    glPushMatrix();


         glRotatef(-90,1,0,0);
         glRotatef(-90,0,0,1);
         glScalef(0.0007, 0.0007, 0.0007);

         modelo->draw();
    glPopMatrix();

}
