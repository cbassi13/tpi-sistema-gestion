#include "archivoAlumno.h"

AlumnoArchivo::AlumnoArchivo(std::string nombreArchivo)
:_nombreArchivo(nombreArchivo){

}

bool AlumnoArchivo::guardar(Alumno &reg){
   FILE *pFile;
   bool result;

   pFile = fopen(_nombreArchivo.c_str(), "ab");

   if(pFile == nullptr){
      return false;
   }

   result = fwrite(&reg, sizeof(Alumno), 1, pFile);

   fclose(pFile);

   return result;
}

Alumno AlumnoArchivo::leer(int pos){
   FILE *pFile;
   Alumno reg;

   reg.setLegajo(-1);

   pFile = fopen(_nombreArchivo.c_str(), "rb");

   if(pFile == nullptr){
      return reg;
   }

   fseek(pFile, pos * sizeof(Alumno), SEEK_SET);

   fread(&reg, sizeof(Alumno), 1, pFile);

   fclose(pFile);

   return reg;
}

int AlumnoArchivo::getCantidadRegistros(){
   FILE *pFile;
   int cant;

   pFile = fopen(_nombreArchivo.c_str(), "rb");

   if(pFile == nullptr){
      return 0;
   }

   fseek(pFile, 0, SEEK_END);

   cant = ftell(pFile) / sizeof (Alumno);

   fclose(pFile);

   return cant;
}

int AlumnoArchivo::getNuevoLegajo(){
   return getCantidadRegistros() + 1;
}
