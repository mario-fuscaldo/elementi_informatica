/* 	M: Questo programma permette di inserire una parola e controllare se è palindroma
 	AUTORE: Francesco Marra
	VERSIONE: v1.0
	ULTIMA MODIFICA: 11/12/2020
*/
#include <iostream>
#include <string.h>
using namespace std;

typedef char stringa[100];

int palindroma(stringa,int, int);
void inserisci_stringa(stringa);

int main(){
	stringa s;
	cout << "Questo programma permette di controllare se una parola e'' palindroma" << endl << endl <<;

	inserisci_stringa(s);	
	cout << endl << "Parola inserita: " << s <<endl << endl;
	
	cout << "La parola inserita " ;
	
	if ( palindroma(s,0,strlen(s))  == 1)
		cout <<"e'";
	else 
		cout << "non e'";
	
	cout << " palindroma" << endl;	


	system("pause");
}

void inserisci_stringa(stringa v){
	cout << "Inserisci stringa: ";
	cin >> v;	
}

int palindroma(const stringa v, int i, int n){
/*
	funzione: palindroma
	La funzione verifica se una sottostringa data in ingresso dall'indice i all'indice n è palindroma
	input:
		- v: IN (const char [100]) stringa da verificare
		- i: IN (int) indice di inizio della sottostringa da verificare 
		- n: IN (int) indice di fine della sottostringa da verificare
	output:
		- int: 1 se palindroma, 0 altrimenti
*/
if (n <= i)
	return 1;
else{
	if (v[i] == v[n-1])                       
		return palindroma(v,i+1,n-1);
	else return 0;
	}
}
