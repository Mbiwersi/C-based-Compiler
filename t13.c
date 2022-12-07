#include <stdio.h>
int x;
int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n-1);
}




int main(int argc, char * argv[]) {
    printf("Enter an int: ");    scanf("%d", &x);
    printf("%d = %d!\n%d = 2*(2*%d)!\n", fact(x), x, 2*fact(2*x), x);
}
