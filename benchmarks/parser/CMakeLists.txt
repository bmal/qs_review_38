# Mechanism: a benchmark executable registered in one call, named after the module it measures.
# Every .cpp here becomes parser_benchmarks, linked to qs_review_38::parser and the bench support main.
project_add_benchmark(MODULE parser)
