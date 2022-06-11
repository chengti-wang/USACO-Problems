/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: Will Wang [chengti4]
TASK: crypt1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int useDig[10];

bool inSet(int a)
{
	while(a > 0)
	{
		if(useDig[ a% 10]==0)	return false;
		a/=10;
	}

	return true;
}

int main()
{
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

	int n;
	fin >> n;
	int a[n];
	
	for(int i=0; i<n; i++)
	{
		fin >> a[i];
		useDig[a[i]] = 1;
	}
	sort(a, a+n);
	int counter = 0;
	for(int i=100; i<=999; i++)
	{
		for(int j=10; j<=99; j++)
		{
			// cout << i << " " << inSet(i) << endl;
			if(inSet(i) && inSet(j))
			{
				//cout << i << " " << j << endl;
				int first = i*(j%10);
				int second = i*(j/10);
				if(inSet(first) && inSet(second) && to_string(first).length() <= 3 && to_string(second).length() <= 3)
				{
					int p = i*j; 
					if(p<100000 && inSet(p))
					{
						// cout << i << " " << j << " " << p << endl;
						counter++;
					}
				}
			}
		}
	}

	fout << counter << endl;
}

