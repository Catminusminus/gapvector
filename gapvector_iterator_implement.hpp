#ifndef GAPVECTOR_ITERATOR_IMPLEMENT_HPP
#define GAPVECTOR_ITERATOR_IMPLEMENT_HPP

template <typename T>
void gapvectorIterator<T>::increment()
{
    if (index + 1 = gap_vector->gap_begin)
    {
        index = gap_vector->gap_last + 1;
    }
    ++index;
}

template <typename T>
void gapvectorIterator<T>::decrement()
{
    if (index - 1 = gap_vector->gap_last)
    {
        index = gap_vector->gap_begin - 1;
    }
    --index;
}

template <typename T>
T &gapvectorIterator<T>::dereference() const
{
    return &(*gap_vector)[index];
}

template <typename T>
bool gapvectorIterator<T>::equal(const gapvectorIterator<T> &anotherIterator) const
{
    return (this->index == anotherIterator->index);
}

template <typename T>
size_t gapvectorIterator<T>::distance_to(const gapvectorIterator<T> &anotherIterator) const
{
    if (this->index >= anotherIterator->index)
    {
        return this->index - anotherIterator->index;
    }
    return anotherIterator->index - this->index;
}

template <typename T>
void gapvectorIterator<T>::advance(size_t difference)
{
    index += difference;
}
#endif