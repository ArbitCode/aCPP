#include <iostream>
#include<stack>
using namespace std;
class Node
{
public:
    int m_data;
    Node *left;
    Node *right;
    Node(int data) : m_data{data}, left(nullptr), right(nullptr) {}
};

// preporder -> root, left, right
vector<int> TreeTraversalPre(Node *root)
{
    vector<int> order;
    if (root == nullptr)
        return order;
    Node *current = root;
    stack<Node *> stackTree;
    stackTree.push(current);
    while (stackTree.empty() == false)
    {
        Node *top = stackTree.top();
        stackTree.pop();
        order.push_back(top->m_data);
        if (top->right)
            stackTree.push(top->right);
        if (top->left)
            stackTree.push(top->left);
    }
    return order;
}

// Inporder -> left, root, right // first go to left most, then root then right repeat again
vector<int> TreeTraversalIn(Node *root)
{
    vector<int> order;
    if (root == nullptr)
        return order;
    Node *current = root;
    stack<Node *> stackTree;
    while (true)
    {
        if (current)
        {
            stackTree.push(current);
            current = current->left;
        }
        else
        {
            if (stackTree.empty())
                break;
            current = stackTree.top();
            order.push_back(current->m_data);
            stackTree.pop();
            current = current->right;
        }
    }
    return order;
}

// postorder -> left, right, root using two stack
vector<int> TreeTraversalPost(Node *root)
{
    vector<int> order;
    if (root == nullptr)
        return order;
    stack<Node *> S1;
    stack<Node *> S2;
    Node *current = root;
    S1.push(current);
    while (!S1.empty())
    {
        Node *top = S1.top();
        S1.pop();
        S2.push(top);
        if (top->left)
            S1.push(top->left);
        if (top->right)
            S1.push(top->right);
    }
    while (!S2.empty())
    {
        order.push_back(S2.top()->m_data);
        S2.pop();
    }
    return order;
}

// without stack
vector<int> morrisTraversalIn(Node *root)
{
    vector<int> order;
    if (root == nullptr)
        return order;
    Node *curr = root;
    Node *prev = nullptr;
    while (curr)
    {
        if (curr->left == nullptr)
        {
            order.push_back(curr->m_data);
            curr = curr->right;
        }
        else
        {
            // Find predecessor
            prev = curr->left;
            while (prev->right != nullptr && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                order.push_back(curr->m_data);
                curr = curr->right;
            }
        }
    }
    return order;
}

// without stack
vector<int> morrisTraversalPre(Node *root)
{
    vector<int> order;
    if (root == nullptr)
        return order;
    Node *curr = root;
    Node *prev = nullptr;
    while (curr)
    {
        if (curr->left == nullptr)
        {
            order.push_back(curr->m_data);
            curr = curr->right;
        }
        else
        {
            // Find predecessor
            prev = curr->left;
            while (prev->right != nullptr && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                order.push_back(curr->m_data); // only diffrence
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return order;
}
// TODO Morriss Post

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    vector<int> order = TreeTraversalPre(root);
    order = TreeTraversalIn(root);
    order = TreeTraversalPost(root);
    order = morrisTraversalIn(root);
    order = morrisTraversalPre(root);
    for (const auto &it : order)
        cout << it << " ";
}
