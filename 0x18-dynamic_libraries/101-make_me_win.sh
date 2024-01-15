#!/bin/bash
wget -P /tmp https://github.com/amedoeyes/alx-low_level_programming/raw/master/0x18-dynamic_libraries/get_rekt.so
export LD_PRELOAD=/tmp/get_rekt.so
