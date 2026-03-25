#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void verticalOrder(Node* root) {
    if (root == NULL) return;

    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* node = p.first;
        int hd = p.second;

        mp[hd].push_back(node->data);

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto x : mp) {
        for (int val : x.second)
            cout << val << " ";
        cout << endl;
    }
}
