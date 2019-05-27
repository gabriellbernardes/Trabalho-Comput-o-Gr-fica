#include <iostream>

using namespace std;

//#include <gui.h>
#include <vector>

//#include <objeto.h>
#include <personagem.h>
#include <casa.h>
#include <robo.h>
#include <Robo2.h>
#include <Robo3.h>
#include <ring.h>
#include <painel.h>
#include<fstream>

//Model3DS model3ds("../3ds/cartest.3DS");

vector<Objeto*> objetos;
vector<Camera*> cameras;
int marcaCamera = -1;
int posSelecionado = -1;

void salvar (){
    ofstream save("save.txt");

    for(int i =0; i<objetos.size(); i++){
        save << objetos[i]->tipo << endl;
        save << objetos[i]->t.x << endl;
        save << objetos[i]->t.y << endl;
        save << objetos[i]->t.z << endl;
        save << objetos[i]->a.x << endl;
        save << objetos[i]->a.y << endl;
        save << objetos[i]->a.z << endl;
        save << objetos[i]->s.x << endl;
        save << objetos[i]->s.y << endl;
        save << objetos[i]->s.z << endl;
    }
}

void carregar (){
    ifstream carrega("save.txt");
    string linha;
    int tipo, i = 0;
    Vetor3D t, a,s;
    while(getline(carrega, linha)){
        tipo =stoi(linha);
        getline(carrega, linha);
        t.x = stof(linha);
        getline(carrega, linha);
        t.y = stof(linha);
        getline(carrega, linha);
        t.z = stof(linha);
        getline(carrega, linha);
        a.x = stof(linha);
        getline(carrega, linha);
        a.y = stof(linha);
        getline(carrega, linha);
        a.z = stof(linha);
        getline(carrega, linha);
        s.x = stof(linha);
        getline(carrega, linha);
        s.y = stof(linha);
        getline(carrega, linha);
        s.z = stof(linha);

        switch (tipo) {
        case 1:
            objetos.push_back(new Casa());

            break;
        case 2:
            objetos.push_back(new Painel());

            break;
        case 3:
            objetos.push_back(new Personagem());

            break;
        case 4:
            objetos.push_back(new Ring());

            break;
        case 5:
            objetos.push_back(new Robo());

            break;
        case 6:
            objetos.push_back(new Robo2());

            break;
        case 7:
            objetos.push_back(new Robo3());

            break;

        default:
            break;
        }
        objetos[i]->t = t;
        objetos[i]->a = a;
        objetos[i]->s = s;
        i++;

    }
}



void desenha() {
    GUI::displayInit();

    GUI::setLight(1,1,3,5,true,false);
    GUI::setLight(2,-1.5,0.5,-1,true,false);
    //GUI::setLight(3,-5,3,5,true,false);

    GUI::drawOrigin(1);
    GUI::setColor(1,0,0);
    //GUI::drawFloor();



    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }


    GUI::displayEnd();
}

bool incluirObjeto = false;

void teclado(unsigned char key, int x, int y) {
    //if (!incluirObjeto) {
        GUI::keyInit(key,x,y);
    //}

    switch (key) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'n':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;
        posSelecionado = posSelecionado%objetos.size();
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;
    case 'b':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado--;
        if (posSelecionado < 0) {
            posSelecionado = objetos.size()-1;
        }
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    case 'O':
        incluirObjeto = !incluirObjeto;
        break;
    case 'p':
        if (incluirObjeto) {
            objetos.push_back( new Personagem() );
        }
        break;
    case 'c':
        marcaCamera++;
        if(marcaCamera>=cameras.size()){
            marcaCamera =0;
        }
        glutGUI::cam = new CameraDistante(cameras[marcaCamera]->e, cameras[marcaCamera]->c, cameras[marcaCamera]->u);
        break;

    case 'r':
        if (incluirObjeto) {
            objetos.push_back( new Robo() );
        }
        break;
    case 'w':
        if (incluirObjeto) {
            objetos.push_back( new Robo2() );
        }
        break;
    case 'e':
        if (incluirObjeto) {
            objetos.push_back( new Robo3() );
        }
        break;
    case 'a':
        if (incluirObjeto) {
            objetos.push_back( new Ring() );
        }
        break;
    case 's':
        if (incluirObjeto) {
            objetos.push_back( new Painel() );
        }
        break;
    case 'f':
        if (incluirObjeto) {
            objetos.push_back( new Casa() );
        }
        break;

    case 'k':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->origem = !objetos[posSelecionado]->origem;
        }
        break;
    case 'd':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos.erase(objetos.begin()+posSelecionado, objetos.begin()+posSelecionado+1);
        }
        break;
    case 'D':
        if(!objetos.empty()){
            objetos.pop_back();
        }
        break;
    case 'S':
        salvar();

        break;

    case 'C':
        carregar();

        break;

    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    cameras.push_back(new CameraDistante(0,10,-4.7,0,0,0,0,1,0));
    cameras.push_back(new CameraDistante(4.7,10,0,0,0,0,0,1,0));
    cameras.push_back(new CameraDistante(15,5,15,0,0,0,0,1,0));
    cameras.push_back(new CameraDistante(-15,5,-15,0,0,0,0,1,0));
    GUI gui = GUI(800,600,desenha,teclado);

}


//while(true) {
//    desenha();
//    interacaoUsuario();
//}
