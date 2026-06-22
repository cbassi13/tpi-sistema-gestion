#pragma once
#include "materiaManager.h"
#include "menu.h"

class MateriaMenu : public Menu {
public:
    MateriaMenu();
    void mostrarOpciones() override;
    void ejecutarOpcion(int opcion) override;

private:
    MateriaManager _managerMateria;
};
