#include<bits/stdc++.h>

using namespace std;
struct binarynode
{
    int val;
    binarynode* left;
    binarynode* right;
};

binarynode* createnew(int data)
{
    binarynode* temp = new binarynode;
    temp->val=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int preorder(binarynode* root)
{
    if(root==NULL)
        return NULL;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);

}
void levelorder(binarynode* root)
{
    int data,length,ans=INT_MAX;
     if(root==NULL)
        {cout<<"Tree empty";return;}
     queue< pair<binarynode*,int> > q;
     q.push(make_pair(root,1));
     while(!q.empty())
     {
         binarynode* temp = q.front().first;
         length = q.front().second;
         if(temp->left!=NULL)
            q.push(make_pair(temp->left,length+1));
         if(temp->right!=NULL)
            q.push(make_pair(temp->right,length+1));
         if(temp->left==NULL && temp->right==NULL)
            {ans=min(ans,length);break;}
         q.pop();
     }
    cout<<ans<<'\n';
}

int main()
{
    binarynode* root = createnew(1);
    root->left = createnew(2);
    root->right = createnew(3);
    root->left->left = createnew(4);
    root->left->right = createnew(5);
    ///preorder(root);
    levelorder(root);



    return 0;
}
