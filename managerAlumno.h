#pragma once
#include "archivoAlumno.h"

class AlumnoManager {
public:
	AlumnoManager();

   void guardarAlumno();
   void listarAlumno();

private:
   AlumnoMenu crearAlumno();
   AlumnoArchivo _alumnoArchivo;
};

