#include<iostream>
#include<cstdlib>

using namespace std;
int Partition(int [],int ,int );
void R_Quicksort(int [],int ,int );
int R_Partition(int [],int,int );
int comparisons=0;

int main()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements in the array: "<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    cout<<"\nSORTING USING RANDOMISED QUICK SORT "<<endl;
    int p=1,r=n;

    R_Quicksort(a,p,r);

   cout<<"SORTED FORM: "<<endl;
   for(int i=1;i<=n;i++)
   {
       cout<<"A["<<i<<"]="<<a[i]<<endl;
   }

   cout<<"\nSORTED ARRAY -> ";
   cout<<" { ";
   for(int i=1;i<=n;i++)
   {
      cout<<a[i] << "  ";
   }
   cout<<"}";
   cout<<"\nTOTAL NUMBER OF COMPARISONS: "<<comparisons;
   return 0;
}

void R_Quicksort(int a[],int p,int r)
    {
        int q;
        if(p<r)
        {
         q=R_Partition(a,p,r);
         R_Quicksort(a,p,q-1);
         R_Quicksort(a,q+1,r);
        }
    }

 int R_Partition(int a[],int p,int r)
 {
        int i=p+rand()%(r-p+1);
        int temp;
        temp=a[r];
        a[r]=a[i];
        a[i]=temp;
        return Partition(a,p,r);
  }

 int Partition(int a[],int p,int r)
 {
        int temp,temp1;
        int x=a[r];
        int i=p-1;
        for(int j=p;j<=r-1;j++)
        {
            comparisons++;
            if(a[j]<=x)
            {
                i=i+1;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp1=a[i+1];
        a[i+1]=a[r];
        a[r]=temp1;
        return i+1;

  }
