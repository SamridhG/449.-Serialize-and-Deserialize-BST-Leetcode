/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
   
    TreeNode* insert(TreeNode *temp,int ans)
    {
        if(temp==NULL)
        {
            temp=new TreeNode(ans);
        }
        else if(temp->val>ans)
        {
            temp->left=insert(temp->left,ans);
        }
        else if(temp->val<ans)
        {
            temp->right=insert(temp->right,ans);
        }
          return temp;
    }
   void preorder(TreeNode *root,string &data)
    {
        if(root!=NULL)
        {
            data=data+to_string(root->val)+"%";
            preorder(root->left,data);
            preorder(root->right,data);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        preorder(root,data); 
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ans=0;
        TreeNode *rt=NULL;
        int i=0;
        while(i<data.size())
       
       {
           if(data[0]=='%')
           {
               rt=insert(rt,ans);
               ans=0;
           }
           else
           {
               ans=ans*10+(data[0]-48);
           }
            data.erase(data.begin());
       }
            return rt;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
