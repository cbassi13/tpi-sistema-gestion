#pragma once
#include <string>
#include "cuota.h"

class CuotaArchivo {
public:
    CuotaArchivo(std::string nombreArchivo = "cuotas.dat");
    bool guardar(Cuota cuota);
    bool modificar(Cuota cuota, int pos);
    Cuota leer(int pos);
    int getCantidadRegistros();
    int getPosByIdCuota(int idCuota);
    int getNuevoId();

private:
    std::string _nombreArchivo;
};
