#include<stdio.h>
void main()
{
    int rs[100],count = 0,f,n,m[10],hit,miss=0,used[10] = {0},frq[10] = {0};
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
        m[i] = rs[i];
        miss++;
    }
    for(int i = f;i<n;i++)
    {
        int j =0;
        for(j =0;j<f;j++)
        {
            if(rs[i] == m[j])
            {
                hit++;
                freq[j]++;
                break;
            }
        }
       if(j == f)
       {
        int min_time = freq[0],min_in = 0;
        for(int k = 1;k<f;k++)
        {
            if(freq[k] < min_time)
            {
                min_time = freq[k];
                min_in = k;
            }
        }
        m[min_in] = rs[i];
        freq[min_in] = 1;
        miss++;
       }
    }
    printf("%d",miss);
}
