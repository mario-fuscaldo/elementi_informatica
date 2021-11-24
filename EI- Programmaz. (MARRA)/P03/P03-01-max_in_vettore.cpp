// Questo programma calcola il massimo tra N numeri dove N è al massimo 100 e minimo 2
#include<iostream>
using namespace std;

int main()
{
	const int Nmax=100;
	float max;
	float v[Nmax];
	int N;
	
	//Numero di elementi	
	do
	{
		cout<<"Inserisci il numero di elementi compreso tra 2 e "<<Nmax<<": ";
		cin>>N;

		if(N<2||N>100)
			cout<<"Il numero inserito non e' corretto.\n";

	}while(N<2 || N>100);
	
	//Riempimento array
	for(int i=0; i<N; i++)
	{
		cout<<"Inserisci valore: ";
		cin>>v[i];
	}

	cout<<"Il vettore inserito e':"<<endl<<"{";	
	//Visualizza elementi array
	for(int i=0;i<N;i++)
	{
		if( i <N-1)
			cout<<v[i]<<",";
		else
			cout<<v[i];
	}
	cout<<"}"<<endl;

	//Ricerca del massimo
	max=v[0];

	for(int i=0;i<N;i++)
	{
		if(v[i]>max)
			max=v[i];
	}

	cout<<endl<<"Il massimo e': "<<max;
	
	cout<<endl<<endl;
	system("pause");
}
