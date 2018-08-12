#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int construirLabirinto(int lab[N][N]){

	
	int i,j;
	char pattern[] =  {'a', 'v','r','l'};
	
	int pattern_p =0;
	
	srand(time(NULL));
	for(i=0;i<N;i++){
		
		for(j=0;j<N;j++){
			
			lab[i][j] = rand()%2;
		}
		
	}
	
	for(i=0;i<N;i++){
		
		for(j=0;j<N;j++){
			
			if(lab[i][j]==1){
				
				int color = rand()%4;
				lab[i][j] = pattern[color];	
			}
			
		}
		
	}
	
}
void gerarCoordIniciais(int lab[N][N],int* x,int* y,int* x1,int* y1){
	

	*x = rand()%N;
	*y = rand()%N;
	
	while(lab[*x][*y]==0){	
		*x = rand()%N;
		*y = rand()%N;
	}
	
	*x1 = rand()%N;
	*y1 = rand()%N;
	
	while(lab[*x1][*y1]==0 && (*x1== *x && *y1== *y)){	
		*x1 = rand()%N;
		*y1 = rand()%N;
	}
	
	
	
}
void salvarCoordIniciais(int lab[N][N]){
	
	int x,y,x1,y1;
	gerarCoordIniciais(lab,&x,&y,&x1,&y1);
	
	FILE* file = fopen("labirinto.dat","w");
	
	fprintf(file,"%i",x);
	fprintf(file,"%i",y);
	
	fputs("\n",file);

	fprintf(file,"%i",x);
	fprintf(file,"%i",y);
	
	fputs("\n",file);
	
	fclose(file);		
}

void salvarLabirinto(int lab[N][N]){
	
	FILE* file = fopen("labirinto.txt","a");
	
	int i,j;
	for(i=0;i<N;i++){
		
		for(j=0;j<N;j++){
			
			fprintf(file,"%i",lab[i][j]);	
		}
		fputs("\n",file);
	}

	fclose(file);	
}

int main(){
	
	int lab[N][N];
	construirLabirinto(lab);
	
	
	int i,j;
	for(i=0;i<N;i++){
		
		for(j=0;j<N;j++){
			
			if(lab[i][j]==0){
				printf("%i ",lab[i][j]);	
			}else{
				printf("%c ",lab[i][j]);
			}
			
			
		}
		printf("\n");
	}
	return 0;
}

