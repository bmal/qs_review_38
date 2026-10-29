# Mechanism: one support library that every benchmark executable links in place of benchmark_main.
# An OBJECT library, so its main always reaches the link of the executable.
add_library(qs_review_38_bench_support OBJECT src/cache_flush.cpp src/main.cpp src/percentiles.cpp)
target_include_directories(qs_review_38_bench_support PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(
  qs_review_38_bench_support
  PUBLIC benchmark::benchmark
  PRIVATE qs_review_38::core qs_review_38_warnings qs_review_38_options
)
