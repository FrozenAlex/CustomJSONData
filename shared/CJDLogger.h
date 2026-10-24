#pragma once
#include "beatsaber-hook/shared/members.hpp"
#include "beatsaber-hook/shared/listw.hpp"
#include "beatsaber-hook/shared/safeptr.hpp"
#include "beatsaber-hook/shared/callback.hpp"

#include "scotland2/shared/loader.hpp"

#include "paper2_scotland2/shared/logger.hpp"

using LogLevel = Paper::LogLevel;

namespace CustomJSONData {
static modloader::ModInfo const modInfo{"CustomJSONData", VERSION, 1};
}

class CJDLogger {
public:
  // Register file log in main.cpp
  static constexpr auto Logger =
      Paper::ConstLoggerContext("CustomJSONData"); // Paper::Logger::WithContext<"CustomJSONData", false>();
};

// Keep native exceptions from crossing the IL2CPP hook boundary.
#define PAPER_IL2CPP_CATCH_HANDLER(...) \
  try { __VA_ARGS__ } catch (std::exception const& exc) { \
    CJDLogger::Logger.error("Uncaught native exception: {}", exc.what()); \
    CJDLogger::Logger.Backtrace(100); \
    Paper::Logger::WaitForFlush(); \
    SAFE_ABORT(); \
  } catch (...) { \
    CJDLogger::Logger.error("Uncaught unknown native exception"); \
    CJDLogger::Logger.Backtrace(100); \
    Paper::Logger::WaitForFlush(); \
    SAFE_ABORT(); \
  }

template <auto Func, class T>
/// @brief Exposes a static wrapper method that forwards to the provided function pointer, wrapping it in
/// IL2CPP_CATCH_HANDLER.
struct PaperHookCatchWrapper;

template <auto Func, class R, class... TArgs> struct PaperHookCatchWrapper<Func, R (*)(TArgs...)> {
  static R wrapper(TArgs... args) {
    PAPER_IL2CPP_CATCH_HANDLER(return Func(args...);)
  }
};

// Hook layout follows beatsaber-hook 9, with the logging boundary retained.
#define MAKE_PAPER_HOOK_MATCH(name_, method, retval, ...) \
  struct BS_HOOK_HIDDEN hook_##name_ { \
    static constexpr auto cast_test = []<typename T>() { return requires { static_cast<T>(method); }; }; \
    using func_t = retval (*)(__VA_ARGS__); \
    using cast_t = ::i2c::detail::method_check<cast_test, func_t>::type; \
    static_assert(cast_test.operator()<cast_t>(), "Hook method signature does not match!"); \
    static_assert(::i2c::detail::match_hookable<static_cast<cast_t>(method)>); \
    static constexpr char const* name() { return #name_; } \
    static auto addr() { return ::i2c::metadata_getter<static_cast<cast_t>(method)>::method_info(); } \
    static func_t hook() { return &::PaperHookCatchWrapper<&hook_m_##name_, func_t>::wrapper; } \
    static func_t* trampoline() { return &name_; } \
    static inline flamingo::HookHandle install_handle; \
    static inline flamingo::HookPriority install_priority; \
    static inline func_t name_ = nullptr; \
    static retval hook_m_##name_(__VA_ARGS__); \
  }; \
  retval hook_##name_::hook_m_##name_(__VA_ARGS__)
