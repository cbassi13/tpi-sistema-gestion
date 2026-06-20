#include "becaArchivo.h"

BecaArchivo::BecaArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {
}

bool BecaArchivo::guardar(Beca beca) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr) return false;
    bool result = fwrite(&beca, sizeof(Beca), 1, pFile);
    fclose(pFile);
    return result;
}

Beca BecaArchivo::leer(int pos) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    Beca beca;
    if(pFile == nullptr) return beca;
    fseek(pFile, pos * sizeof(Beca), SEEK_SET);
    fread(&beca, sizeof(Beca), 1, pFile);
    fclose(pFile);
    return beca;
}

int BecaArchivo::getCantidadRegistros() {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return 0;
    fseek(pFile, 0, SEEK_END);
    int cant = ftell(pFile) / sizeof(Beca);
    fclose(pFile);
    return cant;
}

int BecaArchivo::getNuevoId() {
    return getCantidadRegistros() + 1;
}
