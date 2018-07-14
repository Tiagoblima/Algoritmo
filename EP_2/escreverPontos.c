#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void savePoints(int qtd_points){

	srand(time(NULL));
	FILE* file;
	file = fopen("points.dat","w");
	int i = 0; 
	fprintf(file,"%i",qtd_points);
	fputs("\n",file);
	while(i<qtd_points){
	 fprintf(file,"%i",1+rand()%qtd_points);
	 fputs(" ",file);	
	 i++;
	}
	i = 0;
	fputs("\n",file);
	while(i<qtd_points){
		fprintf(file,"%i",1+rand()%qtd_points);
		fputs(" ",file);
		i++;
	}
	
	fclose(file);
	
}
int matriz(int** m){
	printf("%i ", m[0][7]);
}
main(){
	
	int n;
	printf("Digite a quantidade de pontos: ");
	scanf("%i",&n);
	savePoints(n);
	int **M; 
   	M = malloc (n * sizeof (int *));
   	int i;
   	for (i = 0; i < n; ++i)
      M[i] = malloc (n * sizeof (int));
      
      M[0][7]= 0;
	matriz(M);
}
