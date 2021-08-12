#include <iostream>

using namespace std;

//constructor.
template<typename T>
TList<T>::TList()
{
    //empty list
    size = 0;
    first = nullptr;
    last = nullptr;
    
}

//constructor
template<typename T>
TList<T>::TList(T val, int d)
{
//let size = 0
    size = 0;

    if (d == 0)
    {
        first = nullptr;
      last = nullptr;
        return;
    }
    //setting node 1
    first = new Node<T>(val); 
    size++; 

    //will be used to iterate
    Node<T>* current = first; 

    for (int i = 0; i < d - 1; i++)
    {
        current->next = new Node<T>(val);
        current->next->prev = current;
        size++; 
        current = current->next; // pointing to next node

        if (i + 1 == d - 1)
        {
            //last node
            last = current;
        }
    }
}

//destructor
template<typename T>
TList<T>::~TList()
{
    //calling clear function
    Clear();
}

//copy constructor
template<typename T>
TList<T>::TList(const TList<T>& L)
{
    //pointers as null
    first = nullptr;
        last = nullptr;
    //copy list
    *this = L; 
    //size same as list L
    size = L.size; 
}


//move constructor
template<typename T>
TList<T>::TList(TList<T>&& L)
{
    //variables same as the input list and make L as NULL
    size = L.size;
    L.size = 0;
    first = L.first;
    L.first = nullptr;
    last = L.last;
    L.last = nullptr;
}


//= operator
template<typename T>
TList<T>& TList<T>::operator = (const TList<T>& L)
{
    //if it is not already equal proceed
    if (this != &L) {

        //make list empty
        if (first != nullptr)
        {
            //calling clear function
            Clear();
        }

        //nodes used to copy
        Node<T>* copyNode = nullptr, * originalNode = L.first;

        // Loop through each node in the input list
        while (originalNode != nullptr)
        {
            // if empty list
            if (first == nullptr)
            {
                first = last = copyNode = new Node<T>(originalNode->data);
            }
            else
            {

                copyNode->next = new Node<T>(originalNode->data);
                copyNode->prev = originalNode->prev;

                //reference to next node
                copyNode = copyNode->next;
            }
            //reference to next original node
            originalNode = originalNode->next;
        }
    }
    return *this;
}

//= operator
template<typename T>
TList<T>& TList<T>::operator = (TList<T>&& L)
{
    //making empty
    Clear();

    //assigning values of input list
    this->first = L.first;
    this->last = L.last;
    this->size = L.size;

    //L as NULL
    L.first = nullptr;
        L.last = nullptr;
    L.size = 0;

    return *this;
}


//clear function
template<typename T>
void TList<T>::Clear()
{
    //loop till the list is empty
    while (!IsEmpty())
    {
        //deleting node by node
        Node<T>* current = first;
        first = current->next;
        delete current;
        size--; 
    }
}

//empty function
template<typename T>
bool TList<T>::IsEmpty() const
{
    //return true if the list is empty
    return GetSize() == 0;
}


//get size function returns the size
template<typename T>
int TList<T>::GetSize() const
{
    return size;
}


//inserting node at the back 
template<typename T>
void TList<T>::InsertBack(const T& d)
{
    //new node creation
    auto* newNode = new Node<T>(d);

    //if empty node, newNode will be the first node
    if (IsEmpty())
    {
        first = last = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        size++;

        return;
    }

    //else newNode will be insert at the last
    newNode->next = nullptr;
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
    size++;
}


//inserting new node at front
template<typename T>
void TList<T>::InsertFront(const T& d)
{
    //new node creation
    auto* newNode = new Node<T>(d);

    //if empty node, newNode will be the first node
    if (IsEmpty())
    {
        first = last = newNode;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        size++;
        return;
    }

    //else newNode will be insert at the front
    first->prev = newNode;
    newNode->next = first;
    newNode->prev = nullptr;
    first = newNode;
    size++;
}



//removing last node
template<typename T>
void TList<T>::RemoveBack()
{
    //if the list is already empty, nothing will happen
    if (IsEmpty())
        return;

    //temp node creation that has reference of first
    Node<T>* tempNode = last;

    if (last->prev != nullptr)
    {
        last->prev->next = nullptr;
        last = last->prev; 
        delete tempNode;
        size--; 
    }
    else
    {
        first = nullptr;
        size--;
    }
}

//removing front node
template<typename T>
void TList<T>::RemoveFront()
{
    //if the list is already empty, nothing will happen
    if (IsEmpty())
        return;

    //temp node creation that has reference of first
    Node<T>* tempNode = first;

    if (first->next != nullptr)
    {
        first->next->prev = nullptr;
        first = first->next;
        delete tempNode;
        size--;
    }
    else
    {
        first = nullptr;
        size--;
    }
}


//this will return the last node
template<typename T>
T& TList<T>::GetLast() const
{
    if (IsEmpty())
        return dummy;

    //if list is not empty return last node data
    return last->data;
}
//this will return first node
template<typename T>
T& TList<T>::GetFirst() const
{
    if (IsEmpty())
        return dummy;
    //if list is not empty return first node data
    return first->data;
}


//get iterator to the last node
template<typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const
{

    //if empty list,default iterator
    if (IsEmpty())
        return TListIterator<T>();

    //if list is not empty, iterator to the last node
    TListIterator<T> iter;
    iter.ptr = last;

    return iter;
}

//get iterator to the first node
template<typename T>
TListIterator<T> TList<T>::GetIterator() const
{

    //if empty list,default iterator
    if (IsEmpty())
        return TListIterator<T>();

    //if list is not empty, iterator to the first node
    TListIterator<T> iter;
    iter.ptr = first;

    return iter;
}


//insert new node at position
template<typename T>
void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
    //reference to first node
    Node<T>* current = first;

    //iterate till correct position is found
    while (current != nullptr)
    {
        //if position is correct, insert node
        if (pos.ptr == current)
        {

            auto* newNode = new Node<T>(d);
            newNode->next = current;

            //update prev noe, if we are not at the start of list
            if (current->prev != nullptr)
            {
                newNode->prev = current->prev;
                current->prev->next = newNode;
            }
            else
            {
                //update prev node, if we are at start of list
                newNode->prev = nullptr;
                first = newNode; 
            }

            current->prev = newNode;
            size++;
        }

        //update last, if we are at the end of list
        if (current->next == nullptr)
            last = current;

        //update first, if we are at the start of list
        if (current->prev == nullptr)
            first = current;

        // reference to the next node
        current = current->next;
    }
}


//print function
template<typename T>
void TList<T>::Print(std::ostream& os, char delim) const
{
    if (IsEmpty())
        return;

    //reference to first node
    Node<T>* current = first; 

    //loop till the list is empty
    while (current != nullptr)
    {
        //print
        cout << current->data << delim;
        current = current->next;
    }
}

//removing node from position
template<typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
    //if empty list
    if (IsEmpty())
        return pos;

    //node referencing to first node
    Node<T>* current = first;

    //loop till the correct position is found
    while (current != nullptr)
    {
        //remove node, if reach the correct position
        if (current == pos.ptr)
        {
            if (current->prev != nullptr && current->next != nullptr)
            {
                //update neighbor nodes when remove the node to maintain the links
                current->prev->next = current->next;
                current->next->prev = current->prev;
                size--;
            }
            //when list has more than one nodes
            else if (current->next == nullptr && current->prev != nullptr)
            {
                //update the nodes
                current->prev->next = nullptr;
                size--;
            }
            else if (current->prev == nullptr && current->next != nullptr)
            {
                // Update the node
                current->next->prev = nullptr;
                size--;
            }
        }

        if (current->next == nullptr)
            last = current;

        //reference to the next node
        current = current->next;
    }
    //delete the correct position
    delete current;

    return pos.Next();
}


//iterator constructor
template<typename T>
TListIterator<T>::TListIterator()
{
    //seting ptr to null
    this->ptr = nullptr;
}

//if there is the prev item, this function will return true
template<typename T>
bool TListIterator<T>::HasPrevious() const
{
    return this->ptr->prev != nullptr;
}

//if there is the next item, this function will return true
template<typename T>
bool TListIterator<T>::HasNext() const
{
    return this->ptr->next != nullptr;
}

//iterator reference to the prev item
template<typename T>
TListIterator<T> TListIterator<T>::Previous()
{
    if (HasPrevious())
        this->ptr = this->ptr->prev;

    return *this;
}

//iterator reference to the next item
template<typename T>
TListIterator<T> TListIterator<T>::Next()
{
    if (HasNext())
        this->ptr = this->ptr->next;

    return *this;
}


//+ operator
template<typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2)
{
    //creating an empty list
    auto  newList = new TList<T>();

    //iterator to first node
    TListIterator<T> itr = t1.GetIterator();

    //copy all nodes
    while (itr.HasNext())
    {
        newList->InsertBack(itr.GetData());
        itr.Next();

        if (!itr.HasNext())
        {
            newList->InsertBack(itr.GetData());
        }
    }

    //iterator to first node of t2
    TListIterator<T> newItr = t2.GetIterator();

    //iterate through t2 and copy all nodes
    while (newItr.HasNext())
    {
        newList->InsertBack(newItr.GetData());
        newItr.Next();

        if (!newItr.HasNext())
        {
            newList->InsertBack(newItr.GetData());
        }
    }
    
    //new list
    return *newList;
}
//this function will return the data
template<typename T>
T& TListIterator<T>::GetData() const
{
    return ptr->data;
}
