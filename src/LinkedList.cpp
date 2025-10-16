#include "LinkedList.hpp"
#include <sstream>

LinkedList::LinkedList() : head_(nullptr) {}
LinkedList::~LinkedList() {
    Node* p = head_;
    while (p) { Node* n = p->next; delete p; p = n; }
}
void LinkedList::push_front(int v) { head_ = new Node(v, head_); }
void LinkedList::remove_evens() {
    Node* curr = head_;
    Node* prev = nullptr;
    while (curr) {
        if (curr->value%2 == 0) {
            Node* temp = curr;
            prev->next = curr->next;
            delete temp;
            curr = prev->next;
            prev = curr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    // TODO: implement
}
std::string LinkedList::to_string() const {
    std::ostringstream oss;
    oss << "[";
    Node* p = head_;
    bool first = true;
    while (p) {
        if (!first) oss << ", ";
        first = false;
        oss << p->value;
        p = p->next;
    }
    oss << "]";
    return oss.str();
}
