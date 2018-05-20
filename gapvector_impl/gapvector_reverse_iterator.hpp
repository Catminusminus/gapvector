#ifndef GAPVECTOR_REVERSE_ITERATOR_HPP
#define GAPVECTOR_REVERSE_ITERATOR_HPP

#include "gapvector_impl.hpp"
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <memory>

namespace my
{
template <typename T>
class gapvector;

template <typename T>
class gapvectorReverseIterator : public boost::iterator_facade<gapvectorReverseIterator<T>, T, boost::random_access_traversal_tag>
{
  template <typename>
  friend class gapvector;

private:
  friend class boost::iterator_core_access;
  gapvector<T> *gap_vector;
  size_t index;

  gapvectorReverseIterator();
  gapvectorReverseIterator(gapvector<T> *, size_t);

public:
  void increment();
  void decrement();
  T &dereference() const;
  bool equal(const gapvectorReverseIterator<T> &) const;
  size_t distance_to(const gapvectorReverseIterator<T> &) const;
  void advance(size_t);
};
#include "gapvector_reverse_iterator_implement.hpp"
}; // namespace my

#endif
