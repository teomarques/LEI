#include <stdio.h>
#include <time.h>

// Function to find minimum value in array
int findMin(int arr[], int length) {
    int min = arr[0];
    for(int i = 1; i < length; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

// Function to find maximum value in array
int findMax(int arr[], int length) {
    int max = arr[0];
    for(int i = 1; i < length; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int verifica(int arr[], int length) {
    // Start timing
    clock_t start_time = clock();
    
    // Variables
    int minEl = findMin(arr, length);
    int maxEl = findMax(arr, length);
    int flag = 0;    // Using int instead of boolean (0 = false, 1 = true)
    int missing = -1;

    // Two nested loops
    for(int i = 0; i < length-1; i++) {
        for(int j = 0; j < length-1; j++) {
            if(arr[j] == arr[i]+1 && arr[i] < maxEl) {
                flag = 1;
                break;
            }
            else if(arr[j] == maxEl && !flag) {
                missing = arr[i]+1;
            }
        }
        if(flag) break;  // Break outer loop if flag is set
    }
    
    // End timing
    clock_t end_time = clock();
    
    // Calculate execution time in seconds
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    printf("Missing element: %d\n", missing);
    printf("Execution time: %.6f seconds\n", execution_time);
    
    return missing;
}

int main() {
    // Test array (equivalent to Python example)
    int arr[] = {1, 2, 4, 5, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    
    verifica(arr, length);
    
    return 0;
}
