#include<iostream>
using namespace std;
/*

class Addition{
	int x;
	int y;
	public:
		Addition(int a,int b):x(a),y(b){
		}
		int sum(){
			return x+y;
		}
};

// that i  have to add to avoid error
class Addition{
	double x;
	double y;
	public:
		Addition(double a,double b):x(a),y(b){
		}
		double sum(){
			return x+y;
		}
};

*/


/*

//To avoid multiple class of Addition  for defferent data type of data member. We use template

template <typename T>
class Addition{
	T x;
	T y;
	public:
		Addition(T a,T b):x(a),y(b){
		}
		T sum(){
			return x+y;
		}
};

*/
// To add defferent types of "Data Member" of same class
template <typename T,typename V>
class Addition{
	T x;
	V y;
	public:
		Addition(T a, V b):x(a),y(b){
		}
		V sum(){
			return x+y;
		}
};

int main(){
	/*
	Addition a(5,6);
	cout<<a.sum();
//	if want to add to double then i can not do
    Addition b(4.3,5.6);// this will give error if i do not declare another class with double data member
    */
    
    /*
    Addition<int> a(5,6);
    cout<<a.sum()<<endl;
    Addition<double> b(5.7,3.5);
    cout<<b.sum()<<endl;
    */
    
    Addition<int,double> a(5,6.6);
    cout<<a.sum()<<endl;
    Addition<double,double> b(5.7,3.5);
    cout<<b.sum()<<endl;
    
	return 0;
	
}
