#pragma once
#include "alumnoArchivo.h"
#include "cuotaArchivo.h"

class AlumnoManager {
public:
	AlumnoManager();

   void guardarAlumno();
   void listarAlumnos();
   void modificarAlumno();
   void bajaAlumno();
    void buscarAlumnoPorLegajo();
   void buscarAlumnoPorApellido();
   void listarAlumnosDeudores();

private:
   Alumno crearAlumno();
   AlumnoArchivo _alumnoArchivo;
   CuotaArchivo _cuotaArchivo;
};

