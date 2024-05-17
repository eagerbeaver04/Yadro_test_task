add_subdirectory(ReaderLib)
add_executable(main_executable  main.cpp )
target_link_libraries(main_executable  PRIVATE reader_lib)
