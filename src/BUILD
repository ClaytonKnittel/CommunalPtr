cc_library(
    name = "communal_ptr",
    hdrs = ["communal_ptr.h"],
    deps = [
    ],
)

cc_library(
    name = "communal_ptr_test_fixture",
    hdrs = ["communal_ptr_test_fixture.h"],
    deps = [
        ":communal_ptr",
        "@googletest//:gtest",
    ],
)

cc_test(
    name = "communal_ptr_test",
    size = "small",
    srcs = ["communal_ptr_test.cc"],
    deps = [
        ":communal_ptr",
        ":communal_ptr_test_fixture",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
