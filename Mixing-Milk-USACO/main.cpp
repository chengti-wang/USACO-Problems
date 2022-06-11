/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: Will Wang [chengti4]
TASK: milk
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int n,m;
    fin >> n >> m;
    pair <int,int> a[m];
    for(int i=0; i<m; i++)
    {
        fin >> a[i].first >> a[i].second;
    }
    sort(a, a+m);

    int total = 0; 
    int num = 0;
    int flag = 0;
    for(int i=0; i<m; i++)
    {
        if(num + a[i].second >= n)
        {
            total += (n - num) * a[i].first;
            fout << total << endl;
            flag = 1;
            break;
        }
        else
        {
            total += a[i].first * a[i].second;
            num += a[i].second;
        }
    }
    if(flag == 0) fout << "0" << endl;
}

