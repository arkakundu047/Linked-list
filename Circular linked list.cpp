#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int val){
		data= val;
		next=NULL;
	}
};
void InsertAtHead(node* &head,int val){
	node* n = new node(val);
		if(head==NULL){
		n->next = n;
		head = n;
		return;
	}
	node * temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = n;
	n->next=head;
	head=n;
}

void InsertAtTail(node* &head , int val){
	node* n = new node(val);
	if(head==NULL){
		n->next=n;
		head = n;
		return;
		
	}

	node* temp = head;

	while(temp->next!=head){
		temp = temp->next;
	}
	temp->next= n;
	n->next = head;
	head=n;
	
}
void deleteAtHead(node* &head){
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp ->next;
	}
	node* todelete = head;
	temp->next = head->next;
	head=head->next;
	delete todelete ;
}

void deletion(node* &head,int pos){
	if(pos==1){
		deleteAtHead(head);
		}
	node* temp = head;
	int count = 1;
	while(count!=pos-1){
		temp = temp->next;
		count++;
	}
	node *todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
	
}
void display(node* head){
	node* temp =head;
	do{
		cout<<temp->data<<"->";
		temp = temp->next;
	}while(temp!=head);
	cout<<"NULL"<<endl;
}

int main(){
	node* head=NULL;
	cout<<"enter the no of nodes of linked list"<<endl;
	int n=0;
	cin >> n;
	int val;
	for(int i=1;i<=n;i++){
		cout<<"the "<<i<<"th element is:"<<" ";
		cin>>val;
		InsertAtTail(head,val);
	}
	cout<<"the linked list is "<<endl;
	display(head);
	cout<<"enter the position to be deleted "<<endl;
	int pos;
	cin >> pos;
	deletion(head,pos);
	cout<<"after deletion the linked list is"<<endl;
	display(head);
}
