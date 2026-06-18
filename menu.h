#pragma once

class Menu {
public:
   Menu();
   void run();

   virtual void mostrarOpciones() = 0;
   virtual void ejecutarOpcion(int opcion) = 0;

private:

};
