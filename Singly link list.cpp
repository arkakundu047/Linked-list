#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int val){
		data = val;
		next = NULL;
	}
};
void InsertAtTail (node* &head , int val){
	node* n = new node(val);
	if(head ==NULL){
		head = n;
		return ;
	}
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp-> next;
	}
	temp->next = n;
}
void InsertAtPosition(node* &head,int p,int val){
	node* n = new node(val);
	if(p==1){
		n->next = head;
		head = n;
		return ;
		
	}
	node* temp = head;
	for(int i=0;i<p-1;i++){
		temp=temp->next;
		
	}
	n->next=temp->next;
	temp->next=n;
}
void InsertAtHead(node* &head,int val){
	node* n = new node(val);
	n->next = head;
	head=n;
}
void display(node* head){
	node *temp= head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp= temp->next;
	}
	cout<<"NULL"<<endl;
	
}
void deletion(node* &head , int val){
	node* temp = head;
	while(temp->next->data!=val){
		temp = temp->next;
	}
	node *todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}

int main(){
	node* head = NULL;
	cout<<"Enter the element of nodes"<<" ";
	
	int count = 0,val,p;
	cin>>count;
	for(int i=1;i<count+1;i++){
		cout<<"enter the "<<i<<"th element"<<" ";
		cin >> val;
		InsertAtTail(head,val);
	}
	
/*	InsertAtTail(head,2);
	InsertAtTail(head,3);
	InsertAtTail(head,4);
	InsertAtTail(head,5);*/
	display(head);
	cout<<"enter the element to be inserted at head"<<endl;
	cin>>val;
	InsertAtHead(head,val);
	cout<<"after insertion linked list is"<<endl;
	display(head);
	cout<<"enter the element to be inserted at position"<<endl;
	cin>>p;
	cout<<"enter the element to be inserted"<<endl;
	cin>>val;
	InsertAtPosition(head,p,val);
	cout<<"after insertion linked list is "<<endl;
	display(head);
	cout<<"enter the element to be deleted"<<endl;
	cin>>val;
	deletion(head,val);
	cout<<"after deletion the linked list is "<<endl;
	display(head);
	return 0;
}
