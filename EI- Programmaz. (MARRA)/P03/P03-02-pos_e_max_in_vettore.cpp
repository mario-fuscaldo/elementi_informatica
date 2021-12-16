// Questo programma calcola il massimo e la sua posizione tra N numeri dove N � al massimo 100 e minimo 2
#include<iostream>
using namespace std;

int main()
{
	const int Nmax=100;
	float max;
	float v[Nmax];
	int N,imax;

	//Numero di elementi	
	do
	{
		cout<<"Inserisci il numero di elementi compreso tra 2 e "<<Nmax<<": ";
		cin>>N;
		if(N<2||N>100)
			cout<<"Il numero inserito non e' corretto.\n";
	}while(N<2||N>100);

	//Riempimento array	
	for(int i=0;i<N;i++)
	{
		cout<<"Inserisci valore: ";
		cin>>v[i];
	}
	
	//Visualizza elementi array
	cout<<"Il vettore inserito e':"<<endl<<"{";
	for(int i=0;i<N;i++)
	{
		if(i<N-1)
			cout<<v[i]<<",";
		else
			cout<<v[i];
	}
	cout<<"}"<<endl;
	
	//Ricerca del massimo e della sua posizione
	max=v[0];
	imax=1;
	for(int i=1;i<N;i++)
	{
		if(v[i]>max)
		{
			max=v[i];
			imax=i+1;//poteva anche essere i
		}
	}
	cout<<endl<<"Il massimo e' "<<max<<", che si trova in posizione "<<imax;
	
	cout<<endl<<endl;
	system("pause");
}
