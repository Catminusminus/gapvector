#ifndef GAPVECTOR_PIMPL_HPP
#define GAPVECTOR_PIMPL_HPP
#include "gapvector.hpp"

namespace my
{
template <typename T>
class gapvectorPimpl
{
    template <typename T>
    class gapvector;
    std::unique_ptr<gapvector<T>> gapvector_p;

  public:
    gapvectorPimpl() : gapvector_p(std::make_unique<gapvector<T>>()) {}
    gapvectorPimpl(const gapvectorPimpl &);
    gapvectorPimpl(gapvectorPimpl &&) = default;
    gapvectorPimpl(std::initializer_list<T>);

    gapvectorPimpl &operator=(const gapvectorPimpl &);
    gapvectorPimpl &operator=(gapvectorPimpl &&) = default;
    gapvectorPimpl &operator=(std::initializer_list<T>);

    template <class inputIterator, class inputIterator>
    void assign(inputIterator, inputIterator);
    void assign(size_t, const T &);
    void assign(std::initializer_list<T>);

    void insert(size_t, const T &);
    void insert(size_t, T &&);
    iterator insert(iterator, const T &);
    iterator insert(const_iterator, const T &);
    iterator insert(iterator, T &&);
    iterator insert(const_iterator, T &&);
    void insert(iterator, size_t, const T &);
    iterator insert(const_iterator, size_t, const T &);
    template <class inputIterator>
    void insert(iterator, inputIterator, inputIterator);
    template <class inputIterator>
    iterator insert(const_iterator, inputIterator, inputIterator);

    template <class... Args>
    iterator emplace(const_iterator, Args &&...);

    void push_back(const T &);
    void push_back(T &&);

    template <class... Args>
    void emplace_back(Args &&...);

    void erase(size_t);
    iterator erase(iterator);

    void pop_back();
    void clear() noexcept;
    int size() const noexcept;
    bool empty() const noexcept;
    void swap(gapvectorPimpl &);

    T &operator[](size_t);
    const T &operator[](size_t) const;

    T &at(size_t);
    const T &at(size_t) const;

    T &front();
    const T &front() const;

    T &back();
    const T &back() const;

    T *data() noexcept;
    const T *data() const noexcept;
};

} // namespace my
#endif
