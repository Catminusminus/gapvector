#ifndef GAPVECTOR_PIMPL_IMPLEMENT_HPP
#define GAPVECTOR_PIMPL_IMPLEMENT_HPP

template <typename T>
gapvectorPimpl<T>::gapvectorPimpl(const gapvectorPimpl &another)
{
    gap_v = std::make_unique<gapvector<T>>();
    *gap_v = *(another.gap_v);
}

template <typename T>
gapvectorPimpl<T>::gapvectorPimpl(std::initializer_list<T> init_list)
{
    gap_v = std::make_unique<gapvector<T>>(init_list);
}

template <typename T>
gapvectorPimpl<T>::~gapvectorPimpl() = default;

template <typename T>
gapvectorPimpl<T> &gapvectorPimpl<T>::operator=(const gapvectorPimpl &another)
{
    if (another.gap_v == nullptr)
        return *this;
    *gap_v = *(another.gap_v);
    return *this;
}

template <typename T>
gapvectorPimpl<T> &gapvectorPimpl<T>::operator=(std::initializer_list<T> init_list)
{
    gap_v.reset();
    gap_v = std::make_unique<gapvector<T>>(init_list);
}

template <typename T>
template <class inputIterator>
void gapvectorPimpl<T>::assign(inputIterator first, inputIterator end)
{
    gap_v->assign(first, end);
}

template <typename T>
void gapvectorPimpl<T>::assign(size_t size, const T &value)
{
    gap_v->assign(size, value);
}

template <typename T>
void gapvectorPimpl<T>::assign(std::initializer_list<T> init_list)
{
    gap_v->assign(init_list);
}

template <typename T>
void gapvectorPimpl<T>::insert(size_t index, const T &value)
{
    gap_v->insert(index, value);
}

template <typename T>
void gapvectorPimpl<T>::insert(size_t index, T &&value)
{
    gap_v->insert(index, std::move(value));
}

template <typename T>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::insert(iterator itr, const T &value)
{
    return gap_v->insert(itr, value);
}

template <typename T>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::insert(const_iterator itr, const T &value)
{
    return gap_v->insert(itr, value);
}

template <typename T>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::insert(iterator itr, T &&value)
{
    return gap_v->insert(itr, value);
}

template <typename T>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::insert(const_iterator itr, T &&value)
{
    return gap_v->insert(itr, value);
}

template <typename T>
void gapvectorPimpl<T>::insert(iterator itr, size_t number, const T &value)
{
    gap_v->insert(itr, number, value);
}

template <typename T>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::insert(const_iterator itr, size_t number, const T &value)
{
    return gap_v->insert(itr, number, value);
}

template <typename T>
template <typename inputIterator>
void gapvectorPimpl<T>::insert(iterator itr, inputIterator first, inputIterator end)
{
    gap_v->insert(itr, first, end);
}

template <typename T>
template <typename inputIterator>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::insert(const_iterator itr, inputIterator first, inputIterator end)
{
    return gap_v->insert(itr, first, end);
}

template <typename T>
template <class... Args>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::emplace(const_iterator itr, Args &&... args)
{
    return gap_v->emplace(itr, std::forward<Args>(args)...);
}

template <typename T>
void gapvectorPimpl<T>::push_back(const T &value)
{
    gap_v->push_back(value);
}

template <typename T>
void gapvectorPimpl<T>::push_back(T &&value)
{
    gap_v->push_back(std::move(value));
}

template <typename T>
template <class... Args>
void gapvectorPimpl<T>::emplace_back(Args &&... args)
{
    gap_v->emplace_back(std::forward<Args>(args)...);
}

template <typename T>
void gapvectorPimpl<T>::erase(size_t index)
{
    gap_v->erase(index);
}

template <typename T>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::erase(iterator itr)
{
    return gap_v->erase(itr);
}

template <typename T>
void gapvectorPimpl<T>::pop_back()
{
    gap_v->pop_back();
}

template <typename T>
void gapvectorPimpl<T>::clear() noexcept
{
    gap_v->clear();
}

template <typename T>
size_t gapvectorPimpl<T>::size() const noexcept
{
    return gap_v->size();
}

template <typename T>
void gapvectorPimpl<T>::swap(gapvectorPimpl<T> &another)
{
    this->gap_v.swap(another.gap_v);
}

template <typename T>
T &gapvectorPimpl<T>::operator[](size_t index)
{
    return (*gap_v)[index];
}

template <typename T>
const T &gapvectorPimpl<T>::operator[](size_t index) const
{
    return (*gap_v)[index];
}

template <typename T>
T &gapvectorPimpl<T>::at(size_t index)
{
    return gap_v->at(index);
}

template <typename T>
const T &gapvectorPimpl<T>::at(size_t index) const
{
    return gap_v->at(index);
}

template <typename T>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::begin() noexcept
{
    return gap_v->begin();
}

template <typename T>
typename gapvectorPimpl<T>::const_iterator gapvectorPimpl<T>::begin() const noexcept
{
    return gap_v->cbegin();
}

template <typename T>
typename gapvectorPimpl<T>::iterator gapvectorPimpl<T>::end() noexcept
{
    return gap_v->end();
}

template <typename T>
typename gapvectorPimpl<T>::const_iterator gapvectorPimpl<T>::end() const noexcept
{
    return gap_v->cend();
}

template <typename T>
typename gapvectorPimpl<T>::const_iterator gapvectorPimpl<T>::cbegin() const noexcept
{
    return gap_v->cbegin();
}

template <typename T>
typename gapvectorPimpl<T>::const_iterator gapvectorPimpl<T>::cend() const noexcept
{
    return gap_v->cend();
}

template <typename T>
typename gapvectorPimpl<T>::reverse_iterator gapvectorPimpl<T>::rbegin() noexcept
{
    return gap_v->rbegin();
}

template <typename T>
typename gapvectorPimpl<T>::const_reverse_iterator gapvectorPimpl<T>::rbegin() const noexcept
{
    return gap_v->crbegin();
}

template <typename T>
typename gapvectorPimpl<T>::reverse_iterator gapvectorPimpl<T>::rend() noexcept
{
    return gap_v->rend();
}

template <typename T>
typename gapvectorPimpl<T>::const_reverse_iterator gapvectorPimpl<T>::rend() const noexcept
{
    return gap_v->crend();
}

template <typename T>
typename gapvectorPimpl<T>::const_reverse_iterator gapvectorPimpl<T>::crbegin() const noexcept
{
    return gap_v->crbegin();
}

template <typename T>
typename gapvectorPimpl<T>::const_reverse_iterator gapvectorPimpl<T>::crend() const noexcept
{
    return gap_v->crend();
}

template <typename T>
bool gapvectorPimpl<T>::empty() const noexcept
{
    return gap_v->empty();
}

template <typename T>
T &gapvectorPimpl<T>::front()
{
    return gap_v->front();
}

template <typename T>
const T &gapvectorPimpl<T>::front() const
{
    return gap_v->front();
}

template <typename T>
T &gapvectorPimpl<T>::back()
{
    return gap_v->back();
}

template <typename T>
const T &gapvectorPimpl<T>::back() const
{
    return gap_v->back();
}

template <typename T>
T *gapvectorPimpl<T>::data() noexcept
{
    return gap_v->data();
}

template <typename T>
const T *gapvectorPimpl<T>::data() const noexcept
{
    return gap_v->data();
}

#endif
