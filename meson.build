project('nfloppy', 'cpp',
  version: '0.0.1',
  meson_version: '>=1.1.0',
  license: 'MIT',
  license_files: 'LICENSE',
  default_options: [
    'cpp_std=c++20',
    'buildtype=debug',
    'default_library=static',
    'warning_level=everything',
])


cpp = meson.get_compiler('cpp')
warning_flags = [
  '-Wfloat-equal',
  '-Wundef',
  '-Wshadow',
  '-Wpointer-arith',
  '-Wcast-align',
  '-Wwrite-strings',
  '-Wcast-qual',
  '-Wswitch-default',
  '-Wswitch-enum',
  '-Wconversion',
  '-Wformat=2',
  '-Wpedantic',
  '-Wformat-security',
  '-Wtype-limits',
  '-Wunused-result',
  '-Wvariadic-macros',
  '-Wno-format-extra-args',
  '-Wno-padded',
  '-Wno-missing-declarations',
  '-Wnon-virtual-dtor',  
  '-pedantic',
  '-Wold-style-cast',
  '-Woverloaded-virtual',
  '-Wconversion',
  '-Wnull-dereference',
  '-Wdouble-promotion',
  '-Weffc++',
  '-Wno-c++98-compat',
  '-Wno-abi-tag',
  '-Wno-suggest-attribute=const',
  '-Wno-multiple-inheritance',
]

add_project_arguments(cpp.get_supported_arguments(warning_flags), language: 'cpp')
incdir = include_directories('include')

subdir('src')

cmake = import('cmake')

sdl2 = cmake.subproject('sdl2').dependency('SDL2-static')
sdl2_ttf = cmake.subproject('sdl2-ttf').dependency('SDL2_ttf')
sdl2_image = cmake.subproject('sdl2-image').dependency('SDL2_image')


executable('nfloppy', src,
          include_directories: incdir,
          dependencies: [sdl2, sdl2_ttf, sdl2_image])
