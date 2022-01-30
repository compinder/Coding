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
	Node *createNode(int x){
		return new Node(x);
	}

	LinkList() {
		head = nullptr;
	}
    //Function to insert a node at the beginning of the linked list.
     void insertAtBegining(int x) {
       // Your code here
       Node *newNode;
	   newNode = createNode(x);
       newNode->next = head;
       head = newNode;
     }
    void rotate(int k)
    {
        Node *itr = head;
        itr = head;
        int count = 1;
        Node *oHead;
        
        oHead = head;
        
        while(itr != nullptr &&
            count < k){
                itr = itr->next;
                count++;
        }
        if(itr != nullptr &&
            itr->next != nullptr){ // its not the last node.
             head = itr->next;
             itr->next = nullptr;
             
             itr = head;
             // move to last node
             while(itr->next != nullptr){
                 itr = itr->next;
             }
             itr->next = oHead;
        }
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
	LinkList List;
	int k;
	List.insertAtBegining(9);
	List.insertAtBegining(8);
	List.insertAtBegining(7);
	List.insertAtBegining(6);
	List.insertAtBegining(5);
	List.insertAtBegining(4);
	List.insertAtBegining(3);
	List.insertAtBegining(2);
	List.insertAtBegining(1);
	List.printList();
	cout<<"Insert rotate position"<<endl;
	cin>>k;
	List.rotate(k);
	cout<<"rotated List"<<endl;
	List.printList();
	return 0;
}
