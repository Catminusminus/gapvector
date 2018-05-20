#ifndef GAPVECTOR_REVERSE_ITERATOR_IMPLEMENT_HPP
#define GAPVECTOR_REVERSE_ITERATOR_IMPLEMENT_HPP

template <typename T>
void gapvectorReverseIterator<T>::increment()
{
    --index;
}

template <typename T>
void gapvectorReverseIterator<T>::decrement()
{
    ++index;
}

template <typename T>
T &gapvectorReverseIterator<T>::dereference() const
{
    return (gap_vector->at(index - 1));
}

template <typename T>
bool gapvectorReverseIterator<T>::equal(const gapvectorReverseIterator<T> &anotherIterator) const
{
    return (this->gap_vector == anotherIterator.gap_vector && this->index == anotherIterator.index);
}

template <typename T>
size_t gapvectorReverseIterator<T>::distance_to(const gapvectorReverseIterator<T> &anotherIterator) const
{
    if (this->index >= anotherIterator.index)
    {
        return this->index - anotherIterator.index;
    }
    return anotherIterator.index - this->index;
}

template <typename T>
void gapvectorReverseIterator<T>::advance(size_t difference)
{
    index -= difference;
}

template <typename T>
gapvectorReverseIterator<T>::gapvectorReverseIterator()
{
}

template <typename T>
gapvectorReverseIterator<T>::gapvectorReverseIterator(gapvector<T> *gap_v, size_t ind) : gap_vector(gap_v), index(ind)
{
}

#endif
