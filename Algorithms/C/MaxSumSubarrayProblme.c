#include <stdio.h>


void printArr(int *arr,int s, int n);
int maxNumber(int a,int b);
int findMaxSubArraySum(int *arr,int s,int e);
int findCss(int *arr,int s,int m,int e);

int main()
{
    int n = 0;
    printf("Enter Size of Array: ");
    scanf("%d", &n);
   

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d Element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max=findMaxSubArraySum(arr,0,n-1);

    printArr(arr, 0,n);


    printf("Sum = %d \n",max);
   


    // printf("Sum=%d",sum);
}

void printArr(int *arr,int s, int n)
{
    if (n != 0)
    {
        printf("[ ");
        for (int i = s; i < n - 1; i++)
        {

            printf("%d ,", arr[i]);
        }
        printf("%d ]\n", arr[n - 1]);
    }
}


int findMaxSubArraySum(int *arr,int s,int e){

    if(s==e){
        return arr[s];
    }
    int m=s+(e-s)/2;

    int lss=findMaxSubArraySum(arr,s,m);
    int rss=findMaxSubArraySum(arr,m+1,e);

    int css=findCss(arr,s,m,e);


    // printf("%d %d %d %d \n",s,e,m,css);
    

    int maxans=maxNumber(maxNumber(lss,rss),css);
   

  

    return maxans;

}


int maxNumber(int a,int b){
    return a>b?a:b;
}

int findCss(int *arr,int s,int m,int e){
        int sum = arr[m];
        int left_sum = sum;
        for (int i = m-1; i >= s; i--) {
            sum = sum + arr[i];
            if (sum > left_sum)
                left_sum = sum;
        }

        //* -2 -7 -4 -1
        // -7
        // -4 
        
        int right_sum = arr[m+1];
        sum = right_sum;
        for (int i = m + 2; i <= e; i++) {
            sum = sum + arr[i];
            if (sum > right_sum)
                right_sum = sum;
        }
 

        return maxNumber(left_sum + right_sum,
                        maxNumber(left_sum, right_sum));
}