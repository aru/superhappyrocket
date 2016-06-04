function generate()
{
  cmake -G "Unix Makefiles" ..
}

  mkdir travis-build \
  cd travis-build    \
  && generate        \
  && make            \
