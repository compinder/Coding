#include<iostream>
using namespace std;
class LinkList{
 /*Structure of the linked list node is as*/
    struct Node {
  		int data;
  		struct Node * next;
		 Node(int x) {
    		  data = x;
    		  next = nullptr;
  		}
    };
    struct Node *head ;
    public:
	LinkList() {
		head = nullptr;
	}
    //Function to insert a node at the end of the linked list.
     void insertAtEnd(int x)  {
       // Your code here
       Node *newNode = new Node(x);
       Node *tempNode = head;
       
       if(head == nullptr){
           head = newNode;
	   return;
       }
       while(
	     tempNode->next != nullptr){
               tempNode = tempNode->next;
       }
       tempNode->next = newNode;
     }

	void sortedMergeHelper(Node* &head1, Node* &head2)  
	{
    	// code here
    	Node *dummy = new Node(0);
    	Node *first,*prev;
    
    	first = prev = dummy;
    	while(head1 != nullptr &&
        	head2 != nullptr){
            if(head1->data <= head2->data){
                prev->next = head1;
                head1 = head1->next;
            }
            else{
                prev->next = head2;
                head2 = head2->next;
            }
            prev = prev->next;
    	}
    	if(head1 != nullptr){
        	prev->next = head1;
    	}
    	else if(head2 != nullptr){
        	prev->next = head2;
    	}
    	delete dummy;
    	head1 = first->next;
	}
	void sortedMerge(LinkList &L2){
		sortedMergeHelper(this->head, L2.head);  
	}
    
    void printList(){
		Node *tempNode = head;
	 	while(tempNode != nullptr){
			cout<<tempNode->data;
			tempNode = tempNode->next;
			if(tempNode != nullptr){
				cout<<"->";
			}
		}
		cout<<"\n";
     }
};
int main()
{
	LinkList List1,List2;
	List1.insertAtEnd(5);
	List1.insertAtEnd(10);
	List1.insertAtEnd(15);
	List1.insertAtEnd(40);
	List1.printList();
	List2.insertAtEnd(2);
	List2.insertAtEnd(3);
	List2.insertAtEnd(20);
	List2.printList();
	// Merge List1 and List2. New list will be List1
	List1.sortedMerge(List2);
	List1.printList();
	return 0;
}
