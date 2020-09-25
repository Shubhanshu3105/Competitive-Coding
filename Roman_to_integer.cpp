#include<bits/stdc++.h>
using namespace std;
int value(char r)
{
    switch(r)
    {
        case 'I':
          return 1;
        case 'V':
          return 5;
        case 'X':
          return 10;
        case 'L':
          return 50;
        case 'C':
          return 100;
        case 'D':
          return 500;
        case 'M':
          return 1000;
    }
    return -1;
}
int romanToInt(string A) {
    int i=0;
    int n=A.size();
    vector<int>total;
    while(i<n)
    {
        total.push_back(value(A[i]));
        i++;
    }
    int val=total[0];
    int prev=total[0];
    for(int j=1;j<n;j++)
    {
        int next=total[j];
        if(next>prev)
        {
        //	cout<<next<<"  "<<prev<<"\n";
            next=next-prev;
           
		   prev=next+prev;	
		}
        else
        {
        	prev=next;
		}
          
        val=val+next;
         cout<<val<<"\n";
    }
    return val;
    
}
int main()
{
  cout<<romanToInt("MDCCCIV");
}
