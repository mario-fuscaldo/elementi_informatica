//Calcolo dell'integrale definito
#include<iostream>
using namespace std;

int main()
{
	float x,xmin,xmax,integrale;
	float delta=0.01;
	
	cout<<"Inserisci estremo sinistro: ";
	cin>>xmin;
	cout<<"Inserisci estremo destro: ";
	cin>>xmax;

	x=xmin+delta/2;
	integrale=0;
	
	while(x<xmax)
	{
		integrale += delta*(2*x*x+4*x-1);
		x+=delta;


	}
	
	
	cout<<"Integrale = "<<integrale;
	
	cout<<endl<<endl;
	system("pause");
}
