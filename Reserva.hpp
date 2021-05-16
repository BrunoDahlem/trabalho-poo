#ifndef Reserva_hpp
#define Reserva_hpp

#include "Quarto.hpp"
#include "Cliente.hpp"


#include <vector>
#include <iostream>

using namespace std;

class Reserva {

  public:
  Reserva();
  Reserva(int cliente, int quarto,int d, int m, int a,int fd, int fm, int fa,string funcio);
  int getId();
  int getDia();
  int getMes();
  int getAno();
  int getDiaF();
  int getMesF();
  int getAnoF();
  int getCliente();
  int getQuarto();

  void setId(int id);
  void setDia(int dia);
  void setMes(int mes);
  void setAno(int ano);
  void setDiaF(int diaf);
  void setMesF(int mesf);
  void setAnoF(int anof);
  void setCliente(int cliente);
  void setQuarto(int quarto);

  void imprime();
  
  private:
  string funcionario;
  int id;
  int dia;
  int mes;
  int ano;
  int fdia;
  int fmes;
  int fano;

  int static ultimoId;
  int geraId();

  int cliente;
  int quarto;

  

};
#endif /* Reserva_hpp */