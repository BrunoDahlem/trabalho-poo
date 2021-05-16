#include "Cliente.hpp"

Cliente::Cliente(){
}
Cliente::Cliente(string n, int c) {
  this->nomeCliente = n;
  this->cpfCliente = c;
  this->nReservas = 0;
}

string Cliente::getNome(){
  return nomeCliente;
}
int Cliente::getCPF(){
  return cpfCliente;
}
string Cliente::getTel(){
  return telefone;
}
int Cliente::getNReservas(){
  return nReservas;
}
void Cliente::setNome(string n){
  this->nomeCliente = n;
}
void Cliente::setCPF(int c){
  this->cpfCliente = c;
}
void Cliente::setTel(string tel){
  this->telefone = tel;
}
void Cliente::setNReservas(int n){
  this->nReservas = n;
}
void Cliente::imprime(){
  cout << "Nome: " << nomeCliente << endl;
  cout << "CPF: " << cpfCliente << endl;
  cout << "Telefone: " << telefone << endl;
  cout << "Numero de reservas: " << nReservas <<endl;
}