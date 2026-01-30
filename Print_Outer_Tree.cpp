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
void left(Node* root)
{
    if(root==NULL) return;
 
        if(root->left){
             left(root->left);
        cout<<root->val<<" ";
      
        }
       else if(root->right){
         left(root->right);
            cout<<root->val<<" ";
           
        }
        else
        {
            left(root->left);
            left(root->right);
            if(root->left==NULL &&root->right==NULL){
                cout<<root->val<<" ";
            }
        }

}
void right(Node* root)
{
    if(root==NULL) return;
 
        if(root->right){
           
        cout<<root->val<<" ";
         right(root->right);
       
        }
       else if(root->left){
       
            cout<<root->val<<" ";
             right(root->left);
            
        }
         else
        {
            if(root->left==NULL &&root->right==NULL){
                cout<<root->val<<" ";
            }
             left(root->left);
            left(root->right);
        }


}
int main()
{
Node* root= binary_input();

left(root->left);
cout<<root->val<<" ";
right(root->right);
  return 0;
}