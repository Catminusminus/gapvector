#ifndef GAPVECTOR_CONST_REVERSE_ITERATOR_IMPLEMENT_HPP
#define GAPVECTOR_CONST_REVERSE_ITERATOR_IMPLEMENT_HPP

template <typename T>
void gapvectorConstRevrseIterator<T>::increment()
{
    --index;
}

template <typename T>
void gapvectorConstReverseIterator<T>::decrement()
{
    ++index;
}

template <typename T>
const T &gapvectorConstReverseIterator<T>::dereference() const
{
    return (gap_vector->at(index - 1));
}

template <typename T>
bool gapvectorConstReverseIterator<T>::equal(const gapvectorConstReverseIterator<T> &anotherIterator) const
{
    return (this->gap_vector == anotherIterator.gap_vector && this->index == anotherIterator.index);
}

template <typename T>
size_t gapvectorConstReverseIterator<T>::distance_to(const gapvectorConstReverseIterator<T> &anotherIterator) const
{
    if (this->index >= anotherIterator.index)
    {
        return this->index - anotherIterator.index;
    }
    return anotherIterator.index - this->index;
}

template <typename T>
void gapvectorConstReverseIterator<T>::advance(size_t difference)
{
    index -= difference;
}

template <typename T>
gapvectorConstReverseIterator<T>::gapvectorConstReverseIterator()
{
}

template <typename T>
gapvectorConstReverseIterator<T>::gapvectorConstReverseIterator(const gapvector<T> *gap_v, size_t ind) : gap_vector(gap_v), index(ind)
{
}

#endif
