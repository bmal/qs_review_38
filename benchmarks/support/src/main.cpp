// Mechanism: the one Google Benchmark main every benchmark executable shares.
// It records the version and commit in the JSON context, so every result names its build.
#include <benchmark/benchmark.h>

#include "core/build_info.hpp"

// NOLINTNEXTLINE(bugprone-exception-escape): an escaping exception should terminate and dump core.
int main(int argc, char** argv) {
    benchmark::AddCustomContext("qs_review_38_version", qs_review_38::core::version_banner());
    benchmark::Initialize(&argc, argv);
    if (benchmark::ReportUnrecognizedArguments(argc, argv)) {
        return 1;
    }
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}
