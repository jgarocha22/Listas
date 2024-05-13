#ifndef SIMPLE
#define SIMPLE

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *prx;
};

Node* createNode(int num){
    Node *q = new Node;
    q->value = num;
    q->prx = NULL;
    return q;
} 

void addFirst(Node **p, int num){
    if(!(*p)){
        *p = createNode(num);
    }
    else{
        Node *aux;
        aux = createNode(num);
        aux->prx = *p;
        *p = aux;
    }
}

void addLast(Node **p, int num){
    if(!(*p)){
        *p = createNode(num);
    }
    else{
        Node *aux = *p, *aux2;
        while(aux->prx != NULL){
            aux = aux->prx;
        }
        aux2 = createNode(num);
        aux->prx = aux2;
    }
}

void deleteElement(Node **p, int num){
    Node *aux = *p;
    if((*p)->value == num){
        *p = (*p)->prx;
        delete(aux);
    }
    else{
        while(aux != NULL){
            if(aux->prx->value == num){
                Node *aux2 = aux->prx;
                aux->prx = aux2->prx;
                aux2->prx = NULL;
                aux = NULL;
                delete(aux2);
            }
            else
                aux = aux->prx;
        }
    }
}

void show(Node *p){
    Node *aux = p;
    cout << "\n******LISTA******\n" << endl;
    while(aux){
        if(aux->prx != NULL){
            cout << aux->value << " -> ";
        }
        else{
            cout << aux->value << " -> //" << endl;
        }
        aux = aux->prx;
    }
}

#endif