#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root == NULL){
    return;
  }
  traverseInOrder(root->left);
  cout<<root->key<<" ";
  traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if(node == NULL){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }
  if(node->key < key){
    node->right = insertNode(node->right, key);
  }
  else if(node->key>key){
    node->left = insertNode(node->left , key);

  }
  
  return node;


}

struct node* minValue(struct node* node){
  struct node* current = node;
  while( current && current->left != NULL){
    current = current->left;
  }
  return current;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if(root == NULL){
    return root;
  }
  if(key < root->key){
    root->left = deleteNode(root->left, key);
  }
  else if(key > root->key){
    root->right = deleteNode(root->right, key);
  }
  else{
      if(root->left ==NULL && root->right == NULL){
          return NULL;
      }
      else if(root->left == NULL){
        root = root->right;
        return root;
      }
      else if(root->right == NULL){
        root = root->left;
        return root;
      }
      else{
      struct node* newNode = minValue(root->right);
      root->key = newNode->key;
      root->right = deleteNode(root->right, newNode->key);
      }
  }
  return root;
}




// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}