function generate()
{
  cmake -G "Unix Makefiles" ..

}

      mkdir travis-build \
      && generate \
      && make \
