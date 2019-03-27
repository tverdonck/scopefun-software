cmake_minimum_required (VERSION 2.8)

# include folders
set(SCOPEFUN_LIB_INCLUDE_PYTHON    "${CMAKE_SOURCE_DIR}/lib/Python-2.7.16/Include"    CACHE PATH "include folder for python library" FORCE)
set(SCOPEFUN_LIB_INCLUDE_USB       "${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/libusb"     CACHE PATH "include folder for libUsb library" FORCE)
set(SCOPEFUN_LIB_INCLUDE_USB_EZ    "${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/examples"   CACHE PATH "include folder for ezusb load library" FORCE)
set(SCOPEFUN_LIB_INCLUDE_SDL2      "${CMAKE_SOURCE_DIR}/lib/SDL2-2.0.9/include"       CACHE PATH "include fodler for SDL2 library " FORCE)
set(SCOPEFUN_LIB_INCLUDE_WX        "${CMAKE_SOURCE_DIR}/lib/wxWidgets-3.0.4/include"  CACHE PATH "include fodler for wxWidgets library" FORCE)      
set(SCOPEFUN_LIB_INCLUDE_CJSON     "${CMAKE_SOURCE_DIR}/lib/cJSON"                CACHE PATH "include folder for cjson" FORCE)
set(SCOPEFUN_LIB_INCLUDE_KISSFFT   "${CMAKE_SOURCE_DIR}/lib/kissfft130"           CACHE PATH "include folder for kissfft" FORCE)
set(SCOPEFUN_LIB_INCLUDE_GLEW      "${CMAKE_SOURCE_DIR}/lib/glew-1.13.0/include"  CACHE PATH "include folder for glew" FORCE)

# include platform specifix folders
if(SCOPEFUN_WINDOWS)
   set(SCOPEFUN_LIB_INCLUDE_PYTHON_PC "${CMAKE_SOURCE_DIR}/lib/Python-2.7.16/PC" CACHE PATH "include folder for python on windows" FORCE)                                                                                      
   set(SCOPEFUN_LIB_INCLUDE_WX_SETUP  "${CMAKE_SOURCE_DIR}/lib/wxWidgets-3.0.4/sfBuild${SCOPEFUN_TYPE}/lib/wx/include/msw-unicode-static-3.0" CACHE PATH "include folder for wx/setup.h" FORCE ) 
endif()
if(SCOPEFUN_MACOSX)
   set(SCOPEFUN_LIB_INCLUDE_PYTHON_PC "${CMAKE_SOURCE_DIR}/lib/Python-2.7.16/sfBuild${SCOPEFUN_TYPE}" CACHE PATH "include folder for python on mac and linux" FORCE)
   set(SCOPEFUN_LIB_INCLUDE_WX_SETUP  "${CMAKE_SOURCE_DIR}/lib/wxWidgets-3.0.4/sfBuild${SCOPEFUN_TYPE}/lib/wx/include/osx_cocoa-unicode-static-3.0" CACHE PATH "include folder for wx/setup.h" FORCE )
endif()
if(SCOPEFUN_LINUX)
   set(SCOPEFUN_LIB_INCLUDE_PYTHON_PC "${CMAKE_SOURCE_DIR}/lib/Python-2.7.16/sfBuild${SCOPEFUN_TYPE}" CACHE PATH "include folder for python on mac and linux" FORCE)
   set(SCOPEFUN_LIB_INCLUDE_WX_SETUP  "${CMAKE_SOURCE_DIR}/lib/wxWidgets-3.0.4/sfBuild${SCOPEFUN_TYPE}/lib/wx/include/gtk3-unicode-static-3.0" CACHE PATH "include folder for wx/setup.h" FORCE ) 
endif()

# link folders
set(SCOPEFUN_LIB_LINK_USB     "${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/sfBuild${SCOPEFUN_TYPE}/libusb/.libs" CACHE FILEPATH "link folder for libUsb" FORCE)
set(SCOPEFUN_LIB_LINK_SDL2    "${CMAKE_SOURCE_DIR}/lib/SDL2-2.0.9/sfBuild${SCOPEFUN_TYPE}/build/.libs"     CACHE FILEPATH "link folder for SDL2" FORCE)
set(SCOPEFUN_LIB_LINK_WX      "${CMAKE_SOURCE_DIR}/lib/wxWidgets-3.0.4/sfBuild${SCOPEFUN_TYPE}/lib"        CACHE FILEPATH "link folder for wxWidgets" FORCE)

# link folders platform specific
if(SCOPEFUN_WINDOWS)
	set(SCOPEFUN_LIB_LINK_PYTHON  "${CMAKE_SOURCE_DIR}/lib/Python-2.7.16/${SCOPEFUN_BITS}" CACHE FILEPATH "link folder for python" FORCE)
else()
	set(SCOPEFUN_LIB_LINK_PYTHON  "${CMAKE_SOURCE_DIR}/lib/Python-2.7.16/sfBuild${SCOPEFUN_TYPE}" CACHE FILEPATH "link folder for python" FORCE)
endif()

# libraries
if(SCOPEFUN_WINDOWS)

set(SCOPEFUN_LIBS
"mingw32.a" 
"${SCOPEFUN_LIB_LINK_USB}/libusb-1.0.a"
"${SCOPEFUN_LIB_LINK_SDL2}/libSDL2.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_adv-3.0.a" 
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_core-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_baseu-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_baseu_net-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_baseu_xml-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_aui-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_gl-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_html-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_media-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_propgrid-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_qa-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_ribbon-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_richtext-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_stc-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_webview-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_mswu_xrc-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxexpat-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxjpeg-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxpng-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxregexu-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxscintilla-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxtiff-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxzlib-3.0.a" 
"opengl32.a"
"winmm.a"
"ole32.a"
"imm32.a"
"version.a"
"uuid.a"
"oleaut32.a"
"comctl32.a"
"winspool.a"
"ws2_32.a"
"wsock32.a"
"setupapi.a"
"hid.a"
"${CMAKE_SOURCE_DIR}/source/osciloscope/rc/osc.res"
)

endif()

if(SCOPEFUN_MACOSX)

set(SCOPEFUN_LIBS 
"iconv.a"
"Z.a"
"${SCOPEFUN_LIB_LINK_USB}/libusb-1.0.a"
"${SCOPEFUN_LIB_LINK_SDL2}/libSDL2.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_adv-3.0.a" 
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_core-3.0.a" 
"${SCOPEFUN_LIB_LINK_WX}/libwx_baseu-3.0.a" 
"${SCOPEFUN_LIB_LINK_WX}/libwx_baseu_net-3.0.a" 
"${SCOPEFUN_LIB_LINK_WX}/libwx_baseu_xml-3.0.a" 
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_aui-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_gl-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_html-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_media-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_propgrid-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_qa-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_ribbon-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_richtext-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_stc-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_webview-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_osx_cocoau_xrc-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxjpeg-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxpng-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxregexu-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxscintilla-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxtiff-3.0.a"
"-framework CoreFoundation"
"-framework AudioUnit"
"-framework CoreAudioKit"
"-framework AudioToolbox"
"-framework ForceFeedback"
"-framework IOKit"
"-framework Carbon"
"-framework Cocoa"
"-framework CoreAudio"
"-framework CoreVideo"
"-framework WebKit"
"-framework OpenGL"
"-framework Metal"
)

endif()

if(SCOPEFUN_LINUX)

set(SCOPEFUN_LIBS 
"${SCOPEFUN_LIB_LINK_USB}/libusb-1.0.a"
"${SCOPEFUN_LIB_LINK_SDL2}/libSDL2.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_adv-3.0.a" 
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_core-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_baseu-3.0.a" 
"${SCOPEFUN_LIB_LINK_WX}/libwx_baseu_xml-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_baseu_net-3.0.a" 
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_aui-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_html-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_propgrid-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_qa-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_ribbon-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_richtext-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_xrc-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxjpeg-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxregexu-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxscintilla-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwxtiff-3.0.a"
"${SCOPEFUN_LIB_LINK_WX}/libwx_gtk3u_stc-3.0.a"
"dl"
"X11"
"Xext"
"SM"
"gtk-3"
"gdk-3"
"pango-1.0"
"cairo"
"pangocairo-1.0"
"gdk_pixbuf-2.0"
"gobject-2.0"
"glib-2.0"
"z"
"m"
"expat"
"atk-1.0"
"gio-2.0"
"gthread-2.0"
"pthread"
"png"
"GL"
"udev"
"Xxf86vm"
)

endif()

