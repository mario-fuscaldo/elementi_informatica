// Soluzione prova programmazione 26-03-2021 
// Parcheggio Brin
// Una possibile soluzione....senza commenti!
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

const int M = 10;
const int N=4;
const float prezzo_orario=1.5;

struct Autovettura{
	char targa[21];
	char modello[31];
	char colore[21];
};

struct Orario{
	int ora;
	int min;
};

struct Posto{
	Autovettura autov;
	Orario orario;
};


struct Piano{
	Posto posto[M];
	int occupato[M];
	
};

typedef Piano Parcheggio[N];

void visualizza_menu();
void crea_parcheggio(Parcheggio park);

void stampa_posti_liberi(Parcheggio park);
void stampa_posti_occupati(Parcheggio park);

double calcola_sosta(Posto p, Orario orario_attuale);
Orario inserisci_orario();
bool seleziona_posto(Parcheggio park, int riempimento_piani[N],int primo_disponibile[N]);

double uscita_vettura(Parcheggio park);
void entrata_vettura(Parcheggio park);

int main(){
	
	Parcheggio park;
	double incasso = 0;
	char scelta;
	bool uscita = false;
	
	crea_parcheggio(park);
	
	do{
		visualizza_menu();
		
		cout << endl << "Scelta: " << endl;
		cin >> scelta;
		
		switch (scelta){
			case '1':{
				stampa_posti_liberi(park);
				break;
			}
			case '2':{
				stampa_posti_occupati(park);
				break;
			}
			case '3':{
				entrata_vettura(park);
				break;
			}
			case '4':{
				incasso += uscita_vettura(park);
				break;
			}
			case '5':{
				cout << "Incasso :" << incasso << " euro"<<endl;
				break;
			}
			case 'E':{
				
				bool liberi = true;
				int i=0,j=0;
				
				while ((liberi) && (i<N)){
					j = 0;
					while ((liberi) && (j<M)){
						if (park[i].occupato[j] == 1)
							liberi = false;
						j++;			 
					}
					i++;
				}
				
				if (liberi){
					uscita = true;
				}
				else{
					char s;
					cout << "ATTENZIONE ci sono ancora autovetture nel parcheggio, proseguire?(y/n)";
					cin.ignore();
					cin >> s;
					if (s == 'y')
						uscita = true;
				}
				
				break;
			}
		}
	}while(!uscita);

	cout << "Parcheggio chiuso!";
}


void visualizza_menu(){
	cout << "---------------------------------------" << endl;
	cout << "Seleziona un'operazione da effettuare: " << endl;
	cout << "1- Stampa posti liberi" << endl;
	cout << "2- Stampa posti occupati" << endl;
	cout << "3- Entrata vettura " << endl;
	cout << "4- Uscita vettura" << endl;
	cout << "5- Visualizza incasso" << endl;
	cout << "E- Chiudi parcheggio" << endl;
	cout << "-----------------------------------------------" << endl;	
}

void crea_parcheggio(Parcheggio park){	
	for (int i=0; i < N; i++)
		for (int j=0; j < M; j++)
			park[i].occupato[j] = 0;	

}

void stampa_posti_liberi(Parcheggio park){
	int liberi;
	
	for (int i=0; i < N; i++){
		liberi = M;
		for (int j=0; j < M; j++)
			liberi -= park[i].occupato[j];
	
		cout << "PIANO " << i+1<< ": ";
		if (liberi == 0)
			cout << "nessun posto libero";
		else if (liberi == 1)
			cout << "1 posto libero";
		else
			cout << liberi << " posti liberi";
		
		cout << endl;						
	}

}


void visualizza_auto(Posto posto){
	cout << posto.autov.targa << " - " << posto.autov.modello << " - " << posto.autov.colore << " - Entrata: " << posto.orario.ora << "." << posto.orario.min << endl;	
}

void stampa_posti_occupati(Parcheggio park){
	int occupati_piano;
	for (int i=0; i < N; i++){
		cout << "Piano " << i+1 << ":" <<endl;
		occupati_piano = 0;	
		for (int j=0; j < M; j++)
			if (park[i].occupato[j] == 1){
				cout << "Posto " << j+1 << ": ";
				visualizza_auto(park[i].posto[j]);
				cout << endl;				
				occupati_piano++;
			}	
		if (occupati_piano == 0)
			cout << "Nessuna auto" << endl;
	}
}

bool seleziona_posto(Parcheggio park, int riempimento_piani[N],int primo_disponibile[N]){
	bool libero = false;
	int occupati_piano;
	
	for (int i=0; i < N; i++){
		occupati_piano = 0;	
		primo_disponibile[i] = -1;
		for (int j=0; j < M; j++){
			if (park[i].occupato[j] == 0){
				if (primo_disponibile[i] == -1)
					primo_disponibile[i] = j;
			}else{
				occupati_piano++;
			}				
		}	
		if (occupati_piano<M)
			libero = true;
			
		riempimento_piani[i] = occupati_piano;
	}
	return libero;
}


Orario inserisci_orario(){
	Orario orario;
	do{
		cout << "Ora ingresso: ";
		cin >> orario.ora;
	}while(orario.ora <0 || orario.ora > 23);
	
	do{
		cout << "Minuto ingresso: ";
		cin >> orario.min;	
	}while(orario.min<0 || orario.min > 59);
		
	return orario;
}

void entrata_vettura(Parcheggio park){
	
	int riempimento_piani[N], primo_disponibile[N];
	Autovettura autov;
	Orario orario;
	int piano_selezionato, posto_selezionato;
		
	if (seleziona_posto(park, riempimento_piani, primo_disponibile)){
		cout << "Inserisci targa: " ;
		cin.ignore();
		cin.get(autov.targa, 20);

		cout << "Inserisci modello: " ;
		cin.ignore();
		cin.get(autov.modello, 30);

		cout << "Inserisci colore: " ;
		cin.ignore();
		cin.get(autov.colore, 20);
		
		piano_selezionato = 0;
		for(int i = 1; i<N;i++)
			if (riempimento_piani[i] < riempimento_piani[piano_selezionato])
				piano_selezionato = i;
		
		posto_selezionato = primo_disponibile[piano_selezionato];		
		orario = inserisci_orario();
		
		park[piano_selezionato].occupato[posto_selezionato] = 1;
		park[piano_selezionato].posto[posto_selezionato].autov = autov;
		park[piano_selezionato].posto[posto_selezionato].orario = orario;

		cout << endl;
		cout << "Posto assegnato: Piano " << piano_selezionato + 1 << " - Posto " << posto_selezionato + 1 << endl << endl;
				
	}	
	else{
		cout << "Parcheggio pieno…torna dopo!";
	}
	
}

double calcola_sosta(Orario orario_sosta, Orario orario_attuale){
	double prezzo;
	prezzo =  ceil(double( (orario_attuale.ora - orario_sosta.ora ) * 60 + (orario_attuale.min - orario_sosta.min) ) / 60 );
	return prezzo;
}

double uscita_vettura(Parcheggio park){
	double prezzo = 0;
	char targa[21];
	int piano = -1, posto = -1;
	char scelta;

	cout << "Inserisci targa:" ;
	cin.ignore();
	cin.get(targa, 20);
	
	for (int i=0; i < N; i++){
		for (int j=0; j < M; j++){
			if (park[i].occupato[j] == 1){
				if (strcmp(park[i].posto[j].autov.targa, targa)==0){
					piano = i;
					posto = j;
				}
			}		
		}	
	}
	
	if (piano == -1){
		cout << "Automobile non presente nel parcheggio" << endl;
	}
	else{
		Orario orario_attuale;
		orario_attuale = inserisci_orario();
		while ( (orario_attuale.ora*60+orario_attuale.min) < (park[piano].posto[posto].orario.ora*60+park[piano].posto[posto].orario.min) ){
			cout << "ORARIO NON COERENTE (Entrata: "<< park[piano].posto[posto].orario.ora << "." << park[piano].posto[posto].orario.min << ")" << endl;
			orario_attuale = inserisci_orario();
		}
		
		visualizza_auto(park[piano].posto[posto]);
		
		cout << "Prezzo: " << calcola_sosta(park[piano].posto[posto].orario,orario_attuale) << " euro" << endl;
		
		cout << "Fai uscire questa auto? (y/n): ";
		cin >> scelta;
		if (scelta == 'y'){
			prezzo = calcola_sosta(park[piano].posto[posto].orario,orario_attuale);	
			park[piano].occupato[posto] = 0;
		}			
	}

	return prezzo;
}
