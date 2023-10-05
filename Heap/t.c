#include<stdio.h>
#define max 50

void bottomUp(int h[],int n)
{
    int p,i,j,key;
    for(p=(n-1)/2;p>=0;p--)
    {
        j=p;
        key=h[j];
        i=2*j+1;
        while(i<=n)
        {
            if(i+1<=n)
                if(h[i]<h[i+1])
                    i++;
            if(key<h[i])
            {
                h[j]=h[i];
                j=i;
                i=2*j+1;
            }
            else
                break;
        }
        h[j]=key;
    }
}
int main()
{
    int h[max],n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&h[i]);
    printf("Before heapify: ");
    for(i=0;i<n;i++)
        printf("%d ",h[i]);
    printf("\n");
    bottomUp(h,n-1);
    printf("After heapify: ");
    for(i=0;i<n;i++)
        printf("%d ",h[i]);
    printf("\n");
    return 0;
}