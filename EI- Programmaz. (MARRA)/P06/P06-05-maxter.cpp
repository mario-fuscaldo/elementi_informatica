//Calcolo del massimo tra due numeri
#include<iostream>
using namespace std;

void max(float a_,float b_,float &massimo_)
{
	massimo_=a_;
	if(b_>massimo_)
		massimo_=b_;
}

int main()
{
	float a,b,massimo;
	
	cout<<"Calcolo del massimo tra due numeri.\n";
	cout<<"Inserisci primo numero: ";
	cin>>a;
	cout<<"Inserisci secondo numero: ";
	cin>>b;
	max(a,b,massimo);
	cout<<"Il massimo e': "<<massimo;
	
	cout<<endl<<endl;
	system("pause");
}
