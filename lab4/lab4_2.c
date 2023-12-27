#include<stdio.h>

struct node
{
    int wt;
    int val;
    float a;
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
        if (L[i].a >= R[j].a) { 
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
    struct node array[4];
    int w[4] = {1,2,4,5};
    int v[4] = {5,4,8,6};
    int i , ans = 0;
    for(i = 0 ; i < 4 ; i++)
    {
        array[i].wt = w[i];
        array[i].val = v[i];
        array[i].a = (float) v[i] / w[i];
    }

    mergeSort(array , 0 , 3);
    int weigth = 0;
    for(i = 0 ; i < 4 ; i++)
    {
        if(array[i].wt + weigth <= 6)
        {
            ans += array[i].val;
            weigth += array[i].wt;
        }
        else{
            ans += ((6 - weigth) * array[i].a);
            break;
        }
    }

    printf("val = %d",ans);
}