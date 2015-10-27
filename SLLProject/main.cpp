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

    if (head != NULL) {
        node *temp1;
        // Had to steal to get rid of segmentation fault
        temp1= (node*)malloc(sizeof(node));
        temp1 = head;
        // Go to the last node
        while(temp1->next!=NULL) {
            temp1 = temp1->next;
        }
        node *temp;
        temp = (node*)malloc(sizeof(node));
        temp->data = info;
        temp->next = NULL;
        // Set the previously NULL next to point to the new last node
//        if (head->next != NULL)
            temp1->next = temp;
//        else
//            head->next = temp; // If there were no elements

        printSLL();
    }
    else
        insertFront(info);

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
    
public:
    
    int calcRaiser(int digits) {
        int raiser = 1;
        for (int i = 0; i < digits - 1; i++) {
            raiser *= 10;
        }
        return raiser;
    }
    
    int listToInt(SLL sll) {
        int temp0i = 0;
        node *temp0 = sll.head;
        int temp0Raiser = calcRaiser(sll.size());
        // Go through each node of each list
        while (temp0->next != NULL) {
            char c = temp0->data;
            // Convert the char to an int and raise it into the proper digit
            temp0i += (c - '0') * temp0Raiser;
            temp0Raiser /= 10;
            // Go to the next node
            temp0 = temp0->next;
        }
        // Add the last digit
        temp0i += temp0->data - '0';
        return temp0i;
    }
    
    SLL intToList(int i) {
        SLL list;
        
        for (int j = 1; j < i ; j *= 10) {
            list.insertFront((char)(i / j % 10) + '0');
        }
        
        return list;
        
    }
    
    SLL add(SLL sll0, SLL sll1) {
        SLL sum;

        int temp0i = listToInt(sll0);
        int temp1i = listToInt(sll1);
        
        cout << temp0i << " temp0i\n";
        cout << temp1i << " temp1i\n";
        
        int s = listToInt(sll0) + listToInt(sll1);
        sum = intToList(s);
        cout << "\n";

        
        return sum;
    }
    
    SLL multiply() {
        SLL product;
        
        return product;
    }
    
};

void testListAndStack() {
    SLL sll, sll2, sll3, sll4, sll5;
        sll.insertFront('3');
        sll.insertFront('4');
        sll.insertFront('7');
        sll.insertBack('5');
        sll.insertFront('6');
        cout << "list size: " << sll.size() << "\n";
        sll2.insertFront('2');
        sll2.insertBack('1');
        sll3.insertFront('3');
        
        sll5.insertBack('b');
        
        Stack stack;
        stack.push(sll);
        stack.push(sll2);
        stack.push(sll3);
        cout << "stack emptiness: " << stack.empty() << "\n";
        cout << "stack size: " << stack.size() << "\n";
        stack.pop();
        stack.pop();
        
        ListMath math;
        cout << "Add lists\n";
        // 67435 + 21
        sll4 = math.add(sll, sll2);
//        sll4.printSLL();

}

int main() {
        testListAndStack();
        return 1;
}
