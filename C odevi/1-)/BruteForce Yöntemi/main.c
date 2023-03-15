#include <stdio.h>
#include <stdlib.h>

// Ana fonksiyon
int main() {
    int n = 10000; // Dizi boyutu
    int arr[n];
    int i = 0;
    // Diziyi rastgele sayýlarla doldur
    for (i; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    
    // En büyük sayýyý bul
    int max = arr[0];
    
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // En büyük sayýyý yazdýr
    printf("En buyuk sayi: %d\n", max);
    
    return 0;
}

