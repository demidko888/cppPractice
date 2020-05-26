#pragma once
class Node {
public:
    Node(int value);
    bool deleteNext();
    Node* getNext() const;
    int getValue() const;
    void setValue(int value);
    void push(Node* node);
    ~Node();
private:
    int Value;
    Node* Next = nullptr;
};