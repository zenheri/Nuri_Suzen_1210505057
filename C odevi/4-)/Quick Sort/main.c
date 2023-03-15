#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[10000];
    int i;
    // 10.000 sayýlýk dizi rastgele oluþturuluyor
    for (i=0; i < 10000; i++) {
        arr[i] = rand() % 10000;
    }
    
    // Sýralanmadan önce dizinin ilk 10 elemaný yazdýrýlýyor
    printf("Dizinin ilk 10 elemani:\n");
    
    for (i=0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    quicksort(arr, 0, 9999);
    
    // Sýralandýktan sonra dizinin ilk 10 elemaný yazdýrýlýyor
    printf("\nDizinin ilk 10 elemani (sirali):\n");
    for (i=0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

