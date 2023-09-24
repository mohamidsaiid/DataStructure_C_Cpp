#include <stdio.h>
#include <stdlib.h>
void pt(int n)
{
	printf("%i ",n);
}

int main()
{
	int *p = (int *)malloc(5*sizeof(int));
	for(int i = 0; i < 5; i++)p[i] = i;
	int *q = (int *) malloc(10*sizeof(int));
	for (int i = 0; i < 5; i++) q[i] = p[i];
	free(p);
	p = q;
	q = NULL;
	for (int i = 0; i < 10; i++)pt(p[i]);

	printf("\n");
	// 3 ways to declare 2d array
	// a[n][m]
	// int *a[3] means array of pointers and you should intialize 
	// the size of every nested array in it using malloc function
	// int **a means pointer that points to another pointer or
	// another pointers
	int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
		{
			pt(a[i][j]);
		}
		printf("\n");
	}

	int *a1[3];
	a1[0] = (int *)malloc(3*sizeof(int));
	a1[1] = (int *)malloc(3*sizeof(int));
	a1[2] = (int *)malloc(3*sizeof(int));
	
	free(a1[0]);
	free(a1[1]);
	free(a1[2]);
	int **a2 = (int **)malloc(3*sizeof(int *));
	for (int i = 0; i < 3; i++)
		a2[i] = (int *) malloc(3*sizeof(int));
	for (int i = 0; i < 3; i++)
		free(a2[i]);


	return 0;

}
