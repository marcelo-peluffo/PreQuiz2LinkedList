#pragma once

template <typename T>
class Node
{
public:
    Node<T>() = default;
    Node<T>(const T &payload)
        : payload_(payload)
    {
    }
    Node<T>(const Node<T> &other) = delete;
    Node<T> &operator=(const Node<T> &other) = delete;

    Node<T> *getNext() { return next_; }
    const T &getPayload() const { return payload_; }

    void setNext(Node<T> *next) { next_ = next; }
    void setPayload(const T &payload) { payload_ = payload; }

private:
    Node<T> *next_ = nullptr;
    T payload_;
};