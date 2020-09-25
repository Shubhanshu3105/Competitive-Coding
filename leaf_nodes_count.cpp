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

int cnt=0;
int count(struct node *root)
{
	if(root==NULL)
	 return 0;
    if((root->left==NULL)&&(root->right==NULL))
    {
    	
      cout<<root->data<<"\n";
      return 1;
	}
    else
       return count(root->left)+count(root->right);
}


int main() 
{ 
struct node *root = newNode(1); 
root->left	 = newNode(2); 
root->right	 = newNode(3); 
root->left->left = newNode(4); 
root->left->right=newNode(5);

cout<<"No. of internal nodes = "<<count(root);
//cout<<cnt<<"\n";
} 

