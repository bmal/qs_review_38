# Mechanism: an app is a directory under apps/ with one project_add_app call naming its modules.
# The executable lands in build/<preset>/bin/qs_review_38_cli.
project_add_app(NAME qs_review_38_cli DEPS qs_review_38::core qs_review_38::parser)
