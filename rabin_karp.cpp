#include<bits/stdc++.h>
#define limit 256
using namespace std;
 void search(string pattern, string text, int prime)
{    int hash_pattern = 0; 
     int hash_text = 0; 
    int M = pattern.length();
    int N = text.length();
    int h = 1;
     int i, j;
    for (i = 0; i < M-1; i++) //h=pow(limit, M-1)%prime
        h = (h*limit)%prime;
    for (i = 0; i < M; i++)
    {
       hash_pattern = (limit*hash_pattern + pattern[i])%prime;
        hash_text = (limit*hash_text + text[i])%prime;
    }
    for (i = 0; i <= N - M; i++)
    {
        if ( hash_pattern == hash_text )  //if hash value matches check characters
        {
            for (j = 0; j < M; j++)
            {
                if (text[i+j] != pattern[j])
                    break;
            }
            if (j == M)
                cout<<"pattern found at index = "<<i;
        }
 
        if ( i < N-M )
        {
            hash_text = (limit*(hash_text - text[i]*h) + text[i+M])%prime;
            if (hash_text < 0)
            hash_text = (hash_text + prime); //if hash_text gets negative
        }
    }
}
int main()
{   
    string text,pattern;
    cout<<"Enter  text from where pattern will be searched \n";
    cin>>text;
    cout<<"Enter  pattern \n";
    cin>>pattern;
    int prime;
    cout<<"Enter a prime  for creating hash \n";
    cin>>prime;
    search(pattern, text, prime);
    return 0;
}
