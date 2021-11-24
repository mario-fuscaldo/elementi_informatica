/* 	Funzioni di supporto per l'inserimento e la generazione di numeri e vettori random
 	AUTORE: Francesco Marra
	VERSIONE: v1.0
	ULTIMA MODIFICA: 16/12/2020
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "genera.h"
using namespace std;

int inserisci_numero(int min,int max){
	int n;
	do{
		cout << "Inserisci numero da " << min << " a " << max << ": ";
		cin >> n;	
	
	}while ( n < min || n >max);
	
	return n;	
}

int genera_intero(int Nmin,int Nmax){
	return rand()%(Nmax-Nmin+1)+Nmin;
}

float genera_reale(float Rmin,float Rmax){
	return float( rand() )/RAND_MAX *(Rmax-Rmin)+Rmin;
}

void genera_vettore_interi(int n,int v[],int Nmin,int Nmax){
	for(int i=0;i<n;i++){
		v[i] = genera_intero(Nmin,Nmax);
	}
}

void genera_vettore_reali(int n,float v[],float Rmin,float Rmax){
	for(int i=0;i<n;i++){
		v[i] = genera_reale(Rmin,Rmax);
	}
}

void visualizza_vettore_float(float v[],int n){
	cout << "Vettore: ";
	for(int i=0;i<n-1;i++){
		cout << v[i] << " - ";
	}
	cout << v[n-1] << endl;
}


