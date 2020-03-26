cmake_minimum_required(VERSION 3.15)

# libusb
if( SCOPEFUN_VISUALSTUDIO )
	include_external_msproject(libUsb ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/msvc/libusb_static_2017.vcxproj )
	set_target_properties(libUsb PROPERTIES FOLDER libUsb )
else()
	include(ExternalProject)
	externalproject_add(libUsb
		PREFIX            ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22
		BINARY_DIR        ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/Build/${CMAKE_BUILD_TYPE}
		SOURCE_DIR        ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22
		CONFIGURE_COMMAND sh ../configure --disable-shared  --enable-shared=no --enable-static
		BUILD_COMMAND     make
		UPDATE_COMMAND    ""
		INSTALL_COMMAND   ""
	 )
endif()

# SDL2
set( SDL_STATIC   ON  CACHE BOOL "" FORCE )
set( SDL_SHARED   OFF CACHE BOOL "" FORCE )
set( SDL_HAPTIC   OFF CACHE BOOL "" FORCE )
set( SDL_JOYSTICK OFF CACHE BOOL "" FORCE )
add_subdirectory ( SDL2-2.0.12 )
set_target_properties (SDL2main     PROPERTIES FOLDER SDL2 )
set_target_properties (SDL2-static  PROPERTIES FOLDER SDL2 )
set_target_properties (uninstall    PROPERTIES FOLDER SDL2 )

# wxWidgets
set(wxBUILD_USE_STATIC_RUNTIME TRUE)
set(wxBUILD_SHARED FALSE)
add_subdirectory ( wxwidgets-3.1.3 )
set_target_properties(clean_cotire PROPERTIES FOLDER wxwidgets/cotire )
set_target_properties(adv          PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(base         PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(core         PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(aui          PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(gl           PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(html         PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(media        PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(net          PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(propgrid     PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(qa           PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(ribbon       PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(richtext     PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(stc          PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(webview      PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(xml          PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(xrc          PROPERTIES FOLDER wxwidgets/libraries )
set_target_properties(wxexpat      PROPERTIES FOLDER wxwidgets/thirdparty )
set_target_properties(wxjpeg       PROPERTIES FOLDER wxwidgets/thirdparty )
set_target_properties(wxpng        PROPERTIES FOLDER wxwidgets/thirdparty )
set_target_properties(wxregex      PROPERTIES FOLDER wxwidgets/thirdparty )
set_target_properties(wxscintilla  PROPERTIES FOLDER wxwidgets/thirdparty )
set_target_properties(wxtiff       PROPERTIES FOLDER wxwidgets/thirdparty )
set_target_properties(wxzlib       PROPERTIES FOLDER wxwidgets/thirdparty )
set_target_properties(wxrc         PROPERTIES FOLDER wxwidgets/utilities )
