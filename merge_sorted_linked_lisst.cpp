#include <iostream>
#include <list>
using namespace std;

int show_element(list<int> l, int index)
{
    if (index < l.size())
    {
        list<int>::iterator it = l.begin();
        for (int i=0;i<index;i++)
        {
            it++;
        }
        return *it;
    }
}
void show_list(list<int> Lis)
{
    list<int>::iterator it =Lis.begin();
    for (int i=0; i<Lis.size();i++)
    {
        cout<<*it<<" ";
        it++;
    }
}
int main()
{
    list<int> L1{1,3,5,7,9}, L2{2,4,6,8,10},L3;
    int pos1=0, pos2=0;
    while(pos1<L1.size() && pos2<L2.size())
    {   
        if(show_element(L1,pos1)<show_element(L2,pos2))
        {
            L3.push_back(show_element(L1,pos1));
            pos1++;
        }
        else
        {
            L3.push_back(show_element(L2,pos2));
            pos2++;
        }
    }
    while(pos1<L1.size())
    {
        L3.push_back(show_element(L1,pos1));
        pos1++;
    }
    while(pos2<L2.size())
    {
        L3.push_back(show_element(L2,pos2));
        pos2++;
    }
    show_list(L3);
    return 0;
}