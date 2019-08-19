#!/user/bin/env python3
###################################################################################
#                                                                                 #
# NAME: conanfile.py                                                              #
#                                                                                 #
# AUTHOR: Michael Brockus.                                                        #
#                                                                                 #
# CONTACT: <mailto:michael@squidfarts.com>                                        #
#                                                                                 #
# NOTICES:                                                                        #
#                                                                                 #
# License: Apache 2.0 :http://www.apache.org/licenses/LICENSE-2.0                 #
#                                                                                 #
###################################################################################
from conans import ConanFile, Meson, tools
import os



class PackageConan(ConanFile):
    name = 'sqdlist'
    version = '0.1.0'
    license = 'Apache-2.0'
    author = '<Michael Brockus> <mailto:michael@squidfarts.com>'
    url = 'https://github.com/squidfarts/sqdlist.git'
    description = 'List colletion by Squidfarts.'
    topics = ('conan-recipe', 'mesonbuild', 'c11')
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'pkg_config'
    
    def build(self):
        meson = Meson(self)
        meson.configure()
        meson.build()
    # end of method build

    def package(self):
        self.copy('*.h', dst='lib', src='lib')
        self.copy('*sqdlist.lib', dst='lib', keep_path=False)
        self.copy('*.dll', dst='bin', keep_path=False)
        self.copy('*.so', dst='lib', keep_path=False)
        self.copy('*.dylib', dst='lib', keep_path=False)
        self.copy('*.a', dst='lib', keep_path=False)
    # end of method package
    
    def package_info(self):
        self.cpp_info.libs = ['sqdlist']
    # end of method package_info

    def configure(self):
        del self.settings.compiler.libcxx
    # end of method configure

# end of conanfile class
