if (NOT TARGET amulet_test2)
    message(STATUS "Finding amulet_test2")

    set(amulet_test2_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/..")
    find_library(amulet_test2_LIBRARY NAMES amulet_test2 PATHS "${CMAKE_CURRENT_LIST_DIR}/bin")
    message(STATUS "amulet_test2_LIBRARY: ${amulet_test2_LIBRARY}")

    add_library(amulet_test2 SHARED IMPORTED)
    set_target_properties(amulet_test2 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${amulet_test2_INCLUDE_DIR}"
        IMPORTED_IMPLIB "${amulet_test2_LIBRARY}"
    )
endif()
