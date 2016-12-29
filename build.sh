#!/bin/bash

# This Bash script compiles some C to an executable using gcc, and some C to a
# shared object library for use with Lua.
gcc -Wall -o pure_c pure_c.c
gcc -Wall -shared -fPIC -o c_to_lua.so -I/usr/include/lua5.2 -llua5.2 lua_glue.c
