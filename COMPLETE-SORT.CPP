#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
	
void shellsort(int ar[99], int n)
{
	int l,i,c,temp,j;
	l=n+1;
	c=l/2;
	while (c!=0)
	{
		for (i=0;i<=n;i++)
		{
			j=i+c;
			while (j<=n)
			{
				if (ar[i]>ar[j])
				{
					temp=ar[i];
					ar[i]=ar[j];
					ar[j]=temp;
				}
				j=j+c;
			}

		}
		c=c/2;
	}
	
	for (i=0;i<=n;i++)
	{
		cout << ar[i] << " ";
	}
}	

void insertion(int ar[99], int n)
{
	int i,j,temp;
	for (i=1;i<=n;i++)
	{
		temp = ar[i];
		j=i-1;
		while (j>=0 && ar[j] > temp)
		{
			ar[j+1]= ar[j];
			j=j-1;
		}
		ar[j+1]=temp;
	}	
	
	for (i=0;i<=n;i++)
	{
		cout << ar[i] << " ";
	}
}

void selection(int ar[99], int n)
{
	int i,j,temp;
	for (i=0;i<=n;i++)
	{
		for (j=i+1;j<=n;j++)
		{
			if (ar[j]<ar[i])
			{
				swap(ar[j],ar[i]);
			}	
		}
	}
	
	for (i=0;i<=n;i++)
	{
		cout << ar[i] << " ";
	}
}

//ani sugod ang merge sort
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

//ani sugod ang quicksort
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}   

//ani ga una ang counting sort
int getMax(int array[], int size) {
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; //the max element from the array
}

void countSort(int *array, int size) {
   int output[size+1];
   int max = getMax(array, size);
   int count[max+1];     //create count array (max+1 number of elements)
   for(int i = 0; i<=max; i++)
      count[i] = 0;     //initialize count array to all zero
   for(int i = 1; i <=size; i++)
      count[array[i]]++;     //increase number count in count array.
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];     //find cumulative frequency
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; //decrease count for same numbers
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i]; //store output array to main array
   }
}

void display(int *array, int size) {
   for(int i = 1; i<=size; i++)
      cout << array[i] << " ";
   cout << endl;
}

//ani mag sugod ang radix
void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];      //radix of decimal number is 10
   for(i = 0; i< max; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;      //find index for pocket array
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}

void display1(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int main(int argc, char** argv) {
	
	char ch[9];
	
	cout << "[a]insertion	[b]selection	[c]shell	[d]mergesort" << endl << "-----------------------------------------------------" << endl << "[e]quicksort	[f]counting	[g]radix" << endl;
	
	cin >> ch;
	
	if (ch[0]=='a')
	{
		int n, arr[99],size,i;
		
		for (size=0; ;size++)
		{
			cin >>arr[size];
			if (cin.get()=='\n')
			{
				break;
			}
		}
		
		cout << "Array before Sorting: ";
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}
		
		cout << endl << "Array after Sorting: ";
		insertion(arr,size);
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}		
	}
	if (ch[0]=='b')
	{
		int n, arr[99],size,i;
		
		for (size=0; ;size++)
		{
			cin >>arr[size];
			if (cin.get()=='\n')
			{
				break;
			}
		}
		
		cout << "Array before Sorting: ";
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}
		
		cout << endl << "Array after Sorting: ";
		selection(arr,size);
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}		
	}
	if (ch[0]=='c')
	{
		int n, arr[99],size,i;
		
		for (size=0; ;size++)
		{
			cin >>arr[size];
			if (cin.get()=='\n')
			{
				break;
			}
		}
		
		cout << "Array before Sorting: ";
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}
		
		cout << endl << "Array after Sorting: ";
		shellsort(arr,size);
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}		
	}
	if (ch[0]=='d')
	{
		int n, arr[99],size,i;
		
		for (size=0; ;size++)
		{
			cin >>arr[size];
			if (cin.get()=='\n')
			{
				break;
			}
		}
		
		cout << "Array before Sorting: ";
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}
		
		cout << endl << "Array after Sorting: ";
		mergeSort(arr,0,size);
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}		
	}
	if (ch[0]=='e')
	{
		int n, arr[99],size,i;
		
		for (size=0; ;size++)
		{
			cin >>arr[size];
			if (cin.get()=='\n')
			{
				break;
			}
		}
		
		cout << "Array before Sorting: ";
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}
		
		cout << endl << "Array after Sorting: ";
		quickSort(arr,0,size);
		for (i=0;i<=size;i++)
		{
			cout << arr[i] << " ";
		}			
	}
	if (ch[0]=='f')
	{
		int n;
	   cout << "Enter the number of elements: ";
	   cin >> n;
	   int arr[n+1];       //create an array with given number of elements
	   cout << "Enter elements:" << endl;
	   for(int i = 1; i<=n; i++) {
	      cin >> arr[i];
	   }
	   cout << "Array before Sorting: ";
	   display(arr, n);
	   countSort(arr, n);
	   cout << "Array after Sorting: ";
	   display(arr, n);
	}
	if (ch[0]=='g')
	{
		int n, max;
	   cout << "Enter the number of elements: ";
	   cin >> n;
	   cout << "Enter the maximum digit of elements: ";
	   cin >> max;
	   int arr[n]; //create an array with given number of elements
	   cout << "Enter elements:" << endl;
	   for(int i = 0; i<n; i++) {
	      cin >> arr[i];
	   }
	   cout << "Data before Sorting: ";
	   display1(arr, n);
	   radixSort(arr, n, max);
	   cout << "Data after Sorting: ";
	   display1(arr, n);		
	}
	return 0;
}
