#include <stdio.h>
#include <time.h>
void merge(int[],int,int,int);
void mergesort(int[],int,int);

void mergesort(int a[25],int low, int high)
{
    if(low<high)
    {
        int mid;
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[25],int low,int mid,int high)
{
    int h,i,j,k,b[25];
    h=low;
    i=low;
    j=mid+1;
    while((h<=mid)&&(j<=high))
    {
        if(a[h]<a[j])
        {
            b[i]=a[h];
            h++;
        }
        else{
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        while(j<=high)
        {
            b[i]=a[j];
            j++;
            i++;
        }
    }
    else
    {
        while(h<=mid)
        {
            b[i]=a[h];
            i++;
            h++;
            }
    }
    for(k=low;k<=high;k++)
    {
        a[k]=b[k];
    }
}
int main()
{
    int a[25],i,n;
    clock_t st,et;
    double ts;
    printf("Enter the number of elements to be sorted:");
    scanf("%d",&n);
    printf("Enter the elements to be sorted:");
    for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    st = clock();
    printf("\n st = %d",&st);
    mergesort(a,0,n-1);
    et=clock();
    printf("\n et = %d",&et);
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    printf("\n CLOCKS_PER_SEC = %d",CLOCKS_PER_SEC);
    printf("\nThe elements after sorting are:");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n The time taken is %e",ts);
    return 0;


}