#include "delegator.hpp"

#include "spdlog_helper.hpp"

namespace mpo22::misc_cpp_oop {

Delegator::Delegator(std::shared_ptr<Delegatee> delegateeSharedPtr) : delegatee(delegateeSharedPtr) {
  SPDLOG_DEBUG("this={} Delegatee={}", (void*)this, (void*)delegatee.get());
}

Delegator::~Delegator() {
  SPDLOG_DEBUG("this={}", (void*)this);
};

Service::Output Delegator::service(const Service::Input& input) {
  SPDLOG_DEBUG("this={} Input={}", (void*)this, input);
  auto output = delegatee->service(input);
  SPDLOG_DEBUG("this={} Input={} -> Output={}", (void*)this, input, output);
  return output;
}

}  // namespace mpo22::misc_cpp_oop
