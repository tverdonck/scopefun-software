cmake_minimum_required(VERSION 3.15)

# lua_c
file(
    GLOB_RECURSE LUA_C
    LIST_DIRECTORIES false
    "lua-5.3.5/src/*.c"
)

# lua_h
file(
    GLOB_RECURSE LUA_H
    LIST_DIRECTORIES false
    "lua-5.3.5/src/*.h*"
)

# lua
if( SCOPEFUN_VISUALSTUDIO)
	add_library(lua STATIC ${LUA_H} ${LUA_C} )
	source_group("Header" FILES ${LUA_H} )
else()
	add_library(lua STATIC ${LUA_C} )
endif()
set_target_properties(lua PROPERTIES FOLDER Lua )

# libusb
if( SCOPEFUN_VISUALSTUDIO )
	include_external_msproject(libUsb ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/msvc/libusb_static_2017.vcxproj )
	set_target_properties(libUsb PROPERTIES FOLDER libUsb )
else()
	include(ExternalProject)
	if( SCOPEFUN_MACOSX )
		externalproject_add(libUsb
			PREFIX 			  ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/
			SOURCE_DIR        ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/
			BINARY_DIR        ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/Build/${SCOPEFUN_BUILD_TYPE}/
			CONFIGURE_COMMAND sh ../../configure --disable-shared  --enable-shared=no
			BUILD_COMMAND     make
			UPDATE_COMMAND    ""
			INSTALL_COMMAND   ""
		 )
	else()
		externalproject_add(libUsb
			PREFIX 			  ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/
			SOURCE_DIR        ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/
			BINARY_DIR        ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/Build/${SCOPEFUN_BUILD_TYPE}/
			CONFIGURE_COMMAND sh ../../configure --disable-shared  --enable-shared=no --enable-static --without-pcre
			BUILD_COMMAND     make
			UPDATE_COMMAND    ""
			INSTALL_COMMAND   ""
		 )
	endif()
endif()

# SDL2
set( SDL_STATIC   ON  CACHE BOOL "" FORCE )
set( SDL_SHARED   OFF CACHE BOOL "" FORCE )
set( SDL_HAPTIC   OFF CACHE BOOL "" FORCE )
set( SDL_JOYSTICK OFF CACHE BOOL "" FORCE )
add_subdirectory ( SDL2-2.0.12 EXCLUDE_FROM_ALL )
set_target_properties (SDL2main     PROPERTIES FOLDER SDL2 )
set_target_properties (SDL2-static  PROPERTIES FOLDER SDL2 )
set_target_properties (uninstall    PROPERTIES FOLDER SDL2 )

# wxWidgets
set(wxBUILD_USE_STATIC_RUNTIME TRUE)
set(wxBUILD_SHARED  FALSE)
set(wxBUILD_PRECOMP FALSE)
set(wxUSE_LIBTIFF OFF CACHE STRING "" FORCE) 
add_subdirectory ( wxwidgets-3.1.3 EXCLUDE_FROM_ALL )
set_target_properties(core         PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(base         PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(adv          PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(aui          PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(gl           PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(html         PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(media        PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(net          PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(propgrid     PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(qa           PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(ribbon       PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(richtext     PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(stc          PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(webview      PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(xml          PROPERTIES FOLDER wxWidgets/libraries )
set_target_properties(xrc          PROPERTIES FOLDER wxWidgets/libraries )
if( SCOPEFUN_VISUALSTUDIO OR SCOPEFUN_WINDOWS )
	set_target_properties(wxexpat      PROPERTIES FOLDER wxWidgets/thirdparty )
	set_target_properties(wxzlib       PROPERTIES FOLDER wxWidgets/thirdparty )
endif()
set_target_properties(wxjpeg       PROPERTIES FOLDER wxWidgets/thirdparty )
set_target_properties(wxpng        PROPERTIES FOLDER wxWidgets/thirdparty )
set_target_properties(wxregex      PROPERTIES FOLDER wxWidgets/thirdparty )
set_target_properties(wxscintilla  PROPERTIES FOLDER wxWidgets/thirdparty )
set_target_properties(wxrc         PROPERTIES FOLDER wxWidgets/utilities )

