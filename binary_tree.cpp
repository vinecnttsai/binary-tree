
#include <iostream>

using namespace std;
struct tree
{
    int val;
    tree* c_l;
    tree* c_r;
    tree* p;
};
tree *t=new tree;
void build(tree *a,tree* p,tree* c_l,tree* c_r,bool isright)
{
    a->p=p;
    if(isright)p->c_r=a;
    else p->c_l=a;
    a->c_r=c_r;
    a->c_l=c_l;
}
void insert(tree *a,int val)
{
    tree* p=t;
    a->val=val;
    while(true)
    {
        if(p->val>a->val)
        {
            if(p->c_l==NULL)
            {
                build(a,p,NULL,NULL,0);
                return;
            }
            p=p->c_l;
        }
        else
        {
            if(p->c_r==NULL)
            {
                build(a,p,NULL,NULL,1);
                return;
            }
            p=p->c_r;
        }
    }
    
}
void preorder(tree* tre)
{
    tree* p=tre;
    if(p)
    {
        cout<<p->val<<" ";
        preorder(p->c_l);
        preorder(p->c_r);
    }
}
void inorder(tree* tre)
{
    tree* p=tre;
    if(p)
    {
        preorder(p->c_l);
        cout<<p->val<<" ";
        preorder(p->c_r);
    }
}
void postorder(tree* tre)
{
    tree* p=tre;
    if(p)
    {
        preorder(p->c_l);
        preorder(p->c_r);
        cout<<p->val<<" ";
    }
}
int main()
{
    int k=10,n;
    t->p=NULL;
    t->c_l=NULL;
    t->c_r=NULL;
    t->val=30;
    while(k--)
    {
        cin>>n;
        tree *i=new tree;
        insert(i,n);
    }
    cout<<endl;
    preorder(t);
    cout<<endl;
    inorder(t);
    cout<<endl;

    return 0;
}
