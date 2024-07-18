#pragma once

#include <iostream>
#include <vector>

namespace paige {

// TODO: Define type `CommunalPtr`, which takes a single template type argument
// and has the same interface as `std::shared_ptr`.

template <typename T>
class CommunalPtr {
 private:
  T* value_;
  int* references_count_;

 public:
  // default constructor
  explicit CommunalPtr() : references_count_(nullptr), value_(nullptr) {}

  // non default constructor
  explicit CommunalPtr(T* val) : value_(val) {
    references_count_ = new int(1);
    std::cerr << "push new ptr " << this << std::endl;
  }

  // copy constructor
  CommunalPtr(const CommunalPtr& ptr)
      : value_(ptr.value_), references_count_(ptr.references_count_) {
    if (value_ != nullptr) {
      *references_count_ += 1;
      std::cerr << "push copied ptr " << this << std::endl;
    }
  }

  void swap(CommunalPtr& ptr1) {
    std::swap(ptr1.value_, this->value_);
    std::swap(ptr1.references_count_, this->references_count_);
  }

  // overload assignment opperator
  CommunalPtr& operator=(const CommunalPtr& ptr) {
    CommunalPtr(ptr).swap(*this);
    return *this;
  }

  // overload dereference opperator
  T& operator*() {
    return *value_;
  }

  // overload arrow opperator
  T* operator->() {
    return value_;
  }

  T* get() {
    return value_;
  }

  bool empty() {
    return *references_count_ == 0;
  }

  int use_count() {
    if (references_count_ == nullptr) {
      return 0;
    }
    return *references_count_;
  }

  // destructor
  ~CommunalPtr() {
    // if there are references, delete the this copy
    if ((references_count_ != nullptr) && (*references_count_ != 0)) {
      std::cerr << "deleting ptr " << this << std::endl;
      *references_count_ -= 1;
      // if the last reference of the ptr was removed, delete the ptr as a whole
      if (empty()) {
        delete value_;
        delete references_count_;
      }
    }
  }
};

}  // namespace paige
