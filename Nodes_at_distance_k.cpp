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

struct node* newNode(int data) 
{ 
struct node* node = (struct node*)malloc(sizeof(struct node)); 
node->data = data;  
node->left = NULL; 
node->right = NULL; 
return(node); 
} 

void printD(node* root,int k)
{
	if(root==NULL)
	  return;
	  
	 // cout<<"Checking for root->data = "<<root->data<<"\n";
	  
	if(k==0)
	{
		 cout<<root->data<<" ";
		 return;
	}
	
	else
	  {
	  	printD(root->right,k-1);
	  	printD(root->left,k-1);
	  }
}

int main() 
{ 
struct node *root = newNode(1); 
root->left	 = newNode(2); 
root->right	 = newNode(3); 
root->left->left = newNode(4); 
root->left->right=newNode(5);
root->right->left=newNode(6);
root->right->right=newNode(7);

printD(root,2);

} 

