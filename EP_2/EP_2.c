#include <stdio.h>
#include <Math.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}Ponto;

void getQtdPoints(int* n){
	FILE* file;
	file = fopen("points.dat","r");
	
	int i = 0;
	fscanf(file,"%i",n);
	
	fclose(file);
}
void lerArquivo(Ponto points[]){
	
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

double dist(Ponto* point1,Ponto* point2){
		
		double xs = pow((point1->x-point2->x),2);
		double ys = pow((point1->y-point2->y),2);
		
	return sqrt(xs+ys);
	
}


///////////////////////////////////////


void intercala(int v[],int p,int q,int r){
	

	int i,j,k;
	
	int* w = (int*) malloc((r-p)* sizeof (int));  
	k=0;
	i = p; j=q;
		
	while(i<q && j<r){
			
		if(v[i]<=v[j]){
			w[k++] = v[i++];	
		}else{
			w[k++] = v[j++];
		}
	}
	
	while(i<q){
		w[k++] = v[i++];

	}
	
	while(j<r){
		w[k++] = v[j++];
	}

	
	for(i=p;i<r;i++){
		v[i] = w[i-p];
	}
	
	
	free(w);
}
void mergesort(int v[],int p, int r){
	
	
	
	int i = p; int j=r;

	if(p<r-1){	
		int q = (p+r)/2;
		
		mergesort(v,p,q);
		mergesort(v,q,r);
		intercala(v,p,q,r);
	}

}

void intercalaInd(int v[],int p,int q,int r,int a[]){
	
	
	

	int i,j,k;
	int t,u,g;
	int* w = (int*) malloc((r-p)*sizeof(int));  
	int* s = (int*) malloc((r-p)*sizeof(int));  
	k=0;
	g=0;
	i = p; j=q;
	t = p; u = q;	
	while(i<q && j<r){
		
		if(v[i]<=v[j]){
			
			s[k++] = a[i++];
			w[g++] = v[t++];
		}else{
			s[k++] = a[j++]; 
			w[g++] = v[u++];
		}
		
	}
	
	while(i<q){
		s[k++] = a[i++];
		w[g++] = v[t++];
	}
	
	while(j<r){
		s[k++] = a[j++];
		w[g++] = v[u++];	
	}

	
	for(i=p;i<r;i++){
		v[i] = w[i-p];
		a[i] = s[i-p];
	}
	
	free(s);
	free(w);
}
void mergesortInd(int v[],int p, int r,int a[]){
	
	

	
	int i = p; int j=r;
	
	if(p<r-1){	
		int q = (p+r)/2;
		
		mergesortInd(v,p,q,a);
		mergesortInd(v,q,r,a);
		intercalaInd(v,p,q,r,a);
	}

}

int minInt(int x,int y){
	
	if(x<y){
		return x;
	}else{
		return y;
	}
	
}

double minDouble(double x, double y){
	
	if(x<y){
		return x;
	}else{
		return y;
	}
}

int candidatos(int v[],int a[],int p,int r,int d,int f[]){
	

	int q = (p+r)/2;
	int t = 0;
	int k;
		
	for(k=p;k<r;k++){
		
		if(abs(v[a[k]]-v[q])<d){
			t++;
			f[t] = a[k];	
		}
	}

	return t;
}
double combina(Ponto pts[],int a[],int p,int r,double de,double dd){
	

	double d = minDouble(de,dd);
	int* f = (int*) malloc((r-p)*sizeof(int));
	int i,j;
	
	int* v = (int*) malloc((r-p)*sizeof(int));
	//possivel erro

	for(i=p;i<r;i++){
		v[i] = pts[i].x;
	
	}
	int t = candidatos(v,a,p,r,d,f);
	double d1;
	free(v);
	for(i=0;i<t-1;i++){
		for(j=i+1;j<minInt(i+7,t);j++){
			
			d1 = dist(&pts[i],&pts[j]);
			
			if(d1<d){
				d = d1;
			}
		}
	}
	

	return d;
}
void divida(Ponto pts[],int a[],int p,int r,int b[]){


	int q = (p+r)/2;
	int i = p-1; int j=q;
	int k;
	for(k=p;k<r;k++){
		
		if(a[k]<=q){
			i++;
			b[i] = a[k];
		}else{
			j++;
			b[j] = a[k];
		}
	}
	
}
double distanciaRec_SH(Ponto pts[],int a[],int p,int r){
	
	int i;
	
	int q = (p+r)/2;
	
		
	 if(r<=p+2){
	 
	 	return dist(&pts[r],&pts[p]);
	 }else{
	 	
	 
	 	
		int* b = (int*) malloc((r-p)*sizeof(int));
		divida(pts,a,p,r,b);
		
		double de = distanciaRec_SH(pts,b,p,q);
		
		double dd = distanciaRec_SH(pts,b,q+1,r);
		free(b);

	   return combina(pts,a,p,r,de,dd);	
	 }
	 
}
double distancia_SH(Ponto p[],int n){
	
	


	int i;
	int v[n];
			
	int* a = (int*) malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		v[i] = p[i].x; 
	}
	mergesort(v,0,n);
	
	for(i=0;i<n;i++){
		p[i].x = v[i];	 
	}

	for(i=0;i<n;i++){
		a[i] = i;
		v[i] = p[i].y;

	}
	
	mergesortInd(v,0,n,a);
	
	return distanciaRec_SH(p,a,0,n);

}

void verificarOrdenacao(Ponto p[],int n){
	
	
	int v[n];
	int i;
	
	printf("n: %i\n",n);
	for(i=0;i<n;i++){
		v[i] = p[i].x;
		printf("v[%i]: %i\t\n",i,p[i].x);
	}
	printf("\n");
	
	mergesort(v,0,n);
	
	for(i=0;i<n;i++){
		
		p[i].x = v[i];
		
		printf("v[%i]: %i\n",i,p[i].x);
	}
	
}
main(){
	
	srand(time(NULL));
	
	int n;
	getQtdPoints(&n);
	Ponto p[n];
	lerArquivo(p);
	
	double distancia = distancia_SH(p,n);
	
	printf("dist: %lf",distancia);
}
