#include <stdio.h>
#include <stdio.h>

int n;
struct node
{
    int s ;
    int f;
    int digit;
};

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


void select(struct node head[])
{
    int k = 0 , z = 1;

    while(k < n)
    {
        if(head[k].f <= head[k+z].s)
        {
            printf("%d ",head[k].digit);
            k+=z;
            z=1;
        }
        else{
            z++;
        }
    }
    
}
void main()
{
    printf("Input number of Activity n:");
    scanf("%d",&n);
    struct node head[n];

    for (int i = 0; i < n; i++)
    {
        printf("Input Enter S and F of Activity %d ",i+1);
        scanf("%d %d",&head[i].s , &head[i].f);
        head[i].digit = i+1;
    }

    mergeSort(head, 0, n - 1);
    select(head);
    
    

}