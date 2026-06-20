#include <iostream>
#include "materia.h"
#include "materiaManager.h"

using namespace std;

MateriaManager::MateriaManager()
: _materiaArchivo() {
}

Materia MateriaManager::crearMateria() {
    int nroMateria = _materiaArchivo.getNuevoId();

    string nombre;
    string docente;
    int cupo;
    int idAula;
    int idCarrera;

    cout << "ID de materia: #" << nroMateria << endl;

    cout << "Ingrese nombre: ";
    cin >> nombre;

    cout << "Ingrese docente: ";
    cin >> docente;

    cout << "Ingrese cupo: ";
    cin >> cupo;

    cout << "Ingrese ID aula: ";
    cin >> idAula;

    cout << "Ingrese ID carrera: ";
    cin >> idCarrera;

    Materia materia(nroMateria, nombre, docente, cupo, idAula, idCarrera);

    return materia;
}

void MateriaManager::guardarMateria() {
    Materia materia = crearMateria();

    if (_materiaArchivo.guardar(materia)) {
        cout << "Se guardo exitosamente" << endl;
    } else {
        cout << "No se pudo guardar" << endl;
    }
}

void MateriaManager::listarMaterias() {
    int cantidad = _materiaArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Materia materia = _materiaArchivo.leer(i);

        cout << "-----------------------" << endl;
        cout << "Nro. Materia: #" << materia.getNroMateria() << endl;
        cout << "Nombre: " << materia.getNombre() << endl;
        cout << "Docente: " << materia.getDocente() << endl;
        cout << "Cupo: " << materia.getCupo() << endl;
        cout << "ID Aula: " << materia.getIdAula() << endl;
        cout << "ID Carrera: " << materia.getIdCarrera() << endl;
    }
}

void MateriaManager::modificarMateria() {
    int nro;
    cout << "Ingrese nro de materia a modificar: ";
    cin >> nro;

    int cantidad = _materiaArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Materia materia = _materiaArchivo.leer(i);

        if (materia.getNroMateria() == nro) {

            string nuevoNombre;
            string nuevoDocente;
            int nuevoCupo;
            int nuevoIdAula;
            int nuevoIdCarrera;

            cout << "Nuevo nombre: ";
            cin >> nuevoNombre;

            cout << "Nuevo docente: ";
            cin >> nuevoDocente;

            cout << "Nuevo cupo: ";
            cin >> nuevoCupo;

            cout << "Nuevo ID aula: ";
            cin >> nuevoIdAula;

            cout << "Nuevo ID carrera: ";
            cin >> nuevoIdCarrera;

            materia.setNombre(nuevoNombre);
            materia.setDocente(nuevoDocente);
            materia.setCupo(nuevoCupo);
            materia.setIdAula(nuevoIdAula);
            materia.setIdCarrera(nuevoIdCarrera);

            if (_materiaArchivo.modificar(materia, i)) {
                cout << "Materia modificada correctamente" << endl;
            } else {
                cout << "Error al modificar" << endl;
            }

            return;
        }
    }

    cout << "No se encontro la materia" << endl;
}
