#pragma once

#include "fmt_helper.hpp"
#include "service.hpp"

namespace mpo22::misc_cpp_oop {

class Delegatee : public Service {
 public:
  ~Delegatee() override = default;

  virtual auto format(Formattable::FormatContext& ctx) const -> Formattable::FormatOut {
    return fmt::format_to(ctx.out(), FMT_STRING(R"({{"class": "{}"}})"), "Delegatee");
  }

  auto service(const Service::Input& input) -> Service::Output override = 0;
};

}  // namespace mpo22::misc_cpp_oop

// https://fmt.dev/dev/api.html#formatting-user-defined-types
template <>
struct fmt::formatter<mpo22::misc_cpp_oop::Delegatee> : mpo22::misc_cpp_oop::Formatter<mpo22::misc_cpp_oop::Delegatee> {
};
