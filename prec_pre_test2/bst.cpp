#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class tree
{
public:
    node *root;
    tree(int data)
    {
        root = new node(data);
    }

    node *insert(node *root, int data)
    {
        if (root == NULL)
            return new node(data);

        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
    node *Predecessor(node *root)
    {
        if (root->right == NULL)
            return root;
        return root->right;
    }
    node *Delete(node *root, int data)
    {
        if (root == NULL)
            return root;

        if (data < root->data)
        {
            root->left = Delete(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = Delete(root->right, data);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                node *temp = root;
                root = root->left;
                delete temp;
            }
            else if (root->right != NULL && root->left == NULL)
            {
                node *temp = root;
                root = root->right;
                delete temp;
            }
            else
            {
                node *p = Predecessor(root->left);
                root->data = p->data;
                root->left = Delete(root->left, p->data);
            }
        }
        return root;
    }

    void preorder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
};
int main()
{
    tree t(10);
    t.insert(t.root, 5);
    t.insert(t.root, 1);
    t.insert(t.root, 4);
    t.insert(t.root, 51);
    t.insert(t.root, 15);
    t.insert(t.root, 6);

    t.preorder(t.root);

    cout << endl;
    t.root = t.Delete(t.root, 5);  // Delete node with value 5
    t.root = t.Delete(t.root, 51); // Delete node with value 51

    t.preorder(t.root);
}