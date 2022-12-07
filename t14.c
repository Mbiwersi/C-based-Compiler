#include <stdio.h>
int x;
int fib(int n) {
    if (n <= 1) return 1;
    return fib(n-2) + fib(n-1);
}




int main(int argc, char * argv[]) {
    printf("Enter an int: ");
    scanf("%d", &x);
    printf("%d = %dth Fibonacci number\n%d = %dth Fibonacci number\n", fib(x),x, fib(2*x), 2*x);
}
