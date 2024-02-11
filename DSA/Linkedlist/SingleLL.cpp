#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
Node *arr2LL(const vector<int> &vec)
{
    if (vec.size() == 0)
        return nullptr;
    Node *head = new Node(vec[0]);
    Node *mover = head;
    for (int i = 1; i < vec.size(); i++)
    {
        Node *temp = new Node(vec[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthLL(Node *head)
{
    int size = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
bool checkIfPresent(Node *head, int val)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}
Node *insertLast(Node *head, int val)
{
    Node *temp = new Node(val);
    if (head == nullptr)
        return temp;
    Node *mover = head;
    while (mover->next != nullptr)
    {
        mover = mover->next;
    }
    mover->next = temp;
    return head;
}

Node *insertK(Node *head, int val, int k)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            Node *node1 = new Node(val);
            node1->next = head;
            head = node1;
            return head;
        }
        else
        {
            return head;
        }
    }
    if (k == 1)
    {
        Node *node1 = new Node(val);
        node1->next = head;
        head = node1;
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            Node *node1 = new Node(val);
            prev->next = node1;
            node1->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertEl(Node *head, int val, int el)
{
    if (head == nullptr)
    {
        Node *node1 = new Node(val);
        node1->next = head;
        head = node1;
        return head;
    }
    if (head->data == el)
    {
        Node *node1 = new Node(val);
        node1->next = head;
        head = node1;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data == el)
        {
            Node *node1 = new Node(val);
            prev->next = node1;
            node1->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    return head;
}

Node *deleteLast(Node *head)
{
    if (head == nullptr)
        return head;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return nullptr;
    }
    Node *tail = head;
    while (tail->next->next != nullptr)
    {
        tail = tail->next;
    }
    delete tail->next;
    tail->next = nullptr;
    return head;
}

Node *deleteK(Node *head, int k)
{
    if (head == nullptr || k == 0)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            temp = nullptr;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteEl(Node *head, int el)
{
    if (head == nullptr)
        return head;
    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            delete temp;
            temp = nullptr;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
void viewLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}
int main()
{
    vector<int> vec = {1, 2, 3, 4};
    Node *head = arr2LL(vec);
    head = insertK(head, 10, 5);
    head = insertEl(head, 10, 5);
    viewLL(head);
    head = deleteEl(head, 11);
    viewLL(head);
    cout << lengthLL(head) << endl;
    cout << boolalpha << checkIfPresent(head, 1);
    /*
    Deletion and insertion
    1. head
    4. last
    2. position kth
    3. val
    */
}
