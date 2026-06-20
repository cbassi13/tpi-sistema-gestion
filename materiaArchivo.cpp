#include "materiaArchivo.h"

MateriaArchivo::MateriaArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {
}

bool MateriaArchivo::guardar(Materia materia) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr) return false;
    bool result = fwrite(&materia, sizeof(Materia), 1, pFile);
    fclose(pFile);
    return result;
}

bool MateriaArchivo::modificar(Materia materia, int pos) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == nullptr) return false;

    fseek(pFile, pos * sizeof(Materia), SEEK_SET);
    bool modifico = fwrite(&materia, sizeof(Materia), 1, pFile);

    fclose(pFile);
    return modifico;
}

Materia MateriaArchivo::leer(int pos) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    Materia materia;
    if(pFile == nullptr) return materia;
    fseek(pFile, pos * sizeof(Materia), SEEK_SET);
    fread(&materia, sizeof(Materia), 1, pFile);
    fclose(pFile);
    return materia;
}

int MateriaArchivo::getCantidadRegistros() {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return 0;
    fseek(pFile, 0, SEEK_END);
    int cant = ftell(pFile) / sizeof(Materia);
    fclose(pFile);
    return cant;
}

int MateriaArchivo::getNuevoId() {
    return getCantidadRegistros() + 1;
}
