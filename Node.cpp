#include "Node.h"

Node::Node(string _name, float _amount){
    //cout<<"0"<<endl;
    this->name = _name;
    this->amount = _amount;
    this->next = NULL;
}

Node::Node(const Node& node){
    cout<<"1"<<endl;
    this->name = node.name;
    this->amount = node.amount;
    if(node.next) {
        this->next = new Node(*(node.next));
    }
}

Node& Node::operator=(const Node& node){
    cout<<"2"<<endl;
    this->name = node.name;
    this->amount = node.amount;
    if(node.next) {
        delete this->next;
        this->next = new Node(*(node.next));
    }
    return *this;
}

Node::Node(Node&& node){
    cout<<"3"<<endl;
    this->name = move(node.name);
    this->amount = move(node.amount);
    this->next = move(node.next);

    node.name = "";
    node.amount = 0;
    node.next = NULL;

}



Node& Node::operator=(Node&& node){
    cout<<"4"<<endl;
    this->name = move(node.name);
    this->amount = move(node.amount);
    delete this->next;
    this->next = move(node.next);

    node.name = "";
    node.amount = 0;
    node.next = NULL;
    return *this;
}
Node::~Node(){
    if (next) {
        delete next;
    }
}