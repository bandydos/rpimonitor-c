cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(rpimon)

add_executable(rpimon main.c)

target_link_libraries(rpimon PJ_RPI)
target_link_libraries(rpimon mariadb)

install(FILES mysql.h DESTINATION include)
