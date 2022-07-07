#include<iostream>
#include<unordered_map>
#include<utility>
#include<string>
using namespace std;

int main(){
	unordered_map<string, int> hMap;
	// Hashmaps are store data in the form of pair
	pair<string,int> hashPair1("abc",1);
	
	pair<string,int> hashPair2;
	hashPair2 = make_pair("mnl",2);
	
	// insert a element in the hashmaps
	hMap.insert(hashPair1);
	hMap.insert(hashPair2);
	// if key is not present in the hashmap then it will create a default pair with key
	hMap["pqr"] = 3;
	pair<string,int> hashPair3("vinay",101803296);
	pair<string,int> hashPair4("ravi",40183344);
	pair<string,int> hashPair5("loki",101803263);
	pair<string,int> hashPair6("bavesh",101803234);
	hMap.insert(hashPair3);
	hMap.insert(hashPair4);
	hMap.insert(hashPair5);
	hMap.insert(hashPair6);

	
	// access operation
	cout<<hMap["abc"]<<endl;
	cout<<hMap.at("mnl")<<endl;
	cout<<hMap.at("pqr")<<endl;
	cout<<"size : "<<hMap.size()<<endl;
	// key = "cde" does not exist in the hashmap so it will create a default one with rendom value;
	cout<<hMap["cde"]<<endl;
	cout<<"size : "<<hMap.size()<<endl;
    for(auto itr = hMap.begin();itr!=hMap.end();itr++){
		cout<<"<"<<itr->first<<", "<<itr->second<<">"<<endl;
	}
	//remove element from hashmaps
	//1. if we provide the key;
	cout<<"after erase function :"<<endl;
	hMap.erase("cde");
	// key = "kgf" does not exist so it will create and insert at begin
	hMap["kgf"] = 4;
	for(auto itr = hMap.begin();itr!=hMap.end();itr++){
		cout<<"<"<<itr->first<<", "<<itr->second<<">"<<endl;
	}
	//2. if we hace position of the element
	auto itr = hMap.find("pqr");
    cout<<"what: "<<hMap.erase(itr)<<endl;
    cout<<"after erase function :"<<endl;
	for(auto itr=hMap.begin();itr != hMap.end();itr++){
		cout<<"< "<<itr->first<<", "<<itr->second<<" >"<<endl;
	}
	// 3. if We provide range of position
	/*
	pair<string,int> hashPair3("vinay",101803296);
	pair<string,int> hashPair4("ravi",40183344);
	pair<string,int> hashPair5("loki",101803263);
	pair<string,int> hashPair6("bavesh",101803234);
	hMap.insert(hashPair3);
	hMap.insert(hashPair4);
	hMap.insert(hashPair5);
	hMap.insert(hashPair6);
*/
	/*--gave me runtime error why = ? (error came at the time of insert why = ?)
	hMap.insert({"vinay",101803296});
	hMap.insert({"ravi",40183344});
	hMap.insert({"loki",101803263});
	hMap.insert({"bavesh",101803234});
	*/
	auto itr1 = hMap.find("kgf");
	auto itr2 = hMap.find("mnl");

    hMap.erase(itr1,itr2);
	cout<<"after erase function :"<<endl;
	for(auto itr=hMap.begin();itr != hMap.end();itr++){
		cout<<"< "<<itr->first<<", "<<itr->second<<" >"<<endl;
	}
	/* ---remove duplicate form array---
	int arr[8] ={2, 5, 6, 2, 3, 3, 9, 5};
	vector<int> v;
	vector<int> sv;
	unordered_map<int,int> m;
	map<int,int> s;
	for(int i=0;i<8;i++){
		m.insert({arr[i],1});
		s.insert({arr[i],2});
	}
   
	for(auto itr = m.begin();itr != m.end();itr++){
		cout<<"<"<<itr->first<<" ,"<<itr->second<<" >"<<endl;
		v.push_back(itr->first);
	}
   
   for(int i=0;i<v.size();i++){
	   cout<<v[i]<<" ";
   }
   cout<<endl;
   for(auto itr = s.begin();itr != s.end();itr++){
		cout<<"<"<<itr->first<<" ,"<<itr->second<<" >"<<endl;
		sv.push_back(itr->first);
	}
	for(int i=0;i<sv.size();i++){
	   cout<<sv[i]<<" ";
   }
	*/
	return 0;
}
