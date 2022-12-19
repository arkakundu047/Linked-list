#include<iostream>
using namespace std;
class node{
	public :
		int data;
		node* next;
		node* prev;
	node(int val){
		data=val;
		next=NULL;
		prev=NULL;
	}
};
void InsertAtHead(node* &head,int val){
	node* n = new node( val);
	n->next = head;
	if(head!=NULL){
		head->prev=n;
		
	} 
		head = n;
}

void InsertAtTail(node* &head,int val){
	if(head==NULL){
		InsertAtHead(head,val);
		return;
	}
	node* n= new node(val);
	node* temp =head;
	while(temp->next!=NULL){
		temp= temp->next;
	}
	temp->next = n;
	n->prev = temp;
}

void deleteAtHead(node* &head){
	node* todelete= head;
	head= head->next;
	head->prev=NULL;
	delete todelete;
}

void deletion(node* &head,int pos){
	node* temp = head;
	int count = 1;
	while(temp!=NULL&&pos!=count){
		temp= temp->next;
		count++;
	}
	temp->prev->next = temp->next;
	if(temp->next!=NULL){
			temp->next->prev= temp->prev;
	
	}
	delete temp;
	
}


void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
		}
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
	cout<<"enter the position of element to be deleted"<<endl;
	int pos;
	cin>>pos;
	deletion(head,pos);
	cout<<"after deletion linked list is "<<endl;
	display(head);
	deleteAtHead(head);
	cout<<"after deleting first element the linked list is"<<endl;
	display(head);
}
