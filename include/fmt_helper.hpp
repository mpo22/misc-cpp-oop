#pragma once

#include <fmt/core.h>
#include <fmt/format.h>
#include <map>
#include <memory>
#include <optional>
#include <vector>

// see https://fmt.dev/latest/api.html#formatting-user-defined-types

namespace mpo22::misc_cpp_oop {

struct Formattable {
  using FormatOut = fmt::detail::buffer_appender<char>;
  using FormatContext = fmt::basic_format_context<fmt::appender, char>;

  using Format = FormatOut(FormatContext& ctx) const;
};

template <typename F>
struct Formatter {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(F const& formattable, FormatContext& ctx) const -> decltype(ctx.out()) {
    return formattable.format(ctx);
  }
};

}  // namespace mpo22::misc_cpp_oop

#if 1
// https://github.com/fmtlib/fmt/issues/1367
template <typename T>
struct fmt::formatter<std::optional<T>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(const std::optional<T>& optional, FormatContext& ctx) {
    if (optional) {
      fmt::formatter<T>::format(*optional, ctx);
      return ctx.out();
    } else {
      return fmt::format_to(ctx.out(), FMT_STRING(R"(null)"));
    }
  }
};
#endif

#if 1
// specialization of https://github.com/fmtlib/fmt/issues/1367
template <>
struct fmt::formatter<std::optional<std::string>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(const std::optional<std::string>& optional, FormatContext& ctx) {
    if (optional) {
      return fmt::format_to(ctx.out(), FMT_STRING(R"("{}")"), *optional);
    } else {
      return fmt::format_to(ctx.out(), FMT_STRING(R"(null)"));
    }
  }
};
#endif

#if 1
// adaptation of https://github.com/fmtlib/fmt/issues/1367
template <typename T>
struct fmt::formatter<std::unique_ptr<T>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(const std::unique_ptr<T>& unique_ptr, FormatContext& ctx) {
    if (unique_ptr) {
      return fmt::format_to(ctx.out(), R"({})", *unique_ptr);
      return ctx.out();
    } else {
      return fmt::format_to(ctx.out(), R"(null)");
    }
  }
};
#endif

#if 1
// adaptation of https://github.com/fmtlib/fmt/issues/1367
template <>
struct fmt::formatter<std::unique_ptr<std::string>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(const std::unique_ptr<std::string>& unique_ptr, FormatContext& ctx) {
    if (unique_ptr) {
      return fmt::format_to(ctx.out(), R"("{}")", *unique_ptr);
    } else {
      return fmt::format_to(ctx.out(), R"(null)");
    }
  }
};
#endif

#if 1
// adaptation of https://github.com/fmtlib/fmt/issues/1367
template <typename T>
struct fmt::formatter<std::shared_ptr<T>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(const std::shared_ptr<T>& shared_ptr, FormatContext& ctx) {
    if (shared_ptr) {
      return fmt::format_to(ctx.out(), R"({})", *shared_ptr);
    } else {
      return fmt::format_to(ctx.out(), R"(null)");
    }
  }
};
#endif

#if 1
// adaptation of https://github.com/fmtlib/fmt/issues/1367
template <>
struct fmt::formatter<std::shared_ptr<std::string>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(const std::shared_ptr<std::string>& shared_ptr, FormatContext& ctx) {
    if (shared_ptr) {
      return fmt::format_to(ctx.out(), R"("{}")", *shared_ptr);
    } else {
      return fmt::format_to(ctx.out(), R"(null)");
    }
  }
};
#endif

#if 1
template <typename T>
struct fmt::formatter<std::vector<T>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(std::vector<T> const& vector, FormatContext& ctx) const -> decltype(ctx.out()) {
    auto out = ctx.out();
    fmt::format_to(out, R"([)");
    for (auto it = vector.begin(); it != vector.end(); it++) {
      fmt::format_to(out, R"({})", *it);
      if (std::next(it) != vector.end()) {
        fmt::format_to(out, R"(, )");
      }
    }
    fmt::format_to(out, R"(])");
    return out;
  }
};
#endif

#if 1
template <>
struct fmt::formatter<std::vector<std::string>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(std::vector<std::string> const& vector, FormatContext& ctx) const -> decltype(ctx.out()) {
    auto out = ctx.out();
    fmt::format_to(out, R"([)");
    for (auto it = vector.begin(); it != vector.end(); it++) {
      fmt::format_to(out, R"("{}")", *it);
      if (std::next(it) != vector.end()) {
        fmt::format_to(out, R"(, )");
      }
    }
    fmt::format_to(out, R"(])");
    return out;
  }
};
#endif

#if 1
template <typename T>
struct fmt::formatter<std::map<std::string, T>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(std::map<std::string, T> const& map, FormatContext& ctx) const -> decltype(ctx.out()) {
    auto out = ctx.out();
    fmt::format_to(out, "{{");
    for (auto it = map.begin(); it != map.end(); it++) {
      fmt::format_to(out, R"("{}": )", it->first);
      fmt::format_to(out, R"({})", it->second);
      if (std::next(it) != map.end()) {
        fmt::format_to(out, R"(, )");
      }
    }
    fmt::format_to(out, "}}");
    return ctx.out();
  }
};
#endif

#if 1
template <>
struct fmt::formatter<std::map<std::string, std::string>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  };

  template <typename FormatContext>
  auto format(std::map<std::string, std::string> const& map, FormatContext& ctx) const -> decltype(ctx.out()) {
    auto out = ctx.out();
    fmt::format_to(out, "{{");
    for (auto it = map.begin(); it != map.end(); it++) {
      fmt::format_to(out, R"("{}": )", it->first);
      fmt::format_to(out, R"("{}")", it->second);
      if (std::next(it) != map.end()) {
        fmt::format_to(out, R"(, )");
      }
    }
    fmt::format_to(out, "}}");
    return ctx.out();
  }
};
#endif
