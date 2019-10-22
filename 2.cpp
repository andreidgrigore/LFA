#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
ifstream fin("intrare.in");

struct Transition {
    int source, destination;
    char input_letter;
    char top_of_stack;
    string stack_replace;
};

class APD {
    int size;
    stack<char> st;
    vector<bool> isfinal;
    vector<Transition> apd;
    public:
        APD(int = 0);
        void addTransition(int, int, char, char, string);
        void setFinal(int x) { isfinal[x] = true; };
        void test(string);
        void DFS(string, int, int, bool&);
};

APD::APD(int x) : size(x) {
    isfinal.assign(size, false);
    st.push('Z');
}

void APD::addTransition(int st, int dr, char in, char top, string replace){
    this->apd.push_back((Transition){st, dr, in, top, replace});
}
void APD::test(string word) {
    bool t = false;
    this->DFS(word, 0, 0, t);
    if(t == true)
        cout<<"Cuvant acceptat"<<endl;
    else cout<<"Cuvant neacceptat"<<endl;
}
void APD::DFS(string word, int pos, int q, bool& tester) {
    if(tester == true)
        return;
    if(word.length() == pos && (st.top() == 'Z' || st.empty() == true)){
        if(isfinal[q] == true)
            tester = true;
        else {
            for(int i=0; i<size; i++)
                if(apd[i].source == q && apd[i].input_letter == '0' && apd[i].stack_replace == "0")
                    DFS(word, pos, apd[i].destination, tester);
        }
    }
    else
        for(int i=0; i<size; i++)
            if(apd[i].source == q && apd[i].input_letter == word[pos] && st.top() == apd[i].top_of_stack){
                st.pop();
                if(apd[i].stack_replace != "0")
                    for(int j = apd[i].stack_replace.length()-1; j>=0; j--)
                        st.push(apd[i].stack_replace[j]);
                DFS(word, pos+1, apd[i].destination, tester);
           }
}

int main(){
    int n, m;
    fin>>n>>m;
    APD a(m);
    int i, x, y;
    char c, t;
    string r;
    for(i=1; i<=m; i++){
        fin>>x>>y>>c>>t>>r;
        a.addTransition(x, y, c, t, r);
    }
    int k;
    fin>>k;
    for(i=1; i<=k; i++){
        fin>>x;
        a.setFinal(x);
    }
    a.test("aaaabbccccccdd");

    return 0;
}
