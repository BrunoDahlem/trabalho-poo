#ifndef Cliente_hpp
#define Cliente_hpp

#include "Quarto.hpp"
#include "Reserva.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Cliente {
  public:
  Cliente();
  Cliente(string n, int c);
  string getNome();
  int getCPF();
  string getTel();
  int getNReservas();
  void setNome(string n);
  void setCPF(int c);
  void setTel(string tel);
  void setNReservas(int n);
  void imprime();
  private:
  int nReservas;
  int cpfCliente;
  string nomeCliente, telefone;

};
#endif