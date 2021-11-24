/* Massimo tra 2 numeri interi */
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
	if(a>b)
	{
		max=a;
	}
	else
	{
		max=b;
	}
	cout<<"Il massimo e': "<<max;
	
	cout<<endl<<endl;
	system("pause");
}
