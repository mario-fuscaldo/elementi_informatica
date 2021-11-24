//Questo programma calcola il quadrato di un numero
#include<iostream>
using namespace std;

float quadrato(float x_)
{
	float y_;

	y_=x_*x_;
	return y_;
}

int quadrato_in_place(float &x_)
{
	int positivo = 1;
	
	if x < 0 
		positivo = -1;
	
	x_ = x_ * x_;
	return positivo;
}



int main()
{
	float x,y;
	
	cout<<"Questo programma calcola il quadrato di un numero.\n";
	cout<<"Inserisci numero reale: ";
	cin>>x;
	y=quadrato(x);
	cout<<"Il quadrato e': "<<y;
	
	cout<<endl<<endl;
	system("pause");	
}



