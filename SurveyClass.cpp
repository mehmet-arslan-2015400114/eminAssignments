#include "SurveyClass.h"
SurveyClass::SurveyClass() {
    this->members = new LinkedList();
}
SurveyClass::SurveyClass(const SurveyClass &other) {

this->members = other.members;
}
SurveyClass& SurveyClass::operator=(const SurveyClass &list) {

    this->members = list.members;
    return *this;
}
SurveyClass::SurveyClass(SurveyClass &&other) {

this->members = move(other.members);
//*********************
delete other.members;
}
SurveyClass& SurveyClass::operator=(SurveyClass &&list) {

this->members = move(list.members);
delete list.members;
    return  *this;
}
SurveyClass::~SurveyClass() {

    delete this->members;
}
void SurveyClass::handleNewRecord(string _name, float _amount) {
    Node* temp = members->head;
    if(members->head == nullptr){
        members->pushTail(_name,_amount);
    }
    else if(members->head->name == _name){
        members->updateNode(_name,_amount);
    }else {
        while (temp->next != nullptr) {
            if (temp->name == _name) {
                members->updateNode(_name,_amount);

                break;
            }

            temp = temp->next;
        }

        if (temp->next == nullptr) {
            members->pushTail(_name, _amount);

        }
    }

}
float SurveyClass::calculateMaximumExpense() {
    Node* temp = members->head;
    float max = temp->amount;
    while(temp->next != nullptr){
        temp = temp->next;
        if(temp->amount > max) {
            max = temp->amount;
        }
    }
    return max;
}
float SurveyClass::calculateMinimumExpense() {
    Node* temp = members->head;
    float min = temp->amount;
    while(temp->next != nullptr){
        temp = temp->next;
        if(temp->amount < min) {
            min = temp->amount;
        }
    }
    return min;
}
float SurveyClass::calculateAverageExpense() {
    Node* temp = members->head;
    float sum = temp->amount;
    while(temp->next != nullptr){
        temp = temp->next;
        sum = sum + temp->amount;
    }
    return (float)((int)((sum/members->length)*100))/100;
}