cmake_minimum_required(VERSION 3.27.0)

project(ImOsmVis LANGUAGES CXX C VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

if(WIN32) 
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:100000000")
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
add_compile_definitions(_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
endif(WIN32) 
		
find_package(glfw3 REQUIRED)
find_package(glew REQUIRED)
find_package(glu REQUIRED)
find_package(imgui REQUIRED)
find_package(stb REQUIRED)
find_package(CURL REQUIRED)
find_package(freeglut REQUIRED)
find_package(freetype REQUIRED)
find_package(ZLIB REQUIRED)
find_package(opengl REQUIRED)

set(CPACK_NSIS_CONTACT "rajiv.sithiravel@gmail.com")
	
include(CTest) 
# CTest sets the BUILD_TESTING variable to ON
if (BUILD_TESTING)

    add_executable(${PROJECT_NAME} 
	bindings/imgui_impl_glfw.h
    bindings/imgui_impl_opengl3.h
    bindings/imgui_impl_opengl3_loader.h
	bindings/imgui_impl_glfw.cpp
	bindings/imgui_impl_opengl3.cpp
	external/imapp/imapp.h
	external/imapp/ImAppMainWindow.h
	external/imapp/ImAppStopWatch.h
	external/imapp/ImAppMainWindow.cpp
	external/imfonts/RobotoBold.cpp
	external/imfonts/RobotoItalic.cpp
	external/imfonts/RobotoMonoBold.cpp
	external/imfonts/RobotoMonoItalic.cpp
	external/imfonts/RobotoMonoRegular.cpp
	external/imfonts/RobotoRegular.cpp
	external/imosm/src/ImOsmTile.cpp
    external/imosm/src/ImOsmTileLoader.cpp
    external/imosm/src/ImOsmTileSourceAsync.cpp
    external/imosm/src/ImOsmTileSourceUrl.cpp
    external/imosm/src/ImOsmTileGrabberUrl.cpp
    external/imosm/src/ImOsmTileGrabber.cpp
    external/imosm/src/ImOsmMapPlot.cpp
    external/imosm/src/ImOsmTileLoaderUrl.cpp
    external/imosm/src/ImOsmTileTexture.cpp
    external/imosm/src/ImOsmRichMarkItem.cpp
    external/imosm/src/ImOsmRichMarkStorage.cpp
    external/imosm/src/ImOsmRichMarkEditorWidget.cpp
    external/imosm/src/ImOsmRichMarkItemWidget.cpp
    external/imosm/src/ImOsmRichDestinationCalcWidget.cpp
    external/imosm/src/ImOsmRichDistanceCalcWidget.cpp
    external/imosm/src/ImOsmRichMapPlot.cpp
    external/imosm/src/ImOsmTileGrabberWidget.cpp
    external/imosm/src/ImOsmTileSourceWidget.cpp
    external/imosm/src/ImOsmTileSourceUrlImpl.cpp
    external/imosm/src/ImOsmTileSourceFs.cpp
    external/imosm/src/ImOsmTileSaver.cpp
	external/implot/implot.cpp
	external/implot/implot.h
	external/implot/implot_internal.h
	external/implot/implot_items.cpp
	src/ImOsmDemoApp.cpp
    src/ImOsmDemoApp.h
	src/main.cpp)
	
	if(WIN32) 				
	target_compile_options(${PROJECT_NAME} PRIVATE "/Od")   
	endif(WIN32)

	target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLEW)
    target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/bindings ${PROJECT_SOURCE_DIR}/external/imapp ${PROJECT_SOURCE_DIR}/external/imfonts ${PROJECT_SOURCE_DIR}/external/imosm ${PROJECT_SOURCE_DIR}/external/imosm/include ${PROJECT_SOURCE_DIR}/external/imosm/src ${PROJECT_SOURCE_DIR}/external/implot ${PROJECT_SOURCE_DIR}/external/imwrap ${PROJECT_SOURCE_DIR}/external/imwrap/include ${PROJECT_SOURCE_DIR}/external/latlon ${PROJECT_SOURCE_DIR}/external/latlon/script ${PROJECT_SOURCE_DIR}/external/mini) 
	target_link_libraries(${PROJECT_NAME} glfw opengl::opengl GLEW::GLEW imgui::imgui stb::stb FreeGLUT::freeglut_static Freetype::Freetype ZLIB::ZLIB CURL::libcurl glu::glu)

endif()
