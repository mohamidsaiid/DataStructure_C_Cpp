#include <iostream>
#include <set>
using namespace std;


class Node
{
public:
    Node *rchild;
    Node *lchild;
    int data;
};

class BSTM
{
public:
    Node *root;
    BSTM(){root = NULL;}
    Node * newnode(int val)
    {
        Node *t = new Node;
        t->data = val;
        t->rchild = t->lchild = NULL;
        return t;
    }
    void insert(int val)
    {
        Node *x= root, *y;
        if (root == NULL)
        {
            root = newnode(val);
            return;
        }
        while (x != NULL)
        {
            y = x;
            if (val > x->data) x = x->rchild;
            else if (val < x->data) x = x->lchild;
            else return;
        }
        if (val > y->data)
        {
            y->rchild = newnode(val);
        }
        else
        {
            y->lchild = newnode(val);
        }
    }
    void rinsert(int x){ rinsert(root,x);}
    Node *rinsert(Node *p,int x)
    {
        if (p == NULL)
        {
            return newnode(x);
        }
        if (x < p->data)
            p->lchild = rinsert(p->lchild,x);
        else if(x > p->data)
            p->rchild = rinsert(p->rchild,x);
        return p;
    }
    bool search(int x)
    {
        Node *t = root;
        while (t != NULL)
        {
            if (x > t->data) t = t->rchild;
            else if (x < t->data) t = t->lchild;
            else return true;
        }
        return false;
    }

    Node * erase(Node *p, int key)
    {
        Node *q;
        if (p == NULL)
            return NULL;
        if (p->rchild == NULL && p->lchild == NULL)
        {
            if (p == root) root = NULL;
            delete p;
            return NULL;
        }
        if (key < p->data) p->lchild = erase(p->lchild, key);
        else if(key > p->data) p->rchild = erase(p->rchild,key);
        else
        {
            if(height(p->lchild) > height (p->rchild))
            {
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = erase(p->lchild,q->data);
            }
            else
            {
                q = InSec(p->rchild);
                p->data = q->data;
                p->rchild = erase(p->rchild,q->data);
            }
        }
        return p;
    }
    void Inorder(){ Inorder(root);}
    void Inorder(Node *t)
    {
        if (t)
        {
            Inorder(t->lchild);
            cout << t->data << " ";
            Inorder(t->rchild);
        }
    }
    void preorder(Node *p)
    {
        if(p)
        {
            cout << p->data << " ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }
    int height (Node *p)
    {
        int x,y;
        if (p == NULL) return 0;
        x = height(p->lchild);
        y = height(p->rchild);
        return (x>y)? x + 1: y+1;
    }

    Node *InSec(Node *p)
    {
        while (p && p->lchild)
            p = p->lchild;
        return p;
    }
    Node *InPre(Node *p)
    {
        while (p && p->rchild)
            p = p->rchild;

        return p;
    }
};

int main() {
    BSTM tt;
    tt.root=tt.rinsert(tt.root,5);
    tt.rinsert(tt.root,7);
    tt.rinsert(tt.root,9);
    tt.rinsert(tt.root,2);
    tt.rinsert(tt.root,3);
    tt.rinsert(tt.root,5);
    tt.rinsert(tt.root,13);
    tt.Inorder(tt.root);
    tt.erase(tt.root,2);
    tt.Inorder(tt.root);
    cout << '\n';
    return 0;
}
