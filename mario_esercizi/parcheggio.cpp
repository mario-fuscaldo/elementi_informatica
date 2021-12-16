#include <iostream>
#include <cstring>

 using namespace std;
//-------------------CONSTANTI------------------------
 const int N=4;
 const int M=10;

 const float Prezzo_orario=1.5;  //optionale

//------------------STRUCTS--------------------------
 typedef struct {
	char targa [20];
	char modello [30];
	char colore [20];
 }Autovettura;

 typedef struct {
	int ora;
	int min;
 }Orario;

 typedef struct {
	Autovettura autov;
	Orario orario;
 }Posto;
 	
 typedef struct {
 	Posto vposto [M];
 	int occupato [M];
}Piano;

 typedef Piano Parcheggio [N]; 

//------------------PROTOTIPI---------------------------
 void crea_parcheggio (Parcheggio&);

 void stampa_posti_liberi(Parcheggio&);
 
void stampa_posti_occupati(Parcheggio&);

void entrata_vettura(Parcheggio&);

void uscita_vettura(Parcheggio&);

bool check_orario(Orario , Orario );

int calcolo_sosta(Orario , Orario);

//-------------------MAIN----------------------------ì
 int main(int argc, char** argv) {
	Parcheggio park;
	double Incasso; 
	
	char quit_condition;
	crea_parcheggio(park);  
	
	while (quit_condition != 'E' && quit_condition != 'e') {
		
	cout<<"Seleziona una operazione da effettuare: "<<endl;
	cout<<"1- Stampa posti liberi"<<endl;
	cout<<"2- Stampa posti occupati"<<endl;
	cout<<"3- Entrata vettura"<<endl;
	cout<<"4- Uscita vettura"<<endl;
	cout<<"5- Visualizza incasso"<<endl;
		//TBD
	cout<<"E- esci"<<endl;
	cin>>quit_condition;
	
		switch (quit_condition) {

			case '1': 
			stampa_posti_liberi(park);
			break;

			case '2':
			stampa_posti_occupati(park);
			break;

			case '3':
			entrata_vettura(park);
			break;

			case '4':
			uscita_vettura(park);

			case 'e':
			break;

			case 'E':
			break;

			default:
				cout<<"riprova"<<endl;
			break;
		}
	}
	return 0;
}

//------------------------FUNZIONI-----------------------------
  void crea_parcheggio (Parcheggio &park_della_funzione){
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++){
				park_della_funzione[i].occupato[j]=0;
		}
			}
		cout<<" Ho creato il parcheggio "<<endl<<endl;
  		
  	}

  	void stampa_posti_liberi(Parcheggio &park_della_funzione){
		for (int i=0; i<N; i++) {		//per ogni piano
			int k=0;	
			for (int j=0; j<M; j++){	//cicla occupatov e vedi se è libero o occupato
				if(park_della_funzione[i].occupato[j]==0){
					k++;
				}
			}
			cout<<"PIANO "<<i<<": "<<k<<" POSTI LIBERI"<<endl;
		}
  	}
  
  	void stampa_posti_occupati(Parcheggio &park_della_funzione){
		for (int i=0; i<N; i++) {	//per ogni piano	
			int k=0;	
			for (int j=0; j<M; j++){	//cicla occupatov e vedi se è libero o occupato
				if(park_della_funzione[i].occupato[j]==1){
					cout<<"PIANO "<<i<<"; POSTO "<<j<<" OCCUPATO DA "<<	park_della_funzione[i].vposto[j].autov.targa<<" "<<
																		park_della_funzione[i].vposto[j].autov.modello<<" "<<
																		park_della_funzione[i].vposto[j].autov.colore<<endl;	
					k++;
				}
			}

			if(k==0){
				cout<<"PIANO "<<i<<" nessuna macchina"<<endl;
			}
		}
    }

  	void entrata_vettura(Parcheggio &p){
	   	//controllo se il parcheggio è pieno
		int k=0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++){
				if(p[i].occupato[j]!=0){
					k++;
				}
			}
		}	
		if(k==N*M){
			cout<<"IL PARCHEGGIO E' PIENO, VEDI CHE DEVI FARE"<<endl<<endl;
			return;
		}

		//metto la macchina nel posto particolare (opzionale)

		int posti_liberi=0;
		int max=0;
		int ppl; //piano più libero
			for (int i=0; i<N; i++) {
				for (int j=0; j<M; j++){
					if(p[i].occupato[j]==0){
						posti_liberi++;
					}
				}

				if(posti_liberi>max){ //se sono uguali dovrebbe non incrementare e restare nel piano più basso
						max=posti_liberi;
						ppl=i;
					}
				posti_liberi=0;
			}

		int pl=0;	
			//posto libero
		while(p[ppl].occupato[pl]!=0){
			pl++;
		}
		/*
		for (int j=0; j<M; j++){
			if(p[ppl].occupato[j]==0){
				pl=j;
			}
		}*/
		
		cout<<"inserisci targa"<<endl;
			cin.ignore();
			cin.getline(p[ppl].vposto[pl].autov.targa,20);

		cout<<"inserisci modello"<<endl;
			cin.ignore();
			cin.getline(p[ppl].vposto[pl].autov.modello,30);

		cout<<"inserisci colore"<<endl;
			cin.ignore();
			cin.getline(p[ppl].vposto[pl].autov.colore,20);

		//aggiunto da me
		cout<<"inserisci orario di arrivo"<<endl;
			cout<<"ora"<<endl;
			cin>>(p[ppl].vposto[pl].orario.ora);
			cout<<"minuti"<<endl;
			cin>>(p[ppl].vposto[pl].orario.min);

		p[ppl].occupato[pl]=1;
		cout<<"posto occupato"<<endl<<endl;



	}

	void uscita_vettura(Parcheggio &p){
		char t [20];
		Orario temp;
		bool a;
		char b;

		cout<<"targa della macchina che sta uscendo?"<<endl;
		cin.ignore();
		cin.getline(t,20);

		bool trovato=false;
		for (int i=0; i<N; i++) {		//per ogni piano	
			for (int j=0; j<M; j++){	//cicla occupatov e vedi se è libero o occupato
				if(strcmp(t,p[i].vposto[j].autov.targa)==0){
					trovato=true;
					cout<<"la macchina è al posto "<<j<<" del piano "<<i<<endl;
					do{
						cout<<"inserisci orario di uscita"<<endl;
						cout<<"ora"<<endl;
						cin>>temp.ora;
						cout<<"minuti"<<endl;
						cin>>temp.min;
						if( !(a=check_orario(p[i].vposto[j].orario,temp) ) ){ //esegue l'assegnazione dentro l'if
							cout<<"orario di uscita minore di ingresso"<<endl;
						}
					}while(!a);

					cout<<"elimina macchina? y/n"<<endl;
					cin>>b;

					switch (b){
						case 'y':
						p[i].occupato[j]=0;
						cout<<"macchina eliminata dal parcheggio"<<endl;
						cout<<"prezzo da pagare :"<<Prezzo_orario*calcolo_sosta(p[i].vposto[j].orario,temp)<<endl<<endl;

						case 'n':
						return;

						default:
						cout<<"tasto sbagliato ritorno al main"<<endl<<endl;
						return;
					}

				}//if
				
			}//ciclo posti
		}//ciclo piani
		if(!trovato)
			cout<<"LA MACCHINA NON E' NEL PARCHEGGIO"<<endl<<"vuoi riprovare? y/n"<<endl;
			char riprova;
			cin>>riprova;
			switch (riprova){
				case 'y':
				uscita_vettura(p);
				break;
				case 'n':
				return;
				default:
				cout<<"tasto sbaliato ritorno al main"<<endl<<endl;
				return;
			}
	}//funzione


	bool check_orario(Orario in, Orario out){

		if(in.ora<out.ora || in.min<in.min){
			return true;
		}else{
			return false;
		}
	}


	int calcolo_sosta(Orario in, Orario out){
		int a, b;
		
		a = 60*in.ora + in.min;
		b = 60*out.ora + out.min;

		return (b-a)/60;

	}
