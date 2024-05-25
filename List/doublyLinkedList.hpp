#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template<typename T>
class DoublyLinkedList{
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>&);
    ~DoublyLinkedList();

    //functions
    void push_back(const T&); 
    void push_front(const T&);
    void erase_back();
    void erase_front();
    void erase_node(const size_t&);
    bool isEmpty();
    const size_t getSize();

    //operators
    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const DoublyLinkedList<U>&);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& );
    
    //node
    template<typename U>
    class Node {
    public:
        U data;
        Node<U>* prev;
        Node<U>* next;
        Node(const U& data_) : data(data_), prev(nullptr), next(nullptr) {}
    };

    //iterator
    class Iterator{
    public:
        Iterator(Node<T>*, Node<T>*);
        Iterator &operator++(); 
        Iterator &operator++(int);
        Iterator &operator--(); 
        Iterator &operator--(int);
        bool operator!=(const Iterator&) const;
        bool operator==(const Iterator&) const;
        T& operator*();
        T* operator->();
    private:
        Node<T>* current;
        Node<T>* prev;
    };

    //iterator functions
    Iterator begin() const;
    Iterator end() const;
    
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

};

#include "doublyLinkedList.inl"
#endif