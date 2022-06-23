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
} ;
typedef struct Bridge *ponte;
struct Vertex{
	int num;//numero o posizione nell'array (torna utile)
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
void newGraph(nodo *G){
	//creo il grafo "a mano"
	ponte P1,P2,P3;//puntatore di supporto
	cout<<"sono in newGraph\n";
	//nodo 1-------------------
	P1=newPonte();
	G[0]->arco=P1;
	P1->vertice=G[1];
	cout<<"primo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[2];
		
	cout<<"secondo collegamento\n";
	P1=newPonte();
	P2->next=P1;
	P1->vertice=G[3];
	cout<<"terzo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[4];
	ponte aux;
	
	cout<<"quarto collegamento\n";
	P1=newPonte();
	P2->next=P1;
	P1->vertice=G[7];
	cout<<"quinto collegamento\n";
	//nodo 2-------------------------
	P1=newPonte();
	G[1]->arco=P1;
	P1->vertice=G[0];
	cout<<"primo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[2];
		
	cout<<"secondo collegamento\n";
	P1=newPonte();
	P2->next=P1;
	P1->vertice=G[5];
	cout<<"terzo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[7];
	ponte aux;
	
	cout<<"quarto collegamento\n";
	P1=newPonte();
	P2->next=P1;
	P1->vertice=G[8];
	cout<<"quinto collegamento\n";
	//nodo 3-------------------------------
	P1=newPonte();
	G[1]->arco=P1;
	P1->vertice=G[0];
	cout<<"primo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[1];
		
	cout<<"secondo collegamento\n";
	P1=newPonte();
	P2->next=P1;
	P1->vertice=G[3];
	cout<<"terzo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[5];
	ponte aux;
	cout<<"quarto collegamento\n";
	//nodo 4--------------------------
	P1=newPonte();
	G[3]->arco=P1;
	P1->vertice=G[0];
	cout<<"primo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[2];
		
	cout<<"secondo collegamento\n";
	P1=newPonte();
	P2->next=P1;
	P1->vertice=G[3];
	cout<<"terzo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[6];
	ponte aux;
	
	cout<<"quarto collegamento\n";
	P1=newPonte();
	P2->next=P1;
	P1->vertice=G[7];
	cout<<"quinto collegamento\n";

	//nodo 5 -------------------------
	P1=newPonte();
	G[0]->arco=P1;
	P1->vertice=G[2];
	cout<<"primo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[3];
		
	cout<<"secondo collegamento\n";
	P1=newPonte();
	P2->next=P1;
	P1->vertice=G[4];
	cout<<"terzo collegamento\n";
	
	P2=newPonte();
	P1->next=P2;
	P2->vertice=G[5];
	ponte aux;
	
	cout<<"quarto collegamento\n";
	P1=newPonte();
	P2->next=P1;
	P1->vertice=G[8];
	cout<<"quinto collegamento\n";
}




int main(){
nodo *G =new Vertex* [9];//dichiaro un array di vertici
cout<<"creo l'array\n";
	for(int i=0;i<9;i++) {//inizializzo i nodi nell'array
		G[i]=newNodo();
		G[i]->num=i;
		cout<<G[i]->num<<endl;
	}
	cout<<"array creato\n";
	newGraph(G);
	ponte aux;
	aux=G[0]->arco;
	do{
		
		cout<<aux->vertice->num<<endl;
		aux=aux->next;
	
	
	}while(aux!=NULL);
	
	if (aux==NULL)cout<<"sei un coglione\n";
cout<<"prova\n";

}