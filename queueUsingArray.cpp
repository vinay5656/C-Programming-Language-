#include<iostream>
using namespace std;

template <typename T>
class Queue{
	T * data;
	int nextIndex;
	int firstIndex;
	int curSize;
	int capacity;
	public:
		Queue(int length):nextIndex(0),firstIndex(-1),curSize(0),capacity(length){
			data =new T[length];
		}
		
		int size(){
			return curSize;
		}
		
		bool isEmpty(){
			return curSize==0;
		}
		/*
		void enqueue(T element){
			if(curSize == capacity){
				cout<<"Queue is full"<<endl;
				return;
			}
			data[nextIndex] = element;
			nextIndex = (nextIndex+1)%capacity;
			if(firstIndex == -1){
				firstIndex++;
			}
			curSize++;
		}
		*/
		void enqueue(T element){
			if(curSize == capacity){
				int *newdata = new T[2*capacity];
				int n = size();
				int j = 0;
				for(int i=firstIndex;n>0;n--){
					newdata[j] = data[i];
					j++;
					i=(i+1)%capacity;
				}
				delete [] data;
				data = newdata;
				firstIndex = 0;
				nextIndex = capacity;
				capacity*=2;
			}
			data[nextIndex] = element;
			nextIndex = (nextIndex+1)%capacity;
			if(firstIndex == -1){
				firstIndex++;
			}
			curSize++;
		}
		
		T dequeue(){
			cout<<"dequeue : ";
			if(isEmpty()){
			   cout<<"Queue is empty "<<endl;
			   return 0;
			}
			T element = data[firstIndex];
			firstIndex = (firstIndex+1)%capacity;
			curSize--;
			if(curSize== 0){
				nextIndex = 0;
				firstIndex = -1;
			}
			return element;
		}
		
		T front(){
			cout<<"front : ";
			if(isEmpty()){
				cout<<"Queue is empty ";
				return 0;
			}
			return data[firstIndex];
		}
		
		void print(){
			int n = size();
			if(n==0){
				cout<<"print() cann't print because queue is empty"<<endl;
				return;
			}
			for(int i=firstIndex;n>0;n--){
				cout<<data[i]<<" ";
				i=(i+1)%capacity;
			}
			cout<<endl;
		}
};
int main(){
	Queue<int> q(5);
	q.isEmpty();
	q.dequeue();
	cout<<q.front()<<endl;
	cout<<"size:"<<q.size()<<endl;
	q.enqueue(10); q.enqueue(20); q.enqueue(30); q.enqueue(40);
	q.print();
	cout<<q.dequeue(); cout<<q.dequeue();
	q.enqueue(50); cout<<q.front()<<endl;
	cout<<q.dequeue();
	q.enqueue(60); q.enqueue(70); q.enqueue(80);cout<<q.front();
	q.print();
	cout<<q.dequeue();
    cout<<"size :"<<q.size()<<endl;
	cout<<q.front()<<endl;
	q.print();
	q.enqueue(100);
	q.enqueue(101);
	q.enqueue(102);q.enqueue(103);q.enqueue(104);q.enqueue(105);
	q.print();
	q.dequeue();q.dequeue();q.dequeue();q.dequeue();
	q.print();
	cout<<q.front();
	return 0;
	
}
