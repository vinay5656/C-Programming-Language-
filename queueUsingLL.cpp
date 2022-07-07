#include<iostream>
using namespace std;

template <typename T>
class Node{
	public:
	T data;
	Node<T> *next;
	public:
		Node(T data){
			this->data = data;
			next = NULL;
		}
};

template <typename T>
class Queue{
	Node<T> *head;
	Node<T> *tail;
	int size;
	public:
		Queue():head(NULL),tail(NULL),size(0){}
		
		int getSize(){
			return size;
		}
		
		bool isEmpty(){
			return size==0;
		}
		
		void enqueue(T element){
			Node<T> * newNode = new Node<T>(element);
			if(head == NULL){
				head = tail = newNode;
			}
			tail->next = newNode;
			tail = tail->next;
			size++;
			return;
		}
		
		T dequeue(){
			if(isEmpty()){
				return 0;
			}
			Node<T> *temp = head;
			head= head->next;
			T element = temp->data;
			delete temp;
			size--;
			return element;
		}
	    
	    T front(){
	    	if(isEmpty()){
	    		return 0;
			}
	    	return head->data;
		}
		
		void print(){
			Node<T> *temp = head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
};
int main(){
	Queue<int> q;
	
	q.enqueue(10); q.enqueue(20); q.enqueue(30); q.enqueue(40); q.enqueue(50);
	q.print();
	cout<<"size : "<<q.getSize()<<endl;
	cout<<"front : "<<q.front()<<endl;
	cout<<"dequeue : "<<q.dequeue()<<endl;
	cout<<"dequeue : "<<q.dequeue()<<endl;
	cout<<"dequeue : "<<q.dequeue()<<endl;cout<<"dequeue : "<<q.dequeue()<<endl;
	q.enqueue(100);q.enqueue(500);
	q.enqueue(200);q.enqueue(600);
	q.enqueue(300);q.enqueue(700);
	q.enqueue(400);q.enqueue(800);
	q.print();
	cout<<"size : "<<q.getSize()<<endl;
	cout<<"front : "<<q.front()<<endl;
	return 0;
	
}

