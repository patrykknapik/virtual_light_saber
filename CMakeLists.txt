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
find_package(Qt5Widgets REQUIRED PATHS ${QT_PATH})
find_package(Qt5Charts REQUIRED PATHS ${QT_PATH})
find_package(Qt53DCore REQUIRED PATHS ${QT_PATH})
find_package(Qt53DInput REQUIRED PATHS ${QT_PATH})
find_package(Qt53DRender REQUIRED PATHS ${QT_PATH})
find_package(Qt53DExtras REQUIRED PATHS ${QT_PATH})
find_package(Qt5SerialPort REQUIRED PATHS ${QT_PATH})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(desktopApp src/main.cpp src/MainWindow.cpp inc/MainWindow.h src/ControlButton.cpp inc/ControlButton.h src/AxisLabel.cpp inc/AxisLabel.h src/DescriptionLabel.cpp inc/DescriptionLabel.h src/ChartsWindow.cpp inc/ChartsWindow.h src/SettingsWindow.cpp inc/SettingsWindow.h src/ValueLabel.cpp inc/ValueLabel.h src/SerialReader.cpp inc/SerialReader.h inc/DataTypes.h src/Calculator.cpp inc/Calculator.h)

# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
target_link_libraries(desktopApp Qt5::Widgets Qt5::Charts Qt5::3DCore Qt5::3DExtras Qt5::3DRender Qt5::3DInput Qt5::SerialPort)