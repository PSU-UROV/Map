project(MapsLib)

set(MapsLib_SRCS
	vector3f.cpp
	vector2f.cpp
	matrix2x2f.cpp
	matrixops.cpp)

set(MapsLib_HDRS
	vector3f.h
	vector2f.h
	matrix2x2f.h
	matrixops.h)

add_library(mapslib ${MapsLib_SRCS})

