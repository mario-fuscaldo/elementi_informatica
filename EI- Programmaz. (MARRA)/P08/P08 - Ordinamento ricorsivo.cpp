/* 	M: Questo programma permette di generare un vettore di numeri pseudo-randomici con N specificato (da 20 a 100), 
ordinarlo con uno degli algoritmi di ordinamento scelto dall'utente, visualizzarlo e permettere di cercare un valore con 
ricerca binaria
 	AUTORE: Francesco Marra
	VERSIONE: v1.0
	ULTIMA MODIFICA: 11/12/2020
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

typedef int vettore[100];


int inserisci_numero(int min,int max);
void genera_vettore(int N,vettore v);
void visualizza_vettore(vettore v,int n);

void selection_sort(vettore v,int n);
void bubble_sort(vettore v,int n);
void bubble_sort_modificato(vettore v,int n);

void selection_sort_ricorsivo(vettore v,int i,int j);
int find_min(vettore v,int i,int j);

int ricerca_binaria(vettore v, int n, int x);


int main(){
	srand((unsigned int) time(NULL));
	vettore v;
	int n,x,scelta,pos;
	
	n = inserisci_numero(20,100);
	genera_vettore(n,v);
	visualizza_vettore(v,n);
	
	cout << "Seleziona algoritmo di ordinamento: " << endl;
	cout << "1) Selection sort" << endl;
	cout << "2) Selection sort ricorsivo" << endl;
	cout << "3) Bubble sort" << endl;
	cout << "4) Bubble sort modificato" << endl;

	scelta = inserisci_numero(1,4);
	switch (scelta){
	
		case 1: selection_sort(v,n);
				break;
		case 2: selection_sort_ricorsivo(v,0,n);
				break;
		case 3: bubble_sort(v,n);
				break;
		case 4: bubble_sort_modificato(v,n);
				break;
	}

	cout << endl;
	
	visualizza_vettore(v,n);
	
	cout << "Inserisci un numero da cercare: " ;
	cin >> x;

	pos = ricerca_binaria(v,n,x);
	
	
	if(pos!=-1)
		cout<<"Numero trovato in posizione: "<<pos<< "(infatti v["<<pos<< "]="<< v[pos] << ")"<<endl;
	else 
		cout<<"Numero non trovato" << endl;	
	
	cout << endl << endl;
	system("pause");
}


int inserisci_numero(int min,int max){
	int n;
	do{
		cout << "Inserisci numero da " << min << " a " << max << ": ";
		cin >> n;	
	
	}while ( n < min || n >max);
	
	return n;	
}

void genera_vettore(int n,vettore v){
	for(int i=0;i<n;i++){
		v[i] = rand() % 50; // modificare come si vuole
	}
}

void visualizza_vettore(vettore v,int n){
	cout << "Vettore: ";
	for(int i=0;i<n-1;i++){
		cout << v[i] << " - ";
	}
	cout << v[n-1] << endl;
}

void scambia(vettore v,int i,int j){
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	
}

void selection_sort(vettore v,int n){
	
	int min,i,j;
	for(i=0; i<n-1; i++){
		// si trova l'elemento più piccolo dell'array e si scambia con l'elemento alla posizione i
		min=i;   
		for (j=i+1;j<n;j++){
			if (v[j]<v[min])
				min=j;						
		}	
		scambia(v,i,min);
	}	
}

void bubble_sort(vettore v,int n){
	bool scambio;
	int i;
	do {
		scambio = false;
		for(i=0;i<n-1;i++)
			if(v[i]>v[i+1])
			{
				scambia(v,i,i+1);
				scambio = true;
		}
	} while (scambio);
		
}


void bubble_sort_modificato(vettore v,int n){

	bool scambio;
	int i,ultimo_scambio = n, u;

	do {
		scambio = false;
		for(i=0; i<ultimo_scambio-1; i++)
			if(v[i]>v[i+1])
			{
				scambia(v,i,i+1);
				scambio = true;
				u = i+1;
		}
		ultimo_scambio = u;
	} while (scambio);
		
}

int ricerca_binaria(vettore v, int n, int x){

	int primo=0, ultimo=n-1, medio, pos=-1;

	do { 
		medio= int( (primo+ultimo)/2);
		
		if (v[medio]==x)  
			pos=medio;
		else if (v[medio]<x)
			primo=medio+1;
		else
			ultimo=medio-1;

	} while(primo<=ultimo && pos==-1);	

	return pos;
}

int find_min(vettore v,int i,int j){
	int min = i;   
	for (int k=i+1;k<j;k++){
		if (v[k]<v[min])
			min=k;						
	}	
	return min;
}

void selection_sort_ricorsivo(vettore v,int i,int -j){
	if (i<j){
		int min = find_min(v,i,j);
		scambia(v,i,min);
		selection_sort_ricorsivo(v,i+1,j);
	}
}

