#include <stdio.h>

int n;
int x;

int fact() {
    if (n <= 1) return 1;
    n = n - 1;
    return (n+1) * fact();
}




int main(int argc, char * argv[]) {
    printf("Enter an int: ");
    scanf("%d", &n);
    x = n;
    printf("%d = %d!\n", fact(), x);
}
