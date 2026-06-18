#include <iostream>
#include "menuAlumno.h"
#include <cstdio>

using namespace std;

Menu::Menu(){}

void Menu::run(){

   int opcion;
   while(true){
      system("cls");
      mostrarOpciones();
      cout << "Ingrese opcion: ";
      cin >> opcion;

      if(opcion == 0){
         return;
      }

      ejecutarOpcion(opcion);
      system("pause");
   }
}
