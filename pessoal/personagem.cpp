#include "personagem.h"
#include "ctime"

Personagem::Personagem()
{
    tipo =3;
     modelo = new Model3DS("../3ds/arma.3DS");
}

void Personagem::desenha()
{
    GUI::setColor((float)(rand())/(float)(RAND_MAX)*1.0,(float)(rand())/(float)(RAND_MAX)*1.0,(float)(rand())/(float)(RAND_MAX)*1.0);



    glScalef(0.2,0.2,0.2);
    glTranslatef(0,3,0);
    glPushMatrix();
        Objeto::desenha();

//        glScalef(0.7,0.7,0.7);
//        glRotatef(0,1,0,0);
//        glTranslatef(0,0,0);
//        glScalef(1,1,1);
        //cara





//        glPushMatrix();
//             Objeto::Cubo();
//        glPopMatrix();
        //cabeca
        glPushMatrix();

        glTranslatef(0,2.3,0);
        glutSolidSphere(1,20,20);
        glPopMatrix();

        //pescoco
        glPushMatrix();
            glScaled(0.5,0.09,0.5);
            glRotatef(-90,1,0,0);
            glTranslatef(0,0,11);
            Objeto::Cilindro();
        glPopMatrix();

        //pelvis
        glPushMatrix();
            //transformacoes influenciam todo o escopo push/pop
            glTranslatef(0,-1,0);
            glRotatef(0,1,0,0);
           // GUI::drawOrigin(0.5);
            //modelo

            GUI::drawBox(-0.5,0.0,-0.5, 0.5,0.5,0.5);

            //tronco
            glPushMatrix();
                glTranslatef(0,0.5,0);
                glRotatef(glutGUI::lx,1,0,0);
              //  GUI::drawOrigin(0.5);
                //modelo

                GUI::drawBox(-0.5,0.0,-0.5, 0.5,1.5,0.5);

                //braco direito
                glPushMatrix();
                    //transformacoes influenciam apenas localmente (escopo push/pop mais interno)
                    glTranslatef(0.5,1.4,0);
                    glRotatef(glutGUI::ly,0,0,1);
                   glRotatef(-90,0,1,0);
                   glRotatef(l+=1,0,0,1);
                    l%=45;
                  //  GUI::drawOrigin(0.5);
                    //modelo

                    glTranslatef(1,0,0);
                    GUI::drawBox(-1.0,0.0,-0.1, 1.0,0.2,0.1);
                glPopMatrix();
//arma
                glPushMatrix();
                     glScalef(0.08, 0.05, 0.05);
                     glRotatef(-90,0,0,1);
                     glRotatef(-90,0,1,0);
                     glTranslatef(40,0,20);
                     glRotatef(p-=1,0,1,0);
                   p%=45;

                     modelo->draw();
                glPopMatrix();

                //braco esquerdo
                glPushMatrix();
                    glTranslatef(-0.5,1.4,0);
                    glRotatef(95,0,1,0);
                    glRotatef(45,0,0,1);
                    glRotatef(s-=1,0,0,1);
                    s%=-45;
                    //GUI::drawOrigin(0.5);
                    //modelo

                    glTranslatef(-1,0,0);
                    GUI::drawBox(-1.0,0.0,-0.1, 1.0,0.2,0.1);
                glPopMatrix();
                //perna esquerda
                glPushMatrix();
                        glScalef(0.5,0.5,0.5);
                        glRotatef(90,1,0,0);
                        //glRotatef(-45,0,1,0);
                       glTranslatef(-0.6,0,1);
                    Objeto::Cilindro();

                glPopMatrix();
                //perna direita
                glPushMatrix();
                        glScalef(0.5,0.5,0.5);
                        glRotatef(90,1,0,0);
                        //glRotatef(-45,0,1,0);
                       glTranslatef(0.6,0,1);
                    Objeto::Cilindro();

                glPopMatrix();

            glPopMatrix();
        glPopMatrix();

    glTranslatef(0,2.4,0);
        glPushMatrix();
        GUI::setColor(0,0,0);
            glScalef(0.5,0.5,0.17);
            glTranslatef(1,0,2);
            Objeto::Cilindro();
        glPopMatrix();
        glPushMatrix();
        glScalef(0.5,0.5,0.17);
        glTranslatef(-1,0,2);
            Objeto::Cilindro();
        glPopMatrix();
            glPopMatrix();
            //boca
            glPushMatrix();
            glScalef(0.5,0.5,0.17);
            glTranslatef(0,3.5,3);
                glutSolidSphere(1,20,20);
            glPopMatrix();

    glPopMatrix();
}
