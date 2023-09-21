#include "delegatee_impl1.hpp"

#include "spdlog_helper.hpp"

namespace mpo22::misc_cpp_oop {

DelegateeImpl1::DelegateeImpl1() {
  SPDLOG_DEBUG("this={}", (void*)this);
}

DelegateeImpl1::~DelegateeImpl1() {
  SPDLOG_DEBUG("this={}", (void*)this);
};

Service::Output DelegateeImpl1::service(const Service::Input& input) {
  const Service::Output output = std::string(input.rbegin(), input.rend());
  SPDLOG_DEBUG("this={} Input={} -> Output={}", (void*)this, input, output);
  return output;
}

}  // namespace mpo22::misc_cpp_oop
