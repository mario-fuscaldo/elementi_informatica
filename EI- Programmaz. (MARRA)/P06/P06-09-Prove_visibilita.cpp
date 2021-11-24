//Questo programma controlla la presenza di un elemento in un vettore
#include<iostream>
using namespace std;


int prova(int a,int &b){
	b++;
	return (a+1);
}

int main()
{
	int a = 7, b = 3,c;
		
	cout << "Prima Ciclo. a = " << a << endl;
	for (int i = 0; i <10;i++){
		int a = i+1;	
		cout << "Interno Ciclo. a = " << a << endl;
	}
		
	cout << endl << "Dopo ciclo" << endl;
	cout << "il valore di a:"<< a <<endl;

	//cout << "il valore di b:"<< b <<endl;
	
	/*
	c = prova(a,b);		

	cout << "il valore di a:"<< a <<endl;
	cout << "il valore di b:"<< b <<endl;
	cout << "il valore di c:"<< c <<endl;
*/
	cout<<endl<<endl;
	system("pause");
}

