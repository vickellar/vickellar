⁷// parallel programming for calculatiing pi 
// this program does not run on normal compilers but there are some additions to be done on your compiler linkers... so that so of the function could work 
#include <stdio.h>
#include <omp.h> // 

int main() {
    int n = 10000; // Number of terms in the Leibniz series
    double pi_estimate = 0.0;

    #pragma omp parallel for reduction(+:pi_estimate)
    for (int i = 0; i < n; i++) {
        double term = (i % 2 == 0) ? 1.0 / (2 * i + 1) : -1.0 / (2 * i + 1);
        pi_estimate += term;

        // Print intermediate value for each thread
        printf("Thread %d: Partial sum = %.10lf\n", omp_get_thread_num(), pi_estimate);
    }

    pi_estimate *= 4.0; // Multiply by 4 to get the final estimate of π

    printf("Estimated value of π using Leibniz series: %.10lf\n", pi_estimate);

    return 0;
}
