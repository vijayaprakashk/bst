#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* getNewNode (int data) {
    Node *newNode = new Node;
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

bool Insert(Node** root, int data) {
    Node *cur_node = *root;
    Node *parent;
    if (*root == NULL) {
        Node *tmp = getNewNode (data);
        if (tmp != NULL) {
            *root = tmp; 
            return true;
        }
        else {
            cout << "Memory Allocation Error" << endl;
            return false;
        }
    }

    while (cur_node != NULL) {
        if (data <= cur_node->data) {
	    parent = cur_node;
            cur_node = cur_node->left;
        } else {
	    parent = cur_node;
            cur_node = cur_node->right;
        }
    }

    Node *tmp = getNewNode (data);
    if (tmp != NULL) {
	    if (data <= parent->data) {
            parent->left = tmp;
	    } else {
            parent->right = tmp;
        }
        return true;
    }
    else {
        cout << "Memory Allocation Error" << endl;
        return false;
    }
}

void levelOrderTraversal (Node **root) {
    std::queue<Node*> traversalQ;

    if (*root != NULL) {
        traversalQ.push(*root);
    } else {
        cout << "Empty Tree" << endl;
    }

    while (!traversalQ.empty()) {
        Node* cur_node = traversalQ.front();
        if (cur_node != NULL) {
            cout << cur_node->data << " ";
            if (cur_node->left != NULL) {
                traversalQ.push(cur_node->left);
            }
            if (cur_node->right != NULL) {
                traversalQ.push(cur_node->right);
            }
            traversalQ.pop();
        }
    }
}

int main () {
    int arr[] = {10, 20, 8, 5, 23, 15, 18, 40};
    Node* root = NULL;
    levelOrderTraversal(&root);
    for (int x : arr) {
        if (!Insert(&root, x))
        {
            cout << "Insert Failure, data = " << x << endl;
            break;
        }
        levelOrderTraversal(&root);
        cout << endl;
    }
}
