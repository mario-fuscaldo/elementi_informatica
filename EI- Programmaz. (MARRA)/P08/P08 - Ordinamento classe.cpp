/* 	M: Questo programma permette di generare un vettore di numeri pseudo-randomici con N specificato (da 20 a 100), 
ordinarlo con uno degli algoritmi di ordinamento scelto dall'utente, visualizzarlo e permettere di cercare un valore con 
ricerca binaria
 	AUTORE: Francesco Marra
	VERSIONE: v1.0
	ULTIMA MODIFICA: 11/12/2020
*/
#include <iostream>
#include <string.h>

#define N_MAX 30
using namespace std;


typedef struct{
	char Nome[30];
	char Cognome[30];
	int eta;	
}Studente;

typedef Studente tipo_v;


Studente leggi_Studente();
void inserisci_Studente(tipo_v v[],int &n,tipo_v s);
//int elimina_Studente(tipo_v v[],int &n,int i_s);
void visualizza_classe(Studente v[],int n);

bool confronta_studente(Studente,Studente);
void ordina_classe_inplace(tipo_v v[],int n);

int main(){
	

	int n;
	char scelta;
	Studente s,classe[N_MAX];

	cout << "Inserisci nuovo studente?(y/n)";
	cin >> scelta;
	
	while(n<N_MAX && scelta=='y'){
		s = leggi_Studente();
		inserisci_Studente(classe,n,s);
		cout << "Inserisci nuovo studente?(y/n)";
		cin >> scelta;
	}
		
	cout << "Classe disordinata: " << endl;
	visualizza_classe(classe,n);	

	cout << endl << "Classe ordinata: " << endl;
	ordina_classe_inplace(classe,n);
	visualizza_classe(classe,n);	

	cout << endl;
	
	
	cout << endl << endl;
	system("pause");
}

Studente leggi_Studente(){
	Studente s;
	cout << "Inserisci nome: " ;
	cin >> s.Nome;
	cout << "Inserisci cognome: " ;
	cin >> s.Cognome;	
	cout << "Inserisci eta': " ;
	cin >> s.eta;

	return s;
}


void inserisci_Studente(tipo_v v[],int &n,tipo_v s){
	v[n] = s;
	n++;
}



void visualizza_classe(Studente v[],int n){
	for(int i=0;i<n;i++)
		cout << i << ") " << v[i].Cognome << " - "<< v[i].Nome << " - " << v[i].eta <<endl;
}


void scambia(tipo_v v[],int i,int j){
	tipo_v temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	
}

bool confronta_studente(Studente v1,Studente v2){
	bool minore=false;
	int confronto;
	
	confronto = strcmp(v1.Cognome,v2.Cognome); // confrontiamo i cognomi
	if (confronto<0) //il cognome è alfabeticamente minore 
		minore = true;
	else if (confronto == 0){ // se i cognomi sono uguali confrontiamo i nomi
		confronto = strcmp(v1.Nome,v2.Nome); // confrontiamo i nomi
		if (confronto<0) //il nome è alfabeticamente minore 
			minore = true;
		else if (confronto == 0){ // se anche i nomi sono uguali confrontiamo le età
			minore = v1.eta < v2.eta; // confrontiamo le eta
		}
	}	
	
	return minore;
}


void ordina_classe_inplace(tipo_v v[],int n){
	
	int min,i,j;
	for(i=0; i<n-1; i++){
		// si trova l'elemento più piccolo dell'array e si scambia con l'elemento alla posizione i
		min=i;   
		for (j=i+1;j<n;j++){
			if ( confronta_studente(v[j],v[min]) )
				min=j;						
		}	
		scambia(v,i,min);
	}	
}

