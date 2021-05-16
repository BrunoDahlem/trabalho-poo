#ifndef Hotel_hpp
#define Hotel_hpp

#include "Quarto.hpp"
#include "Cliente.hpp"
#include "Reserva.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Hotel {
  public:
  Hotel();
  Hotel(string nome);
  string getNome();
  void adicionaQuarto(int nCamas, bool status, bool prestigio, bool tipoCama);
  void adicionaCliente(string nome,int cpf);
  void adicionaReserva(int cpf, int numero, int d, int m, int a,int fd, int fm, int fa);
  int getNReservas(int cpf);
  void setNReservas(int cpf,int nReserva);
  void imprimeLista();
  void imprimeCliente(int cpf);
  void imprimeTodosCliente();
  void imprimeListaLivres(int d, int m, int a,int fd, int fm, int fa);
  void imprimeQuarto(int id,int d, int m, int a,int fd, int fm, int fa);
  int verificar(int numero);
  int verificarQuarto(int numero);
  int verificarCliente(int cpf);
  void ocuparQuarto(int numero);
  void desocuparQuarto(int numero);
  void imprimeReserva();
  string getNomeFuncio();
  string getNomeCliente(int cpf);
  string getTelCliente(int cpf);
  void setNomeCliente(int cpf,string nome);
  void setTelCliente(int cpf,string tel);
  
  
  private:
  const string funcionario = "Devidson";
  string nome;
  vector<Quarto> quarto;
  vector<Cliente> cliente;
  vector<Reserva> reserva;
  int x, y;


};
#endif /* Hotel_hpp */