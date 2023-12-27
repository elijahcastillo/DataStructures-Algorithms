#pragma once



//       Rules
//---------------------
// - Every node is red or black
// - Root is always black
// - New insertions are always red (initially)
// - Every path from root -> left has the same number of black nodes
// - No path can have 2 consecutive Red Nodes (but can have 2 black)
// - Null nodes are black
//
//
//     ReBalance
//---------------------
// - Black Aunt: Rotate
//         Black
//         /  \
//       Red  Red
//
//
// - Red  Aunt: Color Flip
//           Red
//          /  \
//      Black Black


template <typename T>
class RBTree {


  enum NodeColor {
    RED,
    BLACK,
  };
  
  struct Node {
    T value;
    Node* left;
    Node* right;
    Node* parent;
    NodeColor color;

    Node(T value): value(value), left(nullptr), right(nullptr), parent(nullptr), color(RED) {};
  };

  Node* root;

  RBTree(){
    root = nullptr;
  }


  Node* createNode(T data){
    return new Node(data);
  }

  void flipColor(Node* node){
    node->color = node->color == RED ? BLACK : RED;
  }

  void changeColor(Node* node, NodeColor color){
    node->color = color;
  }

  void rightRotate(Node*& A){
  //      A
  //     / \
  //    B   E 
  //   / \
  //  C  D 
  //
  //  -> (Right rotate on A)
  //    
  //     B 
  //    / \
  //   C  A
  //     / \
  //    D  E 
  //

    Node* parent = A->parent;
    Node* B = A->left;

    //Update A's children
    A->left = B->right;

    
    if (B->right != nullptr) {
      B->right->parent = A; //Update D's parent
    }

    //Update B 
    B->parent = parent;
    if(parent == nullptr) //A was root now B is
    {
      root = B;
    }

    //Update parent pointers
    if(parent->right == A){
      parent->right = B;
    } else {
      parent->left = B;
    }



    //Update B's children
    B->right = A;
    A->parent = B;

  }


  void leftRotate(Node*& A){

  //
  //     A 
  //    / \
  //   E  B 
  //     / \
  //    C  D 
  //
  //  -> (left rotate on B) (Opposite of right rotate)
  // 
  //      B 
  //     / \
  //    A   D 
  //   / \
  //  E  C 
  //
  //
    Node* parent = A->parent;
    Node* B = A->right;

    //Update parent
    if(parent->right == A){
      parent->right = B;
    } else {
      parent->left = B;
    }

    //Update A's children
    A->right = B->left;

    //Update B's children
    B->left = A;

  }

  void fixTreeProperties(Node*& node){

  /* Upward Propagation: After an insertion, the changes made to restore the tree's properties might cause further violations up the tree. The loop allows these to be corrected as we move upwards, starting from the newly inserted node. */
  /* Termination Conditions: The loop terminates when either the node becomes the root (thus no further violation can propagate upwards) or when the parent of the current node is black (as no red-red parent-child relationship exists anymore). */
    while (node != root && node->parent->color == RED){
     Node* parent = node->parent;
     Node* grandparent = parent->parent;

    //Next step is to find uncle of node

     if(parent == grandparent->left){
      Node* uncle = grandparent->right;


      // Case 1: Uncle is red (Color Flip)
      // Example: Parent and Uncle are red, flip colors to maintain properties, like no two red nodes in order

      //    G(B)                 G(R) <- Continue fixing from here
      //   /   \    Flip        /   \
      //  P(R) U(R)  ---->    P(B) U(B)
      // /                    /
      // N(R)                N(R)
      if(uncle != nullptr && uncle->color == RED){
          parent->color = BLACK;
          uncle->color = BLACK;
          grandparent->color = RED;
          node = grandparent; // Move up the tree for further checks
      }
     }

    }
  }

  void insert(T value){
    if(root == nullptr){
      root = createNode(value);
      changeColor(root, BLACK); //Hold rules that root is black
      return;
    }

    insertHelper(root, nullptr, value);
  }

  void insertHelper(Node*& node, Node*& parent, T value){
    if(node == nullptr){
      //Insert Node
      Node* newNode = createNode(value);
      node = newNode;
      node->parent = parent;

      //Make sure RB rules hold 
      fixTreeProperties();
      

      return;
    }


    //Recursivly search for valid node placement
    if(value <  node->value){
      insertHelper(node->left, value, node);
    }

    if(value > node->value){
      insertHelper(node->right, value, node);
    }

  }


};
