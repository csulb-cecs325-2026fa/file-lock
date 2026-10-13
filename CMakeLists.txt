cmake_minimum_required(VERSION 3.21)

project("FileLock" LANGUAGES CXX)

option(BUILD_TESTING "Build the unit tests" ON)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Release,MinSizeRel>:ProgramDatabase>>")
endif()

add_library(filelock
  src/filelock.cpp
  src/lockablefile.cpp
)

target_include_directories(filelock PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(filelock PUBLIC cxx_std_20)

add_executable(filelock_demo src/main.cpp)
target_link_libraries(filelock_demo PRIVATE filelock)

include(CTest)
if (BUILD_TESTING)
  add_subdirectory("tests")
endif()
