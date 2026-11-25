#include <iostream>
using namespace std;

template <typename T>
class set
{
    struct node
    {
        T val;
        node* left;
        node* right;
        node* parent;

        node()
        {
            left = right = parent = nullptr;
        }
    };

    node* head;

public:
    set()
    {
        head = new node;
        head->parent = head;
        head->left = head;
        head->right = head;
    }

    void insert(const T& val)
    {
        node* temp = new node;
        temp->val = val;
        temp->left = head;
        temp->right = head;

        if (head->parent == head)
        {
            head->parent = temp;
            temp->parent = head;
            head->left = temp;
            head->right = temp;
            return;
        }
        else
        {
            node* ptr;
            ptr = head->parent;

            while (ptr != head)
            {
                if (ptr->val > temp->val)
                {
                    if (ptr->left == head)
                    {
                        ptr->left = temp;
                        temp->parent = ptr;
                        break;
                    }
                    else
                    {
                        ptr = ptr->left;
                    }
                }
                else if (ptr->val < temp->val)
                {
                    if (ptr->right == head)
                    {
                        ptr->right = temp;
                        temp->parent = ptr;
                        break;
                    }
                    else
                    {
                        ptr = ptr->right;
                    }
                }
                else
                {
                    delete temp;
                    return;
                }
            }
        }

        if (temp->val < head->left->val)
        {
            head->left = temp;
        }

        if (temp->val > head->right->val)
        {
            head->right = temp;
        }
    }
};

int main()
{
    set<int> s;
    s.insert(50);
    s.insert(30);
    s.insert(70);
    s.insert(20);
    s.insert(40);
    s.insert(60);
    s.insert(80);

    return 0;
}
