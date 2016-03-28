set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(inter)
add_subdirectory(lexer)
# add_subdirectory(parser)
add_subdirectory(symbols)

add_library(CompilerExCpp)
target_link_libraries(CompilerExCpp
    CECPPinter
    CECPPlexer
    # CECPPparser
    CECPPsymbols
)

add_executable(cdemo main.cpp)
target_link_libraries(cdemo CompilerExCpp)