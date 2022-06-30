#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    Node *Lchild;
    int data;
    Node *Rchild;
};

class Tree
{
private:
    Node *root;

public:
    Tree() { root = NULL; }
    void createTree();
    void PostOrder();
    int count(Node *p);
    Node *getRoot() { return root; }
};

int Tree::count(Node *p)
{
    int x, y;
    if (p)
    {
        x = count(p->Lchild);
        y = count(p->Rchild);
        return x + y + 1;
    }
    return 0;
}

void Tree::createTree()
{
    Node *t, *p;
    int x;
    queue<Node *> q;
    root = new Node;
    cout << "Enter Root Node ";
    cin >> x;
    root->data = x;
    root->Lchild = NULL;
    root->Rchild = NULL;
    q.emplace(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter Left Child for " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->Lchild = NULL;
            t->Rchild = NULL;
            p->Lchild = t;
            q.emplace(t);
        }
        cout << "Enter Right Child for " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->Lchild = NULL;
            t->Rchild = NULL;
            p->Rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::PostOrder()
{
    stack<Node *> st;
    Node *p = root;
    Node *temp;
    while (p != NULL || !st.empty())
    {
        if (p != NULL)
        {
            st.emplace(p);
            p = p->Lchild;
        }
        else
        {
            temp = st.top()->Rchild;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while (!st.empty() && st.top()->Rchild == temp)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                p = temp;
            }
        }
    }
}

int main()
{
    Tree T;
    T.createTree();
    T.PostOrder();
    Node *root = T.getRoot();
    cout << endl;
    cout << "Number of node in this tree is " << T.count(root);
}