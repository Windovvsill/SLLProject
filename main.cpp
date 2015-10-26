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
                cout << temp1->data;
                temp1 = temp1->next;
        }
                cout << "\n";

}

void static printSLL(node *n) {
        node *temp1 = n;
        cout << "Current List\n";
        while (temp1 != NULL) {
                cout << temp1->data;
                temp1 = temp1->next;
        }
        cout << "\n";
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
    
    void push(SLL nnode) {
        
        // Create temp object and allocate memory
        stackElement *temp;
        temp = (stackElement*)malloc(sizeof(stackElement));
        
        // Set the stackElement object's data
        temp->element = *nnode.head;
        // Set the stackElement's pointer
        temp->next = top;
        top = temp;
        
        printStack(top);
    }
    
    stackElement pop() {
        stackElement *temp1;
        if (this->empty()) {
            temp1 = NULL;
        }
        else {
            temp1 = top;
            // Grab the second element
            stackElement *temp2 = top->next;
            top = temp2;
        }
        printStack(top);
        return *temp1;
    }
    
    
    bool full() {
        // What's full for?
        return this->size() > 99;
    }
    
    int size() {
        stackElement *temp = top;
        int size = 0;
        while (temp != NULL) {
                size++;
                temp = temp-> next;
        }
        return size;
    }
    
    bool empty() {
        if (top == NULL) {
            return true;
        }
        return false;
    }

};

class ListMath {
    SLL sll0, sll1;
    
    SLL add() {
        SLL sum;
        
        node *temp0 = sll0.head;
        node *temp1 = sll1.head;
        // Grab the last node of each list
        while (temp0 != NULL) {
                cout << temp0->data;
                temp0 = temp0->next;
        }
        while (temp1 != NULL) {
                cout << temp1->data;
                temp1 = temp1->next;
        }
        sum.insertBack(char((int)temp0 + (int)temp1))
        
        return sum;
    }
    
    SLL multiply() {
        SLL product;
        
        return product;
    }
};

void testListAndStack() {
    SLL sll, sll2, sll3;
        sll.insertFront('3');
        sll.insertFront('4');
        sll.insertFront('7');
        sll.insertBack('r');
        sll.insertFront('k');
        cout << "list size: " << sll.size() << "\n";
        sll2.insertFront('2');
        sll3.insertFront('3');
        
        Stack stack;
        stack.push(sll);
        stack.push(sll2);
        stack.push(sll3);
        cout << "stack emptiness: " << stack.empty() << "\n";
        cout << "stack size: " << stack.size() << "\n";
        stack.pop();
        stack.pop();
        stack.pop();
}

int main() {
        testListAndStack();
        return 1;
}


