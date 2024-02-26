#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Node
{
    public:
    int val;
    Node *left;
    Node *right;
    Node(){};
    Node(int data) : val{data}, left{nullptr}, right{nullptr} {}
};

class TreeNode : public Node{
    Node *root;
    Node* insertNodeHelper(Node *root, int val)
    {
        if(root == nullptr)
        {
            return new Node(val);
        } 
        if(root->left == nullptr) 
        {
            root->left = insertNodeHelper(root->left, val);
        }

        else
        {
            root->right = insertNodeHelper(root->right, val);
        }

        return root;
    }
    public:
    TreeNode(): root{nullptr}{}
    void insertNode(int val)
    {
        root = insertNodeHelper(root, val);
    }
    vector<int> preorderItr()
    {
        stack<Node* > st;
        vector<int> order;
        st.push(root);
        while(!st.empty())
        {
            Node * top = st.top();
            st.pop();
            order.push_back(top->val);
            if(top->right != nullptr) st.push(top->right);
            if(top->left  != nullptr) st.push(top->left);
        } 
        return order;
    }
    vector<int> inorderItr(){
        stack<Node* > st;
        vector<int> order;
        Node *current = root;
        while(current != nullptr || st.empty() == false)
        {
            while(current){
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            order.push_back(current->val);
            current = current -> right;
        }
        return order;

    }

    vector<int> postorderItr()
    {
        stack<Node* > st1;
        stack<Node* > st2;
        vector<int> order;
        st1.push(root);
        while(!st1.empty())
        {
            Node *top = st1.top();
            st1.pop();
            st2.push(top);
            if(top->left) st1.push(top->left);
            if(top->right) st1.push(top->right);
        }
        while(!st2.empty())
        {
            order.push_back(st2.top()->val);
            st2.pop();
        } 
        return order;

    }

    vector<int> levelOrder(){
        queue<Node* > queue;
        vector<int> order;
        queue.push(root);
        while(!queue.empty()){
            Node *front = queue.front();
            order.push_back(front->val);
            queue.pop();
            if(front->left) queue.push(front->left);
            if(front->right) queue.push(front->right);
        }
        return order;
    }

    vector<int> getPreorder(vector<int> &postorder, vector<int> &inorder)
    {
        vector<int> order;
        
    }
    vector<int> getPostOrder(vector<int> &preporder, vector<int> &inorder);

    
};

int main(){
    TreeNode tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    vector<int> preorder = tree.preorderItr();;
    vector<int> postorder = tree.postorderItr();
    vector<int> inorder = tree.inorderItr();
    vector<int> levelorder = tree.levelOrder();

    cout << "preorder: ";
    for(auto &it : preorder) cout << it << " ";
    cout << "\npostorder: ";
    for(auto &it : postorder) cout << it << " ";
    cout << "\ninorder: ";
    for(auto &it : inorder) cout << it << " ";
    cout << "\nlevelorder: ";
    for(auto &it : levelorder) cout << it << " ";

    vector<int>findPreoeder = getPreorder(postorder, inorder);
    cout << "\nnew preorder: ";
    for(auto &it : findPreoeder) cout << it << " ";
    vector<int>findPostoeder = getPostorder(preorder, inorder);
    cout << "\n\n new postorder: ";
    for(auto &it : findPostoeder) cout << it << " ";

}