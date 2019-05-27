#include "casa.h"

Casa::Casa()
{
    tipo =1;
    modelo = new Model3DS("../3ds/arma2.3DS");
    modelo2 = new Model3DS("../3ds/arma3.3DS");

}

void Casa::desenha()
{
      Objeto::desenha();
    glPushMatrix();

         glPushMatrix();

             glScalef(0.01,0.01,0.01);
             modelo->draw();


        glPopMatrix();

        glPushMatrix();
            glScalef(0.001,0.001,0.001);

            modelo2->draw();

        glPopMatrix();

    glPopMatrix();
}
