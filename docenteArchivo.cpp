#include "docenteArchivo.h"

DocenteArchivo::DocenteArchivo(std::string nombreArchivo)
    : _nombreArchivo(nombreArchivo) {

}
bool DocenteArchivo::guardar(const Docente &reg){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile == nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(Docente), 1, pFile);

    fclose(pFile);

    return result;
}

Docente DocenteArchivo::leer(int pos){
    FILE *pFile;
    Docente reg;

    reg.setLegajo(-1);

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return reg;
    }

    fseek(pFile, pos * sizeof(Docente), SEEK_SET);

    fread(&reg, sizeof(Docente), 1, pFile);

    fclose(pFile);

    return reg;
}

int DocenteArchivo::getCantidadRegistros(){
    FILE *pFile;
    int cant;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    cant = ftell(pFile) / sizeof(Docente);

    fclose(pFile);

    return cant;
}

int DocenteArchivo::getNuevoLegajo(){
    return getCantidadRegistros() + 1;
}

int DocenteArchivo::getPosByLegajo(int legajo) {
      int cantidad = getCantidadRegistros();

      for (int i = 0; i < cantidad; i++) {
          Docente reg = leer(i);
          if (reg.getLegajo() == legajo) {
              return i;
          }
      }

      return -1;
  }

  bool DocenteArchivo::modificar(const Docente &reg, int pos) {
      FILE *pFile;

      pFile = fopen(_nombreArchivo.c_str(), "rb+");

      if (pFile == nullptr) {
          return false;
      }

      fseek(pFile, pos * sizeof(Docente), SEEK_SET);

      bool resultado = fwrite(&reg, sizeof(Docente), 1, pFile);

      fclose(pFile);

      return resultado;
  }
