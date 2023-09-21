#include <catch2/catch_all.hpp>

// see https://github.com/rollbear/trompeloeil/blob/main/docs/CookBook.md#adapt_catch
#include <catch2/trompeloeil.hpp>

#include <memory>

#include "delegatee_impl1.hpp"
#include "delegator.hpp"
#include "spdlog_helper.hpp"

namespace mpo22::misc_cpp_oop::delegator_test {

SCENARIO("DelegatorTest1") {
  GIVEN("a Delegatee and a delegator") {
    auto delegatee = std::make_shared<DelegateeImpl1>();
    Delegator delegator(delegatee);
    SPDLOG_INFO("delegator={}", delegator);

    WHEN("the delegator is called") {
      auto output = delegator.service("42");

      THEN("the Delegatee is called") {
        CHECK(output == "24");
      }
    }
  }
}

class DelegateeMock : public Delegatee {
 public:
  // Service::Output Service(const Service::Input& Input) override = 0;
  MAKE_MOCK1(service, Service::Output(const Service::Input&), override);
};

SCENARIO("DelegatorTest2") {
  GIVEN("a MOCKED Delegatee and a delegator") {
    auto delegatee = std::make_shared<DelegateeMock>();
    ALLOW_CALL(*delegatee, service("42")).RETURN("24");

    Delegator delegator(delegatee);
    SPDLOG_INFO("delegator={}", delegator);

    WHEN("the delegator is called") {
      auto output = delegator.service("42");

      THEN("the MOCKED Delegatee is called") {
        CHECK(output == "24");
      }
    }
  }
}

}  // namespace mpo22::misc_cpp_oop::delegator_test
