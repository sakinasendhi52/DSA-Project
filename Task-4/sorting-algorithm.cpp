/*  Task 4: Sorting Algorithm
    Write a C++ program to Accept n elements from user. Sort using Quick Sort. Display sorted array.
    Mention time complexity in comments.
*/


// Time Complexity of Quick Sort
//     Best Case: O(n log n)
//     Average Case: O(n log n)
//     Worst Case: O(n²)

// Space Complexity
//     Auxiliary Space: O(log n) (average) Due to recursion stack
//     Worst Case Space: O(n)


//header files
#include<iostream>
using namespace std;

void insertArray(int arr[], int n){              //insert array
    for(int i=0; i<n; i++){
        cout<<"arr["<<i<<"] : ";
        cin>>arr[i];
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];    //first element as pivot
    int i = low + 1;
    int j = high;
    while(true){
        // move i right
        while(i <= high && arr[i] <= pivot){           //skip elements smaller than pivot
            i++;
        }
        // move j left
        while(arr[j] > pivot){                 //skip elements greater than pivot
            j--;
        }
        //If Left side has big element,Right side has small element then Swap them
        if(i < j){
            swap(arr[i], arr[j]);
        }
        else{    //When pointers cross → stop
            break;
        }
    }
    //place pivot at correct position
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low>=high){
        return;
    }
    int partitionIndex=partition(arr,low,high);
    quickSort(arr, low, partitionIndex-1);
    quickSort(arr, partitionIndex+1, high);
}

void displayArray(int arr[], int n){            //display array
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){           //main function
    int size;

    cout<<"----------------------------- QUICK SORTING -----------------------------"<<endl;

    cout<<"Enter size of array : ";
    cin>>size;           //input size

    int arr[size];

    cout<<endl<<"Enter array elements : "<<endl;
    insertArray(arr,size);       //insert array

    //quick sort
    quickSort(arr,0,size-1);     

    cout<<endl<<"Array elements after sorting : ";
    displayArray(arr,size);       //array display
    cout<<endl<<"-------------------------------------------------------------------------";

    return 0;
}