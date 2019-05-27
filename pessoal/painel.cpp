#include "painel.h"
#include "math.h"
#define PI 3.1415926535898

Painel::Painel()
{
    tipo =2;

}

void Painel::desenha(){

  glPushMatrix();
  glTranslatef(-1.5,0,0);
     Objeto::desenha();


   // GLint longitude=25;
  //GLint latitude=25;
 // GLint raioEsfera=1;


       //  glTranslatef(0.0,3,-3.0);
       //  glutSolidSphere(1,25,25);
    GUI::setColor(0,0,0);
     glTranslatef(0.0,2,0);
  //base
     glPushMatrix();

         glPushMatrix();
            glScalef(3,1.5,0.1);
            Objeto::Cubo();
         glPopMatrix();

         glPushMatrix();
            glTranslatef(0.1,0,0);
            glRotatef(180,0,0,1);
            glScalef(0.1,1.9,0.1);
            Objeto::Cubo();
         glPopMatrix();

         glPushMatrix();
             glTranslatef(3,0,0);
             glRotatef(180,0,0,1);
             glScalef(0.1,1.9,0.1);
             Objeto::Cubo();
         glPopMatrix();

    glPopMatrix();
    //fundo painel
    glPushMatrix();
        GUI::setColor(0.5,0.5,1);
        glTranslatef(0.25,0.25,0.01);
        glScalef(2.5,1,0.01);
        Objeto::Cubo();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.8,0.75,0.025);
        Objeto::Relogio1(0.5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.2,0.75,0.025);
        Objeto::Relogio2(5);
    glPopMatrix();


  glPopMatrix();

}
