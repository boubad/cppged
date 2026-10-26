# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une
# configuration globale et incluez les sous-projets ici.
#
cmake_minimum_required(VERSION 3.10)
# ========================
cmake_host_system_information(RESULT HOST_NAME QUERY HOSTNAME)
message(STATUS "Host name: ${HOST_NAME}")
# =======================
# Activez Rechargement à chaud pour les compilateurs MSVC si cela est pris en
# charge.
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
      "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>"
  )
endif()

project("cppged")
#
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  if(HOST_NAME STREQUAL "phobos")
    include_directories("C:/vcpkg/installed/x64-windows/include")
    link_directories("C:/vcpkg/installed/x64-windows/lib")
  else()
    include_directories("D:/vcpkg/installed/x64-windows/include")
    link_directories("D:/vcpkg/installed/x64-windows/lib")
  endif()
endif()
# ======================
set(INFO_LIBS infoged)
# ======================
# Incluez les sous-projets.
add_subdirectory("infoged")
add_subdirectory("testinfoged")
# =====================
add_dependencies(testinfoged infoged)
# ======================
