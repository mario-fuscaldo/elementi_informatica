/* Conversione da lettera minuscola a maiuscola e viceversa */

#include<iostream>
using namespace std;

int main()
{
	char c;
	
	cout<<"Questo programma permette di trasformare una lettera maiuscola in minuscola e viceversa.\n";
	cout<<"Inserisci carattere: ";
	cin>>c;
	if(c>=65 && c<=90)
	{
		c+=32;
		cout<<"Carattere trasformato: "<<c;
	}
	else if(c>=97&&c<=122)
	{
		c-=32;
		cout<<"Carattere trasformato: "<<c;
	}
	else
		cout<<"Il carattere inserito non e' una lettera.";
		
	cout<<endl<<endl;
	system("pause");
}
