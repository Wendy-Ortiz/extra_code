/* Wendy Ortiz alfaro (B75584)
Profesor: Sauma - Curso: Analisis de algoritmos
Universidad de Costa Rica - ECCI
Laboratorio #2: Ejercicio 1 - heap-sort */
#include <iostream>

using namespace std;

void correct_top(int array[], int n, int k);
void monticularize(int arr[], int n);
void extract_maximum(int array[], int n);
bool empty(int array[]);
void sort(int array[], int n);
void print_array(int array[], int n, string message);


// principal function 
int main() {
    int array_1[] = { 100, 15, 2, 40, 44, 75, 50, 4, 90, 40 };
    int n_1 = sizeof(array_1) / sizeof(array_1[0]);

    int array_2[] = { 12, -9, 1, -5, 60, 7 };
    int n_2 = sizeof(array_2) / sizeof(array_2[0]);

    int array_3[] = { -4, 3, 6, 9, 12, 15, 2, 4, -61, 8, 10, 1, 21, -3, 4, 10};
    int n_3 = sizeof(array_3) / sizeof(array_3[0]);

    print_array(array_1, n_1, "I) Messy array:\n");
    sort(array_1, n_1);
    print_array(array_1, n_1, "Ordered array:\n");

    print_array(array_2, n_2, "II) Messy array:\n");
    sort(array_2, n_2);
    print_array(array_2, n_2, "Ordered array:\n");

    print_array(array_3, n_3, "III) Messy array:\n");
    sort(array_3, n_3);
    print_array(array_3, n_3, "Ordered array:\n");
    
}

/* put all elements in a heap from position k down - makes it a heap
** @param array of integers; n is the size of it and k is the actual position
*/
void correct_top(int array[], int n, int k) {
    int j = k; // temporary
    int left = 2 * k; // formula 2 * i + 1
    int right = 2 * k + 1; // formula 2 * i + 2

    // if the element that is in position k is greater than its children
    if (left < n && array[left] > array[j])
        j = left;

    if (right < n && array[right] > array[j])
        j = right;

    // if the element is not greater than its children
    if (j != k) {
        // in j is the maximum
        swap(array[k], array[j]);
        // Recursively with j
        correct_top(array, n, j);
    }
}

/** reallocate the array elements - the top one should be the largest
** @param array of integers that we need to reallocate; n is the size of it
*/
void monticularize(int array[], int n) {
    // rearrange array
    for (int index = n / 2; index >= 0; index--) // last father
        correct_top(array, n, index);
}

/** Extract the maximum and put it in the last position of the array
** @param array of integers that works as a heap; n is the size of it
*/
void extract_maximum(int array[], int n) {
    // remove the largest and put it last
    for (int index = n - 1; index > 0; index--) {
        swap(array[0], array[index]);
        //rearrange everything to remain heap
        correct_top(array, index, 0);
    }
}

/** This function checks that the heap is not empty
** @param the array that we need to check
** @return true if is empty
*/
bool empty(int array[]) {
    return array[0] == NULL;
}

/** This function sort the array
** @param Array of integers that we need to sort; n is the size of it
*/
void sort(int array[], int n) {

    monticularize(array, n);
    if (empty(array) != true) {
        extract_maximum(array, n);
    }
}

/** This method print the array
** @param Array of integers that we need to print; n is the size of it
**  and a message for show in a screen
*/
void print_array(int array[], int n, string message) {
    
    cout << message;

    for (int index = 0; index < n; ++index)
        cout << array[index] << " ";
    cout << "\n\n";
}
