add_rules("mode.debug", "mode.release")

add_requires("raylib")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

add_includedirs("include")
add_installfiles("(resource/**)", {prefixdir = "bin"})
set_rundir("$(projectdir)")
set_languages("c++20")


target("TestTech")
    set_kind("binary")
    add_headerfiles("include/**.h")
    add_files("src/*.cpp")
    add_packages("raylib")


task("class")
    on_run(function ()
        import("core.base.option")
        
        -- get parameter content and display
        local classPath = option.get("className") or "newClass"

        headerTemplate = [[
#pragma once

namespace LilShip{

    class %CLASS_NAME%
    {
        public:
            %CLASS_NAME%() = default;
            %CLASS_NAME%(const %CLASS_NAME%&) = delete;
            %CLASS_NAME%(%CLASS_NAME%&&) = delete;
            ~%CLASS_NAME%() = default;

            %CLASS_NAME%& operator=(const %CLASS_NAME%&) = delete;
            %CLASS_NAME%& operator=(%CLASS_NAME%&&) = delete;

        private:
    };
}

]]

        sourceTemplate = [[
#include <%CLASS_PATH%.h>

namespace LilShip{

}
]]

        local className = path.basename(classPath)

        local files = { 
            {TargetPath = path.join("include", classPath) .. ".h", Template = headerTemplate},
            {TargetPath = path.join("src", classPath) .. ".cpp", Template = sourceTemplate}
        }

        local replacements = {
		    CLASS_NAME = className,
		    CLASS_PATH = classPath
        }

        for _, file in pairs(files) do
            local content = file.Template:gsub("%%([%u_]+)%%", function (keyword)
                local r = replacements[keyword]
                if not r then
                    os.raise("missing replacement for " .. keyword)
                end
                return r
            end)
            io.writefile(file.TargetPath, content)
        end

    end)
    
    set_menu {
        usage = "xmake class [options]",
        description = "Creates cpp class",
        options = {
            {nil, "className", "v", nil, "Set class name"}
        }
    }