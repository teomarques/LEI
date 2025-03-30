#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b){
  return (*(int*)a - *(int*)b);
}

int main(int argc, char* argv[]) {
    FILE *file;
    int *sequence = NULL;
    int size = 0;
    int capacity = 10;  // Initial capacity for dynamic array
    int num;

    // Open file for reading
    file = fopen("array.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Dynamically allocate memory for sequence
    sequence = (int*)malloc(capacity * sizeof(int));
    if (sequence == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Read numbers from file into sequence
    while (fscanf(file, "%d", &num) == 1) {
        if (size == capacity) {
            // If array is full, double its capacity
            capacity *= 2;
             /* realloc will allocate the memory again with the doubled capacity*sizeof(int) and insert there the sequence previously allocated*/
            int *tmp = realloc(sequence, capacity * sizeof(int));
            if (tmp == NULL) {
                perror("Memory reallocation failed");
                free(sequence);
                fclose(file);
                return 1;
            }
            sequence = tmp;
        }
        sequence[size++] = num;
    }

    fclose(file);

    // Sorting with qsort
    qsort(sequence, size, sizeof(int), compare);

    // Check for gaps and print missing numbers
    for(int i = 0; i < size - 1; i++) {
        if(sequence[i + 1] - sequence[i] > 1) {
            printf("%d\n", sequence[i] + 1);
        }
    }

    // Free dynamically allocated memory
    free(sequence);
    return 0;
}
