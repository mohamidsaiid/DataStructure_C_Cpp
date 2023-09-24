#include <iostream>
using namespace std;

class Node
{
public:
    Node *rchild;
    Node *lchild;
    int data;
    int height;
};

class AVL {
public:
    Node *root;
    AVL() { root = nullptr; }

    Node *newnode(int val) {
        Node *p = new Node;
        p->data = val;
        p->rchild = p->lchild = nullptr;
        return p;
    }

    int nodeheight(Node *p) {
        int x, y;
        x = (p && p->lchild) ? p->lchild->height : 0;
        y = (p && p->rchild) ? p->rchild->height : 0;
        return x > y ? x + 1 : y + 1;
    }

    int balancefactor(Node *p)
    {
        int x, y;
        x = (p && p->lchild) ? p->lchild->height : 0;
        y = (p && p->rchild) ? p->rchild->height : 0;
        return x-y;
    }

    Node *LLrotation(Node *p)
    {
        Node *pl = p->lchild;
        Node *plr = pl->rchild;

        pl->rchild = p;
        p->lchild = plr;
        p->height  = nodeheight(p);
        pl->height = nodeheight(pl);

        if (root == p)  root = pl;
        return pl;
    }

    Node *LRrotation(Node *p)
    {
        Node *pl = p->lchild;
        Node *plr = pl->rchild;


        p->lchild = plr->rchild;
        pl->rchild = plr->lchild;
        plr -> rchild = p;
        plr->lchild = pl;

        pl->height = nodeheight(pl);
        plr->height = nodeheight(plr);
        p->height = nodeheight(p);
        if (p == root) root = plr;
        return plr;
    }

    Node *RRrotation(Node *p)
    {
        Node *pr = p->rchild;
        Node *prl = pr->lchild;

        pr->lchild = p;
        p->rchild = prl;
        p->height = nodeheight(p);
        pr->height = nodeheight(pr);
        if (root == p) root  = pr;
        return pr;
    }

    Node *RLrotation(Node *p)
    {
        Node *pr = p->rchild;
        Node *prl = pr->lchild;

        p->rchild = prl->lchild;
        pr->rchild = prl->lchild;
        prl -> rchild = p;
        prl->lchild = pr;

        pr -> height = nodeheight(pr);
        prl-> height = nodeheight(prl);
        p->height = nodeheight(p);
        if (p == root) root = prl;
        return prl;
    }

    Node *insert(Node *p, int val)
    {
        if (p == nullptr) return newnode(val);

        if (val < p->data) p->lchild = insert(p->lchild, val);
        else if (val > p->data) p -> rchild = insert(p->rchild, val);

        p->height = nodeheight(p);
        if (balancefactor(p) == 2 && balancefactor(p->lchild) == 1)
            return LLrotation(p);
        else if (balancefactor(p) == 2 && balancefactor(p->lchild) == -1)
            return LRrotation(p);
        else if (balancefactor(p) == -2 && balancefactor(p->rchild) == -1)
            return RRrotation(p);
        else if(balancefactor(p) == -2 && balancefactor(p->rchild) == 1)
            return RLrotation(p);

        return p;
    }

    void Inorder(Node *p)
    {
        if (p)
        {
            Inorder(p->lchild);
            cout << p->data << ' ';
            Inorder(p->rchild);
        }
    }
    void Inorder(){ Inorder(root);}
};
int main() {

    AVL x;

    x.root = x.insert(x.root,10);
    x.insert(x.root, 20);
    x.insert(x.root, 30);
    x.insert(x.root, 25);
    x.insert(x.root, 28);
    x.insert(x.root, 27);
    x.insert(x.root, 5);
    x.Inorder();
    return 0;
}
