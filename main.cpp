/* 
 * File:   main.cpp
 * Author: Steve Vezeau
 *
 * Created on October 19, 2015, 11:19 PM
 */

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;


// Single Linked List data structure

typedef struct node {
        char data;
        node *next;
};

typedef struct stackElement {
    node element;
    stackElement *next;
    
};



class SLL {
public:
    
    node *head = NULL;


void printSLL() {
        node *temp1 = head;
        cout << "Current List\n";
        while (temp1 != NULL) {
                cout << temp1->data << "\n";
                temp1 = temp1->next;
        }
}

void printSLL(node *n) {
        node *temp1 = n;
        cout << "Current List\n";
        while (temp1 != NULL) {
                cout << temp1->data << "\n";
                temp1 = temp1->next;
        }
}

// Using the diagrams on http://www.codeproject.com/Articles/24684/How-to-create-Linked-list-using-C-C

void insertFront(char info) {

        node *temp;
        // Had to steal to get rid of segmentation fault
        temp = (node*)malloc(sizeof(node));
        temp->data = info;
        temp->next = head;
        head = temp;

        printSLL();

}

void insertBack(char info) {

        node *temp1;
        // Had to steal to get rid of segmentation fault
        temp1= (node*)malloc(sizeof(node));
        temp1 = head;
        // Go to the last node
        while(temp1->next!=NULL)
        temp1 = temp1->next;

        node *temp;
        temp = (node*)malloc(sizeof(node));
        temp->data = info;
        temp->next = NULL;
        // Set the previously NULL next to point to the new last node
        temp1->next = temp;

        printSLL(head);

}

int size() {
        node *temp = head;
        int size = 0;
        while (temp != NULL) {
                size++;
                temp = temp-> next;
        }
        return size;
}
};

class Stack {
private:
    stackElement *top = NULL;
    
public:
    void printStack(stackElement *se) {
        stackElement *temp1 = se;
        cout << "Current Stack\n";
        while (temp1 != NULL) {
                cout << temp1->element.data << "\n";
                temp1 = temp1->next;
        }
    }
    
//    node top() {
//        return top;
//    }
    
    void push(node nnode) {
        
        // Create temp object and allocate memory
        stackElement *temp;
        temp = (stackElement*)malloc(sizeof(stackElement));
        
        temp->element = nnode;
        temp->next = top;
        top = temp;
        
        printStack(top);
    }
    
    void pop() {
        
    }
    
    void full() {
        
    }
    
    bool empty() {
        if (top == NULL) {
            return true;
        }
        return false;
    }

};

int main() {
        SLL sll;
        sll.insertFront('3');
        sll.insertFront('4');
        sll.insertFront('7');
        sll.insertBack('r');
        sll.insertFront('k');
        cout << "list size: " << sll.size() << "\n";
        
        Stack stack;
        stack.push(*sll.head);
        cout << "stack emptiness: " << stack.empty() << "\n";
        return 1;
}


