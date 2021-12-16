//controllo valore in un vettore
#include<iostream>
using namespace std;

int main()
{
	const int Nmax=100;
	int v[Nmax];
	int N,x;
	bool contenuto;
	
	cout<<"Questo programma consente di verificare la presenza di un elemento in un vettore di numeri interi.\n";
	cout<<"Inserisci lunghezza del vettore: ";
	cin>>N;
	
	// Si pu� inserire il controllo sulla lunghezza del vettore
	
	for(int i=0;i<N;i++)
	{
		cout<<"Inserisci valore in posizione "<<i+1<<": ";
		cin>>v[i];
	}
	
	cout<<"Inserisci valore da verificare: ";
	cin>>x;
	
	contenuto=false;
	for(int i=0;i<N;i++) //Si pu� sostituire con un while per non scorrere tutto il vettore o modificare la condizione del for
		contenuto=contenuto||(x==v[i]);
	
	if(contenuto)
		cout<<"Il valore cercato e' contenuto nel vettore.";
	else
		cout<<"Il valore cercato non e' contenuto nel vettore.";
		
	cout<<endl<<endl;
	system("pause");
}
