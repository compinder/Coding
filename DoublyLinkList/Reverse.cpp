#include<iostream>
using namespace std;

class doublyList {
	struct Node
	{
  		int data;
  		struct Node *next;
  		struct Node *prev;
  		Node(int x)
  		{
      		data = x;
      		next = prev = nullptr;
  		}
	};
	struct Node *head;
public:
	doublyList(){
		head = nullptr;
	}
	void insertNode(int data);
	void printList();
	void reverseList();
	void reverseListRec();
	void reverseListRecHelper(Node *);
};

void doublyList::insertNode(int data){
	if(head == nullptr){
		head = new Node(data);
		return;
	}
	Node *newNode;
	newNode = new Node(data);
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}



void doublyList::reverseList(){
    Node *currNode = head;
    Node *tempNode,*prevNode = nullptr;
    
    while(currNode != nullptr){
        tempNode = currNode->next;
        currNode->next = currNode->prev;
        currNode->prev = tempNode;
        prevNode = currNode;
        currNode = currNode->prev;
    }
    head = prevNode;
}

void doublyList::reverseListRecHelper(Node *currNode){
    Node *tempNode,*prevNode = nullptr;
    
    tempNode = currNode->next;
    currNode->next = currNode->prev;
    currNode->prev = tempNode;
	if(currNode->prev != nullptr){
		reverseListRecHelper(currNode->prev);
	}
	else{  // control will come here only for the last node of the original list
		head = currNode;
	}
}
void doublyList::reverseListRec(){
	if(head != nullptr){
		reverseListRecHelper(head);
	}
}


void doublyList::printList(){
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

int main(){
	doublyList dList;
	dList.insertNode(2);
	dList.insertNode(3);
	dList.insertNode(4);
	dList.insertNode(5);
	dList.printList();
	dList.reverseList();
	dList.printList();
	dList.reverseListRec();
	dList.printList();
	return 0;
}
