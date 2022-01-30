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
	Node* createNode(int data){
		return new Node(data);
	}
    void sortedInsert(int data)
    {
       Node *itr;
       Node *newNode;
       Node *prev = nullptr;
	   
	   newNode = createNode(data);
       // List is empty
       if(tail == nullptr){
           newNode->next = newNode;
           tail = newNode;
       }
       // Insert at 1st position
       else if(tail->next->data >= data){
           newNode->next = tail->next;
		   tail->next = newNode;;
       }
       else{
		   itr = tail->next;	
           do{
              prev = itr; 
              itr = itr->next;
           }while(itr != tail->next &&
                  itr->data < data );
		   if(itr == tail->next){
				tail = newNode;
		   }
           newNode->next = itr;
           prev->next = newNode;
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
	cList.sortedInsert(10);
	cList.sortedInsert(9);
	cList.sortedInsert(6);
	cList.printList();
	cList.sortedInsert(5);
	cList.printList();
	cList.sortedInsert(8);
	cList.printList();
	cList.sortedInsert(10);
	cList.printList();
	cList.sortedInsert(12);
	cList.printList();
	return 0;
}
