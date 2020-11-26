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

int fibo(int n)  // 값을 기억하지 않고 연산하는 것이기 때문에 fibo(6)만 계산해도 fibo를 25번 호출해야 함.
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fibo(n - 1) + fibo(n - 2));
}

int iter_fibo(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	int i = 777, result = 0;
	int pp = 0;
	int p = 1;
	printf("test %d \n", i);
	for (i = n; i > 1; i--)
	{
		result = pp + p;
		pp = p;
		p = result;
	}
	return result;
}

int hanoi_count = 0;
void hanoi(int n, char start, char middle, char goal)
{

	if (n == 1)
	{
		printf("Move disk 1 from %c to %c \n", start, goal);
		hanoi_count += 1;
	}
	else {
		hanoi(n - 1, start, goal, middle);
		printf("Move disk %d from %c to %c \n", n, start, goal);
		hanoi_count += 1;
		hanoi(n - 1, middle, start, goal);
	}
}

int main() {

	int num = 4;
	int res;
	res = factorial(num);

	//printf("factorial : %d \n", res);
	//printf("sub : %d \n", sub(10));
	//printf("power with iteration : %lf \n", iter_power(3, 5));
	//printf("power with recursion : %lf \n", recur_power(3, 5));
	//printf("fibo with iterations : %d \n", iter_fibo(7));

	hanoi(4, 'A', 'B', 'C');
	printf("Count : %d", hanoi_count);


	return 0;

}