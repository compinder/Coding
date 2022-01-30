#include<iostream>
using namespace std;
class LinkList{
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
	LinkList() {
		head = nullptr;
	}

	Node *createNode(int x){
		return new Node(x);
	}
    //Function to insert a node at the beginning of the linked list.
     void insertAtBegining(int x) {
       // Your code here
       Node *newNode = createNode(x);
       newNode->next = head;
       head = newNode;
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
	void addList(LinkList &L2,LinkList &L3){
		int carry = 0;
		int n1,n2,sum;
		Node *itr1;
		Node *itr2;
		Node *newNode;
		Node *headOfFinalList = nullptr;
		Node *tailofFinalList = nullptr;
		reverseListIter();
		L2.reverseListIter();
		itr1 = head;
		itr2 = L2.head;
		
		while(itr1 != nullptr ||
			itr2 != nullptr){
				n1 = (itr1 != nullptr) ? itr1->data : 0;
				n2 = (itr2 != nullptr) ? itr2->data : 0;
				sum = n1+n2+carry;
				carry = sum/10;
				sum = sum%10;
       			newNode = createNode(sum);
				if(headOfFinalList == nullptr){
					headOfFinalList = newNode;
					tailofFinalList = newNode;
				}
				tailofFinalList->next = newNode;
				tailofFinalList = newNode;
				if(itr1 != nullptr){
					itr1 = itr1->next;
				}
				if(itr2 != nullptr){
					itr2 = itr2->next;
				}
		}
		if(carry == 1){
       			newNode = createNode(carry);
				tailofFinalList->next = newNode;
				tailofFinalList = newNode;
		}
		L3.head = headOfFinalList;
		L3.reverseListIter();
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
	LinkList L1,L2,resL;
	LinkList L3,L4;
	L1.insertAtBegining(6);
	L1.insertAtBegining(4);
	L1.insertAtBegining(9);
	L1.insertAtBegining(5);
	L1.insertAtBegining(7);
	L2.insertAtBegining(4);
	L2.insertAtBegining(8);
	cout<<"first List:"<<endl;
	L1.printList();
	cout<<"secondList:"<<endl;
	L2.printList();
	L1.addList(L2,resL);
	cout<<"List representing 75946+84 is 76030: "<<endl;
	resL.printList();
	L3.insertAtBegining(4);
	L3.insertAtBegining(4);
	L4.insertAtBegining(6);
	L4.insertAtBegining(5);
	cout<<"first List:"<<endl;
	L3.printList();
	cout<<"secondList:"<<endl;
	L4.printList();
	L3.addList(L4,resL);
	cout<<"List representing 44+56 is 100: "<<endl;
	resL.printList();
	return 0;
}
