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


 void LeafSum(Node* root,int &sum){
        if(!root) return;
        
            if(!(root->left==NULL && root->right ==NULL)){
                sum+=root->val;
            
        }
          
        
        LeafSum(root->left, sum);
        LeafSum(root->right, sum);
    }
    int sum_without_leaf(Node* root){
 int sum=0;
 LeafSum(root,sum);
return sum;
}
int main()
{
    Node* root= binary_input();
    
    sum_without_leaf(root);
    cout<<sum_without_leaf(root);

  return 0;
}