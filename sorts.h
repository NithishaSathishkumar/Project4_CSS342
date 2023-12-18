/* Nithisha Sathishkumar
* Novemeber 13, 2023
* Project 1
* Professor.Dimpsey
*/

#ifndef SORT_H
#define SORT_H
#include <vector>
using namespace std;

//Bubble Sort
void BubbleSort(vector<int> &vec, int first_index, int last_index) {
    // Iterate through the array multiple times
    for (int i = first_index; i < last_index; i++) {

        // Iterate through the unsorted portion of the array
        for (int j = first_index; j < last_index - (i - first_index); j++) {

            // Compare adjacent elements and swap if necessary to move the larger element to the right
            if (vec[j] > vec[j + 1]) {

                // Swap elements
                int temp_vec = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp_vec;
            }
        }
    }
}

//Insertion Sort 
void InsertionSort(vector<int> &vec, int first_index, int last_index){
    // Iterate through the unsorted portion of the vector
    for(int i = first_index + 1; i <= last_index; i++){

        // Store the current element to be inserted
        int temp_vec = vec[i];

        // Find the correct position for the current element in the sorted portion
        int j = i - 1;

        while(j >= first_index && temp_vec < vec[j]){

            // Shift elements to make space for the current element
            vec[j + 1] = vec[j];
            vec[j] = temp_vec;
            j--;
        }
    }
}

//Quick Sort recursively
void QuickSort(vector<int> &vec, int first_index, int last_index){

    // Base case: if the subarray is small, use insertion sort
    if(last_index - first_index < 5){
        InsertionSort(vec, first_index, last_index);
        return;
    }

    // Find the median of three for pivot selection
    int mid_index = (first_index + last_index) / 2;
    if(vec[first_index] > vec[last_index]){
        swap(vec[first_index], vec[last_index]);
    }

    if(vec[mid_index] > vec[last_index]){
        swap(vec[mid_index], vec[last_index]);
    }

    if(vec[first_index] > vec[mid_index]){
        swap(vec[first_index], vec[mid_index]);
    }

    // Choose the pivot and move it to the second-to-last position
    int pivot = vec[mid_index];
    swap(vec[mid_index], vec[last_index - 1]);

    //temp_vec_index of the location
    int left = first_index + 1;
    int right = last_index - 2;

    bool done = false;

    //Partition the subarray around the pivot
    while(!done){
        while(vec[left] < pivot){
            left++;
        }
        while(vec[right] > pivot){
            right--;
        }
        if(right > left){
            //Swap elements to ensure left side is less than or equal to the pivot,
            //and right side is greater than or equal to the pivot
            swap(vec[left], vec[right]);
            left++;
            right--;

        }else{
            done = true;
        }
    }

    //Swap the pivot back to its final position
    swap(vec[last_index - 1], vec[left]);

    //Recursively sort the two partitions
    QuickSort(vec, first_index, left - 1);
    QuickSort(vec, left + 1, last_index);

}

//Helper Function for Recursive Merge Sort
void Merge(vector<int> &vec, int first_index, int mid_index, int last_index){

    // Calculate the size of the temporary array
    int vec_size = last_index - first_index + 1;

    // Allocate memory for the temporary array
    int *temp_vec = new int[vec_size];

    // Initialize indices for the two subarrays and the temporary array
    int first1 = first_index;
    int last1 = mid_index;
    int first2 = mid_index + 1;
    int last2 = last_index;
    int temp_vec_index = 0;

    // Merge the two subarrays into the temporary array
    while ((first1 <= last1) && (first2 <= last2)){
        if (vec[first1] < vec[first2]){
            temp_vec[temp_vec_index] = vec[first1];
            first1++;
        }else{
            temp_vec[temp_vec_index] = vec[first2];
            first2++;
        }
        temp_vec_index++;
    }

    // Copy any remaining elements from the first subarray
    while (first1 <= last1){
        temp_vec[temp_vec_index] = vec[first1];
        first1++;
        temp_vec_index++;
    }
    
    // Copy any remaining elements from the second subarray
    while (first2 <= last2){
        temp_vec[temp_vec_index] = vec[first2];
        first2++;
        temp_vec_index++;
    }

    // Copy the sorted elements back to the original vector
    for (temp_vec_index = 0; temp_vec_index < vec_size; temp_vec_index++){
        vec[first_index] = temp_vec[temp_vec_index];
        first_index++;
    }

    // Free the allocated memory for the temporary array
    delete[] temp_vec;
}

//Recursive Merge Sort
void MergeSort(vector<int> &vec, int first_index, int last_index){

    // Base case: if the array has more than one element
    if (first_index < last_index){

        // Calculate the midpoint
        int mid_index = (first_index + last_index) / 2;

        // Recursively sort the two halves
        MergeSort(vec, first_index, mid_index);
        MergeSort(vec, mid_index + 1, last_index);

        // Merge the sorted halves
        Merge(vec, first_index, mid_index, last_index);
    }
}

//Iterative merge sort
void IterativeMergeSort(vector<int> &vec, int first_index, int last_index) {
    int vec_size = last_index - first_index + 1; //Calculate the size of the vector segment to be sorted
    vector<int> temp_vec(vec_size); //Temporary vector to store merged results

    
    for (int i = 1; i <= vec_size; i *= 2) { //Iterate over the vector with increasing step sizes
        for (int left = first_index; left <= last_index; left += (2 * i)) { // Merge adjacent subarrays of size 'i'

            //Determine the boundaries of the subarrays to be merged
            int mid = min(left + i - 1, last_index);
            int right = min(left + 2 * i - 1, last_index);

            //Initialize pointers for merging
            int first1 = left;
            int last1 = mid;
            int first2 = mid + 1;
            int last2 = right;

            //Temporary index for the merged array
            int temp_vec_index = 0;

            //Merge the subarrays
            while (first1 <= last1 && first2 <= last2) {
                temp_vec[temp_vec_index++] = (vec[first1] <= vec[first2]) ? vec[first1++] : vec[first2++];
            }

            //Copy any remaining elements from the left subarray
            while (first1 <= last1) {
                temp_vec[temp_vec_index++] = vec[first1++];
            }

            //Copy any remaining elements from the right subarray
            while (first2 <= last2) {
                temp_vec[temp_vec_index++] = vec[first2++];
            }

            //Copy back to the original vector
            copy(temp_vec.begin(), temp_vec.begin() + temp_vec_index, vec.begin() + left);
        }
    }
}

//Shell Sort
void ShellSort(vector<int> &vec, int first_index, int last_index) {

    // Calculate the size of the vector segment to be sorted
	int size = (last_index - first_index) + 1;

    // Initialize the initial gap for the shell sort
	int gap;

    // Iterate over decreasing gap values
	for (gap = size / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2)) {

        // Iterate over the vector with the current gap
		for (int i = gap; i < size; i++) {

            // Store the current element to be compared and inserted
			int temp = vec[i + first_index];
			int j = i;

            // Compare and move elements within the gap
			for (; j >= gap && (temp < vec[(j-gap)+first_index]); j -= gap) {
				vec[j + first_index] = vec[(j - gap )+first_index];
		    }

            // Insert the current element into its correct position within the gap
			vec[j + first_index] = temp;
		}
	}
}

#endif
