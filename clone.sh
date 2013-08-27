#!/bin/bash

TARGET=protobuf/
PROTOBUFSRC=protobuf-2.5.0/

if [ ! -e protobuf-ios ]; then
	git clone https://github.com/axet/protobuf-ios
fi

if [ ! -e $PROTOBUFSRC ]; then
  svn export http://protobuf.googlecode.com/svn/tags/2.5.0 $PROTOBUFSRC || exit 1
fi

if [ ! -e $PROTOBUFSRC/configure ]; then
  (cd $PROTOBUFSRC && ./autogen.sh) || exit 1
fi

if [ ! -e $TARGET ]; then
  (cd $PROTOBUFSRC && ./configure CC="clang -std=gnu99" CXX="clang++ -std=gnu++11 -stdlib=libc++" CXXFLAGS="-O3" --prefix=$(pwd)/../$TARGET) || exit 1
  (cd $PROTOBUFSRC && make install) || exit 1
fi

if [ ! -e $PROTOBUFSRC/protobuf.podspec ]; then
	cp protobuf-ios/protobuf.podspec $PROTOBUFSRC || exit 1 
fi