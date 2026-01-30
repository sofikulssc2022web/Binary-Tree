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


  void LeafNodes(Node* root,vector<int>&l){
        if(!root) return;
        
        
            
            if(!root->left && !root->right){
               l.push_back(root->val);
               return;
            }
        
         
      LeafNodes(root->right,l);
       LeafNodes(root->left,l);
        
    }
   

int main()
{
    Node* root= binary_input();
    
    vector<int>l;
    LeafNodes(root,l);
    sort(l.begin(),l.end(),greater<int>());
    for(int i=0;i<l.size();i++){
    cout<<l[i]<<" ";
    }

   

  return 0;
}