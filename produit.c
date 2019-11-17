/*    RAHMANI TAHA ABDELAZIZ   */


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


#define ROW 100
#define COL 200
#define COL2 300
#define NTHREADS 7








int main(){
	int mat1 [ROW][COL], mat2 [COL][COL2] , mat [ROW][COL2];
	
	printf("------------matrice 1 -----------\n");	
 	for(int i = 0 ; i < ROW ; i++){
		for (int j = 0 ; j < COL ; j++){
			mat1 [i][j] = rand()%10;
			printf("%d ",mat1 [i][j]);
		}
		printf(" \n");
	}

   	printf("------------matrice 2 -----------\n");
	for(int i = 0 ; i < COL ; i++){
	        for (int j = 0 ; j < COL2 ; j++){
                        mat2 [i][j] = rand()%10;
                        printf("%d ",mat2 [i][j]);

                }
                printf(" \n");
	}

	printf("--------------------le calcul du produit matricielle parallele--------------------------\n");
	double start = omp_get_wtime();
	#pragma omp parallel shared(mat1,mat2,mat)  num_threads(NTHREADS) 

	for(int i=0; i<ROW; i++){
		int sum=0;
		for(int j=0; j<COL2; j++){
	            	sum = 0;
			for(int k=0; k<COL; k++)
	                  	 sum = sum + mat1[i][k] * mat2[k][j];
	                 mat[i][j] = sum;
	        }
	 }
         
 	double fin = omp_get_wtime() - start;
	printf("------------matrice resultat -----------\n");

	for(int i = 0 ; i < ROW ; i++){
		 for (int j = 0 ; j < COL2 ; j++) 
	                printf("%d ",mat [i][j]);
	         printf(" \n");                  
	}

	printf("temps parallele=%f\n", fin);
	

	printf("--------------------le calcul du produit matricielle sequentielle-----------------------\n");
	start = omp_get_wtime();
	for(int i=0; i<ROW; i++){
		int sum=0;
		for(int j=0; j<COL2; j++){
	            	sum = 0;
			for(int k=0; k<COL; k++)
	                  	 sum = sum + mat1[i][k] * mat2[k][j];
	                 mat[i][j] = sum;
	        }
	 }
	fin = omp_get_wtime() - start;
	printf("------------matrice resultat -----------\n");

	        for(int i = 0 ; i < ROW ; i++){
	        	for (int j = 0 ; j < COL2 ; j++) 
	                	printf("%d ",mat [i][j]);
	        	printf(" \n");
	         }
	 printf("temps sequentielle=%f\n", fin);
	return 0;
} 
