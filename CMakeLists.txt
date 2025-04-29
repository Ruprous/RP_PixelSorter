cmake_minimum_required(VERSION 3.10)

# プロジェクト名とC++標準の指定
project(RP_PixelSorter)
set(CMAKE_CXX_STANDARD 11)

# AfterEffects SDKのパスを指定
set(AE_SDK_PATH "C:/Program Files/Adobe/AfterEffectsSDK/Examples")

# インクルードディレクトリとリンクディレクトリを設定
include_directories(${AE_SDK_PATH})

# ソースファイルの指定
add_library(RP_PixelSorter SHARED
    RP_PixelSorter.cpp
)

# エフェクトプラグインとして出力されるファイル名と拡張子
set_target_properties(RP_PixelSorter PROPERTIES
    PREFIX ""
    SUFFIX ".aex"
)

# リンクする必要のあるライブラリ (AfterEffectsのライブラリ)
target_link_libraries(RP_PixelSorter
    "${AE_SDK_PATH}/Libraries/Win/EntryPoint.lib"
    "${AE_SDK_PATH}/Libraries/Win/AEGP.lib"
)
