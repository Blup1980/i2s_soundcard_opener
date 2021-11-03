cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(CardOpener VERSION 1.0)

add_executable(CardOpener main.cpp)

find_package(ALSA REQUIRED)                                    
if (ALSA_FOUND)                                                
    include_directories(${ALSA_INCLUDE_DIRS})                  
    target_link_libraries(CardOpener ${ALSA_LIBRARIES})      
endif(ALSA_FOUND)  

configure_file(Config.h.in Config.h)
target_include_directories(CardOpener PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
