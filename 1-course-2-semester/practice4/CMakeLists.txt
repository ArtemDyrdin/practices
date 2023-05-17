cmake_minimum_required(VERSION 3.25)
project(practice4)

set(CMAKE_CXX_STANDARD 17)

add_executable(practice4 main.cpp inc/Device.h inc/DeviceType.h inc/Devices.h inc/Factory.h)
file(COPY Models.txt DESTINATION "/")