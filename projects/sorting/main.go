package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func bubbleSort(numbers []int) {
	for range len(numbers) {
		for j := 0; j < len(numbers)-1; j++ {
			if numbers[j] > numbers[j+1] {
				numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
			}
		}
	}
}

func mergeSort(numbers []int) []int {
	if len(numbers) <= 1 {
		return numbers
	}
	middle := len(numbers) / 2
	left := mergeSort(numbers[:middle])
	right := mergeSort(numbers[middle:])
	return merge(left, right)
}

func merge(left, right []int) []int {
	size, i, j := len(left)+len(right), 0, 0
	result := make([]int, size)
	for k := range size {
		if i > len(left)-1 && j <= len(right)-1 {
			result[k] = right[j]
			j++
		} else if j > len(right)-1 && i <= len(left)-1 {
			result[k] = left[i]
			i++
		} else if left[i] < right[j] {
			result[k] = left[i]
			i++
		} else {
			result[k] = right[j]
			j++
		}
	}
	return result
}

func selectionSort(numbers []int) {
	for i := range len(numbers) {
		min := i
		for j := range numbers[i+1:] {
			if numbers[i+1+j] < numbers[min] {
				min = i + 1 + j
			}
		}
		numbers[i], numbers[min] = numbers[min], numbers[i]
	}
}

func quickSort(numbers []int) []int {
	if len(numbers) <= 1 {
		return numbers
	}

	pivot := numbers[len(numbers)-1]
	var left, right []int

	for i := 0; i < len(numbers)-1; i++ {
		if numbers[i] <= pivot {
			left = append(left, numbers[i])
		} else {
			right = append(right, numbers[i])
		}
	}

	left = quickSort(left)
	right = quickSort(right)

	return append(append(left, pivot), right...)
}

func insertionSort(numbers []int) []int {
	for i := 1; i < len(numbers); i++ {
		key := numbers[i]
		j := i - 1
		for j >= 0 && numbers[j] > key {
			numbers[j+1] = numbers[j]
			j--
		}
		numbers[j+1] = key
	}
	return numbers
}

func heapSort(numbers []int) []int {
	n := len(numbers)
	for i := n/2 - 1; i >= 0; i-- {
		heapify(numbers, n, i)
	}
	for i := n - 1; i > 0; i-- {
		numbers[0], numbers[i] = numbers[i], numbers[0]
		heapify(numbers, i, 0)
	}
	return numbers
}

func heapify(numbers []int, n, i int) {
	largest := i
	left := 2*i + 1
	right := 2*i + 2

	if left < n && numbers[left] > numbers[largest] {
		largest = left
	}
	if right < n && numbers[right] > numbers[largest] {
		largest = right
	}

	if largest != i {
		numbers[i], numbers[largest] = numbers[largest], numbers[i]
		heapify(numbers, n, largest)
	}
}

func countingSort(numbers []int) []int {
	if len(numbers) == 0 {
		return numbers
	}

	max := numbers[0]
	for _, num := range numbers {
		if num > max {
			max = num
		}
	}

	count := make([]int, max+1)
	for _, num := range numbers {
		count[num]++
	}

	sortedIndex := 0
	for i, c := range count {
		for c > 0 {
			numbers[sortedIndex] = i
			sortedIndex++
			c--
		}
	}
	return numbers
}

func radixSort(numbers []int) []int {
	if len(numbers) == 0 {
		return numbers
	}
	max := numbers[0]
	for _, num := range numbers {
		if num > max {
			max = num
		}
	}

	for exp := 1; max/exp > 0; exp *= 10 {
		countingSortForRadix(numbers, exp)
	}
	return numbers
}

func countingSortForRadix(numbers []int, exp int) {
	n := len(numbers)
	output := make([]int, n)
	count := make([]int, 10)

	for i := 0; i < n; i++ {
		index := (numbers[i] / exp) % 10
		count[index]++
	}

	for i := 1; i < 10; i++ {
		count[i] += count[i-1]
	}

	for i := n - 1; i >= 0; i-- {
		index := (numbers[i] / exp) % 10
		output[count[index]-1] = numbers[i]
		count[index]--
	}

	for i := 0; i < n; i++ {
		numbers[i] = output[i]
	}
}

func bubble_test(numbers []int) {
	fmt.Println("Starting timer for bubble sort... ")
	timer := time.Now()
	bubbleSort(numbers)
	fmt.Println("Bubble sort: " + time.Since(timer).String())
}

func merge_test(numbers []int) {
	fmt.Println("Starting timer for merge sort... ")
	timer := time.Now()
	mergeSort(numbers)
	fmt.Println("Merge sort: " + time.Since(timer).String())
}

func selection_test(numbers []int) {
	fmt.Println("Starting timer for selection sort... ")
	timer := time.Now()
	selectionSort(numbers)
	fmt.Println("Selection sort: " + time.Since(timer).String())
}

func quick_test(numbers []int) {
	fmt.Println("Starting timer for quick sort... ")
	timer := time.Now()
	quickSort(numbers)
	fmt.Println("Quick sort: " + time.Since(timer).String())
}

func insertion_test(numbers []int) {
	fmt.Println("Starting timer for insertion sort... ")
	timer := time.Now()
	insertionSort(numbers)
	fmt.Println("Insertion sort: " + time.Since(timer).String())
}

func heap_test(numbers []int) {
	fmt.Println("Starting timer for heap sort... ")
	timer := time.Now()
	heapSort(numbers)
	fmt.Println("Heap sort: " + time.Since(timer).String())
}

func counting_test(numbers []int) {
	fmt.Println("Starting timer for counting sort... ")
	timer := time.Now()
	countingSort(numbers)
	fmt.Println("Counting sort: " + time.Since(timer).String())
}

func radix_test(numbers []int) {
	fmt.Println("Starting timer for radix sort... ")
	timer := time.Now()
	radixSort(numbers)
	fmt.Println("Radix sort: " + time.Since(timer).String())
}

func main() {
	numbers := make([]int, 100_000)
	for i := range numbers {
		numbers[i] = rand.Intn(100_000)
	}
	var wg sync.WaitGroup

	wg.Add(8)

	go func() {
		defer wg.Done()
		numbersCopy := make([]int, len(numbers))
		copy(numbersCopy, numbers)
		bubble_test(numbersCopy)
	}()
	go func() {
		defer wg.Done()
		numbersCopy := make([]int, len(numbers))
		copy(numbersCopy, numbers)
		merge_test(numbersCopy)
	}()
	go func() {
		defer wg.Done()
		numbersCopy := make([]int, len(numbers))
		copy(numbersCopy, numbers)
		selection_test(numbersCopy)
	}()
	go func() {
		defer wg.Done()
		numbersCopy := make([]int, len(numbers))
		copy(numbersCopy, numbers)
		quick_test(numbersCopy)
	}()
	go func() {
		defer wg.Done()
		numbersCopy := make([]int, len(numbers))
		copy(numbersCopy, numbers)
		insertion_test(numbersCopy)
	}()
	go func() {
		defer wg.Done()
		numbersCopy := make([]int, len(numbers))
		copy(numbersCopy, numbers)
		heap_test(numbersCopy)
	}()
	go func() {
		defer wg.Done()
		numbersCopy := make([]int, len(numbers))
		copy(numbersCopy, numbers)
		counting_test(numbersCopy)
	}()
	go func() {
		defer wg.Done()
		numbersCopy := make([]int, len(numbers))
		copy(numbersCopy, numbers)
		radix_test(numbersCopy)
	}()

	wg.Wait()

}
