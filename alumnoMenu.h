#pragma once
#include "alumnoManager.h"
#include "menu.h"

class AlumnoMenu: public Menu {
public:
   AlumnoMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);

private:
   AlumnoManager _alumnoManager;
};




