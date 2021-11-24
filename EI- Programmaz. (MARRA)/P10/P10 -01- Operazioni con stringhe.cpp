/* 	M: Questo programma permette di inserire un numero N di parole (anche con spazi) e visualizzarle ordinate
 	AUTORE: Francesco Marra
	VERSIONE: v1.0
	ULTIMA MODIFICA: 11/12/2020
*/
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_S 255

typedef char stringa[MAX_S];

void leggi(stringa s);

void visualizza(stringa s);
void visualizza_maiuscola(stringa s);
void visualizza_minuscola(stringa s);
void visualizza_senza_spazi(stringa);
void visualizza_invertita(stringa);
int conta_caratteri(stringa);
int conta_parole(stringa);
int conta_carattere(stringa,char);

int main(){

	stringa s;
	int scelta;
	leggi(s);
	
	do{
			cout << "Seleziona una operazione: " << endl;
			cout << "1) Visualizza" << endl;
			cout << "2) Visualizza MAIUSCOLA" << endl;
			cout << "3) Visualizza minuscola" << endl;
			cout << "4) Visualizza senza spazi" << endl;
			cout << "5) Visualizza invertita" << endl;
			cout << "6) Conta caratteri" << endl;
			cout << "7) Conta parole" << endl;
			cout << "8) Conta carattere" << endl;
			cout << "9) Esci" << endl;

			cin >> scelta;
			switch (scelta){
			
				case 1: visualizza(s);
						break;
				case 2: visualizza_maiuscola(s);
						break;
				case 3: visualizza_minuscola(s);
						break;
				case 4: visualizza_senza_spazi(s);
						break;
				case 5: visualizza_invertita(s);
						break;
				case 6: {
						int n = conta_caratteri(s);
						cout << "Numero di caratteri: "<<n<<endl<<endl;
						break;
						}
				case 7: {
						int n = conta_parole(s);
						cout << "Numero di parole: "<<n<<endl<<endl;
						break;
						}
				case 8: {
						char c;
						cout << "Inserisci carattere: ";
						cin >> c;
						int n = conta_carattere(s,c);
						cout << "Numero di occorrenze del carattere '"<<c<<"' e': "<<n<<endl<<endl;
						break;
						}
				case 9: cout<< "Bye bye!"<<endl;
						break;

				default: cout<<endl<<"Scelta sbagliata"<<endl<<endl;;
			}
	}while(scelta!=9);

	
	return 0;
}

void leggi(char s[]){
	cout << "Inserisci la stringa: ";
	//cin.ignore();
	cin.get(s,MAX_S);
}

int conta_caratteri(stringa s){
	return strlen(s);
}

int conta_parole(stringa s){
	int n = strlen(s);
	int parole = 0;
	
	for(int i=0;i<n;i++){
		if (s[i]>32 && (s[i+1]==32 || s[i+1]=='\0')) // Una parola è contata quando incontro uno spazio (o un fine stringa) e 
													 // avevo uno spazio stampabile in posizione precedente.
													 // ignora gli spazi consecutivi...si può raffinare (tenere conto della punteggiatura)
			parole++;
	}
	return parole;
}


int conta_carattere(stringa s,char c){
	int car = 0;
	int n = strlen(s);
	
	for (int i= 0;i<n;i++){
		if (s[i]==c) 
			car++;
	}
	
	return car;	
}



void visualizza(stringa s){
	cout << "La stringa e':"<<endl<< s << endl<<endl;
}

void visualizza_maiuscola(stringa s){
	cout << "La stringa maiuscola e':"<<endl;
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		if (s[i] >=97 && s[i] <= 122)
			cout << char(s[i]-32);
		else
			cout << s[i];
		
	}
	cout << endl<<endl;
}

void visualizza_minuscola(stringa s){
	cout << "La stringa minuscola e':"<<endl;
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		if (s[i] >=65 && s[i] <= 90)
			cout << char(s[i]+32);
		else
			cout << s[i];
	}
	cout << endl<<endl;

}


void visualizza_senza_spazi(stringa s){
	cout << "La stringa senza spazi e':"<<endl;
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		if (s[i] !=32)
			cout << s[i];
	}
	cout << endl<<endl;

}



void visualizza_invertita(stringa s){
	cout << "La stringa invertita e':"<<endl;
	int n = strlen(s);
	for(int i = n-1; i >= 0; i--)
		cout << s[i];

	cout << endl<<endl;

}


