#include <stdio.h>

int factorial(int n) {

	if (n <= 1) return 1;
	else return (n * factorial(n - 1));
}

int sub(int number) {

	int i, result = 0;

	for (i = number; i > 0; i -= 3) {
		result = result + i;
	}
	return result;
}

double iter_power(double base, int power)
{
	int i;
	double result = 1.0;

	for (i = 0; i < power; i++)
	{
		result *= base;
	}
	return result;
}

double recur_power(double base, int power)
{
	double result = 1.0;

	if (power == 0) return 1;
	else if ((power % 2) == 0) return (recur_power(base * base, power / 2));
	else return recur_power(base * base, (power - 1) / 2) * base;
}

int main() {

	int num = 4;
	int res;
	res = factorial(num);

	printf("factorial : %d \n", res);
	printf("sub : %d \n", sub(10));
	printf("power with iteration : %lf \n", iter_power(3, 5));
	printf("power with recursion : %lf \n", recur_power(3, 5));

	return 0;

}