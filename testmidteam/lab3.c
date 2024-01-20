#include <stdio.h>
#include <conio.h>  
#include <time.h>
#include <stdlib.h>

void main()
{
    int ans[2];
    int n;
    srand((unsigned)time(0)); 
    printf("Enter n:");
    scanf("%d",&n);

     int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] =  rand() % 100  +1; 
        printf("%d\n",a[i]);
    }
    ans[0] = 101;
    ans[1] = 101;
    
    for (int i = 0; i < n; i++)
    {
        if(a[i] < ans[0])
        {
            if(a[i] < ans[1])
            {
                ans[0] = ans[1];
                ans[1] = a[i];
            }
            else{
                ans[0] = a[i];
            }
        }
    }

    printf("%d",ans[0]);
    
    


}