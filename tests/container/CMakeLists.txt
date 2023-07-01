enable_testing()

add_executable(test_trie test_trie.cc)

target_include_directories(test_trie PUBLIC
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(test_trie PUBLIC
    GTest::gtest_main
    infra-lib-container
)

include(GoogleTest)
gtest_discover_tests(test_trie)
