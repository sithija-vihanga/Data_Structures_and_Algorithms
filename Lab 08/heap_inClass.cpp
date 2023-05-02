#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int large_index = root;
   int left_index = 2*root+1;
   int right_index = 2*root+2;

   if(arr[large_index]<arr[left_index]  && left_index< n){
      large_index = left_index;
   }
   if(arr[large_index]<arr[right_index]  && right_index <n){
      large_index = right_index;
   }
   if(large_index != root){
         swap(arr[large_index], arr[root]);
         heapify(arr,n,large_index);
   }
  
   
}


  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int j = 0; j<n; j++){
       for(int i = n-j; i>=0; i--){
       heapify(arr, i , 0);
       //displayArray(arr,n);
       //
       }
       //cout<<"value is: "<<arr[0]<<endl;
       swap(arr[0],arr[n-j-1]);
   }
   
  
   // extracting elements from heap one by one
   
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
  

// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
