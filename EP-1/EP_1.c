#include <stdio.h>
#include <time.h>
#include <locale.h>

#define N 40000
#define PASSO 2000

/* Função armazena os dados coletados da quantidade de operações e 
tamanho de entrada  correspondente. A função recebe como argumento o nome
do arquivo a ser criado o tamanho da entrada e a quantidade operações 
além do modo de abertura do arquivo (w,a etc)*/
void armazenarDados(char fileName[],int n,int count,char mode[]){
	
	  FILE* file;
	   file = fopen(fileName,mode);
	  if(mode=="w"){
	  	fputs(" # Tamanho da Entrada: ",file);
	  	fputs("Quantidade de Operações:\n\n",file);
	  }else{	  		
		fprintf(file,"%i",n);
		fputs("\t\t\t",file);
		fprintf(file,"%i",count);
		fputs("\n\n",file);
	  }
	fclose(file);
		  
}

void msgFinal(){
	printf("Fim dos algoritmos!\n\n");
}
//MAX_REC DIVISÃO E COQUISTA//
/*A função MAX_REC recebe como argumento um vetor de inteiros,
a posição inicial e final do vetor uma contadora(count) e a posição da memoria (i) para guarda
o seu valor e devolve o maior valor encontrado
para e e d >= 0 
//visto em sala
*/

int MAX_REC(int v[], int e, int d,int* i,int count){
	
	(*i) = count;
	FILE* file;
	if(e==d){
		
		return v[e];
	}
	int m = (e+d)/2;
	
	int me = MAX_REC(v,e,m,i,++count);
	int md = MAX_REC(v,m+1,d,i,++count);
	
	if(me>md){
	    return me;
	}
	return md;
 	 
}

////////////////////////////
/*A função MAX_IT recebe como argumento um vetor de inteiros,
e o seu tamanho para n>=0, e uma contadora e devolve o maior valor encontrado
*/


int MAX_IT(int v[], int n,int* count){

  int i,maior=0;
  int j = 0;
  for(i=0;i<n;i++){
  	(*count)++;
  	if(v[i]>maior){
  		maior = v[i];
  		
	  }
  }
  return maior;
}

void Q1(void){

		setlocale(LC_ALL,"");
		printf("Questão 1: \n\n");
		
	  int erro=0;
	armazenarDados("MAX_REC.dat",0,0,"w");
	armazenarDados("MAX_IT.dat",0,0,"w");
	  int max_rec,max_it,count;
		int j;int n = PASSO;
		for(j=0;j<20;j++){
			
			  int i,v[n];
			  for(i=0;i<n;i++)
			  {
			    v[i] = rand()%n;
			    
			  }	
			 
			  count = 0;
			  max_rec = MAX_REC(v,0,n-1,&count,0);
			  armazenarDados("MAX_REC.dat",n-1,count,"a");
			  count = 0;
		  	  max_it = MAX_IT(v,n,&count);
		  	  armazenarDados("MAX_IT.dat",n,count,"a");
		  	   
		  
		  
			 n += PASSO;
		  
		}
		msgFinal();
	 
}
///////////////////////////////
/*
A função CRESC_REC recebe como argumento um vetor de inteiros e
seu tamanho para n>=0 e devolve 1 se o vetor estiver ordenado e o senão
devolve 1, se os valores forem iguais ele devolve a posição enontrada
*/
int CRESC_REC(int v[],int e,int d,int i,int* count){

	(*count) = i;
	if(e==d){
		return e;
	}
	int m = (e+d)/2;
	
	int em = CRESC_REC(v,e,m,++i,count);
	int dm = CRESC_REC(v,m+1,d,++i,count);

	if(v[em]>v[dm]){	
		return 0;
	}
	if(v[em]==v[dm]){
		return em;
	}
	return 1;
}
/*
A função CRESC_IT recebe como argumento um vetor de inteiros e
seu tamanho para n>=0 e devolve 1 se o vetor estiver ordenado e o senão
*/
int CRESC_IT(int v[],int n,int* count){
	
	int i;
	for(i=n;i>0;i--){
		(*count)++;
	  if(v[i-1]>v[i]){
	    return 0;
	  }
	}
  return 1;
}
///Chamadas da funções da questão 2
void Q2(void){

	setlocale(LC_ALL,"");
	printf("Questão 2:\n\n");
	armazenarDados("CRESC_REC.dat",0,0,"w");
	armazenarDados("CRESC_IT.dat",0,0,"w");
	
	  int j,count,cresc_rec,cresc_it,erro=0; int n = PASSO;
	  for(j=0;j<20;j++){
	  	int i,v[n];
	  	for(i=0;i<n;i++){
	   	 v[i] = i;
	  	}
	  
	    count = 0; 
		CRESC_REC(v,0,n-1,0,&count);
		armazenarDados("CRESC_REC.dat",n-1,count,"a");
		
		count = 0; 
		CRESC_IT(v,n,&count);
		armazenarDados("CRESC_IT.dat",n,count,"a");
	

		n += PASSO;
	
	  }
	  
	msgFinal();
}
/////////////////////////////////////////
/*
A função LOC_REC recebe como argumento um vetor de inteiros e
o trecho e inicial e final do trecho analisado, além do edereço 
da contadora count=0 e devolve a posição do valor x 
encontrado ou o que mais se aproxima
baseado no LOC_IT feito em sala*/
int LOC_REC(int v[], int e, int d, int x,int i,int* count){
	
	if(e==d-1){
		
	   (*count) = i;
		return d;
	}
	int m = (e+d)/2;
	if(x>v[m]){
		e = m;
	}else{
		d = m;
	}

	LOC_REC(v,e,d,x,++i,count);
	
}
//como feito em sala de aula
/*
A função LOC_IT recebe como argumento um vetor de inteiros o seu tamnho 
o valor x além do edereço da contadora count=0 a ser
 econtrado e devolve a sua posição ou a posição relativa 
ao valor mais próximo
//Alogritmo feito em sala*/
int LOC_IT(int v[],int n,int x,int* count){

int e = -1; int d = n; int m;

	int i = 0;
  while(e<d-1){
  	
	m = (e+d)/2; 
	
  	if(v[m]<x){
  		i++;
  		e = m;
	  }else{
	  	i++;
	  	d = m;
	  }
  	
  }
  
  (*count) = i;
	return d;
}


///Chamda das funções da 3 questão
void Q3(void){
	
	srand(time(NULL));
	setlocale(LC_ALL,"");
	printf("\n\nQuestão 3:\n\n");
  	int n = PASSO;
  	int erro = 0;
 	int j,count;
 	armazenarDados("LOC_REC.dat",0,0,"w");
	armazenarDados("LOC_IT.dat",0,0,"w");
 	for(j=0;j<20;j++){
 		
 		int i,v[n];
	  	i=0;
	  	while(i<n){
		  	v[i] = i;
		  	i++;
	  	}
	  	count= 0; 
	  
	  int x = rand()%n;
	  LOC_IT(v,n,x,&count);
	  armazenarDados("LOC_REC.dat",n,count,"a");
	  count= 0;
	  LOC_REC(v,0,n,x,0,&count);
	  armazenarDados("LOC_IT.dat",n,count,"a");
	 
	  n += PASSO;
	 }
	msgFinal();
}

///////////////////////////////////////////
/*
A função SEG_IT recebe como argumento um vetor de inteiros e
seu tamanho para n>=0 e devolve a soma do vetor v máxima
FONTE: https://www.ime.usp.br/~pf/livrinho-AA/AA-BOOKLET.pdf
*/
int SEG_IT(int A[],int p,int r,int* count){
	
	int x = A[r];
	int q,j,s;
	int i = 0;
	for(q=r-1;q>p;q--){
		s = 0;
		i++;
		for(j=q;j<r;j++){
			 
			 s = s + A[j];
			 i++;
			if(s>x){
				x = s;
			}
		}
		
	}
	(*count) = i;
	return x;
	
}

/*
A função SEG_REC recebe como argumento um vetor de inteiros e
seu tamanho para n>=0, além da valor inicial da soma que deve ser 0
e devolve a soma de todos os valores do vetor v;
FONTE: https://www.ime.usp.br/~pf/livrinho-AA/AA-BOOKLET.pdf
*/
int max(int x,int y,int z){
	
	int v[3]; v[0] = x;v[1] = y; v[2] = z;
	int maior = 0;
	int i;
	for(i=0;i<3;i++){
		if(v[i]>maior){
			maior = v[i];
		}
	}
	return maior;
}
int k = 0;
int SEG_REC(int A[],int p,int r){

	int q;
	int s = 0;
	int x1,x2,y1,y2,i,j,x;
	if(p==r){
		return A[p];
	}else{
		q= (p+r)/2;
		x1 = SEG_REC(A,p,q);
		x2 = SEG_REC(A,q+1,r);
		s = A[q];
		y1 = s;
		
		int i;
	
		for(i=q-1;i>p;i--){
			s = A[i] + s;
			++k;
			if(s>y1){
				y1 = s;
			}
			s = A[q+1];
			y2 = s;
			for(j=q+2;j<r;j++){
				s = s + A[j];
				++k;
				if(s>y2){
					y2 = s;
				}
			}
			
		}
		x = max(x1,y1+y2,x2);
	}
}




void Q4(void){

	setlocale(LC_ALL,"");
	printf("\n\nQuestão 4:\n\n");
	armazenarDados("SEG_REC.dat",0,0,"w");
	armazenarDados("SEG_IT.dat",0,0,"w");
  	int n,j; 
  	int count;
  	n = PASSO;
	for(j=0;j<20;j++){
	  
	  int i = 0;
	   int v[n];
	  while(i<n){
	  	v[i] = i;
	  	i++;
	  }	 
	  
	  	k = 0;
	 	count = 0;
		int seg_it = SEG_IT(v,0,n,&count);
		armazenarDados("SEG_IT.dat",n-1,count,"a");
		count = 0;
		int seg_rec = SEG_REC(v,0,n-1);
		
		armazenarDados("SEG_REC.dat",n,k,"a");
		n += PASSO;
	}
	msgFinal();
}
int main(void) {
 	Q1();
  	Q2();
  	Q3();
  	Q4();
  return 0;
}

