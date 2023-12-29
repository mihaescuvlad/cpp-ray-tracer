add_executable(basic_ray_tracer main.cpp)

target_link_libraries(
  basic_ray_tracer
  PRIVATE cpp_ray_tracer::cpp_ray_tracer_options
          cpp_ray_tracer::cpp_ray_tracer_warnings
          cpp_ray_tracer_CApp)

target_link_system_libraries(
  basic_ray_tracer
  PRIVATE
          CLI11::CLI11
          fmt::fmt)

target_include_directories(basic_ray_tracer PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")
