#include <iostream>
#include "app.h"
using namespace std;

App::App();{
int setCantidadOpciones (1);

}
void App::mostrarOpciones(){
   cout << "----- MENU APP ---------"<<endl;
   cout << "1- MENU"<<endl;
   cout << "0- SALIR"<<endl;
   cout << "------------------------"<<endl;
}
void App::ejecutarOpcion(int opcion){
   switch(opcion){
   case 1:
      _menu.run();
      break;
   case 0:
      cout << "Gracias por usar mi app :)" << endl;
   }
}
