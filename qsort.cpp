#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
struct node //Initialize node.
{
	int data;
	node * next;
};
class LL
{
	public:
	 node* head;	
	 LL()
	 {
	 	head=NULL;
		//Initialize head as NULL
	 }
	 void quick2();	
	 void push(int data) //Add elements to the LL
	 {
	 	node* temp=new node;
	 	temp->data=data;
	 	temp->next=NULL;
	 	if(head==NULL) head=temp; //If no LL, then make temp the head 
	 	else 
	 	{
	 		temp->next=head; //If LL exists, point this to the previous head and then make this the head
			head=temp;	
		}
	 }
	 void print() //Print the stuff out. Duh.
	 {
	 	node* temp=head;
	 	while(temp)
	 	{
	 		cout<<temp->data<<" ";
	 		temp=temp->next;
		}
	 }
}ob;
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
void LL::quick2()
{
	node* temp=head;
	int a[100];
	int i=0;
	for(;temp;i++)
	{
		a[i]=temp->data;
		temp=temp->next;
	}
	quick1(a,i);
	head=NULL;
	for(int j=0;j<i;j++) push(a[j]);
	print();
}
int main()
{
	int a[]={1,8,5,6,6,4,6,-1};
	int size = sizeof(a)/sizeof(int);
	quick1(a,size);
	for(int i=0;i<size;i++) cout<<a[i]<<" ";
	cout<<"\n\n\n\n";
	ob.push(0);
	ob.push(-2);
	ob.push(30);
	ob.push(115);
	ob.push(4332);
	ob.push(3126);
	ob.push(7432);
	ob.quick2();
	return 0;
}
