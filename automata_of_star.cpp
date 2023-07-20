#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int end(0), start(0);         // start and end indices while generating automata

    class DFS
    {
        private :           // five parameters
            
            vector <int> vertices;
            string language;
            map <pair<int,char>,int> transitions;
            int start_vertice=0;
        public :
            vector <int> good_vertices;
            void automata_of_star (string s, int initial) ;       
    };

void DFS::automata_of_star (string s, int initial)      // initial is the value (index of the end vertice of the previous subpart of automata)
{
    if (s.length() == 1)
    {
        transitions.insert({{initial,s[0]},initial});
        ::end = initial;
        return;
    }
    int i;
    int temp = initial;
    for ( i = 0; i < s.length()-1; i++)
    {
        transitions.insert({{initial,s[i]},initial+1});
        initial ++;
        vertices.push_back(initial);
    }
    transitions.insert({{initial,s[i]},temp});
    ::end = temp;
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main()
{
    DFS dfs;
    string s = "abc";
    dfs.automata_of_star(s,::end);
    dfs.good_vertices.push_back(::end);
    
    
}
