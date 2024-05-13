#include <iostream>

struct Node{
    int value;
    Node *prx;
};

bool validate(Node *p){
    if(p)
        return false;
    return true;
}

int pop(Node **p){
    Node *aux = *p;
    *p = (*p) -> prx;
    int val = aux->value;
    delete aux;
    return val;
}

void push(Node **p, int val){
    Node *aux = new Node;
    aux -> value = val;
    aux -> prx = *p;
    *p = aux;
    aux = NULL;
    delete aux;
}