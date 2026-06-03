#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
#include "menu.h"


class App: public Menu {
public:
  App();
  void mostrarOpciones() override;
  void ejecutarOpcion (int opcion) override;

private:
  Menu _menu;

};


#endif // APP_H_INCLUDED
