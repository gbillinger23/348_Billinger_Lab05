// Name: Gavin Billinger
// KUID: 3107788
// Lab Session: Friday 4p.m.
// Lab Assignment: Lab 05
// Description: Takes the given arrays and works different functions on them.

#include <stdio.h>
#define SIZE 5

void addMatrices(const int m1[SIZE][SIZE], const int m2[SIZE][SIZE]);

void multiplyMatrices(const int m1[SIZE][SIZE], const int m2[SIZE][SIZE]);

void transposeMatrix(const int m[SIZE][SIZE]);

void printMatrix(const int m[SIZE][SIZE]);

void checkInput(int i);

int main(){
	int m1[SIZE][SIZE] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};
	int m2[SIZE][SIZE] = {
		{25, 24, 23, 22, 21},
		{20, 19, 18, 17, 16},
		{15, 14, 13, 12, 11},
		{10, 9, 8, 7, 6},
		{5, 4, 3, 2, 1}
	};

	while(1){
		int num = 0;
		printf("\n1. Add matrices\n2. Multiply matrices\n3. Transpose a matrix.\n4. Print a matrix.\n5. Exit program\n");
		printf("Select an option for the matrix (1-5): ");
		scanf("%d", &num);
		getchar();

		while (num < 1 || num > 5){
			printf("Invalid selection. Select again (1-5): ");
			scanf("%d", &num);
			getchar();
		}

		if (num == 1){
			printf("\n");
			addMatrices(m1, m2);
		}
		else if (num == 2){
			printf("\n");
			multiplyMatrices(m1, m2);
		}
		else if (num == 3){
			printf("\n");
			transposeMatrix(m1);
		}
		else if (num == 4){
			printf("\n");
			printMatrix(m1);
		}
		else if (num == 5){
			break;
		}
	}
	return 0;
}

void addMatrices(const int m1[SIZE][SIZE], const int m2[SIZE][SIZE]){
	int mSum[SIZE][SIZE];
	// To add we just iterate over each row and column.
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			mSum[i][j] = m1[i][j] + m2[i][j];
			printf("%d ", mSum[i][j]);
		}
		printf("\n");
	}
}

void multiplyMatrices(const int m1[SIZE][SIZE], const int m2[SIZE][SIZE]){
	int mProduct[SIZE][SIZE] = {0}; // Initialize product array.
	// We do some dot product iteration stuff here.
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			for (int k = 0; k < SIZE; k++){
				mProduct[i][j] += m1[i][k] * m2[k][j]; // Dot product.
			}
			printf("%d ", mProduct[i][j]); // Print the number.
		}
		printf("\n"); // This will print when a row is complete.
	}
}

void transposeMatrix(const int m[SIZE][SIZE]){
	int mTrans[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			mTrans[j][i] = m[i][j];
		}
	}
	printMatrix(mTrans);
}

void printMatrix(const int m[SIZE][SIZE]){
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			printf("%d ", m[i][j]);
		}
	printf("\n");
	}
}