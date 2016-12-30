/* This C source file takes the functions in pure_c.c, and can be compiled to
   create a shared object file that can be used in Lua. */

#include "pure_c.c"
#include <lauxlib.h>
#include <lualib.h>
#include <lua.h>
#include <stdlib.h>

/* These glue integer functions take a lua_State, and return the number of
   values returned. The function lua_pushnumber is used to return values. */

int glue_say_hello_from_c(lua_State* L)
{
    say_hello_from_c();
    return 0;
}

int glue_norm(lua_State* L)
{
    double returnValue;
    double* components;
    int count;
    int index;

    /* Parse the input array into a form C can understand. */
    count = lua_gettop(L);
    components = calloc(count, sizeof(double));
    for(index=0; index<count; index++)
    {
        components[index] = lua_tonumber(L, lua_gettop(L));
        lua_pop(L, 1);
    }

    /* Compute the norm, push it, and return. */
    returnValue = norm(components, count);
    lua_pushnumber(L, returnValue);
    return 1;
}

/* Now we register the functions with Lua. Presumably there's a better way of
   automating this. This function is called by Lua when this module is
   required. */

int luaopen_c_to_lua(lua_State* L)
{
    /* This register function "adds" a function to the library we create. */
    lua_register(L, "say_hello_from_c", glue_say_hello_from_c);
    lua_register(L, "norm", glue_norm);
    return 0;
}
