/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: Will Wang [chengti4]
TASK: barn1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}
int main()
{
    // ofstream fout ("barn1.out");
    // ifstream fin ("barn1.in");

    int m, s, c;
    cin >> m >> s >> c;
    int a[c];
    int diffs[c-1];
    for(int i=0; i<c; i++)
    {
        cin >> a[i];
    }
    int first = a[0];
    for(int i=1; i<c; i++)
    {
        int diff = a[i] - first;
        first = a[i];
        diffs[i-1] = diff;
    }
    sort(diffs, diffs+c-1, cmp);
    int range = a[c-1] - a[0] + m*2;
    for(int i=0; i<m; i++)
    {
        range -= diffs[i];
    }
    cout << range << endl;
}

