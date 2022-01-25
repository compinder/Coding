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
	void addNode(int pos, int data);
	void deleteNode(int x);
	void printList();
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
// add node after position pos, consider first node as pos=0
void doublyList::addNode(int pos, int data){
    Node *nNode;
	Node *tempNode = head;
    nNode = new Node(data);
    // First node is at position 0
    while(tempNode != nullptr &&
			pos != 0){
        tempNode = tempNode->next;
        pos--;
    }
	if(tempNode == nullptr){
		cout<<"Insert position not found"<<endl;
		return;
	}

    nNode->next = tempNode->next;
	if(tempNode->next != nullptr &&
		tempNode->next->prev != nullptr){
			tempNode->next->prev = nNode;
	}
    nNode->prev = tempNode;
    tempNode->next = nNode;
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
void doublyList::deleteNode(int x)
{
	Node *deleteNode = head;
    int pos = 1;
        
    // First node is at position 1
    while(pos != x){
         deleteNode = deleteNode->next;
         pos++;
    }
        // First Node
    if(deleteNode == head){
        head = head->next;
           head->prev = nullptr;
    }
        // last NOde
    else if(deleteNode->next == nullptr){
        deleteNode->prev->next = nullptr;
    }
        // some node in between
    else{
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;
    }
    delete deleteNode;
}


int main(){
	doublyList dList;
	dList.insertNode(2);
	dList.insertNode(3);
	dList.insertNode(4);
	dList.printList();
	dList.addNode(1,5);
	dList.printList();
	dList.addNode(2,6);
	dList.printList();
	dList.addNode(0,0);
	dList.printList();
	dList.addNode(5,10);
	dList.printList();
	dList.deleteNode(1); // first node
	dList.printList();
	dList.deleteNode(6);  // last node
	dList.printList();
	dList.deleteNode(3);  // middle node
	dList.printList();
	return 0;
}
