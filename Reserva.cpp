#include "Reserva.hpp"

int Reserva::ultimoId = 0;

Reserva::Reserva(){
}
Reserva::Reserva(int cpf, int numero,int d, int m, int a,int fd, int fm, int fa,string funcio) {
  this->cliente = cpf;
  this->quarto = numero;
  this->dia = d;
  this->mes = m;
  this->ano = a;
  this->fdia = fd;
  this->fmes = fm;
  this->fano = fa;
  this->id = geraId();
  this->funcionario = funcio;
}

int Reserva::geraId(){
  ultimoId++;
  return ultimoId;
}

void Reserva::imprime(){
  cout << "Periodo de: " << dia << "/" << mes << "/" << ano << endl;
  cout << "Ate: " << fdia << "/" << fmes << "/" << fano << endl;
  cout << "Realizada por: " << funcionario << endl;
  cout << "----------------------------------------------------" << endl;
}


int Reserva::getId(){
  return id;
}
int Reserva::getDia(){
  return dia;
}
int Reserva::getMes(){
  return mes;
}
int Reserva::getAno(){
  return ano;
}
int Reserva::getDiaF(){
  return fdia;
}
int Reserva::getMesF(){
  return fmes;
}
int Reserva::getAnoF(){
  return fano;
}
int Reserva::getCliente(){
  return cliente;
}
int Reserva::getQuarto(){
  return quarto;
}

void Reserva::setId(int id){
  this->id = id;
}
void Reserva::setDia(int dia){
  this->dia = dia;
}
void Reserva::setMes(int mes){
  this->mes = mes;
}
void Reserva::setAno(int ano){
  this->ano = ano;
}
void Reserva::setDiaF(int diaf){
  this->fdia = diaf;
}
void Reserva::setMesF(int mesf){
  this->fmes = mesf;
}
void Reserva::setAnoF(int anof){
  this->fano = anof;
}
void Reserva::setCliente(int cliente){
  this->cliente = cliente;
}
void Reserva::setQuarto(int quarto){
  this->quarto = quarto;
}