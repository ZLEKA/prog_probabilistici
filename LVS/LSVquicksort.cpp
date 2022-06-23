#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>
typedef long long int intero;
const long int rep=1000;
const intero X=1000;

using namespace std;
//trovo il pivot in modo randomico
 long int getpivot( intero inizio,intero fine){
	return rand()%(fine-inizio)+inizio;//mi genero un numero casuale compreso tra inizio e fine
} 
void scambia(intero *V, intero pivot,intero scambio){
	intero aux;//supporto
	aux=V[pivot];//salvo il valore del pivot in aux
	V[pivot]=V[scambio];//scambio il pivot
	V[scambio]=V[pivot+1];//metto il valore di pivot+1 in scambio
	V[pivot+1]=aux;//metto il pivot in pivot+1
		
}


//riordino il vettore
void partition(intero *V, intero inizio,intero fine,intero &pivot){
	intero aux=V[pivot];//
	V[pivot]=V[inizio];//
	V[inizio]=aux;//inizializzo il pivot a inizio
	pivot=inizio;//
	//cout<<" patition "<<fine-inizio<<endl;
	for(int i=inizio+1;i<=fine;i++){//inizio a confrontare da inizio+1
		
		if(V[pivot]>V[i]){
			
			scambia(V,pivot,i);//check
			pivot++;	
		}
		
	}
}
//chiamo quicksort
intero quicksort(intero *V, intero inizio,intero fine){
 	intero pivot;
	intero count=0;
	if(inizio<fine){//controllo che non si rimasto 1 solo elemeto
		
		pivot=getpivot(inizio,fine);//recupero la posizione del pivot
		partition(V,inizio,fine,pivot);//riordino il vettore in base al pivot	
		
		count+=fine-inizio;
		
		//cout<<"sinistra\n";
		count+=quicksort(V,inizio,pivot-1);//ricorsione sulla parte di inizio, pivot-1	
		//cout<<"destra\n";
		count+=quicksort(V,pivot+1,fine);//ricorsione sulla parte di pivot+1, fine
		
	}
	//cout<<count<<endl;
	//cout<<"esco\n";
	return count;
}


int main(){
	intero *N=new intero [X];// dichiaro il mio vettore N
	intero *countrep=new intero [rep];//dichiaro il mio vettore dei risultati
	unsigned long long int count;//variabile che conta i confronti
	srand(time(NULL));
	
	for(intero j=0;j<rep;j++){//ciclo delle ripetizioni
		count=0;//metto count a 0 per ogni volta che chiamo il quicksort
		//cout<<"disordinato \n";
		for(intero i=0; i<X ;i++) {
			N[i]=rand()%X;//mi riampo il vettore con numeri casuali
			
			//cout<<N[i]<<endl;
		}
		countrep[j]=quicksort(N,0,X);//riordino il vettore e ritorno il numero di confronti
		cout<<countrep[j]<<endl;
		//cout<<"riodinato\n";
		//for(int i=0;i<X;i++)cout<<N[i];
	}	
	/* media empirica
	intero media_empirica=0;
	for(intero i=0;i<3000;i++) media_empirica+=countrep[i];//sommo tutti confronti fatti
	media_empirica=media_empirica/rep;//divido la somma con il numero di rep
	cout<<"media empirica "<<media_empirica<<endl;
	*/
	//media pesata
	unsigned long long int media_pesata=0;
	for(intero i=0;i<rep;i++){
		media_pesata+=countrep[i];//sommo tutti gli scambi
	}
    media_pesata=media_pesata/rep;//trovo la media pesata
	cout<<"media pesata = "<<media_pesata<<endl;
	cout<<endl;
	//for(int i=0;i<rep;i++) cout<<countrep[i]<<endl;
	//count=quicksort(countrep,0,rep,count);//mi riordino il vettore dei risultati
	
	//for(int i=0;i<rep;i++) cout<<countrep[i]<<endl;
	
	//creo il txt-------------------------------------------------------------------------
	cout<<"creo il file txt\n";
	ofstream src("/home/carre/Scrivania/APA/dati.txt");//creo o riscivo un file di testo di nome dati.txt
	
	count=1;//riutilizzo count nel ciclo di scrittura
	for(int i=0;i<rep;i++){//ciclo per la scrittura
		if(countrep[i]!=countrep[i-1]){
			src<<countrep[i]<<"\t"<<count<<"\n";//equivalente a cout ma sul txt
			count=1;	
		}else count++;
		
	}
	src.close();
return 0;
}
