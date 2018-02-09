#include<iostream>
#include<cstdlib>
using namespace std;
void append(int *a,int *arr1,int *arr2,int n1,int n2)
{
	int i=0;
	while(i<n1) 
	{
		a[i]=arr1[i];
		i++;
	}
	i=0;
	while(i<n2)
	{
		a[n1+i]=arr2[i];
		i++;
	}
}
void quick1(int *a,int n)
{
	int pivot = n/2;
	if(pivot)
	{
		int arr1[100],arr2[100],n1=1,n2=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]<a[pivot]) arr1[n1++]=a[i];
			else if(i!=pivot) arr2[n2++]=a[i];
		}
		arr1[0]=a[pivot];
		quick1(arr1,n1);
		quick1(arr2,n2);
		append(a,arr1,arr2,n1,n2);
	}
}
void bbsort1(int* a,int n)
{
	int flag=1;
	for(int i=0;i<n&&flag;i++) // Start at 0 and go till the end. If there were no iterations in the previous one, done!
	{
	 flag=0;
	 for(int j=0;j<n-1;j++) //Start at 0 and go till the one before the end
	 {
	 	if(a[j+1]<a[j]) // If the next element is smaller, swap
		{
			int temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
			flag++;
		}  
	 }
	}
}
int main() //Call and initialize stuff to see if everything works.
{
	int a[100];
	int size = sizeof(a)/sizeof(int);
	for(int i=0;i<size;i++) a[i] = rand()%1000;
	//bbsort1(a,size);
	quick1(a,size);
	for(int i=0;i<size;i++) cout<<a[i]<<"\n";
	return 1;
}
