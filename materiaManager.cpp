#include <iostream>
#include "materia.h"
#include "materiaManager.h"
#include <string>

using namespace std;

MateriaManager::MateriaManager()
: _materiaArchivo() {
}

Materia MateriaManager::crearMateria() {
    int nroMateria = _materiaArchivo.getNuevoId();

    string nombre;
    int idDocente;
    int cupo;
    int idAula;
    int idCarrera;

    cout << "ID de materia: #" << nroMateria << endl;

    cout << "Ingrese nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese ID docente: ";
    cin >> idDocente;

    cout << "Ingrese cupo: ";
    cin >> cupo;

    cout << "Ingrese ID aula: ";
    cin >> idAula;

    cout << "Ingrese ID carrera: ";
    cin >> idCarrera;

    Materia materia(nroMateria, nombre, idDocente, cupo, idAula, idCarrera);

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
        cout << "ID Docente: " << materia.getIdDocente() << endl;
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
            int nuevoIdDocente;
            int nuevoCupo;
            int nuevoIdAula;
            int nuevoIdCarrera;

            cout << "Nuevo nombre: ";
            cin.ignore();
            getline(cin, nuevoNombre);

            cout << "Nuevo ID docente: ";
            cin >> nuevoIdDocente;

            cout << "Nuevo cupo: ";
            cin >> nuevoCupo;

            cout << "Nuevo ID aula: ";
            cin >> nuevoIdAula;

            cout << "Nuevo ID carrera: ";
            cin >> nuevoIdCarrera;

            materia.setNombre(nuevoNombre);
            materia.setIdDocente(nuevoIdDocente);
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

void MateriaManager::bajaMateria(){

    int id;

    cout << "Ingrese ID de la Materia: ";
    cin >> id;

    int pos = _materiaArchivo.getPosByIdMateria(id);

    if(pos == -1){
        cout << "No existe una materia con ese ID." << endl;
        return;
    }

    Materia materia = _materiaArchivo.leer(pos);

    materia.setEliminado(true);

    if(_materiaArchivo.modificar(materia, pos)){
        cout << "Materia dada de baja correctamente." << endl;
    }
    else{
        cout << "No se pudo realizar la baja." << endl;
    }
}
