#pragma once

#include "carreraManager.h"
#include "menu.h"

class CarreraMenu : public Menu {
public:
    CarreraMenu();

    void mostrarOpciones() override;
    void ejecutarOpcion(int opcion) override;

private:
    CarreraManager _managerCarrera;
};
