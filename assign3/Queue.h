//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef QUEUE_H
#define QUEUE_H


/**
 * @brief Queue defined using array as ring
 */
template <class T>
class Queue
{
private:
    T* data;
    int start;
    int end;
    int dataSize;

    /**
     * @brief used to allocate a larger backing array when storage fills
     */
    void grow();

public:
    /**
     * @brief Construct empty stack
     */
    Queue();

    /**
     * @brief Copy constructor
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Queue(const Queue<T>& other);

    /**
     * @brief Assignment Operator
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Queue<T>& operator=(const Queue<T>& other);

    /**
     * @brief Destructor
     */
    ~Queue();

    /**
     * @brief Check if queue is empty
     * @return true if nothing in the queue, false otherwise
     */
    int getStart() const;

    int getEnd() const;

    int getDataSize() const;

    bool isEmpty() const;

    /**
     * @brief add item to back of queue
     * @param value Item to add
     */
    void enqueue(const T& item);

    /**
     * @brief Remove and return front item from queue
     * @return Item that was at the front of the queue
     * Can throw exception/blow up with assertion if currently empty
     */
    T dequeue();

    /**
     * @brief Return a copy of the front item
     * @return Item that is at the front of the queue
     */
    T front() const;

    /**
     * @brief print the queue
     */
    void print() const;
};

//--------------------------------------------------------------------
// Queue Implementations
//--------------------------------------------------------------------

template <class T>
void Queue<T>::grow()
{
    this->dataSize *= 2;
}
/**
 * @brief Construct empty stack
 */
template <class T>
Queue<T>::Queue()
{
    this->start = 0;
    this->end = 0;
    this->dataSize = 20;
    this->data = new T[dataSize];
}

/**
 * @brief Copy constructor
 *
 * Implement if you need it, otherwise not required
 * Declared to prevent default shallow copy
 */
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{

}

/**
 * @brief Assignment Operator
 *
 * Implement if you need it, otherwise not required
 * Declared to prevent default shallow copy
 */
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{

}

/**
 * @brief Destructor
 */
template <class T>
Queue<T>::~Queue()
{
    delete [] data;
}

template <class T>
int Queue<T>::getStart() const
{
    return this->start;
}

template <class T>
int Queue<T>::getEnd() const
{
    return this->end;
}

template <class T>
int Queue<T>::getDataSize() const
{
    return this->dataSize;
}

/**
 * @brief Check if queue is empty
 * @return true if nothing in the queue, false otherwise
 */
template <class T>
bool Queue<T>::isEmpty() const
{
    if (this->start == this->end)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief print the queue
 */
template <class T>
void Queue<T>::print() const
{
    int curLoc = this->start;
    while (curLoc != this->end)
    {
        std::cout << data[curLoc] << " ";
        curLoc++;
        if (curLoc == this->dataSize)
        {
            curLoc = 0;
        }
    }
    std::cout << std::endl;
}

/**
 * @brief add item to back of queue
 * @param value Item to add
 */
template <class T>
void Queue<T>::enqueue(const T& item)
{
    this->data[end] = item;
    this->end++;
    if (this->end == this->dataSize)
    {
        this->grow();
    }
}

/**
 * @brief Remove and return front item from queue
 * @return Item that was at the front of the queue
 * Can throw exception/blow up with assertion if currently empty
 */
template <class T>
T Queue<T>::dequeue()
{
    if (this->isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
    }
        T thing = this->data[start];
        this->start++;
        return thing;
}

/**
 * @brief Return a copy of the front item
 * @return Item that is at the front of the queue
 */
template <class T>
T Queue<T>::front() const
{
    if (this->start == this->end)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }
    return this->data[start];
}



#endif // STACK_H
