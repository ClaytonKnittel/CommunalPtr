#pragma once

#include <vector>

namespace paige {

// TODO: Define type `CommunalPtr`, which takes a single template type argument
// and has the same interface as `std::shared_ptr`.

template <typename T>
class CommunalPtr {
 private:
  std::vector<CommunalPtr*>* references_;
  T* value_;

 public:
  // default constructor
  explicit CommunalPtr() : references_(nullptr), value_(nullptr) {}

  // non default constructor
  explicit CommunalPtr(T* val) {
    value_ = new T;
    value_ = val;
    references_ = new std::vector<CommunalPtr*>;
    references_->push_back(this);
  }

  // copy constructor
  CommunalPtr(const CommunalPtr& ptr)
      : references_(ptr.references_), value_(ptr.value_) {
    if (value_ != nullptr) {
      references_->push_back(this);
    }
  }

  void swap(CommunalPtr& ptr1) {
    std::swap(ptr1.references_, this->references_);
    std::swap(ptr1.value_, this->value_);
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
    return references_ == nullptr;
    // return references_->size() == 0;
  }

  int use_count() {
    if (references_ == nullptr) {
      return 0;
    }
    return references_->size();
  }

  // destructor
  ~CommunalPtr() {
    if (empty()) {
      delete value_;
      delete references_;
    }
  }
};

}  // namespace paige
