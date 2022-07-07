#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T data){
			this->data = data;
		}
		
    	~TreeNode(){
			for(int i=0;i<children.size();i++){
				delete children[i];
			}
		}

};

/*
// ----- This takeInput function is taking input depthwise----
TreeNode<int>* takeInput(){
	int data;
	cout<<"Enter the data for node ";
	cin>>data;
	cout<<endl;
	TreeNode<int> *root = new TreeNode<int>(data);
	int numChild;
	cout<<"Enter the number of children for node "<<root->data<<" :";
	cin>>numChild;
	cout<<endl;
	for(int i=0;i<numChild;i++){
	    TreeNode<int>* node = takeInput();
	    root->children.push_back(node);
	}
	return root;	
}
*/
/*takes input levelwise*/
TreeNode<int>* takeInput(){
	queue<TreeNode<int>*> pendingNodes;
	int data;
	cout<<"Enter the data for root node:";
	cin>>data;
	TreeNode<int> *root = new TreeNode<int>(data);
	pendingNodes.push(root);
	while(pendingNodes.size()!= 0){
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		int num;
		cout<<"Enter the number of children for node "<<front->data<<" :";
		cin>>num;
		for(int i=0;i<num;i++){
			int newData;
			cout<<"Enter the data for node "<<i+1<<" children of "<<front->data<<" : ";
			cin>>newData;
			TreeNode<int> * node  = new TreeNode<int>(newData);
			front->children.push_back(node);
			pendingNodes.push(node);
		}
	}
	return root;
}
/*

//----- This Print function print depthwise -----

void print(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<": ";
	for(int i=0;i<root->children.size();i++){
		if(i<root->children.size()-1){
		    cout<<root->children[i]->data<<",";	
		}else{
			cout<<root->children[i]->data;
		}
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		print(root->children[i]);
	}
	return;
}
*/
void print(TreeNode<int> *root){
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		TreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<" : ";
		for(int i=0;i<front->children.size();i++){
			if(i<front->children.size()-1){
				cout<<front->children[i]->data<<", ";
			}else{
				cout<<front->children[i]->data;
			}
			pendingNodes.push(front->children[i]);
		}
		cout<<endl;
	}
}

void preOrder(TreeNode<int> *root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	for(int i =0;i<root->children.size();i++){
		preOrder(root->children[i]);
	}
	return;
}

void postOrder(TreeNode<int> *root){
	if(root == NULL){
		return;
	}
	for(int i =0;i<root->children.size();i++){
		postOrder(root->children[i]);
	}
	cout<<root->data<<" ";
	return;
}

int countNode(TreeNode<int> *root){
	if(root==NULL){
		return 0;
	}
	int ans = 0;
	for(int i=0;i<root->children.size();i++){
		ans = ans + countNode(root->children[i]);
	}
	return ans+1;
}

int sumOfNodes(TreeNode<int> *root){
		if(root==NULL){
		return 0;
	}
	int sum = 0;
	sum = root->data;
	for(int i=0;i<root->children.size();i++){
		sum = sum + sumOfNodes(root->children[i]);
	}

	return sum;
}

int findHeight(TreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	int maxlen = 1;
	for(int i=0;i<root->children.size();i++){
		int len = findHeight(root->children[i])+1;
		if(len>maxlen){
			maxlen = len;
		}
	}
	return maxlen;
}

void printAtLevelK(TreeNode<int> *root,int k){
	if(root == NULL){
		return ;
	}
	if(k = 0){
		cout<<root->data<<" ";
		return;
	}
	for(int  i=0;i<root->children.size();i++){
		printAtLevelK(root->children[i],k-1);
	}
	return;
}

int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    int ans = 0;
    if(root == NULL){
        return 0;
    }
    for(int i=0;i<root->children.size();i++){
        ans += getLeafNodeCount(root->children[i]);
    }
    if(root->children.size() == 0 && root != NULL){
        return 1;
    }
    return ans;
}

int main(){
	/*
	 TreeNode<int> *root = new TreeNode<int>(1);
	 TreeNode<int> *node2 = new TreeNode<int>(2);
	 TreeNode<int> *node3 = new TreeNode<int>(3);TreeNode<int> *node4 = new TreeNode<int>(4);
	 TreeNode<int> *node5 = new TreeNode<int>(5);TreeNode<int> *node6 = new TreeNode<int>(6);
	 TreeNode<int> *node7 = new TreeNode<int>(7);TreeNode<int> *node8 = new TreeNode<int>(8);
	 
	 root->children.push_back(node2);root->children.push_back(node3);root->children.push_back(node4);
	 node2->children.push_back(node5);node2->children.push_back(node6);
	 node3->children.push_back(node7);node4->children.push_back(node8);
	 */
	 TreeNode<int> *root = takeInput();
	 print(root);
	 postOrder(root);
	 cout<<endl;
	 preOrder(root);
	 cout<<endl;
	 cout<<countNode(root)<<endl;
	 cout<<sumOfNodes(root)<<endl;
	 cout<<findHeight(root)<<endl;
	 cout<<printAtLevelK(root,2)<<endl;
	 cout<<getLeafNodeCount(root)<<endl;
	 return 0;
	 
}
