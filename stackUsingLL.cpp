#include<iostream>
using namespace std;

template <typename T>
class Node{
	public:
	T data;
	Node<int> *next;
	public:
		Node(T data):data(data),next(NULL){}
		
};

template <typename T>
class Stack{
	Node<T> *head;
	int length;
	public:
		Stack(){
			head = NULL;
			length = 0;
		}
		
		int size(){
			return length;
		}
		
		bool isEmpty(){
			return head==NULL;
		}
		
		void push(T element){
			Node<T> *newNode = new Node<T>(element);
			if(head == NULL){
				head = newNode;
			}else{
				newNode->next = head;
				head = newNode;
			}
			length++;
		}
		
		T pop(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			T element = head->data;
			head = head->next;
			length--;
			return element;
		}
		
		T top(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			return head->data;
		}
		
		void print(){
			Node<T> *temp;
			temp = head;
			while(temp!= NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		
};
int main(){
	Stack<int> s;
	cout<<s.isEmpty()<<endl;
	s.pop();
	s.push(15);
	s.push(25);
	s.push(15);
	s.push(5);
	s.push(35);
	s.push(105);
	s.push(150);
	s.push(153);
	s.push(1);
	s.print();
	cout<<s.size()<<endl;
	s.pop();
	s.pop();
	s.pop();
	s.print();
	cout<<s.size()<<endl;
	cout<<s.top()<<endl;
	cout<<s.isEmpty()<<endl;
	
	return 0;
}
