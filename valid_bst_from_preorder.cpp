#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> A)  //O(n^2) Approach 
{
	int n=A.size();
    for(int i=0;i<n-1;i++)
    {
        int j=i+1;
        while((A[j]<=A[i])&&(j<n))
        {
            j++;
        }
        cout<<A[i]<<" the greater value will be = "<<A[j]<<"\n";
        for(int k=j;k<n;k++)
        {
            if(A[i]>A[k])
              return 0;
        }
    }
    return 1;
}

int solve_2(vector<int> A)
{
	stack<int>s; //create an empty stack
	//initialize current root as minimum as possible
	int root=INT_MIN;
	
	int n=A.size();
	for(int i=0;i<n;i++)
	{
		  if (A[i] < root) 
            return 0;
		  
		// If A[i] is in right subtree of stack top, 
        // Keep removing items smaller than pre[i] 
        // and make the last removed item as new 
        // root. 
        while (!s.empty() && s.top()<A[i]) 
        { 
            root = s.top(); 
            s.pop(); 
        } 
  
        // At this point either stack is empty or 
        // A[i] is smaller than root, push A[i] 
        s.push(A[i]); 
    } 
    return 1; 
	}
	


int main()
{
 vector<int> A={315, 279, 263, 205, 187, 184, 70, 68, 141, 100, 176, 185, 193, 309, 839, 749, 491, 384, 364, 416, 392, 386, 418, 417, 457, 433, 655, 645, 596, 
	 584,524, 630, 748, 667, 658, 692, 735, 732, 805, 787, 773, 763, 763, 796, 897, 896, 859, 863, 886, 960, 948, 943, 969, 996, 989};
 cout<<solve_2(A); //O(n^2) Approach
 
	 
 	
}
