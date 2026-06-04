#pragma once
#include "managerAlumno.h"
#include "menu.h"

class AlumnoMenu: public Menu {
public:
   AlumnoMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);

private:
   AlumnoManager _managerAlumno;
};




