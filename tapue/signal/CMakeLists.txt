
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(.)

add_executable(sleep1 sleep1.c )
add_executable(sleep2 sleep2.c)
add_executable(sigset sigset.c)
add_executable(sigpend sigpend.c)
