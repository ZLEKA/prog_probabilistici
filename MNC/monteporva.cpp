#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>

using namespace std;
//strutture----------------------------------------------------------------------
struct Bridge{//struttura dell' arco
	struct Vertex *vertice;//puntatore a Vertex(nodo)
	Bridge *next;//puntatore al prossimo arco(ponte)
	int peso;
} ;
typedef struct Bridge *ponte;
struct Vertex{
	bool flag;//viene usato per il controllo 
	int num;//numero vertice 
	struct Bridge *arco;//puntatore a Bridge(ponte)
};
typedef struct Vertex *nodo;



//creo un nodo vuoto--------------------------------------------------------------
nodo newNodo(){
	nodo v=new Vertex;
	v->num=0;
	return v ;
}
//creo un ponte vuoto-------------------------------------------------------------
ponte newPonte(){
	ponte b= new Bridge;
	b->next=NULL;
	return b ;
}
//creo il grafo di frisch------------------------------------------------------------------------
void newGraph(nodo *G,int** V){
	//creo il grafo "a mano"
	ponte P1,P2,P3;//puntatore di supporto
	int j=0;//prende i ponti in V
	for(int i=0;i<9;i++){//cilo per i vertici
		P1=newPonte();//creo un nuovo ponte
		G[i]->arco=P1;//collego il vertice al ponte
		while(V[i][j]!=-1){//ciclo per i ponti
			P1->vertice=G[V[i][j]];//collego il ponte al nodo corrispettivo
			P1->peso=j+i;//metto il peso nell' arco
			P2=newPonte();//creo un nuovo ponte
			P1->next=P2;//collego il precendente ponte con quello appan creato
			P1=P1->next;//passo al ponte appena creato
			
			j++;
			
		}
		j=0;//azzero j per il prossimo nodo
	}
}

//stampa grafo----------------------------------------------------------------
void printG(nodo *G){
ponte aux;
	for(int i=0;i<9;i++){
	aux=G[i]->arco;
		cout<<"\nnodo numero "<<i<<endl;//controllo nodo
		do{
			cout<<aux->vertice->num<<"  ";//controllo collegamento ponte
			aux=aux->next;
		}while(aux->next!=NULL);
	}
}
// min-cut ---------------------------------------------------------------------
void mincut(nodo *G){
ponte aux;
int backup=0;
int j=0;

	for(int i=0;i<9;i++){//cilco per i vertici
		aux->next=G[i][j]->arco;//collego il aux al vertice
		do{
			if(aux->peso>backup)backup=aux->peso;
			
		}while(aux->next!=NULL);
		j++
	}
	
}






int main(){
nodo *G =new Vertex* [9];//dichiaro un array di vertici
int** V=new int*[9];
for(int i=0;i<9;i++) V[i]=new int[6];
	
	//inizializzo il vettore che contiene i collegamenti
	int v0[6]={1,2,3,4,7,-1};
	V[0]=v0;
	int v1[6]={0,2,5,7,8,-1};
	V[1]=v1;
	int v2[5]={0,1,3,5,-1};
	V[2]=v2;
	int v3[6]={0,2,4,5,6,-1};
	V[3]=v3;
	int v4[5]={0,3,6,7,-1};
	V[4]=v4;
	int v5[6]={1,2,3,6,8,-1};
	V[5]=v5;
	int v6[6]={3,4,5,7,8,-1};
	V[6]=v6;
	int v7[6]={0,1,4,6,8,-1};
	V[7]=v7;
	int v8[5]={1,5,6,7,-1};
	V[8]=v8;
	//metto -1 alla fine per capoire che non ho alri numeri
	
	cout<<"creo l'array\n";
	for(int i=0;i<9;i++) {//inizializzo i nodi nell'array
		G[i]=newNodo();
		G[i]->num=i;
		//cout<<G[i]->num<<endl;
	}
	cout<<"array creato\n";
	newGraph(G,V);
	cout<<"grafo creato\n";
	printG(G);
	
	
cout<<"prova\n";

}
