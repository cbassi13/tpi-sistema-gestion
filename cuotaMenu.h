#pragma once
#include "cuotaManager.h"
#include "menu.h"

class CuotaMenu : public Menu {
public:
    CuotaMenu();
    void mostrarOpciones() override;
    void ejecutarOpcion(int opcion) override;

private:
    CuotaManager _managerCuota;
};
