#include<iostream>
using namespace std;
struct node //Create a node 
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
	 	head=NULL; //Initialize head as NULL
	 }
	 void bbsort2();	
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
void LL:: bbsort2()
{
	int flag=1;
	for(node* i=head;i&&flag;i=i->next) //Start from the head and traverse till the tail. Also check is the previous iteration had any switches. If not, Done!
	{
	 flag=0; //Reset flag
	 for(node* j=head;j->next;j=j->next) // Start from the head and traverse till the one before the tail.
	 {
	 	if(((j->next)->data)<(j->data)) // If the next ones data is less then this one, swap them.
		{
			int temp=(j->next)->data;
			(j->next)->data=j->data;
			j->data=temp;
			flag++;
		}  
	 }
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
	int a[10]={1,4,5,6,3,2,9,10,89,0};
	bbsort1(a,10);
	for(int i=0;i<10;i++) cout<<a[i]<<" ";
	cout<<"\n\n\n";
	ob.push(0);
	ob.push(-2);
	ob.push(30);
	ob.push(115);
	ob.push(4332);
	ob.push(3126);
	ob.push(7432);
	ob.bbsort2();
	ob.print();
	return 1;
}
