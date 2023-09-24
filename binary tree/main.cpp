#include <iostream>
#include "Queue.h"
using namespace std;

class Tree {
public:
    Node *root;

    Tree() { root = NULL; }

    void create() {
        Queue q(100);
        Node *p, *t = NULL;
        int x;
        cout << "Enter the root val : ";
        cin >> x;
        root = new Node;
        root->lchild = root->rchild = NULL;
        root->data = x;
        q.enqueue(root);
        while (!q.isEmpty()) {
            p = q.dequeue();
            cout << "Enter the left val for " << p->data << " ";
            cin >> x;
            if (x != -1) {
                t = new Node;
                t->data = x;
                t->rchild = t->lchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "Enter the right child val for " << p->data << " ";
            cin >> x;
            if (x != -1) {
                t = new Node;
                t->data = x;
                t->rchild = t->lchild = NULL;
                p->rchild = t;
                q.enqueue(t);
            }
        }
    }

    void Inorder(Node *p) {
        if (p) {
            Inorder(p->lchild);
            cout << p->data << ' ';
            Inorder(p->rchild);
        }
    }

    void Preorder() { Preorder(root); }

    void Inorder() { Inorder(root); }

    void Postorder() { Postorder(root); }

    void Preorder(Node *p) {
        if (p) {
            cout << p->data << ' ';
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }

    void Postorder(Node *p) {
        if (p) {
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout << p->data << ' ';
        }
    }
    void levelorder(){ levelorder(root);}
    void levelorder(Node *p)
    {
        Node *t = NULL;
        Queue x(100);
        cout << p->data << " ";
        x.enqueue(p);
        while(!x.isEmpty())
        {
            p = x.dequeue();
            if(p->lchild)
            {
                cout << p->lchild->data << " ";
                x.enqueue(p->lchild);
            }
            if (p->rchild) {
                cout << p->rchild->data << " ";
                x.enqueue(p->rchild);
            }
        }
    }

    int count(Node *p)
    {
        if (p == NULL)
            return 0;
        return count(p->lchild) + count(p->rchild) + 1;
    }
    int countleaf(Node *p)
    {
        if (p->lchild == NULL && p->rchild == NULL)
            return 1;
        return countleaf(p->lchild) + countleaf(p->rchild);
    }
    int height(Node *p)
    {
        int x, y;
        if (p != NULL){
            x = height(p->lchild);
            y = height(p->rchild);
            if(x > y) return x+1;
            else return y + 1;
        }
        return 0;
    }

    int leaf(Node *p)
    {
        int x, y;
        if (p != NULL){
            x = height(p->lchild);
            y = height(p->rchild);
            if(p->rchild == NULL && p->lchild == NULL) return x + y + 1;
            else return x + y;
        }
        return 0;
    }
};


int main() {

    Tree t;
    t.create();
    t.Preorder();
    cout << "\n";
    t.Postorder();
    cout << '\n';
    t.Inorder();
    cout << '\n';
    t.levelorder();
    cout << '\n';
    cout << t.count(t.root) << " ";
    cout << t.leaf(t.root) << " ";
    return 0;
}
