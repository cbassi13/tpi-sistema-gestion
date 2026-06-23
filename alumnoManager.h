#pragma once
#include "alumnoArchivo.h"

class AlumnoManager {
public:
	AlumnoManager();

   void guardarAlumno();
   void listarAlumnos();
   void modificarAlumno();
   void bajaAlumno();
    void buscarAlumnoPorLegajo();

private:
   Alumno crearAlumno();
   AlumnoArchivo _alumnoArchivo;
};

