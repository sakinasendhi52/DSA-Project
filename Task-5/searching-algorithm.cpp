/*  Task 5: Searching Algorithm
    Write a C++ program to :
    Accept n elements from user
    Perform Linear Search
    Display position of element if found
    Display number of comparisons made
*/

//header files
#include<iostream>
using namespace std;

int main(){         //main function
    //variables
    int size,search,elementIndex;
    bool found=false;

    cout<<"-------------------------------- SEARCHING ALGORITHM --------------------------------"<<endl;
    cout<<"Enter the size of Array : ";
    cin>>size;           //input size

    int arr[size];
    cout<<endl<<"Enter elements in Array : "<<endl;
    for(int i=0; i<size; i++){
        cout<<"arr["<<i<<"] = ";
        cin>>arr[i];       //input array elements
    }

    cout<<endl<<"Enter element you want to search : ";
    cin>>search;           //input element
    cout<<endl;

    for(int i=0; i<size; i++){
        if(arr[i]==search){     //if element found in the array
            found=true;
            elementIndex=i;
            break;
        }
    }

    if(found){
        cout<<endl<<"Position of element   : "<<elementIndex<<" Index";
        cout<<endl<<"Number of comparisons : "<<elementIndex+1<<" Comparisons"<<endl;
    }
    else{
        cout<<endl<<"No Element Found in Array";
        cout<<endl<<"Number of comparisons : "<<size<<" Comparisons"<<endl;
    }
    cout<<"-------------------------------------------------------------------------------------";

    return 0;
}