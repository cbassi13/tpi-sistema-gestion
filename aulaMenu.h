#pragma once
#include "aulaManager.h"
#include "menu.h"

class AulaMenu : public Menu {
public:
    AulaMenu();
    void mostrarOpciones() override;
    void ejecutarOpcion(int opcion) override;

private:
    AulaManager _managerAula;
};
