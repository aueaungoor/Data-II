#include<stdio.h>
int size;

struct node
{
    int s;
    int f;
    int num;
};


void select(struct node array[])
{
    int k = 0 , z = 1;

    while(k < size)
    {
        if(array[k].f <= array[k+z].s)
        {
            printf("%d ",array[k].num);
            k+=z;
            z = 1;
        }
        else{
            z++;
        }
    }
}

void merge(struct node arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
   
    struct node L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
   
    i = 0; 
  
   
    j = 0; 
  
    
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i].f <= R[j].f) { 
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
  

void mergeSort(struct node arr[], int l, int r) 
{ 
    if (l < r) { 
        
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int main()
{
    printf("Input number of Activity (n) = ");
    scanf("%d",&size);
    struct node array[size];
    int i;
    for(i = 0 ; i < size ; i++)
    {
        printf("Input Enter S and F of Activity %d = ",i+1);
        scanf("%d %d",&array[i].s,&array[i].f);
        array[i].num = i + 1;
    }
    mergeSort(array,0,size-1); 
    select(array);
    

}