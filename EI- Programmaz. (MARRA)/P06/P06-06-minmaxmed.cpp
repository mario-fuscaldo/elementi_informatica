//Questo programma calcola il minimo, il massimo e la media di valori niseriti da tastiera
#include<iostream>
using namespace std;

void max(float v_[],int n_,float &massimo_)
{
	massimo_=v_[0];
	for(int i=1;i<n_;i++)
		if(v_[i]>massimo_)
			massimo_=v_[i];
}

void min(float v_[],int n_,float &minimo_)
{
	minimo_=v_[0];
	for(int i=1;i<n_;i++)
		if(v_[i]<minimo_)
			minimo_=v_[i];
}

void mean(float v_[],int n_,float &media_)
{
	media_=0;
	for(int i=0;i<n_;i++)
		media_+=v_[i];
	media_/=n_;
}

int main()
{
	const int Nmax=1000;
	float v[Nmax];
	int n=0;
	char yn;
	float massimo,minimo,media;
	
	do
	{
		cout<<"Inserire valore: ";
		cin>>v[n];
		n++;
		cout<<"Ci sono altri valori? (y/n): ";
		cin>>yn;
	}while(yn=='y'&&n<Nmax);
	max(v,n,massimo);
	min(v,n,minimo);
	mean(v,n,media);
	cout<<"Il massimo e': "<<massimo<<endl;
	cout<<"Il minimo e': "<<minimo<<endl;
	cout<<"La media e': "<<media<<endl;
	
	
	cout<<endl<<endl;
	system("pause");
}
