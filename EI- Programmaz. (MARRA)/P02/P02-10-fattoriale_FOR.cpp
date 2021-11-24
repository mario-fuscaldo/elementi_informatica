// Questo programma trova il fattoriale di un numero
#include<iostream>
using namespace std;

int main()
{
	int n;
	double fattoriale;
	
	do
	{
		cout<<"Inserisci un numero intero non negativo: ";
		cin>>n;
		if(n<0)
			cout<<"Hai inserito un numero negativo.\n";
	}while(n<0);
	fattoriale=1;
	for(int i=1;i<=n;i++)
	{
		fattoriale*=i;
	}
	cout<<"Il fattoriale di "<<n<<" e' "<<fattoriale;
	
	cout<<endl<<endl;
	system("pause");
}
