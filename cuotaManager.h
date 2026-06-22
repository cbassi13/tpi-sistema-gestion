#pragma once
#include "cuotaArchivo.h"

class CuotaManager {
public:
    CuotaManager();
    void guardarCuota();
    void listarCuotas();
    void modificarCuota();
    void bajaCuota();
    void pagoCuota();

private:
    Cuota crearCuota();
    CuotaArchivo _cuotaArchivo;
};
