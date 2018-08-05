# IntruderDetection

Detect human object from IPC to identify intruder.

[TOC]

## Installation

### 1.1 Install FFMPEG

>./configure --enable-nonfree --enable-pic --enable-shared --prefix=/usr/local --libdir=/usr/local/lib64

>make && make install

>ldconfig

### 1.2 Install OpenCV

>mkdir build

>cd build

>export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib64/pkgconfig

>cmake -D CMAKE_BUILD_TYPE= -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_OPENGL=ON ..
