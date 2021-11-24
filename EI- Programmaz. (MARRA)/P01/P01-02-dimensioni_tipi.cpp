/*Questo programma visualizza le dimensioni dei tipi di variabili*/
#include<iostream>
using namespace std;

int main()
{
	cout<<"Dimensione di uno short int: "<<sizeof(short int)<<'B'<<endl;
	cout<<"Dimensione di un int: "<<sizeof(int)<<'B'<<endl;
	cout<<"Dimensione di un long int: "<<sizeof(long int)<<'B'<<endl;
	
	cout<<"Dimensione di un float: "<<sizeof(float)<<'B'<<endl;
	cout<<"Dimensione di un double: "<<sizeof(double)<<'B'<<endl;
	cout<<"Dimensione di un long double: "<<sizeof(long double)<<'B'<<endl;

	cout<<"Dimensione di un bool: "<<sizeof(bool)<<'B'<<endl;
	cout<<"Dimensione di un char: "<<sizeof(char)<<'B'<<endl;
	
	cout<<endl<<endl;
	system("pause");
}

