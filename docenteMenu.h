#pragma once
#include "docenteManager.h"
#include "menu.h"

class DocenteMenu : public Menu {
public:
    DocenteMenu();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

private:
    DocenteManager _docenteManager;
};
