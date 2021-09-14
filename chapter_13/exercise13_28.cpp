//
// Created by 柴长林 on 2021/9/14.
//
#include <string>
class TreeNode {
 public:
  TreeNode()
      : value(std::string()),
        count(new int(1)),
        left(nullptr),
        right(nullptr) {}
  TreeNode(const TreeNode &orig)
      : value(orig.value),
        count(orig.count),
        left(orig.left),
        right(orig.right) {
    ++*count;
  }
  TreeNode &operator=(const TreeNode &rhs);
  ~TreeNode();

 private:
  std::string value;
  int *count;
  TreeNode *left;
  TreeNode *right;
};

TreeNode &TreeNode::operator=(const TreeNode &rhs) {
  ++*rhs.count;
  if (--*count == 0) {
    delete count;
    delete left;
    delete right;
  }
  value = rhs.value;
  count = rhs.count;
  left = rhs.left;
  right = rhs.right;
  return *this;
}

TreeNode::~TreeNode() {
  if (--*count == 0) {
    delete count;
    delete left;
    delete right;
  }
}

class BinStrTree {
 public:
  BinStrTree() : root(new TreeNode()){};
  BinStrTree(const BinStrTree &orig) : root(new TreeNode(*orig.root)) {}
  BinStrTree &operator=(const BinStrTree &rhs);
  ~BinStrTree() { delete root; }

 private:
  TreeNode *root;
};

BinStrTree &BinStrTree::operator=(const BinStrTree &rhs) {
  auto temp = new TreeNode(*rhs.root);
  delete root;
  root = temp;
  return *this;
}