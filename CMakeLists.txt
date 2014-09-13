PROJECT(binSpector)

IF( APPLE )
	SET( PROGNAME binSpector )
	SET( MACOSX_BUNDLE_ICON_FILE binSpector.icns )
	SET( MACOSX_BUNDLE_SHORT_VERSION_STRING 0.1-alpha )
    SET( MACOSX_BUNDLE_VERSION 0.1-alpha )
    SET( MACOSX_BUNDLE_LONG_VERSION_STRING Version 0.1-alpha )
ELSE( APPLE )
	SET( PROGNAME binSpector )
ENDIF( APPLE )

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)
SET( CMAKE_COLOR_MAKEFILE ON )
SET( CMAKE_VERBOSE_MAKEFILE ON )
SET( CMAKE_INCLUDE_CURRENT_DIR TRUE )

##################
#### Qt Stuff ####
##################

# Instruct CMake to run moc automatically when needed.
SET(CMAKE_AUTOMOC ON)
# Find includes in corresponding build directories
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
# Find the QtWidgets library
FIND_PACKAGE(Qt5Core REQUIRED)

##################

INCLUDE_DIRECTORIES("include")

ADD_SUBDIRECTORY(docs)
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(tools/binSpector)