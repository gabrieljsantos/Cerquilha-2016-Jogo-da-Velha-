//+++++++++++++++++++++++++++++++++++++++++++++++++++//
//---------------------------------------------------//
//--------------GABRIEL DE JESUS SANTOS--------------//
//-----------------------2016------------------------//
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

char jogo [9]  ; //Array para reprezentar o jogo.
char p1_x = 'x' ; //Valor do player 1.
char p2_o = 'o' ; //Valor do player 2.
char x_ou_o ; //Para alternar entre x ou o, no momento que for player 1 ou 2,de arcodo controle auter.

string comandos ;

bool check_jogada ; //Chekar se alguma jogada inteligente foi ativada.

int v_to_all_jogo2 ; //Variavel que para funcao que darar

int v_to_all_jogo ; //Variavel que para funcao que darar valo '-' a todo array no inicio.;PS: v == valor.
int vencedor ; //Para identificar quem ganhou.
int controle ; //Mapemento do controle
int auter = -1 ; //x_ou_o receber o valor de p1_x ou p2_o ,no momento que for player 1 ou 2.
int numjog ; //Numero de jogadas,valor inicial 0.
int decisao ; //decisao do propio jogo,de acordo com os padroes de jogada.
int decisao_aleato ; //decisao aleatoria caso nenhum padrao de jogada seja adquererido.
int dec_ale_start ; //decisao aleatoria para inicio.
int partid_wins_p1 = 0 ; //Patidas ganhadas do player 1 (O jogador ).
int partid_wins_p2 = 0 ; //Patidas ganhadas do player 2 (O propio Jogo).
int showvalor = 0 ; //registra opc�o de ver valor das variaveis (menu)

int posicao_ja_jogada[9] ;

int gravar_banco_de_dados (void) {

}

int posicoes_jogadas (void) {
    posicao_ja_jogada[((controle) - (1))] = controle ;

}

int zerar_pos_jogadas (void) {
    for (v_to_all_jogo = 0 ;v_to_all_jogo <= 8 ; v_to_all_jogo ++ ) { //funcao que darar valo 0 a todo array no posicoes jogadas.
		posicao_ja_jogada[v_to_all_jogo] = 0 ;
	}

}

int logva (void) {
	cout << endl << endl
	<< "p1_x = " << p1_x  << endl
	<< "p2_o = " << p2_o << endl
	<< "x_ou_o = " << x_ou_o << endl
	<< "comandos = " << comandos << endl
	<< "check_jogada = " << check_jogada << endl
	<< "vencedor = " << vencedor << endl
	<< "controle = " << controle << endl
	<< "auter = " << auter << endl
	<< "numjog = " << numjog << endl
	<< "decisao = " << decisao  << endl
	<< "decisao_aleato = " << decisao_aleato << endl
	<< "dec_ale_start = " << dec_ale_start << endl
	<< "partid_wins_p1 = " << partid_wins_p1 << endl
	<< "partid_wins_p2 = " << partid_wins_p2 <<endl
	<< "showvalor = " << showvalor <<endl ;

	system ("pause") ;
}

int tutorial (void) {
	cout << "cada posicao e reprenzentado por um numero,de forma que 2 , 5 e 7 reprenzentara:" << endl
	     << "- 2 -" << endl
		 << "- 5 -" << endl
		 << "7 - -" << endl
		 << "sendo assim :" << endl
		 << "1 2 3 \n4 5 6 \n7 8 9 " << endl
		 << "jogue Apenas um numero por vez." << endl
		 << "quando se pedir numeros ,nao digite letras ou palavras." ;
		 system ("pause") ;
	}

int cleararray (void) { //funcao que darar valo '-' a todo array no inicio.
	for (v_to_all_jogo = 0 ;v_to_all_jogo <= 8 ; v_to_all_jogo ++ ) { //funcao que darar valo '-' a todo array no inicio.
		jogo[v_to_all_jogo] = '-' ;
	}
}
int imprimir (void) { //funcao que limparar e imprimirar todo array em uma matriz 3x3 com todas auteracoes de acordo com as jogada.

	system ("cls") ; //Limpa tela.

	for (v_to_all_jogo = 0 ;v_to_all_jogo <= 8 ; v_to_all_jogo ++ ) { //funcao que imprimirar todo array em uma matriz 3x3 + Score.


		switch (v_to_all_jogo) {
			case 0 :
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << "+    "  ;
				break ;
			case 1 :
				cout << " | " ;
				break ;
			case 2 :
				cout << " | " ;
				break ;
			case 3 :
				cout << "          |Player1 : " << partid_wins_p1 << "|    Menu => Digite 10    |     +" << endl
					 << "+    ---------"
					 << "          |Player2 : " << partid_wins_p2 << "|    Tutorial no menu!    |     +" << endl
					 << "+    ";
				break ;
			case 4 :
				cout << " | " ;
				break ;
			case 5 :
				cout << " | " ;
				break ;
			case 6 :
				cout << "          |Numeros ja usados : " ;
				for (v_to_all_jogo2 = 0 ;v_to_all_jogo2 <= 8 ; v_to_all_jogo2 ++) {
						cout <<  posicao_ja_jogada[v_to_all_jogo2] ;

                        if (posicao_ja_jogada[v_to_all_jogo2] == 0) {
                            cout << "\b-" ;
                        }

                        if (v_to_all_jogo2 <= 7 ) {
                            cout << " " ;
                        }
				}
				cout << "|     +" ;
				//v_to_all_jogo = v_to_all_jogo - 10 ;

				cout << endl
			    	 << "+    ---------                                                      +" << endl
					 << "+    " ;
				break ;
			case 7 :
				cout << " | " ;
				break ;
			case 8 :
				cout << " | " ;
				break ;
		}
		cout << jogo[v_to_all_jogo] << "" ;

	}
	cout << "                                                      +" << endl ;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl ;
	cout << "Digite a posicao :" ;
}

int reset (void) {
	auter = auter ^ numjog ;
	numjog = (numjog / numjog) ;
}


int main() {

   	srand(time(0) ) ;

	while (true) { //Loop para novas partidads, partidas infinitas.

		decisao = 0 ;
		numjog = 0 ;

		cleararray () ; //Chamando a funcao de limpa o array,sendo para resetar ou iniciar.

		imprimir () ; //imprimir.
        if (showvalor == 1) {
            logva () ;
        }


		while (true) { //Repetir enquanto nenhuma combinacao para vitoria se atendida ou todos elementos do array for diferente de '-'.

			switch (auter) { //De acordo com auter x_ou_o receber valor de p1_x ou p2_o.
				case 1 :
					x_ou_o = p1_x ;
					break ;
				case -1 :
					x_ou_o = p2_o ;
					break ;
			}


			dec_ale_start = (rand( ) % 5 + 1) ;


			if ((auter == -1) &&
				((jogo[0] == '-') or

				(jogo[2] == '-') or

				(jogo[4] == '-') or

				(jogo[6] == '-') or

				(jogo[8] == '-'))) {

				check_jogada = 1 ;

				switch (dec_ale_start) { //Jogada iniciais inteligente e aletoria para opropio jogo.

		          	case 1 :
		          		if (jogo[4] == '-') {
			          		controle = 5 ; //centro
			        	 	break ;
						}

		           	case 2 :
		           		if (jogo[0] == '-') {
			          		controle = 1 ; //pocisao 1
			        	 	break ;
						}

		           	case 3 :
		           		if (jogo[2] == '-') {
			          		controle = 3 ; //pocisao 3
			        	 	break ;
						}

		           	case 4 :
		           		if (jogo[6] == '-') {
			          		controle = 7 ; //pocisao 7
			        	 	break ;
						}

		           	case 5 :
		           		if (jogo[8] == '-') {
			          		controle = 9 ; //pocisao 9
			        	 	break ;
						}
				}
			} else {

			check_jogada = 0 ;

			}
//########################################################################################################
// retirei codigo da qui.
			//Grupo de combinacoes para evitar que o jogador ganhe na jogada de posicao 1.
			if ((jogo[0] == '-') && (((jogo[1] == p1_x) && (jogo[2] == p1_x)) or //!jj !-- !--
									 ((jogo[4] == p1_x) && (jogo[8] == p1_x)) or //--- -j- j--
									 ((jogo[3] == p1_x) && (jogo[6] == p1_x)))){ //--- --j j--
				decisao = 1 ;
			}

			//Grupo de combinacoes para evitar que o jogador ganhe na jogada de posicao 2.
			if ((jogo[1] == '-') && (((jogo[0] == p1_x) && (jogo[2] == p1_x)) or //j!j -!- ---
									 ((jogo[4] == p1_x) && (jogo[7] == p1_x)))){ //--- -j- ---
									                                            	 //--- -j- ---
				decisao = 2 ;
			}

			//Grupo de combinacoes para evitar que o jogador ganhe na jogada de posicao 3.
			if ((jogo[2] == '-') && (((jogo[0] == p1_x) && (jogo[1] == p1_x)) or //jj! --! --!
									 ((jogo[4] == p1_x) && (jogo[6] == p1_x)) or //--- -j- --j
									 ((jogo[5] == p1_x) && (jogo[8] == p1_x)))){ //--- j-- --j
				decisao = 3 ;
			}

			//Grupo de combinacoes para evitar que o jogador ganhe na jogada de posicao 4.
			if ((jogo[3] == '-') && (((jogo[0] == p1_x) && (jogo[6] == p1_x)) or //j-- --- ---
									 ((jogo[4] == p1_x) && (jogo[5] == p1_x)))){ //!-- !jj ---
									                                            	 //j-- --- ---
				decisao = 4 ;
			}

			//Grupo de combinacoes para evitar que o jogador ganhe na jogada de posicao 5.
			if ((jogo[4] == '-') && (((jogo[0] == p1_x) && (jogo[8] == p1_x)) or //j-- --j --- -j-
									 ((jogo[6] == p1_x) && (jogo[2] == p1_x)) or //-!- -!- j!j -!-
									 ((jogo[3] == p1_x) && (jogo[5] == p1_x)) or //--j j-- --- -j-
									 ((jogo[1] == p1_x) && (jogo[7] == p1_x)))){
				decisao = 5 ;
			}

			//Grupo de combinacoes para evitar que o jogador ganhe na jogada de posicao 6.
			if ((jogo[5] == '-') && (((jogo[2] == p1_x) && (jogo[8] == p1_x)) or //--j --- ---
									 ((jogo[3] == p1_x) && (jogo[4] == p1_x)))){ //--! jj! ---
									                                            	 //--j --- ---
				decisao = 6 ;
			}

			//Grupo de combinacoes para evitar que o jogador ganhe na jogada de posicao 7.
			if ((jogo[6] == '-') && (((jogo[0] == p1_x) && (jogo[3] == p1_x)) or //j-- --j ---
									 ((jogo[4] == p1_x) && (jogo[2] == p1_x)) or //j-- -j- ---
									 ((jogo[7] == p1_x) && (jogo[8] == p1_x)))){ //!-- !-- !jj
				decisao = 7 ;
			}

			//Grupo de combinacoes para evitar que o jogador ganhe na jogada de posicao 8.
			if ((jogo[7] == '-') && (((jogo[6] == p1_x) && (jogo[8] == p1_x)) or //--- -j- ---
									 ((jogo[4] == p1_x) && (jogo[1] == p1_x)))){ //--- -j- ---
									                                             //j!j -!- ---
				decisao = 8 ;
			}

			//Grupo de combinacoes para evitar que o jogador ganhe na jogada de posicao 9.
			if ((jogo[8] == '-') && (((jogo[6] == p1_x) && (jogo[7] == p1_x)) or //--- j-- --j
									 ((jogo[4] == p1_x) && (jogo[0] == p1_x)) or //--- -j- --j
									 ((jogo[2] == p1_x) && (jogo[5] == p1_x)))){ //jj! --! --!
				decisao = 9 ;
			}

			//Grupo de combinacoes pra jogar na posicao 1.
			if ((jogo[0] == '-') && (((jogo[1] == p2_o) && (jogo[2] == p2_o)) or //!jj !-- !--
									 ((jogo[4] == p2_o) && (jogo[8] == p2_o)) or //--- -j- j--
									 ((jogo[3] == p2_o) && (jogo[6] == p2_o)))){ //--- --j j--
				decisao = 1 ;
			}

			//Grupo de combinacoes pra jogar na posicao 2.
			if ((jogo[1] == '-') && (((jogo[0] == p2_o) && (jogo[2] == p2_o)) or //j!j -!- ---
									 ((jogo[4] == p2_o) && (jogo[7] == p2_o)))){ //--- -j- ---
									                                            	 //--- -j- ---
				decisao = 2 ;
			}

			//Grupo de combinacoes pra jogar na posicao 3.
			if ((jogo[2] == '-') && (((jogo[0] == p2_o) && (jogo[1] == p2_o)) or //jj! --! --!
									 ((jogo[4] == p2_o) && (jogo[6] == p2_o)) or //--- -j- --j
									 ((jogo[5] == p2_o) && (jogo[8] == p2_o)))){ //--- j-- --j
				decisao = 3 ;
			}

			//Grupo de combinacoes pra jogar na posicao 4.
			if ((jogo[3] == '-') && (((jogo[0] == p2_o) && (jogo[6] == p2_o)) or //j-- --- ---
									 ((jogo[4] == p2_o) && (jogo[5] == p2_o)))){ //!-- !jj ---
									                                            	 //j-- --- ---
				decisao = 4 ;
			}

			//Grupo de combinacoes pra jogar na posicao 5.
			if ((jogo[4] == '-') && (((jogo[0] == p2_o) && (jogo[8] == p2_o)) or //j-- --j --- -j-
									 ((jogo[6] == p2_o) && (jogo[2] == p2_o)) or //-!- -!- j!j -!-
									 ((jogo[3] == p2_o) && (jogo[5] == p2_o)) or //--j j-- --- -j-
									 ((jogo[1] == p2_o) && (jogo[7] == p2_o)))){
				decisao = 5 ;
			}

			//Grupo de combinacoes pra jogar na posicao 6.
			if ((jogo[5] == '-') && (((jogo[2] == p2_o) && (jogo[8] == p2_o)) or //--j --- ---
									 ((jogo[3] == p2_o) && (jogo[4] == p2_o)))){ //--! jj! ---
									                                             //--j --- ---
				decisao = 6 ;
			}

			//Grupo de combinacoes pra jogar na posicao 7.
			if ((jogo[6] == '-') && (((jogo[0] == p2_o) && (jogo[3] == p2_o)) or //j-- --j ---
									 ((jogo[4] == p2_o) && (jogo[2] == p2_o)) or //j-- -j- ---
									 ((jogo[7] == p2_o) && (jogo[8] == p2_o)))){ //!-- !-- !jj
				decisao = 7 ;
			}

			//Grupo de combinacoes pra jogar na posicao 8.
			if ((jogo[7] == '-') && (((jogo[6] == p2_o) && (jogo[8] == p2_o)) or //--- -j- ---
									 ((jogo[4] == p2_o) && (jogo[1] == p2_o)))){ //--- -j- ---
									                                           	 //j!j -!- ---
				decisao = 8 ;
			}

			//Grupo de combinacoes pra jogar na posicao 9.
			if ((jogo[8] == '-') && (((jogo[6] == p2_o) && (jogo[7] == p2_o)) or //--- j-- --j
									 ((jogo[4] == p2_o) && (jogo[0] == p2_o)) or //--- -j- --j
									 ((jogo[2] == p2_o) && (jogo[5] == p2_o)))){ //jj! --! --!
				decisao = 9 ;
			}
//########################################################################################################

//#######################################################################################################



		    switch (auter) { //De acordo com auter definice quem vai jogar.

	          	case 1 ://caso auter igual a 1 o player 1 joga

                    caractererro:

	          		controle = 0 ;
					cin >> controle ;

					break ;

	          	case -1 :

                    if (check_jogada == 0) {
                        decisao = 0 ;
                    }

	          		switch (decisao) {

	          			case 1 :
	          				if (jogo[0] == '-') {
	          				controle = 1 ;
							}break ;

	          			case 2 :
	          				if (jogo[1] == '-') {
	          				controle = 2 ;
							}break ;

						case 3 :
							if (jogo[2] == '-') {
	          				controle = 3 ;
							}break ;

	          			case 4 :
	          				if (jogo[3] == '-') {
	          				controle = 4 ;
							}break ;

	          			case 5 :
	          				if (jogo[4] == '-') {
	          				controle = 5 ;
							}break ;

	          			case 6 :
	          				if (jogo[5] == '-') {
	          				controle = 6 ;
							}break ;

						case 7 :
							if (jogo[6] == '-') {
	          				controle = 7 ;
							}break ;

						case 8 :
							if (jogo[7] == '-') {
	          				controle = 8 ;
							}break ;

						case 9 :
							if (jogo[8] == '-') {
	          				controle = 9 ;
							}break ;

	          			case 0 :
	          				if 	(check_jogada == 0) {
				          		decisao_aleato = (rand( ) % 9 + 1) ;
				          		controle = decisao_aleato++ ;
				          	 	break ;
							}

	          		}
		    }






			switch (controle) {//Mapeamento de controles ,de acordo com o valor de "controle" o jogo[valor de "controle" - 1] receber valor de x_ou_o.

		  		case 1 :
		    		if (jogo [0] == '-' ) {
		      			jogo [0] = x_ou_o ;
		     			auter = auter * (-1) ;
		    			numjog = numjog + 1 ;
		   			} break ;

		  		case 2 :
		    		if (jogo [1] == '-' ) {
		      			jogo [1] = x_ou_o ;
		    			auter = auter * (-1) ;
		    			numjog = numjog + 1 ;
		   			} break ;

				case 3 :
					if (jogo [2] == '-' ) {
				      	jogo [2] = x_ou_o ;
				     	auter = auter * (-1) ;
				    	numjog = numjog + 1 ;
					} break ;

				case 4 :
					if (jogo [3] == '-' ){
				    	jogo [3] = x_ou_o ;
				     	auter = auter * (-1) ;
				    	numjog = numjog + 1 ;
					} break ;

				case 5 :
					if (jogo [4] == '-' ){
				    	jogo [4] = x_ou_o ;
				     	auter = auter * (-1) ;
				    	numjog = numjog + 1 ;
					} break ;

				case 6 :
					if (jogo [5] == '-' ){
				    	jogo [5] = x_ou_o ;
				     	auter = auter * (-1) ;
				    	numjog = numjog + 1 ;
				   	} break ;

				case 7 :
				    if (jogo [6] == '-' ){
				      	jogo [6] = x_ou_o ;
				     	auter = auter * (-1) ;
				    	numjog = numjog + 1 ;
				   	} break ;

				case 8 :
					if (jogo [7] == '-' ){
					  	jogo [7] = x_ou_o ;
				     	auter = auter * (-1) ;
				    	numjog = numjog + 1 ;
					} break ;

				case 9 :
				    if (jogo [8] == '-' ){
				      	jogo [8] = x_ou_o ;
				     	auter = auter * (-1) ;
				    	numjog = numjog + 1 ;
				   	} break ;
				case 10 :
					menu :
					system("cls");
					cout << "*------------------------------MENU------------------------------*" << endl ;
					cout << endl

					<< "Comandos :" << endl
					<< "reset - Nova partida." << endl
					<< "tutorial - tutorial." << endl
					<< "inicio - Recomeca jogo." << endl
					<< "easy - Ativar modo facil." << endl
					<< "medium - Ativar modo m�dio." << endl
					<< "hard - Ativar modo dif�cil." << endl
					<< "credits - Creditos do jogo." << endl
					<< "cheats - Menu de cheats." << endl
					<< "valor - valor de variaves" << endl
					<< "sair - Sair do jogo." << endl
					<< "v - Voltar para o jogo." << endl
					<< endl
					<< " *** Nem tudo funciona aqui ***" << endl
					<< "talzez em atualizacoes futuras !!" << endl ;
					cin >> comandos ;
					if (comandos == "credits"){
						system("cls") ;
						cout << "Gabriel de Jesus Santos" << endl ;
						system ("pause") ;
						goto menu ;
					}
					if (comandos == "sair"){
						goto sair ;
					}
					if (comandos == "tutorial"){
						tutorial () ;
						system ("pause") ;
					}
					if (comandos == "reset"){
						reset () ;
						zerar_pos_jogadas() ;
					}
					if (comandos == "valor"){

                        if (showvalor == 0) {
                            showvalor = 1;
                        } else {
                            showvalor = 0;
                        }


					}


		  	}



			imprimir () ;

            if (showvalor == 1) {
                logva () ;
            }

			posicoes_jogadas() ;

		  	//combinacao para ganha

		    if ((jogo [0]  == 'x') && //xxx
			    (jogo [1]  == 'x') && //
		        (jogo [2]  == 'x')) { //
				vencedor = 1 ;
		       	break ;
		    }

			if ((jogo [3]  == 'x') && //
			    (jogo [4]  == 'x') && //xxx
		        (jogo [5]  == 'x')) { //
				vencedor = 1 ;
		       	break ;
		    }

			if ((jogo [6]  == 'x') && //
			    (jogo [7]  == 'x') && //
		        (jogo [8]  == 'x')) { //xxx
				vencedor = 1 ;
		       	break ;
		    }

			if ((jogo [0]  == 'x') && //x
			    (jogo [3]  == 'x') && //x
		        (jogo [6]  == 'x')) { //x
				vencedor = 1 ;
		       	break ;
		    }

			if ((jogo [1]  == 'x') && // x
			    (jogo [4]  == 'x') && // x
		        (jogo [7]  == 'x')) { // x
				vencedor = 1 ;
		       	break ;
		    }

			if ((jogo [2]  == 'x') && //  x
			    (jogo [5]  == 'x') && //  x
		        (jogo [8]  == 'x')) { //  x
				vencedor = 1 ;
		       	break ;
		    }

			if ((jogo [0]  == 'x') && //x
			    (jogo [4]  == 'x') && // x
		        (jogo [8]  == 'x')) { //  x
				vencedor = 1 ;
		       	break ;
		    }

			if ((jogo [2]  == 'x') && //  x
			    (jogo [4]  == 'x') && // x
		        (jogo [6]  == 'x')) { //x
				vencedor = 1 ;
		       	break ;
		    }

		  	//combinacao para o jogador (2;o) ganha

		    if ((jogo [0]  == 'o') && //ooo
			    (jogo [1]  == 'o') && //
		        (jogo [2]  == 'o')) { //
				vencedor = 0 ;
		       	break ;
		    }

			if ((jogo [3]  == 'o') && //
			    (jogo [4]  == 'o') && //ooo
		        (jogo [5]  == 'o')) { //
				vencedor = 0 ;
		       	break ;
		    }

			if ((jogo [6]  == 'o') && //
				(jogo [7]  == 'o') && //
		    	(jogo [8]  == 'o')) { //ooo
				vencedor = 0 ;
		       	break ;
		    }

			if ((jogo [0]  == 'o') && //o
			    (jogo [3]  == 'o') && //o
		        (jogo [6]  == 'o')) { //o
				vencedor = 0 ;
		       	break ;
		    }

			if ((jogo [1]  == 'o') && // o
			    (jogo [4]  == 'o') && // o
		        (jogo [7]  == 'o')) { // o
				vencedor = 0 ;
		       	break ;
		    }

			if ((jogo [2]  == 'o') && //  o
			    (jogo [5]  == 'o') && //  o
		        (jogo [8]  == 'o')) { //  o
				vencedor = 0 ;
		       	break ;
		    }

			if ((jogo [0]  == 'o') && //o
			    (jogo [4]  == 'o') && // o
		        (jogo [8]  == 'o')) { //  o
				vencedor = 0 ;
		       	break ;
		    }

			if ((jogo [2]  == 'o') && //  o
			    (jogo [4]  == 'o') && // o
		        (jogo [6]  == 'o')) { //o
				vencedor = 0 ;
		       	break ;
		    }

		    if ((jogo[0] != '-') &&
				(jogo[1] != '-') &&
				(jogo[2] != '-') &&
				(jogo[3] != '-') &&
				(jogo[4] != '-') &&
				(jogo[5] != '-') &&
				(jogo[6] != '-') &&
				(jogo[7] != '-') &&
				(jogo[8] != '-')) {
				vencedor = 2 ; //empate .
				break ;
			}

		imprimir () ;

		posicoes_jogadas() ;

        if (showvalor == 1) {
            logva () ;
        }


		}

		switch (vencedor) {
			case 1 :
		 		cout << "Voce ganhou!" << endl ;
		 		cout << "Voce ganhou em " << numjog << " jogadas!" << endl;
		 		partid_wins_p1 = partid_wins_p1 + 1 ;
		 		auter = 1;
		 		zerar_pos_jogadas() ;
		 		cout << "Na proxima voce comeca ." << endl;
		 		break ;
		 	case 0 :
		 		cout << "Voce perdeu!" << endl ;
		 		cout << "Voce perdeu em " << numjog << " jogadas!" << endl;
		 		partid_wins_p2 = partid_wins_p2 + 1 ;
		 		zerar_pos_jogadas();
		 		auter = -1;
		 		break ;
		 	case 2 :
		 		auter = rand() % 2 + 1 ; //Caso empate proximo jogador e escolhido aleatoriamente.
		 		if (auter == 2){ //O valor 2 nao e permitido,entao troca esse valor por -1.
		 			auter = auter-1 ;
				}
		 		cout << "Empate!" << endl ;
		 		cout << "Empate em " << numjog << " jogadas!" << endl;
		 		zerar_pos_jogadas() ;
		 		if (auter == 1) {
		 			cout << "Na proxima voce comeca ." << endl;

				}
		 		break ;
		}

		system ("pause") ;
	}
	sair :
return 0 ;
}



