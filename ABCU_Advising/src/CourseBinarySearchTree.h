#ifndef COURSEBINARYSEARCHTREE_H
#define COURSEBINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
namespace std
{   

   

    class CourseBinarySearchTree
    {
        public:

            // struct representing the Node of the tree struct Node
            struct Node
            {
                Node* left;
                Node* right;
                Course course;

                //default constructor
                Node() 
                {
                    left = nullptr;
                    right = nullptr;
                }

                // Initialized with a course
                Node(Course course) :
                    Node () 
                {
                    this->course = course;
                }
            };


            CourseBinarySearchTree();
            virtual ~CourseBinarySearchTree();
            void InOrder();
            void Insert(Course);
            void Remove(string courseNumber);
            Course Search(string courseNumber);
        private:
            Node* root;

            void deleteTree(Node* node);
            void inOrder(Node* node);
            Node* removeNode(Node* node, string courseNumber);
            void addNode(Node* node, Course course);
            Node* findMinNode(Node* node);
    };
}
#endif /*! COURSEBINARYSEARCHTREE_H */
