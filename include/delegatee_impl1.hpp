#pragma once

#include <iostream>
#include <string>

#include "delegatee.hpp"

namespace mpo22::misc_cpp_oop {

class DelegateeImpl1 : public Delegatee {
 public:
  DelegateeImpl1();
  ~DelegateeImpl1() override;

  auto service(const Service::Input& input) -> Service::Output override;

  auto format(Formattable::FormatContext& ctx) const -> Formattable::FormatOut override {
    return fmt::format_to(ctx.out(), FMT_STRING(R"({{"class": "{}"}})"), "DelegateeImpl1");
  }
};

}  // namespace mpo22::misc_cpp_oop

// https://fmt.dev/dev/api.html#formatting-user-defined-types
template <>
struct fmt::formatter<mpo22::misc_cpp_oop::DelegateeImpl1>
    : mpo22::misc_cpp_oop::Formatter<mpo22::misc_cpp_oop::DelegateeImpl1> {};
