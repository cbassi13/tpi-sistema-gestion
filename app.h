#pragma once
#include "menu.h"
#include "menuAlumno.h"
#include "menuDocente.h"


class App: public Menu {
public:
  App();
  void mostrarOpciones() override;
  void ejecutarOpcion (int opcion) override;

private:
  AlumnoMenu _menuAlumno;
  DocenteMenu _menuDocente;

};
