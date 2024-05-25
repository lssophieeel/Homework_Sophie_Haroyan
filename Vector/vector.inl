template<typename T>
Vector<T>::Vector() : capacity_(0), size_(0), data_(nullptr){}

template<typename T>
Vector<T>::Vector(size_t size) : capacity_(size*1.6), size_(size) {
    data_ = (new T[capacity_]);
}

template<typename T>
Vector<T>::Vector(size_t size, const T& value) :capacity_(size*1.6), size_(size) {
    data_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = value;
    }
}

template<typename T>
Vector<T>::Vector(const Vector& other) : capacity_(other.capacity_), size_(other.size_)  {
    data_ = new T[other.capacity_];
    for (size_t i = 0; i < other.size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (size_ + 1 > capacity_) {
        reallocate();
    }
    data_[size_] = value;
    ++size_;
}

template<typename T>
void Vector<T>::reallocate(){
    capacity_ *= 1.6;
    //T* temp = static_cast<T*>(realloc(data_, capacity_)); 
    T* temp = new T[capacity_];
    for (size_t i = 0; i < size_; ++i){
        temp[i] = std::move(data_[i]);
    }
    delete[] data_;
    data_ = temp;
}

template<typename T>
void Vector<T>::pop_back() {
    if(size_ > 0){
        data_[size_ - 1].~T();
        --size_;
    }
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= size_)
        throw std::out_of_range("Index out of range");
    return data_[index];
}
template<typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size_)
        throw std::out_of_range("Index out of range");
    return data_[index];
}

template<typename T>
const size_t Vector<T>::size() const{
    return size_;
}

template<typename T>
const bool Vector<T>::isEmpty() const{
    if(data_ == nullptr){
        return 1;
    }
    return 0;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec) {
    if (!vec.isEmpty()) {
        os << vec[0];
        for (size_t i = 1; i < vec.size(); ++i)
            os << ", " << vec[i];
    }
    os << "\n";
    return os;
}


template<typename T>
void Vector<T>::insert(const size_t& index, const T& element) {
    if (index >= size_){
        throw std::out_of_range("Index out of range");
    }
    if (size_ + 1 > capacity_) {
        reallocate();
    }
    ++size_;
    for (size_t i = size_ - 1; i >= index + 1; --i){
        data_[i] = data_[i - 1];
    }
    data_[index] = element;
}

template<typename T>
void Vector<T>::erase(const size_t& index) {
    if (index >= size_){
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size_ - 1; ++i){
        data_[i] = std::move(data_[i + 1]);
    }
    data_[size_ - 1].~T();
    --size_;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other){
    if(this != &other){
        delete[] data_;
        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data_;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::begin() const {
    return Iterator(data_); 
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::end() const {
    return Iterator(data_ + size_); 
}

//iterator

template<typename T>
Vector<T>::Iterator::Iterator(T* it_) : it(it_) {}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
    ++it;
    return *this;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++it;
    return temp;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--() {
    --it;
    return *this;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    --it;
    return temp;
}

template<typename T>
bool Vector<T>::Iterator::operator==(const Vector<T>::Iterator& other) const {
    return it == other.it;
}

template<typename T>
bool Vector<T>::Iterator::operator!=(const Vector<T>::Iterator& other) const {
    return it != other.it;
}

template<typename T>
T& Vector<T>::Iterator::operator*() { 
    return *it;
}

template<typename T>
T* Vector<T>::Iterator::operator->() { 
    return it; 
}
