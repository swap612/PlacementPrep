#include <stdio.h>

// swap utility
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b =temp;
}

// Partition 
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i =low-1;
    for(int j= low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    // for (int k = low;  k<= high; k++)
    //     printf("%d ", arr[k]);
    return i+1;
}

void quicksort(int arr[], int low, int high){
    // printf("QS: %d -- %d",low, high);
    if(low < high){
        int pi = partition(arr, low, high);
        quicksort(arr,low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main()
{
    int arr[] = {11, 2, 33, 4,55, 6,7, 38,9};

    int low = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("QuickSort: Original array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    quicksort(arr, low, size - 1);
    // int a = 8, b =10;
    // swap(&a, &b);
    // printf("a: %d, b: %d",a,b);
    printf("\nQuickSort: Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

}