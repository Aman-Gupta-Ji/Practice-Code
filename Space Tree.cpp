#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> parent;
vector<int> locked_child;
vector<vector<int>> children;
vector<int> mutex;

void inform_all_parent(int node, int userid, int plus, map<int, unordered_map<int, int>> &count, unordered_map<int, unordered_set<int>> &des_node, int original_node)
{
    if (plus == 1)
    {
        locked_child[node] += plus;
        count[node][userid] += plus;
        des_node[node].insert(original_node);
    }
    else
    {
        locked_child[node] -= plus;
        count[node][userid] -= plus;
        if (count[node][userid] == 0)
        {
            count.erase(node);
        }
        des_node[node].erase(original_node);
    }
    if (parent[node] != -1)
    {
        inform_all_parent(parent[node], userid, plus, count, des_node, original_node);
    }
}

bool validate_child(int node, int userid, unordered_map<int, int> &lock, map<int, unordered_map<int, int>> &count, unordered_map<int, unordered_set<int>> &des_node)
{
    if (lock.find(node) != lock.end() && locked_child[node] != 0)
    {
        return false;
    }
    if (parent[node] != -1)
    {

        inform_all_parent(parent[node], userid, 1, count, des_node, node);
    }

    return true;
}

bool validate(int node, int userId, unordered_map<int, int> &lock, map<int, unordered_map<int, int>> &count, unordered_map<int, unordered_set<int>> &des_node)
{
    if (lock.find(node) != lock.end())
    {
        return false;
    }
    int copy_node = node;

    while (parent[node] != -1)
    {
        if (lock.find(parent[node]) != lock.end())
        {
            return false;
        }
        node = parent[node];
    }
    node = copy_node;

    if (!validate_child(node, userId, lock, count, des_node))
        return false;
    lock[copy_node] = userId;

    return true;
}

bool unlock(int node, int userId, unordered_map<int, int> &lock, map<int, unordered_map<int, int>> &count, unordered_map<int, unordered_set<int>> &des_node)
{
    if (lock.find(node) == lock.end())
    {
        return false;
    }
    if (lock[node] == userId)
    {
        lock.erase(node);
        if (parent[node] != -1)
        {
            inform_all_parent(parent[node], userId, -1, count, des_node, node);
        }

        return true;
    }
    return false;
}

bool upgrade(int node, int userid, unordered_map<int, int> &lock, map<int, unordered_map<int, int>> &count, unordered_map<int, unordered_set<int>> &des_node)
{
    if (lock.find(node) != lock.end())
    {
        return false;
    }
    int size = count[node].size();
    if (size != 1)
    {
        return false;
    }
    if (count[node].find(userid) == count[node].end())
    {
        return false;
    }
    lock[node] = userid;
    if (parent[node] != -1)
    {
        inform_all_parent(parent[node], userid, 1, count, des_node, node);
    }
    for (auto it : des_node[node])
    {
        unlock(it, lock[it], lock, count, des_node);
    }
    return true;
}
void signal(int node, vector<queue<int>> &locked_by)
{
    if (locked_by[node].empty())
    {
        return;
    }
    if (mutex[node] == 1)
    {
        mutex[node]--;
    }
    else
    {
        return;
    }
    int userid = locked_by[node].front();
    locked_by[node].pop();
    bool ans = validate(node, userId, lock, count, des_node);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    mutex[node]++;
    if (mutex[node] > 0)
    {
        signal(node, locked_by);
    }
}

int main()
{

    unordered_map<string, int> hash;
    unordered_map<int, int> lock;
    map<int, unordered_map<int, int>> count;
    unordered_map<int, unordered_set<int>> des_node;
    vector<queue<int>> locked_by;

    int node, child, queries;
    cin >> node >> child >> queries;

    parent.resize(node, -1);
    locked_child.resize(node, 0);
    children.resize(node);
    mutex.resize(node, 1);

    for (int i = 0; i < node; i++)
    {
        string s;
        cin >> s;
        hash[s] = i;
    }

    vector<vector<int>> tree(node);
    queue<int> help_make_tree;
    help_make_tree.push(0);

    for (int i = 0, j = 1; i < node; i++)
    {
        if (j >= node)
            break;
        for (int k = j; k < j + child && k < node; k++)
        {
            tree[i].push_back(k);
            parent[k] = i;
            children[i].push_back(k);
        }
        j += child;
    }

    for (int i = 0; i < queries; i++)
    {
        int type, userId;
        string name;
        cin >> type >> name >> userId;
        int node = hash[name];

        if (type == 1)
        {

            bool ans = validate(node, userId, lock, count, des_node);
            if (ans)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (type == 2)
        {
            bool ans = unlock(node, userId, lock, count, des_node);
            if (ans)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else
        {
            bool ans = upgrade(node, userId, lock, count, des_node);
            if (ans)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
    }
    return 0;
}