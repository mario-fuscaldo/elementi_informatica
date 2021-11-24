/* Queto programma scrive il giorno della settimana corrispondente ad un numero intero */
#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"Inserisci un numero intero tra 1 e 7: ";
	cin>>n;
	switch(n)
	{
		case 1:
			cout<<"Giorno corrispondente: Lunedi'";
			break;
		case 2:
			cout<<"Giorno corrispondente: Martedi'";
			break;
		case 3:
			cout<<"Giorno corrispondente: Mercoledi'";
			break;
		case 4:
			cout<<"Giorno corrispondente: Giovedi'";
			break;
		case 5:
			cout<<"Giorno corrispondente: Venerdi'";
			break;
		case 6:
			cout<<"Giorno corrispondente: Sabato";
			break;
		case 7:
			cout<<"Giorno corrispondente: Domenica";
			break;
		default:
			cout<<"Il numero inserito non e' compreso tra 1 e 7";
	}
	
	cout<<endl<<endl;
	system("pause");
}
