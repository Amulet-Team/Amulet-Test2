#ifndef AMULET_TEST2_DLLX
    #ifdef _WIN32
        #ifdef ExportAmuletTest2
            #define AMULET_TEST2_DLLX __declspec(dllexport)
        #else
            #define AMULET_TEST2_DLLX __declspec(dllimport)
        #endif
    #else
        #define AMULET_TEST2_DLLX
    #endif
#endif
