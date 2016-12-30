#!/usr/bin/lua

-- This Lua source file import a shared object file compiled from C code, and
-- calls a function defined therein.

require("c_to_lua")
require("io")

say_hello_from_c()
io.write("The norm of [0.1, 0.2, 0.3, 0.4, 0.5] is " ..
            norm(0.1, 0.2, 0.3, 0.4, 0.5) .. "\n")
io.write("The norm of [-1, -0.01, -0.01] is " ..
            norm(-1, -0.01, -0.01) .. "\n")
