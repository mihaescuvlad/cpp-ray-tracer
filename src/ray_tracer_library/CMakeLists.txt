include(GenerateExportHeader)


add_library(cpp_ray_tracer_CApp CApp.cpp)


add_library(cpp_ray_tracer::CApp ALIAS cpp_ray_tracer_CApp)

find_package(SDL2 REQUIRED)
target_link_libraries(cpp_ray_tracer_CApp PRIVATE cpp_ray_tracer_options cpp_ray_tracer_warnings SDL2::SDL2)

target_include_directories(cpp_ray_tracer_CApp  ${WARNING_GUARD} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

target_compile_features(cpp_ray_tracer_CApp  PUBLIC cxx_std_20)

set_target_properties(
  cpp_ray_tracer_CApp 
  PROPERTIES VERSION ${PROJECT_VERSION}
             CXX_VISIBILITY_PRESET hidden
             VISIBILITY_INLINES_HIDDEN YES)

generate_export_header(cpp_ray_tracer_CApp  EXPORT_FILE_NAME ${PROJECT_BINARY_DIR}/include/cpp_ray_tracer/CApp_export.hpp)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(cpp_ray_tracer_CApp PUBLIC SAMPLE_LIBRARY_STATIC_DEFINE)
endif()
