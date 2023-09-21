#include <catch2/catch_all.hpp>

#include "spdlog_helper.hpp"

namespace mpo22::misc_cpp_oop::test {

class testRunListener : public Catch::EventListenerBase {
 public:
  using Catch::EventListenerBase::EventListenerBase;

  void testRunStarting(Catch::TestRunInfo const&) override {
    spdlogSetup();
  }
};

CATCH_REGISTER_LISTENER(testRunListener)

}  // namespace mpo22::misc_cpp_oop::test
