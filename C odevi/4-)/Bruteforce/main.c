#include <stdio.h>

void bruteforce_sort(int arr[], int n) {
	int i,j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[10000];
    int i;
    // 10.000 say�l�k dizi rastgele olu�turuluyor
    for (i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000;
    }
    
    // S�ralanmadan �nce dizinin ilk 10 eleman� yazd�r�l�yor
    printf("Dizinin ilk 10 elemani:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    bruteforce_sort(arr, 10000);
    
    // S�raland�ktan sonra dizinin ilk 10 eleman� yazd�r�l�yor
    printf("\nDizinin ilk 10 elemani (sirali):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

