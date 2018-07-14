#include <stdio.h>
typedef struct{

	int x;
	int y;

}Point;

void getQtdPoints(int* n){
	FILE* file;
	file = fopen("points.dat","r");
	
	int i = 0;
	fscanf(file,"%i",n);
	
	fclose(file);
}
void lerArquivo(Point points[]){
	
	FILE* file;
	file = fopen("points.dat","r");
	
	int i = 0;
	int n;
	fscanf(file,"%i",&n);
	
	while(i<n){
		
		fseek(file,1,SEEK_CUR);
		fscanf(file,"%i",&points[i].x);
		i++;	
	}
	int cur = i;
	i = 0;		
	while(i<n){
		fseek(file,1,SEEK_CUR);
		fscanf(file,"%i",&points[i].y);
		i++;	
	}	
	close(file);
	
}

void troca(int* x,int* y){

	int aux = *x;
	*x = *y;
	*y = aux;

}
heap(int m,int v[]){

	int k;
	for(k=1;k<m;k++){

		int f = k+1;
		while(f>1&&v[f/2]<v[f]){
			troca(&v[f/2],&v[f]);
			f /=2;
		}
	}
}
void peneira(int m, int v[]){

	int f = 2;
	while(f<=m){

		if(f<m&&v[f]<v[f+1])++f;
		if(v[f/m]>=v[f])break;
		troca(&v[f/2],&v[f]);
		f *=2;
	}

}
double dist(Point* point1,Point* point2){
		
		double xs = pow((point1->x-point2->x),2);
		double ys = pow((point1->y-point2->y),2);
		
	return sqrt(xs+ys);
	
}
double forca_bruta(Point pts[],int n){
	
	
	int i,j;
	double d = dist(&pts[0],&pts[1]);
	double d1;
	for(i=0;i<n;i++){
		
		for(j=i+1;j<n-1;j++){
			d1 = dist(&pts[i],&pts[j]);
			if(d>d1){
				d = d1;
			}	
		}
	}
	
	return d;
	
}
void heapsort(int n, int v[]){
	int m;
	heap(n,v);
	for(m=n;m>=1;m--){
		troca(&v[1],&v[m]);
		peneira(m-1,v);
	}
}

main(){

	srand(time(NULL));

    int n;
    getQtdPoints(&n);
    
	Point p[n];
	int v[n];
	lerArquivo(p);
	
	printf("%lf ",forca_bruta(p,n));
	int i;
	



}
