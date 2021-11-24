//Questo programma consente di verificare la presenza di una stringa tra le stringhe inserite in precedenza
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	const int Nmax=20;
	const int Mmax=100;
	typedef char Nome[Nmax];
	Nome nomi[Mmax];
	Nome cercato;

	int M;
	bool contenuto;
	
	cout<<"Questo programma consente di verificare la presenza di un nome tra quelli inseriti in precedenza.\n\n";
	M=-1;
	do
	{
		M++;
		cout<<"Inserisci nome, oppure '.' se l'elenco e' finito: ";
		cin>>nomi[M];
	}while(strcmp(nomi[M],".")!=0);

	cout<<"\nInserisci nome da cercare: ";
	cin>>cercato;

	contenuto=false;
	for(int i=0;(i<M) ;i++)
		contenuto=contenuto||( strcmp(cercato,nomi[i])==0);

	if(contenuto)
		cout<<"Il nome cercato e' contenuto nell'elenco.";
	else
		cout<<"Il nome cercato non e' contenuto nell'elenco.";
	
	cout<<endl<<endl;
	system("pause");
}
