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
