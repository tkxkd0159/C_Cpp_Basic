#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

	int N;
	int total = 0;
	int** tri = NULL;
	int** answ = NULL;

	scanf("%d", &N);

	tri = (int**)calloc(N, sizeof(int*));
	answ = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++) {
		*(tri + i) = (int*)calloc(i + 1, sizeof(int));
		*(answ + i) = (int*)calloc(i + 1, sizeof(int));
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &(tri[i][j]));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0) answ[i][j] = tri[i][j];
			else {
				if (j == 0) {
					answ[i][j] = answ[i - 1][j] + tri[i][j];
				}
				else if (j == i) {
					answ[i][j] = answ[i - 1][j - 1] + tri[i][j];
				}
				else {
					int left = answ[i - 1][j - 1];
					int right = answ[i - 1][j];
					if (left > right) {
						answ[i][j] = left + tri[i][j];
					}
					else {
						answ[i][j] = right + tri[i][j];
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (total < answ[N - 1][i]) total = answ[N - 1][i];
	}

	printf("%d\n", total);

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", (answ[i][j]));
		}
		printf("\n");
	}
	*/

	for (int i = 0; i < N; i++) {
		free(*(tri + i));
		free(*(answ + i));
	}
	free(tri);
	free(answ);

	return 0;
}
