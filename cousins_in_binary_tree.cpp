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

void check(node* A,int B)
{
    if(A==NULL)
     return ;
     
     queue<node* >q;
     q.push(A);
     int found=0;
     while(!q.empty() && (found!=1))
     {
         int k=q.size();
         while(k--)
         {
             node* temp;
             temp=q.front();
             q.pop();
             
             /*if((temp->left->val==B && (temp->left)) || (temp->right->val==B && (temp->right)))
             {
              found=1;
             }
               
             else
             {
                 if(temp->left)
                   q.push(temp->left);
                 if(temp->right)
                   q.push(temp->right);
             }*/
             if(temp->left || temp->right)
             {
                 if(temp->left)
                 {
                     if(temp->left->data==B)
                    {
                        found=1;
                        continue;
                    }
                 }
                 if(temp->right)
                 {
                     if(temp->right->data==B)
                    {
                        found=1;
                        continue;
                    }
                 }
                 
                 if(temp->left)
                  q.push(temp->left);
                 if(temp->right)
                  q.push(temp->right);
                
             }
             
         }
     }
     if(found)
     {
         while(!q.empty())
         {
            cout<<q.front()->data<<" ";
             q.pop();
         }
     }
     return;
     
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
check(root,7);

} 

