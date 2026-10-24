#pragma once

#include "custom-types/shared/macros.hpp"

namespace CustomJSONData {

template <class T, class... TArgs>
concept CtorArgs = requires(T t, TArgs&&... args) {
  { T::New_ctor(std::forward<TArgs>(args)...) };
};

template <class T, class... TArgs>
requires(CtorArgs<std::remove_pointer_t<T>, TArgs...>)
T NewFast(TArgs&&... args) {
  return std::remove_pointer_t<T>::New_ctor(std::forward<TArgs>(args)...);
}

// custom-types now calls the native constructor directly.
#define DECLARE_FASTER_CTOR(name, ...) DECLARE_CTOR(name, __VA_ARGS__)
} // namespace CustomJSONData
