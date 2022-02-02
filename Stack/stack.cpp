#include<iostream>

using namespace std;

template<class T>
class _Stack_{
	struct Node{
		T data;
		class Node* next;
		Node(T _data_){
			data = _data_;
			next = nullptr;
		}
	};
	Node *head;
	public:
	Node* createNode(T data){
		return new Node(data);
	}
	void push(T data){
		Node *newNode;
		newNode = createNode(data);
		newNode->next = head;
		head = newNode;
	}
	T pop(){
		if(isEmpty()){
			cout<<"Stack is empty"<<endl;
			return -1;
		}
		Node *goneNode;
		goneNode = head;
		head = head->next;
		return goneNode->data;
	}
	T peek(){
		if(isEmpty()){
			cout<<"Stack is empty"<<endl;
			return -1;
		}
		return head->data;
	}
	bool isEmpty(){
		if(head == nullptr){
			return true;
		}
		return false;
	}
	_Stack_(){
		head = nullptr;
	}
};

int main()
{
	_Stack_<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	cout<<"top element is: "<<stk.peek()<<endl;
	stk.push(4);
	cout<<"top element is: "<<stk.peek()<<endl;
	stk.pop();
	cout<<"top element is: "<<stk.peek()<<endl;
	stk.pop();
	cout<<"top element is: "<<stk.peek()<<endl;
	stk.pop();
	cout<<"top element is: "<<stk.peek()<<endl;
	stk.pop();
	cout<<"pop: "<<stk.pop()<<endl;
	cout<<"peek: "<<stk.peek()<<endl;
	stk.push(5);
	stk.push(6);
	cout<<"pop: "<<stk.pop()<<endl;
	cout<<"peek: "<<stk.peek()<<endl;
	return 0;
}
