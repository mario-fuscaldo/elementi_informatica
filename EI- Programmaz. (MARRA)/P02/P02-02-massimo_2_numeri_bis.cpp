/* Massimo tra 2 numeri interi, variante */
#include<iostream>
using namespace std;

int main()
{
	int a,b,max;
	
	cout<<"Questo programma permette di calcolare il massimo tra 2 numeri interi.\n\n";
	cout<<"Inserisci il primo numero: ";
	cin>>a;
	cout<<"Inserisci il secondo numero: ";
	cin>>b;
	max=a;
	if(b>a)
	{
		max=b;
	}
	cout<<"Il massimo e': "<<max;
	
	cout<<endl<<endl;
	system("pause");
}
