cmake_minimum_required(VERSION 3.15)

#--------------------------------------------------------------------------------
# version
#--------------------------------------------------------------------------------
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/source/version/sfversion.h.in ${CMAKE_SOURCE_DIR}/source/version/sfversion.h @ONLY)

#--------------------------------------------------------------------------------
# cpp files
#--------------------------------------------------------------------------------
file(
    GLOB_RECURSE HEADERS_SOURCE
    LIST_DIRECTORIES false
    "*.h*"
)

file(
    GLOB_RECURSE FILES_CORE
    LIST_DIRECTORIES false
    "core/*.c*"
)

file(
    GLOB_RECURSE FILES_SCOPEFUN
    LIST_DIRECTORIES false
	"ScopeFun/*.c*"
)

set( FILES_LIB 
"${CMAKE_SOURCE_DIR}/lib/cJSON/cJSON.c"
"${CMAKE_SOURCE_DIR}/lib/glew-1.13.0/src/glew.c"
"${CMAKE_SOURCE_DIR}/lib/kiss_fft130/kiss_fft.c"
"${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/examples/ezusb.c" )

set( FILES_API "${CMAKE_SOURCE_DIR}/source/api/scopefun.c" )

set( FILES_RES "${CMAKE_SOURCE_DIR}/source/scopefun/xpm/xpm96.c"
			   "${CMAKE_SOURCE_DIR}/source/scopefun/xpm/xpm512.c"
			   "${CMAKE_SOURCE_DIR}/source/scopefun/xpm/xpm64.c"
			   "${CMAKE_SOURCE_DIR}/source/scopefun/xpm/xpm256.c"
			   "${CMAKE_SOURCE_DIR}/source/scopefun/xpm/xpm16.c"
			   "${CMAKE_SOURCE_DIR}/source/scopefun/xpm/xpm32.c"
			   "${CMAKE_SOURCE_DIR}/source/scopefun/xpm/xpm128.c"
			   "${CMAKE_SOURCE_DIR}/source/scopefun/rc/dpi.manifest"
			   "${SF_DATA}"
			   "${SF_LOCALE}" )

#--------------------------------------------------------------------------------
# executable
#--------------------------------------------------------------------------------
if(SCOPEFUN_WINDOWS)
	set( SCOPEFUN_EXE_TYPE WIN32 )
endif()
if(SCOPEFUN_MACOSX)
	set( SCOPEFUN_EXE_TYPE MACOSX_BUNDLE )
endif()
if(SCOPEFUN_LINUX)
	set( SCOPEFUN_EXE_TYPE "" )
endif()
if( SCOPEFUN_VISUALSTUDIO)
	add_executable(ScopeFun ${SCOPEFUN_EXE_TYPE} ${HEADERS_SOURCE} ${FILES_CORE} ${FILES_SCOPEFUN} ${FILES_LIB} ${FILES_API} ${FILES_RES} )
else()
	add_executable(ScopeFun ${SCOPEFUN_EXE_TYPE} ${FILES_CORE} ${FILES_SCOPEFUN} ${FILES_LIB} ${FILES_API} ${FILES_RES} )
endif()
	
#--------------------------------------------------------------------------------
# groups
#--------------------------------------------------------------------------------				
source_group("Core"     FILES ${FILES_CORE})
source_group("ScopeFun" FILES ${FILES_SCOPEFUN})
source_group("Lib"      FILES ${FILES_LIB})
source_group("Res"      FILES ${FILES_RES})
source_group("Api"      FILES ${FILES_API})
source_group("Header"   FILES ${HEADERS_SOURCE})

#--------------------------------------------------------------------------------
# include
#--------------------------------------------------------------------------------
if( ${SCOPEFUN_BUILD_TYPE} MATCHES "Debug" )
	if( ${SCOPEFUN_VISUALSTUDIO} )
		set(SCOPEFUN_INCLUDE_WX_SETUP   ${CMAKE_BINARY_DIR}/lib/vc_x64_lib/mswud )
	else()
		set(SCOPEFUN_INCLUDE_WX_SETUP   ${CMAKE_BINARY_DIR}/lib/gcc_x64_lib/mswud )
	endif()
endif()
if( ${SCOPEFUN_BUILD_TYPE} MATCHES "Release" )
	if( ${SCOPEFUN_VISUALSTUDIO} )
		set(SCOPEFUN_INCLUDE_WX_SETUP   ${CMAKE_BINARY_DIR}/lib/vc_x64_lib/mswu )
	else()
		set(SCOPEFUN_INCLUDE_WX_SETUP   ${CMAKE_BINARY_DIR}/lib/gcc_x64_lib/mswu )
	endif()
endif()
set(SCOPEFUN_INCLUDE_WX        "${CMAKE_SOURCE_DIR}/lib/wxWidgets-3.1.3/include"  CACHE PATH "include fodler for wxWidgets library" FORCE)
set(SCOPEFUN_INCLUDE_USB       "${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/libusb"     CACHE PATH "include folder for libUsb library" FORCE)
set(SCOPEFUN_INCLUDE_USB_EX    "${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/examples"   CACHE PATH "include folder for ezusb load library" FORCE)
set(SCOPEFUN_INCLUDE_SDL2      "${CMAKE_SOURCE_DIR}/lib/SDL2-2.0.12/include"      CACHE PATH "include fodler for SDL2 library " FORCE)
set(SCOPEFUN_INCLUDE_CJSON     "${CMAKE_SOURCE_DIR}/lib/cJSON"                    CACHE PATH "include folder for cjson" FORCE)
set(SCOPEFUN_INCLUDE_KISSFFT   "${CMAKE_SOURCE_DIR}/lib/kissfft130"               CACHE PATH "include folder for kissfft" FORCE)
set(SCOPEFUN_INCLUDE_GLEW      "${CMAKE_SOURCE_DIR}/lib/glew-1.13.0/include"      CACHE PATH "include folder for glew" FORCE)

target_include_directories(
    ScopeFun
    PUBLIC
	${CMAKE_SOURCE_DIR}/source
	${SCOPEFUN_INCLUDE_USB}
	${SCOPEFUN_INCLUDE_USB_EX}
	${SCOPEFUN_INCLUDE_SDL2}	
	${SCOPEFUN_INCLUDE_WX}
	${SCOPEFUN_INCLUDE_WX_SETUP}
	${SCOPEFUN_INCLUDE_CJSON} 
	${SCOPEFUN_INCLUDE_KISSFFT} 
	${SCOPEFUN_INCLUDE_GLEW}
)

#--------------------------------------------------------------------------------
# output
#--------------------------------------------------------------------------------
set_target_properties( ScopeFun PROPERTIES OUTPUT_NAME "${SCOPEFUN_EXE_NAME}" )

#--------------------------------------------------------------------------------
# warnings
#--------------------------------------------------------------------------------
# target_compile_options(ScopeFun PRIVATE -Wall)
# target_compile_options(ScopeFun PRIVATE -WX)
	
#--------------------------------------------------------------------------------
# link
#--------------------------------------------------------------------------------
if( SCOPEFUN_VISUALSTUDIO )
	set( SCOPEFUN_LIB_USB ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/Build/${SCOPEFUN_BUILD_TYPE}/libusb-1.0.lib )
else()
	set( SCOPEFUN_LIB_USB ${CMAKE_SOURCE_DIR}/lib/libusb-1.0.22/Build/${SCOPEFUN_BUILD_TYPE}/libusb/.libs/libusb-1.0.a )
endif()
list( APPEND SCOPEFUN_LIB_SDL2 SDL2-static )
list( APPEND SCOPEFUN_LIB_WX core base adv propgrid richtext )
if(SCOPEFUN_WINDOWS)
	if( SCOPEFUN_VISUALSTUDIO )
		target_link_libraries( ScopeFun  
			# libs
			# ${SCOPEFUN_LIB_USB} 
			${SCOPEFUN_LIB_SDL2} 
			${SCOPEFUN_LIB_WX} 
			# system
			opengl32.lib 
			winmm.lib 
			ole32.lib 
			imm32.lib 
			version.lib 
			uuid.lib 
			oleaut32.lib 
			comctl32.lib 
			winspool.lib 
			ws2_32.lib 
			wsock32.lib 
			setupapi.lib 
			hid.lib 
			Rpcrt4.lib 
			# res
			${CMAKE_SOURCE_DIR}/source/scopefun/rc/osc.res
		)
	else()
		target_link_libraries(ScopeFun 
		# mingw
		mingw32.a
		# libs
		${SCOPEFUN_LIB_USB}
		${SCOPEFUN_LIB_SDL2}
		${SCOPEFUN_LIB_WX}
		# system
		opengl32.a 
		winmm.a 
		ole32.a 
		imm32.a 
		version.a 
		uuid.a 
		oleaut32.a 
		comctl32.a 
		winspool.a 
		ws2_32.a 
		wsock32.a 
		setupapi.a 
		hid.a 
		# res
		${CMAKE_SOURCE_DIR}/source/scopefun/rc/osc.res
		)
	endif()
endif()
if(SCOPEFUN_MACOSX)
	target_link_libraries(ScopeFun 
		# system
		iconv.a
		Z.a
		# libs
		${SCOPEFUN_LIB_USB}
		${SCOPEFUN_LIB_SDL2}
		${SCOPEFUN_LIB_WX}
		# frameworks
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
	target_link_libraries(ScopeFun
		# libs
		${SCOPEFUN_LIB_USB} 
		${SCOPEFUN_LIB_SDL2} 
		${SCOPEFUN_LIB_WX} 
		# system
		dl 
		X11 
		Xext 
		SM 
		gtk-3 
		gdk-3 
		pango-1.0 
		cairo 
		pangocairo-1.0 
		gdk_pixbuf-2.0 
		gobject-2.0 
		glib-2.0 
		z 
		m 
		expat 
		atk-1.0 
		gio-2.0 
		gthread-2.0 
		pthread 
		png 
		GL 
		udev 
		Xxf86vm 
	)
endif()

#--------------------------------------------------------------------------------
# defines
#--------------------------------------------------------------------------------
if (${SCOPEFUN_BUILD_TYPE} MATCHES "Release")
	 add_definitions(-DNDEBUG)
endif()
if (${SCOPEFUN_BUILD_TYPE} MATCHES "Debug")
   	 add_definitions(-D_DEBUG)
endif()
add_definitions(-D__WX__)
add_definitions(-DwxUSE_UNICODE=1)
add_definitions(-DwxUSE_UNICODE_UTF8=0)
add_definitions(-DwxUSE_UNICODE_WCHAR=1)
add_definitions(-DwxUSE_COMBOCTRL=1)
add_definitions(-DwxUSE_GLOBAL_MEMORY_OPERATORS=0) 
add_definitions(-DSDL_MAIN_HANDLED)
add_definitions(-DGLEW_STATIC)
add_definitions(-DGLEW_NO_GLU)
add_definitions(-DDBL_EPSILON=0.0000000000001)
add_definitions(-DUSE_LOCKS=1)
add_definitions(-DUSE_DL_PREFIX)
add_definitions(-D_FILE_OFFSET_BITS=64) 
add_definitions(-D_LARGE_FILES)
if(SCOPEFUN_WINDOWS)
	add_definitions(-DWIN64)
	add_definitions(-D__WIN64__)
	add_definitions(-DPLATFORM_WIN)
	add_definitions(-D_WINDOWS)
	if(SCOPEFUN_VISUALSTUDIO)
	   add_definitions(-DMS_WIN64)
	   add_definitions(-DMS_WIN64)
	   add_definitions(-DPLATFORM_MSVC)
	else()
	   add_definitions(-D__MINGW64__)
	   add_definitions(-DPLATFORM_MINGW)
	endif()
endif()
if(SCOPEFUN_MACOSX)
   add_definitions(-DPLATFORM_MAC)
   add_definitions(-DMAC)
   add_definitions(-D__WXOSX_COCOA__)
   add_definitions(-D__WXOSX__)
   add_definitions(-D__WXMAC__)
   add_definitions(-D_WXMAC_XCODE__=1)
endif()
if(SCOPEFUN_LINUX)
   add_definitions(-DPLATFORM_LINUX)
   add_definitions(-DLINUX)
   add_definitions(-D__LINUX__)
   add_definitions(-D__WXGTK__)
endif(SCOPEFUN_LINUX)

#--------------------------------------------------------------------------------
# post-build
#--------------------------------------------------------------------------------
add_custom_command(
			TARGET ScopeFun POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy
					$<TARGET_FILE:ScopeFun>
					${CMAKE_SOURCE_DIR}/bin/${SCOPEFUN_EXE_NAME}.exe 
)

#--------------------------------------------------------------------------------
# install
#--------------------------------------------------------------------------------
if(SCOPEFUN_LINUX)
	
	set(ALL_PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE )

    install( DIRECTORY "${CMAKE_SOURCE_DIR}/package/scopefun-linux-${SCOPEFUN_BITS}/DEBIAN"   DESTINATION "../" 
	FILE_PERMISSIONS ${ALL_PERMISSIONS} DIRECTORY_PERMISSIONS  ${ALL_PERMISSIONS})
    install( DIRECTORY "${CMAKE_SOURCE_DIR}/package/scopefun-linux-${SCOPEFUN_BITS}/usr"      DESTINATION "../" 
	FILE_PERMISSIONS ${ALL_PERMISSIONS} DIRECTORY_PERMISSIONS  ${ALL_PERMISSIONS})
    install( DIRECTORY "${CMAKE_SOURCE_DIR}/package/scopefun-linux-${SCOPEFUN_BITS}/lib"      DESTINATION "../" 
	FILE_PERMISSIONS ${ALL_PERMISSIONS} DIRECTORY_PERMISSIONS  ${ALL_PERMISSIONS})
    install( DIRECTORY "${CMAKE_SOURCE_DIR}/bin/locale"                                       DESTINATION "./share" 
	FILE_PERMISSIONS ${ALL_PERMISSIONS} DIRECTORY_PERMISSIONS  ${ALL_PERMISSIONS})
    install( DIRECTORY "${CMAKE_SOURCE_DIR}/bin/data"                                         DESTINATION "./lib/oscilloscope" FILE_PERMISSIONS ${ALL_PERMISSIONS} DIRECTORY_PERMISSIONS  ${ALL_PERMISSIONS})
    install(TARGETS ScopeFun
            PERMISSIONS ${ALL_PERMISSIONS}
            RUNTIME  DESTINATION "./bin"
            BUNDLE   DESTINATION "./bin" )
else()
	install(TARGETS ScopeFun
	        PERMISSIONS ${ALL_PERMISSIONS}
			RUNTIME  DESTINATION "."
			BUNDLE   DESTINATION "." )
endif()
if(SCOPEFUN_MACOSX)
	add_custom_command(
			TARGET ScopeFun POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_SOURCE_DIR}/bin/data
					${CMAKE_SOURCE_DIR}/bin/ScopeFun${SCOPEFUN_TYPE}.app/Contents/Resources/data)
					
	add_custom_command(
			TARGET ScopeFun POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_SOURCE_DIR}/bin/locale
					${CMAKE_SOURCE_DIR}/bin/ScopeFun${SCOPEFUN_TYPE}.app/Contents/Resources/locale)
					
	add_custom_command(
			TARGET ScopeFun POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy
					${CMAKE_SOURCE_DIR}/package/scopefun-mac/AppIcon.icns
					${CMAKE_SOURCE_DIR}/bin/ScopeFun${SCOPEFUN_TYPE}.app/Contents/Resources)
	
	set(MACOSX_BUNDLE_INFO_STRING           "ScopeFun open source oscilloscope" )
	set(MACOSX_BUNDLE_ICON_FILE    			AppIcon )
	set(MACOSX_BUNDLE_GUI_IDENTIFIER		"ScopeFun.Oscilloscope" )
	set(MACOSX_BUNDLE_BUNDLE_NAME           "ScopeFun" )
	set(MACOSX_BUNDLE_LONG_VERSION_STRING   ${SCOPEFUN_VERSION_MAJOR}.${SCOPEFUN_VERSION_MINOR}.${SCOPEFUN_VERSION_MICRO} )
	set(MACOSX_BUNDLE_SHORT_VERSION_STRING  ${SCOPEFUN_VERSION_MAJOR}.${SCOPEFUN_VERSION_MINOR}.${SCOPEFUN_VERSION_MICRO} )
	set(MACOSX_BUNDLE_BUNDLE_VERSION        ${SCOPEFUN_VERSION_MAJOR}.${SCOPEFUN_VERSION_MINOR}.${SCOPEFUN_VERSION_MICRO} )
	set(MACOSX_BUNDLE_COPYRIGHT             "Copyright (C) 2016 - 2019 David Košenina" )

	set(CPACK_BUNDLE_PLIST ${CMAKE_SOURCE_DIR}/package/info.plist )
	set(CPACK_BUNDLE_ICON  ${CMAKE_SOURCE_DIR}/package/scopefun-mac/appicon.icns )
	set(CPACK_BUNDLE_NAME "ScopeFun")
endif()
if(SCOPEFUN_WINDOWS)

	set(ALL_PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE )

	# install
    install( DIRECTORY "${CMAKE_SOURCE_DIR}/bin/data" DESTINATION "." FILE_PERMISSIONS ${ALL_PERMISSIONS} DIRECTORY_PERMISSIONS  ${ALL_PERMISSIONS} )
	
    install( DIRECTORY "${CMAKE_SOURCE_DIR}/bin/locale" DESTINATION "." FILE_PERMISSIONS ${ALL_PERMISSIONS} DIRECTORY_PERMISSIONS  ${ALL_PERMISSIONS} )

	# generator
	set(CPACK_GENERATOR "NSIS") 

	# version
	set(CPACK_NSIS_PACKAGE_NAME "ScopeFun" )

	# create links
	LIST(APPEND CPACK_NSIS_CREATE_ICONS_EXTRA  "
		CreateShortCut '$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\ScopeFun.lnk'  '$INSTDIR\\\\ScopeFun${SCOPEFUN_TYPE}.exe'
		CreateShortCut '$DESKTOP\\\\ScopeFun.lnk'  '$INSTDIR\\\\ScopeFun${SCOPEFUN_TYPE}.exe'")
		
	# delete links
	LIST(APPEND CPACK_NSIS_DELETE_ICONS_EXTRA  "  
		Delete '$SMPROGRAMS\\\\$START_MENU\\\\ScopeFun.lnk'
		Delete '$SMPROGRAMS\\\\$START_MENU\\\\ScopeFun.lnk'
		Delete '$DESKTOP\\\\ScopeFun.lnk'
		Delete '$DESKTOP\\\\ScopeFun.lnk'")

	#icons
	set(CPACK_NSIS_MUI_ICON                       "${CMAKE_SOURCE_DIR}/package/scopefun-win\\\\logo.ico")
	set(CPACK_NSIS_MUI_UNIICON                    "${CMAKE_SOURCE_DIR}/package/scopefun-win\\\\logo.ico")
	set(CPACK_NSIS_MUI_WELCOMEFINISHPAGE_BITMAP   "${CMAKE_SOURCE_DIR}/package/scopefun-win\\\\setup.bmp")
	set(CPACK_NSIS_MUI_UNWELCOMEFINISHPAGE_BITMAP "${CMAKE_SOURCE_DIR}/package/scopefun-win\\\\setup.bmp")
endif(SCOPEFUN_WINDOWS)

#--------------------------------------------------------------------------------
# pack
#--------------------------------------------------------------------------------

# url
set( CPACK_PACKAGE_HOMEPAGE_URL www.scopefun.com)

#icons
if(SCOPEFUN_MACOSX)
	set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/package/header.bmp")
else()
	set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/package\\\\header.bmp")
endif()

# license
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING.TXT" )

# version
set(CPACK_PACKAGE_VERSION_MAJOR ${SCOPEFUN_VERSION_MAJOR} )
set(CPACK_PACKAGE_VERSION_MINOR ${SCOPEFUN_VERSION_MINOR} )
set(CPACK_PACKAGE_VERSION_PATCH ${SCOPEFUN_VERSION_MICRO} )

#vendor
set(CPACK_PACKAGE_VENDOR "ScopeFun" )

#vendor
set(CPACK_PACKAGE_CONTACT "info@scopefun.com" )

#description
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/package/desc.txt" ) 
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Open Source Oscilloscope" )

#checksum
set(CPACK_PACKAGE_CHECKSUM SHA512)

#source
set(CPACK_SOURCE_IGNORE_FILES  "" 
"/\\\\.git/;"
"/\\\\sfExe/;"
"/\\\\sfSrc/;"
"/\\\\bin/ScopeFun.exe/;"
"/\\\\bin/sfBuild.exe/;"
"/\\\\lib/libusb-1.0.22/Build/;"
"/\\\\lib/libusb-1.0.22/src/;"
"/\\\\lib/libusb-1.0.22/tmp/;"
"/\\\\lib/SDL2-2.0.12/Build/;"
"/\\\\lib/SDL2-2.0.12/tmp/;"
"/\\\\lib/wxWidgets-3.1.3/Build/;"
"/\\\\lib/wxWidgets-3.1.3/src/wxWidgets313-stamp/;"
"/\\\\lib/wxWidgets-3.1.3/tmp/;"
)

include(CPack)