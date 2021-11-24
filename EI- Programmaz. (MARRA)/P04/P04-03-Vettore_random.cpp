//Calcolo media di un vettore generato casualmente
#include<iostream>
#include<cstdlib>
#include<ctime> //Serve per inizializzare il seed del rand
using namespace std;

int main()
{
	const int Nmax=10;
	const int Nmin=1;
	float v[Nmax];
	int random,N;
	const float Rmin=-1000;
	const float Rmax=1000;
	float R01,R,media;
	
	srand( (unsigned int) time(NULL) );
	
	cout<<"Rand max: "<<RAND_MAX<<endl;

	random=rand();	
	cout<<"Random: "<<random<<endl;
	
	N=random%(Nmax-Nmin+1)+Nmin;	
	cout<<"N: "<<N<<endl;

	for(int i=0;i<N;i++)
	{
		random=rand();

		R01=float(random)/RAND_MAX;
		R=R01*(Rmax-Rmin)+Rmin;

		v[i]=R;
	}
	cout<<"Vettore = {";
	for(int i=0;i<N-1;i++)
		cout<<v[i]<<", ";
	cout<<v[N-1]<<"}\n";
	//calcolo media

	media=0;
	for(int i=0;i<N;i++)
	{
		media+=v[i];
	}
	media/=N;

	cout<<"Media = "<<media;
	
	cout<<endl<<endl;
	system("pause");
}
