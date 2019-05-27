#include "ring.h"

Ring::Ring()
{
    tipo = 4;

}

void Ring::desenha(){


    glPushMatrix();
     Objeto::desenha();

       glTranslatef(-2.5,-0.215,2.5);
        //base do ring
       glPushMatrix();
            GUI::setColor(0,0,0);
           glScalef(5,0.2,5);
           Objeto::Cubo();
       glPopMatrix();
       GUI::setColor(1,0,0);
        glPushMatrix();
            // coluna inferior esq
           glPushMatrix();

                glTranslatef(0,0.2,0);
                glScalef(0.3,1,0.3);
                Objeto::Cubo();
           glPopMatrix();
            //coluna superior esq
           glPushMatrix();

                glTranslatef(0,0.2,-4.7);
                glScalef(0.3,1,0.3);
                Objeto::Cubo();
           glPopMatrix();
            //coluna inferior dir
           glPushMatrix();

                glTranslatef(4.7,0.2,0);
                glScalef(0.3,1,0.3);
               Objeto::Cubo();
           glPopMatrix();
            // coluna superior dir
           glPushMatrix();

                glTranslatef(4.7,0.2,-4.7);
                glScalef(0.3,1,0.3);
                Objeto::Cubo();
           glPopMatrix();
     glPopMatrix();
    //cordas
    GUI::setColor(1,1,1);
    glPushMatrix();

       // cordas 1
       glPushMatrix();
           glPushMatrix();
               glTranslatef(0.3,1,-0.1);
               glScalef(4.4,0.1,0.1);
               Objeto::Cubo();
           glPopMatrix();

           glPushMatrix();
               glTranslatef(0.3,0.7,-0.1);
               glScalef(4.4,0.1,0.1);
               Objeto::Cubo();
           glPopMatrix();

           glPushMatrix();
               glTranslatef(0.3,0.4,-0.1);
               glScalef(4.4,0.1,0.1);
               Objeto::Cubo();
           glPopMatrix();
        glPopMatrix();

        // cordas 2

        glPushMatrix();
            glTranslatef(0.2,0,0);
            glRotatef(90,0,1,0);
            glPushMatrix();
                glTranslatef(0.3,1,0);
                glScalef(4.4,0.1,0.1);
                Objeto::Cubo();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.3,0.7,0);
                glScalef(4.4,0.1,0.1);
                Objeto::Cubo();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.3,0.4,0);
                glScalef(4.4,0.1,0.1);
                Objeto::Cubo();
            glPopMatrix();
         glPopMatrix();

         // cordas 3


         glPushMatrix();
                glTranslatef(0,0,-4.8);
                 glPushMatrix();
                     glTranslatef(0.3,1,0);
                     glScalef(4.4,0.1,0.1);
                     Objeto::Cubo();
                 glPopMatrix();

                 glPushMatrix();
                     glTranslatef(0.3,0.7,0);
                     glScalef(4.4,0.1,0.1);
                     Objeto::Cubo();
                 glPopMatrix();

                 glPushMatrix();

                     glTranslatef(0.3,0.4,0);
                     glScalef(4.4,0.1,0.1);
                     Objeto::Cubo();
                 glPopMatrix();
          glPopMatrix();
          // cordas 4

          glPushMatrix();
              glTranslatef(4.9,0,0);
              glRotatef(90,0,1,0);
              glPushMatrix();
                  glTranslatef(0.3,1,0);
                  glScalef(4.4,0.1,0.1);
                  Objeto::Cubo();
              glPopMatrix();

              glPushMatrix();
                  glTranslatef(0.3,0.7,0);
                  glScalef(4.4,0.1,0.1);
                  Objeto::Cubo();
              glPopMatrix();

              glPushMatrix();
                  glTranslatef(0.3,0.4,0);
                  glScalef(4.4,0.1,0.1);
                  Objeto::Cubo();
              glPopMatrix();
           glPopMatrix();

     glPopMatrix();

     //arquibancada
     glPushMatrix();
     GUI::setColor(0,0.2,0.5);
     glTranslatef(-5,-0.2,5);
     glScalef(15,0.2,15);
     Objeto::Cubo();
     glPopMatrix();


    glPopMatrix();


}
