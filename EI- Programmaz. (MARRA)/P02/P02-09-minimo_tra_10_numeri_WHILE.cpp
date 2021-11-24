/* Questo programma permette di calcolare il minimo tra 10 numeri */
#include<iostream>
using namespace std;

int main()
{
	const int n=10;
	float r,min;
	int i;
	
	cout<<"Inserisci un numero: ";
	cin>>r;
	min=r;
	i=2;
	while(i<=10)
	{
		cout<<"Inserisci un numero: ";
		cin>>r;
		if(r<min)
			min=r;
		i++;
	}
	cout<<"Il minimo e': "<<min;
	
	cout<<endl<<endl;
	system("pause");
	
}
