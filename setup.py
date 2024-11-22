import os
import subprocess
import sys
from pathlib import Path
import pybind11

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

import amulet_test1


# https://github.com/pybind/cmake_example/blob/master/setup.py
class CMakeExtension(Extension):
    def __init__(self, name: str, sourcedir: str = "") -> None:
        super().__init__(name, sources=[])
        self.sourcedir = os.fspath(Path(sourcedir).resolve())


class CMakeBuild(build_ext):
    def build_extension(self, ext):
        ext_fullpath = Path.cwd() / self.get_ext_fullpath("")
        src_dir = ext_fullpath.parent.resolve()

        platform_args = []
        if sys.platform == "win32":
            platform_args.extend(["-G", "Visual Studio 17 2022"])
            if sys.maxsize > 2 ** 32:
                platform_args.extend(["-A", "x64"])
            else:
                platform_args.extend(["-A", "Win32"])
            platform_args.extend(["-T", "v143"])

        subprocess.run([
            "cmake",
            *platform_args,
            f"-DPYTHON_EXECUTABLE={sys.executable}",
            f"-Dpybind11_DIR={pybind11.get_cmake_dir().replace(os.sep, '/')}",
            f'-Damulet_test1_DIR={amulet_test1.__path__[0]}',
            f"-DCMAKE_INSTALL_PREFIX=install",
            f'-DSRC_INSTALL_DIR={src_dir}',
            '-B', 'build',
        ])
        subprocess.run(["cmake", "--build", "build", "--config", "Release"])
        subprocess.run(["cmake", "--install", "build", "--config", "Release"])

        # TODO: Add .0 to compiled dependency versions


setup(
    cmdclass={"build_ext": CMakeBuild},
    ext_modules=[CMakeExtension("amulet_test2._amulet_test2")],
)
