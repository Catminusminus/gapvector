#ifndef GAPVECTOR_CONST_ITERATOR_IMPLEMENT_HPP
#define GAPVECTOR_CONST_ITERATOR_IMPLEMENT_HPP

template <typename T>
void gapvectorConstIterator<T>::increment()
{
    ++index;
}

template <typename T>
void gapvectorConstIterator<T>::decrement()
{
    --index;
}

template <typename T>
const T &gapvectorConstIterator<T>::dereference() const
{
    return (gap_vector->at(index));
}

template <typename T>
bool gapvectorConstIterator<T>::equal(const gapvectorConstIterator<T> &anotherIterator) const
{
    return (this->index == anotherIterator.index);
}

template <typename T>
size_t gapvectorConstIterator<T>::distance_to(const gapvectorConstIterator<T> &anotherIterator) const
{
    if (this->index >= anotherIterator.index)
    {
        return this->index - anotherIterator.index;
    }
    return anotherIterator.index - this->index;
}

template <typename T>
void gapvectorConstIterator<T>::advance(size_t difference)
{
    index += difference;
}

template <typename T>
gapvectorConstIterator<T>::gapvectorConstIterator()
{
}

template <typename T>
gapvectorConstIterator<T>::gapvectorConstIterator(const gapvector<T> *gap_v) : gap_vector(gap_v)
{
}

#endif
