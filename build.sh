mkdir build
meson . build -Db_coverage=true
cd build
ninja

ninja doc
