#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MAX 100

struct stack {
    int arr[MAX];
    int top = -1;

    bool is_fill() {
        return top == MAX - 1;
    }

    void push(int val) {
        if (!is_fill()) {
            arr[++top] = val;
        } else {
            cout << "Stack overflow\n";
        }
    }

    void insert(int val) {
        push(val);
    }

    bool is_empty() {
        return top == -1;
    }
    void pop() {
    	if (is_empty()) {
    		cout << "Stack is empty\n";
		}
		else {
			top--;
		}
	}
    void peek(){
    	if (is_empty()) {
    		cout << "stack is empty\n";
		}
		else {
			cout << "peek element is : ";
			cout << arr[top] <<"\n";
		} 
	}
    void display() {
        if (is_empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements:\n";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

#endif
