#include <stdio.h>
#include <stdlib.h>

// Bul ve Fethet algoritmasý
void mergeSort(int arr[], int l, int r);

// Birleþtirme (merge) iþlemi
void merge(int arr[], int l, int m, int r);

// Ana fonksiyon
int main() {
    int n = 10000; // Dizi boyutu
    int arr[n];
    int i;
    // Diziyi rastgele sayýlarla doldur
    
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    
    // Merge Sort algoritmasý ile diziyi sýrala
    mergeSort(arr, 0, n - 1);
    
    // En büyük sayýyý yazdýr
    printf("En buyuk sayi: %d\n", arr[n - 1]);
    
    return 0;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        // Sol yarýyý sýrala
        mergeSort(arr, l, m);
        
        // Sað yarýyý sýrala
        mergeSort(arr, m + 1, r);
        
        // Birleþtirme iþlemi
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Geçici diziler
    int L[n1], R[n2];
    
    // Sol yarýyý geçici diziye kopyala
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    
    // Sað yarýyý geçici diziye kopyala
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    
    // Ýki geçici diziyi birleþtir
    i = 0; // Sol yarýdaki index
    j = 0; // Sað yarýdaki index
    k = l; // Ana daki index
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
    
    // Sol yarýdaki kalan elemanlarý ana diziye ekle
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Sað yarýdaki kalan elemanlarý ana diziye ekle
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


