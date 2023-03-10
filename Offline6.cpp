#include <bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
#define S second
#define F first
#define ll long long int
bool comparefn(pr a, pr b)
{
    if(b.S==a.S)return a.F<b.F;
    return b.S>a.S;
}

int main()
{
    freopen("in.txt","r+",stdin);
    int n,x,y;
    int i=0;
    int willfree=0;

    cin>>n;
    vector<pair<int,int>>customer_info,serve_List;

    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        customer_info.push_back(make_pair(x,y));
    }

    sort(customer_info.begin(),customer_info.end(),comparefn);
    
    //for printing the lst after sorting 
    // for(int i=0;i<n;i++)
    // {
    //     cout<<customer_info[i].first<<" "<<customer_info[i].second<<endl;
    // }

    while(i<n)
    {
        if(i==0)
        {   
            serve_List.push_back(customer_info[i]);
            willfree=customer_info[i].second;
        }
        else{
            if(customer_info[i].first>=willfree)
            {
            serve_List.push_back(customer_info[i]);
            willfree=customer_info[i].second;
            }
        }
        i++;
    }
    //printing serve list
    cout<<serve_List.size()<<endl;
    for( int i=0;i<serve_List.size();i++)
    {
        cout<<serve_List[i].first<<" "<<serve_List[i].second;
        cout<<endl;
    }
    return 0;
}