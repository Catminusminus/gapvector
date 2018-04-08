#ifndef GAPVECTOR_ITERATOR_HPP
#define GAPVECTOR_ITERATOR_HPP

#include "gapvector.hpp"
#include <iterator>
#include <memory>

namespace my
{
template <typename T>
class gapvector;

template <typename T>
class gapvectorIterator : public std::iterator<std::random_access_iterator_tag, T>
{
  template <typename>
  friend class gapvector;

private:
  size_t index;
  std::shared_ptr<gapvector<T>> ptr_gap_vector;
  gapvectorIterator();
  gapvectorIterator(std::shared_ptr<gapvector<T>>, int);

public:
  gapvectorIterator(const gapvectorIterator &);
};
#include "gapvector_iterator_implement.hpp"
};

#endif