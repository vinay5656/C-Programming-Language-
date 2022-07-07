/* Stack Implementation */
#include<iostream>
#include<climits>
using namespace std;

class Stack{
	int *arr;
	int nextIndex;
	int capacity;
	public:
		Stack(int capacity):nextIndex(0),capacity(capacity){
			arr = new int[capacity];
		}
		// size(), Return number of element persent in the stack;
		int size(){
			return nextIndex;
		}
		bool isEmpty(){
			/*
			if(nextIndex == 0){
				return true;
			}else{
				return false;
			}
			*/
			return nextIndex==0;
		}
		void push(int data){
			if(capacity == nextIndex){
				cout<<"Stack is full "<<endl;
				return;
			}
			arr[nextIndex++] = data;
    	}
	    int pop(){
	    	if(isEmpty()){
	    		cout<<"Stack is empty"<<endl;
	    		return INT_MIN;
			}
			nextIndex--;
	    	return arr[nextIndex];
		}
		int  top(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl; 
			}
			return arr[nextIndex-1];
		}
	    void print(){
	    	int len = nextIndex-1;
	    	for(int i =len;i>=0;i--){
	    		cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	Stack s(10);
    s.pop();
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(160);
	s.push(102);
	s.print(); 
    cout<<"Deleted Element "<<s.pop()<<endl;
    cout<<"Deleted Elemet "<<s.pop()<<endl;
    s.print();
    cout<<"Top most element "<<s.top()<<endl;
    cout<<"Is stack is Empty "<<s.isEmpty()<<endl;
    cout<<"what is the size of the stack "<<s.size()<<endl;
	return 0;
	
	
}
