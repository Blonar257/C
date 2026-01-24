#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

// Bubble Sort - modifies array in place
void bubble_sort(int *numbers, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

// Merge Sort - returns new sorted array
int *merge_sort(int *numbers, int n) {
    if (n <= 1) {
        int *result = (int *)malloc(n * sizeof(int));
        if (n == 1) {
            result[0] = numbers[0];
        }
        return result;
    }
    
    int middle = n / 2;
    int *left = merge_sort(numbers, middle);
    int *right = merge_sort(numbers + middle, n - middle);
    
    int *result = (int *)malloc(n * sizeof(int));
    
    int i = 0, j = 0, k = 0;
    int left_len = middle;
    int right_len = n - middle;
    
    while (i < left_len && j < right_len) {
        if (left[i] < right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }
    
    while (i < left_len) {
        result[k++] = left[i++];
    }
    
    while (j < right_len) {
        result[k++] = right[j++];
    }
    
    free(left);
    free(right);
    
    return result;
}

// Selection Sort - modifies array in place
void selection_sort(int *numbers, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (numbers[j] < numbers[min]) {
                min = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }
}

// Quick Sort helper function
int *quick_sort_helper(int *numbers, int n) {
    if (n <= 1) {
        int *result = (int *)malloc(n * sizeof(int));
        if (n == 1) {
            result[0] = numbers[0];
        }
        return result;
    }
    
    int pivot = numbers[n - 1];
    int *left = (int *)malloc(n * sizeof(int));
    int *right = (int *)malloc(n * sizeof(int));
    int left_count = 0, right_count = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (numbers[i] <= pivot) {
            left[left_count++] = numbers[i];
        } else {
            right[right_count++] = numbers[i];
        }
    }
    
    int *sorted_left = quick_sort_helper(left, left_count);
    int *sorted_right = quick_sort_helper(right, right_count);
    
    int *result = (int *)malloc(n * sizeof(int));
    int idx = 0;
    
    for (int i = 0; i < left_count; i++) {
        result[idx++] = sorted_left[i];
    }
    result[idx++] = pivot;
    for (int i = 0; i < right_count; i++) {
        result[idx++] = sorted_right[i];
    }
    
    free(left);
    free(right);
    free(sorted_left);
    free(sorted_right);
    
    return result;
}

// Quick Sort - returns new sorted array
int *quick_sort(int *numbers, int n) {
    return quick_sort_helper(numbers, n);
}

// Insertion Sort - modifies array in place
int *insertion_sort(int *numbers, int n) {
    int *result = (int *)malloc(n * sizeof(int));
    memcpy(result, numbers, n * sizeof(int));
    
    for (int i = 1; i < n; i++) {
        int key = result[i];
        int j = i - 1;
        while (j >= 0 && result[j] > key) {
            result[j + 1] = result[j];
            j--;
        }
        result[j + 1] = key;
    }
    return result;
}

// Heapify helper for heap sort
void heapify(int *numbers, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && numbers[left] > numbers[largest]) {
        largest = left;
    }
    if (right < n && numbers[right] > numbers[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        int temp = numbers[i];
        numbers[i] = numbers[largest];
        numbers[largest] = temp;
        heapify(numbers, n, largest);
    }
}

// Heap Sort - modifies array in place
int *heap_sort(int *numbers, int n) {
    int *result = (int *)malloc(n * sizeof(int));
    memcpy(result, numbers, n * sizeof(int));
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(result, n, i);
    }
    
    for (int i = n - 1; i > 0; i--) {
        int temp = result[0];
        result[0] = result[i];
        result[i] = temp;
        heapify(result, i, 0);
    }
    
    return result;
}

// Counting Sort - returns new sorted array
int *counting_sort(int *numbers, int n) {
    if (n == 0) {
        return (int *)malloc(0);
    }
    
    int max = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[numbers[i]]++;
    }
    
    int *result = (int *)malloc(n * sizeof(int));
    int sorted_index = 0;
    
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            result[sorted_index++] = i;
        }
    }
    
    free(count);
    return result;
}

// Counting Sort for Radix Sort helper
void counting_sort_for_radix(int *numbers, int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int *count = (int *)calloc(10, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        int index = (numbers[i] / exp) % 10;
        count[index]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        int index = (numbers[i] / exp) % 10;
        output[count[index] - 1] = numbers[i];
        count[index]--;
    }
    
    for (int i = 0; i < n; i++) {
        numbers[i] = output[i];
    }
    
    free(output);
    free(count);
}

// Radix Sort - returns new sorted array
int *radix_sort(int *numbers, int n) {
    if (n == 0) {
        return (int *)malloc(0);
    }
    
    int *result = (int *)malloc(n * sizeof(int));
    memcpy(result, numbers, n * sizeof(int));
    
    int max = result[0];
    for (int i = 1; i < n; i++) {
        if (result[i] > max) {
            max = result[i];
        }
    }
    
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort_for_radix(result, n, exp);
    }
    
    return result;
}

// Test function for bubble sort
void bubble_test(int *numbers, int n) {
    printf("Starting timer for bubble sort... \n");
    
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    int *copy = (int *)malloc(n * sizeof(int));
    memcpy(copy, numbers, n * sizeof(int));
    bubble_sort(copy, n);
    
    clock_gettime(CLOCK_REALTIME, &end);
    
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Bubble sort: %.6f seconds\n", elapsed);
    
    free(copy);
}

// Test function for merge sort
void merge_test(int *numbers, int n) {
    printf("Starting timer for merge sort... \n");
    
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    int *sorted = merge_sort(numbers, n);
    
    clock_gettime(CLOCK_REALTIME, &end);
    
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Merge sort: %.6f seconds\n", elapsed);
    
    free(sorted);
}

// Test function for selection sort
void selection_test(int *numbers, int n) {
    printf("Starting timer for selection sort... \n");
    
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    int *copy = (int *)malloc(n * sizeof(int));
    memcpy(copy, numbers, n * sizeof(int));
    selection_sort(copy, n);
    
    clock_gettime(CLOCK_REALTIME, &end);
    
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Selection sort: %.6f seconds\n", elapsed);
    
    free(copy);
}

// Test function for quick sort
void quick_test(int *numbers, int n) {
    printf("Starting timer for quick sort... \n");
    
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    int *sorted = quick_sort(numbers, n);
    
    clock_gettime(CLOCK_REALTIME, &end);
    
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Quick sort: %.6f seconds\n", elapsed);
    
    free(sorted);
}

// Test function for insertion sort
void insertion_test(int *numbers, int n) {
    printf("Starting timer for insertion sort... \n");
    
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    int *sorted = insertion_sort(numbers, n);
    
    clock_gettime(CLOCK_REALTIME, &end);
    
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Insertion sort: %.6f seconds\n", elapsed);
    
    free(sorted);
}

// Test function for heap sort
void heap_test(int *numbers, int n) {
    printf("Starting timer for heap sort... \n");
    
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    int *sorted = heap_sort(numbers, n);
    
    clock_gettime(CLOCK_REALTIME, &end);
    
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Heap sort: %.6f seconds\n", elapsed);
    
    free(sorted);
}

// Test function for counting sort
void counting_test(int *numbers, int n) {
    printf("Starting timer for counting sort... \n");
    
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    int *sorted = counting_sort(numbers, n);
    
    clock_gettime(CLOCK_REALTIME, &end);
    
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Counting sort: %.6f seconds\n", elapsed);
    
    free(sorted);
}

// Test function for radix sort
void radix_test(int *numbers, int n) {
    printf("Starting timer for radix sort... \n");
    
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    int *sorted = radix_sort(numbers, n);
    
    clock_gettime(CLOCK_REALTIME, &end);
    
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Radix sort: %.6f seconds\n", elapsed);
    
    free(sorted);
}

// Thread argument structure
struct thread_args {
    int *numbers;
    int n;
    void (*test_func)(int *, int);
};

// Thread function
void *thread_function(void *arg) {
    struct thread_args *args = (struct thread_args *)arg;
    args->test_func(args->numbers, args->n);
    free(args);
    return NULL;
}

int main() {
    int n = 100000;
    srand(42);
    
    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % 100000;
    }
    
    pthread_t threads[8];
    
    // Bubble sort thread
    struct thread_args *args1 = (struct thread_args *)malloc(sizeof(struct thread_args));
    args1->numbers = numbers;
    args1->n = n;
    args1->test_func = bubble_test;
    pthread_create(&threads[0], NULL, thread_function, args1);
    
    // Merge sort thread
    struct thread_args *args2 = (struct thread_args *)malloc(sizeof(struct thread_args));
    args2->numbers = numbers;
    args2->n = n;
    args2->test_func = merge_test;
    pthread_create(&threads[1], NULL, thread_function, args2);
    
    // Selection sort thread
    struct thread_args *args3 = (struct thread_args *)malloc(sizeof(struct thread_args));
    args3->numbers = numbers;
    args3->n = n;
    args3->test_func = selection_test;
    pthread_create(&threads[2], NULL, thread_function, args3);
    
    // Quick sort thread
    struct thread_args *args4 = (struct thread_args *)malloc(sizeof(struct thread_args));
    args4->numbers = numbers;
    args4->n = n;
    args4->test_func = quick_test;
    pthread_create(&threads[3], NULL, thread_function, args4);
    
    // Insertion sort thread
    struct thread_args *args5 = (struct thread_args *)malloc(sizeof(struct thread_args));
    args5->numbers = numbers;
    args5->n = n;
    args5->test_func = insertion_test;
    pthread_create(&threads[4], NULL, thread_function, args5);
    
    // Heap sort thread
    struct thread_args *args6 = (struct thread_args *)malloc(sizeof(struct thread_args));
    args6->numbers = numbers;
    args6->n = n;
    args6->test_func = heap_test;
    pthread_create(&threads[5], NULL, thread_function, args6);
    
    // Counting sort thread
    struct thread_args *args7 = (struct thread_args *)malloc(sizeof(struct thread_args));
    args7->numbers = numbers;
    args7->n = n;
    args7->test_func = counting_test;
    pthread_create(&threads[6], NULL, thread_function, args7);
    
    // Radix sort thread
    struct thread_args *args8 = (struct thread_args *)malloc(sizeof(struct thread_args));
    args8->numbers = numbers;
    args8->n = n;
    args8->test_func = radix_test;
    pthread_create(&threads[7], NULL, thread_function, args8);
    
    // Wait for all threads
    for (int i = 0; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }
    
    free(numbers);
    
    return 0;
}
