/* This C source file takes the functions in pure_c.c, and can be compiled to
   create a shared object file that can be used in Lua. */

#include "pure_c.c"
#include <lauxlib.h>
#include <lualib.h>
#include <lua.h>

/* These glue integer functions take a lua_State, and return the number of
   arguments returned. */

int glue_say_hello_from_c(lua_State* L)
{
    say_hello_from_c();
    return 0;
}

/* Now we register the functions with Lua. Presumably there's a better way of
   automating this. This function is called by Lua when this module is
   required. */

int luaopen_c_to_lua(lua_State* L)
{
    /* This register function "adds" a function to the library we create. */
    lua_register(L, "say_hello_from_c", glue_say_hello_from_c);
    return 0;
}
