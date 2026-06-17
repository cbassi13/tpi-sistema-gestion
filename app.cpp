#include <iostream>
#include "app.h"
using namespace std;

App::App(){
    setCantidadOpciones(2);
}

void App::mostrarOpciones(){
   cout << "----- MENU APP ---------"<<endl;
   cout << "1- MENU ALUMNOS"<<endl;
   cout << "2- MENU DOCENTES "<<endl;
   cout << "0- SALIR"<<endl;
   cout << "------------------------"<<endl;
}
void App::ejecutarOpcion(int opcion){
   switch(opcion){
   case 1:
      _menuAlumno.run();
   case 2:
      _menuDocente.run();
      break;
   case 0:
      cout << "Gracias por usar mi app :)" << endl;
   }
}
