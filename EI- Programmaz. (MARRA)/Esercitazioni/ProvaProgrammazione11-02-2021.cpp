// Soluzione prova programmazione 11-02-2021 
// Programma per liceo di Acireale
// Una possibile soluzione....senza commenti!
#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <string.h>
using namespace std;



#define N_MAX 31 				// caratteri nome
#define C_MAX 26				// caratteri cognome
#define V_MAX 100				// numero voti max
#define S_MAX 100				// numero studenti max

typedef char Nome[N_MAX];
typedef char Cognome[C_MAX];
typedef float Voto[V_MAX];
typedef time_t Data[V_MAX];

struct Studente{
	Nome nome;
	Cognome cognome;
	int n_voti;
	Voto voto;
	Data data;	
};

typedef Studente Studenti[S_MAX];

// Prototipi funzioni richieste
void inserisci_studenti(Studenti v_,int &riemp_);
void visualizza_studenti(Studenti v_,int riemp_);
void visualizza_studente(Studenti v_,int riemp_);

void interroga_studente(Studenti v_,int riemp_);
void interroga_studente_casuale(Studenti v_,int riemp_);

// Prototipi funzioni di supporto
void scambia(Studenti v_, int i,int j);
void inserisci_voto(Studenti v_,int s);
void ordina_studenti(Studenti v_,int riemp_);


int main(){
	srand(time(0));
	Studenti v;
	int riemp=0;
	int scelta;
	bool continua = true;
	
	do{
		cout << "--------------------------------" << endl;
		cout << "1) inserire studenti" << endl;
		cout << "2) visualizzare lista studenti" << endl;
		cout << "3) visualizza dettaglio studente" << endl;
		cout << "4) interroga studente specifico" << endl;
		cout << "5) interroga studente casuale" << endl;
		cout << "6) Esci" << endl;
		
		
		cin >> scelta;
		
		switch(scelta){
			
			case 1:
				inserisci_studenti(v,riemp);
				ordina_studenti(v,riemp);
				break;
			
			case 2:
				visualizza_studenti(v,riemp);
				break;
			case 3:
				visualizza_studente(v,riemp);
				break;
			case 4:
				interroga_studente(v,riemp);
				break;
			case 5:
				interroga_studente_casuale(v,riemp);
				break;
			case 6:{
				cout << endl << "CIAO!";
				continua = false;
				break;
			}
			default:
				cout << endl << "Scelta sbagliata"; 
		
		cout << endl;
	
		}
		


	}while(continua);

	cout << endl << endl;
	return 0;

}

// Definizione funzioni
void inserisci_studenti(Studenti v_,int &riemp_){

    char continua='s';
    int n;

    while (continua=='s' && riemp_< S_MAX){
	
        cout << "Inserisci nome dello studente: ";
        cin.ignore();
        cin.get(v_[riemp_].nome, N_MAX);
    
        cout << "Inserisci cognome dello studente: ";
        cin.ignore();
        cin.get(v_[riemp_].cognome, C_MAX);
         
        v_[riemp_].n_voti = 0;
        riemp_++;

		do{
		    cout << "Inserire altri studenti? (s/n): ";
	        cin >> continua;
	        cout << endl;
		}while(continua != 's' and continua!='n');

	}
	return;
}



void visualizza_studenti(Studenti v_,int riemp_){

	float media = 0, media_classe = 0;
	int n_con_voti = 0;

    for (int i=0; i<riemp_; i++){
    	cout << i+1 << ")" << v_[i].cognome << " " << v_[i].nome << " - ";

	    if (v_[i].n_voti==0) cout << "N/A";
	    else{
	    	media = 0;
			for(int j = 0;j<v_[i].n_voti;j++) 
				media += v_[i].voto[j];	
			media /= v_[i].n_voti;
	    	
			cout << media;
			media_classe += media;
			n_con_voti += 1;
		}
	    cout << " ( "<< v_[i].n_voti << " )" << endl;
		
    }
    
    cout << "La media di tutti i voti della classe e': ";
    
    if (n_con_voti==0) 
		cout << "N/A";
    else 
		cout << media_classe/n_con_voti;
    
    cout << endl;
	
}
    

void visualizza_studente(Studenti v_,int riemp_){

	int c_max = max(C_MAX,N_MAX);	
	char criterio[c_max];
	cout << endl << "Nome o cognome da cercare: ";
	cin.ignore();
	cin.get(criterio, c_max);

	cout << endl;
    for (int i=0; i<riemp_; i++){
		
		if ( strcmp( v_[i].nome, criterio)==0 or strcmp(v_[i].cognome,criterio)==0){

			cout << v_[i].cognome << " " << v_[i].nome << endl;
			
			if (v_[i].n_voti == 0)
				cout << "Nessun voto"<<endl;
			else
				for (int j =0; j<v_[i].n_voti;j++)
					cout << j+1 << "- Voto:" << v_[i].voto[j] << " - Data: "<< ctime(&v_[i].data[j]);			

			cout << endl;
		} 
	
	}
	
}

void interroga_studente(Studenti v_,int riemp_){
	int s;
	
	visualizza_studenti(v_,riemp_);
	
	cout << "Che studente vuoi interrogare? ";
    cin >>s;
    
    while (s<1 || s>riemp_)
    {
        cout << "Valore non valido. Riprovare!"<<endl;
		cout << "Che studente vuoi interrogare? ";
        cin >> s;
    }
    
    inserisci_voto(v_, s-1);
}

void interroga_studente_casuale(Studenti v_,int riemp_){
	int irand = rand()%(riemp_);
    inserisci_voto(v_, irand); 
}

void inserisci_voto(Studenti v_,int s){
    float voto;
    cout << endl << "Interroga: " << v_[s].cognome << " "<< v_[s].nome << endl << endl;

	do{
		cout<< "Voto: ";
	    cin >> voto; 
		cout << endl;
	}while( voto<1 || voto>10);

	v_[s].voto[ v_[s].n_voti ] = voto;
	v_[s].data[ v_[s].n_voti ] = time(NULL);
	v_[s].n_voti++;

	return;   
}


void scambia(Studenti v_, int i,int j){
	Studente temp = v_[i];
	v_[i] = v_[j];
	v_[j] = temp;
}


void ordina_studenti(Studenti v_,int riemp_){

    int i_m;
    int confronto_cognome;
    for (int i=0; i<riemp_-1; i++)
    {
        i_m=i;
        for (int j=i+1; j<riemp_; j++)
        {	
        	confronto_cognome = strcmp(v_[i_m].cognome, v_[j].cognome);
            if ( (confronto_cognome>0) || (confronto_cognome ==0 and strcmp(v_[i_m].nome, v_[j].nome)>0) ) 
                i_m=j;
        }
        scambia(v_,i_m, i);
     }
}




