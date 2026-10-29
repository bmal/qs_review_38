// Mechanism: which sanitizer instruments this build, detected the same way on GCC and Clang.
// QS_REVIEW_38_SKIP_UNDER_SANITIZER skips a test that one sanitizer cannot run, and says why.
#pragma once

#include <gtest/gtest.h>

// GCC and Clang 18+ define __SANITIZE_*__; __has_feature covers older Clang and MemorySanitizer.
#ifdef __SANITIZE_ADDRESS__
#define QS_REVIEW_38_UNDER_ASAN 1
#endif
#ifdef __SANITIZE_THREAD__
#define QS_REVIEW_38_UNDER_TSAN 1
#endif
#ifdef __has_feature
#if __has_feature(address_sanitizer) && !defined(QS_REVIEW_38_UNDER_ASAN)
#define QS_REVIEW_38_UNDER_ASAN 1
#endif
#if __has_feature(thread_sanitizer) && !defined(QS_REVIEW_38_UNDER_TSAN)
#define QS_REVIEW_38_UNDER_TSAN 1
#endif
#if __has_feature(memory_sanitizer)
#define QS_REVIEW_38_UNDER_MSAN 1
#endif
#endif

#ifndef QS_REVIEW_38_UNDER_ASAN
#define QS_REVIEW_38_UNDER_ASAN 0
#endif
#ifndef QS_REVIEW_38_UNDER_TSAN
#define QS_REVIEW_38_UNDER_TSAN 0
#endif
#ifndef QS_REVIEW_38_UNDER_MSAN
#define QS_REVIEW_38_UNDER_MSAN 0
#endif

// Skips the rest of the test under ASAN, TSAN, or MSAN; any other name fails to compile.
//   QS_REVIEW_38_SKIP_UNDER_SANITIZER(TSAN, "death tests fork a process that already has threads");
#define QS_REVIEW_38_SKIP_UNDER_SANITIZER(sanitizer, reason)                                       \
    if (QS_REVIEW_38_UNDER_##sanitizer) {                                                          \
        GTEST_SKIP() << #sanitizer ": " << (reason);                                               \
    }                                                                                              \
    static_assert(true, "the caller's semicolon ends this")
