#! /bin/sh
# convert a texinfo dvi file into laserjet3
# ---------------------------------------------------------------------------
run()
{
  echo "dtdvt2lj.sh: $@"
  eval "$@"
}
# ---------------------------------------------------------------------------

run dvilj $1.dvt
