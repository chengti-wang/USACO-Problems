/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: Will Wang [chengti4]
TASK: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n;
string s; 

int check_forward(int i)
{
    int head;
    if(i == n-1)
    {
        head = s[0];
        i = 0;
    }
    else
    {
        head = s[i+1];
        i++;
    } 
    int length = 1;

    if (head == 'w')
    {
        while(1)
        {
            i++;
            length++;
            if(i == n) i=0;
            if(s[i] != 'w' or length >= n)
            {
                head = s[i];
                break;
            }
            
        }
    }
    while(1)
    {
        i++;
        if(i==n) i=0;
        if (s[i] != head and s[i] != 'w' or length >= n)
        {
            break;
        }
        length++;
    }
    return length;
}

int check_backward(int i)
{
    int head = s[i];
    int length = 1;

    if (head == 'w')
    {
        while(1)
        {
            i--;
            length++;
            if(i == -1) i=n-1;
            if(s[i] != 'w' or length >= n)
            {
                head = s[i];
                break;
            }
            
        }
    }
    while(1)
    {
        i--;
        if(i==-1) i=n-1;
        
        if (s[i] != head and s[i] != 'w' or length >= n)
        {
            break;
        }
        length++;
    }
    return length;
}


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    
    
    fin >> n >> s;
    int biggest = 0;  
    for(int i=0; i<n; i++)
    {
        int forward = check_forward(i);
        int backward = check_backward(i);
        int sum = forward + backward;
        if(sum>n) sum = n;
        if(sum > biggest)
        {
            //cout << forward << " " << backward << " " << i << endl;
            biggest = sum;
        }
    }

    fout << biggest << endl;
}