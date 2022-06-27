from conans import ConanFile, CMake

class NovelRTConan(ConanFile):
    name = "NovelRT"
    version = "0.1"
    license = "MIT"
    url = "https://github.com/novelrt/NovelRT"
    description = "A cross-platform 2D game engine accompanied by a strong toolset for visual novels."
    settings = "os", "compiler", "build_type", "arch"
    requires = [
        ("libsndfile/1.0.30"),
        ("openal/1.21.1"),
    ]
    generators = "cmake_find_package", "cmake_paths"
    options = {
        "documentation": [True, False],
        "buildtests": [True, False],
        "buildsamples": [True, False],
        "buildinterop": [True, False]
    }
    default_options = {
        "libsndfile:shared":True,
        "openal:shared":True,
        "flac:shared":True,
        "Opus:shared":True,
        "Ogg:shared":True,
        "Vorbis:shared":True,
        "documentation": False,
        "buildtests":True,
        "buildsamples":True,
        "buildinterop":True
    }
    cmake = None

    def imports(self):
        if self.settings.os == "Windows":
            self.copy("*.dll", dst="thirdparty", src="bin")
            self.copy("*.dll", dst="thirdparty", src="lib")
        if self.settings.os == "Macos":
            self.copy("*.dylib", dst="thirdparty", src="lib")
    
    def source(self):
        self.run("git clone https://github.com/novelrt/NovelRT.git")

    def configure_cmake(self):
        cmake = CMake(self)
        if(self.options.documentation):
            cmake.definitions["NOVELRT_BUILD_DOCUMENTATION"] = "On"
        else:
            cmake.definitions["NOVELRT_BUILD_DOCUMENTATION"] = "Off"
        if(self.options.buildtests):
            cmake.definitions["NOVELRT_BUILD_TESTS"] = "On"
        else:
            cmake.definitions["NOVELRT_BUILD_TESTS"] = "Off"
        if(self.options.buildsamples):
            cmake.definitions["NOVELRT_BUILD_SAMPLES"] = "On"
        else:
            cmake.definitions["NOVELRT_BUILD_SAMPLES"] = "Off"
        if(self.options.buildinterop):
            cmake.definitions["NOVELRT_BUILD_INTEROP"] = "On"
        else:
            cmake.definitions["NOVELRT_BUILD_INTEROP"] = "Off"
        cmake.configure()
        return cmake

    def build(self):
        self.cmake = self.configure_cmake()
        self.cmake.build()
        if(self.options.buildtests):
            self.cmake.test()

