#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int x;
	int y;
} Point;

typedef struct {
	double y;
	double m;
	double b;
} Line;

Point generatePoint();	//random point generator
Point createPoint(int, int);	//hardcode point coords
Line createLine(Point*, Point*); //creates Line from 2 points
void printPoint(Point*);	//prints point coords
void printLine(Line*);		//prints line formula
//function for m = (y2, y1)/(x2, x1)
double calculateM(Point*, Point*);
//function for b = y/mx (will do this for both points
double calculateB(double, Point*);
void functionTable(Line*);

int main(){
	Point point1 = createPoint(1,2);
	Point point2 = generatePoint();
	Line line;
	printPoint(&point1);
	printPoint(&point2);
	line.m = calculateM(&point1, &point2);
	line.b = calculateB(line.m, &point1);
	printLine(&line);
	functionTable(&line);
	return 0;
}

Point generatePoint(){
	Point point;
	srand(time(NULL));
	int randomNumber = (rand() % 10) + 1;
	point.x = randomNumber;
	randomNumber = (rand() % 10) + 1;
	point.y = randomNumber;
	return point;
}

Point createPoint(int x, int y){
	Point point;
	point.x = x;
	point.y = y;
	return point;
}

void printPoint(Point* point){
	printf("point: {%d,%d}\n", point->x, point->y);
}

void printLine(Line* line){
	printf("line: y = %.2fx + %.2f\n", line->m, line->b);
}

double calculateM(Point* point1, Point* point2){
	double m; 
	int y1 = point1->y;
	int y2 = point2->y;
	int x1 = point1->x;
	int x2 = point2->x;
	m = (double)(y2-y1)/(x2-x1);
	printf("m: %.2f\n", m);
	return m;
}

double calculateB(double m, Point* point){
	double b;
	double intercept = m;
	int y = point->y;
	int x = point->x;
	if(intercept == 0 || x == 0){
		return 0;
	}
	b = (double)y/(intercept * x);
	printf("b: %.2f\n", b);
	return b;
}

void functionTable(Line* line){
	printf("f(x)\tx\n");
	double m = line->m;
	double b = line->b;
	double fx;
	for(int i = 0; i < 10; i++){
		fx=(m*i)+b;
		printf("%.2f\t%d\n", fx, i);
	}
}
