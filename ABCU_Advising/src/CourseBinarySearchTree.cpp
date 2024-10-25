// CourseCourseBinarySearchTree.cpp

#include "CourseBinarySearchTree.h"
#include "Course.h"

using namespace std;

CourseBinarySearchTree::CourseBinarySearchTree()
{
    root = nullptr;
}
/**
 * Destructor
 */
CourseBinarySearchTree::~CourseBinarySearchTree() {
    // recurse from root deleting every node
    deleteTree(root); // calls the helper method to delete all nodes
    
}
/**
 * Helper method for deleting the nodes in the Binary Tree
 */
void CourseBinarySearchTree::deleteTree(Node* node) {
    // if the node is null we return this serves as the base case
    if (node == nullptr) {
        return;
    }

    // now we recursively call the left and right nodes
    deleteTree(node->left);
    deleteTree(node->right);

    // since we have explored the node's children
    delete node;
}

/**
 * Adds nodes to the tree
 */
void CourseBinarySearchTree::addNode(Node* node, Course course)
{
    // if node is larger then add to left
    if(node->course.courseNumber >= course.courseNumber)
    {
        // if no left node
        if (node->left == nullptr)
        {
            //this node becomes the left
            Node* leftNode = new Node(course);
            node->left = leftNode;
        }
        //else recuse left
        else
        {
            addNode(node->left, course);
        }
    }
    else 
    {
        // If no right node
        if (node->right == nullptr)
        {
            // this node becomes right
            Node* rightNode = new Node(course);
            node->right = rightNode;
        }
        else
        {
            // recurse down thr right
            addNode(node->right, course);
        }
    }
}

/**
 * Traverses the nodes in order
 */
void CourseBinarySearchTree::inOrder(Node* node) 
{
    if (node == nullptr)
    {
        return;
    }
    inOrder(node->left);
    node->course.PrintCourse();
    inOrder(node->right);
}

CourseBinarySearchTree::Node* CourseBinarySearchTree::findMinNode(Node* node)
{
    Node* currentNode = node;

    while (currentNode != nullptr && currentNode->left != nullptr) 
    {
        currentNode = currentNode->left;
    }
    return currentNode;
}

/** 
 * Removes a Node or Course from the tree
 */
CourseBinarySearchTree::Node* CourseBinarySearchTree::removeNode(Node* node, string courseNumber) 
{
    // if node = nullptr return node
    if (node == nullptr){
        return node;
    }
    // Determines if we should traverse down the left subtree
    else if (courseNumber < node->course.courseNumber) {
        node->left = removeNode(node->left, courseNumber);
    }
    // Determines if we should traverse down the left subtree
    else if (courseNumber > node->course.courseNumber) {
        node->right = removeNode(node->right, courseNumber);
    }
    // Otherwise we have found the node to be removed
    else {
        // first case Node with no child
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        // if node only has a right child
        else if (node->left == nullptr) {
            Node* tempNode  = node;
            node = node->right;
            delete tempNode;
        }
        // if node only has left child
        else if (node->right == nullptr) {
            Node* tempNode = node;
            node = node->left;
            delete tempNode;
        }
        // A node with two children
        else {
            // Finds the in order successor in the smallest subtree
            Node* tempNode = findMinNode(node->right);

            // copies the successor's data into this node
            node->course = tempNode->course;

            // removes the redundant successor
            node->right = removeNode(node->right, tempNode->course.courseNumber);
        }
    }
    return node;
}

/**
 * Traverse the tree in order
 */
void CourseBinarySearchTree::InOrder() {
    // call inOrder fuction and pass root 
    inOrder(root);
}

/**
 * Insert a course
 */
void CourseBinarySearchTree::Insert(Course course) {
    // if root equarl to null ptr
    if (root == nullptr){
      // root is equal to new node course
      root = new Node(course);
    }
    else {
      // add Node root and course
      addNode(root, course);
    }
}
/**
 * Remove a course
 */
void CourseBinarySearchTree::Remove(string courseNumber)
{
    // calls the private removeNode
    removeNode(root, courseNumber);
}

/**
 * Search for a bid
 */
Course CourseBinarySearchTree::Search(string courseNumber)
{
        // set current node equal to root
    Node* currentNode = root;


    // keep looping downwards until bottom reached or matching bidId found
    while(currentNode != nullptr) {
        // if match found, return current bid
        if(currentNode->course.courseNumber == courseNumber){
            return currentNode->course;
        }

        // if bid is smaller than current node then traverse left
        if(courseNumber < currentNode->course.courseNumber) {
            currentNode = currentNode->left;
        }
        // else larger so traverse right
        else{
            currentNode = currentNode->right;
        }

    }
    Course course;
    return course;
}
