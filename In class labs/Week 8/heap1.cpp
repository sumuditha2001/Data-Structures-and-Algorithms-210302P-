#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//function to swap two numbers
void swap(int *p,int *q){
    int tempory=*p;
    *p=*q;
    *q=tempory;
}
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int maximum=root;
   int left=2*root +1;   //finding the left and right child of the given node
   int right=2*root +2;
   if(left<n && arr[left]>=arr[root]){   //if left child is greater than the given node select that as the maximum
      maximum=left;
   }else{
      maximum=root;  //else select the given node as the maximum 
   }if(right<n && arr[right]>=arr[maximum]){  //if right child is greater than the selected maximum set hat as the maximum
      maximum=right;
   }
   if(root != maximum){   //doing the swap if the given node is not the maximum
      swap(&arr[root],&arr[maximum]);
      heapify(arr,n,maximum);
   }     
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   for(int i=n/2 -1;i>=0;i--){  //building the heap by heapifying the nodes with children in bottom to top approach
      heapify(arr,n,i);
   }
   for(int i=n-1;i>=0;i--){  //creating the sorted array
      swap(&arr[i],&arr[0]);
      heapify(arr,i,0);
   }     
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
   int n;  //variable for the size of the array
   string IntegerList;    //variable for taking a line as the input
   cout<<"Enter the size of the array "<<endl;
   cin>>n;   //taking the array size as an input
   cin.ignore();
   if (n<0){
      cout<<"invalid size for the array";  //terminate the program if user inputs invalid data
      return -1;
   }
   cout<<"Enter the array as space seperated integers"<<endl;
   getline(cin,IntegerList);   ///taking the space seperated line as an input
   stringstream ss(IntegerList);
   int arr[n];  //creating an empty array with the above size
   int i = 0;
   while (ss >> arr[i] && i < n) {   //adding the elements into the array from the space seperated line
        i++;
   }
   
   cout<<"Input array"<<endl;  //printing the output
   displayArray(arr,n);
  
   heapSort(arr, n);
   cout << "Sorted array"<<endl;
   displayArray(arr, n);
}