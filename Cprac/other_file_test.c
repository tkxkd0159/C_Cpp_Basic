#include <stdio.h>

int main() {
	printf("Rename to Test\n");
	
	printf("int: %zu uint: %zu double: %zu float: %zu char: %zu", sizeof(int), sizeof(unsigned int), sizeof(double), sizeof(float), sizeof(char));

	return 0;
}