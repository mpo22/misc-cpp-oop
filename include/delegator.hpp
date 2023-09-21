#pragma once

#include <memory>

#include "delegatee.hpp"

namespace mpo22::misc_cpp_oop {

class Delegator : public Service {
 public:
  explicit Delegator(std::shared_ptr<Delegatee> delegatee);
  ~Delegator() override;

  auto service(const Service::Input& input) -> Service::Output override;

  virtual auto format(Formattable::FormatContext& ctx) const -> Formattable::FormatOut {
    return fmt::format_to(ctx.out(), FMT_STRING(R"({{"class": "{}", "delegatee": {}}})"), "Delegator", delegatee);
  }

 private:
  std::shared_ptr<Delegatee> delegatee;

  friend struct fmt::formatter<Delegator>;
};

}  // namespace mpo22::misc_cpp_oop

// https://fmt.dev/latest/api.html#formatting-user-defined-types
template <>
struct fmt::formatter<mpo22::misc_cpp_oop::Delegator> : mpo22::misc_cpp_oop::Formatter<mpo22::misc_cpp_oop::Delegator> {
};
