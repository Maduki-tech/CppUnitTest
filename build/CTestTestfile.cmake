# CMake generated Testfile for 
# Source directory: /Users/davidschluter/personal/C++/UnitExamples
# Build directory: /Users/davidschluter/personal/C++/UnitExamples/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(example_test "/Users/davidschluter/personal/C++/UnitExamples/build/test_runner")
set_tests_properties(example_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/davidschluter/personal/C++/UnitExamples/CMakeLists.txt;44;add_test;/Users/davidschluter/personal/C++/UnitExamples/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
