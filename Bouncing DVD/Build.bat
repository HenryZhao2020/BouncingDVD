@echo off
mkdir "Build"
cd "Build"
qmake "../BouncingDVD.pro"
mingw32-make
"release/Bouncing DVD"