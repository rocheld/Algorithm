#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int val;
    int pre;
    int post;
    vector<node*> next;
    vector<node*> prev;
    bool visited;
    node(int v) : val(v), pre(0), post(0), visited(false) {};
};

int cc = 0;

void addEdge(node* u,node* v) {
    u->next.push_back(v);
    v->prev.push_back(u);
}
// DFS on G^R
void DFS1(node* curr, vector<node*>& st) {
    curr->visited = true;
    cout << "IN: " << curr->val << endl;
    for(int i=0; i < curr->prev.size(); i++) {
        node* next = curr->prev[i];
        if(next->visited == false) DFS1(next,st);
    }
    cout << "Out: " << curr->val << endl;
    st.push_back(curr);
}

void DFS2(node* curr,int count) {
    curr->visited = true;
    if(count >0) cout << "found" ;
    for(int i=0; i < curr->next.size(); i++) {
        node* next = curr->next[i];
        if(next->visited == false) DFS2(next,count+1);
    }
    cout << curr->val << " " << count;
}

int main() {
    cout << "===== Korasaju alogrithm =====" << endl;
    vector<node*> graph;
    vector<node*> st;
    node* v1 = new node(1);
    node* v2 = new node(2);
    node* v3 = new node(3);
    node* v4 = new node(4);
    node* v5 = new node(5);
    graph.push_back(v5);
    graph.push_back(v1);
    graph.push_back(v2);
    graph.push_back(v3);
    graph.push_back(v4);

    addEdge(v1,v2);
    addEdge(v1,v4);
    addEdge(v4,v5);
    addEdge(v5,v4);
    addEdge(v2,v3);
    queue<node*> que;
    que.push(graph[0]);
    for( node* &n : graph) {
        if(n->visited == false)
            DFS1(n,st);
    }

    for(int i=0; i < graph.size(); i ++) {
        graph[i]->visited = false;
    }
    int cc = 0;

    while(st.size() != 0) {
        cout << "SCC# "<< cc << ": ";
        node* curr = st.back(); st.pop_back();
        if(curr->visited == false) DFS2(curr,0);
        ++cc;
        cout << endl;
    }
    return 0;

}