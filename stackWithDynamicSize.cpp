#include<iostream>
#include<climits>
using namespace std;

class Stack{
	int *arr;
	int nextIndex;
	int capacity;
	public:
		Stack():nextIndex(0),capacity(1){
			arr = new int[capacity];
		}
		
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
			if(nextIndex == capacity){
				int *newArr = new int[2*capacity];
				for(int i=0;i<capacity;i++){
					newArr[i] = arr[i];
				}
				delete [] arr;
				arr = newArr;
				capacity *= 2;
			}
			arr[nextIndex] = data;
			nextIndex++;
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
	Stack s;
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
