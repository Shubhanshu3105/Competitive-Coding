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

int height(struct node *root)
{
	if(root==NULL)
	 return 0;
return 1+max(height(root->left),height(root->right));
}


int main() 
{ 
struct node *root = newNode(1); 
root->left	 = newNode(2); 
root->right	 = newNode(3); 
root->left->left = newNode(4); 
root->left->right=newNode(5);

cout<<height(root);
} 

