#ifndef GAPVECTOR_CONST_ITERATOR_HPP
#define GAPVECTOR_CONST_ITERATOR_HPP

#include "gapvector.hpp"
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <memory>

namespace my
{
template <typename T>
class gapvector;

template <typename T>
class gapvectorConstIterator : public boost::iterator_facade<gapvectorConstIterator<T>, T const, boost::random_access_traversal_tag>
{
  template <typename>
  friend class gapvector;

private:
  friend class boost::iterator_core_access;
  const gapvector<T> *gap_vector;
  size_t index;

  gapvectorConstIterator();
  gapvectorConstIterator(const gapvector<T> *, size_t);

public:
  void increment();
  void decrement();
  const T &dereference() const;
  bool equal(const gapvectorConstIterator<T> &) const;
  size_t distance_to(const gapvectorConstIterator<T> &) const;
  void advance(size_t);
};
#include "gapvector_const_iterator_implement.hpp"
};

#endif
