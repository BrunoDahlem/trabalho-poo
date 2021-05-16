#include "Quarto.hpp"

int Quarto::ultimoNumero = 0;

Quarto::Quarto(){
};
Quarto::Quarto(int nCamas, bool status, bool prestigio, bool tipoCama){
  this->nCamas = nCamas;
  this->status = status;
  this->prestigio = prestigio;
  this->tipoCama = tipoCama;
  this->numero = geraNumero();
};
int Quarto::getNumero(){
  return numero;
};
int Quarto::getNCama(){
  return nCamas;
};
bool Quarto::getStatus(){
  return status;
};
bool Quarto::getPrestigio(){
  return prestigio;
};
bool Quarto::getTipoCama(){
  return tipoCama;
};

void Quarto::setNCama(int nCamas){
  this->nCamas = nCamas;
};
void Quarto::setPrestigio(bool prestigio){
  this->prestigio = prestigio;
};
void Quarto::setStatus(bool status){
  this->status = status;
}
void Quarto::setTipoCama(bool tipoCama){
  this->tipoCama = tipoCama;
}

int Quarto::geraNumero(){
    ultimoNumero++;
    return ultimoNumero;
}
void Quarto::imprime(){
  if (tipoCama){
      Cama = "Solteiro";
  } else {
      Cama = "Casal";
  }
  if (prestigio){
      tipo = "Luxo";
  } else {
      tipo = "Simples";
  }
  if (status){
      ocp = "sim";
  } else {
      ocp = "nao";
  }
    cout << "Numero: " << numero << endl;
    cout << "Tipo Cama: " << Cama << endl;
    cout << "Tipo do Quarto: " << tipo << endl;
    cout << "Numero de camas: " << nCamas << endl;
    cout << "Ocupado: " << ocp << endl;
    cout << "----------------------------------------------------" << endl;
}