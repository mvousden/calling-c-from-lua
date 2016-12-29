#!/usr/bin/lua

-- This Lua source file import a shared object file compiled from C code, and
-- calls a function defined therein.

require("c_to_lua")
say_hello_from_c()
