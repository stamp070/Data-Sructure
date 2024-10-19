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
class avl
{
public:
    node *root;
    avl(int data)
    {
        root = new node(data);
    }
    int height(node *root)
    {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    node *rotateright(node *y)
    {
        node *x = y->left;
        node *t2 = x->right;
        x->right = y;
        y->left = t2;

        x->height = height(x);
        y->height = height(y);

        return x;
    }
    node *rotateleft(node *x)
    {
        node *y = x->right;
        node *t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = height(x);
        y->height = height(y);

        return y;
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
        else
        {
            return root;
        }

        root->height = height(root);

        // case LL
        if (height(root->left) - height(root->right) > 1 && data < root->left->data)
        {
            return rotateright(root);
        }
        // case RR
        if (height(root->right) - height(root->left) > 1 && data > root->right->data)
        {
            return rotateleft(root);
        }
        // case LR
        if (height(root->left) - height(root->right) > 1 && data > root->left->data)
        {
            root->left = rotateleft(root->left);
            return rotateright(root);
        }
        // case RL
        if (height(root->right) - height(root->left) > 1 && data < root->right->data)
        {
            root->right = rotateright(root->right);
            return rotateleft(root);
        }
        return root;
    }
    node *successor(node *root)
    {
        if (root->left == NULL)
            return root;
        return successor(root->left);
    }

    node *Delete(node *root, int data)
    {
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
                node *temp = successor(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
            root->height = height(root);

            // case LL
            if (height(root->left) - height(root->right) > 1 && data < root->left->data)
            {
                return rotateright(root);
            }
            // case RR
            if (height(root->right) - height(root->left) > 1 && data > root->right->data)
            {
                return rotateleft(root);
            }
            // case LR
            if (height(root->left) - height(root->right) > 1 && data > root->left->data)
            {
                root->left = rotateleft(root->left);
                return rotateright(root);
            }
            // case RL
            if (height(root->right) - height(root->left) > 1 && data < root->right->data)
            {
                root->right = rotateright(root->right);
                return rotateleft(root);
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
    avl t(10);
    t.root = t.insert(t.root, 20);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 40);
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 25);

    t.preorder(t.root);
    cout << endl;
    t.root = t.Delete(t.root, 30);
    t.preorder(t.root);
}
