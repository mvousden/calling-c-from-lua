#!/bin/bash

gcc -Wall -shared -fPIC -o c_to_lua.so -I/usr/include/lua5.2 -llua5.2 lua_glue.c
