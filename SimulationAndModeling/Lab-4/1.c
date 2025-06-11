//Lab-4 Implementation of testing of uniformity of random numbers using chi-square test.
/*
Algorithm:
    1. Fix the number of intervals 'n' of equal length in [0,1]
    2. Compute E = N/n, where E is expected number in each interval, N is total sample size
    3. Compute the observed Oi in the interval for i=1,2,...
    4. Compute chi-square = SUM((Oi-Ei)^2)/Ei for i = 1 to n
    Where Oi is the observed number in the ith class.
          Ei is the expected number in the ith class
          n is the number of classes
    5. Determine the critical value Chi-square(t) from the chi-square table for the specified alpha and n-1 degree of freedom 
    6. If chi+squate > chi-square table the nnumbers are uniformily distributed else not.
*/

#include <stdio.h>
#include <math.h>

#define MAX 1000  // maximum number of random numbers

int main() {
    int N, n, i, index;
    double numbers[MAX], expected, observed[50] = {0};
    double chi_square = 0.0, critical_value;

    // Step 1: Input number of random numbers and intervals
    printf("Enter the number of random numbers (N): ");
    scanf("%d", &N);

    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);

    if (n > 50) {
        printf("Too many intervals. Max supported is 50.\n");
        return 1;
    }

    // Step 2: Input random numbers in [0, 1)
    printf("Enter %d random numbers (between 0 and 1):\n", N);
    for (i = 0; i < N; i++) {
        scanf("%lf", &numbers[i]);
        if (numbers[i] < 0 || numbers[i] >= 1) {
            printf("Invalid input. Random numbers must be in [0,1).\n");
            return 1;
        }
    }

    // Step 3: Compute expected frequency
    expected = (double)N / n;

    // Step 4: Count observed frequencies
    for (i = 0; i < N; i++) {
        index = (int)(numbers[i] * n); // which interval the number falls into
        if (index == n) index = n - 1; // handle edge case for 1.0
        observed[index]++;
    }

    // Step 5: Compute chi-square statistic
    for (i = 0; i < n; i++) {
        chi_square += ((observed[i] - expected) * (observed[i] - expected)) / expected;
    }

    // Print interval info
    printf("\nInterval\tObserved\tExpected\n");
    for (i = 0; i < n; i++) {
        printf("[%0.2lf - %0.2lf)\t%d\t\t%.2lf\n", (double)i / n, (double)(i + 1) / n, (int)observed[i], expected);
    }

    // Step 6: Input critical value and conclude
    printf("\nEnter critical chi-square value from table (df = n - 1): ");
    scanf("%lf", &critical_value);

    printf("\nCalculated Chi-Square value = %.4lf\n", chi_square);

    if (chi_square > critical_value)
        printf("Result: Numbers are uniformly distributed (Reject H0)\n");
    else
        printf("Result: Numbers are NOT uniformly distributed (Accept H0)\n");

    return 0;
}
