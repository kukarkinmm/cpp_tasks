project(
    'CP_tasks',
    'cpp',
    version: '0.1',
    meson_version: '>=0.46',
    default_options: ['cpp_std=c++14']
)
subdir('src')

doxyfile = configuration_data()
doxyfile.set('./docs', meson.build_root())
configure_file(input: 'Doxyfile.conf',
               output: 'Doxyfile',
               configuration: doxyfile)
doxygen = find_program('doxygen', required : false)
if doxygen.found()
    message('Doxygen found')
    run_target('doc', command: [doxygen, join_paths(meson.build_root(), 'Doxyfile')])
endif