//Questo programma controlla la presenza di un elemento in un vettore
#include<iostream>
using namespace std;

void inserisci_vettore(int Nmax,int &riemp_,int v_[]);
int cerca_elemento(int v_[],int riemp_);

int main()
{
	const int Nmax=100;
	int v[Nmax];
	int riemp=0;
	
	cout<<"Questo programma controlla la presenza di un elemento in un vettore.\n";
	inserisci_vettore(Nmax,riemp,v);
	cerca_elemento(v,riemp);
	
	cout<<endl<<endl;
	system("pause");
}

void inserisci_vettore(int Nmax_,int &riemp_,int v_[])
{
	char yn;

	do
	{
		cout<<"Inserisci elemento: ";
		cin>>v_[riemp_];
		riemp_++;
		cout<<"Ci sono altri elementi? (y/n): ";
		cin>>yn;
	}while(yn=='y'&&riemp_<Nmax_);

}

int cerca_elemento(int v_[],int riemp_)
{
	int cercato;
	bool trovato=false;
	int i;
	
	cout<<"Inserisci elemento da cercare: ";
	cin>>cercato;

	for(i=0;i<riemp_ && !trovato;i++)
	{
		if(v_[i]==cercato)
		{
			cout<<"L'elemento cercato si trova in posizione "<<i+1;
			trovato=true;
		}
	}

	if(!trovato){
		cout<<"Elemento non presente.";
		i = -1;
	}
		
	return i;
}

