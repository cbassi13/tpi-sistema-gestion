#include "inscripcionesArchivo.h"

InscripcionArchivo::InscripcionArchivo(std::string nombreArchivo)
    : _nombreArchivo(nombreArchivo) {

}
bool InscripcionArchivo::guardar(const Inscripcion &reg) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&reg, sizeof(Inscripcion), 1, pFile);

    fclose(pFile);

    return result;
}
Inscripcion InscripcionArchivo::leer(int pos) {
    FILE *pFile;
    Inscripcion reg;

    reg.setIdInscripcion(-1);

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(pFile, pos * sizeof(Inscripcion), SEEK_SET);

    fread(&reg, sizeof(Inscripcion), 1, pFile);

    fclose(pFile);

    return reg;
}

int InscripcionArchivo::getCantidadRegistros() {
    FILE *pFile;
    int cant;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    cant = ftell(pFile) / sizeof(Inscripcion);

    fclose(pFile);

    return cant;
}

int InscripcionArchivo::getNuevoIdInscripcion() {
    return getCantidadRegistros() + 1;
}

int InscripcionArchivo::getPosByIdInscripcion(int idInscripcion){

    int cantidad = getCantidadRegistros();

    for(int i = 0; i < cantidad; i++){

        Inscripcion reg = leer(i);

        if(reg.getIdInscripcion() == idInscripcion){
            return i;
        }
    }

    return -1;
}

bool InscripcionArchivo::modificar(const Inscripcion &reg, int pos){

    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(Inscripcion), SEEK_SET);

    bool resultado = fwrite(&reg, sizeof(Inscripcion), 1, pFile);

    fclose(pFile);

    return resultado;
}
