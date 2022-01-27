#include<iostream>
using namespace std;
class circularList{
 /*Structure of the linked list node is as*/
    struct Node {
  		int data;
  		struct Node * next;
		 Node(int x) {
    		  data = x;
    		  next = NULL;
  		}
    };
    struct Node *tail;
    public:
	circularList() {
		tail = nullptr;
	}
    //Function to insert a node at the beginning of the linked list.
     void insertAtBegining(int x) {
       // Your code here
		Node *head;
        Node *newNode = new Node(x);
		if(tail ==  nullptr){
			newNode->next = newNode;
			tail = newNode;
		}
		else{
			head = tail->next; 
        	newNode->next = head;
        	tail->next = newNode;
		}
     }
    
    
    //Function to insert a node at the end of the linked list.
     void insertAtEnd(int x)  {
         Node *newNode = new Node(x);
         Node *head;
		 if(tail ==  nullptr){
			newNode->next = newNode;
		 }
		 else{
			head = tail->next; 
        	tail->next = newNode;
        	newNode->next = head;
        }
		tail = newNode;
     }
	// Insert after val
     void insertAfter(int val,int x) {
		if(tail == nullptr){
			cout<<"Empty List"<<endl;
			return;
		}
		Node *head = tail->next;
		Node *tempNode = head;
        Node *newNode = nullptr;
	 	do{
			if(tempNode->data == val){
        		newNode = new Node(x);
				newNode->next = tempNode->next;
				tempNode->next = newNode;
				if(tempNode == tail){
					tail = newNode;
				}
				break;
			}
			tempNode = tempNode->next;
		}while(tempNode != head);
		if(newNode == nullptr){
			cout<<"insertAfter fail : Node with value "<<val<<"\t"<<"is not present in the list"<<endl;
		}
     }

     void printList(){
		if(tail == nullptr){
			return;
		}
		Node *head = tail->next;
		Node *tempNode = head;
	 	do{
			cout<<tempNode->data;
			tempNode = tempNode->next;
			if(tempNode != head){
				cout<<"->";
			}
		}while(tempNode != head);
		cout<<"\n";
     }
};
int main()
{
	circularList cList;
	cList.insertAtBegining(4);
	cList.insertAtBegining(3);
	cList.insertAtBegining(2);
	cList.printList();
	cList.insertAtEnd(5);
	cList.insertAtEnd(6);
	cList.insertAtEnd(7);
	cList.printList();
	cList.insertAfter(7,8);
	cList.printList();
//	cList.insertAfter(10,8);
	cList.insertAfter(2,1);
	cList.printList();
	cList.insertAfter(8,9);
	cList.printList();
	return 0;
}
