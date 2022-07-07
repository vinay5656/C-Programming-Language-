#include<iostream>
using namespace std;

template <typename T>
class binearyTreeNode{
	public:
		T data;
		binearyTreeNode<T> *left;
		binearyTreeNode<T> *right;
		
		binearyTreeNode(T data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
		
		~binearyTreeNode(){
			delete left;
			delete right;
		}
};

binearyTreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter the root data : ";
	cin>>rootData;
	if(rootData == -1){
		return NULL;
	}
	binearyTreeNode<int> *root = new binearyTreeNode<int>(rootData);
	binearyTreeNode<int> *leftChild = takeInput();
	binearyTreeNode<int> *rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	
	return root;
}

void print(binearyTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" : ";
	if(root->left != NULL){
		cout<<"L "<<root->left->data;
	}
	cout<<" ";
	if(root->right != NULL){
		cout<<"R "<<root->right->data;
	}
	cout<<endl;
	print(root->left);
	print(root->right);
	return ;
	
}

int main(){
	/*
	binearyTreeNode<int> *root = new binearyTreeNode<int>(10);
	binearyTreeNode<int> *node1 = new binearyTreeNode<int>(20);
	binearyTreeNode<int> *node2 = new binearyTreeNode<int>(30);
	binearyTreeNode<int> *node3 = new binearyTreeNode<int>(40);binearyTreeNode<int> *node4 = new binearyTreeNode<int>(50);
	binearyTreeNode<int> *node5 = new binearyTreeNode<int>(60);binearyTreeNode<int> *node6 = new binearyTreeNode<int>(70);
	
	root->left = node1; 	root->right = node2;
	node1->left = node3;	node1->right = node4;
	node2->left = node5;	node2->right = node6;
	*/
	
	binearyTreeNode<int> *root = takeInput();
	print(root);
	
	return 0;
	
}
