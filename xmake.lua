add_rules("mode.debug", "mode.release")

add_requires("raylib")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

add_includedirs("include")


target("TestTech")
    set_kind("binary")
    add_headerfiles("include/**.h")
    add_files("src/*.cpp")
    add_packages("raylib")
