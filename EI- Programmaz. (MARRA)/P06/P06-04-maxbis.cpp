//Calcolo del massimo tra due numeri
#include<iostream>
using namespace std;

float max(float a_,float b_)
{
	float massimo_=a_;
	if(b_>massimo_)
		massimo_=b_;
	return massimo_;
}

int main()
{
	float a,b;
	
	cout<<"Calcolo del massimo tra due numeri.\n";
	cout<<"Inserisci primo numero: ";
	cin>>a;
	cout<<"Inserisci secondo numero: ";
	cin>>b;
	cout<<"Il massimo e': "<<max(a,b);
	
	cout<<endl<<endl;
	system("pause");
}
