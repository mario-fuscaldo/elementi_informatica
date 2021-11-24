// Soluzione prova programmazione 26-02-2021 
// Programma per giocare a carta alta vince con gli amici
// Una possibile soluzione....senza commenti!
#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

const int G_max = 10;
const int Nvalori=10;
const int Nsemi=4;

enum SEME{
	denari = 1,
	spade,
	coppe,
	bastoni
};

struct Carta{
	int valore;
	SEME seme;
};

struct Giocatore{
	char nome[31];
	Carta carta;
};

void crea_mazzo(Carta mazzo[],int &n_carte);
void crea_giocatori(Giocatore giocatori[],int &n_giocatori);
void mescola_mazzo(Carta mazzo[],int n_carte);
Carta estrai_carta(Carta mazzo[],int &n_carte);
void visualizza_carta(Carta c);
void dichiara_vincitore(Giocatore giocatori[],int n_giocatori);

void mescola_giocatori(Giocatore giocatori[],int n_giocatori);


int main()
{
	srand(time(NULL));
	
	int n_carte;
	Carta mazzo[Nvalori*Nsemi];

	int n_giocatori = 0;
	Giocatore giocatori[G_max];

	char scelta1,scelta2;

	cout << "Questo programma consente di giocare a Carta Più Alta con i tuoi amici."<<endl<<endl;
	
	do{
		cout << "Giochiamo!" << endl << endl;	
		
		crea_giocatori(giocatori, n_giocatori);
		do{
			crea_mazzo(mazzo,n_carte);
			mescola_giocatori(giocatori,n_giocatori);
			
			for(int i=0;i<n_giocatori;i++){
				cout << "Gioca: " << giocatori[i].nome << endl;
				mescola_mazzo(mazzo,n_carte);
				giocatori[i].carta = estrai_carta(mazzo,n_carte);
				cout << "Carta estratta: " << endl;
				visualizza_carta(giocatori[i].carta);
				cout << endl << endl;
			}

			dichiara_vincitore(giocatori,n_giocatori);
			
			cout << "Rigiochi con gli stessi giocatori(s/n)? ";
			cin >> scelta1;
		}while(scelta1 == 's');
		cout << "Rigiochi con altri giocatori(s/n)? ";
		cin >> scelta2;
	}while(scelta2 == 's');
	
	cout<<endl<<endl;
	system("pause");
}




void crea_giocatori(Giocatore giocatori[],int &n_giocatori){
	
	cout << "Quanti giocatori ci sono? ";
	cin >> n_giocatori;
	while (n_giocatori<2 || n_giocatori>10){
		cout << "Posono esserci minimo 2 giocatori e massimo 10! " << endl << "Quanti giocatori ci sono? ";
		cin>>n_giocatori;
	}

	for(int i = 0 ; i < n_giocatori;i++){
		cout << "Nome del " << i+1 << " giocatore: ";
		cin >> giocatori[i].nome;		
	}
	
}
void crea_mazzo(Carta mazzo[],int &n_carte)
{
	n_carte = Nvalori*Nsemi;
	for(int i=0;i<Nsemi;i++)
		for(int j=0;j<Nvalori;j++)
		{	
			mazzo[i*Nvalori+j].valore=j+1;
			mazzo[i*Nvalori+j].seme=SEME(i+1);
		}
	
	//Altro metodo
	//for(int i=0;i<n_carte;i++){
	//		mazzo[i].valore = (i% Nvalori)+1;
	//		mazzo[i].seme   = SEME( int(i/Nvalori) + 1 );
	//} 
	
	//Altro metodo
	//n_carte = 0;
	//for(int S = 1; i<=Nsemi; i++)
	//	for(int v = 1; j<=Nvalori; j++){
	//		mazzo_[n_carte].valore = v;
	//		mazzo_[n_carte].seme = s;
	//		n_carte++;
	//	}	
	
	
			
	
	cout<<"Mazzo creato!"<<endl;
}

Carta estrai_carta(Carta mazzo[],int &n_carte)
{
	int estratto;
	Carta estratta;
	estratto=rand()%(n_carte);
	estratta = mazzo[estratto];
	for(int i=estratto+1; i < n_carte;i++){
		mazzo[i-1] = mazzo[i];
	}
	n_carte--;
	return estratta;
}

void visualizza_carta(Carta c)
{
	cout<<c.valore<<" di ";
	switch(c.seme)
	{
		case denari:
			cout<<"denari";
			break;
		case spade:
			cout<<"spade";
			break;
		case coppe:
			cout<<"coppe";
			break;
		case bastoni:
			cout<<"bastoni";
			break;
	}
}

void mescola_mazzo(Carta mazzo[],int n_carte)
{
	int Nmischiate;
	int casuale;
	Carta mazzomischiato[n_carte];
	
	cout<<"Quante volte si desidera mescolare? ";
	cin>>Nmischiate;
	
	for(int m=0;m<Nmischiate;m++)
	{
		for(int i=0;i<n_carte;i++)
		{
			casuale=rand()%(n_carte - i);
			mazzomischiato[i]=mazzo[casuale];
			for(int j=casuale+1;j<n_carte-i;j++)
				mazzo[j-1]=mazzo[j];
		}

		for(int i=0;i<n_carte;i++)
			mazzo[i]=mazzomischiato[i];
		cout<<"Mescolato per la "<< m << " volta!"<<endl;
	}
}

void mescola_giocatori(Giocatore giocatori[],int n_giocatori)
{
	int casuale;
	Giocatore giocatori_mischiato[n_giocatori];
	
	for(int i=0;i<n_giocatori;i++)
	{
		casuale=rand()%(n_giocatori - i);
		giocatori_mischiato[i]=giocatori[casuale];
		for(int j=casuale+1;j<n_giocatori-i;j++)
			giocatori[j-1]=giocatori[j];
	}

	for(int i=0;i<n_giocatori;i++)
		giocatori[i]=giocatori_mischiato[i];

}


void dichiara_vincitore(Giocatore giocatori[],int n_giocatori){
	
	int i_max = 0;
	for (int i = 1; i < n_giocatori;i++){
		if ((giocatori[i].carta.valore > giocatori[i_max].carta.valore) or ( (giocatori[i].carta.valore == giocatori[i_max].carta.valore)and (giocatori[i].carta.seme > giocatori[i_max].carta.seme) ) )
			i_max = i;		
	}

	cout << endl << "Il vincitore e': " << giocatori[i_max].nome << " con la carta ";
	visualizza_carta(giocatori[i_max].carta);
	cout << endl;
}

