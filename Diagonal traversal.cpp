#include<bits/stdc++.h>
using namespace std;
struct node 
{ 
	int data; 
	struct node *left; 
	struct node *right; 
	node (int a)
	{
		this->data=data;
		left=right=NULL;
	}
}; 
map<int,vector<int>>mp;
struct node* newNode(int data) 
{ 
struct node* node = (struct node*)malloc(sizeof(struct node)); 
node->data = data;  
node->left = NULL; 
node->right = NULL; 
return(node); 
} 

int height(struct node *root)
{
	if(root==NULL)
	 return 0;
return 1+max(height(root->left),height(root->right));
}

void diagonal_tra(node* root,int level)
{
	if(root==NULL)
	 return ;
	 mp[level].push_back(root->data);
	cout<<root->data<<"\t\t"<<level<<"\n";
    diagonal_tra(root->left,level+1);
	diagonal_tra(root->right,level);

	
}

int main() 
{ 
struct node *root = newNode(1); 
root->right=newNode(2);
root->right->right=newNode(3);
root->right->right->left=newNode(6);
root->left=newNode(4);
root->left->left=newNode(8);
root->left->right=newNode(5);
root->left->right->left=newNode(9);
root->left->right->right=newNode(7);
cout<<"root->data"<<"  "<<"level"<<"\n";
mp.clear();
diagonal_tra(root,0);
for(auto it=mp.begin();it!=mp.end();it++)
 {
  	vector<int>temp=(it->second);
  	for(int i=0;i<temp.size();i++)
 	{
 		cout<<temp[i]<<" ";
	 }
	 cout<<"level = "<<it->first<<"\n";
 }

} 

