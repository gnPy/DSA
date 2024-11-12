#include<stdio.h>
void main()
{
    int rs[100],count = 0,f,n,m[10],hit,miss=0,used[10] = {0};
    printf("Enter the no of frames : ");
    scanf("%d",&f);
    printf("Enter the length of reference string ");
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        scanf("%d",&rs[i]); 
    }
    for(int i =0;i<f;i++)
    {
        m[i] = -1;
    }
    for(int i = 0;i<n;i++)
    {
        int j =0;
        for(j =0;j<f;j++)
        {
            if(rs[i] == m[j])
            {
                hit++;
                used[j] = i+1;
                break;
            }
        }
       if(j == f)
       {
        int min_time = used[0],min_in = 0;
        for(int k = 1;k<f;k++)
        {
            if(used[k] < min_time)
            {
                min_time = used[k];
                min_in = k;
            }
        }
        m[min_in] = rs[i];
        used[min_in] = i+1;
        miss++;
       }
        for(int k =0;k<f;k++)
        {
            printf("%d\t",m[k]);
        }
        if(j == f)
        {
            printf("Page Fault"); 
        }
        printf("\n");
    }
    printf("%d",miss);
}
