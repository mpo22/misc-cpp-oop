#pragma once

#include <string>

namespace mpo22::misc_cpp_oop {

class Service {
 public:
  virtual ~Service() = default;

  using Input = std::string;
  using Output = std::string;
  virtual auto service(const Input& input) -> Output = 0;
};

}  // namespace mpo22::misc_cpp_oop
