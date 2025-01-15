-- premake5.lua generated from the Full_build table in blmake.lua!

workspace "Full_build" 
configurations { "Debug", "Release" } 
location "build" 

project "Full_build" 
kind "ConsoleApp" 
language "C++" 
targetdir "build" 
objdir "build/obj" 

-- Compiler and files
files { "main.cpp", "utils.cpp", "lexer.cpp", "ast.cpp" } 

-- Language standard
cppdialect "C++20" 

-- Build options
filter "configurations:Debug" 
    defines { "DEBUG" } 
    symbols "On"
    optimize "Off"

filter "configurations:Release"
    defines { "NDEBUG" } 
    symbols "Off"
    optimize "Full" 
    flags { "LinkTimeOptimization" } 
