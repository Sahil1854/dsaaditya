//assignment 10
#include <iostream>
using namespace std;
void MaxHeapify(int a[], int i, int n)
{
 int j, temp;
 temp = a[i];
 j = 2*i;

  while (j <= n)
 {
  if (j < n && a[j+1] > a[j])
  j = j+1;

  if (temp > a[j])
   break;
  else if (temp <= a[j])
  {
   a[j/2] = a[j];
   j = 2*j;
  }
 }
 a[j/2] = temp;
 return;
}
void MinHeapify(int a[], int i, int n)
{
 int j, temp;
 temp = a[i];
 j = 2*i;

  while (j <= n)
 {
  if (j < n && a[j+1] < a[j])
  j = j+1;
  if (temp < a[j])
   break;
  else if (temp >= a[j])
  {
   a[j/2] = a[j];
   j = 2*j;
  }
 }
 a[j/2] = temp;
 return;
}
void MaxHeapSort(int a[], int n)
{
 int i, temp;
 for (i = n; i >= 2; i--)
 {
 temp = a[i];
  a[i] = a[1];
  a[1] = temp;
  MaxHeapify(a, 1, i - 1);
 }
}
void MinHeapSort(int a[], int n)
{
 int i, temp;
 for (i = n; i >= 2; i--)
 {
  temp = a[i];
  a[i] = a[1];
  a[1] = temp;
  MinHeapify(a, 1, i - 1);
 }
}
void Build_MaxHeap(int a[], int n)
{
 int i;
 for(i = n/2; i >= 1; i--)
  MaxHeapify(a, i, n);
}
void Build_MinHeap(int a[], int n)
{
 int i;
 for(i = n/2; i >= 1; i--)
  MinHeapify(a, i, n);
}
int main()
{
 int n, i;
 cout<<"\nEnter the number of Students : ";
 cin>>n;
 n++;
 int arr[n];
 for(i = 1; i < n; i++)
 {
  cout<<"Enter the marks :  "<<i<<": ";
  cin>>arr[i];
 }
 Build_MaxHeap(arr, n-1);
 MaxHeapSort(arr, n-1);


 int max,min;
 cout<<"\nSorted Data : ASCENDING : ";
 for (i = 1; i < n; i++)
  cout<<"->"<<arr[i];
 min=arr[1];
 Build_MinHeap(arr, n-1);
   MinHeapSort(arr, n-1);
   cout<<"\nSorted Data : DESCENDING: ";
 max=arr[1];
   for (i = 1; i < n; i++)
     cout<<"->"<<arr[i];
   cout<<"\nMaximum Marks : "<<max<<"\nMinimum marks : "<<min;
 return 0;
}

/* The heap tree is a special balanced binary tree data structure where the root node is compared with its children and arrange accordingly.
A heap is a binary tree-based data structure that satisfies the heap property: the value of each node is greater than or equal to the value of its children. This property makes sure that the root node contains
 the maximum or minimum value (depending on the type of heap), and the values decrease or increase as you move down the tree..

 Min-Heap(child>parent) − Where the value of the root node is less than or equal to either of its children.
 The root node contains the minimum value, and the values increase as you move down the tree.

 Max-Heap(prent>child) − Where the value of the root node is greater than or equal to either of its children
 The root node contains the maximum value, and the values decrease as you move down the tree.
 Common heap operations are:

Insert: Adds a new element to the heap while maintaining the heap property.o(nlogn)
Extract Max/Min: Removes the maximum or minimum element from the heap and returns it.
Heapify: Converts an arbitrary binary tree into a heap.o(n)

Heaps are commonly used to implement priority queues, where elements are retrieved based on their priority (maximum or minimum value).
Heapsort is a sorting algorithm that uses a heap to sort an array in ascending or descending order.
Heaps are used in graph algorithms like Dijkstra’s algorithm and Prim’s algorithm for finding the shortest paths and minimum spanning trees.

Conclusion: This program gives us the knowledge of heap and its types
This C++ program performs sorting on an array of student marks using heap sort algorithm. Here's a breakdown of each function and the main program:

MaxHeapify(int a[], int i, int n): This function is used to maintain the max-heap property. 
It takes an array a[], an index i, and the size of the heap n. 
It compares the element at index i with its children and swaps it with the larger child if necessary, recursively maintaining the max-heap property down the tree.
MinHeapify(int a[], int i, int n): Similar to MaxHeapify, but it maintains the min-heap property by swapping with the smaller child.
MaxHeapSort(int a[], int n): This function sorts the array in ascending order using the max-heap property. It repeatedly swaps the root element (maximum element) with the last element and then restores the heap property by calling MaxHeapify.
MinHeapSort(int a[], int n): Similar to MaxHeapSort, but sorts the array in descending order using the min-heap property.
Build_MaxHeap(int a[], int n): Builds a max heap from the given array by calling MaxHeapify on non-leaf nodes starting from the last non-leaf node.
Build_MinHeap(int a[], int n): Builds a min heap from the given array by calling MinHeapify on non-leaf nodes starting from the last non-leaf node

This program essentially demonstrates the use of heap sort algorithm to sort student marks efficiently in both ascending and descending order.
*/