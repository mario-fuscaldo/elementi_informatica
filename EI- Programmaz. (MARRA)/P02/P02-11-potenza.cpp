//Calcolo della potenza
#include<iostream>
using namespace std;

int main()
{
	float r,potenza;
	int k;
	
	cout<<"Calcolo della potenza di un numero reale.\n";
	
	do
	{
		cout<<"Inserisci base (numero reale positivo): ";
		cin>>r;
		if(r<=0)
			cout<<"Inserimento errato.\n";
	}while(r<=0);
	
	cout<<"Inserisci esponente (numero intero positivo, nullo o negativo): ";
	cin>>k;
	
	if(k<0)
	{
		k=-k;
		r=1/r;
	}
	
	potenza=1;
	for(int i=0;i<k;i++)
		potenza*=r;

	cout<<"Potenza = "<<potenza;
	
	cout<<endl<<endl;
	system("pause");
}
