#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#define SPDLOG_FUNCTION mpo22::misc_cpp_oop::spdlogPrettyFunctionToFullyQualifiedFunction(__PRETTY_FUNCTION__)
#include <spdlog/spdlog.h>

namespace mpo22::misc_cpp_oop {

void spdlogSetup();
const char* spdlogPrettyFunctionToFullyQualifiedFunction(const char* prettyFunction);

}  // namespace mpo22::misc_cpp_oop
