#include<stdio.h>
//knapsack problem using Brute Force Approach
int getMaxVal(int n, int w[], int v[], int c, int i)
{
int vin, vex;
if(i==n || c <=0)
    {
            return 0;
    }
    if(w[i] <= c)
    {
            vin = getMaxVal(n, w, v, c-w[i], i+1)+ v[i];
            vex= getMaxVal(n, w, v, c , i+1);
            if(vin> vex)
            {
                   return vin;
            }
            else
                   return vex;             

    }
    else
    {
        vex = getMaxVal(n, w, v, c, i+1);
        return vex;
    }
}
int main(int argc, char *argv[])
 {
int n = 5 ;
int c = 12, value;
int w[100] = {2,4,3,5,5};
int v[100]={3,4,1,2,6};
value = getMaxVal(n, w, v, c, 0);
printf("The final value = %d", value);
return 0;
 }
