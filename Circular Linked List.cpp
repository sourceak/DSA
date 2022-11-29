#include <iostream>
using namespace std;

class Node{
public:
	int key, data;
	Node *next;
	Node *previous;

	Node():key(0),data(0),next(NULL),previous(NULL){}
	Node(int k,int d):key(k),data(d),next(NULL),previous(NULL){}
};

class CircularLinkedList{
public:
	Node *head;
	Node *last;

	CircularLinkedList():head(NULL),last(NULL){}
	CircularLinkedList(Node* h):head(NULL){
		head = h; //the first node is the head=
		last = h;
	}

	Node* nodeExists(int k){
		Node* ptr2 = last;

		Node* temp = NULL;
		while(ptr2!=NULL){
			if(ptr2->key==k){
				temp=ptr2;
			}
			ptr2=ptr2->previous;
		}
		return temp;
	}

	void appendNode(Node* n){
		Node* ptr = head;
		Node* ptr2 = last;

		if(nodeExists(n->key)!=NULL){
			cout<<"Node with key "<<n->key<<" already exists"<<endl<<endl;
		}else{
			if(head==NULL){
				head=n;
				last=n;
			}else if(ptr==ptr2){
				n->previous=head;
				ptr->next=n;
				last=n;
				n->next=head;
			}else{
				ptr2->next=n;
				n->previous=last;
				last=n;
				n->next=head;
			}
			cout<<"key:"<<n->key<<" data:"<<n->data<<" previous:"<<n->previous<<" next:"<<n->next<<" appended"<<endl<<endl;
		}
	}

	void prependNode(Node* n){
		Node* ptr = head;
		Node* ptr2 = last;

		if(nodeExists(n->key)!=NULL){
			cout<<"Node with key "<<n->key<<" already exists"<<endl<<endl;
		}else{
			ptr2->next=n;
			ptr->previous=n;
			n->next=head;
			head=n;
			cout<<"key:"<<n->key<<" data:"<<n->data<<" previous:"<<n->previous<<" next:"<<n->next<<" prepend"<<endl<<endl;
		}
	}

	void insertAfterNode(int k, Node* n){
		Node* ptr = nodeExists(k);
		Node* check = nodeExists(n->key);
		Node* temp = NULL;
		Node* ptr2 = last;

		if(check==NULL){
			if(ptr==NULL){
				cout<<"No node with key "<<k<<" exists"<<endl<<endl;
			}else if(ptr!=last){
				temp=ptr;
				n->previous=temp;
				ptr=ptr->next;
				n->next=ptr;
				temp->next=n;
				ptr->previous=n;
				cout<<"key:"<<n->key<<" data:"<<n->data<<" previous:"<<n->previous<<" next:"<<n->next<<" inserted between keys "<<temp->key<<" & "<<ptr->key<<endl<<endl;
			}else if(ptr==last){
				ptr2->next=n;
				n->previous=last;
				last=n;
				n->next=head;
				cout<<"key:"<<n->key<<" data:"<<n->data<<" previous:"<<n->previous<<" next:"<<n->next<<" appended"<<endl<<endl;
			}
		}else{
			cout<<"Node with key "<<n->key<<" already exists"<<endl<<endl;
		}
	}

	void updateNode(int k, int val){
		Node* ptr = nodeExists(k);

		if(ptr!=NULL){
			ptr->data=val;
			cout<<"key:"<<ptr->key<<" data:"<<ptr->data<<" previous:"<<ptr->previous<<" next:"<<ptr->next<<" updated"<<endl<<endl;
		}else{
			cout<<"No node with key "<<k<<" exists"<<endl<<endl;
		}
	}

	void deleteNode(int k){
		Node *after = NULL;
		Node *prev = NULL;
		Node* current = nodeExists(k);

		if(current!=NULL){
			if(head->key==k){
				head=head->next;
				head->previous=NULL;
				last->next=head;
			}else if(current==last){
				prev=last->previous;
				prev->next=head;
				last=prev;
			}else{
				prev=current->previous;
				after=current->next;
				after->previous=prev;
				prev->next=after;
			}
			cout<<"key:"<<current->key<<" data:"<<current->data<<" previous:"<<current->previous<<" next:"<<current->next<<" deleted"<<endl<<endl;
		}else{
			cout<<"No Node with key "<<k<<" exists"<<endl<<endl;
		}
	}

	void displayNodes(){
		Node* ptr = head;
		cout<<"head: "<<head<<endl;

		while(ptr->next!=head){
			cout<<"key:"<<ptr->key<<" data:"<<ptr->data<<" previous:"<<ptr->previous<<" next:"<<ptr->next<<endl<<endl;
			//cout<<ptr->key<<" "<<ptr<<endl;
			ptr=ptr->next;
		}
		if(ptr->next==head)
			cout<<"key:"<<ptr->key<<" data:"<<ptr->data<<" previous:"<<ptr->previous<<" next:"<<ptr->next<<endl<<endl;
	}
};

int main(){

	CircularLinkedList c;
	int option, key, data, k1;

	do{
		cout<<"What operation would you like to perform? Select Option Number. Enter 0 to exit."<<endl;
		cout<<"1. Append Node()"<<endl;
		cout<<"2. Prepend Node()"<<endl;
		cout<<"3. Insert After Node()"<<endl;
		cout<<"4. Update Node()"<<endl;
		cout<<"5. Delete Node()"<<endl;
		cout<<"6. Display Node()"<<endl<<endl;

		cout<<"Enter option # >> "<<flush;
		cin>>option;
		cout<<endl;
		Node *n1 = new Node();

		switch(option){
		case 0:
			break;
		case 1:
			cout<<"Append Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>key;
			n1->key=key;
			cout<<"Enter data: "<<flush;
			cin>>data;
			n1->data=data;
			c.appendNode(n1);
			break;
		case 2:
			cout<<"Prepend Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>key;
			n1->key=key;
			cout<<"Enter data: "<<flush;
			cin>>data;
			n1->data=data;
			c.prependNode(n1);
			break;
		case 3:
			cout<<"Insert Function Called"<<endl;
			cout<<"Enter Node to Insert After: "<<flush;
			cin>>k1;
			cout<<"Enter key: "<<flush;
			cin>>key;
			n1->key=key;
			cout<<"Enter data: "<<flush;
			cin>>data;
			n1->data=data;
			c.insertAfterNode(k1, n1);
			break;
		case 4:
			cout<<"Update Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>k1;
			cout<<"Enter data: "<<flush;
			cin>>data;
			c.updateNode(k1, data);
			break;
		case 5:
			cout<<"Delete Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>k1;
			c.deleteNode(k1);
			break;
		case 6:
			cout<<"Display Function Called"<<endl;
			c.displayNodes();
			break;
		case 7:
			cout<<"Exist Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>k1;
			cout<<c.nodeExists(k1)<<endl;
			break;
		default:
			cout<<"Enter Proper Number"<<endl;
		}
	}while(option!=0);

	return 0;
}









