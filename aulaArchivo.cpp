#include "aulaArchivo.h"

AulaArchivo::AulaArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {
}

bool AulaArchivo::guardar(Aula aula) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr) return false;
    bool result = fwrite(&aula, sizeof(Aula), 1, pFile);
    fclose(pFile);
    return result;
}

Aula AulaArchivo::leer(int pos) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    Aula aula;
    if(pFile == nullptr) return aula;
    fseek(pFile, pos * sizeof(Aula), SEEK_SET);
    fread(&aula, sizeof(Aula), 1, pFile);
    fclose(pFile);
    return aula;
}

int AulaArchivo::getCantidadRegistros() {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return 0;
    fseek(pFile, 0, SEEK_END);
    int cant = ftell(pFile) / sizeof(Aula);
    fclose(pFile);
    return cant;
}

int AulaArchivo::getNuevoId() {
    return getCantidadRegistros() + 1;
}
