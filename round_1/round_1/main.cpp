#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


using namespace std;

void storeData(vector<vector<int>>& vect,int T,int N)
{
    for(int i=0;i<T;i++)
    {
        cin>>N;
        vect[i] = vector<int>(N);
        for(int j=0;j<N;j++)
        {
            cin>>vect[i][j];
        }
    }
}

void printData(vector<vector<int>> vect,int T,int N)
{
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
}

int findMinElementIndex(vector<int> v,int j)
{
    vector<int>::iterator result = min_element(v.begin()+j, v.end());
    //cout << "min element at: " << distance(v.begin(), result);
    return (int) distance(v.begin(), result);
}

int reverseSubArray(vector<int> &v,int i,int j)
{
    reverse(v.begin()+i, v.begin()+j+1);
    //cout<<v.size()-1<<endl;
    //cout<< j-i+1<<endl;
//    cout<<"i :"<<i<<" && j :"<<j<<endl;
//    for(int i=0;i<v.size();i++)
//    {
//        cout<<v[i]<<" ";
//    }
//    cout<<endl;
    return j-i+1;
}

int calculateCost(vector<int> & vect)
{
    int Cost = 0,foundIndex=0;
    for(int j=0;j<vect.size()-1;j++)
    {
        foundIndex = findMinElementIndex(vect,j);
        Cost += reverseSubArray(vect,j,foundIndex);
    }
    return Cost;
}

int main()
{
    //TODO[1] => Data Structure -|
    int T=0,N=0;
    cin>>T;
    vector<vector<int>> vect(T);

    storeData(vect,T,N);
    
    for(int i=0;i<T;i++)
    {
        cout<<"Case #"<<i+1<<": "<<calculateCost(vect[i])<<endl;
    }
         

    //DISPLAY
    //printData(vect,T,N);
}
