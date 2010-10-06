project(MapViewer)

find_package(Qt4 COMPONENTS QtCore QtGui QtNetwork REQUIRED)
include(${QT_USE_FILE})

set(MapViewer_SRCS
	main.cpp
	mainwindow.cpp)

set(MapViewer_HDRS
	mainwindow.h)

set(MapViewer_UI
	ui/mainwindow.ui)

QT4_WRAP_UI(MapViewerUI ${MapViewer_UI})
QT4_AUTOMOC(${MapViewer_SRCS})

add_executable(mapviewer ${MapViewer_SRCS} ${MapViewermoc} ${MapViewerUI})

