#include<iostream>
using namespace std;
class circularList{
 /*Structure of the linked list node is as*/
   public:
    struct Node {
  		int data;
  		struct Node * next;
		 Node(int x) {
    		  data = x;
    		  next = NULL;
  		}
    };
    struct Node *tail;
	circularList() {
		tail = nullptr;
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

     void printList(Node *t){
		if(t == nullptr){
			return;
		}
		Node *head = t->next;
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
	// If there are odd nodes in the given circular linked list then the first result list has 1 more node than the second result list.
	 void splitList(struct Node **t1, struct Node **t2){
		if(tail == nullptr){
			return;
		}
		struct Node *slow = tail->next;
		struct Node *fast = tail->next;	
		Node *head = tail->next;
		Node *head2;

		//List has only one node
		if(tail->next == tail){
			return;
		}
		/* fast->next becomes equal to head for odd number of nodes and 
			fast->next->next for even number of nodes */
		while(fast->next != head &&
			fast->next->next != head){
			slow = slow->next;
			fast = fast->next->next;
		}
		*t1 = slow;
		head2 = slow->next;
		(*t1)->next = tail->next;
		*t2 = tail;
		tail->next = head2;
	 }
};
int main()
{
	circularList cList;
	struct circularList::Node* tail1;
	struct circularList::Node* tail2;
	tail1 = nullptr;
	tail2 = nullptr;
	cList.insertAtEnd(1);
	cList.insertAtEnd(2);
	cList.insertAtEnd(3);
	cList.insertAtEnd(4);
	cList.insertAtEnd(5);
	cList.insertAtEnd(6);
	cList.insertAtEnd(7);
	cList.insertAtEnd(8);
	cList.insertAtEnd(9);
	cout<<"original list:"<<endl;
	cList.printList(cList.tail);
	cList.splitList(&tail1,&tail2);
	cout<<"List1 after split"<< endl;
	cList.printList(tail1);
	cout<<"List2 after split"<< endl;
	cList.printList(tail2);
	return 0;
}
