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
	return 0;
}
