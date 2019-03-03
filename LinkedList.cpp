#include "LinkedList.h"

LinkedList::LinkedList() {
    this->length=0;
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& list){

    this->length = list.length;
    this->head = list.head;
    this->tail = list.tail;

}
LinkedList& LinkedList::operator=(const LinkedList &list) {
    this->length = list.length;
    this->head = list.head;
    this->tail = list.tail;
    return *this;
}

LinkedList::LinkedList(LinkedList &&list) {

    this->length = move(list.length);
    this->head = move(list.head);
    this->tail = move(list.tail);

    list.length = 0;
    this->head = nullptr;
    this->tail = nullptr;

}
LinkedList& LinkedList::operator=(LinkedList &&list) {

    this->length = move(list.length);
    this->head = move(list.head);
    this->tail = move(list.tail);
    list.length = 0;
    this->head = nullptr;
    this->tail = nullptr;
    return *this;
}
void LinkedList::pushTail(string _name, float _amount) {

    Node* newNode = new Node(_name,_amount);
    if(this->head == nullptr){
        this->head = newNode;
        tail = head;

    }else {
        tail->next =newNode;
        tail = tail->next;
    }
    this->length++;
}
void LinkedList::updateNode(string _name, float _amount) {
    Node* tmp = this->head;
    while(tmp->name != _name){
        tmp = tmp->next;
    }
    tmp->amount = _amount;
}


LinkedList::~LinkedList() {

    delete (this->head, this->tail);
}
