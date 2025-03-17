// https://leetcode.cn/problems/construct-quad-tree/ Construct Quad Tree
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
         Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

inline void impl(Node*& root, vector<vector<int>>& grid, int is, int ie, int js,
                 int je) {
    if (is + 1 == ie) {
        root = new Node();
        root->val = grid[is][js] == 1;
        root->isLeaf = true;
        return;
    }

    root = new Node();

    int half = (ie - is) / 2;
    impl(root->topLeft, grid, is, is + half, js, js + half);
    impl(root->topRight, grid, is, is + half, js + half, je);
    impl(root->bottomLeft, grid, is + half, ie, js, js + half);
    impl(root->bottomRight, grid, is + half, ie, js + half, je);

    bool tl = root->topLeft->val;
    bool tr = root->topRight->val;
    bool bl = root->bottomLeft->val;
    bool br = root->bottomRight->val;

    if (root->topLeft->isLeaf && root->topRight->isLeaf &&
        root->bottomLeft->isLeaf && root->bottomRight->isLeaf && tl == tr &&
        tr == bl && bl == br) {
        root->isLeaf = true;
        root->val = root->topLeft->val;
        delete root->bottomRight;
        delete root->bottomLeft;
        delete root->topLeft;
        delete root->topRight;
        root->bottomRight = nullptr;
        root->bottomLeft = nullptr;
        root->topLeft = nullptr;
        root->topRight = nullptr;
    }
}

inline Node* construct(vector<vector<int>>& grid) {
    Node* root = nullptr;
    impl(root, grid, 0, grid.size(), 0, grid.size());
    return root;
}