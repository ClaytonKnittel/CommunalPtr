#pragma once

#include <vector>

namespace paige {

// TODO: Define type `CommunalPtr`, which takes a single template type argument
// and has the same interface as `std::shared_ptr`.

template <typename T>
class CommunalPtr {
 private:
  std::vector<CommunalPtr*>* references;
  T* value;

 public:
  // default constructor
  explicit CommunalPtr() {
    references->push_back(this);
  }

  // non default constructor
  explicit CommunalPtr(T* val) {
    value = val;
    references = new std::vector<CommunalPtr*>;
    references->push_back(this);
  }

  // copy constructor
  CommunalPtr(const CommunalPtr& ptr) : value(ptr.value) {
    references->push_back(this);
  }

  void swap(CommunalPtr& ptr1) {
    std::swap(ptr1.references, this->references);
    std::swap(ptr1.value, this->value);
  }

  // overload assignment opperator
  CommunalPtr& operator=(const CommunalPtr& ptr) {
    CommunalPtr(ptr).swap(*this);
    return *this;
  }

  // overload dereference opperator
  T& operator*() {
    return *value;
  }

  // overload arrow opperator
  T* operator->() {
    return value;
  }

  T* get() {
    return value;
  }

  bool empty() {
    return references->size() == 0;
  }

  int use_count() {
    return references->size();
  }

  // destructor
  ~CommunalPtr() {
    if (empty()) {
      delete value;
      delete references;
    }
  }
};

}  // namespace paige
