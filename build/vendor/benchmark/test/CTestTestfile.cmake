# CMake generated Testfile for 
# Source directory: /home/julesy/workspace/moo-cpp/vendor/benchmark/test
# Build directory: /home/julesy/workspace/moo-cpp/build/vendor/benchmark/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(benchmark "benchmark_test" "--benchmark_min_time=0.01")
add_test(filter_simple "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=Foo" "3")
add_test(filter_suffix "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=BM_.*" "4")
add_test(filter_regex_all "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=.*" "5")
add_test(filter_regex_blank "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=" "5")
add_test(filter_regex_none "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=monkey" "0")
add_test(filter_regex_wildcard "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=.*Foo.*" "3")
add_test(filter_regex_begin "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=^BM_.*" "4")
add_test(filter_regex_begin2 "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=^N" "1")
add_test(filter_regex_end "filter_test" "--benchmark_min_time=0.01" "--benchmark_filter=.*Ba$" "1")
add_test(options_benchmarks "options_test" "--benchmark_min_time=0.01")
add_test(basic_benchmark "basic_test" "--benchmark_min_time=0.01")
add_test(fixture_test "fixture_test" "--benchmark_min_time=0.01")
add_test(cxx03 "cxx03_test" "--benchmark_min_time=0.01")
