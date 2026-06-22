#include "carreraArchivo.h"

CarreraArchivo::CarreraArchivo(std::string nombreArchivo)
    : _nombreArchivo(nombreArchivo) {

}

bool CarreraArchivo::guardar(const Carrera &reg) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&reg, sizeof(Carrera), 1, pFile);

    fclose(pFile);

    return result;
}

Carrera CarreraArchivo::leer(int pos) {
    FILE *pFile;
    Carrera reg;

    reg.setIdCarrera(-1);

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(pFile, pos * sizeof(Carrera), SEEK_SET);

    fread(&reg, sizeof(Carrera), 1, pFile);

    fclose(pFile);

    return reg;
}

int CarreraArchivo::getCantidadRegistros() {
    FILE *pFile;
    int cant;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    cant = ftell(pFile) / sizeof(Carrera);

    fclose(pFile);

    return cant;
}

int CarreraArchivo::getNuevoIdCarrera() {
    return getCantidadRegistros() + 1;
}

int CarreraArchivo::getPosByIdCarrera(int idCarrera){

    int cantidad = getCantidadRegistros();

    for(int i = 0; i < cantidad; i++){

        Carrera reg = leer(i);

        if(reg.getIdCarrera() == idCarrera){
            return i;
        }
    }

    return -1;
}

bool CarreraArchivo::modificar(const Carrera &reg, int pos){

    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(Carrera), SEEK_SET);

    bool resultado = fwrite(&reg, sizeof(Carrera), 1, pFile);

    fclose(pFile);

    return resultado;
}

