#include <iostream>
#include <cstdio>

using namespace std;

void combinar(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mezcla(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mezcla(arr, left, mid);
        mezcla(arr, mid + 1, right);

        combinar(arr, left, mid, right);
    }
}

int main() {
    int n;

    printf("Ingrese el numero de elementos del arreglo: ");
    scanf("%d", &n);

    int arr[n];

    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mezcla(arr, 0, n - 1);

    printf("Arreglo ordenado en orden ascendente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
