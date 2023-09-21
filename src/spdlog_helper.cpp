#include "spdlog_helper.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <cassert>
#include <regex>

namespace mpo22::misc_cpp_oop {

void spdlogSetup() {
  auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  stdout_sink->set_level(spdlog::level::debug);

  auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("test.log", true);
  file_sink->set_level(spdlog::level::trace);

  std::vector<spdlog::sink_ptr> sinks{stdout_sink, file_sink};

  auto logger = std::make_shared<spdlog::logger>("root", spdlog::sinks_init_list({stdout_sink, file_sink}));
  logger->set_level(spdlog::level::debug);
  logger->set_pattern("[%s:%#] [%!] [%l] %v");

  spdlog::set_default_logger(logger);

  SPDLOG_INFO("logging initialized");
}

const char* spdlogPrettyFunctionToFullyQualifiedFunction(const char* prettyFunction) {
  // prettyFunction: expansion de __PRETTY_FUNCTION__ fournie a la compilation par le compilo
  // ne changera pas entre appels => peut servir de clef
  // TODO reusiner
  static std::map<const char*, std::string> map;
  if (map.contains(prettyFunction)) {
    return map.at(prettyFunction).c_str();
  }

  // TODO profiler et optimiser
  static std::regex regex(R"(((?:(?:\w+::)*(?:\w+)(?:<[\w, ]+>){0,1}::){0,1}(?:~?\w+))[(])");
  if (prettyFunction) {
    std::string prettyFunctionString(prettyFunction);
    std::smatch smatch;
    if (std::regex_search(prettyFunctionString, smatch, regex)) {
      assert(smatch.size() > 1);
      map.emplace(prettyFunction, smatch[1].str());
      return map.at(prettyFunction).c_str();
    } else {
      return {prettyFunction};
    }
  } else {
    return {};
  }
}

}  // namespace mpo22::misc_cpp_oop
