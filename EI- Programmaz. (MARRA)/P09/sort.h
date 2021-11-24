/* 	Algoritmi di ordinamento
 	AUTORE: Francesco Marra
	VERSIONE: v1.0
	ULTIMA MODIFICA: 16/12/2020
*/

typedef float tipo_v;

void selection_sort(tipo_v v[],int n);
void bubble_sort(tipo_v v[],int n);
void bubble_sort(tipo_v v[],int n);

/*Le funzioni di ricerca restituiscono due interi aggiuntivi che contano il numero di confronti 
e il numero di scambi avvenuti per ordinare il vettore */
void selection_sort_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi);
void bubble_sort_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi);
void bubble_sort_modificato_con_conteggio(tipo_v v[],int n,int &num_confronti,int &num_scambi);


