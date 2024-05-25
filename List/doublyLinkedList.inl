template<typename T>
DoublyLinkedList<T>::DoublyLinkedList():head(nullptr), tail(nullptr), size(0) { }

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : head(nullptr), tail(nullptr), size(0) {
    Node<T>* temp = other.head;
    while (temp) {
        this->push_back(temp->data);
        temp = temp->next;
    }
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}
    
template<typename T>
void DoublyLinkedList<T>::erase_front() {
    if (!head) {
        return; 
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

template<typename T>
void DoublyLinkedList<T>::erase_back() {
    if (!head) {
        return;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

template<typename T>
void DoublyLinkedList<T>::erase_node(const size_t& index){
    if(index > getSize()){
        throw std::out_of_range("Index out of range");
    } else {
        if(index == 0) { 
            erase_front();
            return;
        }
        Node<T>* temp = head;
        for(int i = 0; i < index; ++i){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if(temp->next){
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty(){
    return !head;
}

template<typename T>
const size_t DoublyLinkedList<T>::getSize() {
    size = 0;
    Node<T>* temp = head;
    while (temp) {
        ++size;
        temp = temp->next;
    }
    return size;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& list) {
    typename DoublyLinkedList<U>::Node<U>* temp = list.head;
    while (temp != nullptr) {
        os << temp->data << ", ";
        temp = temp->next;
    }
    os << "\n";
    return os;
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
    if(this == &other){
        return *this;
    }
    else {
        Node<T>* temp = other.head;
        while (temp) {
            this->push_back(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

//iterator functions

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() const {
    return Iterator(head, nullptr); 
}

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() const {
    return Iterator(nullptr, tail); 
}

//iterator

template<typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node<T>* current_, Node<T>* prev_):current(current_), prev(prev_) {

}

template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++() {
    current = current->next;
    return *this;
}

template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    current = current->next;;
    return temp;
}


template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator--() {
    current = current->prev;
    return *this;
}

template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    current = current->prev;
    return temp;
}

template<typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template<typename T>
bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

template<typename T>
T& DoublyLinkedList<T>::Iterator::operator*() {
    return current->data;
}

template<typename T>
T* DoublyLinkedList<T>::Iterator::operator->() {
    return &current->data;
}