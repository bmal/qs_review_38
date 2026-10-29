// Mechanism: a definition kept out of the header, so qs_review_38_core compiles to a library.
// SystemClock reads std::chrono::steady_clock, which never jumps backwards.
#include "core/clock.hpp"

#include <chrono>

namespace qs_review_38::core {

std::chrono::nanoseconds SystemClock::now() noexcept {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now().time_since_epoch());
}

} // namespace qs_review_38::core
