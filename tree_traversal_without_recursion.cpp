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

void preorder(struct node *root)
{
	if(root==NULL)
	 return;
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	
}


void postorder(struct node *root)
{
	if(root==NULL)
	 return;

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void inorder(struct node *root)
{
	if(root==NULL)
	 return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
void solve(struct node  *root)
{
	if(root==NULL) return;
	
	stack<struct node *> first,second;

	first.push(root);
		struct node* k;
	while(!first.empty())
	{
	     k=first.top();
		 first.pop();
	     second.push(k);
	    
		if(k->left) 
		first.push(k->left);
		if(k->right)
		first.push(k->right);
		
	
	}
	
	while(!second.empty())
	{
	
		 k=second.top();
		
		second.pop();
		cout<<k->data<<"  ";
	}
}

int main() 
{ 
struct node *root = newNode(1); 
root->left	 = newNode(2); 
root->right	 = newNode(3); 
root->left->left = newNode(4); 
root->left->right=newNode(5);
root->right->left = newNode(6); 
root->right->right=newNode(7);

solve(root);



/*
cout<<"PREORDER\n\n";
preorder(root);

cout<<"\n\nINORDER\n\n";
inorder(root);

cout<<"\n\nPOSTORDER\n\n";
postorder(root);*/
} 

