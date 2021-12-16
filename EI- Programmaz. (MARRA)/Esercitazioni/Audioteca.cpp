/*
Scrivere un programma in C++ che consente di inserire un array di CD, 
ognuno descritto dall'autore, il titolo, e i titoli delle tracce, e poi trovare un CD tra quelli inseriti.
A tale scopo, utilizzare la struttura descritta di seguito.

ESEMPIO DI FUNZIONAMENTO sul moodle del corso

OPZIONI --------------------------------
Questo programma consente di inserire una lista di CD, 
e di trovarne uno in base all'autore, al titolo o ai titoli delle tracce e visualizzare secondo l'ordine desiderato.

1) per inserire CD alla lista.
2) per trovare un CD in base all'autore.
3) per trovare un CD in base al titolo.
4) per trovare un CD in base al titolo di una traccia.
5) Visualzzare la lista (scelta ordinamento)
6) Esci

*/

// Possibile soluzione (senza commenti)

#include<iostream>
#include<string.h>
using namespace std;

const int C_max=31;
const int T_max=30;
const int CD_max=1000;

typedef char Titolo[C_max];
typedef char Autore[C_max];

struct cd
{
	Autore autore;
	Titolo titolo;
	int num_tracce;
	Titolo tracce[T_max];
	float prezzo;
	int anno;
};

typedef cd CDV[CD_max];

void inserisci(CDV v, int &riemp);
void trova_per_autore(CDV v, int riemp);
void trova_per_titolo(CDV v, int riemp);
void trova_per_traccia(CDV v, int riemp);

void scambia(int &c1,int &c2);
void visualizza_indice(CDV v,int riemp,int index[]);

void visualizza_ordinato_titolo(CDV v,int riemp);
void visualizza_ordinato_autore(CDV v,int riemp);
void visualizza_ordinato_anno(CDV v,int riemp);

int main()
{
	CDV v;
	int riemp=0;

	char scelta;
	bool continua=true;
	
	cout<<"Questo programma consente di inserire una lista di CD, e di trovarne uno in base all'autore, al titolo o ai titoli delle tracce.\n";
	do
	{
		cout << endl <<	"1) per inserire CD alla lista.";
		cout << endl <<	"2) per trovare un CD in base all'autore.";
		cout << endl <<	"3) per trovare un CD in base al titolo.";
		cout << endl <<	"4) per trovare un CD in base al titolo di una traccia.";
		cout << endl <<	"5) Visualzzare la lista (scelta ordinamento)";
		cout << endl << "6) Esci" << endl <<endl;

		cin>>scelta;
		switch(scelta)
		{
			case '1':
				inserisci(v,riemp);
				break;
			case '2':
				trova_per_autore(v,riemp);
				break;
			case '3':
				trova_per_titolo(v,riemp);
				break;
			case '4':
				trova_per_traccia(v,riemp);
				break;
			case '5':{
				char scelta_ordinamento;
				cout << endl;
				cout << "Ordinare in base a:";
				cout << endl <<	"\t1) Autore";
				cout << endl <<	"\t2) Titolo";
				cout << endl <<	"\t3) Anno di uscita" << endl;
				cin  >> scelta_ordinamento;

				switch (scelta_ordinamento)
				{
					case '1': 
							  visualizza_ordinato_autore(v,riemp);
							  break;							  
					case '2':
							  visualizza_ordinato_titolo(v,riemp);
							  break;							  
					case '3':
							  visualizza_ordinato_anno(v,riemp);
							  break;
					default: cout << "Scelta ordinamento errata!"  << endl;
				}
				break;
			}

			case '6':
				continua = false;
				break;
			default:
				cout << endl << endl << "Scelta Errata!" << endl;	//PROFESSORE: avevo scritto di scrivere 
		}
	}while(continua);
}


void inserisci(CDV v, int &riemp)
{
	char continua='y';
	int n;
	
	while(continua=='y' && riemp<CD_max)
	{
		cout<<"Inserisci autore: ";
		cin.ignore();
		cin.get(v[riemp].autore,C_max);
		cout<<"Inserisci titolo CD: ";
		cin.ignore();
		cin.get(v[riemp].titolo,C_max);
		cout<<"Inserisci numero tracce: ";
		cin>>n;
		while(n>T_max)
		{
			cout<<"Numero di tracce troppo alto. Riprova: ";
			cin>>n;
		}
		v[riemp].num_tracce = n;
		for(int i=0;i<n;i++)
		{
			cout<<"Titolo traccia "<<i+1<<": ";
			cin.ignore();
			cin.get(v[riemp].tracce[i],C_max);
		}
		cout<<"Inserisci prezzo in euro: ";
		cin>>v[riemp].prezzo;

		cout<<"Inserisci anno di uscita: ";
		cin>>v[riemp].anno;

		riemp++;
		cout<<"Ci sono altri CD? (y/n): ";
		cin>>continua;
	}
	
	
}

void trova_per_autore(CDV v, int riemp)
{
	Autore criterio;
	
	cout<<"Inserisci autore: ";
	cin.ignore();
	cin.get(criterio,T_max);
	for(int i=0;i<riemp;i++)
		if(strcmp(criterio,v[i].autore)==0)
			cout<<v[i].autore<<" - "<<v[i].titolo<<" ("<<v[i].anno<<") - "<<v[i].prezzo<<" euro\n";

}

void trova_per_titolo(CDV v, int riemp)
{
	Titolo criterio;
	
	cout<<"Inserisci titolo CD: ";
	cin.ignore();
	cin.get(criterio,T_max);
	for(int i=0;i<riemp;i++)
		if(strcmp(criterio,v[i].titolo)==0)
			cout<<v[i].autore<<" - "<<v[i].titolo<<" ("<<v[i].anno<<") - "<<v[i].prezzo<<" euro\n";
}

void trova_per_traccia(CDV v, int riemp)
{
	Titolo criterio;
	
	cout<<"Inserisci titolo traccia: ";
	cin.ignore();
	cin.get(criterio,T_max);

	for(int i=0;i<riemp;i++)
		for(int j=0;j<v[i].num_tracce ;j++)
			if(strcmp(criterio,v[i].tracce[j])==0)
				cout<<v[i].autore<<" - "<<v[i].titolo<<" ("<<v[i].anno<<") - "<<v[i].prezzo<<" euro\n";
}


void visualizza_indice(CDV v,int riemp,int index[]){
	for(int i=0;i<riemp;i++)
			cout<<v[index[i]].autore<<" - "<<v[index[i]].titolo<<" ("<<v[index[i]].anno<<") - "<<v[index[i]].prezzo<<" euro\n";
}

void scambia(int &c1,int &c2){
	int temp;
	temp = c1;
	c1 = c2;
	c2 = temp;
}

void visualizza_ordinato_titolo(CDV v,int riemp){
	int indici[riemp];
	int idx_min;
	
	for (int i = 0; i<riemp;i++)
		indici[i] = i;
		
	for (int i = 0; i<riemp-1; i++){
		idx_min = i;
		for (int j=i+1;j<riemp;j++){
			if ( strcmp(v[indici[idx_min]].titolo, v[indici[j]].titolo)>0  ){
				idx_min = j;
			}			
		}
		scambia(indici[i],indici[idx_min]);

	}
	
	visualizza_indice(v,riemp,indici);	
}


void visualizza_ordinato_autore(CDV v,int riemp){
	int indici[riemp];
	int idx_min;
	
	for (int i = 0; i<riemp;i++)
		indici[i] = i;
		
	for (int i = 0; i<riemp-1; i++){
		idx_min = i;
		for (int j=i+1;j<riemp;j++){
			if ( strcmp(v[indici[idx_min]].autore, v[indici[j]].autore)>0  ){
				idx_min = j;
			}			
		}
		scambia(indici[i],indici[idx_min]);

	}
	
	visualizza_indice(v,riemp,indici);	
}

void visualizza_ordinato_anno(CDV v,int riemp){
	int indici[riemp];
	int idx_min;
	
	for (int i = 0; i<riemp;i++)
		indici[i] = i;
		
	for (int i = 0; i<riemp-1; i++){
		idx_min = i;
		for (int j=i+1;j<riemp;j++){
			if ( v[indici[idx_min]].anno > v[indici[j]].anno  ){
				idx_min = j;
			}			
		}
		scambia(indici[i],indici[idx_min]);
	}
	
	visualizza_indice(v,riemp,indici);	
}

