#include "robo.h"

Robo::Robo()
{
    tipo =5;
    modelo = new Model3DS("../3ds/robo1.3DS");
}

void Robo::desenha()
{

    Objeto::desenha();

    glPushMatrix();

      glRotatef(-90, 0, 1, 0);
      glRotatef(-90, 1, 0, 0);
      glRotatef(90, 0, 0, 1);
      glScalef(0.00032, 0.00032, 0.00032);

      modelo->draw();
    glPopMatrix();

}
