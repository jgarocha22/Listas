#include <iostream>
#include <string.h>

using namespace std;
struct Node{
    string nombre;
    Node *prx;
};

bool validate(Node *p){
    if(p)
        return false;
    return true;
}

string pop(Node **p){
    Node *aux = *p;
    *p = (*p) -> prx;
    string nom = aux->nombre;
    delete aux;
    return nom;
}

void pop2(Node **p){
    Node *aux = *p;
    *p = (*p) -> prx;
    delete aux;
}

void push(Node **p, string val){
    Node *aux = new Node;
    aux -> nombre = val;
    aux -> prx = *p;
    *p = aux;
    aux = NULL;
    delete aux;
}