#ifndef GAPVECTOR_PIMPL_HPP
#define GAPVECTOR_PIMPL_HPP
#include "gapvector_impl/gapvector_impl.hpp"

namespace my
{
template <typename T>
class gapvector;

template <typename T>
class gapvectorPimpl
{

public:
  using iterator = gapvectorIterator<T>;
  using const_iterator = gapvectorConstIterator<T>;
  using reverse_iterator = gapvectorReverseIterator<T>;
  using const_reverse_iterator = gapvectorConstReverseIterator<T>;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;

  iterator end() noexcept;
  const_iterator end() const noexcept;

  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  reverse_iterator rbegin() noexcept;
  const_reverse_iterator rbegin() const noexcept;

  reverse_iterator rend() noexcept;
  const_reverse_iterator rend() const noexcept;

  const_reverse_iterator crbegin() const noexcept;
  const_reverse_iterator crend() const noexcept;

private:
  std::unique_ptr<gapvector<T>> gap_v;

public:
  gapvectorPimpl() : gap_v(std::make_unique<gapvector<T>>()) {}
  gapvectorPimpl(const gapvectorPimpl &another);
  gapvectorPimpl(gapvectorPimpl &&) = default;
  gapvectorPimpl(std::initializer_list<T>);
  ~gapvectorPimpl();

  gapvectorPimpl &operator=(const gapvectorPimpl &);
  gapvectorPimpl &operator=(gapvectorPimpl &&) = default;
  gapvectorPimpl &operator=(std::initializer_list<T>);

  template <class inputIterator>
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
  size_t size() const noexcept;
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
#include "gapvector_implement.hpp"

template <typename T>
using GapVector = gapvectorPimpl<T>;
} // namespace my
#endif
