#include<iostream>
using namespace std;
class Solution{
 /*Structure of the linked list node is as*/
    struct Node {
  		int data;
  		struct Node * next;
		 Node(int x) {
    		  data = x;
    		  next = NULL;
  		}
    };
    struct Node *head ;
    public:
	Solution() {
		head = nullptr;
	}
    //Function to insert a node at the beginning of the linked list.
     void insertAtBegining(int x) {
       // Your code here
       Node *newNode = new Node(x);
       newNode->next = head;
       head = newNode;
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
	 void deleteNodeByVal(int x){
		Node *tempNode = head;
		Node *prevNode = nullptr;
	 	while(tempNode != nullptr){
			if(tempNode->data == x){
				break;
			}
			prevNode = tempNode;
			tempNode = tempNode->next;
		}
		if(tempNode == nullptr){
			cout<<"Node not found"<<endl;
			return;
		}
		// check if it is head node
		if(prevNode == nullptr){
			tempNode = head;
			head = head->next;
		}
		else{
			prevNode->next = tempNode->next;
		}
		delete(tempNode);
		
	 }
	 void deleteNodeByPos(int x){
    	Node *tempNode = head;
    	Node *prevNode = nullptr;
    	while(tempNode != nullptr &&
        	x != 1){
        	x--;
        	prevNode = tempNode;
        	tempNode = tempNode->next;
    	}
	// Node not found
    	if(tempNode == nullptr){
        	return ;
    	}
    // check if it is head node
    	if(prevNode == nullptr){
            tempNode = head;
            head = head->next;
    	}
    	else{
        	prevNode->next = tempNode->next;
    	}
    	delete(tempNode);
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
	Solution List;
	List.insertAtBegining(4);
	List.insertAtBegining(3);
	List.insertAtBegining(2);
	List.insertAtEnd(5);
	List.insertAtEnd(6);
	List.printList();
	List.deleteNodeByVal(6);
	List.printList();
	List.deleteNodeByVal(2);
	List.printList();
	List.deleteNodeByVal(4);
	List.printList();
	List.insertAtEnd(6);
	List.insertAtEnd(7);
	List.printList();
	List.deleteNodeByPos(4);
	List.printList();
	List.deleteNodeByPos(1);
	List.printList();
	return 0;
}
