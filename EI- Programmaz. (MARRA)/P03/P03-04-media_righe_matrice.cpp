//Calcolo media per ogni riga di una matrice
#include<iostream>
using namespace std;

int main()
{
	const int Nmax=10;
	const int Mmax=10;
	typedef float Matrice[Nmax][Mmax];
	Matrice mat;
	int N,M;
	float medie[Nmax];
	
	cout<<"Inserisci numero di righe: ";
	cin>>N;
	cout<<"Inserisci numero di colonne: ";
	cin>>M;
	
	// Popola matrice
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			cout<<"Inserisci valore in posizione ("<<i+1<<","<<j+1<<"): ";
			cin>>mat[i][j];
		}
	
	//Calcola medie
	for(int i=0;i<N;i++)
	{
		medie[i]=0;
		for(int j=0;j<M;j++)
			medie[i]+=mat[i][j];
		medie[i]/=M;
	}
	
	//Visualizza risultato
	for(int i=0;i<N;i++)
		cout<<"Media riga "<<i+1<<": "<<medie[i]<<endl;
	
	cout<<endl<<endl;
	system("pause");
}
