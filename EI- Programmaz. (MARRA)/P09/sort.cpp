#include "sort.h"



void scambia(tipo_v v[],int i,int j){
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	
}

void selection_sort(tipo_v v[],int n){
	
	int min,i,j;
	
	for(i=0; i<n-1; i++){
		// si trova l'elemento più piccolo dell'array e si scambia con l'elemento alla posizione i
		min=i;   
		for (j=i+1;j<n;j++){
			if (v[j]<v[min])
				min=j;
		}	
		scambia(v,i,min);
	}	
}

void bubble_sort(tipo_v v[],int n){
	bool scambio;
	int i;

	do {
		scambio = false;
		for(i=0;i<n-1;i++){
			if(v[i]>v[i+1])
			{
				scambia(v,i,i+1);
				scambio = true;
			}
		}
	} while (scambio);
		
}


void bubble_sort_modificato(tipo_v v[],int n){

	bool scambio;
	int i,ultimo_scambio = n, u;

	do {
		scambio = false;
		for(i=0; i<ultimo_scambio-1; i++){
			if(v[i]>v[i+1])
			{
				scambia(v,i,i+1);
				scambio = true;
				u = i+1;
			}	
		}
		ultimo_scambio = u;
			
	} while (scambio);
		
}


void selection_sort_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi){
	
	int min,i,j;
	num_confronti = 0;
	num_scambi = 0;
	
	for(i=0; i<n-1; i++){
		// si trova l'elemento più piccolo dell'array e si scambia con l'elemento alla posizione i
		min=i;   
		for (j=i+1;j<n;j++){
			if (v[j]<v[min])
				min=j;
			num_confronti++;						
		}	
		scambia(v,i,min);
		num_scambi++;
	}	
}

void bubble_sort_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi){
	bool scambio;
	int i;
	num_confronti = 0;
	num_scambi = 0;

	do {
		scambio = false;
		for(i=0;i<n-1;i++){
			if(v[i]>v[i+1])
			{
				scambia(v,i,i+1);
				num_scambi++;
				scambio = true;
			}
			num_confronti++;
		}
	} while (scambio);
		
}


void bubble_sort_modificato_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi){

	bool scambio;
	int i,ultimo_scambio = n, u;
	num_confronti = 0;
	num_scambi = 0;

	do {
		scambio = false;
		for(i=0; i<ultimo_scambio-1; i++){
			if(v[i]>v[i+1])
			{
				scambia(v,i,i+1);
				num_scambi++;
				scambio = true;
				u = i+1;
			}	
			num_confronti++;
		}
		ultimo_scambio = u;
			
	} while (scambio);
		
}
