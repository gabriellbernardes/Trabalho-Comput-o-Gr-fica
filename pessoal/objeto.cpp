#include "objeto.h"

Objeto::Objeto()
{

}

void Objeto::desenha()
{
    glTranslatef(t.x,t.y,t.z);
    if(selecionado){
        glPushMatrix();
        GUI::setColor(1,0,0);
        glRotatef(-90,1,0,0);
        glScalef(2,2,2);
        Objeto::Circulo();
        glPopMatrix();
//    glRotatef(l+=1,0,1,0);
//    l%=360;
    }
    glRotatef(a.z,0,0,1);
    glRotatef(a.y,0,1,0);
    glRotatef(a.x,1,0,0);
    if(origem){
    GUI::drawOrigin(1);
    }
    glScalef(s.x,s.y,s.z);

}


void Objeto :: Quadrado(){
    glBegin(GL_QUADS);
        glNormal3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(0,1,0);
    glEnd();

}

void Objeto ::Circulo(){

    int i, x=0, y=0;
    double radius = 0.50;
    double twicePi = 2.0 * 3.142;

    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex3f(x, y, 0); // center of circle
    for (i = 0; i <= 50; i++)   {
        glVertex3f ((x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20))),0);
    }
    glEnd(); //END
    glPopMatrix();
}
void Objeto :: Relogio1(float s){

    int i, x=0, y=0;
    double radius = 0.50;
    double twicePi = 2.0 * 3.142;
    GUI::setColor(1,1,1);
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex3f(x, y, 0); // center of circle
    for (i = 0; i <= 50; i++)   {
        glVertex3f ((x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20))),0);
    }
    glEnd(); //END
    glPopMatrix();

    GUI::setColor(0,0,0);

    glPushMatrix();
        glRotatef(-(h+=s),0,0,1);
        glTranslatef(-0.025,0,0.025);
        glScalef(0.05,0.5,0);
        Cubo();
    glPopMatrix();

   if(h>359){
      h=0;   }
}

void Objeto :: Relogio2(float s){

    int i, x=0, y=0;
    double radius = 0.50;
    double twicePi = 2.0 * 3.142;
    GUI::setColor(1,1,1);
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex3f(x, y, 0); // center of circle
    for (i = 0; i <= 50; i++)   {
        glVertex3f ((x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20))),0);
    }
    glEnd(); //END
    glPopMatrix();

    GUI::setColor(0,0,0);

    glPushMatrix();
        glRotatef(-(g+=s),0,0,1);
        glTranslatef(-0.025,0,0.025);
        glScalef(0.05,0.5,0);
        Cubo();
    glPopMatrix();

   if(g>359){
      g=0;   }
}
void Objeto :: Cubo(){
   glPushMatrix();
    glBegin(GL_QUADS);
        glNormal3f(0,0,1.1);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(0,1,0);
    glEnd();


    glBegin(GL_QUADS);
        glNormal3f(0,0,1);
        glVertex3f(0,0,-1);
        glVertex3f(0,1,-1);
        glVertex3f(1,1,-1);
        glVertex3f(1,0,-1);
    glEnd();


    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,0,-1);
        glVertex3f(1,1,-1);
        glVertex3f(1,1,0);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,-1);
        glVertex3f(0,0,-1);
    glEnd();



    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,-1);
        glVertex3f(1,0,-1);
        glVertex3f(1,0,0);
    glEnd();


    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(0,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,1,-1);
        glVertex3f(0,1,-1);
    glEnd();

  glPopMatrix();


}
void Objeto :: Cilindro(){
    //Base Cilindro
    glPushMatrix();
    glTranslatef(0,0,0);
    glRotatef(-180,1,0,0);

    int i1, x1=0, y1=0;

    double radius1 = 0.50;
    double twicePi1 = 2.0 * 3.142;

    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex3f(x1, y1, 0); // center of circle
    for (i1 = 0; i1 <= 50; i1++)   {
        glVertex3f ((x1 + (radius1 * cos(i1 * twicePi1 / 20))), (y1 + (radius1 * sin(i1 * twicePi1 / 20))),0);
    }
    glEnd(); //END
    glPopMatrix();
    //Topo Cilindro
    glPushMatrix();
    glTranslatef(0,0,4);
    int i, x=0, y=0;
    double radius = 0.50;
    double twicePi = 2.0 * 3.142;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex3f(x, y, 0); // center of circle
    for (i = 0; i <= 50; i++)   {
        glVertex3f ((x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20))),0);
    }
    glEnd(); //END
    glPopMatrix();

    GLUquadric *quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    glPushMatrix();
    gluCylinder(quad, 0.5,0.5,4,12,3);
    //GUI::drawSphere(2,2,2,0.15);
    glPopMatrix();
    }


