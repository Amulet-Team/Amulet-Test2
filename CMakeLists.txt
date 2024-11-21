cmake_minimum_required(VERSION 3.13)

project(amulet_test2 LANGUAGES CXX)
set(SRC_INSTALL_DIR "." CACHE PATH "The path to the src directory to install into.")

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif(NOT CMAKE_CXX_STANDARD)

add_definitions(-DPYBIND11_DETAILED_ERROR_MESSAGES)
if (WIN32)
	# set windows 7 as the minimum version
	add_definitions(-D_WIN32_WINNT=0x0601)
elseif(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15")
endif()

# Add pybind11 fallback
if (NOT TARGET pybind11::headers)
    add_subdirectory(submodules/pybind11)
endif()

if (NOT TARGET amulet_test1)
    add_subdirectory(submodules/Amulet-Test1)
endif()

add_library(amulet_test2 SHARED)
target_compile_definitions(amulet_test2 PRIVATE ExportAmuletTest2)
target_include_directories(amulet_test2 PUBLIC src)
target_sources(amulet_test2 PRIVATE src/amulet_test2/test2.cpp)
target_link_libraries( amulet_test2 PRIVATE amulet_test1 )

pybind11_add_module(_amulet_test2 src/amulet_test2/__init_amulet_test2.cpp)
target_link_libraries( _amulet_test2 PRIVATE amulet_test1 )
target_link_libraries( _amulet_test2 PRIVATE amulet_test2 )

install(TARGETS amulet_test2 DESTINATION "${SRC_INSTALL_DIR}/amulet_test2/bin")
install(TARGETS _amulet_test2 DESTINATION "${SRC_INSTALL_DIR}/amulet_test2")
