// Mechanism: a vcpkg dependency found with find_package and linked through the module helper.
// Formats the generated version constants with fmt into the banner every app prints at startup.
#include "core/build_info.hpp"

#include <fmt/format.h>
#include <qs_review_38/version.hpp>

#include <string>

namespace qs_review_38::core {

std::string version_banner() {
    return fmt::format("qs_review_38 {} ({}{})", version_string, git_commit,
                       git_dirty ? "-dirty" : "");
}

} // namespace qs_review_38::core
