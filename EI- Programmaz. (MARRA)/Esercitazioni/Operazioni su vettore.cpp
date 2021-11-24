/*
Risoluzione esercitazione "Operazioni su vettori". Il testo dell'esercizio è sul moodle del corso
*/

// Possibile soluzione (senza commenti)

#include<iostream>
#include<string.h>

#define N_MAX 100
using namespace std;

typedef int vettore[N_MAX];

void stampaVettore(vettore v,int n);
void invertiVettore(vettore v,int n, vettore v2);
void riempiVettore(vettore,int n);
void aggiungiVettore(vettore,int &n,int m);
void stampaVettoreOrdinato(vettore v,int n,bool crescente);

int totalePari(vettore v,int n,int z);

int main()
{
	vettore v,v2;
	int riemp=0;
	char scelta;
	bool continua=true;
	
	do
	{
		cout << endl <<	"1) Inserisci Vettore.";
		cout << endl <<	"2) Aggiungi a Vettore.";
		cout << endl << "3) Visualizza Vettore.";
		cout << endl <<	"4) Inverti vettore.";
		cout << endl <<	"5) Visualzza ordinato";
		cout << endl <<	"6) Calcolo pari (minori di z).";
		cout << endl << "7) Esci" << endl <<endl;

		cin>>scelta;
		switch(scelta)
		{
			case '1':
				cout << "Numero di elementi da inserire:" ;
				cin >> riemp;
				riempiVettore(v,riemp);
				break;
			case '2':
				int m;
				cout << "Numero di elementi da aggiungere:" ;
				cin >> m;
				aggiungiVettore(v,riemp,m);
				break;
			case '3':
				stampaVettore(v,riemp);
				break;
			case '4':
				invertiVettore(v,riemp,v2);
				stampaVettore(v2,riemp);
				break;
			case '5':
				char scelta_ordinamento;
				do{
					cout << "Stampa vettore crescente (c) o decrescente (d)? ";
					cin >> scelta_ordinamento;
				}while(! (scelta_ordinamento=='c' || scelta_ordinamento=='d'));
				
				stampaVettoreOrdinato(v,riemp,scelta_ordinamento=='c');
				break;
			case '6':
				int z,totale;
				cout << "Calcola somma interi, positivi, pari, minori di z" << endl;
				cout << "Inserisci z: ";
				cin >> z;				
				
				totale = totalePari(v,riemp,z);
				cout << "Somma: " << totale << endl;
				break;
			case '7':
				continua = false;
				break;
			default:
				cout << endl << endl << "Scelta Errata!" << endl;
		}
	}while(continua);
}

void stampaVettore(vettore v,int n){
	cout << "[ ";
	for (int i = 0; i<n;i++){
		cout << v[i] << " ";
	}
	cout << "]" <<endl;
}

void invertiVettore(vettore v,int n, vettore v2){
	for (int i = n-1; i>=0;i--){
		v2[ (n-1) - i ] = v[i];
	}
}

void riempiVettore(vettore v,int n){
	
	for (int i= 0;i<n;i++){
		cout << i+1 << "- Valore da inserire: ";
		cin >> v[i];
	}	
}

void aggiungiVettore(vettore v,int &n,int m){
	for (int j= 0;j<m;j++){
		cout << j+1 << "- Valore da aggiungere: ";
		cin >> v[n+j];
	}	
	n += m;
}


int totalePari(vettore v,int n,int z){
	int totale = 0;
	for (int i= 0;i<n;i++){
		if ( v[i]>0 && v[i]%2==0 && v[i]<z ){
			totale += v[i];
		}
	}
	return totale;
}


void ordinaVettore(vettore v,int i, int j,int index[], bool crescente){
	if (i<j){
		//trova il minimo/massimo
		int selezionato =i, temp;
		for(int k=i+1;k<j;k++){
			if ( (crescente && v[index[selezionato]]>v[index[k]]) || (!crescente  && v[index[selezionato]]<v[index[k]]) )
				selezionato = k;
		}

		//scambia
		temp = index[selezionato];
		index[selezionato] = index[i];
		index[i] = temp;		
		//ricorsione		
		ordinaVettore(v,i+1,j,index,crescente);	
	}
	
}

void stampaVettoreOrdinato(vettore v,int n,bool crescente){
	int index[n];
	for (int i=0;i<n;i++)
		index[i] = i;

	ordinaVettore(v,0,n,index,crescente);
	cout << "[ ";
	for (int i = 0; i<n;i++){
		cout << v[index[i]] << " ";
	}
	cout << "]";

	
}

