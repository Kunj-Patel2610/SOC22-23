#include <iostream>
#include <list>

using namespace std;

void show_list(list<int> Lis)
{
    list<int>::iterator it =Lis.begin();
    for (int i=0; i<Lis.size();i++)
    {
        cout<<*it<<" ";
        it++;
    }
}

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
    else
    {
        return -1;
    }
}

list<int> merge_sorted_list (list<int> a, list<int> b);

list<int> sort(list<int> L)
{   
    list<int> L1,L2,L3;
    int size = L.size();
    if (size == 1)
    {
        return L;
    }
    else
    {
        int i;
        for(i=0;i<size/2;i++)
        {
            
            L1.push_back(L.front());
            L.pop_front();
        }
        for(i=(size/2);i<size;i++)
        {
            
            L2.push_back(L.front());
            L.pop_front();
        }
    }
    L1 = sort(L1);
    L2 = sort(L2);
    L3 = merge_sorted_list(L1,L2);
    return L3;
}

list<int> merge_sorted_list (list<int> a, list<int> b)
{
    list<int> c;
    int pos1=0, pos2=0;
    while(pos1<a.size() && pos2<b.size())
    {   
        if(show_element(a,pos1)<show_element(b,pos2))
        {
            c.push_back(show_element(a,pos1));
            pos1++;
        }
        else
        {
            c.push_back(show_element(b,pos2));
            pos2++;
        }
    }
    while(pos1<a.size())
    {
        c.push_back(show_element(a,pos1));
        pos1++;
    }
    while(pos2<b.size())
    {
        c.push_back(show_element(b,pos2));
        pos2++;
    }
    return c;
}
int main()
{
    list<int> L1{10,9,8,78,9,5,41,65,21,47,58,125,154,225,2214};
    //cout << L1.size() << endl;
    L1 = sort (L1);
    cout << "Sorted:";
    show_list(L1);
    return 0;

}