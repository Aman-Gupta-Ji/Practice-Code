#include<bits/stdc++.h>
#include<vector.h>
#include<iostream>
using namespace std;
struct TreeNode {
     int x, y, z;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int X, int Y) : x(X), x(Y), left(nullptr), right(nullptr) {}
     TreeNode(int X, int Y, TreeNode *left, TreeNode *right) : x(X), x(Y), left(left), right(right) {}
 };
TreeNode* build(unordered_map<int,int>& find, vector<int>& preorder, vector<int>& inorder, int *pre, int l, int r, vector<pair<int,int>>& ref) {
    if(l>r)
        return NULL;
    int el=preorder[++*pre];
    int pos=find[el];
    el--;
    TreeNode* root=new TreeNode(ref[el].first,ref[el].second);
    root->left=build(find,preorder,inorder,pre,l,pos-1,ref);
    root->right=build(find,preorder,inorder,pre,pos+1,r,ref);
    return root;
}
TreeNode* buildTree(int n, vector<int>& preorder, vector<int>& inorder, vector<pair<int,int>>& ref) {
    unordered_map<int,int> find;
    for(int i=0;i<n;i++)
        find[inorder[i]]=i;
    int pre=-1;
    return build(find,preorder,inorder,&pre,0,n-1,ref);
}

int inorder(TreeNode* root,vector<int>& result){
    if (root==null) return 0;
    int l= inorder(root->left,result);
    l=root->z=root->x-root->y+l;
    result.push_back(root->z);
    l+=inorder(root->right,result);
    return l;
}
vector<int> inorderTraversal(TreeNode* root) {
    vector <int> result;
    inorder(root,result);
    return result;
}

vector<int> newTree(int n, vector<int>& inorder, vector<int>& preorder, vector<pair<int,int>>& ref) {
    TreeNode root=buildTree(n,inorder,preorder,ref);
    return inorderTraversal(root);
}