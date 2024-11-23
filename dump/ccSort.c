#include <stdio.h>

void sort(int b[], int l, int r) {
    if (l >= r) {
        return;
    }
    int index = b[r];
    int i = l - 1, j = l;
    while (j < r) {
        if (b[j] < index) {
            i++;
            int temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
        j++;
    }
    int temp = b[i + 1];
    b[i + 1] = b[r];
    b[r] = temp;
    sort(b, l, i);
    sort(b, i + 2, r);
}

int main() {
    int i;
    int a[7] = { 44, 33, 66, 55, 77, 11, 22 };
    sort(a, 0, 6);
    for (i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}