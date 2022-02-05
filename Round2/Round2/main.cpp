#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Data{
    int x;
    int y;
    string s;
};

//passing array by value is impossible
void printData(struct Data d[],int T)
{
    for(int i=0;i<T;i++)
        cout<<d[i].x<<" "<<d[i].y<<" "<<d[i].s<<endl;
    cout<<endl;
}

void getData(struct Data *d,int T)
{
    for(int i=0;i<T;i++)
    {
        cin>>d[i].x>>d[i].y>>d[i].s;
    }
}

int countFreq(string &pat, string &txt)
{
    int M = (int)pat.length();
    int N = (int)txt.length();
    int res = 0;
   
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        /* For current index i, check for
           pattern match */
        int j;
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j])
                break;
  
        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M)
        {
           res++;
        }
    }
    return res;
}

void calcMinCosts(struct Data d[],string *sub,char C, int T)
{
    for(int i=0;i<T;i++)
    {
        d[i].s.erase(remove(d[i].s.begin(), d[i].s.end(), C),d[i].s.end());
        
        int count_CJ = countFreq(sub[0],d[i].s);
        int count_JC = countFreq(sub[1],d[i].s);
        
        int cost = count_CJ*d[i].x + count_JC*d[i].y ;
        
        cout<<"Case #"<<i+1<<": "<< cost <<endl;
    }
}

int main()
{
    struct Data* d;
    int T=0;
    cin>>T;
    d = new Data[T];
    string sub[2] = {"CJ","JC"};
    char C = '?';
    
    getData(d,T);
    
    //d[0].s.replace(0, 6, "sharma");
    //replace( d[0].s.begin(), d[0].s.end(), '?', '');
    calcMinCosts(d, sub,C,T);
    
    //printData(d, T);
}
