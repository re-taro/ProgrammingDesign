#!/bin/sh

options="-std=c++11"

while test "$1" != ""; do
  case "$1" in
    -W) options="$options -Wall -Wextra -Wconversion -Winit-self -Wmissing-include-dirs -Wnon-virtual-dtor -Wswitch-default" ;;
    -F) options="$options -O2" ;;
    -*) options="$options $1" ;;
    *) break ;;
  esac
  shift
done

filename=${1%.*}

shift
args="$@"

g++ $options $filename.cpp && ./a.out $args