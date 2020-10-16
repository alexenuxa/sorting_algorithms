#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r);
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf(" ");
}
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
void merge(int arr[], int l, int m, int r)
{
  int i,j,k;
  int a1=m-l+1,a2=r-m;
  int t1[a1],t2[a2];
  for(int i=0;i<a1;i++)
    t1[i]=arr[l+i];
  for(int i=0;i<a2;i++)
    t2[i]=arr[m+1+i];
  i=0;
  j=0;
  k=l;
  while(i<a1&&j<a2){
    if(t1[i]<t2[j]){
      arr[k]=t1[i];
      i++;
    }
    else{
      arr[k]=t2[j];
      j++;
    }
    k++;
  }
  while(i<a1){
    arr[k]=t1[i];
    i++;
    k++;
  }
  while(j<a2){
    arr[k]=t2[j];
    j++;
    k++;
  }
}
