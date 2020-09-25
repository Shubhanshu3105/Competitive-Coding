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
int minm,maxm;
struct node* newNode(int data) 
{ 
struct node* node = (struct node*)malloc(sizeof(struct node)); 
node->data = data;  
node->left = NULL; 
node->right = NULL; 
return(node); 
} 

void findMinMax(node* root,int hd)
{
	if(root==NULL) return;
	if(hd<minm)
	  minm=hd;
	if(hd>maxm)
	maxm=hd;
	if(root->left)
	 {
 	findMinMax(root->left,hd-1);
	 }
	 if(root->right)
	 {
	   findMinMax(root->right,hd+1);
	}
 }
 
 /* 
 void printvertical(node* root,int linenumber,int hd)
 {
 	if(root==NULL)
 	  return;
 	if(linenumber==hd)
 	  cout<<root->data<<" ";
 	printvertical(root->left,linenumber,hd-1);
 	printvertical(root->right,linenumber,hd+1);
 }*/
 
void printing(node* root,int hd,vector<vector<int>>&m)
{
 	if(root==NULL)
 	  return;
 	 
 	if(root->left)
 	 printing(root->left,hd-1,m);
 	  
 	 int j=hd-minm;
 	m[j].push_back(root->data);
 	
 	if(root->right)
 	printing(root->right,hd+1,m);
 
}

void preorder(node* root)
{
	if(root==NULL)
 	  return;
 	 
 	if(root->left)
 	   preorder(root->left);
 	  cout<<root->data<<"\n";
 	if(root->right)
 	preorder(root->right);
}
int main() 
{ 
minm=INT_MAX;
maxm=INT_MIN;
int hd=0;


struct node *root = newNode(1); 
root->left =newNode(2); 
root->right =newNode(3); 
root->left->left =newNode(4); 
root->left->right=newNode(5);
root->right->left=newNode(6);
root->right->right=newNode(7);
root->right->left->right=newNode(8);
root->right->right->right=newNode(9);

findMinMax(root,hd);

//cout<<minm<<"  "<<maxm;
/*
for(int i=minm;i<=maxm;i++)
{
	printvertical(root,i,0);
	cout<<"\n";
}*/

int k=maxm-minm;
vector<vector<int>>ans(k);
printing(root,0,ans);
//preorder(root);


cout<<ans.size()<<"\n";
for(int i=0;i<ans.size();i++)
{
	for(int j=0;j<ans[i].size();j++)
	{
		cout<<ans[i][j]<<" ";
	}
	cout<<"\n";
}


} 

