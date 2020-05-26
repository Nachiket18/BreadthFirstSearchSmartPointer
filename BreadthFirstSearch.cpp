#include <iostream>

#include <memory>

#include <queue>

using std::unique_ptr;
using std::queue;
using std::cout;
// T is MoveConstructible.
template < typename T >
  class TreeNode {
    struct Node;
    typedef std::unique_ptr < Node > spTreeNode;
    /*  Used to specify the structure of the node of the tree */
    struct Node {
      T value;
      spTreeNode left, right;
      Node(const T & value): value(value) {}
    };
    spTreeNode root;
    void print(const spTreeNode & ) const;
    void BreadFirstSearch(const spTreeNode & node) const;

    public:
      TreeNode();
    void insert(const T & node);
    void print() const;
    void BreadFirstSearch() const;

  };
template < class T >
  TreeNode < T > ::TreeNode(): root(nullptr) {};

template < class T >
  void::TreeNode < T > ::insert(const T & value) {
    spTreeNode node(new Node(value));

    if (root == nullptr) {
      root = std::move(node);
    } else {
      Node * temp = root.get();
      Node * prev = root.get();
      /*.The loop to find out the exact node where to insert the newly arrived node. Feature of binary search tree, where the left side node has lesser value than root while right side node has higher*/
      while (temp != nullptr) {
        prev = temp;
        if (temp - > value < value) {
          temp = temp - > right.get();
        } else
          temp = temp - > left.get();
      }
      if (prev - > value < value)
        prev - > right = std::move(node);
      else
        prev - > left = std::move(node);
    }
  }

template < class T >
  void TreeNode < T > ::print() const {
    print(root);
  }

template < class T >
  void TreeNode < T > ::print(const spTreeNode & node) const {

    if (node == nullptr)
      return;

    print(node - > left);
    std::cout << node - > value << std::endl;
    print(node - > right);

  }
template < class T >
  void TreeNode < T > ::BreadFirstSearch() const {
    BreadFirstSearch(root);
  }
/*BreadthFirstSearch code based on queue*/
template < class T >
  void TreeNode < T > ::BreadFirstSearch(const unique_ptr < Node > & node) const {
    queue <
      const unique_ptr < Node > * > q;
    q.push( & node);
    while (q.empty() == false) {
      auto p = q.front();
      cout << " " << ( * p) - > value;
      q.pop();
      if (( * p) - > left != nullptr) {
        q.push( & ( * p) - > left);
      }
      if (( * p) - > right != nullptr) {
        q.push( & ( * p) - > right);
      }
    }

  }


int main() {
  TreeNode < int > tree;
  tree.insert(12);
  tree.insert(5);
  tree.insert(10);
  tree.print();
  tree.BreadFirstSearch();
  return 0;
}
