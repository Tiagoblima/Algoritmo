
#ifndef CLOSEPOINT_H
#define CLOSEPOINT_H

typedef struct {
	int x;
	int y;
}Point;

double dist(Point* point1,Point* point2){
		
		double xs = pow((point1->x-point2->x),2);
		double ys = pow((point1->y-point2->y),2);
		
	return sqrt(xs+ys);
	
}

void closePoint(Point points[],int qtd_point,double* closest,Point* p1,Point* p2){
	
	int i,j;

	for(i=0;i<qtd_point;i++){
		
		for(j=i+1;j<qtd_point;j++){
			
			double calculo = dist(&points[i],&points[j]);
			if(*closest>calculo){
				
				*closest = calculo;
				*p1 = points[i];
				*p2 = points[j];
			}
					
		}
		
	}
		
}
#endif
