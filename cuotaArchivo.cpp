#include "cuotaArchivo.h"

CuotaArchivo::CuotaArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {
}

bool CuotaArchivo::guardar(Cuota cuota) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr) return false;
    bool result = fwrite(&cuota, sizeof(Cuota), 1, pFile);
    fclose(pFile);
    return result;
}

bool CuotaArchivo::modificar(Cuota cuota, int pos) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == nullptr) return false;

    fseek(pFile, pos * sizeof(Cuota), SEEK_SET);
    bool modifico = fwrite(&cuota, sizeof(Cuota), 1, pFile);

    fclose(pFile);
    return modifico;
}

Cuota CuotaArchivo::leer(int pos) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    Cuota cuota;
    if(pFile == nullptr) return cuota;
    fseek(pFile, pos * sizeof(Cuota), SEEK_SET);
    fread(&cuota, sizeof(Cuota), 1, pFile);
    fclose(pFile);
    return cuota;
}

int CuotaArchivo::getCantidadRegistros() {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return 0;
    fseek(pFile, 0, SEEK_END);
    int cant = ftell(pFile) / sizeof(Cuota);
    fclose(pFile);
    return cant;
}

int CuotaArchivo::getNuevoId() {
    return getCantidadRegistros() + 1;
}
