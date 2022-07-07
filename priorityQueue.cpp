#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class PriorityQueue{
	vector<int> pqArr;
	public:
		PriorityQueue(){
		}
		
		bool isEmpty(){
			return pqArr.size()==0;
		}
		
		int getSize(){
			return pqArr.size();
		}
		
		int getMin(){
			if(isEmpty()){
				return INT_MAX;
			}
//			cout<<"Minimum or top value : ";
			return pqArr[0];
		}
		
		void insert(int data){
			if(isEmpty()){
				cout<<"only has one element :";
				pqArr.push_back(data);
				return;
			}
			int childIndex = getSize();
			pqArr.push_back(data); 

            int parentIndex;
            while(childIndex != 0){
            	parentIndex = (childIndex-1)/2;
            	if(pqArr[parentIndex] > pqArr[childIndex]){
			       int temp = pqArr[parentIndex];
			       pqArr[parentIndex] = pqArr[childIndex];
			       pqArr[childIndex] = temp;
			   }
               childIndex = parentIndex;
			}
			return;	
		}
		void print(){
			if(isEmpty()){
				return;
			}
			for(int i=0;i<pqArr.size();i++){
				cout<<pqArr[i]<<" ";
			}
			cout<<endl;
		}
		int removeMin(){
			if(isEmpty()){
				return INT_MAX;
			}
			if(pqArr.size() == 1){
				int minimum = getMin();
				pqArr.pop_back();
				return minimum;
			}
			if(pqArr.size() == 2){
				int minimum  = getMin();
				pqArr[0] = pqArr[1];
				pqArr.pop_back();
				return minimum;
			}
			if(pqArr.size() == 3){
				int minimum = getMin();
				pqArr[0] = pqArr[1];
				pqArr[1] = pqArr[2];
				pqArr.pop_back();
				return minimum;
			}
//			int minimum = getMin();
			int lastIndex = pqArr.size()-1;
			int minimum = pqArr[0];
			pqArr[0] = pqArr[lastIndex];
//    		pqArr[lastIndex] = minimum; // opptional //write it because it right
			pqArr.pop_back();
			int parentIndex = 0;
			
			if(pqArr.size() >= 3){
			
			while(parentIndex < (pqArr.size()-1)/2){
			
			      if(pqArr[parentIndex]>pqArr[2*parentIndex+1] && pqArr[2*parentIndex+1]<pqArr[2*parentIndex+2]){
				     int temp = pqArr[parentIndex];
				     pqArr[parentIndex] = pqArr[2*parentIndex+1];
				     pqArr[2*parentIndex+1] = temp;
				     parentIndex = 2*parentIndex+1;
				     continue;
			        }else if((pqArr[parentIndex]<pqArr[2*parentIndex+1] && pqArr[2*parentIndex+1]>pqArr[2*parentIndex+2]) 
					||(pqArr[parentIndex]>pqArr[2*parentIndex+1] && pqArr[2*parentIndex+1]>pqArr[2*parentIndex+2])){
				            int temp = pqArr[parentIndex];
				            pqArr[parentIndex] = pqArr[2*parentIndex+2];
				            pqArr[2*parentIndex+2] = temp;
				            parentIndex = 2*parentIndex+2;
				            continue;
			        }else{
			        	break;
					}
	     	}
	     }
	     
	     	return minimum;
		}
};
int main(){
	PriorityQueue *pq = new PriorityQueue();
	/*
	cout<<pq->isEmpty()<<endl;
	cout<<pq->getMin()<<endl;
//	cout<<pq->removeMin()<<endl;
	pq->insert(10);
//	cout<<pq->removeMin()<<endl;
	
	pq->insert(20);
	pq->insert(40);
	pq->insert(30);
	pq->insert(25);
	pq->insert(100);
//	pq->insert(5);
	pq->print();
	cout<<pq->getMin()<<endl;
	cout<<pq->removeMin()<<endl;

	pq->print();
	*/
	
	pq->insert(10);
	pq->insert(100);
	pq->insert(12);
	pq->insert(200);
	pq->insert(400);
	pq->insert(18);
	pq->insert(15);
	pq->print();
	cout<<pq->getMin()<<endl;
	cout<<pq->getSize()<<endl;
	cout<<pq->removeMin()<<" ";
	cout<<pq->removeMin()<<" ";
	cout<<pq->removeMin()<<" ";cout<<pq->removeMin()<<" ";cout<<pq->removeMin()<<" ";cout<<pq->removeMin()<<" ";cout<<pq->removeMin()<<" ";
	
	return 0;
	
}
