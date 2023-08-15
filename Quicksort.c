#include <stdio.h>
#include <time.h>

void Exchange(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void QuickSort(int a[25], int low, int high) {
    if (low >= high)
        return;

    int key = low;
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && a[i] <= a[key]) {
            i++;
        }
        while (a[key] < a[j]) {
            j--;
        }
        if (i < j) {
            Exchange(&a[i], &a[j]);
        }
    }
    Exchange(&a[key], &a[j]);
    QuickSort(a, low, j - 1);
    QuickSort(a, j + 1, high);
}

int main() {
    int n, a[25], k;
    clock_t st, et;
    double ts;
    printf("\n Enter the count of numbers:");
    scanf("%d", &n);
    printf("\n The Random Numbers are:\n");
    for (k = 0; k < n; k++) {
        scanf("%d", &a[k]);
    }
    st = clock();
    QuickSort(a, 0, n - 1); // Corrected this line
    et = clock();
    ts = (double)(et - st) / CLOCKS_PER_SEC;
    printf("\nst=%ld", st); // Use %ld for printing clock_t
    printf("\net=%ld", et); // Use %ld for printing clock_t
    printf("\nCLOCKS_PER_SEC=%ld", CLOCKS_PER_SEC); // Use %ld for printing clock_t
    printf("\nSorted Numbers are:\n");
    for (k = 0; k < n; k++) { // Corrected this line
        printf("%d\t", a[k]);
    }
    printf("\n The time taken is %e", ts);
    return 0;
}
