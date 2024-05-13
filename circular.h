#ifndef Circular
#define Circular

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *prx;
};

struct Node *last;

Node* createNode(int num){
    Node *q = new Node;
    q->value = num;
    q->prx = NULL;
    return q;
} 

void addFirst(Node **p, int num){
    if(!(*p)){
        *p = createNode(num);
        (*p)->prx = *p;
        last = *p;
    }
    else{
        Node *aux;
        aux = createNode(num);
        aux->prx = *p;
        *p = aux;
        last->prx = *p;
    }
}

void addLast(Node **p, int num){
    if(!(*p)){
        *p = createNode(num);
        (*p)->prx = *p;
        last = *p;
    }
    else{
        Node *aux = *p, *aux2;
        while(aux->prx != *p){
            aux = aux->prx;
        }
        aux2 = createNode(num);
        aux->prx = aux2;
        last = aux2;
        last->prx = *p;
    }
}

void deleteElement(Node **p, int num){
    Node *aux = *p;
    int n = 0;
    if((*p)->value == num){
        *p = (*p)->prx;
        last = *p;
        aux->prx = NULL;
        delete(aux);
    }
    else{
        if(last->value == num){
            while(aux->prx != last) aux = aux->prx;
            Node *aux2 = aux->prx;
            aux->prx = aux2->prx;
            last = aux;
            aux2 = NULL;
            delete(aux2);
            
        }else{
            while(aux->prx != last || n != 1){
                if(aux->prx->value == num){
                    Node *aux2 = aux->prx;
                    aux->prx = aux2->prx;
                    aux2->prx = NULL;
                    aux = NULL;
                    n = 1;
                    delete(aux2);
                }
                else
                    aux = aux->prx;
            }
        }
    }
}

void show(Node *p){
    Node *aux = p;
    cout << "\n******LISTA******\n" << endl;
    while(aux != last){
        cout << aux->value << " ";
        aux = aux->prx;
    }
    cout << last->value << " ";
}

#endif