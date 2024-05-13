#ifndef DOUBLE
#define DOUBLE

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *prx;
    Node *prev;
};

Node* createNode(int num){
    Node *q = new Node;
    q->value = num;
    q->prx = NULL;
    q->prev = NULL;
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
        (*p)->prev = aux;
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
        aux2->prev = aux;
    }
}

void deleteElement(Node **p, int num){
    Node *aux = *p;
    if((*p)->value == num){
        *p = (*p)->prx;
        (*p)->prev = NULL;
        aux->prx = NULL;
        delete(aux);
    }
    else{
        while(aux != NULL){
            if(aux->prx->value == num){
                Node *aux2 = aux->prx, *aux3;
                aux->prx = aux2->prx;
                aux3 = aux->prx; 
                aux2->prx = NULL;
                aux2->prev = NULL;
                aux3->prev = aux;
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
        cout << aux->value << " ";
        aux = aux->prx;
    }
}

#endif