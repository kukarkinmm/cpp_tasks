executable(
    'merge',
    include_directories: src,
    sources: 'main.cpp',
    link_args: '-pthread'
)

configure_file(input : 'plotting.py',
               output : 'plotting.py',
               copy : true)
