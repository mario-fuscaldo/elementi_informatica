/* Queto programma scrive il giorno della settimana corrispondente ad un numero intero */
#include<iostream>
using namespace std;

typedef enum{
	lun=1,
	mar,
	mer,
	gio,
	ven,
	sab,
	dom
} giorni;

int main()
{
	int n;
	giorni giorno;
	
	cout<<"Inserisci un numero intero tra 1 e 7: ";
	cin >> n;

	giorno = (giorni) n;
	
	switch(giorno)
	{
		case lun:
			cout<<"Giorno corrispondente: Lunedi'";
			break;
		case mar:
			cout<<"Giorno corrispondente: Martedi'";
			break;
		case mer:
			cout<<"Giorno corrispondente: Mercoledi'";
			break;
		case gio:
			cout<<"Giorno corrispondente: Giovedi'";
			break;
		case ven:
			cout<<"Giorno corrispondente: Venerdi'";
			break;
		case sab:
			cout<<"Giorno corrispondente: Sabato";
			break;
		case dom:
			cout<<"Giorno corrispondente: Domenica";
			break;
		default:
			cout<<"Il numero inserito non e' compreso tra 1 e 7";
	}
	
	cout<<endl<<endl;
	system("pause");
}
