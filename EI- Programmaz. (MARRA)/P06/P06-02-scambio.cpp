//Programma per scambiare 2 valori inseriti da tastiera
#include<iostream>
using namespace std;

void scambia(int &a_,int &b_)
{
	int temp;
	
	temp=a_;
	a_=b_;
	b_=temp;
	cout<<"Dentro la funzione:\n";
	cout<<"I due valori sono: "<<a_<<" e "<<b_<<endl;
}

int main()
{
	int a,b;
	
	cout<<"Questo programma consente di scambiare 2 valori inseriti da tastiera.\n";
	cout<<"Inserisci primo valore: ";
	cin>>a;
	cout<<"Inserisci secondo valore: ";
	cin>>b;
	cout<<"Prima dello scambio:\n";
	cout<<"I due valori sono: "<<a<<" e "<<b<<endl;
	scambia(a,b);
	cout<<"Dopo lo scambio:\n";
	cout<<"I due valori sono: "<<a<<" e "<<b;
		
	cout<<endl<<endl;
	system("pause");
}
