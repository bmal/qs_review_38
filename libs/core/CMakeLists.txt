# Mechanism: a compiled module registered in one call, plus the configure-time version header.
# Sources under src/ make qs_review_38_core a real library; project_add_version_header adds qs_review_38/version.hpp.
project_add_module(NAME core PRIVATE_DEPS fmt::fmt qs_review_38::parser)
project_add_version_header(core)
