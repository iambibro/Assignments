#include <stdio.h>
// Procedure to find HCF between m and n
int HCF(int m, int n) {
    if (!m) // m is zero, so n is hcf
        return n;
    if (!n) // n is zero, so m is hcf
        return m;
        	// When both are non-zero
    return (HCF(n, m % n)); // Recursive call
}

int LCM(int m, int n, int x) {
    if (m % n)                       // Remainder is greater than zero, so we will
                                     // go to the next factor of m, i.e. (m+x)
        return (LCM((m + x), n, x)); // Recursive call
    else
        return m; // m is completely divisible by n
}

int main() {
    int n, i, lc, hc;
    printf("\nEnter number of elements : ");
    scanf("%d", &n);
    if (n < 1) {
        printf("\n[Error] Number of elements must be positive!");
        return 1;
    }
    int A[n];
    printf("Enter 1st number : ");
    scanf("%d", &A[0]);
    lc = hc = A[0];
    for (i = 1; i < n; i++) {
        int j = i + 1, suf = j % 10; // for display purposes
        printf("Enter %d%s number : ", j,
               suf == 1 ? "st" : // *1st
               suf == 2 ? "nd" : // *2nd
               suf == 3 ? "rd" : "th"); // *3rd / *th
        scanf("%d", &A[i]); // input
        if (lc < A[i])
            lc = LCM(A[i], lc, A[i]); // LCM Function calling
        else
            lc = LCM(lc, A[i], lc);
        hc = HCF(hc, A[i]); // HCF function calling
    }
    printf("\nHighest Common Factor : %d", hc);
    printf("\nLowest Common Multiple : %d", lc);
}

