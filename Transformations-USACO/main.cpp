/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: Will Wang [chengti4]
TASK: transform
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    
    int n;
    fin >> n;
    char a[n][n];
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                {
                    fin >> a[i][j];
                }
        }
    char b[n][n];
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                {
                    fin >> b[i][j];
                }
        }
    
    char c[n][n];
    int alr = 0;
    char d[n][n];
    memcpy(d, a, sizeof(a));
    for(int k=1; k<4; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    {
                        c[j][n-i-1] = a[i][j];
                    }
            }
            if(memcmp(b,c,sizeof(b))==0)
            {
                fout << k;
                alr = 1;
                break;
            }
        memcpy(a, c, sizeof(a));
        }
    memcpy(a, d, sizeof(a));
    if(alr == 0)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                {
                    c[i][n-j-1] = a[i][j];
                }
        }
        if(memcmp(b,c,sizeof(b))==0)
        {
            fout << 4;
            alr = 1;
        }
        else
        {
            memcpy(a, c, sizeof(a));
            for(int k=1; k<4; k++)
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                        {
                            c[j][n-i-1] = a[i][j];
                        }
                }
                if(memcmp(b,c,sizeof(b))==0)
                {
                    fout << 5;
                    alr = 1;
                    break;
                }
                memcpy(a, c, sizeof(a));
            }
        }
    }
    if(alr == 0)
    {
        if(memcmp(d,b,sizeof(b))==0)
        {
            fout << 6;
        }
        else
        {
            fout << 7;
        }
    }
    fout << endl;
}