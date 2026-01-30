#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }

};
Node* binary_input()
{
    int val;
    cin>>val;
    Node* root; 
    if(val==-1) root=NULL;
    else
    root= new Node(val);

    queue<Node*>q;
    if(root !=NULL)
   q.push(root);
   while (!q.empty())
   {
   Node* p=q.front();
   q.pop();

   int l,r;
   cin>>l>>r;
   Node* myleft,*myright;
   if(l==-1) myleft=NULL;
   else myleft=new Node(l);
   if(r==-1) myright=NULL;
   else myright=new Node(r);
   p->left=myleft;
   p->right=myright;
   if(p->left) q.push(p->left);
   if(p->right) q.push(p->right);
   }
   return root;
}
int max_height(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    int l=max_height(root->left);
    int r= max_height(root->right);
   
    return max(l,r)+1;
}
 void level_Nodes(Node* root,int x)
{
 if(root==NULL) return;
 if(x==0){
    cout<<root->val<<" ";
    return;
 }
 level_Nodes(root->left,x-1);
 level_Nodes(root->right,x-1);

}
int main()
{
 Node* root= binary_input();
 int x;
 cin>>x;
 int height= max_height(root);
 if(height>x)
 level_Nodes(root,x);
 else 
 cout<<"Invalid";
  return 0;
}