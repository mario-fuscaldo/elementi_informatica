//Calcolo dell'integrale definito
#include<iostream>
using namespace std;

int main()
{
	const int nmax=10;
	float x,xmin,xmax,potenza,funzione,integrale;
	int n;
	float coefficienti[nmax];
	float delta=0.01;
	
	cout<<"Questo programma consente di calcolare l'integrale definito di una funzione polinomiale di grado n<="<<nmax<<endl;
	cout<<"Inserisci grado del polinomio: ";
	cin>>n;
	
	for(int i=n;i>=0;i--)
	{
		cout<<"Inserisci coefficiente di grado "<<i<<": ";
		cin>>coefficienti[i];
	}
	
	cout<<"Inserisci estremo sinistro: ";
	cin>>xmin;
	cout<<"Inserisci estremo destro: ";
	cin>>xmax;
	
	x=xmin+delta/2;
	integrale=0;
	while(x<xmax)
	{
		
		funzione=0;
		for(int i=n;i>=0;i--)
		{
			potenza=1;
			//Calcolo potenza x^i. Si poteva fare in altro modo?
			for(int j=1;j<=i;j++)
				potenza*=x;

			funzione += coefficienti[i]*potenza;
		}
		
		integrale+=delta*funzione;
		x+=delta;
	}

	cout<<"Integrale = "<<integrale;
	
	cout<<endl<<endl;
	system("pause");
}
