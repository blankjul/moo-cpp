# CMake generated Testfile for 
# Source directory: /home/julesy/Workspace/moo-cpp/vendor/benchmark/test
# Build directory: /home/julesy/Workspace/moo-cpp/build/vendor/benchmark/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(benchmark "benchmark_test" "--benchmark_min_time=0.01")
ADD_TEST(filter_simple "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=Foo" "3")
ADD_TEST(filter_suffix "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=BM_.*" "4")
ADD_TEST(filter_regex_all "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=.*" "5")
ADD_TEST(filter_regex_blank "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=" "5")
ADD_TEST(filter_regex_none "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=monkey" "0")
ADD_TEST(filter_regex_wildcard "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=.*Foo.*" "3")
ADD_TEST(filter_regex_begin "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=^BM_.*" "4")
ADD_TEST(filter_regex_begin2 "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=^N" "1")
ADD_TEST(filter_regex_end "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=.*Ba$" "1")
ADD_TEST(options_benchmarks "options_test" "--benchmark_min_time=0.01")
ADD_TEST(basic_benchmark "basic_test" "--benchmark_min_time=0.01")
ADD_TEST(fixture_test "fixture_test" "--benchmark_min_time=0.01")
ADD_TEST(cxx03 "cxx03_test" "--benchmark_min_time=0.01")
