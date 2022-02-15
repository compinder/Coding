#include<iostream>

using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=10){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
   bool isFull();
};



int main()
{
    int T;
    twoStacks *sq = new twoStacks();
    sq->push1(4);
    sq->push1(5);
    sq->push1(6);
    sq->push1(7);
    sq->push1(8);
    sq->push1(9);
    sq->push2(20);
    sq->push2(21);
    sq->push2(22);
    sq->push2(23);
    sq->push2(24);
    cout<<sq->pop1()<<" ";
    cout<<sq->pop2()<<" ";
    sq->push2(24);
    cout<<sq->pop2()<<" ";

    cout<<endl;
}
// } Driver Code Ends


bool twoStacks :: isFull(){
	if(abs(top1-top2) == 1){
		return true;
	}
	return false;
}
//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
	if(isFull() == true){
		cout<<"push fail for value: " <<x<<", stack is full"<<endl;
		return;
	}
    top1++;
    arr[top1] = x;
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
	if(isFull() == true){
		cout<<"push fail for value: " <<x<<", stack is full"<<endl;
		return;
	}
    top2--;
    arr[top2] = x;
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    int elm;
    if(top1 == -1){
        return -1;
    }
    elm = arr[top1];
    top1--;
    return elm;
    
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    int elm;
    if(top2 == size){
        return -1;
    }
    elm = arr[top2];
    top2++;
    return elm;
}
