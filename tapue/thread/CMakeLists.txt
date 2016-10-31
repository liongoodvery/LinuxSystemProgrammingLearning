set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(thread_id thread_id.c)
add_executable(thread_exit thread_exit.c)
add_executable(thread_exit_stack thread_exit_stack.c)
add_executable(thread_exit_heap thread_exit_heap.c)
add_executable(thread_cleanup thread_cleanup)

TARGET_LINK_LIBRARIES(thread_cleanup pthread)
TARGET_LINK_LIBRARIES(thread_id pthread)
TARGET_LINK_LIBRARIES(thread_exit pthread)
TARGET_LINK_LIBRARIES(thread_exit_stack pthread)
TARGET_LINK_LIBRARIES(thread_exit_heap pthread)
