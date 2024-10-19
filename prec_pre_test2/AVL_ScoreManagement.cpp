#include <iostream>
#include <algorithm>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVL
{
public:
    node *root = NULL;
    void addScore(int data)
    {
        root = insert(root, data);
    }
    void removeScore(int data)
    {
        root = Delete(root, data);
    }
    void displayScore()
    {
        preorder(root);
    }
    int height(node *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    node *rightrotate(node *y)
    {
        node *x = y->left;
        node *t2 = x->right;
        x->right = y;
        y->left = t2;

        y->height = height(y);
        x->height = height(x);
        return x;
    }
    node *leftrotate(node *x)
    {
        node *y = x->right;
        node *t2 = y->left;
        y->left = x;
        x->right = t2;

        y->height = height(y);
        x->height = height(x);
        return y;
    }
    node *insert(node *root, int data)
    {
        if (root == NULL)
        {
            return root = new node(data);
        }
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        else
        {
            return root;
        }

        root->height = height(root);
        int balance = height(root->left) - height(root->right);

        // case LL
        if (balance > 1 && data < root->left->data)
        {
            root = rightrotate(root);
        }
        // case RR
        if (balance < -1 && data > root->right->data)
        {
            root = leftrotate(root);
        }
        // case LR
        if (balance > 1 && data > root->left->data)
        {
            root->left = leftrotate(root->left);
            root = rightrotate(root);
        }
        // case RL
        if (balance < -1 && data < root->right->data)
        {
            root->right = rightrotate(root->right);
            root = leftrotate(root);
        }
        return root;
    }
    node *rightmin(node *root)
    {
        if (root->left == NULL)
            return root;
        return rightmin(root->left);
    }
    node *Delete(node *root, int data)
    {
        if (root == NULL)
        {
            return root;
        }
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
                node *temp = rightmin(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        if (root == NULL)
            return root;

        root->height = height(root);
        int balance = height(root->left) - height(root->right);

        // case LL
        if (balance > 1 && data < root->left->data)
        {
            root = rightrotate(root);
        }
        // case RR
        if (balance < -1 && data > root->right->data)
        {
            root = leftrotate(root);
        }
        // case LR
        if (balance > 1 && data > root->left->data)
        {
            root->left = leftrotate(root->left);
            root = rightrotate(root);
        }
        // case RL
        if (balance < -1 && data < root->right->data)
        {
            root->right = rightrotate(root->right);
            root = leftrotate(root);
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
    AVL tree;

    tree.addScore(85);
    tree.addScore(90);
    tree.addScore(78);

    tree.removeScore(85);

    tree.displayScore();
}
