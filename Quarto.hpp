#ifndef Quarto_hpp
#define Quarto_hpp


#include "Cliente.hpp"
#include "Reserva.hpp"

#include <iostream>
using namespace std;

class Quarto {
  public:
  Quarto();
  Quarto(int nCamas, bool status, bool prestigio, bool tipoCama);
  int getNumero();
  int getNCama();
  bool getStatus();
  bool getPrestigio();
  bool getTipoCama();

  void setNCama(int nCamas);
  void setStatus(bool status);
  void setPrestigio(bool prestigio);
  void setTipoCama(bool tipoCama);

  void imprime();
  

  private:
  int numero, nCamas;
  string Cama, ocp, tipo;
  bool status, prestigio,tipoCama;

  int geraNumero();
  int static ultimoNumero;
  
};
#endif /* Quarto_hpp */