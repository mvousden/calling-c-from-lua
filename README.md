Here's my attempt at calling a C function from Lua. Inspired by the tutorial at
http://www.troubleshooters.com/codecorn/lua/lua_lua_calls_c.htm by Steve Litt.

Motivation
----------

Compared with Lua, C executes more quickly, but takes longer to write. Wouldn't
it be great if we could write the interface and the majority of the logic for a
project in a language like Lua, and develop the performant components in C?

Structure
---------

 - pure_c.c is pure C that we will call from Lua. This C source file can be
   compiled independently of Lua.

 - lua_glue.c is the glue between C and Lua.

 - build.sh compiles the glue as a shared object file that can be "required" by
   Lua.

 - pure_lua.lua demonstrates the function written in C.

Requirements
------------

 - Lua 5.2 (I installed liblua-5.2 and lua5.2 using apt on Ubuntu 14.04
   GNU/Linux)

 - gcc
