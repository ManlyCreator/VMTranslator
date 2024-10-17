# Specifies library source
add_library(Parser src/parser.c)
# Specifies header directory
target_include_directories(Parser PUBLIC include/)
