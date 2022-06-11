/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: Will Wang [chengti4]
TASK: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int wday[2][12]=
{
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};
int getDay(int day)
{
    return day % 7;
}
int main() {
    //ofstream fout ("friday.out");
    //ifstream fin ("friday.in");
    int n;
    cin >> n;
    int isleap;
    int days = 1;
    int week[7] = {0};
    for(int i=0; i<n; i++)
    {
        if((i+1900)%4==0 and ((i+1900)%100!=0) or (i+1900)%400==0)
        {
            isleap = 1;
        }
        else
        {
            
            isleap = 0;
        }
        for(int j=1; j<=12; j++)
        {
            if(j==4 or j==6 or j==9 or j==11)
            {
                for(int k=0; k<30; k++)
                {
                    days += 1;
                    if(k == 12) week[getDay(days)] += 1;
                }
            }
            else if(j == 2)
            {
                if(isleap)
                {
                    for(int k=0; k<29; k++)
                    {
                        days += 1;
                        if(k == 12) week[getDay(days)] += 1;
                    }
                }
                else
                {
                    for(int k=0; k<28; k++)
                    {
                        days += 1;
                        if(k == 12) week[getDay(days)] += 1;
                    }
                }
            }
            else
            {
                for(int k=0; k<31; k++)
                {
                    days += 1;
                    if(k == 12) week[getDay(days)] += 1;
                }
            }
        }
    }
    int count = 0;
    for(int i : week)
    {
        count++;
        cout << i;
        if(count != 7) cout << " ";
    }
}