#!/usr/sh
rm -rf cryptopp-CRYPTOPP_8_7_0
wget https://github.com/weidai11/cryptopp/archive/refs/tags/CRYPTOPP_8_7_0.zip
unzip CRYPTOPP_8_7_0.zip
rm -rf CRYPTOPP_8_7_0.zip
cd cryptopp-CRYPTOPP_8_7_0
make
mkdir deps
make DESTDIR=$(pwd)/deps install