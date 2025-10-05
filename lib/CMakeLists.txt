file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(utils STATIC ${LIB_SOURCES})
target_include_directories(utils PUBLIC include)
target_link_libraries(utils PUBLIC fmt::fmt)

# Optional alias
add_library(concepts::utils ALIAS utils)
