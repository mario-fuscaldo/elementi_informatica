// M: Questo programma calcola l'integrale definito di una funzione polinomiale
/* Librerie necessarie: iostream 
Versione 3.0
Data 13-12-2019 */

#include<iostream>
using namespace std;

int richiesta_grado();
void richiesta_coefficienti(int n_,float v_[]);
void richiesta_estremi(float &xinf_,float &xsup_);
void calcolo_integrale(int n_,float v_[],float deltax_,float xinf_,float xsup_,float &integrale_);
//float calcolo_integrale(int n_,float v_[],float deltax_,float xinf_,float xsup_);
float f(float x_,int n_,float v_[]);
float potenza(float x_,int e_);
float potenzaRicorsiva(float x_,int e_);

int main()
{
	//M: Dichiarazione variabili
	const int nmax=100;
	int n;
	float v[nmax];
	float xinf,xsup,integrale;
	const float deltax=0.001;
	
	//M:Richiesta input all'utente
	//M:	Richiesta grado del polinomio
	n=richiesta_grado();
	//A: n>=0
	
	//M:	Richiesta coefficienti
	richiesta_coefficienti(n,v);

	//M:	Richiesta estremi
	richiesta_estremi(xinf,xsup);
	//A: xinf<xsup
	
	//M: Calcolo dell'integrale
	calcolo_integrale(n,v,deltax,xinf,xsup,integrale);
	
	//M: Scrittura del risultato
	cout<<"L'integrale e' "<<integrale;
}

int richiesta_grado()
{
	
	int enne;
	cout<<"Inserisci grado del polinomio: ";
	cin>>enne;
	
	return enne;
}

void richiesta_coefficienti(int n_,float v_[])
{
	for(int i=0;i<n_+1;i++)
	{
		cout<<"Inserisci coefficiente di grado "<<i<<": ";
		cin>>v_[i];
	}
}

void richiesta_estremi(float &xinf_,float &xsup_)
{
	cout<<"Inserisci estremo inferiore: ";
	cin>>xinf_;
	cout<<"Inserisci estremo superiore: ";
	cin>>xsup_;
}



void calcolo_integrale(int n_,float v_[],float deltax_,float xinf_,float xsup_,float &integrale_)
{
	float x,area;
	x=xinf_+deltax_/2;
	integrale_=0;

	//M: Somma aree rettangoli
	while(x<xsup_)
	{
		//M: Calcolo area rettangolo
		//M: Sommo valore all'integrale
		integrale += deltax_ * f(x,n_,v_);
		//M: Aggiorno x
		x+=deltax_;
	}
}

float f(float x_,int n_,float v_[])
{
	float polinomio=0;
	
	for(int i=0;i<n_+1;i++)
	{
		polinomio+=v_[i]* potenzaRicorsiva(x_,i);
	}
	return polinomio;
}

float potenza(float x_,int e_)
{
	float exp=1;
	
	for(int i=1;i<e_+1;i++)
	{	
		exp*=x_;
		//cout<<exp;
	}
	return exp;
}

float potenzaRicorsiva(float x_,int e_)
{
	if(e_==0)
		return 1;
	else
		return x_* potenzaRicorsiva(x_,e_-1);
}
