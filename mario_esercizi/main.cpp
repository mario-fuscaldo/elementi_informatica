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

#define N_MAGISTRALI 2
#define N_TRIENNALI 3

using namespace std;
//struct
typedef struct{
char nome [20];
int matricola;
bool magistrale;
}studente;	

//def funzioni
void inserimento(studente[], int, bool);
void stampa(studente[], int);
 
//main
int main(int argc, char** argv) {

    //creazione vettori
    studente magistrale[N_MAGISTRALI];	
    studente triennale[N_TRIENNALI];	
        
    /*  nel main faccio una variabile booleana per capire in 
    *   quale vettore inserire lo studente
    *   siccome la chiedo all inizio la do come ingresso alla funzione di 
    *   inserimento così da non doverlo richiedere all'utente
    */
    bool magist;
    /*  metto una variabile exit come uscita per un ciclo while
    *   che comprende tutte le chiamate di funzioni
    *   così che posso continuare a inserire studenti
    */
    bool exit=true;

    while(exit){
        //controllo se lo studente è magistrale
        cout<<"inserisci uno studente"<<endl;
        cout<<"e' uno studente magistrale?"<<endl<<"1->si"<<endl<<"0->no"<<endl;
        cin>>magist;

        //lo inserisco nel vettore giusto
        if(magist){
            inserimento(magistrale, N_MAGISTRALI, magist);
        }else{
            inserimento(triennale, N_TRIENNALI, magist);
        }

        //controllo se uscire dal while
        cout<<"continuare?"<<endl;
        cout<<endl<<"1->si"<<endl<<"0->no"<<endl;
        cin>>exit;
    }

    //stampo i vettori
    stampa(magistrale,N_MAGISTRALI);
    stampa(triennale,N_TRIENNALI);
    system("pause");
}
 
 void inserimento(studente s[], int n, bool m){
     for(int i =0; i<n;i++){
         cout<<"nome dello studente?"<<endl;
         char str [20];
         cin>>str;
         strcpy(s[i].nome, str);
         cout<<"matricola studente?"<<endl;
         cin>>s[i].matricola;
         s[i].magistrale=m;

     }
 }

 void stampa(studente s[], int n){
     for(int i =0; i<n;i++){
         cout<<"nome dello studente: "<<s[i].nome<<endl;
 
         cout<<"matricola studente; "<<s[i].matricola<<endl;

        if(s[i].magistrale){
            cout<<"lo studente appartiene alla magistrale"<<endl;
        }else{
            cout<<"lo studente appartiene alla triennale"<<endl;
        }

     }
 }
