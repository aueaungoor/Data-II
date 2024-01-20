#include <stdio.h>


void sort(int ans[])
{
    for (int i = 0; i < 6; i++)
    {
         for (int i = 0; i < 6; i++)
        {
            if(ans[i] >= ans[i+1])
            {
                int temp = ans[i];
                ans[i] = ans[i+1];
                ans[i+1] = temp;
            }
        }
    }  
}
void main()
{

    int ans[] = {5 , 5 , 1, 2, 2 , 7};
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",ans[i]);
    }
    
    sort(ans);
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",ans[i]);
    }
}