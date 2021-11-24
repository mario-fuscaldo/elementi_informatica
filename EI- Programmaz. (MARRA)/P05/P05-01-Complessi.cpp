//Questo programma permette di effetture operazioni con i numeri complessi
#include<iostream>
using namespace std;

int main()
{
	struct Complessi
	{
		float partereale;
		float parteimmaginaria;
	};
	Complessi complesso1, complesso2, risultato;
	char operatore;
	
	cout<<"Inserisci la parte reale del primo numero complesso: ";
	cin>>complesso1.partereale;
	cout<<"Inserisci la parte immaginaria del primo numero complesso: ";
	cin>>complesso1.parteimmaginaria;
	cout<<"Inserisci la parte reale del secondo numero complesso: ";
	cin>>complesso2.partereale;
	cout<<"Inserisci la parte immaginaria del secondo numero complesso: ";
	cin>>complesso2.parteimmaginaria;
	cout<<"Inserisci operatore (+/-): ";
	cin>>operatore;
	switch(operatore)
	{
		case '+':
		{
			risultato.partereale=complesso1.partereale+complesso2.partereale;
			risultato.parteimmaginaria=complesso1.parteimmaginaria+complesso2.parteimmaginaria;
			break;
		}
		case '-':
		{
			risultato.partereale=complesso1.partereale-complesso2.partereale;
			risultato.parteimmaginaria=complesso1.parteimmaginaria-complesso2.parteimmaginaria;
			break;
		}
		default:
			cout<<"Il carattere inserito non e' valido.";
	}
	cout<<"Risultato: "<<risultato.partereale;
	if(risultato.parteimmaginaria>=0)
		cout<<" + ";
	else
		cout<<" ";
	cout<<risultato.parteimmaginaria<<"i";
	
	cout<<endl<<endl;
	system("pause");
}
