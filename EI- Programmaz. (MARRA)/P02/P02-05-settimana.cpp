/* Queto programma scrive il giorno della settimana corrispondente ad un numero intero */
#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"Inserisci un numero intero tra 1 e 7: ";
	cin>>n;
	if(n==1)
		cout<<"Giorno corrispondente: Lunedi'";
	else if(n==2)
		cout<<"Giorno corrispondente: Martedi'";
	else if(n==3)
		cout<<"Giorno corrispondente: Mercoledi'";
	else if(n==4)
		cout<<"Giorno corrispondente: Giovedi'";
	else if(n==5)
		cout<<"Giorno corrispondente: Venerdi'";
	else if(n==6)
		cout<<"Giorno corrispondente: Sabato";
	else if(n==7)
		cout<<"Giorno corrispondente: Domenica";
	else
		cout<<"Il numero inserito non e' compreso tra 1 e 7";
	
	cout<<endl<<endl;
	system("pause");
}
