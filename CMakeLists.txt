PROJECT(binSpector)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

##################
#### Qt Stuff ####
##################
#
# Instruct CMake to run moc automatically when needed.
#SET(CMAKE_AUTOMOC ON)
# Find includes in corresponding build directories
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
# Find the QtWidgets library
FIND_PACKAGE(Qt5Core REQUIRED)
#
##################

INCLUDE_DIRECTORIES("include")

ADD_SUBDIRECTORY(docs)
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(tools/binSpector)