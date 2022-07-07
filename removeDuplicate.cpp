#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> removeDuplicate(int *arr,int size){
	vector<int> uniqueElementV;
	unorder_map<int,bool> uniqueElementMap;
	
	for(int i=0;i<size;i++){
		if(uniqueElementMap.count(arr[i])>0){
			continue;
		}
		uniqueElementMap[arr[i]] =true;
		uniqueElementV.push_back(arr[i]);
	}
	
	return uniqueElementV;
}
int main(){
	int arr[] = {1,2,3,3,2,1,4,3,6,5,5};
    vector<int> v = removeDuplicate(arr,11);
    for(int i=0;i<v.size();i++){
    	cout<<v[i]<<" ";
	}
	return 0;
}
