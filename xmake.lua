add_rules("mode.debug", "mode.release")

add_requires("raylib")

target("TestTech")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("raylib")
