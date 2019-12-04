#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int CountLeaf_by_bfs(vector<vector<int>> tree, int root_node_num, int deleted_node_num)
{
    int n_leaf = 0;

    queue<int> q;
    q.push(root_node_num);

    while(!q.empty())
    {
        int node_num = q.front();
        q.pop();

        bool node_is_leaf = true;
        for(int children_node_num:tree[node_num])
        {
            if(children_node_num != deleted_node_num)
            {
                node_is_leaf = false;
                q.push(children_node_num);
            }
        }

        if(node_is_leaf == true) n_leaf++;
    }

    return n_leaf;
}

int main ()
{
    int n;
    cin >> n;

    vector<vector<int>> tree; tree.resize(n);

    int root_node_num;
    for(int i = 0; i < n; i++)
    {   
        int parent_node_num;
        cin >> parent_node_num;

        if(parent_node_num == -1)//자식이 부모가 없는 경우 = i 번째 노드는 루트다.
        {
            root_node_num = i;
            continue;
        }

        tree[parent_node_num].push_back(i); //부모에서 자식 연결
    }

    int deleted_node_num;
    cin >> deleted_node_num;
    tree[deleted_node_num].clear();//트리 연결 끊기

    if(deleted_node_num == root_node_num) cout << 0 << endl;
    else
    {
        cout << CountLeaf_by_bfs(tree, root_node_num, deleted_node_num) << endl;
    }

    return 0;
}
