project('nfloppy', 'cpp',
  version: '0.0.1',
  meson_version: '>=1.1.0',
  default_options: [
    'warning_level=everything',
    'cpp_std=c++20',
    'buildtype=debug',
    'optimization=0',
    'b_lundef=false',
    'default_library=static',
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

sdl2_dep = dependency('sdl2')

executable('nfloppy', src,
          include_directories: incdir,
          dependencies: sdl2_dep)
