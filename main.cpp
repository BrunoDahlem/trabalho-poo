#include "Hotel.hpp"
#include <iostream>
using namespace std;

int main() {

  Hotel hotel("Tabajara");
  hotel.adicionaQuarto(1,0,0,0);
  hotel.adicionaQuarto(1,0,1,0);
  hotel.adicionaQuarto(3,0,0,1);
  hotel.adicionaQuarto(1,0,0,0);
  hotel.adicionaQuarto(2,0,1,0);
  hotel.adicionaCliente("Gefferson", 123);
  hotel.adicionaCliente("Ysabella", 321);

  //--------------------------escolha menu----------------------------------------------

  char op; //escolha menu

  //-------------------variaveis verificar um quarto-----------------------------------

  int buscarQuarto; //buscar quarto pelo numero
  int diaVerificarInicial, diaVerificarFinal; // escolher dias para a reserva
  int mesVerificarInicial, mesVerificarFinal; // escolher mes para a reserva
  int anoVerificarInicial, anoVerificarFinal; // escolher ano para a reserva
  char opVerificarNovamente; //escolher se quer verificar outro quarto com a mesma data ou n
  bool opVerificarImprimeQuarto = false; //verifica se foi feito uma escolha valida
  bool opVerificaNumeroSelecionado = false; //verifica se o numero selecionado é valido

  //-----------------Variaveis acessar dados do cliente------------------------------
  int cpfClienteCad; //pesquisar cpf cliente
  char opClienteSelecionado; //opcoes do cliente selecionado
  char opDadosDoCliente; //opcoes dados do cliente selecionado
  string opNovoNome; //variavel para trocar nome usuario
  string opNovoTelefone; //variavel para trocar o telefone
  bool opDadosClienteInvalido = false; //verificar se opcao valida
  char ultimaOpClienteCad;


  //-------------------variaveis escolha do quarto-----------------------------------

  int numeroQuarto; //escolher um quarto vago da lista
  bool verificarQuarto; //caso o numero na escolha do quarto é invalido dar while
  int opClienteCad; //escolher se é cliente cadastrado ou n
  int opClienteCad2; //escolher se deseja continuar com o cliente selecionado
  int numeroCPF; //verificar cpf ja cadastrado
  int opContinuarReserva; //escolher se vai continuar a reserva com o cliente selecionado
  int opOutraReserva; //escolher se deseja fazer mais uma reserva
  int opFazerReserva; //escolher periodo da reserva
  int diaReservaInicial, diaReservaFinal; // escolher dias para a reserva
  int mesReservaInicial, mesReservaFinal; // escolher mes para a reserva
  int anoReservaInicial, anoReservaFinal; // escolher ano para a reserva
  char opVerificarQuartoData; //caso o numero na escolha da data é invalido dar while
  string adicionaNumeroCliente;
  string adicionaNomeCliente;
  int adicionaCpfCliente;

  //------------------variaveis escolha dos relatorios
  char opRelatorios;
  bool opFinalRelatorios = false;
  char opRelatorios2;

  //---------------------------------------------------------------------------------


  do{
    
    system("cls");

    cout << "----------------------------------------------------" << endl;
    cout << "            Sistema de Controle do Hotel" << endl << "                   Hotel " << hotel.getNome() << endl;
    cout << "----------------------------------------------------" << endl << endl;
    
    cout << "Insira uma opcao valida:" << endl << endl;
    
    cout << "1 - Verificar um quarto." << endl;
    cout << "2 - Acessar dados de um Cliente." << endl;
    cout << "3 - Realizar a reserva de um quarto." << endl;
    cout << "4 - Relatorios" << endl;
    cout << "5 - Sair" << endl << endl;
    
    cin >> op;
    
    cout << endl << endl;
    
    switch(op){

      case '1':
        
        do{

          //----------------------VERIFICAR QUARTO-------------------------------
          system("cls");

          cout << "----------------------------------------------------" << endl;
		  cout << "                Verificar um Quarto                 " << endl;
		  cout << "----------------------------------------------------" << endl << endl;
					
          cout << "Digite o periodo que deseja verificar." << endl << endl;

          cout << "Dia inicial: ";
          cin >> diaVerificarInicial;

          cout << "Mes inicial: ";
          cin >> mesVerificarInicial;

          cout << "Ano inicial: ";
          cin >> anoVerificarInicial;

          cout << endl;

          cout << "Dia final: ";
          cin >> diaVerificarFinal;

          cout << "Mes final: ";
          cin >> mesVerificarFinal;

          cout << "Ano final: ";
          cin >> anoVerificarFinal;

          //-------------------------------VERIFICAR SE E ESSE O PERIODO QUE QUER---------------------------
          if((diaVerificarInicial < diaVerificarFinal && mesVerificarInicial == mesVerificarFinal && anoVerificarInicial == anoVerificarFinal)
            || (mesVerificarInicial < mesVerificarFinal && anoVerificarInicial == anoVerificarFinal)
            || (anoVerificarInicial < anoVerificarFinal)){
            
            do{
			  
			  opVerificarImprimeQuarto = false;
			  
              system("cls");

              cout << "----------------------------------------------------" << endl;
              cout << "                Periodo Selecionado                 " << endl;
              cout << "----------------------------------------------------" << endl << endl;


              cout << "Voce escolheu periodo de: " << diaVerificarInicial << "/" << mesVerificarInicial << "/" << anoVerificarInicial << endl;
              cout << "Ate: " << diaVerificarFinal << "/" << mesVerificarFinal << "/" << anoVerificarFinal << endl << endl;

              cout << "1 - Verificar quarto com periodo escolhido." << endl;
              cout << "2 - Escolher outro periodo." << endl;
              cout << "3 - Voltar ao menu principal." << endl << endl;

              cin >> opVerificarQuartoData;

              
              //-------------------------------IMPRIMIR VERIFICACAO DO QUARTO SELECIONADO---------------------
              if(opVerificarQuartoData == '1'){

                do{
				  
				  opVerificaNumeroSelecionado = false;
				  
                  system("cls");
                  
                  cout << "----------------------------------------------------" << endl;
	              cout << "       Verificar quarto com periodo escolhido       " << endl;
	              cout << "----------------------------------------------------" << endl << endl;

                  cout << "Digite qual o numero do quarto desejado." << endl << endl;

                  cin >> buscarQuarto;
                  
                  if(buscarQuarto == hotel.verificarQuarto(buscarQuarto)){
					
					do{
						
						
	                    system("cls");
	                    
	                    cout << "----------------------------------------------------" << endl;
			            cout << "                 Quarto Verificado                  " << endl;
			            cout << "----------------------------------------------------" << endl << endl;
	
	                    hotel.imprimeQuarto(buscarQuarto,diaVerificarInicial,mesVerificarInicial,anoVerificarInicial,diaVerificarFinal,mesVerificarFinal,anoVerificarFinal);
	                  	cout << "----------------------------------------------------" << endl << endl;
	                  	
	                    cout << "1 - Verificar outro quarto com a mesma data." << endl;
	                    cout << "2 - Verificar outro quarto com outra data." << endl;
	                    cout << "3 - Voltar ao menu principal" << endl << endl;
	
	                    cin >> opVerificarNovamente;
	
	                    cout << endl;
	                    
	                    if(opVerificarNovamente != '1' && opVerificarNovamente != '2' && opVerificarNovamente != '3'){
	                    	cout << "Escolha uma opcao valida!" << endl << endl;
	                    	
	                    	system("pause");
	                    	
						}
						
					}while(opVerificarNovamente != '1' && opVerificarNovamente != '2' && opVerificarNovamente != '3');
					
                  }
                  else{
                    cout << "Numero de quarto invalido!" << endl << endl;

                    opVerificaNumeroSelecionado = true;

                    system("pause");
                  }
                  
                }while(opVerificaNumeroSelecionado == true || opVerificarNovamente == '1');
                
              }
              else if(opVerificarQuartoData != '1' && opVerificarQuartoData != '2' && opVerificarQuartoData != '3'){
                cout << "Digite uma opcao valida!" << endl;

                opVerificarImprimeQuarto = true;

                system("pause");
              }
              //--------------------------------------------------------------------------------------------

            }while(opVerificarImprimeQuarto == true || opVerificarNovamente == '1');

          }//---------------------------------CASO DATA ERRADA---------------------------------------------
          else{
            cout << "Formato de data invalido!" << endl;

            system("pause");
          }//--------------------------------------------------------------------------------------------
          

        }while(opVerificarQuartoData == '2' || opVerificarQuartoData == '2' || opVerificarNovamente == '2');

        break;
        

      case '2':

        do{

          system("cls");
          
          cout << "----------------------------------------------------" << endl;
      	  cout << "            Acessar Dados De Um Cliente             " << endl;
      	  cout << "----------------------------------------------------" << endl << endl;

          cout << "Insira o CPF do cliente cadastrado." << endl << endl;

          cout << "CPF: ";
          cin >> cpfClienteCad;
          cout << endl;

          if(cpfClienteCad == hotel.verificarCliente(cpfClienteCad)){

            system("cls");
			
			cout << "----------------------------------------------------" << endl;
            cout << "                Cliente selecionado                 " << endl;
            cout << "----------------------------------------------------" << endl;
            hotel.imprimeCliente(cpfClienteCad);
            cout << "----------------------------------------------------" << endl << endl;

            cout << "1 - Alterar dados do cliente" << endl;
            cout << "2 - Selecionar outro cliente" << endl;
            cout << "3 - Voltar ao menu principal" << endl << endl;

            cin >> opClienteSelecionado;

            if(opClienteSelecionado == '1'){

              do{
				
				opDadosClienteInvalido = false;
				
                system("cls");
                
                cout << "----------------------------------------------------" << endl;
	            cout << "             Alterar Dados Do Cliente               " << endl;
	            cout << "----------------------------------------------------" << endl;
	            hotel.imprimeCliente(cpfClienteCad);
	            cout << "----------------------------------------------------" << endl << endl;

                cout << "1 - Alterar nome do cliente." << endl;
                cout << "2 - Alterar telefone do cliente." << endl;
                cout << "3 - Selecionar outro cliente" << endl;
                cout << "4 - Voltar ao menu principal" << endl << endl;

                cin >> opDadosDoCliente;

                if(opDadosDoCliente == '1'){

                  system("cls");
                  
                  cout << "----------------------------------------------------" << endl;
		          cout << "             Alterar Dados Do Cliente               " << endl;
		          cout << "----------------------------------------------------" << endl << endl;

                  cout << "Nome atual: " << hotel.getNomeCliente(cpfClienteCad) << endl << endl;

                  cout << "Digite novo nome: ";
                  cin >> opNovoNome;

                  cout << endl;
                  hotel.setNomeCliente(cpfClienteCad, opNovoNome);
                  
                  cout << "Nome alterado com sucesso!" << endl << endl;
                  
                  system("pause");
				  
				  cout << endl;
				  
                  cout << "1 - Alterar outro dado" << endl;
                  cout << "2 - Selecionar outro cliente" << endl;
                  cout << "3 - Voltar ao menu principal" << endl << endl;

                  cin >> ultimaOpClienteCad;

                }
                else if(opDadosDoCliente == '2'){
                  
                  system("cls");
                  
                  cout << "----------------------------------------------------" << endl;
		          cout << "             Alterar Dados Do Cliente               " << endl;
		          cout << "----------------------------------------------------" << endl << endl;

                  cout << "Telefone atual: " << hotel.getTelCliente(cpfClienteCad) << endl << endl;

                  cout << "Digite novo telefone: ";
                  cin >> opNovoTelefone;

                  cout << endl;
                  hotel.setNomeCliente(cpfClienteCad, opNovoTelefone);
                  
                  cout << "Telefone alterado com sucesso!" << endl << endl;
                  
                  system("pause");
				  
				  cout << endl;
				  
                  cout << "1 - Alterar outro dado" << endl;
                  cout << "2 - Selecionar outro cliente" << endl;
                  cout << "3 - Voltar ao menu principal" << endl << endl;

                  cin >> ultimaOpClienteCad;
                  
                }
                else if(opDadosDoCliente != '1' && opDadosDoCliente != '2' && opDadosDoCliente != '3' && opDadosDoCliente != '4'){

                  cout << "Escolha uma opcao valida!" << endl;

                  opDadosClienteInvalido = true;

                  system("pause");
                }

              }while(opDadosClienteInvalido == true || ultimaOpClienteCad == '1');

            }

          }
          else{
            cout << "Nenhum cliente com este CPF foi encontrado!" << endl;

            system("pause");
          }


        }while(opClienteSelecionado == '2' || ultimaOpClienteCad == '2' || opDadosDoCliente == '3');

        break;
        
      case '3':

        do{
          
          system("cls");

          cout << "----------------------------------------------------" << endl;
          cout << "          Realizar a reserva de um quarto           " << endl;
          cout << "----------------------------------------------------" << endl << endl;

          cout << "1 - Para cliente ja cadastrado" << endl;
          cout << "2 - Para cliente nao cadastrado" << endl;
          cout << "3 - Voltar ao menu principal" << endl << endl;

          cin >> opClienteCad;

          cout << endl;

          if(opClienteCad == 1){ //--------------------------------------------
            

            do{
              
              system("cls");
              
              cout << "----------------------------------------------------" << endl;
	          cout << "          Realizar a reserva de um quarto           " << endl;
	          cout << "----------------------------------------------------" << endl << endl;

              cout << "Digite o CPF do cliente." << endl;

              cin >> numeroCPF;

              if(numeroCPF == hotel.verificarCliente(numeroCPF)){
                  
                verificarQuarto = false;

                system("cls");
                
                cout << "----------------------------------------------------" << endl;
		        cout << "          Realizar a reserva de um quarto           " << endl;
		        cout << "----------------------------------------------------" << endl << endl;

                cout  << "Cliente selecionado: " << endl;
                hotel.imprimeCliente(numeroCPF);
                cout << endl;

                cout << "1 - Continuar com o pedido de reserva" << endl;
                cout << "2 - Selecionar outro cliente" << endl;
                cout << "3 - Voltar ao menu principal" << endl;
                cout << "4 - Voltar ao menu de reservas" << endl << endl;
                
                cin >> opContinuarReserva;

                cout << endl;

                if(opContinuarReserva == 1){
                  
                  system("cls");
                  
                  cout << "----------------------------------------------------" << endl;
		          cout << "          Realizar a reserva de um quarto           " << endl;
		          cout << "----------------------------------------------------" << endl << endl;

                  cout << "Digite o periodo da sua reserva." << endl << endl;

                  cout << "Dia inicial: ";
                  cin >> diaReservaInicial;

                  cout << "Mes inicial: ";
                  cin >> mesReservaInicial;

                  cout << "Ano inicial: ";
                  cin >> anoReservaInicial;

                  cout << endl;

                  cout << "Dia final: ";
                  cin >> diaReservaFinal;

                  cout << "Mes final: ";
                  cin >> mesReservaFinal;

                  cout << "Ano final: ";
                  cin >> anoReservaFinal;

                  if((diaReservaInicial < diaReservaFinal && mesReservaInicial == mesReservaFinal && anoReservaInicial == anoReservaFinal)
		            || (mesReservaInicial < mesReservaFinal && anoReservaInicial == anoReservaFinal)
		            || (anoReservaInicial < anoReservaFinal)){

                    system("cls");
                    
                    cout << "----------------------------------------------------" << endl;
			        cout << "          Realizar a reserva de um quarto           " << endl;
			        cout << "----------------------------------------------------" << endl << endl;

                    cout << "Voce escolheu periodo de: " << diaReservaInicial << "/" << mesReservaInicial << "/" << anoReservaInicial << endl;
                    cout << "Ate: " << diaReservaFinal << "/" << mesReservaFinal << "/" << anoReservaFinal << endl;
                    
                    system("pause");


                    do{

                      system("cls");

                      verificarQuarto = false;
                      
                      cout << "----------------------------------------------------" << endl;
			          cout << "          Realizar a reserva de um quarto           " << endl;
			          cout << "----------------------------------------------------" << endl << endl;

                      cout << "Escolha um dos quartos a seguir." << endl << endl;

                      hotel.imprimeListaLivres(diaReservaInicial,mesReservaInicial,anoReservaInicial,diaReservaFinal,mesReservaFinal,anoReservaFinal);

                      cin >> numeroQuarto;
                      
                      if(numeroQuarto == hotel.verificar(numeroQuarto))
                      {
                        
                        verificarQuarto = false;

                        system("cls");
                        
                        cout << "----------------------------------------------------" << endl;
				        cout << "          Realizar a reserva de um quarto           " << endl;
				        cout << "----------------------------------------------------" << endl << endl;

                        cout  << "Voce escolheu o quarto numero " << numeroQuarto << endl;

                        cout << "1 - Realizar reserva" << endl;
                        cout << "2 - Escolher outro quarto" << endl << endl;

                        cin >> opFazerReserva;

                        if(opFazerReserva == 1){
                          
                          hotel.adicionaReserva(numeroCPF,numeroQuarto,diaReservaInicial,mesReservaInicial,anoReservaInicial,diaReservaFinal,mesReservaFinal,anoReservaFinal);
                          if(numeroCPF == hotel.verificarCliente(numeroCPF)){
                            int x = hotel.getNReservas(numeroCPF);
                            x++;
                            hotel.setNReservas(numeroCPF,x);
                          }
                          
                          cout << "Reserva realizada com sucesso!" << endl << endl;
                          
                          system("pause");
                        }
                        else if(opFazerReserva < 1 || opFazerReserva > 2){
                        	
                          verificarQuarto == true;

                          cout << "Escolha uma opcao valida!" << endl;
                        }

                      }
                      else(cout << "digite o numero de um quarto vago!" << endl);
                      
                    }while(verificarQuarto == true);

                  }
                  else if(opVerificarQuartoData != '1' && opVerificarQuartoData != '2' && opVerificarQuartoData != '3'){
                  cout << "Digite uma opcao valida!" << endl;

                  opVerificarImprimeQuarto = true;

                  system("pause");
                  }

                }
                else if(opContinuarReserva < 1 || opContinuarReserva > 3){
                  cout << "Escolha uma opcao valida!" << endl << endl;

                  system("pause");
                }

              }
              else if(numeroCPF != hotel.verificarCliente(numeroCPF)){
              	
              	cout << "----------------------------------------------------" << endl;
		        cout << "          Realizar a reserva de um quarto           " << endl;
		        cout << "----------------------------------------------------" << endl << endl;
                
                cout << "Cliente com o CPF informado nao encontrado!" << endl << endl;
                
                system("pause");


              }

            }while(verificarQuarto == true || opContinuarReserva == 2);

            

          }
          else if(opClienteCad == 2){ //-----------------------------------------
            
            
            do{
              
              
              system("cls");

              cout << "----------------------------------------------------" << endl;
	          cout << "                 Cadastrar Cliente                  " << endl;
	          cout << "----------------------------------------------------" << endl << endl;

              cout << "Insira o nome do cliente: ";
              cin >> adicionaNomeCliente;
              
              cout << "Insira o CPF do cliente: ";
              cin >> adicionaCpfCliente;
              hotel.adicionaCliente(adicionaNomeCliente,adicionaCpfCliente);
              cout << "Insira numero do cliente: ";
              cin >> adicionaNumeroCliente;
              hotel.setTelCliente(adicionaCpfCliente, adicionaNumeroCliente);
              system("cls");
              

              cout << "Cliente cadastrado com sucesso! " << endl << endl;

              cout << "Insira novamente o CPF do cliente: ";
              cin >> numeroCPF;


              if(numeroCPF == hotel.verificarCliente(numeroCPF)){
                  
                verificarQuarto = true;

                system("cls");
                
                cout << "----------------------------------------------------" << endl;
		        cout << "          Realizar a reserva de um quarto           " << endl;
		        cout << "----------------------------------------------------" << endl << endl;

                cout  << "Cliente selecionado: " << endl;
                hotel.imprimeCliente(numeroCPF);
                cout << endl;

                cout << "1 - Continuar com o pedido de reserva" << endl;
                cout << "2 - Selecionar outro cliente" << endl;
                cout << "3 - Cadastrar outro cliente" << endl;
                cout << "4 - Voltar ao menu principal" << endl << endl;
                
                cin >> opContinuarReserva;

                cout << endl;

                if(opContinuarReserva == 1){
                  
                  system("cls");
                  
                  cout << "----------------------------------------------------" << endl;
		          cout << "          Realizar a reserva de um quarto           " << endl;
		          cout << "----------------------------------------------------" << endl << endl;

                  cout << "Digite o periodo da sua reserva." << endl << endl;

                  cout << "Dia inicial: ";
                  cin >> diaReservaInicial;

                  cout << "Mes inicial: ";
                  cin >> mesReservaInicial;

                  cout << "Ano inicial: ";
                  cin >> anoReservaInicial;

                  cout << endl;

                  cout << "Dia final: ";
                  cin >> diaReservaFinal;

                  cout << "Mes final: ";
                  cin >> mesReservaFinal;

                  cout << "Ano final: ";
                  cin >> anoReservaFinal;

                  if((diaReservaInicial < diaReservaFinal && mesReservaInicial == mesReservaFinal && anoReservaInicial == anoReservaFinal)
		            || (mesReservaInicial < mesReservaFinal && anoReservaInicial == anoReservaFinal)
		            || (anoReservaInicial < anoReservaFinal)){

                    system("cls");
                    
                    cout << "----------------------------------------------------" << endl;
			        cout << "          Realizar a reserva de um quarto           " << endl;
			        cout << "----------------------------------------------------" << endl << endl;

                    cout << "Voce escolheu periodo de: " << diaReservaInicial << "/" << mesReservaInicial << "/" << anoReservaInicial << endl;
                    cout << "Ate: " << diaReservaFinal << "/" << mesReservaFinal << "/" << anoReservaFinal << endl;
                    
                    system("pause");


                    do{

                      system("cls");

                      verificarQuarto = false;
                      
                      cout << "----------------------------------------------------" << endl;
			          cout << "          Realizar a reserva de um quarto           " << endl;
			          cout << "----------------------------------------------------" << endl << endl;

                      cout << "Escolha um dos quartos a seguir." << endl << endl;

                      hotel.imprimeListaLivres(diaReservaInicial,mesReservaInicial,anoReservaInicial,diaReservaFinal,mesReservaFinal,anoReservaFinal);

                      cin >> numeroQuarto;
                      
                      if(numeroQuarto == hotel.verificar(numeroQuarto))
                      {
                        
                        verificarQuarto = true;

                        system("cls");
                        
                        cout << "----------------------------------------------------" << endl;
				        cout << "          Realizar a reserva de um quarto           " << endl;
				        cout << "----------------------------------------------------" << endl << endl;

                        cout  << "Voce escolheu o quarto numero " << numeroQuarto << endl;

                        cout << "1 - Realizar reserva" << endl;
                        cout << "2 - Escolher outro quarto" << endl << endl;

                        cin >> opFazerReserva;

                        if(opFazerReserva == 1){
                          
                          hotel.adicionaReserva(numeroCPF,numeroQuarto,diaReservaInicial,mesReservaInicial,anoReservaInicial,diaReservaFinal,mesReservaFinal,anoReservaFinal);

                          if(numeroCPF == hotel.verificarCliente(numeroCPF)){
                            int x = hotel.getNReservas(numeroCPF);
                            x++;
                            hotel.setNReservas(numeroCPF,x);
                          }
                          
                          cout << "Reserva realizada com sucesso!" << endl << endl;
                          
                          system("pause");
                        }
                        else if(opFazerReserva < 1 || opFazerReserva > 2){

                          cout << "Escolha uma opcao valida!" << endl;
                        }

                      }
                      else(cout << "digite o numero de um quarto vago!" << endl);
                      
                    }while(verificarQuarto == false);

                  }

                }
                else if(opContinuarReserva < 1 || opContinuarReserva > 3){
                  cout << "Escolha uma opcao valida!" << endl << endl;

                  system("pause");
                }

              }
              else if(numeroCPF != hotel.verificarCliente(numeroCPF)){
                
                cout << "Cliente com o CPF informado nao encontrado!" << endl;

                system("pause");
                
                verificarQuarto = false;
              }

            }while(verificarQuarto == false || opContinuarReserva == 3);

          }



        }while(opContinuarReserva == 4);

        break;

      case '4':

        do{
            
          opRelatorios2 = '0';
		    
          opFinalRelatorios = false;

          system("cls");
          
          cout << "----------------------------------------------------" << endl;
          cout << "                     Relatorios                     " << endl;
          cout << "----------------------------------------------------" << endl << endl;

          cout << "1 - Imprimir relatorio dos quartos" << endl;
          cout << "2 - Imprimir relatorio dos clientes" << endl;
          cout << "3 - Imprimir relatorio das reservas" << endl;
          cout << "4 - Voltar para o menu principal" << endl << endl;

          cin >> opRelatorios;

          if(opRelatorios == '1'){

            system("cls");

            hotel.imprimeLista();

            cout << "1 - Imprimir outro relatorio." << endl;
            cout << "2 - Voltar ao menu principal." << endl << endl;

            cin >> opRelatorios2;
            cout << endl;

          }
          else if(opRelatorios == '2'){

            system("cls");

            hotel.imprimeTodosCliente();

            cout << "1 - Imprimir outro relatorio." << endl;
            cout << "2 - Voltar ao menu principal." << endl << endl;

            cin >> opRelatorios2;
            cout << endl;
          }
          else if(opRelatorios == '3'){

            system("cls");

            hotel.imprimeReserva();

            cout << "1 - Imprimir outro relatorio." << endl;
            cout << "2 - Voltar ao menu principal." << endl << endl;

            cin >> opRelatorios2;
            cout << endl;
          }
          else if(opRelatorios != '4' && opRelatorios != '3' && opRelatorios != '2' && opRelatorios != '1'){

            cout << "Escolha uma opcao valida!" << endl << endl;

            opFinalRelatorios = true;

            system("pause");

          }

        }while(opFinalRelatorios == true || opRelatorios2 == '1');

        break;

      case '5':

        return 0;

    } 
      
      

  }while(op != '1' || op != '2' || op != '3' || op != '4' || op != '5'
        || opVerificarQuartoData == '3' || opVerificarNovamente == '3'
        || opClienteSelecionado == '3'
        || opClienteCad == '4'
        || opRelatorios == '4' || opRelatorios2 == '2');

  return 0;

  

}

