#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "gauss.h"


void HilbertMatrix(int N, double **H); 
void displayMatrix(int N, double **H);
void computeVec(int N, double **H, double *b);
void plotVec(int N, double *v);

void main()
{
	double **H;
	double *b;
	double *x;
	int N;

	printf("Podaj N:");
	scanf("%d", &N);

	b = (double *)malloc(N * sizeof(double));//alokacja pamieci dla wektorow
	x = (double *)malloc(N * sizeof(double));
	H = (double **)malloc(N * sizeof(double *));//alokacja pamieci dla tablicy
	for(int i=0;i<N;i++)
		H[i] = (double *)malloc(N * sizeof(double));

	HilbertMatrix(N, H);
	displayMatrix(N, H);
	computeVec(N, H, b);
	plotVec(N, b);
	gauss(N, H, x, b);
	plotVec(N, x); //funkcja wyswietlajaca wektor x 

	for(int i=0;i<N;i++)
		free(H[i]);
	free(H);
	free(b);
	free(x);
	
}

void HilbertMatrix(int N, double **H) //funkcja ktora tworzy macierz Hilberta 
{
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			H[i][j] = 1./(1. + (double)i + (double)j); //wzor na kolejne elementy macierzy 
		}
	}
}

void displayMatrix(int N, double **H) //funkcja wyswietla macierz H
{	
	printf("Macierz Hilberta:\n");
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			printf("%lf\t", H[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void computeVec(int N, double **H, double *b) //funkcja oblicza wektor prawych stron b
{
	double suma;
	for (int i = 0; i < N; i++) {
		suma = 0.0;
		for (int j = 0; j < N; j++) 
		{
			suma += H[i][j];
		}
	    b[i] = suma;
	}
}

void plotVec(int N, double *v) //funkcja drukujaca wektor 
{	
	printf("WEKTOR:\n");
	for(int i=0;i<N;i++)
	{
		printf("%lf\n", v[i]);
	}
}



