#pragma once

#include "Node.hpp"
#include <iostream>

template <typename T>
class LinkedList
{
public:
    LinkedList() = default;
    ~LinkedList()
    {
        auto *traversing_node = head_;
        while (traversing_node)
        {
            auto *temp_node = traversing_node;

            traversing_node = traversing_node->getNext();

            delete temp_node;
        }
    }

    Node<T> *getHead() { return head_; }
    Node<T> *getTail() { return tail_; }

    void setHead(const T &payload)
    {
        // create the new node
        Node<T> *createdNode = new Node(payload);

        // take current head's next node and set new node next to it
        if (head_ != tail_)
        {
            Node<T> *tempNode = head_->getNext();
            createdNode->setNext(tempNode);
        }

        delete head_;

        head_ = createdNode;
    }

    void setTail(const T &payload)
    {
        Node<T> *createdNode = new Node(payload);

        if (!tail_)
        {
            tail_ = createdNode;
            return;
        }

        // traverse
        Node<T> *traversingNode = head_;
        while (traversingNode->getNext()->getNext()) // 2nd to last
        {
            traversingNode = traversingNode->getNext();
        }

        Node<T> *oldTail = traversingNode->getNext();
        traversingNode->setNext(createdNode);

        delete oldTail;
    }

    void append(const T &payload)
    {
        Node<T> *createdNode = new Node(payload);

        if (tail_)
        {
            tail_->setNext(createdNode);
        }

        tail_ = createdNode;

        if (!head_)
        {
            head_ = tail_;
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const LinkedList &list)
    {
        // by default, print iteratively
        Node<T> *currNode = list.head_;

        out << '{';

        while (currNode)
        {
            out << currNode->getPayload() << ", ";
            currNode = currNode->getNext();
        }

        out << "}\n";
        return out;
    }

    std::string recurPrintList(Node<T> *currNode)
    {
        if (!currNode)
            return "}\n";

        std::string str;
        if (currNode == head_)
            str += "{";

        // does not work for class types because of std::to_string()
        return str + std::to_string(currNode->getPayload()) + ", " + recurPrintList(currNode->getNext());
    }

private:
    Node<T> *head_ = nullptr;
    Node<T> *tail_ = nullptr;
};