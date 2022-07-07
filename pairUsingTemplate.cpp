#include<iostream>
using namespace std;

//template <typename T>
template <typename T, typename V>

class Pair{
	T x;
	V y;
	public:
		void setX(T x){
			this->x = x;
		}
		
		void setY(V y){
			this->y = y;
		}
		
        T getX(){
        	return x;
		}
		 
		V getY(){
			return y;
		}
	
};
int main(){
	Pair<int,int> p1;
	p1.setX(10);
	p1.setY(20);
	cout<<"<"<<p1.getX()<<", "<<p1.getY()<<">"<<endl;
	
	Pair<double,double> p2;
	p2.setX(3.2);
	p2.setY(6.4);
    cout<<"<"<<p2.getX()<<", "<<p2.getY()<<">"<<endl;
	
	Pair<int,double> p3;
	p3.setX(10);
	p3.setY(4.5);
    cout<<"<"<<p3.getX()<<", "<<p3.getY()<<">"<<endl;
    
    Pair<double,int> p4;
    p4.setX(10);
	p4.setY(4.5);
    cout<<"<"<<p4.getX()<<", "<<p4.getY()<<">"<<endl;
    
    Pair<char,int> p5;
    p5.setX('A');
	p5.setY(4.5);
    cout<<"<"<<p5.getX()<<", "<<p5.getY()<<">"<<endl;
    
    Pair<Pair<int,int>,int> p6;
    p6.setX(p1);
	p6.setY(4);
     cout<<"<"<<"<"<<p6.getX().getX()<<","<<p6.getX().getY()<<">"<<", "<<p6.getY()<<">"<<endl;
    
    Pair<Pair<int,double>,int> p7;
    p7.setX(p3);
	p7.setY(4);
    cout<<"<"<<"<"<<p7.getX().getX()<<","<<p7.getX().getY()<<">"<<", "<<p7.getY()<<">"<<endl;
    
    
	
	return 0;
}
