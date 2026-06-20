#pragma once
#include "menu.h"
#include "alumnoMenu.h"
#include "docenteMenu.h"
#include "aulaMenu.h"
#include "becaMenu.h"
#include "cuotaMenu.h"
#include "materiaMenu.h"

class App: public Menu {
public:
    App();
    void mostrarOpciones() override;
    void ejecutarOpcion (int opcion) override;

private:
    AlumnoMenu _alumnoMenu;
    DocenteMenu _docenteMenu;
    AulaMenu _aulaMenu;
    MateriaMenu _materiaMenu;
    CuotaMenu _cuotaMenu;
    BecaMenu _becaMenu;
};
