#include <iostream>
#include "app.h"
using namespace std;

App::App(){

}

void App::mostrarOpciones(){
   cout << "----- MENU APP ---------"<<endl;
   cout << "1- ALUMNOS"<<endl;
   cout << "2- DOCENTES "<<endl;
   cout << "3- AULAS" << endl;
   cout << "6- BECAS" << endl;
   cout << "0- SALIR"<<endl;
   cout << "------------------------"<<endl;
}
void App::ejecutarOpcion(int opcion){
    switch(opcion){
        case 1:
            _alumnoMenu.run();
            break;
        case 2:
            _docenteMenu.run();
            break;
        case 3:
            _aulaMenu.run();
        case 6:
            _becaMenu.run();
            break;
        case 0:
            cout << "Gracias por usar mi app :)" << endl;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
    }
}
