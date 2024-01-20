#include <stdio.h>

int size;


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
   
    int L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
   
    i = 0; 
  
   
    j = 0; 
  
    
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
   
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
   
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 


void delete(int *array)
{
    for (int i = 1; i < size; i++)
    {
        array[i] = array[i+1];
    }
    size--;
    
}

void show(int *number)
{
    for (int i = 0; i < size; i++)
    {
       printf("%d ",number[i]);
    }
    printf("\n");
}




void main()
{
    int sum = 0 ,digit = 0;
    int number[5] = {5 , 10 , 20 , 30 ,30};
    size = 5;

    while(size > 1)
    {
        sum += number[0] + number[1];
        printf("sum = %d \n",sum);
        number[0] = number[0] + number[1];
        delete(number);
        mergeSort(number, 0, size - 1);
        show(number);
        
        
    }

    printf("%d",sum);
    
}