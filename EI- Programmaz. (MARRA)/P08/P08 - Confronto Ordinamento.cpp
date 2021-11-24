/* 	M: Confronto in termini di numero di confronti e numero di scambi per gli algoritmi di ordinamento studiati
 	AUTORE: Francesco Marra
	VERSIONE: v1.0
	ULTIMA MODIFICA: 16/12/2020
*/
#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;
typedef float tipo_v;

#define M_MAX 1000
#define N_MIN 20
#define N_MAX 1000

int inserisci_numero(int min,int max);
float genera_reale(float Rmin,float Rmax);
int genera_intero(int Nmin,int Nmax);

void genera_vettore_interi(int N,int v[],int Nmin, int Nmax);
void genera_vettore_reali(int N,float v[],float Rmin,float Rmax);

void visualizza_vettore(tipo_v v[],int n);
void copia_vettore(tipo_v v2[],const tipo_v v[],int n);

float somma_risultato_normalizzato(int v[],int norm[],int n);
int somma_risultato(int v,int n);
void visualizza_risultato(int confronti[],int scambi[],int v_n[],int m);

/*Le funzioni di ricerca restituiscono due interi aggiuntivi che contano il numero di confronti 
e il numero di scambi avvenuti per ordinare il vettore */
void selection_sort_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi);
void bubble_sort_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi);
void bubble_sort_modificato_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi);

int main(){
	srand((unsigned int) time(NULL));
	
	tipo_v v[M_MAX], v2[M_MAX];
	int c_ss[M_MAX],s_ss[M_MAX]; // confronti e scambi per il Selection Sort
	int c_bs[M_MAX],s_bs[M_MAX]; // confronti e scambi per il Bubble Sort
	int c_bsm[M_MAX],s_bsm[M_MAX]; // confronti e scambi per il Bubble Sort Modificato
	int v_n[M_MAX]; //vettore delle cardinalità dei vettori 
	const float Rmin = -2, Rmax = 3;
	
	int n,m,x,scelta,pos;
	
	cout << "Numero di vettori da generare:"<<endl;
	m = inserisci_numero(1,M_MAX);

	for(int i = 0;i<m;i++){

		v_n[i] = genera_intero(N_MIN,N_MAX);
		genera_vettore_reali(v_n[i],v,Rmin,Rmax);
		
		// NB se passassi il vettore v a tutte e tre le funzioni, sarebbe ordinato la prima volta e le successive prove non avrebbero senso
		// utilizziamo il vettore di appoggio v2, come copia di v, in modo tale da avere un confronto corretto 
		copia_vettore(v2,v,v_n[i]);
		selection_sort_con_conteggio(v2,v_n[i],c_ss[i],s_ss[i]);
			
		copia_vettore(v2,v,v_n[i]);
		bubble_sort_con_conteggio(v2,v_n[i],c_bs[i],s_bs[i]);
		
		copia_vettore(v2,v,v_n[i]);
		bubble_sort_modificato_con_conteggio(v2,v_n[i],c_bsm[i],s_bsm[i]);
	}
	
	//Visualizziamo i risultati:
	cout << "Selection sort:" <<endl;	
	visualizza_risultato(c_ss,s_ss,v_n,m);
	cout << endl;
	cout << "Bubble sort:" <<endl;
	visualizza_risultato(c_bs,s_bs,v_n,m);
	cout << endl;
	cout << "Bubbble sort modificato:" <<endl;	
	visualizza_risultato(c_bsm,s_bsm,v_n,m);
	cout << endl;

	cout << "Come vi dicevo il bubble sort e' un algoritmo didattico ma poco efficiente!";
	cout << endl << endl;
	system("pause");
}


void visualizza_risultato(int confronti[],int scambi[],int v_n[],int m){
	
	int num_c = 0, num_s = 0, N;
	float norm_c = 0,norm_s = 0;
	
	for(int i = 0;i<m;i++){
		num_c += confronti[i];
		num_s += scambi[i];
		norm_c += float( confronti[i] )/ float(v_n[i]);
		norm_s += float(scambi[i] )   / float( v_n[i]);
	}
	num_c /= m; //numero medio confronti
	num_s /= m; //numero medio scambi
	norm_c /= m; //numero medio confronti normalizzato
	norm_s /= m; //numero medio scambi normalizzato

	cout << "Numero medio confronti:              " << num_c <<endl;
	cout << "Numero medio scambi:                 " << num_s<<endl;
	cout << "Numero medio confronti normalizzato: " << norm_c<<endl;
	cout << "Numero medio scambi normalizzato:    " << norm_s<<endl;
	
}


int somma_risultato(int v[],int n){
	int somma=0;
	for(int i=0;i<n;i++)
		somma+=v[i];
	
	return somma;
}

float somma_risultato_normalizzato(int v[],int norm[],int n){
	float somma_norm=0;
	for(int i=0;i<n;i++)
		somma_norm+=v[i]/norm[i];
	
	return somma_norm;	
}


void copia_vettore(tipo_v v2[],const tipo_v v[],int n){
	for(int i = 0; i<n;i++)
		v2[i] = v[i];
}


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

void scambia(tipo_v v[],int i,int j){
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	
}

void selection_sort_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi){
	
	int min,i,j;
	num_confronti = 0;
	num_scambi = 0;
	
	for(i=0; i<n-1; i++){
		// si trova l'elemento più piccolo dell'array e si scambia con l'elemento alla posizione i
		min=i;   
		for (j=i+1;j<n;j++){
			if (v[j]<v[min])
				min=j;
			num_confronti++;						
		}	
		scambia(v,i,min);
		num_scambi++;
	}	
}

void bubble_sort_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi){
	bool scambio;
	int i;
	num_confronti = 0;
	num_scambi = 0;

	do {
		scambio = false;
		for(i=0;i<n-1;i++){
			if(v[i]>v[i+1])
			{
				scambia(v,i,i+1);
				num_scambi++;
				scambio = true;
			}
			num_confronti++;
		}
	} while (scambio);
		
}


void bubble_sort_modificato_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi){

	bool scambio;
	int i,ultimo_scambio = n, u;
	num_confronti = 0;
	num_scambi = 0;

	do {
		scambio = false;
		for(i=0; i<ultimo_scambio-1; i++){
			if(v[i]>v[i+1])
			{
				scambia(v,i,i+1);
				num_scambi++;
				scambio = true;
				u = i+1;
			}	
			num_confronti++;
		}
		ultimo_scambio = u;
			
	} while (scambio);
		
}

