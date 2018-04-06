cmake_minimum_required(VERSION 3.9)
project(desktopApp)

set(CMAKE_CXX_STANDARD 14)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)

set(QT_PATH $ENV{HOME}/Qt/5.10.1/clang_64)

# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets REQUIRED PATHS QT_PATH)
find_package(Qt5Charts REQUIRED PATHS QT_PATH)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(${Qt5Widgets_INCLUDES} ${Qt5Charts_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIRS})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(desktopApp src/main.cpp src/MainWindow.cpp inc/MainWindow.h src/ControlButton.cpp inc/ControlButton.h src/AxisLabel.cpp inc/AxisLabel.h src/DescriptionLabel.cpp inc/DescriptionLabel.h src/ChartsWindow.cpp inc/ChartsWindow.h src/SettingsWindow.cpp inc/SettingsWindow.h src/ValueLabel.cpp inc/ValueLabel.h)

# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
target_link_libraries(desktopApp ${Qt5Widgets_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${Qt5Charts_LIBRARIES})