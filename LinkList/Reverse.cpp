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
    
     Node *reverseListHelper(Node* listNode){
        Node *prevNode;
        if(listNode == nullptr){
            return nullptr;
        }
        prevNode = reverseListHelper(listNode->next);
        if(prevNode == nullptr){
            head = listNode;
        }
        else{
            prevNode->next = listNode;
        }
        return listNode;
     }

    //Function to reverse a linked list.
     void reverseListRec()
     {
        Node *lastNode;
        lastNode = reverseListHelper(head);
        lastNode->next = nullptr;
     }
	 void reverseListIter()
     {
        struct Node *curr;
        struct Node *prev;
        struct Node *next;
        
        curr = head;
        prev = NULL;
        
        if(head == NULL){
            return ;
        }
        if(head->next == NULL){
            return ;
        }
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
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
	List.insertAtBegining(5);
	List.insertAtBegining(4);
	List.insertAtBegining(3);
	List.insertAtBegining(2);
	List.printList();
	List.reverseListIter();
	List.printList();
	List.reverseListRec();
	List.printList();
	return 0;
}
