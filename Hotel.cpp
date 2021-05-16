#include "Hotel.hpp"
int res = 0;

Hotel::Hotel(){
}
Hotel::Hotel(string nome) {
  this->nome = nome;
}
string Hotel::getNome() {
  return nome;
}

void Hotel::adicionaQuarto(int nCamas, bool status, bool prestigio, bool tipoCama) {
  quarto.push_back(Quarto(nCamas, status, prestigio, tipoCama));
}

void Hotel::adicionaCliente(string nome, int cpf) {
  cliente.push_back(Cliente(nome, cpf));
}

void Hotel::adicionaReserva(int cpf, int numero, int d, int m, int a,int fd, int fm, int fa) {
  for(int i=0; i < quarto.size(); i++){
        if(quarto[i].getNumero()==numero) {
          x = quarto[i].getNumero();
        }
  }
  for(int z=0; z < cliente.size(); z++){
        if(cliente[z].getCPF()== cpf) {
          y = cliente[z].getCPF();
        }
  }
  string nomeF = getNomeFuncio();
  reserva.push_back(Reserva(y,x,d,m,a,fd,fm,fa,nomeF));
}
void Hotel::setNReservas(int cpf,int nReserva){
  for(int i=0; i < reserva.size(); i++){
    for(int j=0; j < cliente.size(); j++){
      if(reserva[i].getCliente() == cpf){
        cliente[j].setNReservas(nReserva);
      }
    }
  }
}
int Hotel::getNReservas(int cpf){
  int r;
  for(int i=0; i < reserva.size(); i++){
    for(int j=0; j < cliente.size(); j++){
      if(reserva[i].getCliente() == cpf){
       r= cliente[j].getNReservas();
      }
    }
  }
  return r;
}

void Hotel::imprimeLista(){
  for(int i=0; i < quarto.size(); i++)
  {
      quarto[i].imprime();
  }
}

void Hotel::imprimeCliente(int cpf){
  for(int i=0; i < cliente.size(); i++)
  {
    if(cliente[i].getCPF()==cpf) {
      cliente[i].imprime();
    }
  }
}

void Hotel::imprimeTodosCliente(){
  for(int i=0; i < cliente.size(); i++)
  {
      cliente[i].imprime();
      cout << "----------------------------------------------------" << endl;
  }
}

void Hotel::imprimeListaLivres(int d, int m, int a,int fd, int fm, int fa){
  for(int i=0; i < quarto.size(); i++){

    for(int j=0; j < reserva.size(); j++){

      if(reserva[j].getDia() >= d && reserva[j].getDiaF() <= fd){
        if(reserva[j].getMes() >= m && reserva[j].getMesF() <= fm){
          if(reserva[j].getAno() >= a && reserva[j].getAnoF() <= fa){
            if (quarto[i].getNumero()== reserva[j].getQuarto()){
              quarto[i].setStatus(1);
            }
          }
        }
      }
      if (quarto[i].getNumero()== reserva[j].getQuarto()){
        quarto[i].setStatus(1);
      }
    
    }
    
    if(quarto[i].getStatus()==0) {
      quarto[i].imprime();
    }
  }
}

void Hotel::imprimeQuarto(int id,int d, int m, int a,int fd, int fm, int fa){
  for(int i=0; i < quarto.size(); i++){
    for(int j=0; j < reserva.size(); j++){
      
      if((reserva[j].getDia() >= d && reserva[j].getDiaF() <= fd)
      &&(reserva[j].getMes() >= m && reserva[j].getMesF() <= fm)
      &&(reserva[j].getAno() >= a && reserva[j].getAnoF() <= fa)){
              quarto[i].setStatus(1);
      }
    }
    if(quarto[i].getNumero()==id) {
          quarto[i].imprime();
    }
  }
}

int Hotel::verificar(int numero){

  for(int i=0; i < quarto.size(); i++){
    if(quarto[i].getStatus()==0) {
      if (quarto[i].getNumero()== numero ){
          return numero;
      }
    }
  }
  return 0;
}
int Hotel::verificarQuarto(int numero){

  for(int i=0; i < quarto.size(); i++){
      if (quarto[i].getNumero()== numero ){
          return numero;
      }
  }
  return 0;
}
int Hotel::verificarCliente(int cpf){

  for(int i=0; i < cliente.size(); i++){
      if (cliente[i].getCPF()== cpf ){
          return cpf;
      }
  }
  return 0;
}
void Hotel::ocuparQuarto(int numero){
    for(int i=0; i < quarto.size(); i++){
        if(quarto[i].getNumero()==numero) {
          quarto[i].setStatus(1);
      }
    }
}
void Hotel::desocuparQuarto(int numero){
    for(int i=0; i < quarto.size(); i++){
      if(quarto[i].getNumero()==numero) {
        quarto[i].setStatus(0);
      }
    }
}

void Hotel::imprimeReserva(){
  
  for(int i=0; i < reserva.size(); i++){

      for(int z=0; z < cliente.size(); z++){
        if(cliente[z].getCPF()==reserva[i].getCliente()) {
          cliente[z].imprime();
        }
      }
      
      for(int j=0; j < quarto.size(); j++){
        if(quarto[j].getNumero()==reserva[i].getQuarto()) {
          quarto[j].imprime();
        }
      }

      reserva[i].imprime();
  }  
}

string Hotel::getNomeFuncio(){
  return funcionario;
}
string Hotel::getNomeCliente(int cpf){
  string nomeC;
  for(int i=0; i < cliente.size(); i++)
    {
      if(cliente[i].getCPF()==cpf) {
        nomeC = cliente[i].getNome();
      }
  }
  return nomeC;
}
string Hotel::getTelCliente(int cpf){
  string telC;
  for(int i=0; i < cliente.size(); i++)
    {
      if(cliente[i].getCPF()==cpf) {
        telC = cliente[i].getTel();
      }
  }
  return telC;
}
void Hotel::setNomeCliente(int cpf,string nome){
  for(int i=0; i < cliente.size(); i++)
    {
      if(cliente[i].getCPF()==cpf) {
        cliente[i].setNome(nome);
      }
  }
}
void Hotel::setTelCliente(int cpf,string tel){
  for(int i=0; i < cliente.size(); i++)
    {
      if(cliente[i].getCPF()==cpf) {
        cliente[i].setTel(tel);
      }
  }
}
