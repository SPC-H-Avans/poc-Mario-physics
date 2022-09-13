cmake_minimum_required(VERSION 3.23)
project(poc_mario_physics)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR ./libs/SDL/include)
set(SDL2_LIB_DIR ./libs/SDL/lib/x64)

set(SDL2_IMAGE_INCLUDE_DIR ./libs/SDL_Image/include)
set(SDL2_IMAGE_LIB_DIR ./libs/SDL_Image/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

include_directories(${SDL2_IMAGE_INCLUDE_DIR})
link_directories(${SDL2_IMAGE_LIB_DIR})

include_directories(Core Graphics Physics Object Characters Animation Inputs Timer Map libs/TinyXML Camera Collision)

add_executable(poc_mario_physics main.cpp Core/Engine.cpp Core/Engine.h Graphics/TextureManager.cpp Graphics/TextureManager.h Physics/Vector2D.h Physics/Transform.h Object/IObject.h Object/GameObject.h Characters/Character.h Characters/Warrior.cpp Characters/Warrior.h Animation/Animation.cpp Animation/Animation.h Physics/RigidBody.h Inputs/Input.cpp Inputs/Input.h Timer/Timer.cpp Timer/Timer.h Map/Layer.h Map/GameMap.h Map/TileLayer.cpp Map/TileLayer.h Map/MapParser.cpp Map/MapParser.h libs/TinyXML/tinyxml.cpp libs/TinyXML/tinyxml.h libs/TinyXML/tinyxmlerror.cpp libs/TinyXML/tinyxmlparser.cpp libs/TinyXML/tinystr.cpp libs/TinyXML/tinystr.h Camera/Camera.cpp Camera/Camera.h Physics/Point.h Collision/CollisionHandler.cpp Collision/CollisionHandler.h Physics/Collider.h)

target_link_libraries(poc_mario_physics SDL2main SDL2 SDL2_image)

target_link_libraries(poc_mario_physics -static)

add_custom_command(TARGET poc_mario_physics POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets $<TARGET_FILE_DIR:poc_mario_physics>/Assets)