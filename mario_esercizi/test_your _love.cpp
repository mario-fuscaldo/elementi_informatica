/*allora fai un programma che:

definsice 2 vettori di studenti

con studente struct che contiene :
stringa nome
int matricola
bool magistrale 

all avvio il programma fa inserire gli studenti da tastiera, se il campo magistrale è true (0) allora li inserisce nel vettore 2 altrimenti li inserisce nel vettore 1

(fate i vettori da 3 posizioni) 

l'inserimento dei dati (e la copia dello studente nel vettore giusto) sarà fatto da una funzione e la stampa da un altra

entrambe chiamate dal main

fai che ci sono 3 studenti triennali e 2 magistrali*/

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

//main
int main(int argc, char** argv) {

cout<<"TEST YOUR LOVE <3<3<3"<<endl;
bool k=true;

while(k){
    cout<<"inserisci il tuo nome"<<endl;
    char a[30];
    cin>>a;
    cout<<"inserisci il nome del tuo amato"<<endl;
    char b[30];
    cin>>b;

    if (strcmp(a, "sara")==0 && strcmp(b,"mario")==0){

        cout<<a<<" e "<<b<<" si amano al "<<"100 %"<<endl;
        cout<<"per continuare premi 1"<<endl;
        cout<<"per terminare premi 0"<<endl;
        cin>>k;
    }else{

        srand(time(NULL));
        cout<<a<<" e "<<b<<" si amano al "<<rand()%100+1<<" %"<<endl;
        cout<<"per continuare premi 1"<<endl;
        cout<<"per terminare premi 0"<<endl;
        cin>>k;
    }
}
}
