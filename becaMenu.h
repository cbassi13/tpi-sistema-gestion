#pragma once
#include "becaManager.h"
#include "menu.h"

class BecaMenu : public Menu {
public:
    BecaMenu();
    void mostrarOpciones() override;
    void ejecutarOpcion(int opcion) override;

private:
    BecaManager _managerBeca;
};

