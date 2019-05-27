#include "Robo3.h"



Robo3::Robo3()
{
    tipo =7;
    modelo = new Model3DS("../3ds/robo3.3DS");

}

void Robo3::desenha()
{
    Objeto::desenha();

    glPushMatrix();


         glRotatef(-180,0,0,1);
         glRotatef(90,1,0,0);
         glRotatef(180,0,0,1);
        // GUI::drawOrigin(1);
         glScalef(0.006, 0.008, 0.007);

         modelo->draw();
    glPopMatrix();

}
