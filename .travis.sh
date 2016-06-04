function generate()
{
  cmake -G "Unix Makefiles" ..
}

  cd build        \
  generate        \
  && make         \
