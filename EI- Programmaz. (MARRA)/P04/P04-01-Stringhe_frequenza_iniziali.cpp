//Questo programma calcola la frequenza delle iniziali di nomi inseriti
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	const int Nmax=20;
	char nome[Nmax];
	int freq[26]={0};
	int numero=0;
	char iniz;
	
	cout<<"Calcolo frequenza delle iniziali dei nomi di un elenco\n\n";
	do
	{

		cout<<"Inserisci nome, oppure '.' se l'elenco e' finito: ";
		cin>>nome;
		if(nome[0]>='a'&&nome[0]<='z')
		{
			nome[0]-=32;
			cout<<"Il nome inserito non comincia con la maiuscola, diventa: "<<nome<<endl;
		}
		freq[nome[0]-65]++;

	}while(strcmp(nome,".")!=0);
	
/*	for(int i=0;i<26;i++)
		cout<<freq[i]<<" ";*/
	numero = 0;
	for(int i=0;i<26;i++)
		numero+=freq[i];
	
	cout<<"\nNumero di elementi: "<<numero<<endl<<endl;

	cout<<"Frequenza delle iniziali dei nomi inseriti:\n";
	for(int i=0;i<26;i++)
	{
		iniz=i+65;
		if(freq[i]!=0)
			cout<<iniz<<": "<<freq[i]<<endl;
	}
	
	cout<<endl<<endl;
	system("pause");
}
