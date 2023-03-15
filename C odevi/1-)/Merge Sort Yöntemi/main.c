#include <stdio.h>
#include <stdlib.h>

// Bul ve Fethet algoritmas�
void mergeSort(int arr[], int l, int r);

// Birle�tirme (merge) i�lemi
void merge(int arr[], int l, int m, int r);

// Ana fonksiyon
int main() {
    int n = 10000; // Dizi boyutu
    int arr[n];
    int i;
    // Diziyi rastgele say�larla doldur
    
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    
    // Merge Sort algoritmas� ile diziyi s�rala
    mergeSort(arr, 0, n - 1);
    
    // En b�y�k say�y� yazd�r
    printf("En buyuk sayi: %d\n", arr[n - 1]);
    
    return 0;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        // Sol yar�y� s�rala
        mergeSort(arr, l, m);
        
        // Sa� yar�y� s�rala
        mergeSort(arr, m + 1, r);
        
        // Birle�tirme i�lemi
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Ge�ici diziler
    int L[n1], R[n2];
    
    // Sol yar�y� ge�ici diziye kopyala
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    
    // Sa� yar�y� ge�ici diziye kopyala
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    
    // �ki ge�ici diziyi birle�tir
    i = 0; // Sol yar�daki index
    j = 0; // Sa� yar�daki index
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
    
    // Sol yar�daki kalan elemanlar� ana diziye ekle
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Sa� yar�daki kalan elemanlar� ana diziye ekle
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


