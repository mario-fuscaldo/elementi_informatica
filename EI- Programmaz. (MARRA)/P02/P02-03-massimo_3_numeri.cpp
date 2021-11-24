/* Massimo tra 3 numeri interi */
#include<iostream>
using namespace std;

int main()
{
	int a,b,c;
	
	cout<<"Questo programma permette di calcolare il massimo tra 3 numeri interi.\n\n";
	cout<<"Inserisci il primo numero: ";
	cin>>a;
	cout<<"Inserisci il secondo numero: ";
	cin>>b;
	cout<<"Inserisci il terzo numero: ";
	cin>>c;
	if(a>b)
	{
		if(a>c)
		{
			cout<<"Il massimo e' "<<a;
		}
		else
		{
			cout<<"Il massimo e' "<<c;
		}
	}
	else
	{
		if(b>c)
		{
			cout<<"Il massimo e' "<<b;
		}
		else
		{
			cout<<"Il massimo e' "<<c;
		}
	}
	
	cout<<endl<<endl;
	system("pause");
}
