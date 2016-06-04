function generate()
{
  cmake -G "Unix Makefiles"
}

  mkdir build     \
  cd build        \
  generate        \
  && make         \
