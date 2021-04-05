////////////////////////////////////////////////////////////////////////////////
//    ScopeFun Oscilloscope ( http://www.scopefun.com )
//    Copyright (C) 2016 - 2021 David Košenina
//
//    This file is part of ScopeFun Oscilloscope.
//
//    ScopeFun Oscilloscope is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    ScopeFun Oscilloscope is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this ScopeFun Oscilloscope.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////
standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif

/* -----------------------------------------------------------------------------
 * swigrun.swg
 *
 * This file contains generic C API SWIG runtime support for pointer
 * type checking.
 * ----------------------------------------------------------------------------- */

/* This should only be incremented when either the layout of swig_type_info changes,
   or for whatever reason, the runtime changes incompatibly */
#define SWIG_RUNTIME_VERSION "4"

/* define SWIG_TYPE_TABLE_NAME as "SWIG_TYPE_TABLE" */
#ifdef SWIG_TYPE_TABLE
# define SWIG_QUOTE_STRING(x) #x
# define SWIG_EXPAND_AND_QUOTE_STRING(x) SWIG_QUOTE_STRING(x)
# define SWIG_TYPE_TABLE_NAME SWIG_EXPAND_AND_QUOTE_STRING(SWIG_TYPE_TABLE)
#else
# define SWIG_TYPE_TABLE_NAME
#endif

/*
  You can use the SWIGRUNTIME and SWIGRUNTIMEINLINE macros for
  creating a static or dynamic library from the SWIG runtime code.
  In 99.9% of the cases, SWIG just needs to declare them as 'static'.

  But only do this if strictly necessary, ie, if you have problems
  with your compiler or suchlike.
*/

#ifndef SWIGRUNTIME
# define SWIGRUNTIME SWIGINTERN
#endif

#ifndef SWIGRUNTIMEINLINE
# define SWIGRUNTIMEINLINE SWIGRUNTIME SWIGINLINE
#endif

/*  Generic buffer size */
#ifndef SWIG_BUFFER_SIZE
# define SWIG_BUFFER_SIZE 1024
#endif

/* Flags for pointer conversions */
#define SWIG_POINTER_DISOWN        0x1
#define SWIG_CAST_NEW_MEMORY       0x2
#define SWIG_POINTER_NO_NULL       0x4

/* Flags for new pointer objects */
#define SWIG_POINTER_OWN           0x1


/*
   Flags/methods for returning states.

   The SWIG conversion methods, as ConvertPtr, return an integer
   that tells if the conversion was successful or not. And if not,
   an error code can be returned (see swigerrors.swg for the codes).

   Use the following macros/flags to set or process the returning
   states.

   In old versions of SWIG, code such as the following was usually written:

     if (SWIG_ConvertPtr(obj,vptr,ty.flags) != -1) {
       // success code
     } else {
       //fail code
     }

   Now you can be more explicit:

    int res = SWIG_ConvertPtr(obj,vptr,ty.flags);
    if (SWIG_IsOK(res)) {
      // success code
    } else {
      // fail code
    }

   which is the same really, but now you can also do

    Type *ptr;
    int res = SWIG_ConvertPtr(obj,(void **)(&ptr),ty.flags);
    if (SWIG_IsOK(res)) {
      // success code
      if (SWIG_IsNewObj(res) {
        ...
	delete *ptr;
      } else {
        ...
      }
    } else {
      // fail code
    }

   I.e., now SWIG_ConvertPtr can return new objects and you can
   identify the case and take care of the deallocation. Of course that
   also requires SWIG_ConvertPtr to return new result values, such as

      int SWIG_ConvertPtr(obj, ptr,...) {
        if (<obj is ok>) {
          if (<need new object>) {
            *ptr = <ptr to new allocated object>;
            return SWIG_NEWOBJ;
          } else {
            *ptr = <ptr to old object>;
            return SWIG_OLDOBJ;
          }
        } else {
          return SWIG_BADOBJ;
        }
      }

   Of course, returning the plain '0(success)/-1(fail)' still works, but you can be
   more explicit by returning SWIG_BADOBJ, SWIG_ERROR or any of the
   SWIG errors code.

   Finally, if the SWIG_CASTRANK_MODE is enabled, the result code
   allows to return the 'cast rank', for example, if you have this

       int food(double)
       int fooi(int);

   and you call

      food(1)   // cast rank '1'  (1 -> 1.0)
      fooi(1)   // cast rank '0'

   just use the SWIG_AddCast()/SWIG_CheckState()
*/

#define SWIG_OK                    (0)
#define SWIG_ERROR                 (-1)
#define SWIG_IsOK(r)               (r >= 0)
#define SWIG_ArgError(r)           ((r != SWIG_ERROR) ? r : SWIG_TypeError)

/* The CastRankLimit says how many bits are used for the cast rank */
#define SWIG_CASTRANKLIMIT         (1 << 8)
/* The NewMask denotes the object was created (using new/malloc) */
#define SWIG_NEWOBJMASK            (SWIG_CASTRANKLIMIT  << 1)
/* The TmpMask is for in/out typemaps that use temporal objects */
#define SWIG_TMPOBJMASK            (SWIG_NEWOBJMASK << 1)
/* Simple returning values */
#define SWIG_BADOBJ                (SWIG_ERROR)
#define SWIG_OLDOBJ                (SWIG_OK)
#define SWIG_NEWOBJ                (SWIG_OK | SWIG_NEWOBJMASK)
#define SWIG_TMPOBJ                (SWIG_OK | SWIG_TMPOBJMASK)
/* Check, add and del mask methods */
#define SWIG_AddNewMask(r)         (SWIG_IsOK(r) ? (r | SWIG_NEWOBJMASK) : r)
#define SWIG_DelNewMask(r)         (SWIG_IsOK(r) ? (r & ~SWIG_NEWOBJMASK) : r)
#define SWIG_IsNewObj(r)           (SWIG_IsOK(r) && (r & SWIG_NEWOBJMASK))
#define SWIG_AddTmpMask(r)         (SWIG_IsOK(r) ? (r | SWIG_TMPOBJMASK) : r)
#define SWIG_DelTmpMask(r)         (SWIG_IsOK(r) ? (r & ~SWIG_TMPOBJMASK) : r)
#define SWIG_IsTmpObj(r)           (SWIG_IsOK(r) && (r & SWIG_TMPOBJMASK))

/* Cast-Rank Mode */
#if defined(SWIG_CASTRANK_MODE)
#  ifndef SWIG_TypeRank
#    define SWIG_TypeRank             unsigned long
#  endif
#  ifndef SWIG_MAXCASTRANK            /* Default cast allowed */
#    define SWIG_MAXCASTRANK          (2)
#  endif
#  define SWIG_CASTRANKMASK          ((SWIG_CASTRANKLIMIT) -1)
#  define SWIG_CastRank(r)           (r & SWIG_CASTRANKMASK)
SWIGINTERNINLINE int SWIG_AddCast(int r) {
  return SWIG_IsOK(r) ? ((SWIG_CastRank(r) < SWIG_MAXCASTRANK) ? (r + 1) : SWIG_ERROR) : r;
}
SWIGINTERNINLINE int SWIG_CheckState(int r) {
  return SWIG_IsOK(r) ? SWIG_CastRank(r) + 1 : 0;
}
#else /* no cast-rank mode */
#  define SWIG_AddCast(r) (r)
#  define SWIG_CheckState(r) (SWIG_IsOK(r) ? 1 : 0)
#endif


#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *, int *);
typedef struct swig_type_info *(*swig_dycast_func)(void **);

/* Structure to store information on one type */
typedef struct swig_type_info {
  const char             *name;			/* mangled name of this type */
  const char             *str;			/* human readable name of this type */
  swig_dycast_func        dcast;		/* dynamic cast function down a hierarchy */
  struct swig_cast_info  *cast;			/* linked list of types that can cast into this type */
  void                   *clientdata;		/* language specific type data */
  int                    owndata;		/* flag if the structure owns the clientdata */
} swig_type_info;

/* Structure to store a type and conversion function used for casting */
typedef struct swig_cast_info {
  swig_type_info         *type;			/* pointer to type that is equivalent to this type */
  swig_converter_func     converter;		/* function to cast the void pointers */
  struct swig_cast_info  *next;			/* pointer to next cast in linked list */
  struct swig_cast_info  *prev;			/* pointer to the previous cast */
} swig_cast_info;

/* Structure used to store module information
 * Each module generates one structure like this, and the runtime collects
 * all of these structures and stores them in a circularly linked list.*/
typedef struct swig_module_info {
  swig_type_info         **types;		/* Array of pointers to swig_type_info structures that are in this module */
  size_t                 size;		        /* Number of types in this module */
  struct swig_module_info *next;		/* Pointer to next element in circularly linked list */
  swig_type_info         **type_initial;	/* Array of initially generated type structures */
  swig_cast_info         **cast_initial;	/* Array of initially generated casting structures */
  void                    *clientdata;		/* Language specific module data */
} swig_module_info;

/*
  Compare two type names skipping the space characters, therefore
  "char*" == "char *" and "Class<int>" == "Class<int >", etc.

  Return 0 when the two name types are equivalent, as in
  strncmp, but skipping ' '.
*/
SWIGRUNTIME int
SWIG_TypeNameComp(const char *f1, const char *l1,
		  const char *f2, const char *l2) {
  for (;(f1 != l1) && (f2 != l2); ++f1, ++f2) {
    while ((*f1 == ' ') && (f1 != l1)) ++f1;
    while ((*f2 == ' ') && (f2 != l2)) ++f2;
    if (*f1 != *f2) return (*f1 > *f2) ? 1 : -1;
  }
  return (int)((l1 - f1) - (l2 - f2));
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
  Return 0 if equal, -1 if nb < tb, 1 if nb > tb
*/
SWIGRUNTIME int
SWIG_TypeCmp(const char *nb, const char *tb) {
  int equiv = 1;
  const char* te = tb + strlen(tb);
  const char* ne = nb;
  while (equiv != 0 && *ne) {
    for (nb = ne; *ne; ++ne) {
      if (*ne == '|') break;
    }
    equiv = SWIG_TypeNameComp(nb, ne, tb, te);
    if (*ne) ++ne;
  }
  return equiv;
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
  Return 0 if not equal, 1 if equal
*/
SWIGRUNTIME int
SWIG_TypeEquiv(const char *nb, const char *tb) {
  return SWIG_TypeCmp(nb, tb) == 0 ? 1 : 0;
}

/*
  Check the typename
*/
SWIGRUNTIME swig_cast_info *
SWIG_TypeCheck(const char *c, swig_type_info *ty) {
  if (ty) {
    swig_cast_info *iter = ty->cast;
    while (iter) {
      if (strcmp(iter->type->name, c) == 0) {
        if (iter == ty->cast)
          return iter;
        /* Move iter to the top of the linked list */
        iter->prev->next = iter->next;
        if (iter->next)
          iter->next->prev = iter->prev;
        iter->next = ty->cast;
        iter->prev = 0;
        if (ty->cast) ty->cast->prev = iter;
        ty->cast = iter;
        return iter;
      }
      iter = iter->next;
    }
  }
  return 0;
}

/*
  Identical to SWIG_TypeCheck, except strcmp is replaced with a pointer comparison
*/
SWIGRUNTIME swig_cast_info *
SWIG_TypeCheckStruct(swig_type_info *from, swig_type_info *ty) {
  if (ty) {
    swig_cast_info *iter = ty->cast;
    while (iter) {
      if (iter->type == from) {
        if (iter == ty->cast)
          return iter;
        /* Move iter to the top of the linked list */
        iter->prev->next = iter->next;
        if (iter->next)
          iter->next->prev = iter->prev;
        iter->next = ty->cast;
        iter->prev = 0;
        if (ty->cast) ty->cast->prev = iter;
        ty->cast = iter;
        return iter;
      }
      iter = iter->next;
    }
  }
  return 0;
}

/*
  Cast a pointer up an inheritance hierarchy
*/
SWIGRUNTIMEINLINE void *
SWIG_TypeCast(swig_cast_info *ty, void *ptr, int *newmemory) {
  return ((!ty) || (!ty->converter)) ? ptr : (*ty->converter)(ptr, newmemory);
}

/*
   Dynamic pointer casting. Down an inheritance hierarchy
*/
SWIGRUNTIME swig_type_info *
SWIG_TypeDynamicCast(swig_type_info *ty, void **ptr) {
  swig_type_info *lastty = ty;
  if (!ty || !ty->dcast) return ty;
  while (ty && (ty->dcast)) {
    ty = (*ty->dcast)(ptr);
    if (ty) lastty = ty;
  }
  return lastty;
}

/*
  Return the name associated with this type
*/
SWIGRUNTIMEINLINE const char *
SWIG_TypeName(const swig_type_info *ty) {
  return ty->name;
}

/*
  Return the pretty name associated with this type,
  that is an unmangled type name in a form presentable to the user.
*/
SWIGRUNTIME const char *
SWIG_TypePrettyName(const swig_type_info *type) {
  /* The "str" field contains the equivalent pretty names of the
     type, separated by vertical-bar characters.  We choose
     to print the last name, as it is often (?) the most
     specific. */
  if (!type) return NULL;
  if (type->str != NULL) {
    const char *last_name = type->str;
    const char *s;
    for (s = type->str; *s; s++)
      if (*s == '|') last_name = s+1;
    return last_name;
  }
  else
    return type->name;
}

/*
   Set the clientdata field for a type
*/
SWIGRUNTIME void
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  swig_cast_info *cast = ti->cast;
  /* if (ti->clientdata == clientdata) return; */
  ti->clientdata = clientdata;

  while (cast) {
    if (!cast->converter) {
      swig_type_info *tc = cast->type;
      if (!tc->clientdata) {
	SWIG_TypeClientData(tc, clientdata);
      }
    }
    cast = cast->next;
  }
}
SWIGRUNTIME void
SWIG_TypeNewClientData(swig_type_info *ti, void *clientdata) {
  SWIG_TypeClientData(ti, clientdata);
  ti->owndata = 1;
}

/*
  Search for a swig_type_info structure only by mangled name
  Search is a O(log #types)

  We start searching at module start, and finish searching when start == end.
  Note: if start == end at the beginning of the function, we go all the way around
  the circular list.
*/
SWIGRUNTIME swig_type_info *
SWIG_MangledTypeQueryModule(swig_module_info *start,
                            swig_module_info *end,
		            const char *name) {
  swig_module_info *iter = start;
  do {
    if (iter->size) {
      size_t l = 0;
      size_t r = iter->size - 1;
      do {
	/* since l+r >= 0, we can (>> 1) instead (/ 2) */
	size_t i = (l + r) >> 1;
	const char *iname = iter->types[i]->name;
	if (iname) {
	  int compare = strcmp(name, iname);
	  if (compare == 0) {
	    return iter->types[i];
	  } else if (compare < 0) {
	    if (i) {
	      r = i - 1;
	    } else {
	      break;
	    }
	  } else if (compare > 0) {
	    l = i + 1;
	  }
	} else {
	  break; /* should never happen */
	}
      } while (l <= r);
    }
    iter = iter->next;
  } while (iter != end);
  return 0;
}

/*
  Search for a swig_type_info structure for either a mangled name or a human readable name.
  It first searches the mangled names of the types, which is a O(log #types)
  If a type is not found it then searches the human readable names, which is O(#types).

  We start searching at module start, and finish searching when start == end.
  Note: if start == end at the beginning of the function, we go all the way around
  the circular list.
*/
SWIGRUNTIME swig_type_info *
SWIG_TypeQueryModule(swig_module_info *start,
                     swig_module_info *end,
		     const char *name) {
  /* STEP 1: Search the name field using binary search */
  swig_type_info *ret = SWIG_MangledTypeQueryModule(start, end, name);
  if (ret) {
    return ret;
  } else {
    /* STEP 2: If the type hasn't been found, do a complete search
       of the str field (the human readable name) */
    swig_module_info *iter = start;
    do {
      size_t i = 0;
      for (; i < iter->size; ++i) {
	if (iter->types[i]->str && (SWIG_TypeEquiv(iter->types[i]->str, name)))
	  return iter->types[i];
      }
      iter = iter->next;
    } while (iter != end);
  }

  /* neither found a match */
  return 0;
}

/*
   Pack binary data into a string
*/
SWIGRUNTIME char *
SWIG_PackData(char *c, void *ptr, size_t sz) {
  static const char hex[17] = "0123456789abcdef";
  const unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu =  u + sz;
  for (; u != eu; ++u) {
    unsigned char uu = *u;
    *(c++) = hex[(uu & 0xf0) >> 4];
    *(c++) = hex[uu & 0xf];
  }
  return c;
}

/*
   Unpack binary data from a string
*/
SWIGRUNTIME const char *
SWIG_UnpackData(const char *c, void *ptr, size_t sz) {
  unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu = u + sz;
  for (; u != eu; ++u) {
    char d = *(c++);
    unsigned char uu;
    if ((d >= '0') && (d <= '9'))
      uu = (unsigned char)((d - '0') << 4);
    else if ((d >= 'a') && (d <= 'f'))
      uu = (unsigned char)((d - ('a'-10)) << 4);
    else
      return (char *) 0;
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu |= (unsigned char)(d - '0');
    else if ((d >= 'a') && (d <= 'f'))
      uu |= (unsigned char)(d - ('a'-10));
    else
      return (char *) 0;
    *u = uu;
  }
  return c;
}

/*
   Pack 'void *' into a string buffer.
*/
SWIGRUNTIME char *
SWIG_PackVoidPtr(char *buff, void *ptr, const char *name, size_t bsz) {
  char *r = buff;
  if ((2*sizeof(void *) + 2) > bsz) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,&ptr,sizeof(void *));
  if (strlen(name) + 1 > (bsz - (r - buff))) return 0;
  strcpy(r,name);
  return buff;
}

SWIGRUNTIME const char *
SWIG_UnpackVoidPtr(const char *c, void **ptr, const char *name) {
  if (*c != '_') {
    if (strcmp(c,"NULL") == 0) {
      *ptr = (void *) 0;
      return name;
    } else {
      return 0;
    }
  }
  return SWIG_UnpackData(++c,ptr,sizeof(void *));
}

SWIGRUNTIME char *
SWIG_PackDataName(char *buff, void *ptr, size_t sz, const char *name, size_t bsz) {
  char *r = buff;
  size_t lname = (name ? strlen(name) : 0);
  if ((2*sz + 2 + lname) > bsz) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,ptr,sz);
  if (lname) {
    strncpy(r,name,lname+1);
  } else {
    *r = 0;
  }
  return buff;
}

SWIGRUNTIME const char *
SWIG_UnpackDataName(const char *c, void *ptr, size_t sz, const char *name) {
  if (*c != '_') {
    if (strcmp(c,"NULL") == 0) {
      memset(ptr,0,sz);
      return name;
    } else {
      return 0;
    }
  }
  return SWIG_UnpackData(++c,ptr,sz);
}

#ifdef __cplusplus
}
#endif

/*  Errors in SWIG */
#define  SWIG_UnknownError    	   -1
#define  SWIG_IOError        	   -2
#define  SWIG_RuntimeError   	   -3
#define  SWIG_IndexError     	   -4
#define  SWIG_TypeError      	   -5
#define  SWIG_DivisionByZero 	   -6
#define  SWIG_OverflowError  	   -7
#define  SWIG_SyntaxError    	   -8
#define  SWIG_ValueError     	   -9
#define  SWIG_SystemError    	   -10
#define  SWIG_AttributeError 	   -11
#define  SWIG_MemoryError    	   -12
#define  SWIG_NullReferenceError   -13



/* -----------------------------------------------------------------------------
 * luarun.swg
 *
 * This file contains the runtime support for Lua modules
 * and includes code for managing global variables and pointer
 * type checking.
 * ----------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

#include "lua.h"
#include "lauxlib.h"
#include <stdlib.h>  /* for malloc */
#include <assert.h>  /* for a few sanity tests */

/* -----------------------------------------------------------------------------
 * Lua flavors
 * ----------------------------------------------------------------------------- */

#define SWIG_LUA_FLAVOR_LUA 1
#define SWIG_LUA_FLAVOR_ELUA 2
#define SWIG_LUA_FLAVOR_ELUAC 3

#if !defined(SWIG_LUA_TARGET)
# error SWIG_LUA_TARGET not defined
#endif

#if defined(SWIG_LUA_ELUA_EMULATE)

struct swig_elua_entry;

typedef struct swig_elua_key {
  int type;
  union {
    const char* strkey;
    lua_Number numkey;
  } key;
} swig_elua_key;

typedef struct swig_elua_val {
  int type;
  union {
    lua_Number number;
    const struct swig_elua_entry *table;
    const char *string;
    lua_CFunction function;
    struct {
      char member;
      long lvalue;
      void *pvalue;
      swig_type_info **ptype;
    } userdata;
  } value;
} swig_elua_val;

typedef struct swig_elua_entry {
  swig_elua_key key;
  swig_elua_val value;
} swig_elua_entry;

#define LSTRKEY(x) {LUA_TSTRING, {.strkey = x} }
#define LNUMKEY(x) {LUA_TNUMBER, {.numkey = x} }
#define LNILKEY {LUA_TNIL, {.strkey = 0} }

#define LNUMVAL(x) {LUA_TNUMBER, {.number = x} }
#define LFUNCVAL(x) {LUA_TFUNCTION, {.function = x} }
#define LROVAL(x) {LUA_TTABLE, {.table = x} }
#define LNILVAL {LUA_TNIL, {.string = 0} }
#define LSTRVAL(x) {LUA_TSTRING, {.string = x} }

#define LUA_REG_TYPE swig_elua_entry

#define SWIG_LUA_ELUA_EMUL_METATABLE_KEY "__metatable"

#define lua_pushrotable(L,p)\
  lua_newtable(L);\
  assert(p);\
  SWIG_Lua_elua_emulate_register(L,(swig_elua_entry*)(p));

#define SWIG_LUA_CONSTTAB_POINTER(B,C,D)\
  LSTRKEY(B), {LUA_TUSERDATA, { .userdata={0,0,(void*)(C),&D} } }

#define SWIG_LUA_CONSTTAB_BINARY(B,S,C,D)\
  LSTRKEY(B), {LUA_TUSERDATA, { .userdata={1,S,(void*)(C),&D} } }
#endif

#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUA) || (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUAC)
#  define SWIG_LUA_CONSTTAB_INT(B, C) LSTRKEY(B), LNUMVAL(C)
#  define SWIG_LUA_CONSTTAB_FLOAT(B, C) LSTRKEY(B), LNUMVAL(C)
#  define SWIG_LUA_CONSTTAB_STRING(B, C) LSTRKEY(B), LSTRVAL(C)
#  define SWIG_LUA_CONSTTAB_CHAR(B, C) LSTRKEY(B), LNUMVAL(C)
    /* Those two types of constants are not supported in elua */

#ifndef SWIG_LUA_CONSTTAB_POINTER
#warning eLua does not support pointers as constants. By default, nil will be used as value
#define SWIG_LUA_CONSTTAB_POINTER(B,C,D) LSTRKEY(B), LNILVAL
#endif

#ifndef SWIG_LUA_CONSTTAB_BINARY
#warning eLua does not support pointers to member as constants. By default, nil will be used as value
#define SWIG_LUA_CONSTTAB_BINARY(B, S, C, D) LSTRKEY(B), LNILVAL
#endif
#else /* SWIG_LUA_FLAVOR_LUA */
#  define SWIG_LUA_CONSTTAB_INT(B, C) SWIG_LUA_INT, (char *)B, (long)C, 0, 0, 0
#  define SWIG_LUA_CONSTTAB_FLOAT(B, C) SWIG_LUA_FLOAT, (char *)B, 0, (double)C, 0, 0
#  define SWIG_LUA_CONSTTAB_STRING(B, C) SWIG_LUA_STRING, (char *)B, 0, 0, (void *)C, 0
#  define SWIG_LUA_CONSTTAB_CHAR(B, C) SWIG_LUA_CHAR, (char *)B, (long)C, 0, 0, 0
#  define SWIG_LUA_CONSTTAB_POINTER(B,C,D)\
       SWIG_LUA_POINTER, (char *)B, 0, 0, (void *)C, &D
#  define SWIG_LUA_CONSTTAB_BINARY(B, S, C, D)\
       SWIG_LUA_BINARY,  (char *)B, S, 0, (void *)C, &D
#endif

#ifndef SWIG_LUA_ELUA_EMULATE
#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUA) || (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUAC)
#  define LRO_STRVAL(v) {{.p = (char *) v}, LUA_TSTRING}
#  define LSTRVAL LRO_STRVAL
#endif
#endif /* SWIG_LUA_ELUA_EMULATE*/

#ifndef SWIG_LUA_ELUA_EMULATE
#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUA) || (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUAC)

#ifndef MIN_OPT_LEVEL
#define MIN_OPT_LEVEL 2
#endif

#include "lrodefs.h"
#include "lrotable.h"
#endif
#endif /* SWIG_LUA_ELUA_EMULATE*/
/* -----------------------------------------------------------------------------
 * compatibility defines
 * ----------------------------------------------------------------------------- */

/* History of Lua C API length functions:  In Lua 5.0 (and before?)
   there was "lua_strlen".  In Lua 5.1, this was renamed "lua_objlen",
   but a compatibility define of "lua_strlen" was added.  In Lua 5.2,
   this function was again renamed, to "lua_rawlen" (to emphasize that
   it doesn't call the "__len" metamethod), and the compatibility
   define of lua_strlen was removed.  All SWIG uses have been updated
   to "lua_rawlen", and we add our own defines of that here for older
   versions of Lua.  */
#if !defined(LUA_VERSION_NUM) || LUA_VERSION_NUM < 501
# define lua_rawlen lua_strlen
#elif LUA_VERSION_NUM == 501
# define lua_rawlen lua_objlen
#endif


/* lua_pushglobaltable is the recommended "future-proof" way to get
   the global table for Lua 5.2 and later.  Here we define
   lua_pushglobaltable ourselves for Lua versions before 5.2.  */
#if !defined(LUA_VERSION_NUM) || LUA_VERSION_NUM < 502
# define lua_pushglobaltable(L) lua_pushvalue(L, LUA_GLOBALSINDEX)
#endif

/* lua_absindex was introduced in Lua 5.2 */
#if !defined(LUA_VERSION_NUM) || LUA_VERSION_NUM < 502
# define lua_absindex(L,i) ((i)>0 || (i) <= LUA_REGISTRYINDEX ? (i) : lua_gettop(L) + (i) + 1)
#endif

/* lua_rawsetp was introduced in Lua 5.2 */
#if !defined(LUA_VERSION_NUM) || LUA_VERSION_NUM < 502
#define lua_rawsetp(L,index,ptr)\
  lua_pushlightuserdata(L,(void*)(ptr));\
  lua_insert(L,-2);\
  lua_rawset(L,index);

#define lua_rawgetp(L,index,ptr)\
  lua_pushlightuserdata(L,(void*)(ptr));\
  lua_rawget(L,index);

#endif

/* --------------------------------------------------------------------------
 * Helper functions for error handling
 * -------------------------------------------------------------------------- */

/* Push the string STR on the Lua stack, like lua_pushstring, but
   prefixed with the location of the innermost Lua call-point
   (as formatted by luaL_where).  */
SWIGRUNTIME void
SWIG_Lua_pusherrstring (lua_State *L, const char *str)
{
  luaL_where (L, 1);
  lua_pushstring (L, str);
  lua_concat (L, 2);
}

/* Push a formatted string generated from FMT and following args on
   the Lua stack, like lua_pushfstring, but prefixed with the
   location of the innermost Lua call-point (as formatted by luaL_where).  */
SWIGRUNTIME void
SWIG_Lua_pushferrstring (lua_State *L, const char *fmt, ...)
{
  va_list argp;
  va_start(argp, fmt);
  luaL_where(L, 1);
  lua_pushvfstring(L, fmt, argp);
  va_end(argp);
  lua_concat(L, 2);
}


/* -----------------------------------------------------------------------------
 * global swig types
 * ----------------------------------------------------------------------------- */
/* Constant table */
#define SWIG_LUA_INT     1
#define SWIG_LUA_FLOAT   2
#define SWIG_LUA_STRING  3
#define SWIG_LUA_POINTER 4
#define SWIG_LUA_BINARY  5
#define SWIG_LUA_CHAR    6

/* Structure for variable linking table */
typedef struct {
  const char *name;
  lua_CFunction get;
  lua_CFunction set;
} swig_lua_var_info;

#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUA) || (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUAC)
typedef const LUA_REG_TYPE swig_lua_method;
typedef const LUA_REG_TYPE swig_lua_const_info;
#else /* Normal lua */
typedef luaL_Reg swig_lua_method;

/* Constant information structure */
typedef struct {
    int type;
    char *name;
    long lvalue;
    double dvalue;
    void   *pvalue;
    swig_type_info **ptype;
} swig_lua_const_info;

#endif

typedef struct {
  const char     *name;
  lua_CFunction   getmethod;
  lua_CFunction   setmethod;
} swig_lua_attribute;


struct swig_lua_class;
/* Can be used to create namespaces. Currently used to wrap class static methods/variables/constants */
typedef struct swig_lua_namespace {
  const char            *name;
  swig_lua_method       *ns_methods;
  swig_lua_attribute    *ns_attributes;
  swig_lua_const_info   *ns_constants;
  struct swig_lua_class        **ns_classes;
  struct swig_lua_namespace    **ns_namespaces;
} swig_lua_namespace;

typedef struct swig_lua_class {
  const char    *name; /* Name that this class has in Lua */
  const char    *fqname; /* Fully qualified name - Scope + class name */
  swig_type_info   **type;
  lua_CFunction  constructor;
  void    (*destructor)(void *);
  swig_lua_method   *methods;
  swig_lua_attribute     *attributes;
  swig_lua_namespace    *cls_static;
  swig_lua_method   *metatable; /* 0 for -eluac */
  struct swig_lua_class **bases;
  const char **base_names;
} swig_lua_class;

/* this is the struct for wrapping all pointers in SwigLua
*/
typedef struct {
  swig_type_info   *type;
  int     own;  /* 1 if owned & must be destroyed */
  void        *ptr;
} swig_lua_userdata;

/* this is the struct for wrapping arbitrary packed binary data
(currently it is only used for member function pointers)
the data ordering is similar to swig_lua_userdata, but it is currently not possible
to tell the two structures apart within SWIG, other than by looking at the type
*/
typedef struct {
  swig_type_info   *type;
  int     own;  /* 1 if owned & must be destroyed */
  char data[1];       /* arbitrary amount of data */
} swig_lua_rawdata;

/* Common SWIG API */
#define SWIG_NewPointerObj(L, ptr, type, owner)       SWIG_Lua_NewPointerObj(L, (void *)ptr, type, owner)
#define SWIG_ConvertPtr(L,idx, ptr, type, flags)    SWIG_Lua_ConvertPtr(L,idx,ptr,type,flags)
#define SWIG_MustGetPtr(L,idx, type,flags, argnum,fnname)  SWIG_Lua_MustGetPtr(L,idx, type,flags, argnum,fnname)
/* for C++ member pointers, ie, member methods */
#define SWIG_ConvertMember(L, idx, ptr, sz, ty)       SWIG_Lua_ConvertPacked(L, idx, ptr, sz, ty)
#define SWIG_NewMemberObj(L, ptr, sz, type)      SWIG_Lua_NewPackedObj(L, ptr, sz, type)

/* Runtime API */
#define SWIG_GetModule(clientdata) SWIG_Lua_GetModule((lua_State*)(clientdata))
#define SWIG_SetModule(clientdata, pointer) SWIG_Lua_SetModule((lua_State*) (clientdata), pointer)
#define SWIG_MODULE_CLIENTDATA_TYPE lua_State*

/* Contract support */
#define SWIG_contract_assert(expr, msg)  \
  if (!(expr)) { SWIG_Lua_pusherrstring(L, (char *) msg); goto fail; } else


/* helper #defines */
#define SWIG_fail {goto fail;}
#define SWIG_fail_arg(func_name,argnum,type) \
  {SWIG_Lua_pushferrstring(L,"Error in %s (arg %d), expected '%s' got '%s'",\
  func_name,argnum,type,SWIG_Lua_typename(L,argnum));\
  goto fail;}
#define SWIG_fail_ptr(func_name,argnum,type) \
  SWIG_fail_arg(func_name,argnum,(type && type->str)?type->str:"void*")
#define SWIG_check_num_args(func_name,a,b) \
  if (lua_gettop(L)<a || lua_gettop(L)>b) \
  {SWIG_Lua_pushferrstring(L,"Error in %s expected %d..%d args, got %d",func_name,a,b,lua_gettop(L));\
  goto fail;}


#define SWIG_Lua_get_table(L,n) \
  (lua_pushstring(L, n), lua_rawget(L,-2))

#define SWIG_Lua_add_function(L,n,f) \
  (lua_pushstring(L, n), \
      lua_pushcfunction(L, f), \
      lua_rawset(L,-3))

#define SWIG_Lua_add_boolean(L,n,b) \
  (lua_pushstring(L, n), \
      lua_pushboolean(L, b), \
      lua_rawset(L,-3))

/* special helper for allowing 'nil' for usertypes */
#define SWIG_isptrtype(L,I) (lua_isuserdata(L,I) || lua_isnil(L,I))

#ifdef __cplusplus
/* Special helper for member function pointers
it gets the address, casts it, then dereferences it */
/*#define SWIG_mem_fn_as_voidptr(a)  (*((char**)&(a))) */
#endif

/* storing/access of swig_module_info */
SWIGRUNTIME swig_module_info *
SWIG_Lua_GetModule(lua_State *L) {
  swig_module_info *ret = 0;
  lua_pushstring(L,"swig_runtime_data_type_pointer" SWIG_RUNTIME_VERSION SWIG_TYPE_TABLE_NAME);
  lua_rawget(L,LUA_REGISTRYINDEX);
  if (lua_islightuserdata(L,-1))
    ret=(swig_module_info*)lua_touserdata(L,-1);
  lua_pop(L,1);  /* tidy */
  return ret;
}

SWIGRUNTIME void
SWIG_Lua_SetModule(lua_State *L, swig_module_info *module) {
  /* add this all into the Lua registry: */
  lua_pushstring(L,"swig_runtime_data_type_pointer" SWIG_RUNTIME_VERSION SWIG_TYPE_TABLE_NAME);
  lua_pushlightuserdata(L,(void*)module);
  lua_rawset(L,LUA_REGISTRYINDEX);
}

/* -----------------------------------------------------------------------------
 * global variable support code: modules
 * ----------------------------------------------------------------------------- */

/* this function is called when trying to set an immutable.
default action is to print an error.
This can removed with a compile flag SWIGLUA_IGNORE_SET_IMMUTABLE */
SWIGINTERN int SWIG_Lua_set_immutable(lua_State *L)
{
/*  there should be 1 param passed in: the new value */
#ifndef SWIGLUA_IGNORE_SET_IMMUTABLE
  lua_pop(L,1);  /* remove it */
  luaL_error(L,"This variable is immutable");
#endif
    return 0;   /* should not return anything */
}

#ifdef SWIG_LUA_ELUA_EMULATE

SWIGRUNTIME void SWIG_Lua_NewPointerObj(lua_State *L,void *ptr,swig_type_info *type, int own);
SWIGRUNTIME void SWIG_Lua_NewPackedObj(lua_State *L,void *ptr,size_t size,swig_type_info *type);
static int swig_lua_elua_emulate_unique_key;

/* This function emulates eLua rotables behaviour. It loads a rotable definition into the usual lua table. */
SWIGINTERN void SWIG_Lua_elua_emulate_register(lua_State *L, const swig_elua_entry *table)
{
  int i, table_parsed, parsed_tables_array, target_table;
  assert(lua_istable(L,-1));
  target_table = lua_gettop(L);
  /* Get the registry where we put all parsed tables to avoid loops */
  lua_rawgetp(L, LUA_REGISTRYINDEX, &swig_lua_elua_emulate_unique_key);
  if(lua_isnil(L,-1)) {
    lua_pop(L,1);
    lua_newtable(L);
    lua_pushvalue(L,-1);
    lua_rawsetp(L,LUA_REGISTRYINDEX,(void*)(&swig_lua_elua_emulate_unique_key));
  }
  parsed_tables_array = lua_gettop(L);
  lua_pushvalue(L,target_table);
  lua_rawsetp(L, parsed_tables_array, table);
  table_parsed = 0;
  const int SWIGUNUSED pairs_start = lua_gettop(L);
  for(i = 0;table[i].key.type != LUA_TNIL || table[i].value.type != LUA_TNIL;i++)
  {
    const swig_elua_entry *entry = table + i;
    int is_metatable = 0;
    switch(entry->key.type) {
      case LUA_TSTRING:
        lua_pushstring(L,entry->key.key.strkey);
        if(strcmp(entry->key.key.strkey, SWIG_LUA_ELUA_EMUL_METATABLE_KEY) == 0)
          is_metatable = 1;
        break;
      case  LUA_TNUMBER:
        lua_pushnumber(L,entry->key.key.numkey);
        break;
      case LUA_TNIL:
        lua_pushnil(L);
        break;
      default:
        assert(0);
    }
    switch(entry->value.type) {
      case LUA_TSTRING:
        lua_pushstring(L,entry->value.value.string);
        break;
      case  LUA_TNUMBER:
        lua_pushnumber(L,entry->value.value.number);
        break;
      case LUA_TFUNCTION:
        lua_pushcfunction(L,entry->value.value.function);
        break;
      case LUA_TTABLE:
        lua_rawgetp(L,parsed_tables_array, entry->value.value.table);
        table_parsed = !lua_isnil(L,-1);
        if(!table_parsed) {
          lua_pop(L,1); /*remove nil */
          lua_newtable(L);
          SWIG_Lua_elua_emulate_register(L,entry->value.value.table);
        }
        if(is_metatable) {
          assert(lua_istable(L,-1));
          lua_pushvalue(L,-1);
          lua_setmetatable(L,target_table);
        }

        break;
      case LUA_TUSERDATA:
        if(entry->value.value.userdata.member)
          SWIG_NewMemberObj(L,entry->value.value.userdata.pvalue,
              entry->value.value.userdata.lvalue,
              *(entry->value.value.userdata.ptype));
        else
          SWIG_NewPointerObj(L,entry->value.value.userdata.pvalue,
              *(entry->value.value.userdata.ptype),0);
        break;
      case LUA_TNIL:
        lua_pushnil(L);
        break;
      default:
        assert(0);
    }
    assert(lua_gettop(L) == pairs_start + 2);
    lua_rawset(L,target_table);
  }
  lua_pop(L,1); /* Removing parsed tables storage */
  assert(lua_gettop(L) == target_table);
}

SWIGINTERN void SWIG_Lua_elua_emulate_register_clear(lua_State *L)
{
  lua_pushnil(L);
  lua_rawsetp(L, LUA_REGISTRYINDEX, &swig_lua_elua_emulate_unique_key);
}

SWIGINTERN void SWIG_Lua_get_class_registry(lua_State *L);

SWIGINTERN int SWIG_Lua_emulate_elua_getmetatable(lua_State *L)
{
  SWIG_check_num_args("getmetatable(SWIG eLua emulation)", 1, 1);
  SWIG_Lua_get_class_registry(L);
  lua_getfield(L,-1,"lua_getmetatable");
  lua_remove(L,-2); /* remove the registry*/
  assert(!lua_isnil(L,-1));
  lua_pushvalue(L,1);
  assert(lua_gettop(L) == 3); /* object | function | object again */
  lua_call(L,1,1);
  if(!lua_isnil(L,-1)) /*There is an ordinary metatable */
    return 1;
  /*if it is a table, then emulate elua behaviour - check for __metatable attribute of a table*/
  assert(lua_gettop(L) == 2);
  if(lua_istable(L,-2)) {
    lua_pop(L,1); /*remove the nil*/
    lua_getfield(L,-1, SWIG_LUA_ELUA_EMUL_METATABLE_KEY);
  }
  assert(lua_gettop(L) == 2);
  return 1;

fail:
  lua_error(L);
  return 0;
}

SWIGINTERN void SWIG_Lua_emulate_elua_swap_getmetatable(lua_State *L)
{
  SWIG_Lua_get_class_registry(L);
  lua_pushglobaltable(L);
  lua_pushstring(L,"lua_getmetatable");
  lua_getfield(L,-2,"getmetatable");
  assert(!lua_isnil(L,-1));
  lua_rawset(L,-4);
  lua_pushstring(L, "getmetatable");
  lua_pushcfunction(L, SWIG_Lua_emulate_elua_getmetatable);
  lua_rawset(L,-3);
  lua_pop(L,2);

}
/* END OF REMOVE */

#endif
/* -----------------------------------------------------------------------------
 * global variable support code: namespaces and modules (which are the same thing)
 * ----------------------------------------------------------------------------- */

SWIGINTERN int SWIG_Lua_namespace_get(lua_State *L)
{
/*  there should be 2 params passed in
  (1) table (not the meta table)
  (2) string name of the attribute
*/
  assert(lua_istable(L,-2));  /* just in case */
  lua_getmetatable(L,-2);
  assert(lua_istable(L,-1));
  SWIG_Lua_get_table(L,".get"); /* find the .get table */
  assert(lua_istable(L,-1));
  /* look for the key in the .get table */
  lua_pushvalue(L,2);  /* key */
  lua_rawget(L,-2);
  lua_remove(L,-2); /* stack tidy, remove .get table */
  if (lua_iscfunction(L,-1))
  {  /* found it so call the fn & return its value */
    lua_call(L,0,1);  /* 1 value in (userdata),1 out (result) */
    lua_remove(L,-2); /* stack tidy, remove metatable */
    return 1;
  }
  lua_pop(L,1);  /* remove whatever was there */
  /* ok, so try the .fn table */
  SWIG_Lua_get_table(L,".fn"); /* find the .get table */
  assert(lua_istable(L,-1));  /* just in case */
  lua_pushvalue(L,2);  /* key */
  lua_rawget(L,-2);  /* look for the fn */
  lua_remove(L,-2); /* stack tidy, remove .fn table */
  if (lua_isfunction(L,-1)) /* note: whether it's a C function or lua function */
  {  /* found it so return the fn & let lua call it */
    lua_remove(L,-2); /* stack tidy, remove metatable */
    return 1;
  }
  lua_pop(L,1);  /* remove whatever was there */
  return 0;
}

SWIGINTERN int SWIG_Lua_namespace_set(lua_State *L)
{
/*  there should be 3 params passed in
  (1) table (not the meta table)
  (2) string name of the attribute
  (3) any for the new value
*/

  assert(lua_istable(L,1));
  lua_getmetatable(L,1);    /* get the meta table */
  assert(lua_istable(L,-1));

  SWIG_Lua_get_table(L,".set"); /* find the .set table */
  if (lua_istable(L,-1))
  {
    /* look for the key in the .set table */
    lua_pushvalue(L,2);  /* key */
    lua_rawget(L,-2);
    if (lua_iscfunction(L,-1))
    {  /* found it so call the fn & return its value */
      lua_pushvalue(L,3);  /* value */
      lua_call(L,1,0);
      return 0;
    }
    lua_pop(L,1);  /* remove the value */
  }
  lua_pop(L,1);  /* remove the value .set table */
  lua_pop(L,1); /* remote metatable */
  lua_rawset(L,-3);
  return 0;
}

#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA) /* In elua this is useless */
SWIGINTERN void SWIG_Lua_InstallConstants(lua_State *L, swig_lua_const_info constants[]); /* forward declaration */
SWIGINTERN void  SWIG_Lua_add_variable(lua_State *L,const char *name,lua_CFunction getFn,lua_CFunction setFn); /* forward declaration */
SWIGINTERN void  SWIG_Lua_class_register(lua_State *L,swig_lua_class *clss);

/* helper function - register namespace methods and attributes into namespace */
SWIGINTERN int SWIG_Lua_add_namespace_details(lua_State *L, swig_lua_namespace *ns)
{
  int i;
  /* There must be namespace table (not metatable) at the top of the stack */
  assert(lua_istable(L,-1));
  SWIG_Lua_InstallConstants(L, ns->ns_constants);

  /* add methods to the namespace/module table */
  for(i=0;ns->ns_methods[i].name;i++){
    SWIG_Lua_add_function(L,ns->ns_methods[i].name,ns->ns_methods[i].func);
  }
  lua_getmetatable(L,-1);

  /* add fns */
  for(i=0;ns->ns_attributes[i].name;i++){
    SWIG_Lua_add_variable(L,ns->ns_attributes[i].name,ns->ns_attributes[i].getmethod,ns->ns_attributes[i].setmethod);
  }

  /* clear stack - remove metatble */
  lua_pop(L,1);
  return 0;
}

/* Register all classes in the namespace */
SWIGINTERN void SWIG_Lua_add_namespace_classes(lua_State *L, swig_lua_namespace *ns)
{
  swig_lua_class **classes;

  /* There must be a module/namespace table at the top of the stack */
  assert(lua_istable(L,-1));

  classes = ns->ns_classes;

  if( classes != 0 ) {
    while(*classes != 0) {
      SWIG_Lua_class_register(L, *classes);
      classes++;
    }
  }
}

/* Helper function. Creates namespace table and adds it to module table
   if 'reg' is true, then will register namespace table to parent one (must be on top of the stack
   when function is called).
   Function always returns newly registered table on top of the stack.
*/
SWIGINTERN void SWIG_Lua_namespace_register(lua_State *L, swig_lua_namespace *ns, int reg)
{
  swig_lua_namespace **sub_namespace;
  /* 1 argument - table on the top of the stack */
  const int SWIGUNUSED begin = lua_gettop(L);
  assert(lua_istable(L,-1)); /* just in case. This is supposed to be module table or parent namespace table */
  lua_checkstack(L,5);
  lua_newtable(L); /* namespace itself */
  lua_newtable(L); /* metatable for namespace */

  /* add a table called ".get" */
  lua_pushstring(L,".get");
  lua_newtable(L);
  lua_rawset(L,-3);
  /* add a table called ".set" */
  lua_pushstring(L,".set");
  lua_newtable(L);
  lua_rawset(L,-3);
  /* add a table called ".fn" */
  lua_pushstring(L,".fn");
  lua_newtable(L);
  lua_rawset(L,-3);

  /* add accessor fns for using the .get,.set&.fn */
  SWIG_Lua_add_function(L,"__index",SWIG_Lua_namespace_get);
  SWIG_Lua_add_function(L,"__newindex",SWIG_Lua_namespace_set);

  lua_setmetatable(L,-2); /* set metatable */

  /* Register all functions, variables etc */
  SWIG_Lua_add_namespace_details(L,ns);
  /* Register classes */
  SWIG_Lua_add_namespace_classes(L,ns);

  sub_namespace = ns->ns_namespaces;
  if( sub_namespace != 0) {
    while(*sub_namespace != 0) {
      SWIG_Lua_namespace_register(L, *sub_namespace, 1);
      lua_pop(L,1); /* removing sub-namespace table */
      sub_namespace++;
    }
  }

  if (reg) {
    lua_pushstring(L,ns->name);
    lua_pushvalue(L,-2);
    lua_rawset(L,-4); /* add namespace to module table */
  }
  assert(lua_gettop(L) == begin+1);
}
#endif /* SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA */

/* -----------------------------------------------------------------------------
 * global variable support code: classes
 * ----------------------------------------------------------------------------- */

SWIGINTERN void  SWIG_Lua_get_class_metatable(lua_State *L,const char *cname);

typedef int (*swig_lua_base_iterator_func)(lua_State*,swig_type_info*, int, int *ret);

SWIGINTERN int SWIG_Lua_iterate_bases(lua_State *L, swig_type_info * SWIGUNUSED swig_type,
  int first_arg, swig_lua_base_iterator_func func, int  *const ret)
{
    /* first_arg - position of the object in stack. Everything that is above are arguments
     * and is passed to every evocation of the func */
    int last_arg = lua_gettop(L);/* position of last argument */
    int original_metatable = last_arg + 1;
    size_t bases_count;
    int result = SWIG_ERROR;
    int bases_table;
    (void)swig_type;
    lua_getmetatable(L,first_arg);

    /* initialise base search */
#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA)
    SWIG_Lua_get_table(L,".bases");
    assert(lua_istable(L,-1));
    bases_count = lua_rawlen(L,-1);
    bases_table = lua_gettop(L);
#else
    /* In elua .bases table doesn't exist. Use table from swig_lua_class */
    (void)bases_table;
    assert(swig_type!=0);
    swig_module_info *module=SWIG_GetModule(L);
    swig_lua_class **bases= ((swig_lua_class*)(swig_type->clientdata))->bases;
    const char **base_names= ((swig_lua_class*)(swig_type->clientdata))->base_names;
    bases_count = 0;
    for(;base_names[bases_count];
      bases_count++);/* get length of bases */
#endif

    if(ret)
      *ret = 0;
    if(bases_count>0)
    {
      int to_remove;
      size_t i;
      int j;
      int subcall_last_arg;
      int subcall_first_arg = lua_gettop(L) + 1;/* Here a copy of first_arg and arguments begin */
      int valid = 1;
      swig_type_info *base_swig_type = 0;
      for(j=first_arg;j<=last_arg;j++)
        lua_pushvalue(L,j);
      subcall_last_arg = lua_gettop(L);

      /* Trick: temporarily replacing original metatable with metatable for base class and call getter */
      for(i=0;i<bases_count;i++) {
        /* Iteration through class bases */
#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA)
        lua_rawgeti(L,bases_table,i+1);
        base_swig_type = 0;
        if(lua_isnil(L,-1)) {
          valid = 0;
          lua_pop(L,1);
        } else {
          valid = 1;
        }
#else /* In elua .bases table doesn't exist. Use table from swig_lua_class */
        swig_lua_class *base_class = bases[i];
        if(!base_class) {
          valid = 0;
        } else {
          valid = 1;
          SWIG_Lua_get_class_metatable(L,base_class->fqname);
          base_swig_type = SWIG_TypeQueryModule(module,module,base_names[i]);
          assert(base_swig_type != 0);
        }
#endif

        if(!valid)
          continue;
        assert(lua_isuserdata(L, subcall_first_arg));
        assert(lua_istable(L,-1));
        lua_setmetatable(L,subcall_first_arg); /* Set new metatable */
        assert(lua_gettop(L) == subcall_last_arg);
        result = func(L, base_swig_type,subcall_first_arg, ret); /* Forward call */
        if(result != SWIG_ERROR) {
          break;
        }
      }
      /* Restore original metatable */
      lua_pushvalue(L,original_metatable);
      lua_setmetatable(L,first_arg);
      /* Clear - remove everything between last_arg and subcall_last_arg including */
      to_remove = subcall_last_arg - last_arg;
      for(j=0;j<to_remove;j++)
        lua_remove(L,last_arg+1);
    } else {
      /* Remove everything after last_arg */
      lua_pop(L, lua_gettop(L) - last_arg);
    }
    if(ret) assert(lua_gettop(L) == last_arg + *ret);
    return result;
}

/* The class.get method helper, performs the lookup of class attributes.
 * It returns an error code. Number of function return values is passed inside 'ret'.
 * first_arg is not used in this function because function always has 2 arguments.
 */
SWIGINTERN int  SWIG_Lua_class_do_get_item(lua_State *L, swig_type_info *type, int SWIGUNUSED first_arg, int *ret)
{
/*  there should be 2 params passed in
  (1) userdata (not the meta table)
  (2) string name of the attribute
*/
  int bases_search_result;
  int substack_start = lua_gettop(L)-2;
  assert(first_arg == substack_start+1);
  lua_checkstack(L,5);
  assert(lua_isuserdata(L,-2));  /* just in case */
  lua_getmetatable(L,-2);    /* get the meta table */
  assert(lua_istable(L,-1));  /* just in case */
  /* NEW: looks for the __getitem() fn
  this is a user provided get fn */
  SWIG_Lua_get_table(L,"__getitem"); /* find the __getitem fn */
  if (lua_iscfunction(L,-1))  /* if its there */
  {  /* found it so call the fn & return its value */
    lua_pushvalue(L,substack_start+1);  /* the userdata */
    lua_pushvalue(L,substack_start+2);  /* the parameter */
    lua_call(L,2,1);  /* 2 value in (userdata),1 out (result) */
    lua_remove(L,-2); /* stack tidy, remove metatable */
    if(ret) *ret = 1;
    return SWIG_OK;
  }
  lua_pop(L,1);
  /* Remove the metatable */
  lua_pop(L,1);
  /* Search in base classes */
  bases_search_result = SWIG_Lua_iterate_bases(L,type,substack_start+1,SWIG_Lua_class_do_get_item,ret);
  return bases_search_result;  /* sorry not known */
}


/* The class.get method helper, performs the lookup of class attributes.
 * It returns an error code. Number of function return values is passed inside 'ret'.
 * first_arg is not used in this function because function always has 2 arguments.
 */
SWIGINTERN int  SWIG_Lua_class_do_get(lua_State *L, swig_type_info *type, int SWIGUNUSED first_arg, int *ret)
{
/*  there should be 2 params passed in
  (1) userdata (not the meta table)
  (2) string name of the attribute
*/
  int bases_search_result;
  int substack_start = lua_gettop(L)-2;
  assert(first_arg == substack_start+1);
  lua_checkstack(L,5);
  assert(lua_isuserdata(L,-2));  /* just in case */
  lua_getmetatable(L,-2);    /* get the meta table */
  assert(lua_istable(L,-1));  /* just in case */
  SWIG_Lua_get_table(L,".get"); /* find the .get table */
  assert(lua_istable(L,-1));  /* just in case */
  /* look for the key in the .get table */
  lua_pushvalue(L,substack_start+2);  /* key */
  lua_rawget(L,-2);
  lua_remove(L,-2); /* stack tidy, remove .get table */
  if (lua_iscfunction(L,-1))
  {  /* found it so call the fn & return its value */
    lua_pushvalue(L,substack_start+1);  /* the userdata */
    lua_call(L,1,1);  /* 1 value in (userdata),1 out (result) */
    lua_remove(L,-2); /* stack tidy, remove metatable */
    if(ret)
      *ret = 1;
    return SWIG_OK;
  }
  lua_pop(L,1);  /* remove whatever was there */
  /* ok, so try the .fn table */
  SWIG_Lua_get_table(L,".fn"); /* find the .fn table */
  assert(lua_istable(L,-1));  /* just in case */
  lua_pushvalue(L,substack_start+2);  /* key */
  lua_rawget(L,-2);  /* look for the fn */
  lua_remove(L,-2); /* stack tidy, remove .fn table */
  if (lua_isfunction(L,-1)) /* note: if its a C function or lua function */
  {  /* found it so return the fn & let lua call it */
    lua_remove(L,-2); /* stack tidy, remove metatable */
    if(ret)
      *ret = 1;
    return SWIG_OK;
  }
  lua_pop(L,1);  /* remove whatever was there */
  /* Remove the metatable */
  lua_pop(L,1);
  /* Search in base classes */
  bases_search_result = SWIG_Lua_iterate_bases(L,type,substack_start+1,SWIG_Lua_class_do_get,ret);
  return bases_search_result;  /* sorry not known */
}

/* the class.get method, performs the lookup of class attributes
 */
SWIGINTERN int  SWIG_Lua_class_get(lua_State *L)
{
/*  there should be 2 params passed in
  (1) userdata (not the meta table)
  (2) string name of the attribute
*/
  int result;
  swig_lua_userdata *usr;
  swig_type_info *type;
  int ret = 0;
  assert(lua_isuserdata(L,1));
  usr=(swig_lua_userdata*)lua_touserdata(L,1);  /* get data */
  type = usr->type;
  result = SWIG_Lua_class_do_get(L,type,1,&ret);
  if(result == SWIG_OK)
    return ret;

  result = SWIG_Lua_class_do_get_item(L,type,1,&ret);
  if(result == SWIG_OK)
    return ret;

  return 0;
}

/* helper for the class.set method, performs the lookup of class attributes
 * It returns error code. Number of function return values is passed inside 'ret'
 */
SWIGINTERN int  SWIG_Lua_class_do_set(lua_State *L, swig_type_info *type, int first_arg, int *ret)
{
/*  there should be 3 params passed in
  (1) table (not the meta table)
  (2) string name of the attribute
  (3) any for the new value
  */

  int bases_search_result;
  int substack_start = lua_gettop(L) - 3;
  lua_checkstack(L,5);
  assert(lua_isuserdata(L,substack_start+1));  /* just in case */
  lua_getmetatable(L,substack_start+1);    /* get the meta table */
  assert(lua_istable(L,-1));  /* just in case */
  if(ret)
    *ret = 0; /* it is setter - number of return values is always 0 */

  SWIG_Lua_get_table(L,".set"); /* find the .set table */
  if (lua_istable(L,-1))
  {
    /* look for the key in the .set table */
    lua_pushvalue(L,substack_start+2);  /* key */
    lua_rawget(L,-2);
    lua_remove(L,-2); /* tidy stack, remove .set table */
    if (lua_iscfunction(L,-1))
    {  /* found it so call the fn & return its value */
      lua_pushvalue(L,substack_start+1);  /* userdata */
      lua_pushvalue(L,substack_start+3);  /* value */
      lua_call(L,2,0);
      lua_remove(L,substack_start+4); /*remove metatable*/
      return SWIG_OK;
    }
    lua_pop(L,1);  /* remove the value */
  } else {
    lua_pop(L,1);  /* remove the answer for .set table request*/
  }
  /* NEW: looks for the __setitem() fn
  this is a user provided set fn */
  SWIG_Lua_get_table(L,"__setitem"); /* find the fn */
  if (lua_iscfunction(L,-1))  /* if its there */
  {  /* found it so call the fn & return its value */
    lua_pushvalue(L,substack_start+1);  /* the userdata */
    lua_pushvalue(L,substack_start+2);  /* the parameter */
    lua_pushvalue(L,substack_start+3);  /* the value */
    lua_call(L,3,0);  /* 3 values in ,0 out */
    lua_remove(L,-2); /* stack tidy, remove metatable */
    return SWIG_OK;
  }
  lua_pop(L,1); /* remove value */

  lua_pop(L,1); /* remove metatable */
  /* Search among bases */
  bases_search_result = SWIG_Lua_iterate_bases(L,type,first_arg,SWIG_Lua_class_do_set,ret);
  if(ret)
    assert(*ret == 0);
  assert(lua_gettop(L) == substack_start + 3);
  return bases_search_result;
}

/* This is the actual method exported to Lua. It calls SWIG_Lua_class_do_set and correctly
 * handles return values.
 */
SWIGINTERN int  SWIG_Lua_class_set(lua_State *L)
{
/*  There should be 3 params passed in
  (1) table (not the meta table)
  (2) string name of the attribute
  (3) any for the new value
  */
  int ret = 0;
  int result;
  swig_lua_userdata *usr;
  swig_type_info *type;
  assert(lua_isuserdata(L,1));
  usr=(swig_lua_userdata*)lua_touserdata(L,1);  /* get data */
  type = usr->type;
  result = SWIG_Lua_class_do_set(L,type,1,&ret);
  if(result != SWIG_OK) {
   SWIG_Lua_pushferrstring(L,"Assignment not possible. No setter/member with this name. For custom assignments implement __setitem method.");
   lua_error(L);
  } else {
    assert(ret==0);
  }
  return 0;
}

/* the class.destruct method called by the interpreter */
SWIGINTERN int  SWIG_Lua_class_destruct(lua_State *L)
{
/*  there should be 1 params passed in
  (1) userdata (not the meta table) */
  swig_lua_userdata *usr;
  swig_lua_class *clss;
  assert(lua_isuserdata(L,-1));  /* just in case */
  usr=(swig_lua_userdata*)lua_touserdata(L,-1);  /* get it */
  /* if must be destroyed & has a destructor */
  if (usr->own) /* if must be destroyed */
  {
    clss=(swig_lua_class*)usr->type->clientdata;  /* get the class */
    if (clss && clss->destructor)  /* there is a destroy fn */
    {
      clss->destructor(usr->ptr);  /* bye bye */
    }
  }
  return 0;
}

/* the class.__tostring method called by the interpreter and print */
SWIGINTERN int  SWIG_Lua_class_tostring(lua_State *L)
{
/*  there should be 1 param passed in
  (1) userdata (not the metatable) */
  swig_lua_userdata* userData;
  assert(lua_isuserdata(L,1));  /* just in case */
  userData = (swig_lua_userdata*)lua_touserdata(L,1); /* get the userdata address */

  lua_pushfstring(L, "<userdata of type '%s' at %p>", userData->type->str, userData->ptr);
  return 1;
}

/* to manually disown some userdata */
SWIGINTERN int  SWIG_Lua_class_disown(lua_State *L)
{
/*  there should be 1 params passed in
  (1) userdata (not the meta table) */
  swig_lua_userdata *usr;
  assert(lua_isuserdata(L,-1));  /* just in case */
  usr=(swig_lua_userdata*)lua_touserdata(L,-1);  /* get it */

  usr->own = 0; /* clear our ownership */
  return 0;
}

/* lua callable function to compare userdata's value
the issue is that two userdata may point to the same thing
but to lua, they are different objects */
SWIGRUNTIME int SWIG_Lua_class_equal(lua_State *L)
{
  int result;
  swig_lua_userdata *usr1,*usr2;
  if (!lua_isuserdata(L,1) || !lua_isuserdata(L,2))  /* just in case */
    return 0;  /* nil reply */
  usr1=(swig_lua_userdata*)lua_touserdata(L,1);  /* get data */
  usr2=(swig_lua_userdata*)lua_touserdata(L,2);  /* get data */
  /*result=(usr1->ptr==usr2->ptr && usr1->type==usr2->type); only works if type is the same*/
  result=(usr1->ptr==usr2->ptr);
   lua_pushboolean(L,result);
  return 1;
}

/* populate table at the top of the stack with metamethods that ought to be inherited */
SWIGINTERN void SWIG_Lua_populate_inheritable_metamethods(lua_State *L)
{
  SWIG_Lua_add_boolean(L, "__add", 1);
  SWIG_Lua_add_boolean(L, "__sub", 1);
  SWIG_Lua_add_boolean(L, "__mul", 1);
  SWIG_Lua_add_boolean(L, "__div", 1);
  SWIG_Lua_add_boolean(L, "__mod", 1);
  SWIG_Lua_add_boolean(L, "__pow", 1);
  SWIG_Lua_add_boolean(L, "__unm", 1);
  SWIG_Lua_add_boolean(L, "__len", 1 );
  SWIG_Lua_add_boolean(L, "__concat", 1 );
  SWIG_Lua_add_boolean(L, "__eq", 1);
  SWIG_Lua_add_boolean(L, "__lt", 1);
  SWIG_Lua_add_boolean(L, "__le", 1);
  SWIG_Lua_add_boolean(L, "__call", 1);
  SWIG_Lua_add_boolean(L, "__tostring", 1);
  SWIG_Lua_add_boolean(L, "__gc", 0);
}

/* creates the swig registry */
SWIGINTERN void SWIG_Lua_create_class_registry(lua_State *L)
{
  /* create main SWIG registry table */
  lua_pushstring(L,"SWIG");
  lua_newtable(L);
  /* populate it with some predefined data */

  /* .library table. Placeholder */
  lua_pushstring(L,".library");
  lua_newtable(L);
  {
    /* list of metamethods that class inherits from its bases */
    lua_pushstring(L,"inheritable_metamethods");
    lua_newtable(L);
    /* populate with list of metamethods */
    SWIG_Lua_populate_inheritable_metamethods(L);
    lua_rawset(L,-3);
  }
  lua_rawset(L,-3);

  lua_rawset(L,LUA_REGISTRYINDEX);
}

/* gets the swig registry (or creates it) */
SWIGINTERN void  SWIG_Lua_get_class_registry(lua_State *L)
{
  /* add this all into the swig registry: */
  lua_pushstring(L,"SWIG");
  lua_rawget(L,LUA_REGISTRYINDEX);  /* get the registry */
  if (!lua_istable(L,-1))  /* not there */
  {  /* must be first time, so add it */
    lua_pop(L,1);  /* remove the result */
    SWIG_Lua_create_class_registry(L);
    /* then get it */
    lua_pushstring(L,"SWIG");
    lua_rawget(L,LUA_REGISTRYINDEX);
  }
}

SWIGINTERN void SWIG_Lua_get_inheritable_metamethods(lua_State *L)
{
  SWIG_Lua_get_class_registry(L);
  lua_pushstring(L, ".library");
  lua_rawget(L,-2);
  assert( !lua_isnil(L,-1) );
  lua_pushstring(L, "inheritable_metamethods");
  lua_rawget(L,-2);

  /* Remove class registry and library table */
  lua_remove(L,-2);
  lua_remove(L,-2);
}

/* Helper function to get the classes metatable from the register */
SWIGINTERN void  SWIG_Lua_get_class_metatable(lua_State *L,const char *cname)
{
  SWIG_Lua_get_class_registry(L);  /* get the registry */
  lua_pushstring(L,cname);  /* get the name */
  lua_rawget(L,-2);    /* get it */
  lua_remove(L,-2);    /* tidy up (remove registry) */
}

/* Set up the base classes pointers.
Each class structure has a list of pointers to the base class structures.
This function fills them.
It cannot be done at compile time, as this will not work with hireachies
spread over more than one swig file.
Therefore it must be done at runtime, querying the SWIG type system.
*/
SWIGINTERN void SWIG_Lua_init_base_class(lua_State *L,swig_lua_class *clss)
{
  int i=0;
  swig_module_info *module=SWIG_GetModule(L);
  for(i=0;clss->base_names[i];i++)
  {
    if (clss->bases[i]==0) /* not found yet */
    {
      /* lookup and cache the base class */
      swig_type_info *info = SWIG_TypeQueryModule(module,module,clss->base_names[i]);
      if (info) clss->bases[i] = (swig_lua_class *) info->clientdata;
    }
  }
}

#if defined(SWIG_LUA_SQUASH_BASES) && (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA)
/* Merges two tables  */
SWIGINTERN void SWIG_Lua_merge_tables_by_index(lua_State *L, int target, int source)
{
  /* iterating */
  lua_pushnil(L);
  while (lua_next(L,source) != 0) {
    /* -1 - value, -2 - index */
    /* have to copy to assign */
    lua_pushvalue(L,-2); /* copy of index */
    lua_pushvalue(L,-2); /* copy of value */
    lua_rawset(L, target);
    lua_pop(L,1);
    /* only key is left */
  }
}

/* Merges two tables with given name. original - index of target metatable, base - index of source metatable */
SWIGINTERN void SWIG_Lua_merge_tables(lua_State *L, const char* name, int original, int base)
{
  /* push original[name], then base[name] */
  lua_pushstring(L,name);
  lua_rawget(L,original);
  int original_table = lua_gettop(L);
  lua_pushstring(L,name);
  lua_rawget(L,base);
  int base_table = lua_gettop(L);
  SWIG_Lua_merge_tables_by_index(L, original_table, base_table);
  /* clearing stack */
  lua_pop(L,2);
}

/* Function takes all symbols from base and adds it to derived class. It's just a helper. */
SWIGINTERN void SWIG_Lua_class_squash_base(lua_State *L, swig_lua_class *base_cls)
{
  /* There is one parameter - original, i.e. 'derived' class metatable */
  assert(lua_istable(L,-1));
  int original = lua_gettop(L);
  SWIG_Lua_get_class_metatable(L,base_cls->fqname);
  int base = lua_gettop(L);
  SWIG_Lua_merge_tables(L, ".fn", original, base );
  SWIG_Lua_merge_tables(L, ".set", original, base );
  SWIG_Lua_merge_tables(L, ".get", original, base );
  lua_pop(L,1);
}

/* Function squashes all symbols from 'clss' bases into itself */
SWIGINTERN void  SWIG_Lua_class_squash_bases(lua_State *L, swig_lua_class *clss)
{
  int i;
  SWIG_Lua_get_class_metatable(L,clss->fqname);
  for(i=0;clss->base_names[i];i++)
  {
    if (clss->bases[i]==0) /* Somehow it's not found. Skip it */
      continue;
    /* Thing is: all bases are already registered. Thus they have already executed
     * this function. So we just need to squash them into us, because their bases
     * are already squashed into them. No need for recursion here!
     */
    SWIG_Lua_class_squash_base(L, clss->bases[i]);
  }
  lua_pop(L,1); /*tidy stack*/
}
#endif

#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA) /* In elua this is useless */
/* helper add a variable to a registered class */
SWIGINTERN void  SWIG_Lua_add_variable(lua_State *L,const char *name,lua_CFunction getFn,lua_CFunction setFn)
{
  assert(lua_istable(L,-1));  /* just in case */
  SWIG_Lua_get_table(L,".get"); /* find the .get table */
  assert(lua_istable(L,-1));  /* just in case */
  SWIG_Lua_add_function(L,name,getFn);
  lua_pop(L,1);       /* tidy stack (remove table) */
  if (setFn)
  {
    SWIG_Lua_get_table(L,".set"); /* find the .set table */
    assert(lua_istable(L,-1));  /* just in case */
    SWIG_Lua_add_function(L,name,setFn);
    lua_pop(L,1);       /* tidy stack (remove table) */
  }
}

/* helper to recursively add class static details (static attributes, operations and constants) */
SWIGINTERN void SWIG_Lua_add_class_static_details(lua_State *L, swig_lua_class *clss)
{
  int i = 0;
  /* The class namespace table must be on the top of the stack */
  assert(lua_istable(L,-1));
  /* call all the base classes first: we can then override these later: */
  for(i=0;clss->bases[i];i++)
  {
    SWIG_Lua_add_class_static_details(L,clss->bases[i]);
  }

  SWIG_Lua_add_namespace_details(L, clss->cls_static);
}

SWIGINTERN void SWIG_Lua_add_class_user_metamethods(lua_State *L, swig_lua_class *clss); /* forward declaration */

/* helper to recursively add class details (attributes & operations) */
SWIGINTERN void  SWIG_Lua_add_class_instance_details(lua_State *L, swig_lua_class *clss)
{
  int i;
  size_t bases_count = 0;
  /* Add bases to .bases table */
  SWIG_Lua_get_table(L,".bases");
  assert(lua_istable(L,-1));  /* just in case */
  for(i=0;clss->bases[i];i++)
  {
    SWIG_Lua_get_class_metatable(L,clss->bases[i]->fqname);
    /* Base class must be already registered */
    assert(lua_istable(L,-1));
    lua_rawseti(L,-2,i+1); /* In lua indexing starts from 1 */
    bases_count++;
  }
  assert(lua_rawlen(L,-1) == bases_count);
  lua_pop(L,1); /* remove .bases table */
  /* add attributes */
  for(i=0;clss->attributes[i].name;i++){
    SWIG_Lua_add_variable(L,clss->attributes[i].name,clss->attributes[i].getmethod,clss->attributes[i].setmethod);
  }
  /* add methods to the metatable */
  SWIG_Lua_get_table(L,".fn"); /* find the .fn table */
  assert(lua_istable(L,-1));  /* just in case */
  for(i=0;clss->methods[i].name;i++){
    SWIG_Lua_add_function(L,clss->methods[i].name,clss->methods[i].func);
  }
  lua_pop(L,1);       /* tidy stack (remove table) */
  /* add operator overloads
    This adds methods from metatable array to metatable. Can mess up garbage
    collectind if someone defines __gc method
    */
  if(clss->metatable) {
    for(i=0;clss->metatable[i].name;i++) {
      SWIG_Lua_add_function(L,clss->metatable[i].name,clss->metatable[i].func);
    }
  }

#if !defined(SWIG_LUA_SQUASH_BASES)
  /* Adding metamethods that are defined in base classes. If bases were squashed
   * then it is obviously unnecessary
   */
  SWIG_Lua_add_class_user_metamethods(L, clss);
#endif
}

/* Helpers to add user defined class metamedhods - __add, __sub etc. The helpers are needed
   for the following issue: Lua runtime checks for metamethod existence with rawget function
   ignoring our SWIG-provided __index and __newindex functions. Thus our inheritance-aware method
   search algorithm doesn't work in such case. (Not to say that Lua runtime queries metamethod directly
   in metatable and not in object).
   Current solution is this: if somewhere in hierarchy metamethod __x is defined, then all descendants
   are automatically given a special proxy __x that calls the real __x method.
   Obvious idea - to copy __x instead of creating __x-proxy is wrong because if someone changes __x in runtime,
   those changes must be reflected in all descendants.
*/

SWIGRUNTIME int SWIG_Lua_resolve_metamethod(lua_State *L); /*forward declaration*/

/* The real function that resolves a metamethod.
 * Function searches given class and all it's bases(recursively) for first instance of something that is
 * not equal to SWIG_Lua_resolve_metatmethod. (Almost always this 'something' is actual metamethod implementation
 * and it is a SWIG-generated C function.). It returns value on the top of the L and there is no garbage below the
 * answer.
 * Returns 1 if found, 0 otherwise.
 * clss is class which metatable we will search for method
 * metamethod_name_idx is index in L where metamethod name (as string) lies
 * skip_check allows to skip searching metamethod in givel clss and immideatelly go to searching in bases. skip_check
 * is not caried to subsequent recursive calls - false is always passed. It is set to true only at first call from
 * SWIG_Lua_resolve_metamethod
 * */
SWIGINTERN int SWIG_Lua_do_resolve_metamethod(lua_State *L, const swig_lua_class *clss, int metamethod_name_idx,
    int skip_check)
{
  /* This function is called recursively */
  int result = 0;
  int i = 0;

  if (!skip_check) {
    SWIG_Lua_get_class_metatable(L, clss->fqname);
    lua_pushvalue(L, metamethod_name_idx);
    lua_rawget(L,-2);
    /* If this is cfunction and it is equal to SWIG_Lua_resolve_metamethod then
     * this isn't the function we are looking for :)
     * lua_tocfunction will return NULL if not cfunction
     */
    if (!lua_isnil(L,-1) && lua_tocfunction(L,-1) != SWIG_Lua_resolve_metamethod ) {
      lua_remove(L,-2); /* removing class metatable */
      return 1;
    }
    lua_pop(L,2); /* remove class metatable and query result */
  }

  /* Forwarding calls to bases */
  for(i=0;clss->bases[i];i++)
  {
    result = SWIG_Lua_do_resolve_metamethod(L, clss->bases[i], metamethod_name_idx, 0);
    if (result)
      break;
  }

  return result;
}

/* The proxy function for metamethod. All parameters are passed as cclosure. Searches for actual method
 * and calls it */
SWIGRUNTIME int SWIG_Lua_resolve_metamethod(lua_State *L)
{
  int numargs;
  int metamethod_name_idx;
  const swig_lua_class* clss;
  int result;

  lua_checkstack(L,5);
  numargs = lua_gettop(L); /* number of arguments to pass to actual metamethod */

  /* Get upvalues from closure */
  lua_pushvalue(L, lua_upvalueindex(1)); /*Get function name*/
  metamethod_name_idx = lua_gettop(L);

  lua_pushvalue(L, lua_upvalueindex(2));
  clss = (const swig_lua_class*)(lua_touserdata(L,-1));
  lua_pop(L,1); /* remove lightuserdata with clss from stack */

  /* Actual work */
  result = SWIG_Lua_do_resolve_metamethod(L, clss, metamethod_name_idx, 1);
  if (!result) {
   SWIG_Lua_pushferrstring(L,"The metamethod proxy is set, but it failed to find actual metamethod. Memory corruption is most likely explanation.");
   lua_error(L);
   return 0;
  }

  lua_remove(L,-2); /* remove metamethod key */
  lua_insert(L,1); /* move function to correct position */
  lua_call(L, numargs, LUA_MULTRET);
  return lua_gettop(L); /* return all results */
}


/* If given metamethod must be present in given class, then creates appropriate proxy
 * Returns 1 if successfully added, 0 if not added because no base class has it, -1
 * if method is defined in the class metatable itself
 */
SWIGINTERN int SWIG_Lua_add_class_user_metamethod(lua_State *L, swig_lua_class *clss, const int metatable_index)
{
  int key_index;
  int success = 0;
  int i = 0;

  /* metamethod name - on the top of the stack */
  assert(lua_isstring(L,-1));

  key_index = lua_gettop(L);

  /* Check whether method is already defined in metatable */
  lua_pushvalue(L,key_index); /* copy of the key */
  lua_gettable(L,metatable_index);
  if( !lua_isnil(L,-1) ) {
    lua_pop(L,1);
    return -1;
  }
  lua_pop(L,1);

  /* Iterating over immediate bases */
  for(i=0;clss->bases[i];i++)
  {
    const swig_lua_class *base = clss->bases[i];
    SWIG_Lua_get_class_metatable(L, base->fqname);
    lua_pushvalue(L, key_index);
    lua_rawget(L, -2);
    if( !lua_isnil(L,-1) ) {
      lua_pushvalue(L, key_index);

      /* Add proxy function */
      lua_pushvalue(L, key_index); /* first closure value is function name */
      lua_pushlightuserdata(L, clss); /* second closure value is swig_lua_class structure */
      lua_pushcclosure(L, SWIG_Lua_resolve_metamethod, 2);

      lua_rawset(L, metatable_index);
      success = 1;
    }
    lua_pop(L,1); /* remove function or nil */
    lua_pop(L,1); /* remove base class metatable */

    if( success )
      break;
  }

  return success;
}

SWIGINTERN void SWIG_Lua_add_class_user_metamethods(lua_State *L, swig_lua_class *clss)
{
  int metatable_index;
  int metamethods_info_index;
  int tostring_undefined;
  int eq_undefined = 0;

  SWIG_Lua_get_class_metatable(L, clss->fqname);
  metatable_index = lua_gettop(L);
  SWIG_Lua_get_inheritable_metamethods(L);
  assert(lua_istable(L,-1));
  metamethods_info_index = lua_gettop(L);
  lua_pushnil(L); /* first key */
  while(lua_next(L, metamethods_info_index) != 0 ) {
    /* key at index -2, value at index -1 */
    const int is_inheritable = lua_toboolean(L,-2);
    lua_pop(L,1); /* remove value - we don't need it anymore */

    if(is_inheritable) { /* if metamethod is inheritable */
      SWIG_Lua_add_class_user_metamethod(L,clss,metatable_index);
    }
  }

  lua_pop(L,1); /* remove inheritable metatmethods table */

  /* Special handling for __tostring method */
  lua_pushstring(L, "__tostring");
  lua_pushvalue(L,-1);
  lua_rawget(L,metatable_index);
  tostring_undefined = lua_isnil(L,-1);
  lua_pop(L,1);
  if( tostring_undefined ) {
    lua_pushcfunction(L, SWIG_Lua_class_tostring);
    lua_rawset(L, metatable_index);
  } else {
    lua_pop(L,1); /* remove copy of the key */
  }

  /* Special handling for __eq method */
  lua_pushstring(L, "__eq");
  lua_pushvalue(L,-1);
  lua_rawget(L,metatable_index);
  eq_undefined = lua_isnil(L,-1);
  lua_pop(L,1);
  if( eq_undefined ) {
    lua_pushcfunction(L, SWIG_Lua_class_equal);
    lua_rawset(L, metatable_index);
  } else {
    lua_pop(L,1); /* remove copy of the key */
  }
  /* Warning: __index and __newindex are SWIG-defined. For user-defined operator[]
   * a __getitem/__setitem method should be defined
   */
  lua_pop(L,1); /* pop class metatable */
}

/* Register class static methods,attributes etc as well as constructor proxy */
SWIGINTERN void SWIG_Lua_class_register_static(lua_State *L, swig_lua_class *clss)
{
  const int SWIGUNUSED begin = lua_gettop(L);
  lua_checkstack(L,5); /* just in case */
  assert(lua_istable(L,-1));  /* just in case */
  assert(strcmp(clss->name, clss->cls_static->name) == 0); /* in class those 2 must be equal */

  SWIG_Lua_namespace_register(L,clss->cls_static, 1);

  assert(lua_istable(L,-1)); /* just in case */

  /*  add its constructor to module with the name of the class
  so you can do MyClass(...) as well as new_MyClass(...)
  BUT only if a constructor is defined
  (this overcomes the problem of pure virtual classes without constructors)*/
  if (clss->constructor)
  {
    lua_getmetatable(L,-1);
    assert(lua_istable(L,-1)); /* just in case */
    SWIG_Lua_add_function(L,"__call", clss->constructor);
    lua_pop(L,1);
  }

  assert(lua_istable(L,-1)); /* just in case */
  SWIG_Lua_add_class_static_details(L, clss);

  /* clear stack */
  lua_pop(L,1);
  assert( lua_gettop(L) == begin );
}

/* Performs the instance (non-static) class registration process. Metatable for class is created
 * and added to the class registry.
 */
SWIGINTERN void  SWIG_Lua_class_register_instance(lua_State *L,swig_lua_class *clss)
{
  const int SWIGUNUSED begin = lua_gettop(L);
  int i;
  /* if name already there (class is already registered) then do nothing */
  SWIG_Lua_get_class_registry(L);  /* get the registry */
  lua_pushstring(L,clss->fqname);  /* get the name */
  lua_rawget(L,-2);
  if(!lua_isnil(L,-1)) {
    lua_pop(L,2);
    assert(lua_gettop(L)==begin);
    return;
  }
  lua_pop(L,2); /* tidy stack */
  /* Recursively initialize all bases */
  for(i=0;clss->bases[i];i++)
  {
    SWIG_Lua_class_register_instance(L,clss->bases[i]);
  }
  /* Again, get registry and push name */
  SWIG_Lua_get_class_registry(L);  /* get the registry */
  lua_pushstring(L,clss->fqname);  /* get the name */
  lua_newtable(L);    /* create the metatable */
#if defined(SWIG_LUA_SQUASH_BASES) && (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA)
  /* If squashing is requested, then merges all bases metatable into this one.
   * It would get us all special methods: __getitem, __add etc.
   * This would set .fn, .type, and other .xxx incorrectly, but we will overwrite it right away
   */
  {
    int new_metatable_index = lua_absindex(L,-1);
    for(i=0;clss->bases[i];i++)
    {
      int base_metatable;
      SWIG_Lua_get_class_metatable(L,clss->bases[i]->fqname);
      base_metatable = lua_absindex(L,-1);
      SWIG_Lua_merge_tables_by_index(L,new_metatable_index, base_metatable);
      lua_pop(L,1);
    }
  }
  /* And now we will overwrite all incorrectly set data */
#endif
  /* add string of class name called ".type" */
  lua_pushstring(L,".type");
  lua_pushstring(L,clss->fqname);
  lua_rawset(L,-3);
  /* add a table called bases */
  lua_pushstring(L,".bases");
  lua_newtable(L);
  lua_rawset(L,-3);
  /* add a table called ".get" */
  lua_pushstring(L,".get");
  lua_newtable(L);
  lua_rawset(L,-3);
  /* add a table called ".set" */
  lua_pushstring(L,".set");
  lua_newtable(L);
  lua_rawset(L,-3);
  /* add a table called ".fn" */
  lua_pushstring(L,".fn");
  lua_newtable(L);
  /* add manual disown method */
  SWIG_Lua_add_function(L,"__disown",SWIG_Lua_class_disown);
  lua_rawset(L,-3);
  /* add accessor fns for using the .get,.set&.fn */
  SWIG_Lua_add_function(L,"__index",SWIG_Lua_class_get);
  SWIG_Lua_add_function(L,"__newindex",SWIG_Lua_class_set);
  SWIG_Lua_add_function(L,"__gc",SWIG_Lua_class_destruct);
  /* add it */
  lua_rawset(L,-3);  /* metatable into registry */
  lua_pop(L,1);      /* tidy stack (remove registry) */
  assert(lua_gettop(L) == begin);

#if defined(SWIG_LUA_SQUASH_BASES) && (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA)
  /* Now merge all symbols from .fn, .set, .get etc from bases to our tables */
  SWIG_Lua_class_squash_bases(L,clss);
#endif
  SWIG_Lua_get_class_metatable(L,clss->fqname);
  SWIG_Lua_add_class_instance_details(L,clss);  /* recursive adding of details (atts & ops) */
  lua_pop(L,1);      /* tidy stack (remove class metatable) */
  assert( lua_gettop(L) == begin );
}

SWIGINTERN void  SWIG_Lua_class_register(lua_State *L,swig_lua_class *clss)
{
  int SWIGUNUSED begin;
  assert(lua_istable(L,-1)); /* This is a table (module or namespace) where classes will be added */
  SWIG_Lua_class_register_instance(L,clss);
  SWIG_Lua_class_register_static(L,clss);

  /* Add links from static part to instance part and vice versa */
  /* [SWIG registry]                                   [Module]
   *    "MyClass" ----> [MyClass metatable] <=====     "MyClass" -+> [static part]
   *                     ".get" ----> ...        |                |     getmetatable()----|
   *                     ".set" ----> ...        |                |                       |
   *                     ".static" --------------)----------------/           [static part metatable]
   *                                             |                                ".get" --> ...
   *                                             |                                ".set" --> ....
   *                                             |=============================== ".instance"
   */
  begin = lua_gettop(L);
  lua_pushstring(L,clss->cls_static->name);
  lua_rawget(L,-2); /* get class static table */
  assert(lua_istable(L,-1));
  lua_getmetatable(L,-1);
  assert(lua_istable(L,-1)); /* get class static metatable */
  lua_pushstring(L,".instance"); /* prepare key */

  SWIG_Lua_get_class_metatable(L,clss->fqname); /* get class metatable */
  assert(lua_istable(L,-1));
  lua_pushstring(L,".static"); /* prepare key */
  lua_pushvalue(L, -4); /* push static class TABLE */
  assert(lua_istable(L,-1));
  lua_rawset(L,-3); /* assign static class table(!NOT metatable) as ".static" member of class metatable */
  lua_rawset(L,-3); /* assign class metatable as ".instance" member of class static METATABLE */
  lua_pop(L,2);
  assert(lua_gettop(L) == begin);
}
#endif /* SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA */

#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUA) || (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUAC)
SWIGINTERN void SWIG_Lua_elua_class_register_instance(lua_State *L, swig_lua_class *clss)
{
  const int SWIGUNUSED begin = lua_gettop(L);
  int i;
  /* if name already there (class is already registered) then do nothing */
  SWIG_Lua_get_class_registry(L);  /* get the registry */
  lua_pushstring(L,clss->fqname);  /* get the name */
  lua_rawget(L,-2);
  if(!lua_isnil(L,-1)) {
    lua_pop(L,2);
    assert(lua_gettop(L)==begin);
    return;
  }
  lua_pop(L,2); /* tidy stack */
  /* Recursively initialize all bases */
  for(i=0;clss->bases[i];i++)
  {
    SWIG_Lua_elua_class_register_instance(L,clss->bases[i]);
  }
  /* Again, get registry and push name */
  SWIG_Lua_get_class_registry(L);  /* get the registry */
  lua_pushstring(L,clss->fqname);  /* get the name */
  assert(clss->metatable);
  lua_pushrotable(L, (void*)(clss->metatable));    /* create the metatable */
  lua_rawset(L,-3);
  lua_pop(L,1);
  assert(lua_gettop(L) == begin);
}
#endif /* elua && eluac */

/* -----------------------------------------------------------------------------
 * Class/structure conversion fns
 * ----------------------------------------------------------------------------- */

/* helper to add metatable to new lua object */
SWIGINTERN void SWIG_Lua_AddMetatable(lua_State *L,swig_type_info *type)
{
  if (type->clientdata)  /* there is clientdata: so add the metatable */
  {
    SWIG_Lua_get_class_metatable(L,((swig_lua_class*)(type->clientdata))->fqname);
    if (lua_istable(L,-1))
    {
      lua_setmetatable(L,-2);
    }
    else
    {
      lua_pop(L,1);
    }
  }
}

/* pushes a new object into the lua stack */
SWIGRUNTIME void SWIG_Lua_NewPointerObj(lua_State *L,void *ptr,swig_type_info *type, int own)
{
  swig_lua_userdata *usr;
  if (!ptr){
    lua_pushnil(L);
    return;
  }
  usr=(swig_lua_userdata*)lua_newuserdata(L,sizeof(swig_lua_userdata));  /* get data */
  usr->ptr=ptr;  /* set the ptr */
  usr->type=type;
  usr->own=own;
#if (SWIG_LUA_TARGET != SWIG_LUA_FLAVOR_ELUAC)
  SWIG_Lua_AddMetatable(L,type); /* add metatable */
#endif
}

/* takes a object from the lua stack & converts it into an object of the correct type
 (if possible) */
SWIGRUNTIME int  SWIG_Lua_ConvertPtr(lua_State *L,int index,void **ptr,swig_type_info *type,int flags)
{
  swig_lua_userdata *usr;
  swig_cast_info *cast;
  /* special case: lua nil => NULL pointer */
  if (lua_isnil(L,index))
  {
    *ptr=0;
    return (flags & SWIG_POINTER_NO_NULL) ? SWIG_NullReferenceError : SWIG_OK;
  }
  usr=(swig_lua_userdata*)lua_touserdata(L,index);  /* get data */
  if (usr)
  {
    if (flags & SWIG_POINTER_DISOWN) /* must disown the object */
    {
        usr->own=0;
    }
    if (!type)            /* special cast void*, no casting fn */
    {
      *ptr=usr->ptr;
      return SWIG_OK; /* ok */
    }
    cast=SWIG_TypeCheckStruct(usr->type,type); /* performs normal type checking */
    if (cast)
    {
      int newmemory = 0;
      *ptr=SWIG_TypeCast(cast,usr->ptr,&newmemory);
      assert(!newmemory); /* newmemory handling not yet implemented */
      return SWIG_OK;  /* ok */
    }
  }
  return SWIG_ERROR;  /* error */
}

SWIGRUNTIME void* SWIG_Lua_MustGetPtr(lua_State *L,int index,swig_type_info *type,int flags,
       int argnum,const char *func_name){
  void *result;
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,index,&result,type,flags))){
    luaL_error (L,"Error in %s, expected a %s at argument number %d\n",
		func_name,(type && type->str)?type->str:"void*",argnum);
  }
  return result;
}

/* pushes a packed userdata. user for member fn pointers only */
SWIGRUNTIME void SWIG_Lua_NewPackedObj(lua_State *L,void *ptr,size_t size,swig_type_info *type)
{
  swig_lua_rawdata *raw;
  assert(ptr); /* not acceptable to pass in a NULL value */
  raw=(swig_lua_rawdata*)lua_newuserdata(L,sizeof(swig_lua_rawdata)-1+size);  /* alloc data */
  raw->type=type;
  raw->own=0;
  memcpy(raw->data,ptr,size); /* copy the data */
  SWIG_Lua_AddMetatable(L,type); /* add metatable */
}

/* converts a packed userdata. user for member fn pointers only */
SWIGRUNTIME int  SWIG_Lua_ConvertPacked(lua_State *L,int index,void *ptr,size_t size,swig_type_info *type)
{
  swig_lua_rawdata *raw;
  raw=(swig_lua_rawdata*)lua_touserdata(L,index);  /* get data */
  if (!raw) return SWIG_ERROR;  /* error */
  if (type==0 || type==raw->type) /* void* or identical type */
  {
    memcpy(ptr,raw->data,size); /* copy it */
    return SWIG_OK; /* ok */
  }
  return SWIG_ERROR;  /* error */
}

/* a function to get the typestring of a piece of data */
SWIGRUNTIME const char *SWIG_Lua_typename(lua_State *L, int tp)
{
  swig_lua_userdata *usr;
  if (lua_isuserdata(L,tp))
  {
    usr=(swig_lua_userdata*)lua_touserdata(L,tp);  /* get data */
    if (usr && usr->type && usr->type->str)
      return usr->type->str;
    return "userdata (unknown type)";
  }
  return lua_typename(L,lua_type(L,tp));
}

/* lua callable function to get the userdata's type */
SWIGRUNTIME int SWIG_Lua_type(lua_State *L)
{
  lua_pushstring(L,SWIG_Lua_typename(L,1));
  return 1;
}

/* -----------------------------------------------------------------------------
 * global variable support code: class/struct typemap functions
 * ----------------------------------------------------------------------------- */

#if ((SWIG_LUA_TARGET != SWIG_LUA_FLAVOR_ELUA) && (SWIG_LUA_TARGET != SWIG_LUA_FLAVOR_ELUAC))
/* Install Constants */
SWIGINTERN void
SWIG_Lua_InstallConstants(lua_State *L, swig_lua_const_info constants[]) {
  int i;
  for (i = 0; constants[i].type; i++) {
    switch(constants[i].type) {
    case SWIG_LUA_INT:
      lua_pushstring(L,constants[i].name);
      lua_pushinteger(L,(lua_Integer)constants[i].lvalue);
      lua_rawset(L,-3);
      break;
    case SWIG_LUA_FLOAT:
      lua_pushstring(L,constants[i].name);
      lua_pushnumber(L,(lua_Number)constants[i].dvalue);
      lua_rawset(L,-3);
      break;
    case SWIG_LUA_CHAR:
      lua_pushstring(L,constants[i].name);
      {
        char c = (char)constants[i].lvalue;
        lua_pushlstring(L,&c,1);
      }
      lua_rawset(L,-3);
      break;
    case SWIG_LUA_STRING:
      lua_pushstring(L,constants[i].name);
      lua_pushstring(L,(char *) constants[i].pvalue);
      lua_rawset(L,-3);
      break;
    case SWIG_LUA_POINTER:
      lua_pushstring(L,constants[i].name);
      SWIG_NewPointerObj(L,constants[i].pvalue, *(constants[i]).ptype,0);
      lua_rawset(L,-3);
      break;
    case SWIG_LUA_BINARY:
      lua_pushstring(L,constants[i].name);
      SWIG_NewMemberObj(L,constants[i].pvalue,constants[i].lvalue,*(constants[i]).ptype);
      lua_rawset(L,-3);
      break;
    default:
      break;
    }
  }
}
#endif

/* -----------------------------------------------------------------------------
 * executing lua code from within the wrapper
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_DOSTRING_FAIL /* Allows redefining of error function */
#define SWIG_DOSTRING_FAIL(S) fprintf(stderr,"%s\n",S)
#endif
/* Executes a C string in Lua which is a really simple way of calling lua from C
Unfortunately lua keeps changing its APIs, so we need a conditional compile
In lua 5.0.X it's lua_dostring()
In lua 5.1.X it's luaL_dostring()
*/
SWIGINTERN int
SWIG_Lua_dostring(lua_State *L, const char *str) {
  int ok,top;
  if (str==0 || str[0]==0) return 0; /* nothing to do */
  top=lua_gettop(L); /* save stack */
#if (defined(LUA_VERSION_NUM) && (LUA_VERSION_NUM>=501))
  ok=luaL_dostring(L,str);	/* looks like this is lua 5.1.X or later, good */
#else
  ok=lua_dostring(L,str);	/* might be lua 5.0.x, using lua_dostring */
#endif
  if (ok!=0) {
    SWIG_DOSTRING_FAIL(lua_tostring(L,-1));
  }
  lua_settop(L,top); /* restore the stack */
  return ok;
}

#ifdef __cplusplus
}
#endif

/* ------------------------------ end luarun.swg  ------------------------------ */


/* -------- TYPES TABLE (BEGIN) -------- */

#define SWIGTYPE_p_SArrayCrc swig_types[0]
#define SWIGTYPE_p_SArrayDisplayAnalog0 swig_types[1]
#define SWIGTYPE_p_SArrayDisplayAnalog1 swig_types[2]
#define SWIGTYPE_p_SArrayDisplayAnalogF swig_types[3]
#define SWIGTYPE_p_SArrayDisplayDigital swig_types[4]
#define SWIGTYPE_p_SArrayEEPROM swig_types[5]
#define SWIGTYPE_p_SArrayETS swig_types[6]
#define SWIGTYPE_p_SArrayFpga swig_types[7]
#define SWIGTYPE_p_SArrayFrameData swig_types[8]
#define SWIGTYPE_p_SArrayFx3 swig_types[9]
#define SWIGTYPE_p_SArrayGeneratorAnalog0 swig_types[10]
#define SWIGTYPE_p_SArrayGeneratorAnalog1 swig_types[11]
#define SWIGTYPE_p_SArrayGeneratorDigital swig_types[12]
#define SWIGTYPE_p_SArrayHardware swig_types[13]
#define SWIGTYPE_p_SArrayMagic swig_types[14]
#define SWIGTYPE_p_SArrayPaddingAfter swig_types[15]
#define SWIGTYPE_p_SArrayPaddingBefore swig_types[16]
#define SWIGTYPE_p_SArrayString256 swig_types[17]
#define SWIGTYPE_p_SAtomic swig_types[18]
#define SWIGTYPE_p_SCtxApi swig_types[19]
#define SWIGTYPE_p_SCtxDisplay swig_types[20]
#define SWIGTYPE_p_SCtxFrame swig_types[21]
#define SWIGTYPE_p_SCtxSimulate swig_types[22]
#define SWIGTYPE_p_SDisplay swig_types[23]
#define SWIGTYPE_p_SEeprom swig_types[24]
#define SWIGTYPE_p_SFContext swig_types[25]
#define SWIGTYPE_p_SFpga swig_types[26]
#define SWIGTYPE_p_SFrameData swig_types[27]
#define SWIGTYPE_p_SFrameHeader swig_types[28]
#define SWIGTYPE_p_SFx3 swig_types[29]
#define SWIGTYPE_p_SGUID swig_types[30]
#define SWIGTYPE_p_SGenerator swig_types[31]
#define SWIGTYPE_p_SHardware swig_types[32]
#define SWIGTYPE_p_SSimulate swig_types[33]
#define SWIGTYPE_p_SUsb swig_types[34]
#define SWIGTYPE_p__EFunctionType swig_types[35]
#define SWIGTYPE_p__ESimulateType swig_types[36]
#define SWIGTYPE_p__SCallback swig_types[37]
#define SWIGTYPE_p__SFloat swig_types[38]
#define SWIGTYPE_p__SInt swig_types[39]
#define SWIGTYPE_p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int swig_types[40]
#define SWIGTYPE_p_f_p_SDisplay_p_float_p_float_p_void__int swig_types[41]
#define SWIGTYPE_p_f_p_SFContext__int swig_types[42]
#define SWIGTYPE_p_f_p_SFrameData_int_p_float_p_float_p_void__int swig_types[43]
#define SWIGTYPE_p_f_p_SGenerator_p_unsigned_int__int swig_types[44]
#define SWIGTYPE_p_f_p_SHardware__int swig_types[45]
#define SWIGTYPE_p_f_short_short_p_short__int swig_types[46]
#define SWIGTYPE_p_float swig_types[47]
#define SWIGTYPE_p_int swig_types[48]
#define SWIGTYPE_p_long_long swig_types[49]
#define SWIGTYPE_p_short swig_types[50]
#define SWIGTYPE_p_unsigned_char swig_types[51]
#define SWIGTYPE_p_unsigned_int swig_types[52]
#define SWIGTYPE_p_unsigned_long_long swig_types[53]
#define SWIGTYPE_p_unsigned_short swig_types[54]
#define SWIGTYPE_p_void swig_types[55]
static swig_type_info *swig_types[57];
static swig_module_info swig_module = {swig_types, 56, 0, 0, 0, 0};
#define SWIG_TypeQuery(name) SWIG_TypeQueryModule(&swig_module, &swig_module, name)
#define SWIG_MangledTypeQuery(name) SWIG_MangledTypeQueryModule(&swig_module, &swig_module, name)

/* -------- TYPES TABLE (END) -------- */

#define SWIG_name      "ScopeFun"
#define SWIG_init      luaopen_ScopeFun
#define SWIG_init_user luaopen_ScopeFun_user

#define SWIG_LUACODE   luaopen_ScopeFun_luacode

#ifdef __cplusplus	/* generic alloc/dealloc fns*/
#define SWIG_ALLOC_ARRAY(TYPE,LEN) 	new TYPE[LEN]
#define SWIG_FREE_ARRAY(PTR)		delete[] PTR
#else
#define SWIG_ALLOC_ARRAY(TYPE,LEN) 	(TYPE *)malloc(LEN*sizeof(TYPE))
#define SWIG_FREE_ARRAY(PTR)		free(PTR)
#endif
/* counting the size of arrays:*/
SWIGINTERN int SWIG_itable_size(lua_State* L, int index)
{
	int n=0;
	while(1){
		lua_rawgeti(L,index,n+1);
		if (lua_isnil(L,-1))break;
		++n;
		lua_pop(L,1);
	}
	lua_pop(L,1);
	return n;
}

SWIGINTERN int SWIG_table_size(lua_State* L, int index)
{
	int n=0;
	lua_pushnil(L);  /* first key*/
	while (lua_next(L, index) != 0) {
		++n;
		lua_pop(L, 1);  /* removes `value'; keeps `key' for next iteration*/
	}
	return n;
}

/* super macro to declare array typemap helper fns */
#define SWIG_DECLARE_TYPEMAP_ARR_FN(NAME,TYPE)\
	SWIGINTERN int SWIG_read_##NAME##_num_array(lua_State* L,int index,TYPE *array,int size){\
		int i;\
		for (i = 0; i < size; i++) {\
			lua_rawgeti(L,index,i+1);\
			if (lua_isnumber(L,-1)){\
				array[i] = (TYPE)lua_tonumber(L,-1);\
			} else {\
				lua_pop(L,1);\
				return 0;\
			}\
			lua_pop(L,1);\
		}\
		return 1;\
	}\
	SWIGINTERN TYPE* SWIG_get_##NAME##_num_array_fixed(lua_State* L, int index, int size){\
		TYPE *array;\
		if (!lua_istable(L,index) || SWIG_itable_size(L,index) != size) {\
			SWIG_Lua_pushferrstring(L,"expected a table of size %d",size);\
			return 0;\
		}\
		array=SWIG_ALLOC_ARRAY(TYPE,size);\
		if (!SWIG_read_##NAME##_num_array(L,index,array,size)){\
			SWIG_Lua_pusherrstring(L,"table must contain numbers");\
			SWIG_FREE_ARRAY(array);\
			return 0;\
		}\
		return array;\
	}\
	SWIGINTERN TYPE* SWIG_get_##NAME##_num_array_var(lua_State* L, int index, int* size)\
	{\
		TYPE *array;\
		if (!lua_istable(L,index)) {\
			SWIG_Lua_pusherrstring(L,"expected a table");\
			return 0;\
		}\
		*size=SWIG_itable_size(L,index);\
		if (*size<1){\
			SWIG_Lua_pusherrstring(L,"table appears to be empty");\
			return 0;\
		}\
		array=SWIG_ALLOC_ARRAY(TYPE,*size);\
		if (!SWIG_read_##NAME##_num_array(L,index,array,*size)){\
			SWIG_Lua_pusherrstring(L,"table must contain numbers");\
			SWIG_FREE_ARRAY(array);\
			return 0;\
		}\
		return array;\
	}\
	SWIGINTERN void SWIG_write_##NAME##_num_array(lua_State* L,TYPE *array,int size){\
		int i;\
		lua_newtable(L);\
		for (i = 0; i < size; i++){\
			lua_pushnumber(L,(lua_Number)array[i]);\
			lua_rawseti(L,-2,i+1);/* -1 is the number, -2 is the table*/ \
		}\
	}

SWIG_DECLARE_TYPEMAP_ARR_FN(schar,signed char)
SWIG_DECLARE_TYPEMAP_ARR_FN(uchar,unsigned char)
SWIG_DECLARE_TYPEMAP_ARR_FN(int,int)
SWIG_DECLARE_TYPEMAP_ARR_FN(uint,unsigned int)
SWIG_DECLARE_TYPEMAP_ARR_FN(short,short)
SWIG_DECLARE_TYPEMAP_ARR_FN(ushort,unsigned short)
SWIG_DECLARE_TYPEMAP_ARR_FN(long,long)
SWIG_DECLARE_TYPEMAP_ARR_FN(ulong,unsigned long)
SWIG_DECLARE_TYPEMAP_ARR_FN(float,float)
SWIG_DECLARE_TYPEMAP_ARR_FN(double,double)

SWIGINTERN int SWIG_read_ptr_array(lua_State* L,int index,void **array,int size,swig_type_info *type){
	int i;
	for (i = 0; i < size; i++) {
		lua_rawgeti(L,index,i+1);
		if (!lua_isuserdata(L,-1) || SWIG_ConvertPtr(L,-1,&array[i],type,0)==-1){
			lua_pop(L,1);
			return 0;
		}
		lua_pop(L,1);
	}
	return 1;
}
SWIGINTERN void** SWIG_get_ptr_array_fixed(lua_State* L, int index, int size,swig_type_info *type){
	void **array;
	if (!lua_istable(L,index) || SWIG_itable_size(L,index) != size) {
		SWIG_Lua_pushferrstring(L,"expected a table of size %d",size);
		return 0;
	}
	array=SWIG_ALLOC_ARRAY(void*,size);
	if (!SWIG_read_ptr_array(L,index,array,size,type)){
		SWIG_Lua_pushferrstring(L,"table must contain pointers of type %s",type->name);
		SWIG_FREE_ARRAY(array);
		return 0;
	}
	return array;
}
SWIGINTERN void** SWIG_get_ptr_array_var(lua_State* L, int index, int* size,swig_type_info *type){
	void **array;
	if (!lua_istable(L,index)) {
		SWIG_Lua_pusherrstring(L,"expected a table");
		return 0;
	}
	*size=SWIG_itable_size(L,index);
	if (*size<1){
		SWIG_Lua_pusherrstring(L,"table appears to be empty");
		return 0;
	}
	array=SWIG_ALLOC_ARRAY(void*,*size);
	if (!SWIG_read_ptr_array(L,index,array,*size,type)){
		SWIG_Lua_pushferrstring(L,"table must contain pointers of type %s",type->name);
		SWIG_FREE_ARRAY(array);
		return 0;
	}
	return array;
}
SWIGINTERN void SWIG_write_ptr_array(lua_State* L,void **array,int size,swig_type_info *type,int own){
	int i;
	lua_newtable(L);
	for (i = 0; i < size; i++){
		SWIG_NewPointerObj(L,array[i],type,own);
		lua_rawseti(L,-2,i+1);/* -1 is the number, -2 is the table*/
	}
}

SWIGINTERN int SArrayMagic___len(SArrayMagic const *self){ return 4; }
SWIGINTERN byte SArrayMagic___getitem(SArrayMagic *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayMagic___setitem(SArrayMagic *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayETS___len(SArrayETS const *self){ return 1; }
SWIGINTERN byte SArrayETS___getitem(SArrayETS *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayETS___setitem(SArrayETS *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayPaddingBefore___len(SArrayPaddingBefore const *self){ return 251; }
SWIGINTERN byte SArrayPaddingBefore___getitem(SArrayPaddingBefore *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayPaddingBefore___setitem(SArrayPaddingBefore *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayHardware___len(SArrayHardware const *self){ return 128; }
SWIGINTERN byte SArrayHardware___getitem(SArrayHardware *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayHardware___setitem(SArrayHardware *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayPaddingAfter___len(SArrayPaddingAfter const *self){ return 639; }
SWIGINTERN byte SArrayPaddingAfter___getitem(SArrayPaddingAfter *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayPaddingAfter___setitem(SArrayPaddingAfter *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayCrc___len(SArrayCrc const *self){ return 1; }
SWIGINTERN byte SArrayCrc___getitem(SArrayCrc *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayCrc___setitem(SArrayCrc *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayString256___len(SArrayString256 const *self){ return 256; }
SWIGINTERN byte SArrayString256___getitem(SArrayString256 *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayString256___setitem(SArrayString256 *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayFrameData___len(SArrayFrameData const *self){ return (512*1024*1024); }
SWIGINTERN byte SArrayFrameData___getitem(SArrayFrameData *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayFrameData___setitem(SArrayFrameData *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayEEPROM___len(SArrayEEPROM const *self){ return (256*1024); }
SWIGINTERN byte SArrayEEPROM___getitem(SArrayEEPROM *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayEEPROM___setitem(SArrayEEPROM *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayFx3___len(SArrayFx3 const *self){ return 16384; }
SWIGINTERN byte SArrayFx3___getitem(SArrayFx3 *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayFx3___setitem(SArrayFx3 *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayFpga___len(SArrayFpga const *self){ return (4*1024*1024); }
SWIGINTERN byte SArrayFpga___getitem(SArrayFpga *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayFpga___setitem(SArrayFpga *self,int i,byte v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayGeneratorAnalog0___len(SArrayGeneratorAnalog0 const *self){ return 32768; }
SWIGINTERN ishort SArrayGeneratorAnalog0___getitem(SArrayGeneratorAnalog0 *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayGeneratorAnalog0___setitem(SArrayGeneratorAnalog0 *self,int i,ishort v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayGeneratorAnalog1___len(SArrayGeneratorAnalog1 const *self){ return 32768; }
SWIGINTERN ishort SArrayGeneratorAnalog1___getitem(SArrayGeneratorAnalog1 *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayGeneratorAnalog1___setitem(SArrayGeneratorAnalog1 *self,int i,ishort v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayGeneratorDigital___len(SArrayGeneratorDigital const *self){ return 32768; }
SWIGINTERN ushort SArrayGeneratorDigital___getitem(SArrayGeneratorDigital *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayGeneratorDigital___setitem(SArrayGeneratorDigital *self,int i,ushort v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayDisplayAnalog0___len(SArrayDisplayAnalog0 const *self){ return 10000; }
SWIGINTERN float SArrayDisplayAnalog0___getitem(SArrayDisplayAnalog0 *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayDisplayAnalog0___setitem(SArrayDisplayAnalog0 *self,int i,float v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayDisplayAnalog1___len(SArrayDisplayAnalog1 const *self){ return 10000; }
SWIGINTERN float SArrayDisplayAnalog1___getitem(SArrayDisplayAnalog1 *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayDisplayAnalog1___setitem(SArrayDisplayAnalog1 *self,int i,float v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayDisplayAnalogF___len(SArrayDisplayAnalogF const *self){ return 10000; }
SWIGINTERN float SArrayDisplayAnalogF___getitem(SArrayDisplayAnalogF *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayDisplayAnalogF___setitem(SArrayDisplayAnalogF *self,int i,float v){                                                         self->bytes[i] = v;                                }
SWIGINTERN int SArrayDisplayDigital___len(SArrayDisplayDigital const *self){ return 10000; }
SWIGINTERN ushort SArrayDisplayDigital___getitem(SArrayDisplayDigital *self,int i){                                                            return self->bytes[i];                             }
SWIGINTERN void SArrayDisplayDigital___setitem(SArrayDisplayDigital *self,int i,ushort v){                                                         self->bytes[i] = v;                                }
#ifdef __cplusplus
extern "C" {
#endif
static int _wrap_SHardware_controlAddr_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::controlAddr",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::controlAddr",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::controlAddr",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_controlAddr_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->controlAddr = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_controlAddr_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::controlAddr",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::controlAddr",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_controlAddr_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->controlAddr);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_controlData_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::controlData",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::controlData",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::controlData",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_controlData_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->controlData = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_controlData_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::controlData",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::controlData",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_controlData_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->controlData);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_vgaina_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::vgaina",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::vgaina",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::vgaina",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_vgaina_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->vgaina = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_vgaina_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::vgaina",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::vgaina",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_vgaina_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->vgaina);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_vgainb_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::vgainb",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::vgainb",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::vgainb",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_vgainb_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->vgainb = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_vgainb_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::vgainb",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::vgainb",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_vgainb_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->vgainb);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_offseta_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::offseta",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::offseta",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::offseta",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_offseta_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->offseta = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_offseta_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::offseta",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::offseta",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_offseta_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->offseta);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_offsetb_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::offsetb",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::offsetb",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::offsetb",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_offsetb_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->offsetb = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_offsetb_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::offsetb",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::offsetb",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_offsetb_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->offsetb);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_analogswitch_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::analogswitch",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::analogswitch",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::analogswitch",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_analogswitch_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->analogswitch = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_analogswitch_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::analogswitch",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::analogswitch",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_analogswitch_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->analogswitch);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerMode_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::triggerMode",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerMode",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::triggerMode",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerMode_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->triggerMode = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerMode_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::triggerMode",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerMode",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerMode_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->triggerMode);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerSource_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::triggerSource",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerSource",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::triggerSource",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerSource_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->triggerSource = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerSource_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::triggerSource",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerSource",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerSource_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->triggerSource);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerSlope_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::triggerSlope",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerSlope",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::triggerSlope",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerSlope_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->triggerSlope = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerSlope_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::triggerSlope",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerSlope",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerSlope_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->triggerSlope);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerLevel_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  short arg2 ;
  
  SWIG_check_num_args("SHardware::triggerLevel",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerLevel",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::triggerLevel",2,"short");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerLevel_set",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (short)lua_tonumber(L, 2);
  if (arg1) (arg1)->triggerLevel = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerLevel_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  short result;
  
  SWIG_check_num_args("SHardware::triggerLevel",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerLevel",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerLevel_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (short) ((arg1)->triggerLevel);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerHis_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::triggerHis",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerHis",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::triggerHis",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerHis_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->triggerHis = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_triggerHis_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::triggerHis",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::triggerHis",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_triggerHis_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->triggerHis);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved1_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::reserved1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::reserved1",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved1_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->reserved1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved1_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::reserved1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved1_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->reserved1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_xRange_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::xRange",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::xRange",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::xRange",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_xRange_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->xRange = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_xRange_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::xRange",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::xRange",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_xRange_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->xRange);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_holdoffH_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::holdoffH",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::holdoffH",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::holdoffH",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_holdoffH_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->holdoffH = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_holdoffH_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::holdoffH",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::holdoffH",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_holdoffH_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->holdoffH);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_holdoffL_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::holdoffL",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::holdoffL",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::holdoffL",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_holdoffL_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->holdoffL = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_holdoffL_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::holdoffL",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::holdoffL",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_holdoffL_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->holdoffL);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_sampleSizeH_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::sampleSizeH",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::sampleSizeH",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::sampleSizeH",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_sampleSizeH_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->sampleSizeH = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_sampleSizeH_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::sampleSizeH",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::sampleSizeH",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_sampleSizeH_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->sampleSizeH);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_sampleSizeL_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::sampleSizeL",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::sampleSizeL",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::sampleSizeL",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_sampleSizeL_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->sampleSizeL = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_sampleSizeL_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::sampleSizeL",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::sampleSizeL",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_sampleSizeL_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->sampleSizeL);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorType0_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorType0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorType0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorType0",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorType0_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorType0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorType0_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorType0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorType0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorType0_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorType0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorVoltage0_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorVoltage0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorVoltage0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorVoltage0",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorVoltage0_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorVoltage0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorVoltage0_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorVoltage0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorVoltage0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorVoltage0_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorVoltage0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorOffset0_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  short arg2 ;
  
  SWIG_check_num_args("SHardware::generatorOffset0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorOffset0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorOffset0",2,"short");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorOffset0_set",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (short)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorOffset0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorOffset0_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  short result;
  
  SWIG_check_num_args("SHardware::generatorOffset0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorOffset0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorOffset0_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (short) ((arg1)->generatorOffset0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorDeltaH0_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorDeltaH0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorDeltaH0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorDeltaH0",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorDeltaH0_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorDeltaH0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorDeltaH0_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorDeltaH0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorDeltaH0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorDeltaH0_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorDeltaH0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorDeltaL0_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorDeltaL0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorDeltaL0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorDeltaL0",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorDeltaL0_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorDeltaL0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorDeltaL0_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorDeltaL0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorDeltaL0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorDeltaL0_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorDeltaL0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorSqueareDuty0_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorSqueareDuty0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorSqueareDuty0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorSqueareDuty0",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorSqueareDuty0_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorSqueareDuty0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorSqueareDuty0_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorSqueareDuty0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorSqueareDuty0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorSqueareDuty0_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorSqueareDuty0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorType1_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorType1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorType1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorType1",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorType1_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorType1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorType1_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorType1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorType1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorType1_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorType1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorVoltage1_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorVoltage1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorVoltage1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorVoltage1",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorVoltage1_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorVoltage1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorVoltage1_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorVoltage1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorVoltage1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorVoltage1_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorVoltage1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorOffset1_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  short arg2 ;
  
  SWIG_check_num_args("SHardware::generatorOffset1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorOffset1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorOffset1",2,"short");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorOffset1_set",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (short)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorOffset1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorOffset1_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  short result;
  
  SWIG_check_num_args("SHardware::generatorOffset1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorOffset1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorOffset1_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (short) ((arg1)->generatorOffset1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorDeltaH1_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorDeltaH1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorDeltaH1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorDeltaH1",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorDeltaH1_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorDeltaH1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorDeltaH1_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorDeltaH1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorDeltaH1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorDeltaH1_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorDeltaH1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorDeltaL1_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorDeltaL1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorDeltaL1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorDeltaL1",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorDeltaL1_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorDeltaL1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorDeltaL1_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorDeltaL1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorDeltaL1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorDeltaL1_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorDeltaL1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorSqueareDuty1_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorSqueareDuty1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorSqueareDuty1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorSqueareDuty1",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorSqueareDuty1_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorSqueareDuty1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorSqueareDuty1_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorSqueareDuty1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorSqueareDuty1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorSqueareDuty1_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorSqueareDuty1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern1a_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalPattern1a",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern1a",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalPattern1a",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern1a_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalPattern1a = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern1a_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalPattern1a",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern1a",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern1a_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalPattern1a);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern1b_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalPattern1b",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern1b",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalPattern1b",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern1b_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalPattern1b = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern1b_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalPattern1b",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern1b",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern1b_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalPattern1b);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalMask1_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalMask1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalMask1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalMask1",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalMask1_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalMask1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalMask1_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalMask1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalMask1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalMask1_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalMask1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern2a_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalPattern2a",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern2a",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalPattern2a",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern2a_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalPattern2a = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern2a_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalPattern2a",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern2a",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern2a_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalPattern2a);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern2b_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalPattern2b",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern2b",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalPattern2b",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern2b_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalPattern2b = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern2b_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalPattern2b",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern2b",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern2b_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalPattern2b);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalMask2_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalMask2",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalMask2",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalMask2",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalMask2_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalMask2 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalMask2_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalMask2",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalMask2",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalMask2_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalMask2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern3a_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalPattern3a",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern3a",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalPattern3a",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern3a_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalPattern3a = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern3a_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalPattern3a",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern3a",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern3a_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalPattern3a);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern3b_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalPattern3b",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern3b",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalPattern3b",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern3b_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalPattern3b = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern3b_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalPattern3b",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern3b",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern3b_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalPattern3b);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalMask3_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalMask3",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalMask3",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalMask3",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalMask3_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalMask3 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalMask3_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalMask3",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalMask3",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalMask3_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalMask3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern4a_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalPattern4a",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern4a",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalPattern4a",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern4a_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalPattern4a = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern4a_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalPattern4a",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern4a",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern4a_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalPattern4a);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern4b_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalPattern4b",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern4b",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalPattern4b",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern4b_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalPattern4b = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalPattern4b_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalPattern4b",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalPattern4b",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalPattern4b_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalPattern4b);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalMask4_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalMask4",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalMask4",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalMask4",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalMask4_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalMask4 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalMask4_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalMask4",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalMask4",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalMask4_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalMask4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_delayMaxcnt1_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::dt_delayMaxcnt1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_delayMaxcnt1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::dt_delayMaxcnt1",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_delayMaxcnt1_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->dt_delayMaxcnt1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_delayMaxcnt1_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::dt_delayMaxcnt1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_delayMaxcnt1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_delayMaxcnt1_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->dt_delayMaxcnt1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_delayMaxcnt2_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::dt_delayMaxcnt2",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_delayMaxcnt2",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::dt_delayMaxcnt2",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_delayMaxcnt2_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->dt_delayMaxcnt2 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_delayMaxcnt2_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::dt_delayMaxcnt2",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_delayMaxcnt2",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_delayMaxcnt2_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->dt_delayMaxcnt2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_delayMaxcnt3_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::dt_delayMaxcnt3",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_delayMaxcnt3",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::dt_delayMaxcnt3",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_delayMaxcnt3_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->dt_delayMaxcnt3 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_delayMaxcnt3_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::dt_delayMaxcnt3",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_delayMaxcnt3",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_delayMaxcnt3_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->dt_delayMaxcnt3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_delayMaxcnt4_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::dt_delayMaxcnt4",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_delayMaxcnt4",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::dt_delayMaxcnt4",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_delayMaxcnt4_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->dt_delayMaxcnt4 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_delayMaxcnt4_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::dt_delayMaxcnt4",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_delayMaxcnt4",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_delayMaxcnt4_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->dt_delayMaxcnt4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_control_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::dt_control",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_control",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::dt_control",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_control_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->dt_control = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_dt_control_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::dt_control",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::dt_control",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_dt_control_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->dt_control);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalVoltage_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalVoltage",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalVoltage",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalVoltage",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalVoltage_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalVoltage = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalVoltage_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalVoltage",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalVoltage",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalVoltage_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalVoltage);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalInputOutput_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalInputOutput",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalInputOutput",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalInputOutput",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalInputOutput_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalInputOutput = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalInputOutput_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalInputOutput",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalInputOutput",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalInputOutput_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalInputOutput);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalOutputBit_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalOutputBit",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalOutputBit",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalOutputBit",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalOutputBit_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalOutputBit = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalOutputBit_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalOutputBit",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalOutputBit",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalOutputBit_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalOutputBit);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalOutputMask_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalOutputMask",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalOutputMask",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalOutputMask",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalOutputMask_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalOutputMask = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalOutputMask_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalOutputMask",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalOutputMask",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalOutputMask_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalOutputMask);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalClkDivideH_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalClkDivideH",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalClkDivideH",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalClkDivideH",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalClkDivideH_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalClkDivideH = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalClkDivideH_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalClkDivideH",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalClkDivideH",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalClkDivideH_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalClkDivideH);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalClkDivideL_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::digitalClkDivideL",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalClkDivideL",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::digitalClkDivideL",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalClkDivideL_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->digitalClkDivideL = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_digitalClkDivideL_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::digitalClkDivideL",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::digitalClkDivideL",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_digitalClkDivideL_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->digitalClkDivideL);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_average_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::average",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::average",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::average",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_average_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->average = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_average_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::average",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::average",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_average_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->average);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_preTriggerH_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::preTriggerH",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::preTriggerH",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::preTriggerH",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_preTriggerH_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->preTriggerH = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_preTriggerH_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::preTriggerH",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::preTriggerH",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_preTriggerH_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->preTriggerH);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_preTriggerL_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::preTriggerL",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::preTriggerL",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::preTriggerL",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_preTriggerL_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->preTriggerL = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_preTriggerL_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::preTriggerL",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::preTriggerL",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_preTriggerL_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->preTriggerL);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorPhase_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::generatorPhase",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorPhase",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::generatorPhase",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorPhase_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorPhase = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_generatorPhase_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::generatorPhase",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::generatorPhase",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_generatorPhase_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->generatorPhase);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved2_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SHardware::reserved2",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved2",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::reserved2",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved2_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->reserved2 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved2_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SHardware::reserved2",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved2",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved2_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort) ((arg1)->reserved2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved3_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SHardware::reserved3",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved3",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::reserved3",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved3_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->reserved3 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved3_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("SHardware::reserved3",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved3",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved3_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint) ((arg1)->reserved3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved4_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SHardware::reserved4",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved4",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::reserved4",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved4_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->reserved4 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved4_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("SHardware::reserved4",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved4",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved4_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint) ((arg1)->reserved4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved5_set(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SHardware::reserved5",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved5",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SHardware::reserved5",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved5_set",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->reserved5 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SHardware_reserved5_get(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("SHardware::reserved5",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SHardware::reserved5",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("SHardware_reserved5_get",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint) ((arg1)->reserved5);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SHardware(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *result = 0 ;
  
  SWIG_check_num_args("SHardware::SHardware",0,0)
  result = (SHardware *)calloc(1, sizeof(SHardware));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SHardware,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SHardware(void *obj) {
SHardware *arg1 = (SHardware *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SHardware(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SHardware);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SHardware_attributes[] = {
    { "controlAddr", _wrap_SHardware_controlAddr_get, _wrap_SHardware_controlAddr_set },
    { "controlData", _wrap_SHardware_controlData_get, _wrap_SHardware_controlData_set },
    { "vgaina", _wrap_SHardware_vgaina_get, _wrap_SHardware_vgaina_set },
    { "vgainb", _wrap_SHardware_vgainb_get, _wrap_SHardware_vgainb_set },
    { "offseta", _wrap_SHardware_offseta_get, _wrap_SHardware_offseta_set },
    { "offsetb", _wrap_SHardware_offsetb_get, _wrap_SHardware_offsetb_set },
    { "analogswitch", _wrap_SHardware_analogswitch_get, _wrap_SHardware_analogswitch_set },
    { "triggerMode", _wrap_SHardware_triggerMode_get, _wrap_SHardware_triggerMode_set },
    { "triggerSource", _wrap_SHardware_triggerSource_get, _wrap_SHardware_triggerSource_set },
    { "triggerSlope", _wrap_SHardware_triggerSlope_get, _wrap_SHardware_triggerSlope_set },
    { "triggerLevel", _wrap_SHardware_triggerLevel_get, _wrap_SHardware_triggerLevel_set },
    { "triggerHis", _wrap_SHardware_triggerHis_get, _wrap_SHardware_triggerHis_set },
    { "reserved1", _wrap_SHardware_reserved1_get, _wrap_SHardware_reserved1_set },
    { "xRange", _wrap_SHardware_xRange_get, _wrap_SHardware_xRange_set },
    { "holdoffH", _wrap_SHardware_holdoffH_get, _wrap_SHardware_holdoffH_set },
    { "holdoffL", _wrap_SHardware_holdoffL_get, _wrap_SHardware_holdoffL_set },
    { "sampleSizeH", _wrap_SHardware_sampleSizeH_get, _wrap_SHardware_sampleSizeH_set },
    { "sampleSizeL", _wrap_SHardware_sampleSizeL_get, _wrap_SHardware_sampleSizeL_set },
    { "generatorType0", _wrap_SHardware_generatorType0_get, _wrap_SHardware_generatorType0_set },
    { "generatorVoltage0", _wrap_SHardware_generatorVoltage0_get, _wrap_SHardware_generatorVoltage0_set },
    { "generatorOffset0", _wrap_SHardware_generatorOffset0_get, _wrap_SHardware_generatorOffset0_set },
    { "generatorDeltaH0", _wrap_SHardware_generatorDeltaH0_get, _wrap_SHardware_generatorDeltaH0_set },
    { "generatorDeltaL0", _wrap_SHardware_generatorDeltaL0_get, _wrap_SHardware_generatorDeltaL0_set },
    { "generatorSqueareDuty0", _wrap_SHardware_generatorSqueareDuty0_get, _wrap_SHardware_generatorSqueareDuty0_set },
    { "generatorType1", _wrap_SHardware_generatorType1_get, _wrap_SHardware_generatorType1_set },
    { "generatorVoltage1", _wrap_SHardware_generatorVoltage1_get, _wrap_SHardware_generatorVoltage1_set },
    { "generatorOffset1", _wrap_SHardware_generatorOffset1_get, _wrap_SHardware_generatorOffset1_set },
    { "generatorDeltaH1", _wrap_SHardware_generatorDeltaH1_get, _wrap_SHardware_generatorDeltaH1_set },
    { "generatorDeltaL1", _wrap_SHardware_generatorDeltaL1_get, _wrap_SHardware_generatorDeltaL1_set },
    { "generatorSqueareDuty1", _wrap_SHardware_generatorSqueareDuty1_get, _wrap_SHardware_generatorSqueareDuty1_set },
    { "digitalPattern1a", _wrap_SHardware_digitalPattern1a_get, _wrap_SHardware_digitalPattern1a_set },
    { "digitalPattern1b", _wrap_SHardware_digitalPattern1b_get, _wrap_SHardware_digitalPattern1b_set },
    { "digitalMask1", _wrap_SHardware_digitalMask1_get, _wrap_SHardware_digitalMask1_set },
    { "digitalPattern2a", _wrap_SHardware_digitalPattern2a_get, _wrap_SHardware_digitalPattern2a_set },
    { "digitalPattern2b", _wrap_SHardware_digitalPattern2b_get, _wrap_SHardware_digitalPattern2b_set },
    { "digitalMask2", _wrap_SHardware_digitalMask2_get, _wrap_SHardware_digitalMask2_set },
    { "digitalPattern3a", _wrap_SHardware_digitalPattern3a_get, _wrap_SHardware_digitalPattern3a_set },
    { "digitalPattern3b", _wrap_SHardware_digitalPattern3b_get, _wrap_SHardware_digitalPattern3b_set },
    { "digitalMask3", _wrap_SHardware_digitalMask3_get, _wrap_SHardware_digitalMask3_set },
    { "digitalPattern4a", _wrap_SHardware_digitalPattern4a_get, _wrap_SHardware_digitalPattern4a_set },
    { "digitalPattern4b", _wrap_SHardware_digitalPattern4b_get, _wrap_SHardware_digitalPattern4b_set },
    { "digitalMask4", _wrap_SHardware_digitalMask4_get, _wrap_SHardware_digitalMask4_set },
    { "dt_delayMaxcnt1", _wrap_SHardware_dt_delayMaxcnt1_get, _wrap_SHardware_dt_delayMaxcnt1_set },
    { "dt_delayMaxcnt2", _wrap_SHardware_dt_delayMaxcnt2_get, _wrap_SHardware_dt_delayMaxcnt2_set },
    { "dt_delayMaxcnt3", _wrap_SHardware_dt_delayMaxcnt3_get, _wrap_SHardware_dt_delayMaxcnt3_set },
    { "dt_delayMaxcnt4", _wrap_SHardware_dt_delayMaxcnt4_get, _wrap_SHardware_dt_delayMaxcnt4_set },
    { "dt_control", _wrap_SHardware_dt_control_get, _wrap_SHardware_dt_control_set },
    { "digitalVoltage", _wrap_SHardware_digitalVoltage_get, _wrap_SHardware_digitalVoltage_set },
    { "digitalInputOutput", _wrap_SHardware_digitalInputOutput_get, _wrap_SHardware_digitalInputOutput_set },
    { "digitalOutputBit", _wrap_SHardware_digitalOutputBit_get, _wrap_SHardware_digitalOutputBit_set },
    { "digitalOutputMask", _wrap_SHardware_digitalOutputMask_get, _wrap_SHardware_digitalOutputMask_set },
    { "digitalClkDivideH", _wrap_SHardware_digitalClkDivideH_get, _wrap_SHardware_digitalClkDivideH_set },
    { "digitalClkDivideL", _wrap_SHardware_digitalClkDivideL_get, _wrap_SHardware_digitalClkDivideL_set },
    { "average", _wrap_SHardware_average_get, _wrap_SHardware_average_set },
    { "preTriggerH", _wrap_SHardware_preTriggerH_get, _wrap_SHardware_preTriggerH_set },
    { "preTriggerL", _wrap_SHardware_preTriggerL_get, _wrap_SHardware_preTriggerL_set },
    { "generatorPhase", _wrap_SHardware_generatorPhase_get, _wrap_SHardware_generatorPhase_set },
    { "reserved2", _wrap_SHardware_reserved2_get, _wrap_SHardware_reserved2_set },
    { "reserved3", _wrap_SHardware_reserved3_get, _wrap_SHardware_reserved3_set },
    { "reserved4", _wrap_SHardware_reserved4_get, _wrap_SHardware_reserved4_set },
    { "reserved5", _wrap_SHardware_reserved5_get, _wrap_SHardware_reserved5_set },
    {0,0,0}
};
static swig_lua_method swig_SHardware_methods[]= {
    {0,0}
};
static swig_lua_method swig_SHardware_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SHardware_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SHardware_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SHardware_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SHardware_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SHardware_Sf_SwigStatic = {
    "SHardware",
    swig_SHardware_Sf_SwigStatic_methods,
    swig_SHardware_Sf_SwigStatic_attributes,
    swig_SHardware_Sf_SwigStatic_constants,
    swig_SHardware_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SHardware_bases[] = {0};
static const char *swig_SHardware_base_names[] = {0};
static swig_lua_class _wrap_class_SHardware = { "SHardware", "SHardware", &SWIGTYPE_p_SHardware,_proxy__wrap_new_SHardware, swig_delete_SHardware, swig_SHardware_methods, swig_SHardware_attributes, &swig_SHardware_Sf_SwigStatic, swig_SHardware_meta, swig_SHardware_bases, swig_SHardware_base_names };

static int _wrap_SArrayMagic_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayMagic *arg1 = (SArrayMagic *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayMagic::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayMagic::bytes",1,"SArrayMagic *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayMagic::bytes",2,"byte [4]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayMagic,0))){
    SWIG_fail_ptr("SArrayMagic_bytes_set",1,SWIGTYPE_p_SArrayMagic);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayMagic_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)4; ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayMagic_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayMagic *arg1 = (SArrayMagic *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayMagic::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayMagic::bytes",1,"SArrayMagic *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayMagic,0))){
    SWIG_fail_ptr("SArrayMagic_bytes_get",1,SWIGTYPE_p_SArrayMagic);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayMagic___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayMagic *arg1 = (SArrayMagic *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayMagic::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayMagic::__len",1,"SArrayMagic const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayMagic,0))){
    SWIG_fail_ptr("SArrayMagic___len",1,SWIGTYPE_p_SArrayMagic);
  }
  
  result = (int)SArrayMagic___len((SArrayMagic const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayMagic___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayMagic *arg1 = (SArrayMagic *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayMagic::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayMagic::__getitem",1,"SArrayMagic *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayMagic::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayMagic,0))){
    SWIG_fail_ptr("SArrayMagic___getitem",1,SWIGTYPE_p_SArrayMagic);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayMagic___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayMagic___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayMagic *arg1 = (SArrayMagic *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayMagic::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayMagic::__setitem",1,"SArrayMagic *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayMagic::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayMagic::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayMagic,0))){
    SWIG_fail_ptr("SArrayMagic___setitem",1,SWIGTYPE_p_SArrayMagic);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayMagic___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayMagic(lua_State* L) {
  int SWIG_arg = 0;
  SArrayMagic *result = 0 ;
  
  SWIG_check_num_args("SArrayMagic::SArrayMagic",0,0)
  result = (SArrayMagic *)calloc(1, sizeof(SArrayMagic));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayMagic,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayMagic(void *obj) {
SArrayMagic *arg1 = (SArrayMagic *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayMagic(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayMagic);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayMagic_attributes[] = {
    { "bytes", _wrap_SArrayMagic_bytes_get, _wrap_SArrayMagic_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayMagic_methods[]= {
    { "__len", _wrap_SArrayMagic___len},
    { "__getitem", _wrap_SArrayMagic___getitem},
    { "__setitem", _wrap_SArrayMagic___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayMagic_meta[] = {
    { "__len", _wrap_SArrayMagic___len},
    { "__getitem", _wrap_SArrayMagic___getitem},
    { "__setitem", _wrap_SArrayMagic___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayMagic_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayMagic_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayMagic_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayMagic_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayMagic_Sf_SwigStatic = {
    "SArrayMagic",
    swig_SArrayMagic_Sf_SwigStatic_methods,
    swig_SArrayMagic_Sf_SwigStatic_attributes,
    swig_SArrayMagic_Sf_SwigStatic_constants,
    swig_SArrayMagic_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayMagic_bases[] = {0};
static const char *swig_SArrayMagic_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayMagic = { "SArrayMagic", "SArrayMagic", &SWIGTYPE_p_SArrayMagic,_proxy__wrap_new_SArrayMagic, swig_delete_SArrayMagic, swig_SArrayMagic_methods, swig_SArrayMagic_attributes, &swig_SArrayMagic_Sf_SwigStatic, swig_SArrayMagic_meta, swig_SArrayMagic_bases, swig_SArrayMagic_base_names };

static int _wrap_SArrayETS_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayETS *arg1 = (SArrayETS *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayETS::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayETS::bytes",1,"SArrayETS *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayETS::bytes",2,"byte [1]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayETS,0))){
    SWIG_fail_ptr("SArrayETS_bytes_set",1,SWIGTYPE_p_SArrayETS);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayETS_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)1; ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayETS_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayETS *arg1 = (SArrayETS *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayETS::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayETS::bytes",1,"SArrayETS *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayETS,0))){
    SWIG_fail_ptr("SArrayETS_bytes_get",1,SWIGTYPE_p_SArrayETS);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayETS___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayETS *arg1 = (SArrayETS *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayETS::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayETS::__len",1,"SArrayETS const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayETS,0))){
    SWIG_fail_ptr("SArrayETS___len",1,SWIGTYPE_p_SArrayETS);
  }
  
  result = (int)SArrayETS___len((SArrayETS const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayETS___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayETS *arg1 = (SArrayETS *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayETS::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayETS::__getitem",1,"SArrayETS *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayETS::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayETS,0))){
    SWIG_fail_ptr("SArrayETS___getitem",1,SWIGTYPE_p_SArrayETS);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayETS___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayETS___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayETS *arg1 = (SArrayETS *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayETS::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayETS::__setitem",1,"SArrayETS *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayETS::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayETS::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayETS,0))){
    SWIG_fail_ptr("SArrayETS___setitem",1,SWIGTYPE_p_SArrayETS);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayETS___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayETS(lua_State* L) {
  int SWIG_arg = 0;
  SArrayETS *result = 0 ;
  
  SWIG_check_num_args("SArrayETS::SArrayETS",0,0)
  result = (SArrayETS *)calloc(1, sizeof(SArrayETS));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayETS,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayETS(void *obj) {
SArrayETS *arg1 = (SArrayETS *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayETS(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayETS);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayETS_attributes[] = {
    { "bytes", _wrap_SArrayETS_bytes_get, _wrap_SArrayETS_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayETS_methods[]= {
    { "__len", _wrap_SArrayETS___len},
    { "__getitem", _wrap_SArrayETS___getitem},
    { "__setitem", _wrap_SArrayETS___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayETS_meta[] = {
    { "__len", _wrap_SArrayETS___len},
    { "__getitem", _wrap_SArrayETS___getitem},
    { "__setitem", _wrap_SArrayETS___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayETS_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayETS_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayETS_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayETS_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayETS_Sf_SwigStatic = {
    "SArrayETS",
    swig_SArrayETS_Sf_SwigStatic_methods,
    swig_SArrayETS_Sf_SwigStatic_attributes,
    swig_SArrayETS_Sf_SwigStatic_constants,
    swig_SArrayETS_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayETS_bases[] = {0};
static const char *swig_SArrayETS_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayETS = { "SArrayETS", "SArrayETS", &SWIGTYPE_p_SArrayETS,_proxy__wrap_new_SArrayETS, swig_delete_SArrayETS, swig_SArrayETS_methods, swig_SArrayETS_attributes, &swig_SArrayETS_Sf_SwigStatic, swig_SArrayETS_meta, swig_SArrayETS_bases, swig_SArrayETS_base_names };

static int _wrap_SArrayPaddingBefore_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingBefore *arg1 = (SArrayPaddingBefore *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayPaddingBefore::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingBefore::bytes",1,"SArrayPaddingBefore *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayPaddingBefore::bytes",2,"byte [251]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingBefore,0))){
    SWIG_fail_ptr("SArrayPaddingBefore_bytes_set",1,SWIGTYPE_p_SArrayPaddingBefore);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayPaddingBefore_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)251; ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayPaddingBefore_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingBefore *arg1 = (SArrayPaddingBefore *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayPaddingBefore::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingBefore::bytes",1,"SArrayPaddingBefore *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingBefore,0))){
    SWIG_fail_ptr("SArrayPaddingBefore_bytes_get",1,SWIGTYPE_p_SArrayPaddingBefore);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayPaddingBefore___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingBefore *arg1 = (SArrayPaddingBefore *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayPaddingBefore::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingBefore::__len",1,"SArrayPaddingBefore const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingBefore,0))){
    SWIG_fail_ptr("SArrayPaddingBefore___len",1,SWIGTYPE_p_SArrayPaddingBefore);
  }
  
  result = (int)SArrayPaddingBefore___len((SArrayPaddingBefore const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayPaddingBefore___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingBefore *arg1 = (SArrayPaddingBefore *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayPaddingBefore::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingBefore::__getitem",1,"SArrayPaddingBefore *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayPaddingBefore::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingBefore,0))){
    SWIG_fail_ptr("SArrayPaddingBefore___getitem",1,SWIGTYPE_p_SArrayPaddingBefore);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayPaddingBefore___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayPaddingBefore___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingBefore *arg1 = (SArrayPaddingBefore *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayPaddingBefore::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingBefore::__setitem",1,"SArrayPaddingBefore *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayPaddingBefore::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayPaddingBefore::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingBefore,0))){
    SWIG_fail_ptr("SArrayPaddingBefore___setitem",1,SWIGTYPE_p_SArrayPaddingBefore);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayPaddingBefore___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayPaddingBefore(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingBefore *result = 0 ;
  
  SWIG_check_num_args("SArrayPaddingBefore::SArrayPaddingBefore",0,0)
  result = (SArrayPaddingBefore *)calloc(1, sizeof(SArrayPaddingBefore));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayPaddingBefore,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayPaddingBefore(void *obj) {
SArrayPaddingBefore *arg1 = (SArrayPaddingBefore *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayPaddingBefore(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayPaddingBefore);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayPaddingBefore_attributes[] = {
    { "bytes", _wrap_SArrayPaddingBefore_bytes_get, _wrap_SArrayPaddingBefore_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayPaddingBefore_methods[]= {
    { "__len", _wrap_SArrayPaddingBefore___len},
    { "__getitem", _wrap_SArrayPaddingBefore___getitem},
    { "__setitem", _wrap_SArrayPaddingBefore___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayPaddingBefore_meta[] = {
    { "__len", _wrap_SArrayPaddingBefore___len},
    { "__getitem", _wrap_SArrayPaddingBefore___getitem},
    { "__setitem", _wrap_SArrayPaddingBefore___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayPaddingBefore_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayPaddingBefore_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayPaddingBefore_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayPaddingBefore_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayPaddingBefore_Sf_SwigStatic = {
    "SArrayPaddingBefore",
    swig_SArrayPaddingBefore_Sf_SwigStatic_methods,
    swig_SArrayPaddingBefore_Sf_SwigStatic_attributes,
    swig_SArrayPaddingBefore_Sf_SwigStatic_constants,
    swig_SArrayPaddingBefore_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayPaddingBefore_bases[] = {0};
static const char *swig_SArrayPaddingBefore_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayPaddingBefore = { "SArrayPaddingBefore", "SArrayPaddingBefore", &SWIGTYPE_p_SArrayPaddingBefore,_proxy__wrap_new_SArrayPaddingBefore, swig_delete_SArrayPaddingBefore, swig_SArrayPaddingBefore_methods, swig_SArrayPaddingBefore_attributes, &swig_SArrayPaddingBefore_Sf_SwigStatic, swig_SArrayPaddingBefore_meta, swig_SArrayPaddingBefore_bases, swig_SArrayPaddingBefore_base_names };

static int _wrap_SArrayHardware_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayHardware *arg1 = (SArrayHardware *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayHardware::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayHardware::bytes",1,"SArrayHardware *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayHardware::bytes",2,"byte [128]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayHardware,0))){
    SWIG_fail_ptr("SArrayHardware_bytes_set",1,SWIGTYPE_p_SArrayHardware);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayHardware_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)128; ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayHardware_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayHardware *arg1 = (SArrayHardware *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayHardware::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayHardware::bytes",1,"SArrayHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayHardware,0))){
    SWIG_fail_ptr("SArrayHardware_bytes_get",1,SWIGTYPE_p_SArrayHardware);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayHardware___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayHardware *arg1 = (SArrayHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayHardware::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayHardware::__len",1,"SArrayHardware const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayHardware,0))){
    SWIG_fail_ptr("SArrayHardware___len",1,SWIGTYPE_p_SArrayHardware);
  }
  
  result = (int)SArrayHardware___len((SArrayHardware const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayHardware___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayHardware *arg1 = (SArrayHardware *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayHardware::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayHardware::__getitem",1,"SArrayHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayHardware::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayHardware,0))){
    SWIG_fail_ptr("SArrayHardware___getitem",1,SWIGTYPE_p_SArrayHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayHardware___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayHardware___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayHardware *arg1 = (SArrayHardware *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayHardware::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayHardware::__setitem",1,"SArrayHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayHardware::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayHardware::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayHardware,0))){
    SWIG_fail_ptr("SArrayHardware___setitem",1,SWIGTYPE_p_SArrayHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayHardware___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayHardware(lua_State* L) {
  int SWIG_arg = 0;
  SArrayHardware *result = 0 ;
  
  SWIG_check_num_args("SArrayHardware::SArrayHardware",0,0)
  result = (SArrayHardware *)calloc(1, sizeof(SArrayHardware));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayHardware,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayHardware(void *obj) {
SArrayHardware *arg1 = (SArrayHardware *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayHardware(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayHardware);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayHardware_attributes[] = {
    { "bytes", _wrap_SArrayHardware_bytes_get, _wrap_SArrayHardware_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayHardware_methods[]= {
    { "__len", _wrap_SArrayHardware___len},
    { "__getitem", _wrap_SArrayHardware___getitem},
    { "__setitem", _wrap_SArrayHardware___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayHardware_meta[] = {
    { "__len", _wrap_SArrayHardware___len},
    { "__getitem", _wrap_SArrayHardware___getitem},
    { "__setitem", _wrap_SArrayHardware___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayHardware_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayHardware_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayHardware_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayHardware_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayHardware_Sf_SwigStatic = {
    "SArrayHardware",
    swig_SArrayHardware_Sf_SwigStatic_methods,
    swig_SArrayHardware_Sf_SwigStatic_attributes,
    swig_SArrayHardware_Sf_SwigStatic_constants,
    swig_SArrayHardware_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayHardware_bases[] = {0};
static const char *swig_SArrayHardware_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayHardware = { "SArrayHardware", "SArrayHardware", &SWIGTYPE_p_SArrayHardware,_proxy__wrap_new_SArrayHardware, swig_delete_SArrayHardware, swig_SArrayHardware_methods, swig_SArrayHardware_attributes, &swig_SArrayHardware_Sf_SwigStatic, swig_SArrayHardware_meta, swig_SArrayHardware_bases, swig_SArrayHardware_base_names };

static int _wrap_SArrayPaddingAfter_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingAfter *arg1 = (SArrayPaddingAfter *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayPaddingAfter::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingAfter::bytes",1,"SArrayPaddingAfter *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayPaddingAfter::bytes",2,"byte [639]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingAfter,0))){
    SWIG_fail_ptr("SArrayPaddingAfter_bytes_set",1,SWIGTYPE_p_SArrayPaddingAfter);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayPaddingAfter_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)639; ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayPaddingAfter_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingAfter *arg1 = (SArrayPaddingAfter *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayPaddingAfter::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingAfter::bytes",1,"SArrayPaddingAfter *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingAfter,0))){
    SWIG_fail_ptr("SArrayPaddingAfter_bytes_get",1,SWIGTYPE_p_SArrayPaddingAfter);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayPaddingAfter___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingAfter *arg1 = (SArrayPaddingAfter *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayPaddingAfter::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingAfter::__len",1,"SArrayPaddingAfter const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingAfter,0))){
    SWIG_fail_ptr("SArrayPaddingAfter___len",1,SWIGTYPE_p_SArrayPaddingAfter);
  }
  
  result = (int)SArrayPaddingAfter___len((SArrayPaddingAfter const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayPaddingAfter___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingAfter *arg1 = (SArrayPaddingAfter *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayPaddingAfter::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingAfter::__getitem",1,"SArrayPaddingAfter *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayPaddingAfter::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingAfter,0))){
    SWIG_fail_ptr("SArrayPaddingAfter___getitem",1,SWIGTYPE_p_SArrayPaddingAfter);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayPaddingAfter___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayPaddingAfter___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingAfter *arg1 = (SArrayPaddingAfter *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayPaddingAfter::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayPaddingAfter::__setitem",1,"SArrayPaddingAfter *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayPaddingAfter::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayPaddingAfter::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayPaddingAfter,0))){
    SWIG_fail_ptr("SArrayPaddingAfter___setitem",1,SWIGTYPE_p_SArrayPaddingAfter);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayPaddingAfter___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayPaddingAfter(lua_State* L) {
  int SWIG_arg = 0;
  SArrayPaddingAfter *result = 0 ;
  
  SWIG_check_num_args("SArrayPaddingAfter::SArrayPaddingAfter",0,0)
  result = (SArrayPaddingAfter *)calloc(1, sizeof(SArrayPaddingAfter));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayPaddingAfter,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayPaddingAfter(void *obj) {
SArrayPaddingAfter *arg1 = (SArrayPaddingAfter *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayPaddingAfter(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayPaddingAfter);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayPaddingAfter_attributes[] = {
    { "bytes", _wrap_SArrayPaddingAfter_bytes_get, _wrap_SArrayPaddingAfter_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayPaddingAfter_methods[]= {
    { "__len", _wrap_SArrayPaddingAfter___len},
    { "__getitem", _wrap_SArrayPaddingAfter___getitem},
    { "__setitem", _wrap_SArrayPaddingAfter___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayPaddingAfter_meta[] = {
    { "__len", _wrap_SArrayPaddingAfter___len},
    { "__getitem", _wrap_SArrayPaddingAfter___getitem},
    { "__setitem", _wrap_SArrayPaddingAfter___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayPaddingAfter_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayPaddingAfter_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayPaddingAfter_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayPaddingAfter_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayPaddingAfter_Sf_SwigStatic = {
    "SArrayPaddingAfter",
    swig_SArrayPaddingAfter_Sf_SwigStatic_methods,
    swig_SArrayPaddingAfter_Sf_SwigStatic_attributes,
    swig_SArrayPaddingAfter_Sf_SwigStatic_constants,
    swig_SArrayPaddingAfter_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayPaddingAfter_bases[] = {0};
static const char *swig_SArrayPaddingAfter_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayPaddingAfter = { "SArrayPaddingAfter", "SArrayPaddingAfter", &SWIGTYPE_p_SArrayPaddingAfter,_proxy__wrap_new_SArrayPaddingAfter, swig_delete_SArrayPaddingAfter, swig_SArrayPaddingAfter_methods, swig_SArrayPaddingAfter_attributes, &swig_SArrayPaddingAfter_Sf_SwigStatic, swig_SArrayPaddingAfter_meta, swig_SArrayPaddingAfter_bases, swig_SArrayPaddingAfter_base_names };

static int _wrap_SArrayCrc_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayCrc *arg1 = (SArrayCrc *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayCrc::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayCrc::bytes",1,"SArrayCrc *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayCrc::bytes",2,"byte [1]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayCrc,0))){
    SWIG_fail_ptr("SArrayCrc_bytes_set",1,SWIGTYPE_p_SArrayCrc);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayCrc_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    memcpy(arg1->bytes, arg2, 1);                                                                                             
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayCrc_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayCrc *arg1 = (SArrayCrc *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayCrc::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayCrc::bytes",1,"SArrayCrc *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayCrc,0))){
    SWIG_fail_ptr("SArrayCrc_bytes_get",1,SWIGTYPE_p_SArrayCrc);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayCrc___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayCrc *arg1 = (SArrayCrc *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayCrc::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayCrc::__len",1,"SArrayCrc const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayCrc,0))){
    SWIG_fail_ptr("SArrayCrc___len",1,SWIGTYPE_p_SArrayCrc);
  }
  
  result = (int)SArrayCrc___len((SArrayCrc const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayCrc___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayCrc *arg1 = (SArrayCrc *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayCrc::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayCrc::__getitem",1,"SArrayCrc *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayCrc::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayCrc,0))){
    SWIG_fail_ptr("SArrayCrc___getitem",1,SWIGTYPE_p_SArrayCrc);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayCrc___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayCrc___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayCrc *arg1 = (SArrayCrc *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayCrc::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayCrc::__setitem",1,"SArrayCrc *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayCrc::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayCrc::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayCrc,0))){
    SWIG_fail_ptr("SArrayCrc___setitem",1,SWIGTYPE_p_SArrayCrc);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayCrc___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayCrc(lua_State* L) {
  int SWIG_arg = 0;
  SArrayCrc *result = 0 ;
  
  SWIG_check_num_args("SArrayCrc::SArrayCrc",0,0)
  result = (SArrayCrc *)calloc(1, sizeof(SArrayCrc));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayCrc,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayCrc(void *obj) {
SArrayCrc *arg1 = (SArrayCrc *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayCrc(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayCrc);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayCrc_attributes[] = {
    { "bytes", _wrap_SArrayCrc_bytes_get, _wrap_SArrayCrc_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayCrc_methods[]= {
    { "__len", _wrap_SArrayCrc___len},
    { "__getitem", _wrap_SArrayCrc___getitem},
    { "__setitem", _wrap_SArrayCrc___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayCrc_meta[] = {
    { "__len", _wrap_SArrayCrc___len},
    { "__getitem", _wrap_SArrayCrc___getitem},
    { "__setitem", _wrap_SArrayCrc___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayCrc_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayCrc_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayCrc_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayCrc_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayCrc_Sf_SwigStatic = {
    "SArrayCrc",
    swig_SArrayCrc_Sf_SwigStatic_methods,
    swig_SArrayCrc_Sf_SwigStatic_attributes,
    swig_SArrayCrc_Sf_SwigStatic_constants,
    swig_SArrayCrc_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayCrc_bases[] = {0};
static const char *swig_SArrayCrc_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayCrc = { "SArrayCrc", "SArrayCrc", &SWIGTYPE_p_SArrayCrc,_proxy__wrap_new_SArrayCrc, swig_delete_SArrayCrc, swig_SArrayCrc_methods, swig_SArrayCrc_attributes, &swig_SArrayCrc_Sf_SwigStatic, swig_SArrayCrc_meta, swig_SArrayCrc_bases, swig_SArrayCrc_base_names };

static int _wrap_SFrameHeader_magic_set(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayMagic *arg2 = (SArrayMagic *) 0 ;
  
  SWIG_check_num_args("SFrameHeader::magic",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::magic",1,"SFrameHeader *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFrameHeader::magic",2,"SArrayMagic *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_magic_set",1,SWIGTYPE_p_SFrameHeader);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayMagic,0))){
    SWIG_fail_ptr("SFrameHeader_magic_set",2,SWIGTYPE_p_SArrayMagic);
  }
  
  if (arg1) (arg1)->magic = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_magic_get(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayMagic *result = 0 ;
  
  SWIG_check_num_args("SFrameHeader::magic",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::magic",1,"SFrameHeader *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_magic_get",1,SWIGTYPE_p_SFrameHeader);
  }
  
  result = (SArrayMagic *)& ((arg1)->magic);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayMagic,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_etsDelay_set(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayETS *arg2 = (SArrayETS *) 0 ;
  
  SWIG_check_num_args("SFrameHeader::etsDelay",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::etsDelay",1,"SFrameHeader *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFrameHeader::etsDelay",2,"SArrayETS *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_etsDelay_set",1,SWIGTYPE_p_SFrameHeader);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayETS,0))){
    SWIG_fail_ptr("SFrameHeader_etsDelay_set",2,SWIGTYPE_p_SArrayETS);
  }
  
  if (arg1) (arg1)->etsDelay = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_etsDelay_get(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayETS *result = 0 ;
  
  SWIG_check_num_args("SFrameHeader::etsDelay",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::etsDelay",1,"SFrameHeader *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_etsDelay_get",1,SWIGTYPE_p_SFrameHeader);
  }
  
  result = (SArrayETS *)& ((arg1)->etsDelay);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayETS,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_paddBefore_set(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayPaddingBefore *arg2 = (SArrayPaddingBefore *) 0 ;
  
  SWIG_check_num_args("SFrameHeader::paddBefore",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::paddBefore",1,"SFrameHeader *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFrameHeader::paddBefore",2,"SArrayPaddingBefore *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_paddBefore_set",1,SWIGTYPE_p_SFrameHeader);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayPaddingBefore,0))){
    SWIG_fail_ptr("SFrameHeader_paddBefore_set",2,SWIGTYPE_p_SArrayPaddingBefore);
  }
  
  if (arg1) (arg1)->paddBefore = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_paddBefore_get(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayPaddingBefore *result = 0 ;
  
  SWIG_check_num_args("SFrameHeader::paddBefore",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::paddBefore",1,"SFrameHeader *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_paddBefore_get",1,SWIGTYPE_p_SFrameHeader);
  }
  
  result = (SArrayPaddingBefore *)& ((arg1)->paddBefore);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayPaddingBefore,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_hardware_set(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayHardware *arg2 = (SArrayHardware *) 0 ;
  
  SWIG_check_num_args("SFrameHeader::hardware",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::hardware",1,"SFrameHeader *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFrameHeader::hardware",2,"SArrayHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_hardware_set",1,SWIGTYPE_p_SFrameHeader);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayHardware,0))){
    SWIG_fail_ptr("SFrameHeader_hardware_set",2,SWIGTYPE_p_SArrayHardware);
  }
  
  if (arg1) (arg1)->hardware = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_hardware_get(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayHardware *result = 0 ;
  
  SWIG_check_num_args("SFrameHeader::hardware",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::hardware",1,"SFrameHeader *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_hardware_get",1,SWIGTYPE_p_SFrameHeader);
  }
  
  result = (SArrayHardware *)& ((arg1)->hardware);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayHardware,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_paddAfter_set(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayPaddingAfter *arg2 = (SArrayPaddingAfter *) 0 ;
  
  SWIG_check_num_args("SFrameHeader::paddAfter",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::paddAfter",1,"SFrameHeader *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFrameHeader::paddAfter",2,"SArrayPaddingAfter *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_paddAfter_set",1,SWIGTYPE_p_SFrameHeader);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayPaddingAfter,0))){
    SWIG_fail_ptr("SFrameHeader_paddAfter_set",2,SWIGTYPE_p_SArrayPaddingAfter);
  }
  
  if (arg1) (arg1)->paddAfter = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_paddAfter_get(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayPaddingAfter *result = 0 ;
  
  SWIG_check_num_args("SFrameHeader::paddAfter",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::paddAfter",1,"SFrameHeader *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_paddAfter_get",1,SWIGTYPE_p_SFrameHeader);
  }
  
  result = (SArrayPaddingAfter *)& ((arg1)->paddAfter);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayPaddingAfter,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_crc_set(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayCrc *arg2 = (SArrayCrc *) 0 ;
  
  SWIG_check_num_args("SFrameHeader::crc",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::crc",1,"SFrameHeader *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFrameHeader::crc",2,"SArrayCrc *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_crc_set",1,SWIGTYPE_p_SFrameHeader);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayCrc,0))){
    SWIG_fail_ptr("SFrameHeader_crc_set",2,SWIGTYPE_p_SArrayCrc);
  }
  
  if (arg1) (arg1)->crc = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameHeader_crc_get(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SArrayCrc *result = 0 ;
  
  SWIG_check_num_args("SFrameHeader::crc",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameHeader::crc",1,"SFrameHeader *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("SFrameHeader_crc_get",1,SWIGTYPE_p_SFrameHeader);
  }
  
  result = (SArrayCrc *)& ((arg1)->crc);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayCrc,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SFrameHeader(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *result = 0 ;
  
  SWIG_check_num_args("SFrameHeader::SFrameHeader",0,0)
  result = (SFrameHeader *)calloc(1, sizeof(SFrameHeader));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFrameHeader,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SFrameHeader(void *obj) {
SFrameHeader *arg1 = (SFrameHeader *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SFrameHeader(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SFrameHeader);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SFrameHeader_attributes[] = {
    { "magic", _wrap_SFrameHeader_magic_get, _wrap_SFrameHeader_magic_set },
    { "etsDelay", _wrap_SFrameHeader_etsDelay_get, _wrap_SFrameHeader_etsDelay_set },
    { "paddBefore", _wrap_SFrameHeader_paddBefore_get, _wrap_SFrameHeader_paddBefore_set },
    { "hardware", _wrap_SFrameHeader_hardware_get, _wrap_SFrameHeader_hardware_set },
    { "paddAfter", _wrap_SFrameHeader_paddAfter_get, _wrap_SFrameHeader_paddAfter_set },
    { "crc", _wrap_SFrameHeader_crc_get, _wrap_SFrameHeader_crc_set },
    {0,0,0}
};
static swig_lua_method swig_SFrameHeader_methods[]= {
    {0,0}
};
static swig_lua_method swig_SFrameHeader_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SFrameHeader_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SFrameHeader_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SFrameHeader_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SFrameHeader_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SFrameHeader_Sf_SwigStatic = {
    "SFrameHeader",
    swig_SFrameHeader_Sf_SwigStatic_methods,
    swig_SFrameHeader_Sf_SwigStatic_attributes,
    swig_SFrameHeader_Sf_SwigStatic_constants,
    swig_SFrameHeader_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SFrameHeader_bases[] = {0};
static const char *swig_SFrameHeader_base_names[] = {0};
static swig_lua_class _wrap_class_SFrameHeader = { "SFrameHeader", "SFrameHeader", &SWIGTYPE_p_SFrameHeader,_proxy__wrap_new_SFrameHeader, swig_delete_SFrameHeader, swig_SFrameHeader_methods, swig_SFrameHeader_attributes, &swig_SFrameHeader_Sf_SwigStatic, swig_SFrameHeader_meta, swig_SFrameHeader_bases, swig_SFrameHeader_base_names };

static int _wrap_SArrayString256_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayString256 *arg1 = (SArrayString256 *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayString256::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayString256::bytes",1,"SArrayString256 *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayString256::bytes",2,"byte [256]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayString256,0))){
    SWIG_fail_ptr("SArrayString256_bytes_set",1,SWIGTYPE_p_SArrayString256);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayString256_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)256; ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayString256_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayString256 *arg1 = (SArrayString256 *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayString256::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayString256::bytes",1,"SArrayString256 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayString256,0))){
    SWIG_fail_ptr("SArrayString256_bytes_get",1,SWIGTYPE_p_SArrayString256);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayString256___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayString256 *arg1 = (SArrayString256 *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayString256::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayString256::__len",1,"SArrayString256 const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayString256,0))){
    SWIG_fail_ptr("SArrayString256___len",1,SWIGTYPE_p_SArrayString256);
  }
  
  result = (int)SArrayString256___len((SArrayString256 const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayString256___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayString256 *arg1 = (SArrayString256 *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayString256::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayString256::__getitem",1,"SArrayString256 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayString256::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayString256,0))){
    SWIG_fail_ptr("SArrayString256___getitem",1,SWIGTYPE_p_SArrayString256);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayString256___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayString256___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayString256 *arg1 = (SArrayString256 *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayString256::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayString256::__setitem",1,"SArrayString256 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayString256::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayString256::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayString256,0))){
    SWIG_fail_ptr("SArrayString256___setitem",1,SWIGTYPE_p_SArrayString256);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayString256___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayString256(lua_State* L) {
  int SWIG_arg = 0;
  SArrayString256 *result = 0 ;
  
  SWIG_check_num_args("SArrayString256::SArrayString256",0,0)
  result = (SArrayString256 *)calloc(1, sizeof(SArrayString256));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayString256,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayString256(void *obj) {
SArrayString256 *arg1 = (SArrayString256 *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayString256(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayString256);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayString256_attributes[] = {
    { "bytes", _wrap_SArrayString256_bytes_get, _wrap_SArrayString256_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayString256_methods[]= {
    { "__len", _wrap_SArrayString256___len},
    { "__getitem", _wrap_SArrayString256___getitem},
    { "__setitem", _wrap_SArrayString256___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayString256_meta[] = {
    { "__len", _wrap_SArrayString256___len},
    { "__getitem", _wrap_SArrayString256___getitem},
    { "__setitem", _wrap_SArrayString256___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayString256_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayString256_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayString256_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayString256_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayString256_Sf_SwigStatic = {
    "SArrayString256",
    swig_SArrayString256_Sf_SwigStatic_methods,
    swig_SArrayString256_Sf_SwigStatic_attributes,
    swig_SArrayString256_Sf_SwigStatic_constants,
    swig_SArrayString256_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayString256_bases[] = {0};
static const char *swig_SArrayString256_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayString256 = { "SArrayString256", "SArrayString256", &SWIGTYPE_p_SArrayString256,_proxy__wrap_new_SArrayString256, swig_delete_SArrayString256, swig_SArrayString256_methods, swig_SArrayString256_attributes, &swig_SArrayString256_Sf_SwigStatic, swig_SArrayString256_meta, swig_SArrayString256_bases, swig_SArrayString256_base_names };

static int _wrap_SArrayFrameData_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFrameData *arg1 = (SArrayFrameData *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayFrameData::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFrameData::bytes",1,"SArrayFrameData *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayFrameData::bytes",2,"byte [(512*1024*1024)]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFrameData,0))){
    SWIG_fail_ptr("SArrayFrameData_bytes_set",1,SWIGTYPE_p_SArrayFrameData);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayFrameData_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)(512*1024*1024); ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFrameData_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFrameData *arg1 = (SArrayFrameData *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayFrameData::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFrameData::bytes",1,"SArrayFrameData *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFrameData,0))){
    SWIG_fail_ptr("SArrayFrameData_bytes_get",1,SWIGTYPE_p_SArrayFrameData);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFrameData___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFrameData *arg1 = (SArrayFrameData *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayFrameData::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFrameData::__len",1,"SArrayFrameData const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFrameData,0))){
    SWIG_fail_ptr("SArrayFrameData___len",1,SWIGTYPE_p_SArrayFrameData);
  }
  
  result = (int)SArrayFrameData___len((SArrayFrameData const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFrameData___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFrameData *arg1 = (SArrayFrameData *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayFrameData::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFrameData::__getitem",1,"SArrayFrameData *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayFrameData::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFrameData,0))){
    SWIG_fail_ptr("SArrayFrameData___getitem",1,SWIGTYPE_p_SArrayFrameData);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayFrameData___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFrameData___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFrameData *arg1 = (SArrayFrameData *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayFrameData::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFrameData::__setitem",1,"SArrayFrameData *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayFrameData::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayFrameData::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFrameData,0))){
    SWIG_fail_ptr("SArrayFrameData___setitem",1,SWIGTYPE_p_SArrayFrameData);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayFrameData___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayFrameData(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFrameData *result = 0 ;
  
  SWIG_check_num_args("SArrayFrameData::SArrayFrameData",0,0)
  result = (SArrayFrameData *)calloc(1, sizeof(SArrayFrameData));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayFrameData,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayFrameData(void *obj) {
SArrayFrameData *arg1 = (SArrayFrameData *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayFrameData(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayFrameData);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayFrameData_attributes[] = {
    { "bytes", _wrap_SArrayFrameData_bytes_get, _wrap_SArrayFrameData_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayFrameData_methods[]= {
    { "__len", _wrap_SArrayFrameData___len},
    { "__getitem", _wrap_SArrayFrameData___getitem},
    { "__setitem", _wrap_SArrayFrameData___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayFrameData_meta[] = {
    { "__len", _wrap_SArrayFrameData___len},
    { "__getitem", _wrap_SArrayFrameData___getitem},
    { "__setitem", _wrap_SArrayFrameData___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayFrameData_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayFrameData_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayFrameData_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayFrameData_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayFrameData_Sf_SwigStatic = {
    "SArrayFrameData",
    swig_SArrayFrameData_Sf_SwigStatic_methods,
    swig_SArrayFrameData_Sf_SwigStatic_attributes,
    swig_SArrayFrameData_Sf_SwigStatic_constants,
    swig_SArrayFrameData_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayFrameData_bases[] = {0};
static const char *swig_SArrayFrameData_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayFrameData = { "SArrayFrameData", "SArrayFrameData", &SWIGTYPE_p_SArrayFrameData,_proxy__wrap_new_SArrayFrameData, swig_delete_SArrayFrameData, swig_SArrayFrameData_methods, swig_SArrayFrameData_attributes, &swig_SArrayFrameData_Sf_SwigStatic, swig_SArrayFrameData_meta, swig_SArrayFrameData_bases, swig_SArrayFrameData_base_names };

static int _wrap_SFrameData_data_set(lua_State* L) {
  int SWIG_arg = 0;
  SFrameData *arg1 = (SFrameData *) 0 ;
  SArrayFrameData *arg2 = (SArrayFrameData *) 0 ;
  
  SWIG_check_num_args("SFrameData::data",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameData::data",1,"SFrameData *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFrameData::data",2,"SArrayFrameData *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameData,0))){
    SWIG_fail_ptr("SFrameData_data_set",1,SWIGTYPE_p_SFrameData);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayFrameData,0))){
    SWIG_fail_ptr("SFrameData_data_set",2,SWIGTYPE_p_SArrayFrameData);
  }
  
  if (arg1) (arg1)->data = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFrameData_data_get(lua_State* L) {
  int SWIG_arg = 0;
  SFrameData *arg1 = (SFrameData *) 0 ;
  SArrayFrameData *result = 0 ;
  
  SWIG_check_num_args("SFrameData::data",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFrameData::data",1,"SFrameData *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameData,0))){
    SWIG_fail_ptr("SFrameData_data_get",1,SWIGTYPE_p_SFrameData);
  }
  
  result = (SArrayFrameData *)& ((arg1)->data);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayFrameData,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SFrameData(lua_State* L) {
  int SWIG_arg = 0;
  SFrameData *result = 0 ;
  
  SWIG_check_num_args("SFrameData::SFrameData",0,0)
  result = (SFrameData *)calloc(1, sizeof(SFrameData));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFrameData,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SFrameData(void *obj) {
SFrameData *arg1 = (SFrameData *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SFrameData(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SFrameData);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SFrameData_attributes[] = {
    { "data", _wrap_SFrameData_data_get, _wrap_SFrameData_data_set },
    {0,0,0}
};
static swig_lua_method swig_SFrameData_methods[]= {
    {0,0}
};
static swig_lua_method swig_SFrameData_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SFrameData_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SFrameData_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SFrameData_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SFrameData_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SFrameData_Sf_SwigStatic = {
    "SFrameData",
    swig_SFrameData_Sf_SwigStatic_methods,
    swig_SFrameData_Sf_SwigStatic_attributes,
    swig_SFrameData_Sf_SwigStatic_constants,
    swig_SFrameData_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SFrameData_bases[] = {0};
static const char *swig_SFrameData_base_names[] = {0};
static swig_lua_class _wrap_class_SFrameData = { "SFrameData", "SFrameData", &SWIGTYPE_p_SFrameData,_proxy__wrap_new_SFrameData, swig_delete_SFrameData, swig_SFrameData_methods, swig_SFrameData_attributes, &swig_SFrameData_Sf_SwigStatic, swig_SFrameData_meta, swig_SFrameData_bases, swig_SFrameData_base_names };

static int _wrap_SArrayEEPROM_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayEEPROM *arg1 = (SArrayEEPROM *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayEEPROM::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayEEPROM::bytes",1,"SArrayEEPROM *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayEEPROM::bytes",2,"byte [(256*1024)]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayEEPROM,0))){
    SWIG_fail_ptr("SArrayEEPROM_bytes_set",1,SWIGTYPE_p_SArrayEEPROM);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayEEPROM_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)(256*1024); ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayEEPROM_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayEEPROM *arg1 = (SArrayEEPROM *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayEEPROM::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayEEPROM::bytes",1,"SArrayEEPROM *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayEEPROM,0))){
    SWIG_fail_ptr("SArrayEEPROM_bytes_get",1,SWIGTYPE_p_SArrayEEPROM);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayEEPROM___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayEEPROM *arg1 = (SArrayEEPROM *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayEEPROM::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayEEPROM::__len",1,"SArrayEEPROM const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayEEPROM,0))){
    SWIG_fail_ptr("SArrayEEPROM___len",1,SWIGTYPE_p_SArrayEEPROM);
  }
  
  result = (int)SArrayEEPROM___len((SArrayEEPROM const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayEEPROM___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayEEPROM *arg1 = (SArrayEEPROM *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayEEPROM::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayEEPROM::__getitem",1,"SArrayEEPROM *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayEEPROM::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayEEPROM,0))){
    SWIG_fail_ptr("SArrayEEPROM___getitem",1,SWIGTYPE_p_SArrayEEPROM);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayEEPROM___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayEEPROM___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayEEPROM *arg1 = (SArrayEEPROM *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayEEPROM::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayEEPROM::__setitem",1,"SArrayEEPROM *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayEEPROM::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayEEPROM::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayEEPROM,0))){
    SWIG_fail_ptr("SArrayEEPROM___setitem",1,SWIGTYPE_p_SArrayEEPROM);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayEEPROM___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayEEPROM(lua_State* L) {
  int SWIG_arg = 0;
  SArrayEEPROM *result = 0 ;
  
  SWIG_check_num_args("SArrayEEPROM::SArrayEEPROM",0,0)
  result = (SArrayEEPROM *)calloc(1, sizeof(SArrayEEPROM));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayEEPROM,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayEEPROM(void *obj) {
SArrayEEPROM *arg1 = (SArrayEEPROM *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayEEPROM(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayEEPROM);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayEEPROM_attributes[] = {
    { "bytes", _wrap_SArrayEEPROM_bytes_get, _wrap_SArrayEEPROM_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayEEPROM_methods[]= {
    { "__len", _wrap_SArrayEEPROM___len},
    { "__getitem", _wrap_SArrayEEPROM___getitem},
    { "__setitem", _wrap_SArrayEEPROM___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayEEPROM_meta[] = {
    { "__len", _wrap_SArrayEEPROM___len},
    { "__getitem", _wrap_SArrayEEPROM___getitem},
    { "__setitem", _wrap_SArrayEEPROM___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayEEPROM_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayEEPROM_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayEEPROM_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayEEPROM_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayEEPROM_Sf_SwigStatic = {
    "SArrayEEPROM",
    swig_SArrayEEPROM_Sf_SwigStatic_methods,
    swig_SArrayEEPROM_Sf_SwigStatic_attributes,
    swig_SArrayEEPROM_Sf_SwigStatic_constants,
    swig_SArrayEEPROM_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayEEPROM_bases[] = {0};
static const char *swig_SArrayEEPROM_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayEEPROM = { "SArrayEEPROM", "SArrayEEPROM", &SWIGTYPE_p_SArrayEEPROM,_proxy__wrap_new_SArrayEEPROM, swig_delete_SArrayEEPROM, swig_SArrayEEPROM_methods, swig_SArrayEEPROM_attributes, &swig_SArrayEEPROM_Sf_SwigStatic, swig_SArrayEEPROM_meta, swig_SArrayEEPROM_bases, swig_SArrayEEPROM_base_names };

static int _wrap_SEeprom_data_set(lua_State* L) {
  int SWIG_arg = 0;
  SEeprom *arg1 = (SEeprom *) 0 ;
  SArrayEEPROM *arg2 = (SArrayEEPROM *) 0 ;
  
  SWIG_check_num_args("SEeprom::data",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SEeprom::data",1,"SEeprom *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SEeprom::data",2,"SArrayEEPROM *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SEeprom,0))){
    SWIG_fail_ptr("SEeprom_data_set",1,SWIGTYPE_p_SEeprom);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayEEPROM,0))){
    SWIG_fail_ptr("SEeprom_data_set",2,SWIGTYPE_p_SArrayEEPROM);
  }
  
  if (arg1) (arg1)->data = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SEeprom_data_get(lua_State* L) {
  int SWIG_arg = 0;
  SEeprom *arg1 = (SEeprom *) 0 ;
  SArrayEEPROM *result = 0 ;
  
  SWIG_check_num_args("SEeprom::data",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SEeprom::data",1,"SEeprom *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SEeprom,0))){
    SWIG_fail_ptr("SEeprom_data_get",1,SWIGTYPE_p_SEeprom);
  }
  
  result = (SArrayEEPROM *)& ((arg1)->data);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayEEPROM,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SEeprom(lua_State* L) {
  int SWIG_arg = 0;
  SEeprom *result = 0 ;
  
  SWIG_check_num_args("SEeprom::SEeprom",0,0)
  result = (SEeprom *)calloc(1, sizeof(SEeprom));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SEeprom,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SEeprom(void *obj) {
SEeprom *arg1 = (SEeprom *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SEeprom(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SEeprom);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SEeprom_attributes[] = {
    { "data", _wrap_SEeprom_data_get, _wrap_SEeprom_data_set },
    {0,0,0}
};
static swig_lua_method swig_SEeprom_methods[]= {
    {0,0}
};
static swig_lua_method swig_SEeprom_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SEeprom_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SEeprom_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SEeprom_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SEeprom_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SEeprom_Sf_SwigStatic = {
    "SEeprom",
    swig_SEeprom_Sf_SwigStatic_methods,
    swig_SEeprom_Sf_SwigStatic_attributes,
    swig_SEeprom_Sf_SwigStatic_constants,
    swig_SEeprom_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SEeprom_bases[] = {0};
static const char *swig_SEeprom_base_names[] = {0};
static swig_lua_class _wrap_class_SEeprom = { "SEeprom", "SEeprom", &SWIGTYPE_p_SEeprom,_proxy__wrap_new_SEeprom, swig_delete_SEeprom, swig_SEeprom_methods, swig_SEeprom_attributes, &swig_SEeprom_Sf_SwigStatic, swig_SEeprom_meta, swig_SEeprom_bases, swig_SEeprom_base_names };

static int _wrap_SGUID_data1_set(lua_State* L) {
  int SWIG_arg = 0;
  SGUID *arg1 = (SGUID *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SGUID::data1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGUID::data1",1,"SGUID *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SGUID::data1",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGUID,0))){
    SWIG_fail_ptr("SGUID_data1_set",1,SWIGTYPE_p_SGUID);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->data1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGUID_data1_get(lua_State* L) {
  int SWIG_arg = 0;
  SGUID *arg1 = (SGUID *) 0 ;
  uint result;
  
  SWIG_check_num_args("SGUID::data1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGUID::data1",1,"SGUID *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGUID,0))){
    SWIG_fail_ptr("SGUID_data1_get",1,SWIGTYPE_p_SGUID);
  }
  
  result = (uint) ((arg1)->data1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGUID_data2_set(lua_State* L) {
  int SWIG_arg = 0;
  SGUID *arg1 = (SGUID *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SGUID::data2",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGUID::data2",1,"SGUID *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SGUID::data2",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGUID,0))){
    SWIG_fail_ptr("SGUID_data2_set",1,SWIGTYPE_p_SGUID);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->data2 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGUID_data2_get(lua_State* L) {
  int SWIG_arg = 0;
  SGUID *arg1 = (SGUID *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SGUID::data2",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGUID::data2",1,"SGUID *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGUID,0))){
    SWIG_fail_ptr("SGUID_data2_get",1,SWIGTYPE_p_SGUID);
  }
  
  result = (ushort) ((arg1)->data2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGUID_data3_set(lua_State* L) {
  int SWIG_arg = 0;
  SGUID *arg1 = (SGUID *) 0 ;
  ushort arg2 ;
  
  SWIG_check_num_args("SGUID::data3",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGUID::data3",1,"SGUID *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SGUID::data3",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGUID,0))){
    SWIG_fail_ptr("SGUID_data3_set",1,SWIGTYPE_p_SGUID);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  if (arg1) (arg1)->data3 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGUID_data3_get(lua_State* L) {
  int SWIG_arg = 0;
  SGUID *arg1 = (SGUID *) 0 ;
  ushort result;
  
  SWIG_check_num_args("SGUID::data3",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGUID::data3",1,"SGUID *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGUID,0))){
    SWIG_fail_ptr("SGUID_data3_get",1,SWIGTYPE_p_SGUID);
  }
  
  result = (ushort) ((arg1)->data3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGUID_data4_set(lua_State* L) {
  int SWIG_arg = 0;
  SGUID *arg1 = (SGUID *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SGUID::data4",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGUID::data4",1,"SGUID *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SGUID::data4",2,"byte [8]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGUID,0))){
    SWIG_fail_ptr("SGUID_data4_set",1,SWIGTYPE_p_SGUID);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SGUID_data4_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->data4;
    for (ii = 0; ii < (size_t)8; ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGUID_data4_get(lua_State* L) {
  int SWIG_arg = 0;
  SGUID *arg1 = (SGUID *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SGUID::data4",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGUID::data4",1,"SGUID *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGUID,0))){
    SWIG_fail_ptr("SGUID_data4_get",1,SWIGTYPE_p_SGUID);
  }
  
  result = (byte *)(byte *) ((arg1)->data4);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SGUID(lua_State* L) {
  int SWIG_arg = 0;
  SGUID *result = 0 ;
  
  SWIG_check_num_args("SGUID::SGUID",0,0)
  result = (SGUID *)calloc(1, sizeof(SGUID));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SGUID,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SGUID(void *obj) {
SGUID *arg1 = (SGUID *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SGUID(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SGUID);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SGUID_attributes[] = {
    { "data1", _wrap_SGUID_data1_get, _wrap_SGUID_data1_set },
    { "data2", _wrap_SGUID_data2_get, _wrap_SGUID_data2_set },
    { "data3", _wrap_SGUID_data3_get, _wrap_SGUID_data3_set },
    { "data4", _wrap_SGUID_data4_get, _wrap_SGUID_data4_set },
    {0,0,0}
};
static swig_lua_method swig_SGUID_methods[]= {
    {0,0}
};
static swig_lua_method swig_SGUID_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SGUID_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SGUID_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SGUID_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SGUID_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SGUID_Sf_SwigStatic = {
    "SGUID",
    swig_SGUID_Sf_SwigStatic_methods,
    swig_SGUID_Sf_SwigStatic_attributes,
    swig_SGUID_Sf_SwigStatic_constants,
    swig_SGUID_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SGUID_bases[] = {0};
static const char *swig_SGUID_base_names[] = {0};
static swig_lua_class _wrap_class_SGUID = { "SGUID", "SGUID", &SWIGTYPE_p_SGUID,_proxy__wrap_new_SGUID, swig_delete_SGUID, swig_SGUID_methods, swig_SGUID_attributes, &swig_SGUID_Sf_SwigStatic, swig_SGUID_meta, swig_SGUID_bases, swig_SGUID_base_names };

static int _wrap_SArrayFx3_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFx3 *arg1 = (SArrayFx3 *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayFx3::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFx3::bytes",1,"SArrayFx3 *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayFx3::bytes",2,"byte [16384]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFx3,0))){
    SWIG_fail_ptr("SArrayFx3_bytes_set",1,SWIGTYPE_p_SArrayFx3);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayFx3_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)16384; ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFx3_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFx3 *arg1 = (SArrayFx3 *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayFx3::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFx3::bytes",1,"SArrayFx3 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFx3,0))){
    SWIG_fail_ptr("SArrayFx3_bytes_get",1,SWIGTYPE_p_SArrayFx3);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFx3___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFx3 *arg1 = (SArrayFx3 *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayFx3::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFx3::__len",1,"SArrayFx3 const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFx3,0))){
    SWIG_fail_ptr("SArrayFx3___len",1,SWIGTYPE_p_SArrayFx3);
  }
  
  result = (int)SArrayFx3___len((SArrayFx3 const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFx3___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFx3 *arg1 = (SArrayFx3 *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayFx3::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFx3::__getitem",1,"SArrayFx3 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayFx3::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFx3,0))){
    SWIG_fail_ptr("SArrayFx3___getitem",1,SWIGTYPE_p_SArrayFx3);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayFx3___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFx3___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFx3 *arg1 = (SArrayFx3 *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayFx3::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFx3::__setitem",1,"SArrayFx3 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayFx3::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayFx3::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFx3,0))){
    SWIG_fail_ptr("SArrayFx3___setitem",1,SWIGTYPE_p_SArrayFx3);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayFx3___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayFx3(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFx3 *result = 0 ;
  
  SWIG_check_num_args("SArrayFx3::SArrayFx3",0,0)
  result = (SArrayFx3 *)calloc(1, sizeof(SArrayFx3));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayFx3,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayFx3(void *obj) {
SArrayFx3 *arg1 = (SArrayFx3 *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayFx3(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayFx3);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayFx3_attributes[] = {
    { "bytes", _wrap_SArrayFx3_bytes_get, _wrap_SArrayFx3_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayFx3_methods[]= {
    { "__len", _wrap_SArrayFx3___len},
    { "__getitem", _wrap_SArrayFx3___getitem},
    { "__setitem", _wrap_SArrayFx3___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayFx3_meta[] = {
    { "__len", _wrap_SArrayFx3___len},
    { "__getitem", _wrap_SArrayFx3___getitem},
    { "__setitem", _wrap_SArrayFx3___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayFx3_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayFx3_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayFx3_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayFx3_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayFx3_Sf_SwigStatic = {
    "SArrayFx3",
    swig_SArrayFx3_Sf_SwigStatic_methods,
    swig_SArrayFx3_Sf_SwigStatic_attributes,
    swig_SArrayFx3_Sf_SwigStatic_constants,
    swig_SArrayFx3_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayFx3_bases[] = {0};
static const char *swig_SArrayFx3_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayFx3 = { "SArrayFx3", "SArrayFx3", &SWIGTYPE_p_SArrayFx3,_proxy__wrap_new_SArrayFx3, swig_delete_SArrayFx3, swig_SArrayFx3_methods, swig_SArrayFx3_attributes, &swig_SArrayFx3_Sf_SwigStatic, swig_SArrayFx3_meta, swig_SArrayFx3_bases, swig_SArrayFx3_base_names };

static int _wrap_SFx3_size_set(lua_State* L) {
  int SWIG_arg = 0;
  SFx3 *arg1 = (SFx3 *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SFx3::size",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFx3::size",1,"SFx3 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SFx3::size",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFx3,0))){
    SWIG_fail_ptr("SFx3_size_set",1,SWIGTYPE_p_SFx3);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->size = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFx3_size_get(lua_State* L) {
  int SWIG_arg = 0;
  SFx3 *arg1 = (SFx3 *) 0 ;
  uint result;
  
  SWIG_check_num_args("SFx3::size",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFx3::size",1,"SFx3 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFx3,0))){
    SWIG_fail_ptr("SFx3_size_get",1,SWIGTYPE_p_SFx3);
  }
  
  result = (uint) ((arg1)->size);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFx3_data_set(lua_State* L) {
  int SWIG_arg = 0;
  SFx3 *arg1 = (SFx3 *) 0 ;
  SArrayFx3 *arg2 = (SArrayFx3 *) 0 ;
  
  SWIG_check_num_args("SFx3::data",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFx3::data",1,"SFx3 *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFx3::data",2,"SArrayFx3 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFx3,0))){
    SWIG_fail_ptr("SFx3_data_set",1,SWIGTYPE_p_SFx3);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayFx3,0))){
    SWIG_fail_ptr("SFx3_data_set",2,SWIGTYPE_p_SArrayFx3);
  }
  
  if (arg1) (arg1)->data = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFx3_data_get(lua_State* L) {
  int SWIG_arg = 0;
  SFx3 *arg1 = (SFx3 *) 0 ;
  SArrayFx3 *result = 0 ;
  
  SWIG_check_num_args("SFx3::data",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFx3::data",1,"SFx3 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFx3,0))){
    SWIG_fail_ptr("SFx3_data_get",1,SWIGTYPE_p_SFx3);
  }
  
  result = (SArrayFx3 *)& ((arg1)->data);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayFx3,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SFx3(lua_State* L) {
  int SWIG_arg = 0;
  SFx3 *result = 0 ;
  
  SWIG_check_num_args("SFx3::SFx3",0,0)
  result = (SFx3 *)calloc(1, sizeof(SFx3));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFx3,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SFx3(void *obj) {
SFx3 *arg1 = (SFx3 *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SFx3(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SFx3);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SFx3_attributes[] = {
    { "size", _wrap_SFx3_size_get, _wrap_SFx3_size_set },
    { "data", _wrap_SFx3_data_get, _wrap_SFx3_data_set },
    {0,0,0}
};
static swig_lua_method swig_SFx3_methods[]= {
    {0,0}
};
static swig_lua_method swig_SFx3_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SFx3_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SFx3_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SFx3_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SFx3_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SFx3_Sf_SwigStatic = {
    "SFx3",
    swig_SFx3_Sf_SwigStatic_methods,
    swig_SFx3_Sf_SwigStatic_attributes,
    swig_SFx3_Sf_SwigStatic_constants,
    swig_SFx3_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SFx3_bases[] = {0};
static const char *swig_SFx3_base_names[] = {0};
static swig_lua_class _wrap_class_SFx3 = { "SFx3", "SFx3", &SWIGTYPE_p_SFx3,_proxy__wrap_new_SFx3, swig_delete_SFx3, swig_SFx3_methods, swig_SFx3_attributes, &swig_SFx3_Sf_SwigStatic, swig_SFx3_meta, swig_SFx3_bases, swig_SFx3_base_names };

static int _wrap_SArrayFpga_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFpga *arg1 = (SArrayFpga *) 0 ;
  byte *arg2 ;
  
  SWIG_check_num_args("SArrayFpga::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFpga::bytes",1,"SArrayFpga *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayFpga::bytes",2,"byte [(4*1024*1024)]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFpga,0))){
    SWIG_fail_ptr("SArrayFpga_bytes_set",1,SWIGTYPE_p_SArrayFpga);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,0))){
    SWIG_fail_ptr("SArrayFpga_bytes_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  {
    size_t ii;
    byte *b = (byte *) arg1->bytes;
    for (ii = 0; ii < (size_t)(4*1024*1024); ii++) b[ii] = *((byte *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFpga_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFpga *arg1 = (SArrayFpga *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SArrayFpga::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFpga::bytes",1,"SArrayFpga *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFpga,0))){
    SWIG_fail_ptr("SArrayFpga_bytes_get",1,SWIGTYPE_p_SArrayFpga);
  }
  
  result = (byte *)(byte *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFpga___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFpga *arg1 = (SArrayFpga *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayFpga::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFpga::__len",1,"SArrayFpga const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFpga,0))){
    SWIG_fail_ptr("SArrayFpga___len",1,SWIGTYPE_p_SArrayFpga);
  }
  
  result = (int)SArrayFpga___len((SArrayFpga const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFpga___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFpga *arg1 = (SArrayFpga *) 0 ;
  int arg2 ;
  byte result;
  
  SWIG_check_num_args("SArrayFpga::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFpga::__getitem",1,"SArrayFpga *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayFpga::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFpga,0))){
    SWIG_fail_ptr("SArrayFpga___getitem",1,SWIGTYPE_p_SArrayFpga);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (byte)SArrayFpga___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayFpga___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFpga *arg1 = (SArrayFpga *) 0 ;
  int arg2 ;
  byte arg3 ;
  
  SWIG_check_num_args("SArrayFpga::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayFpga::__setitem",1,"SArrayFpga *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayFpga::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayFpga::__setitem",3,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayFpga,0))){
    SWIG_fail_ptr("SArrayFpga___setitem",1,SWIGTYPE_p_SArrayFpga);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (byte)lua_tonumber(L, 3);
  SArrayFpga___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayFpga(lua_State* L) {
  int SWIG_arg = 0;
  SArrayFpga *result = 0 ;
  
  SWIG_check_num_args("SArrayFpga::SArrayFpga",0,0)
  result = (SArrayFpga *)calloc(1, sizeof(SArrayFpga));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayFpga,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayFpga(void *obj) {
SArrayFpga *arg1 = (SArrayFpga *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayFpga(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayFpga);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayFpga_attributes[] = {
    { "bytes", _wrap_SArrayFpga_bytes_get, _wrap_SArrayFpga_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayFpga_methods[]= {
    { "__len", _wrap_SArrayFpga___len},
    { "__getitem", _wrap_SArrayFpga___getitem},
    { "__setitem", _wrap_SArrayFpga___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayFpga_meta[] = {
    { "__len", _wrap_SArrayFpga___len},
    { "__getitem", _wrap_SArrayFpga___getitem},
    { "__setitem", _wrap_SArrayFpga___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayFpga_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayFpga_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayFpga_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayFpga_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayFpga_Sf_SwigStatic = {
    "SArrayFpga",
    swig_SArrayFpga_Sf_SwigStatic_methods,
    swig_SArrayFpga_Sf_SwigStatic_attributes,
    swig_SArrayFpga_Sf_SwigStatic_constants,
    swig_SArrayFpga_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayFpga_bases[] = {0};
static const char *swig_SArrayFpga_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayFpga = { "SArrayFpga", "SArrayFpga", &SWIGTYPE_p_SArrayFpga,_proxy__wrap_new_SArrayFpga, swig_delete_SArrayFpga, swig_SArrayFpga_methods, swig_SArrayFpga_attributes, &swig_SArrayFpga_Sf_SwigStatic, swig_SArrayFpga_meta, swig_SArrayFpga_bases, swig_SArrayFpga_base_names };

static int _wrap_SFpga_size_set(lua_State* L) {
  int SWIG_arg = 0;
  SFpga *arg1 = (SFpga *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SFpga::size",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFpga::size",1,"SFpga *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SFpga::size",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFpga,0))){
    SWIG_fail_ptr("SFpga_size_set",1,SWIGTYPE_p_SFpga);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->size = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFpga_size_get(lua_State* L) {
  int SWIG_arg = 0;
  SFpga *arg1 = (SFpga *) 0 ;
  uint result;
  
  SWIG_check_num_args("SFpga::size",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFpga::size",1,"SFpga *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFpga,0))){
    SWIG_fail_ptr("SFpga_size_get",1,SWIGTYPE_p_SFpga);
  }
  
  result = (uint) ((arg1)->size);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFpga_data_set(lua_State* L) {
  int SWIG_arg = 0;
  SFpga *arg1 = (SFpga *) 0 ;
  SArrayFpga *arg2 = (SArrayFpga *) 0 ;
  
  SWIG_check_num_args("SFpga::data",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFpga::data",1,"SFpga *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFpga::data",2,"SArrayFpga *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFpga,0))){
    SWIG_fail_ptr("SFpga_data_set",1,SWIGTYPE_p_SFpga);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayFpga,0))){
    SWIG_fail_ptr("SFpga_data_set",2,SWIGTYPE_p_SArrayFpga);
  }
  
  if (arg1) (arg1)->data = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFpga_data_get(lua_State* L) {
  int SWIG_arg = 0;
  SFpga *arg1 = (SFpga *) 0 ;
  SArrayFpga *result = 0 ;
  
  SWIG_check_num_args("SFpga::data",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFpga::data",1,"SFpga *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFpga,0))){
    SWIG_fail_ptr("SFpga_data_get",1,SWIGTYPE_p_SFpga);
  }
  
  result = (SArrayFpga *)& ((arg1)->data);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayFpga,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SFpga(lua_State* L) {
  int SWIG_arg = 0;
  SFpga *result = 0 ;
  
  SWIG_check_num_args("SFpga::SFpga",0,0)
  result = (SFpga *)calloc(1, sizeof(SFpga));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFpga,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SFpga(void *obj) {
SFpga *arg1 = (SFpga *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SFpga(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SFpga);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SFpga_attributes[] = {
    { "size", _wrap_SFpga_size_get, _wrap_SFpga_size_set },
    { "data", _wrap_SFpga_data_get, _wrap_SFpga_data_set },
    {0,0,0}
};
static swig_lua_method swig_SFpga_methods[]= {
    {0,0}
};
static swig_lua_method swig_SFpga_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SFpga_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SFpga_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SFpga_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SFpga_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SFpga_Sf_SwigStatic = {
    "SFpga",
    swig_SFpga_Sf_SwigStatic_methods,
    swig_SFpga_Sf_SwigStatic_attributes,
    swig_SFpga_Sf_SwigStatic_constants,
    swig_SFpga_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SFpga_bases[] = {0};
static const char *swig_SFpga_base_names[] = {0};
static swig_lua_class _wrap_class_SFpga = { "SFpga", "SFpga", &SWIGTYPE_p_SFpga,_proxy__wrap_new_SFpga, swig_delete_SFpga, swig_SFpga_methods, swig_SFpga_attributes, &swig_SFpga_Sf_SwigStatic, swig_SFpga_meta, swig_SFpga_bases, swig_SFpga_base_names };

static int _wrap_SArrayGeneratorAnalog0_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog0 *arg1 = (SArrayGeneratorAnalog0 *) 0 ;
  ishort *arg2 ;
  
  SWIG_check_num_args("SArrayGeneratorAnalog0::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog0::bytes",1,"SArrayGeneratorAnalog0 *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayGeneratorAnalog0::bytes",2,"ishort [32768]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog0,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog0_bytes_set",1,SWIGTYPE_p_SArrayGeneratorAnalog0);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_short,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog0_bytes_set",2,SWIGTYPE_p_short);
  }
  
  {
    size_t ii;
    ishort *b = (ishort *) arg1->bytes;
    for (ii = 0; ii < (size_t)32768; ii++) b[ii] = *((ishort *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorAnalog0_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog0 *arg1 = (SArrayGeneratorAnalog0 *) 0 ;
  ishort *result = 0 ;
  
  SWIG_check_num_args("SArrayGeneratorAnalog0::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog0::bytes",1,"SArrayGeneratorAnalog0 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog0,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog0_bytes_get",1,SWIGTYPE_p_SArrayGeneratorAnalog0);
  }
  
  result = (ishort *)(ishort *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_short,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorAnalog0___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog0 *arg1 = (SArrayGeneratorAnalog0 *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayGeneratorAnalog0::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog0::__len",1,"SArrayGeneratorAnalog0 const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog0,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog0___len",1,SWIGTYPE_p_SArrayGeneratorAnalog0);
  }
  
  result = (int)SArrayGeneratorAnalog0___len((SArrayGeneratorAnalog0 const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorAnalog0___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog0 *arg1 = (SArrayGeneratorAnalog0 *) 0 ;
  int arg2 ;
  ishort result;
  
  SWIG_check_num_args("SArrayGeneratorAnalog0::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog0::__getitem",1,"SArrayGeneratorAnalog0 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayGeneratorAnalog0::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog0,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog0___getitem",1,SWIGTYPE_p_SArrayGeneratorAnalog0);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (ishort)SArrayGeneratorAnalog0___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorAnalog0___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog0 *arg1 = (SArrayGeneratorAnalog0 *) 0 ;
  int arg2 ;
  ishort arg3 ;
  
  SWIG_check_num_args("SArrayGeneratorAnalog0::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog0::__setitem",1,"SArrayGeneratorAnalog0 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayGeneratorAnalog0::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayGeneratorAnalog0::__setitem",3,"ishort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog0,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog0___setitem",1,SWIGTYPE_p_SArrayGeneratorAnalog0);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  arg3 = (ishort)lua_tonumber(L, 3);
  SArrayGeneratorAnalog0___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayGeneratorAnalog0(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog0 *result = 0 ;
  
  SWIG_check_num_args("SArrayGeneratorAnalog0::SArrayGeneratorAnalog0",0,0)
  result = (SArrayGeneratorAnalog0 *)calloc(1, sizeof(SArrayGeneratorAnalog0));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayGeneratorAnalog0,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayGeneratorAnalog0(void *obj) {
SArrayGeneratorAnalog0 *arg1 = (SArrayGeneratorAnalog0 *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayGeneratorAnalog0(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayGeneratorAnalog0);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayGeneratorAnalog0_attributes[] = {
    { "bytes", _wrap_SArrayGeneratorAnalog0_bytes_get, _wrap_SArrayGeneratorAnalog0_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayGeneratorAnalog0_methods[]= {
    { "__len", _wrap_SArrayGeneratorAnalog0___len},
    { "__getitem", _wrap_SArrayGeneratorAnalog0___getitem},
    { "__setitem", _wrap_SArrayGeneratorAnalog0___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayGeneratorAnalog0_meta[] = {
    { "__len", _wrap_SArrayGeneratorAnalog0___len},
    { "__getitem", _wrap_SArrayGeneratorAnalog0___getitem},
    { "__setitem", _wrap_SArrayGeneratorAnalog0___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayGeneratorAnalog0_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayGeneratorAnalog0_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayGeneratorAnalog0_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayGeneratorAnalog0_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayGeneratorAnalog0_Sf_SwigStatic = {
    "SArrayGeneratorAnalog0",
    swig_SArrayGeneratorAnalog0_Sf_SwigStatic_methods,
    swig_SArrayGeneratorAnalog0_Sf_SwigStatic_attributes,
    swig_SArrayGeneratorAnalog0_Sf_SwigStatic_constants,
    swig_SArrayGeneratorAnalog0_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayGeneratorAnalog0_bases[] = {0};
static const char *swig_SArrayGeneratorAnalog0_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayGeneratorAnalog0 = { "SArrayGeneratorAnalog0", "SArrayGeneratorAnalog0", &SWIGTYPE_p_SArrayGeneratorAnalog0,_proxy__wrap_new_SArrayGeneratorAnalog0, swig_delete_SArrayGeneratorAnalog0, swig_SArrayGeneratorAnalog0_methods, swig_SArrayGeneratorAnalog0_attributes, &swig_SArrayGeneratorAnalog0_Sf_SwigStatic, swig_SArrayGeneratorAnalog0_meta, swig_SArrayGeneratorAnalog0_bases, swig_SArrayGeneratorAnalog0_base_names };

static int _wrap_SArrayGeneratorAnalog1_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog1 *arg1 = (SArrayGeneratorAnalog1 *) 0 ;
  ishort *arg2 ;
  
  SWIG_check_num_args("SArrayGeneratorAnalog1::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog1::bytes",1,"SArrayGeneratorAnalog1 *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayGeneratorAnalog1::bytes",2,"ishort [32768]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog1,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog1_bytes_set",1,SWIGTYPE_p_SArrayGeneratorAnalog1);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_short,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog1_bytes_set",2,SWIGTYPE_p_short);
  }
  
  {
    memcpy(arg1->bytes, arg2, 32768);                                                                                             
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorAnalog1_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog1 *arg1 = (SArrayGeneratorAnalog1 *) 0 ;
  ishort *result = 0 ;
  
  SWIG_check_num_args("SArrayGeneratorAnalog1::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog1::bytes",1,"SArrayGeneratorAnalog1 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog1,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog1_bytes_get",1,SWIGTYPE_p_SArrayGeneratorAnalog1);
  }
  
  result = (ishort *)(ishort *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_short,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorAnalog1___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog1 *arg1 = (SArrayGeneratorAnalog1 *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayGeneratorAnalog1::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog1::__len",1,"SArrayGeneratorAnalog1 const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog1,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog1___len",1,SWIGTYPE_p_SArrayGeneratorAnalog1);
  }
  
  result = (int)SArrayGeneratorAnalog1___len((SArrayGeneratorAnalog1 const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorAnalog1___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog1 *arg1 = (SArrayGeneratorAnalog1 *) 0 ;
  int arg2 ;
  ishort result;
  
  SWIG_check_num_args("SArrayGeneratorAnalog1::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog1::__getitem",1,"SArrayGeneratorAnalog1 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayGeneratorAnalog1::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog1,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog1___getitem",1,SWIGTYPE_p_SArrayGeneratorAnalog1);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (ishort)SArrayGeneratorAnalog1___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorAnalog1___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog1 *arg1 = (SArrayGeneratorAnalog1 *) 0 ;
  int arg2 ;
  ishort arg3 ;
  
  SWIG_check_num_args("SArrayGeneratorAnalog1::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorAnalog1::__setitem",1,"SArrayGeneratorAnalog1 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayGeneratorAnalog1::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayGeneratorAnalog1::__setitem",3,"ishort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorAnalog1,0))){
    SWIG_fail_ptr("SArrayGeneratorAnalog1___setitem",1,SWIGTYPE_p_SArrayGeneratorAnalog1);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  arg3 = (ishort)lua_tonumber(L, 3);
  SArrayGeneratorAnalog1___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayGeneratorAnalog1(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorAnalog1 *result = 0 ;
  
  SWIG_check_num_args("SArrayGeneratorAnalog1::SArrayGeneratorAnalog1",0,0)
  result = (SArrayGeneratorAnalog1 *)calloc(1, sizeof(SArrayGeneratorAnalog1));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayGeneratorAnalog1,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayGeneratorAnalog1(void *obj) {
SArrayGeneratorAnalog1 *arg1 = (SArrayGeneratorAnalog1 *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayGeneratorAnalog1(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayGeneratorAnalog1);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayGeneratorAnalog1_attributes[] = {
    { "bytes", _wrap_SArrayGeneratorAnalog1_bytes_get, _wrap_SArrayGeneratorAnalog1_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayGeneratorAnalog1_methods[]= {
    { "__len", _wrap_SArrayGeneratorAnalog1___len},
    { "__getitem", _wrap_SArrayGeneratorAnalog1___getitem},
    { "__setitem", _wrap_SArrayGeneratorAnalog1___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayGeneratorAnalog1_meta[] = {
    { "__len", _wrap_SArrayGeneratorAnalog1___len},
    { "__getitem", _wrap_SArrayGeneratorAnalog1___getitem},
    { "__setitem", _wrap_SArrayGeneratorAnalog1___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayGeneratorAnalog1_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayGeneratorAnalog1_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayGeneratorAnalog1_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayGeneratorAnalog1_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayGeneratorAnalog1_Sf_SwigStatic = {
    "SArrayGeneratorAnalog1",
    swig_SArrayGeneratorAnalog1_Sf_SwigStatic_methods,
    swig_SArrayGeneratorAnalog1_Sf_SwigStatic_attributes,
    swig_SArrayGeneratorAnalog1_Sf_SwigStatic_constants,
    swig_SArrayGeneratorAnalog1_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayGeneratorAnalog1_bases[] = {0};
static const char *swig_SArrayGeneratorAnalog1_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayGeneratorAnalog1 = { "SArrayGeneratorAnalog1", "SArrayGeneratorAnalog1", &SWIGTYPE_p_SArrayGeneratorAnalog1,_proxy__wrap_new_SArrayGeneratorAnalog1, swig_delete_SArrayGeneratorAnalog1, swig_SArrayGeneratorAnalog1_methods, swig_SArrayGeneratorAnalog1_attributes, &swig_SArrayGeneratorAnalog1_Sf_SwigStatic, swig_SArrayGeneratorAnalog1_meta, swig_SArrayGeneratorAnalog1_bases, swig_SArrayGeneratorAnalog1_base_names };

static int _wrap_SArrayGeneratorDigital_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorDigital *arg1 = (SArrayGeneratorDigital *) 0 ;
  ushort *arg2 ;
  
  SWIG_check_num_args("SArrayGeneratorDigital::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorDigital::bytes",1,"SArrayGeneratorDigital *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayGeneratorDigital::bytes",2,"ushort [32768]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorDigital,0))){
    SWIG_fail_ptr("SArrayGeneratorDigital_bytes_set",1,SWIGTYPE_p_SArrayGeneratorDigital);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_short,0))){
    SWIG_fail_ptr("SArrayGeneratorDigital_bytes_set",2,SWIGTYPE_p_unsigned_short);
  }
  
  {
    size_t ii;
    ushort *b = (ushort *) arg1->bytes;
    for (ii = 0; ii < (size_t)32768; ii++) b[ii] = *((ushort *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorDigital_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorDigital *arg1 = (SArrayGeneratorDigital *) 0 ;
  ushort *result = 0 ;
  
  SWIG_check_num_args("SArrayGeneratorDigital::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorDigital::bytes",1,"SArrayGeneratorDigital *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorDigital,0))){
    SWIG_fail_ptr("SArrayGeneratorDigital_bytes_get",1,SWIGTYPE_p_SArrayGeneratorDigital);
  }
  
  result = (ushort *)(ushort *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_short,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorDigital___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorDigital *arg1 = (SArrayGeneratorDigital *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayGeneratorDigital::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorDigital::__len",1,"SArrayGeneratorDigital const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorDigital,0))){
    SWIG_fail_ptr("SArrayGeneratorDigital___len",1,SWIGTYPE_p_SArrayGeneratorDigital);
  }
  
  result = (int)SArrayGeneratorDigital___len((SArrayGeneratorDigital const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorDigital___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorDigital *arg1 = (SArrayGeneratorDigital *) 0 ;
  int arg2 ;
  ushort result;
  
  SWIG_check_num_args("SArrayGeneratorDigital::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorDigital::__getitem",1,"SArrayGeneratorDigital *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayGeneratorDigital::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorDigital,0))){
    SWIG_fail_ptr("SArrayGeneratorDigital___getitem",1,SWIGTYPE_p_SArrayGeneratorDigital);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (ushort)SArrayGeneratorDigital___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayGeneratorDigital___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorDigital *arg1 = (SArrayGeneratorDigital *) 0 ;
  int arg2 ;
  ushort arg3 ;
  
  SWIG_check_num_args("SArrayGeneratorDigital::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayGeneratorDigital::__setitem",1,"SArrayGeneratorDigital *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayGeneratorDigital::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayGeneratorDigital::__setitem",3,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayGeneratorDigital,0))){
    SWIG_fail_ptr("SArrayGeneratorDigital___setitem",1,SWIGTYPE_p_SArrayGeneratorDigital);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (ushort)lua_tonumber(L, 3);
  SArrayGeneratorDigital___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayGeneratorDigital(lua_State* L) {
  int SWIG_arg = 0;
  SArrayGeneratorDigital *result = 0 ;
  
  SWIG_check_num_args("SArrayGeneratorDigital::SArrayGeneratorDigital",0,0)
  result = (SArrayGeneratorDigital *)calloc(1, sizeof(SArrayGeneratorDigital));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayGeneratorDigital,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayGeneratorDigital(void *obj) {
SArrayGeneratorDigital *arg1 = (SArrayGeneratorDigital *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayGeneratorDigital(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayGeneratorDigital);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayGeneratorDigital_attributes[] = {
    { "bytes", _wrap_SArrayGeneratorDigital_bytes_get, _wrap_SArrayGeneratorDigital_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayGeneratorDigital_methods[]= {
    { "__len", _wrap_SArrayGeneratorDigital___len},
    { "__getitem", _wrap_SArrayGeneratorDigital___getitem},
    { "__setitem", _wrap_SArrayGeneratorDigital___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayGeneratorDigital_meta[] = {
    { "__len", _wrap_SArrayGeneratorDigital___len},
    { "__getitem", _wrap_SArrayGeneratorDigital___getitem},
    { "__setitem", _wrap_SArrayGeneratorDigital___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayGeneratorDigital_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayGeneratorDigital_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayGeneratorDigital_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayGeneratorDigital_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayGeneratorDigital_Sf_SwigStatic = {
    "SArrayGeneratorDigital",
    swig_SArrayGeneratorDigital_Sf_SwigStatic_methods,
    swig_SArrayGeneratorDigital_Sf_SwigStatic_attributes,
    swig_SArrayGeneratorDigital_Sf_SwigStatic_constants,
    swig_SArrayGeneratorDigital_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayGeneratorDigital_bases[] = {0};
static const char *swig_SArrayGeneratorDigital_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayGeneratorDigital = { "SArrayGeneratorDigital", "SArrayGeneratorDigital", &SWIGTYPE_p_SArrayGeneratorDigital,_proxy__wrap_new_SArrayGeneratorDigital, swig_delete_SArrayGeneratorDigital, swig_SArrayGeneratorDigital_methods, swig_SArrayGeneratorDigital_attributes, &swig_SArrayGeneratorDigital_Sf_SwigStatic, swig_SArrayGeneratorDigital_meta, swig_SArrayGeneratorDigital_bases, swig_SArrayGeneratorDigital_base_names };

static int _wrap_SGenerator_analog0_set(lua_State* L) {
  int SWIG_arg = 0;
  SGenerator *arg1 = (SGenerator *) 0 ;
  SArrayGeneratorAnalog0 *arg2 = (SArrayGeneratorAnalog0 *) 0 ;
  
  SWIG_check_num_args("SGenerator::analog0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGenerator::analog0",1,"SGenerator *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SGenerator::analog0",2,"SArrayGeneratorAnalog0 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGenerator,0))){
    SWIG_fail_ptr("SGenerator_analog0_set",1,SWIGTYPE_p_SGenerator);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayGeneratorAnalog0,0))){
    SWIG_fail_ptr("SGenerator_analog0_set",2,SWIGTYPE_p_SArrayGeneratorAnalog0);
  }
  
  if (arg1) (arg1)->analog0 = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGenerator_analog0_get(lua_State* L) {
  int SWIG_arg = 0;
  SGenerator *arg1 = (SGenerator *) 0 ;
  SArrayGeneratorAnalog0 *result = 0 ;
  
  SWIG_check_num_args("SGenerator::analog0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGenerator::analog0",1,"SGenerator *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGenerator,0))){
    SWIG_fail_ptr("SGenerator_analog0_get",1,SWIGTYPE_p_SGenerator);
  }
  
  result = (SArrayGeneratorAnalog0 *)& ((arg1)->analog0);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayGeneratorAnalog0,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGenerator_analog1_set(lua_State* L) {
  int SWIG_arg = 0;
  SGenerator *arg1 = (SGenerator *) 0 ;
  SArrayGeneratorAnalog1 *arg2 = (SArrayGeneratorAnalog1 *) 0 ;
  
  SWIG_check_num_args("SGenerator::analog1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGenerator::analog1",1,"SGenerator *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SGenerator::analog1",2,"SArrayGeneratorAnalog1 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGenerator,0))){
    SWIG_fail_ptr("SGenerator_analog1_set",1,SWIGTYPE_p_SGenerator);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayGeneratorAnalog1,0))){
    SWIG_fail_ptr("SGenerator_analog1_set",2,SWIGTYPE_p_SArrayGeneratorAnalog1);
  }
  
  if (arg1) (arg1)->analog1 = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGenerator_analog1_get(lua_State* L) {
  int SWIG_arg = 0;
  SGenerator *arg1 = (SGenerator *) 0 ;
  SArrayGeneratorAnalog1 *result = 0 ;
  
  SWIG_check_num_args("SGenerator::analog1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGenerator::analog1",1,"SGenerator *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGenerator,0))){
    SWIG_fail_ptr("SGenerator_analog1_get",1,SWIGTYPE_p_SGenerator);
  }
  
  result = (SArrayGeneratorAnalog1 *)& ((arg1)->analog1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayGeneratorAnalog1,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGenerator_digital_set(lua_State* L) {
  int SWIG_arg = 0;
  SGenerator *arg1 = (SGenerator *) 0 ;
  SArrayGeneratorDigital *arg2 = (SArrayGeneratorDigital *) 0 ;
  
  SWIG_check_num_args("SGenerator::digital",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGenerator::digital",1,"SGenerator *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SGenerator::digital",2,"SArrayGeneratorDigital *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGenerator,0))){
    SWIG_fail_ptr("SGenerator_digital_set",1,SWIGTYPE_p_SGenerator);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayGeneratorDigital,0))){
    SWIG_fail_ptr("SGenerator_digital_set",2,SWIGTYPE_p_SArrayGeneratorDigital);
  }
  
  if (arg1) (arg1)->digital = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SGenerator_digital_get(lua_State* L) {
  int SWIG_arg = 0;
  SGenerator *arg1 = (SGenerator *) 0 ;
  SArrayGeneratorDigital *result = 0 ;
  
  SWIG_check_num_args("SGenerator::digital",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SGenerator::digital",1,"SGenerator *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGenerator,0))){
    SWIG_fail_ptr("SGenerator_digital_get",1,SWIGTYPE_p_SGenerator);
  }
  
  result = (SArrayGeneratorDigital *)& ((arg1)->digital);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayGeneratorDigital,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SGenerator(lua_State* L) {
  int SWIG_arg = 0;
  SGenerator *result = 0 ;
  
  SWIG_check_num_args("SGenerator::SGenerator",0,0)
  result = (SGenerator *)calloc(1, sizeof(SGenerator));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SGenerator,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SGenerator(void *obj) {
SGenerator *arg1 = (SGenerator *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SGenerator(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SGenerator);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SGenerator_attributes[] = {
    { "analog0", _wrap_SGenerator_analog0_get, _wrap_SGenerator_analog0_set },
    { "analog1", _wrap_SGenerator_analog1_get, _wrap_SGenerator_analog1_set },
    { "digital", _wrap_SGenerator_digital_get, _wrap_SGenerator_digital_set },
    {0,0,0}
};
static swig_lua_method swig_SGenerator_methods[]= {
    {0,0}
};
static swig_lua_method swig_SGenerator_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SGenerator_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SGenerator_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SGenerator_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SGenerator_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SGenerator_Sf_SwigStatic = {
    "SGenerator",
    swig_SGenerator_Sf_SwigStatic_methods,
    swig_SGenerator_Sf_SwigStatic_attributes,
    swig_SGenerator_Sf_SwigStatic_constants,
    swig_SGenerator_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SGenerator_bases[] = {0};
static const char *swig_SGenerator_base_names[] = {0};
static swig_lua_class _wrap_class_SGenerator = { "SGenerator", "SGenerator", &SWIGTYPE_p_SGenerator,_proxy__wrap_new_SGenerator, swig_delete_SGenerator, swig_SGenerator_methods, swig_SGenerator_attributes, &swig_SGenerator_Sf_SwigStatic, swig_SGenerator_meta, swig_SGenerator_bases, swig_SGenerator_base_names };

static int _wrap_SSimulate_active0_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  byte arg2 ;
  
  SWIG_check_num_args("SSimulate::active0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::active0",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::active0",2,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_active0_set",1,SWIGTYPE_p_SSimulate);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (byte)lua_tonumber(L, 2);
  if (arg1) (arg1)->active0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_active0_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  byte result;
  
  SWIG_check_num_args("SSimulate::active0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::active0",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_active0_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (byte) ((arg1)->active0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_active1_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  byte arg2 ;
  
  SWIG_check_num_args("SSimulate::active1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::active1",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::active1",2,"byte");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_active1_set",1,SWIGTYPE_p_SSimulate);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (byte)lua_tonumber(L, 2);
  if (arg1) (arg1)->active1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_active1_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  byte result;
  
  SWIG_check_num_args("SSimulate::active1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::active1",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_active1_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (byte) ((arg1)->active1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_type0_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  ESimulateType arg2 ;
  
  SWIG_check_num_args("SSimulate::type0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::type0",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::type0",2,"ESimulateType");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_type0_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (ESimulateType)(int)lua_tonumber(L, 2);
  if (arg1) (arg1)->type0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_type0_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  ESimulateType result;
  
  SWIG_check_num_args("SSimulate::type0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::type0",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_type0_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (ESimulateType) ((arg1)->type0);
  lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_type1_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  ESimulateType arg2 ;
  
  SWIG_check_num_args("SSimulate::type1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::type1",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::type1",2,"ESimulateType");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_type1_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (ESimulateType)(int)lua_tonumber(L, 2);
  if (arg1) (arg1)->type1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_type1_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  ESimulateType result;
  
  SWIG_check_num_args("SSimulate::type1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::type1",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_type1_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (ESimulateType) ((arg1)->type1);
  lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_period0_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::period0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::period0",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::period0",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_period0_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->period0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_period0_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::period0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::period0",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_period0_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->period0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_period1_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::period1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::period1",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::period1",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_period1_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->period1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_period1_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::period1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::period1",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_period1_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->period1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_peakToPeak0_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::peakToPeak0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::peakToPeak0",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::peakToPeak0",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_peakToPeak0_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->peakToPeak0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_peakToPeak0_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::peakToPeak0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::peakToPeak0",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_peakToPeak0_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->peakToPeak0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_peakToPeak1_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::peakToPeak1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::peakToPeak1",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::peakToPeak1",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_peakToPeak1_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->peakToPeak1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_peakToPeak1_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::peakToPeak1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::peakToPeak1",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_peakToPeak1_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->peakToPeak1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_avery0_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::avery0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::avery0",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::avery0",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_avery0_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->avery0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_avery0_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::avery0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::avery0",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_avery0_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->avery0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_avery1_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::avery1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::avery1",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::avery1",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_avery1_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->avery1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_avery1_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::avery1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::avery1",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_avery1_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->avery1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_speed0_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::speed0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::speed0",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::speed0",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_speed0_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->speed0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_speed0_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::speed0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::speed0",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_speed0_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->speed0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_speed1_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::speed1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::speed1",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::speed1",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_speed1_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->speed1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_speed1_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::speed1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::speed1",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_speed1_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->speed1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_etsIndex_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SSimulate::etsIndex",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::etsIndex",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::etsIndex",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_etsIndex_set",1,SWIGTYPE_p_SSimulate);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->etsIndex = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_etsIndex_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  uint result;
  
  SWIG_check_num_args("SSimulate::etsIndex",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::etsIndex",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_etsIndex_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (uint) ((arg1)->etsIndex);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_etsActive_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SSimulate::etsActive",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::etsActive",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::etsActive",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_etsActive_set",1,SWIGTYPE_p_SSimulate);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->etsActive = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_etsActive_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  uint result;
  
  SWIG_check_num_args("SSimulate::etsActive",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::etsActive",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_etsActive_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (uint) ((arg1)->etsActive);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_etsMax_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SSimulate::etsMax",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::etsMax",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::etsMax",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_etsMax_set",1,SWIGTYPE_p_SSimulate);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->etsMax = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_etsMax_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  uint result;
  
  SWIG_check_num_args("SSimulate::etsMax",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::etsMax",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_etsMax_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (uint) ((arg1)->etsMax);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_time_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::time",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::time",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::time",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_time_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->time = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_time_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::time",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::time",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_time_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->time);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_voltage0_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::voltage0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::voltage0",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::voltage0",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_voltage0_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->voltage0 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_voltage0_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::voltage0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::voltage0",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_voltage0_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->voltage0);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_voltage1_set(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("SSimulate::voltage1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::voltage1",1,"SSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SSimulate::voltage1",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_voltage1_set",1,SWIGTYPE_p_SSimulate);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->voltage1 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SSimulate_voltage1_get(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  float result;
  
  SWIG_check_num_args("SSimulate::voltage1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SSimulate::voltage1",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SSimulate_voltage1_get",1,SWIGTYPE_p_SSimulate);
  }
  
  result = (float) ((arg1)->voltage1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SSimulate(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *result = 0 ;
  
  SWIG_check_num_args("SSimulate::SSimulate",0,0)
  result = (SSimulate *)calloc(1, sizeof(SSimulate));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SSimulate,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SSimulate(void *obj) {
SSimulate *arg1 = (SSimulate *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SSimulate(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SSimulate);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SSimulate_attributes[] = {
    { "active0", _wrap_SSimulate_active0_get, _wrap_SSimulate_active0_set },
    { "active1", _wrap_SSimulate_active1_get, _wrap_SSimulate_active1_set },
    { "type0", _wrap_SSimulate_type0_get, _wrap_SSimulate_type0_set },
    { "type1", _wrap_SSimulate_type1_get, _wrap_SSimulate_type1_set },
    { "period0", _wrap_SSimulate_period0_get, _wrap_SSimulate_period0_set },
    { "period1", _wrap_SSimulate_period1_get, _wrap_SSimulate_period1_set },
    { "peakToPeak0", _wrap_SSimulate_peakToPeak0_get, _wrap_SSimulate_peakToPeak0_set },
    { "peakToPeak1", _wrap_SSimulate_peakToPeak1_get, _wrap_SSimulate_peakToPeak1_set },
    { "avery0", _wrap_SSimulate_avery0_get, _wrap_SSimulate_avery0_set },
    { "avery1", _wrap_SSimulate_avery1_get, _wrap_SSimulate_avery1_set },
    { "speed0", _wrap_SSimulate_speed0_get, _wrap_SSimulate_speed0_set },
    { "speed1", _wrap_SSimulate_speed1_get, _wrap_SSimulate_speed1_set },
    { "etsIndex", _wrap_SSimulate_etsIndex_get, _wrap_SSimulate_etsIndex_set },
    { "etsActive", _wrap_SSimulate_etsActive_get, _wrap_SSimulate_etsActive_set },
    { "etsMax", _wrap_SSimulate_etsMax_get, _wrap_SSimulate_etsMax_set },
    { "time", _wrap_SSimulate_time_get, _wrap_SSimulate_time_set },
    { "voltage0", _wrap_SSimulate_voltage0_get, _wrap_SSimulate_voltage0_set },
    { "voltage1", _wrap_SSimulate_voltage1_get, _wrap_SSimulate_voltage1_set },
    {0,0,0}
};
static swig_lua_method swig_SSimulate_methods[]= {
    {0,0}
};
static swig_lua_method swig_SSimulate_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SSimulate_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SSimulate_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SSimulate_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SSimulate_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SSimulate_Sf_SwigStatic = {
    "SSimulate",
    swig_SSimulate_Sf_SwigStatic_methods,
    swig_SSimulate_Sf_SwigStatic_attributes,
    swig_SSimulate_Sf_SwigStatic_constants,
    swig_SSimulate_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SSimulate_bases[] = {0};
static const char *swig_SSimulate_base_names[] = {0};
static swig_lua_class _wrap_class_SSimulate = { "SSimulate", "SSimulate", &SWIGTYPE_p_SSimulate,_proxy__wrap_new_SSimulate, swig_delete_SSimulate, swig_SSimulate_methods, swig_SSimulate_attributes, &swig_SSimulate_Sf_SwigStatic, swig_SSimulate_meta, swig_SSimulate_bases, swig_SSimulate_base_names };

static int _wrap_SUsb_idVendor_set(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SUsb::idVendor",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::idVendor",1,"SUsb *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SUsb::idVendor",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_idVendor_set",1,SWIGTYPE_p_SUsb);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->idVendor = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_idVendor_get(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint result;
  
  SWIG_check_num_args("SUsb::idVendor",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::idVendor",1,"SUsb *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_idVendor_get",1,SWIGTYPE_p_SUsb);
  }
  
  result = (uint) ((arg1)->idVendor);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_idProduct_set(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SUsb::idProduct",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::idProduct",1,"SUsb *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SUsb::idProduct",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_idProduct_set",1,SWIGTYPE_p_SUsb);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->idProduct = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_idProduct_get(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint result;
  
  SWIG_check_num_args("SUsb::idProduct",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::idProduct",1,"SUsb *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_idProduct_get",1,SWIGTYPE_p_SUsb);
  }
  
  result = (uint) ((arg1)->idProduct);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_idSerial_set(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SUsb::idSerial",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::idSerial",1,"SUsb *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SUsb::idSerial",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_idSerial_set",1,SWIGTYPE_p_SUsb);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->idSerial = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_idSerial_get(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint result;
  
  SWIG_check_num_args("SUsb::idSerial",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::idSerial",1,"SUsb *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_idSerial_get",1,SWIGTYPE_p_SUsb);
  }
  
  result = (uint) ((arg1)->idSerial);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_timeoutEp2_set(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SUsb::timeoutEp2",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::timeoutEp2",1,"SUsb *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SUsb::timeoutEp2",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_timeoutEp2_set",1,SWIGTYPE_p_SUsb);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->timeoutEp2 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_timeoutEp2_get(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint result;
  
  SWIG_check_num_args("SUsb::timeoutEp2",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::timeoutEp2",1,"SUsb *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_timeoutEp2_get",1,SWIGTYPE_p_SUsb);
  }
  
  result = (uint) ((arg1)->timeoutEp2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_timeoutEp4_set(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SUsb::timeoutEp4",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::timeoutEp4",1,"SUsb *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SUsb::timeoutEp4",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_timeoutEp4_set",1,SWIGTYPE_p_SUsb);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->timeoutEp4 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_timeoutEp4_get(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint result;
  
  SWIG_check_num_args("SUsb::timeoutEp4",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::timeoutEp4",1,"SUsb *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_timeoutEp4_get",1,SWIGTYPE_p_SUsb);
  }
  
  result = (uint) ((arg1)->timeoutEp4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_timeoutEp6_set(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SUsb::timeoutEp6",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::timeoutEp6",1,"SUsb *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SUsb::timeoutEp6",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_timeoutEp6_set",1,SWIGTYPE_p_SUsb);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->timeoutEp6 = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_timeoutEp6_get(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint result;
  
  SWIG_check_num_args("SUsb::timeoutEp6",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::timeoutEp6",1,"SUsb *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_timeoutEp6_get",1,SWIGTYPE_p_SUsb);
  }
  
  result = (uint) ((arg1)->timeoutEp6);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_xferSize_set(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SUsb::xferSize",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::xferSize",1,"SUsb *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SUsb::xferSize",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_xferSize_set",1,SWIGTYPE_p_SUsb);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->xferSize = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_xferSize_get(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  uint result;
  
  SWIG_check_num_args("SUsb::xferSize",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::xferSize",1,"SUsb *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_xferSize_get",1,SWIGTYPE_p_SUsb);
  }
  
  result = (uint) ((arg1)->xferSize);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_guid_set(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  SGUID *arg2 = (SGUID *) 0 ;
  
  SWIG_check_num_args("SUsb::guid",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::guid",1,"SUsb *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SUsb::guid",2,"SGUID *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_guid_set",1,SWIGTYPE_p_SUsb);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SGUID,0))){
    SWIG_fail_ptr("SUsb_guid_set",2,SWIGTYPE_p_SGUID);
  }
  
  if (arg1) (arg1)->guid = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SUsb_guid_get(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  SGUID *result = 0 ;
  
  SWIG_check_num_args("SUsb::guid",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SUsb::guid",1,"SUsb *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("SUsb_guid_get",1,SWIGTYPE_p_SUsb);
  }
  
  result = (SGUID *)& ((arg1)->guid);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SGUID,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SUsb(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *result = 0 ;
  
  SWIG_check_num_args("SUsb::SUsb",0,0)
  result = (SUsb *)calloc(1, sizeof(SUsb));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SUsb,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SUsb(void *obj) {
SUsb *arg1 = (SUsb *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SUsb(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SUsb);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SUsb_attributes[] = {
    { "idVendor", _wrap_SUsb_idVendor_get, _wrap_SUsb_idVendor_set },
    { "idProduct", _wrap_SUsb_idProduct_get, _wrap_SUsb_idProduct_set },
    { "idSerial", _wrap_SUsb_idSerial_get, _wrap_SUsb_idSerial_set },
    { "timeoutEp2", _wrap_SUsb_timeoutEp2_get, _wrap_SUsb_timeoutEp2_set },
    { "timeoutEp4", _wrap_SUsb_timeoutEp4_get, _wrap_SUsb_timeoutEp4_set },
    { "timeoutEp6", _wrap_SUsb_timeoutEp6_get, _wrap_SUsb_timeoutEp6_set },
    { "xferSize", _wrap_SUsb_xferSize_get, _wrap_SUsb_xferSize_set },
    { "guid", _wrap_SUsb_guid_get, _wrap_SUsb_guid_set },
    {0,0,0}
};
static swig_lua_method swig_SUsb_methods[]= {
    {0,0}
};
static swig_lua_method swig_SUsb_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SUsb_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SUsb_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SUsb_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SUsb_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SUsb_Sf_SwigStatic = {
    "SUsb",
    swig_SUsb_Sf_SwigStatic_methods,
    swig_SUsb_Sf_SwigStatic_attributes,
    swig_SUsb_Sf_SwigStatic_constants,
    swig_SUsb_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SUsb_bases[] = {0};
static const char *swig_SUsb_base_names[] = {0};
static swig_lua_class _wrap_class_SUsb = { "SUsb", "SUsb", &SWIGTYPE_p_SUsb,_proxy__wrap_new_SUsb, swig_delete_SUsb, swig_SUsb_methods, swig_SUsb_attributes, &swig_SUsb_Sf_SwigStatic, swig_SUsb_meta, swig_SUsb_bases, swig_SUsb_base_names };

static int _wrap_SArrayDisplayAnalog0_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog0 *arg1 = (SArrayDisplayAnalog0 *) 0 ;
  float *arg2 ;
  
  SWIG_check_num_args("SArrayDisplayAnalog0::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog0::bytes",1,"SArrayDisplayAnalog0 *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayDisplayAnalog0::bytes",2,"float [10000]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog0,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog0_bytes_set",1,SWIGTYPE_p_SArrayDisplayAnalog0);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_float,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog0_bytes_set",2,SWIGTYPE_p_float);
  }
  
  {
    size_t ii;
    float *b = (float *) arg1->bytes;
    for (ii = 0; ii < (size_t)10000; ii++) b[ii] = *((float *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalog0_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog0 *arg1 = (SArrayDisplayAnalog0 *) 0 ;
  float *result = 0 ;
  
  SWIG_check_num_args("SArrayDisplayAnalog0::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog0::bytes",1,"SArrayDisplayAnalog0 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog0,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog0_bytes_get",1,SWIGTYPE_p_SArrayDisplayAnalog0);
  }
  
  result = (float *)(float *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_float,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalog0___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog0 *arg1 = (SArrayDisplayAnalog0 *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayDisplayAnalog0::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog0::__len",1,"SArrayDisplayAnalog0 const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog0,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog0___len",1,SWIGTYPE_p_SArrayDisplayAnalog0);
  }
  
  result = (int)SArrayDisplayAnalog0___len((SArrayDisplayAnalog0 const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalog0___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog0 *arg1 = (SArrayDisplayAnalog0 *) 0 ;
  int arg2 ;
  float result;
  
  SWIG_check_num_args("SArrayDisplayAnalog0::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog0::__getitem",1,"SArrayDisplayAnalog0 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayDisplayAnalog0::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog0,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog0___getitem",1,SWIGTYPE_p_SArrayDisplayAnalog0);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (float)SArrayDisplayAnalog0___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalog0___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog0 *arg1 = (SArrayDisplayAnalog0 *) 0 ;
  int arg2 ;
  float arg3 ;
  
  SWIG_check_num_args("SArrayDisplayAnalog0::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog0::__setitem",1,"SArrayDisplayAnalog0 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayDisplayAnalog0::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayDisplayAnalog0::__setitem",3,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog0,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog0___setitem",1,SWIGTYPE_p_SArrayDisplayAnalog0);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  arg3 = (float)lua_tonumber(L, 3);
  SArrayDisplayAnalog0___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayDisplayAnalog0(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog0 *result = 0 ;
  
  SWIG_check_num_args("SArrayDisplayAnalog0::SArrayDisplayAnalog0",0,0)
  result = (SArrayDisplayAnalog0 *)calloc(1, sizeof(SArrayDisplayAnalog0));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayDisplayAnalog0,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayDisplayAnalog0(void *obj) {
SArrayDisplayAnalog0 *arg1 = (SArrayDisplayAnalog0 *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayDisplayAnalog0(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayDisplayAnalog0);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayDisplayAnalog0_attributes[] = {
    { "bytes", _wrap_SArrayDisplayAnalog0_bytes_get, _wrap_SArrayDisplayAnalog0_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayDisplayAnalog0_methods[]= {
    { "__len", _wrap_SArrayDisplayAnalog0___len},
    { "__getitem", _wrap_SArrayDisplayAnalog0___getitem},
    { "__setitem", _wrap_SArrayDisplayAnalog0___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayDisplayAnalog0_meta[] = {
    { "__len", _wrap_SArrayDisplayAnalog0___len},
    { "__getitem", _wrap_SArrayDisplayAnalog0___getitem},
    { "__setitem", _wrap_SArrayDisplayAnalog0___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayDisplayAnalog0_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayDisplayAnalog0_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayDisplayAnalog0_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayDisplayAnalog0_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayDisplayAnalog0_Sf_SwigStatic = {
    "SArrayDisplayAnalog0",
    swig_SArrayDisplayAnalog0_Sf_SwigStatic_methods,
    swig_SArrayDisplayAnalog0_Sf_SwigStatic_attributes,
    swig_SArrayDisplayAnalog0_Sf_SwigStatic_constants,
    swig_SArrayDisplayAnalog0_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayDisplayAnalog0_bases[] = {0};
static const char *swig_SArrayDisplayAnalog0_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayDisplayAnalog0 = { "SArrayDisplayAnalog0", "SArrayDisplayAnalog0", &SWIGTYPE_p_SArrayDisplayAnalog0,_proxy__wrap_new_SArrayDisplayAnalog0, swig_delete_SArrayDisplayAnalog0, swig_SArrayDisplayAnalog0_methods, swig_SArrayDisplayAnalog0_attributes, &swig_SArrayDisplayAnalog0_Sf_SwigStatic, swig_SArrayDisplayAnalog0_meta, swig_SArrayDisplayAnalog0_bases, swig_SArrayDisplayAnalog0_base_names };

static int _wrap_SArrayDisplayAnalog1_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog1 *arg1 = (SArrayDisplayAnalog1 *) 0 ;
  float *arg2 ;
  
  SWIG_check_num_args("SArrayDisplayAnalog1::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog1::bytes",1,"SArrayDisplayAnalog1 *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayDisplayAnalog1::bytes",2,"float [10000]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog1,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog1_bytes_set",1,SWIGTYPE_p_SArrayDisplayAnalog1);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_float,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog1_bytes_set",2,SWIGTYPE_p_float);
  }
  
  {
    memcpy(arg1->bytes, arg2, 10000);                                                                                             
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalog1_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog1 *arg1 = (SArrayDisplayAnalog1 *) 0 ;
  float *result = 0 ;
  
  SWIG_check_num_args("SArrayDisplayAnalog1::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog1::bytes",1,"SArrayDisplayAnalog1 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog1,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog1_bytes_get",1,SWIGTYPE_p_SArrayDisplayAnalog1);
  }
  
  result = (float *)(float *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_float,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalog1___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog1 *arg1 = (SArrayDisplayAnalog1 *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayDisplayAnalog1::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog1::__len",1,"SArrayDisplayAnalog1 const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog1,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog1___len",1,SWIGTYPE_p_SArrayDisplayAnalog1);
  }
  
  result = (int)SArrayDisplayAnalog1___len((SArrayDisplayAnalog1 const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalog1___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog1 *arg1 = (SArrayDisplayAnalog1 *) 0 ;
  int arg2 ;
  float result;
  
  SWIG_check_num_args("SArrayDisplayAnalog1::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog1::__getitem",1,"SArrayDisplayAnalog1 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayDisplayAnalog1::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog1,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog1___getitem",1,SWIGTYPE_p_SArrayDisplayAnalog1);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (float)SArrayDisplayAnalog1___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalog1___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog1 *arg1 = (SArrayDisplayAnalog1 *) 0 ;
  int arg2 ;
  float arg3 ;
  
  SWIG_check_num_args("SArrayDisplayAnalog1::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalog1::__setitem",1,"SArrayDisplayAnalog1 *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayDisplayAnalog1::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayDisplayAnalog1::__setitem",3,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalog1,0))){
    SWIG_fail_ptr("SArrayDisplayAnalog1___setitem",1,SWIGTYPE_p_SArrayDisplayAnalog1);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  arg3 = (float)lua_tonumber(L, 3);
  SArrayDisplayAnalog1___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayDisplayAnalog1(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalog1 *result = 0 ;
  
  SWIG_check_num_args("SArrayDisplayAnalog1::SArrayDisplayAnalog1",0,0)
  result = (SArrayDisplayAnalog1 *)calloc(1, sizeof(SArrayDisplayAnalog1));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayDisplayAnalog1,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayDisplayAnalog1(void *obj) {
SArrayDisplayAnalog1 *arg1 = (SArrayDisplayAnalog1 *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayDisplayAnalog1(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayDisplayAnalog1);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayDisplayAnalog1_attributes[] = {
    { "bytes", _wrap_SArrayDisplayAnalog1_bytes_get, _wrap_SArrayDisplayAnalog1_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayDisplayAnalog1_methods[]= {
    { "__len", _wrap_SArrayDisplayAnalog1___len},
    { "__getitem", _wrap_SArrayDisplayAnalog1___getitem},
    { "__setitem", _wrap_SArrayDisplayAnalog1___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayDisplayAnalog1_meta[] = {
    { "__len", _wrap_SArrayDisplayAnalog1___len},
    { "__getitem", _wrap_SArrayDisplayAnalog1___getitem},
    { "__setitem", _wrap_SArrayDisplayAnalog1___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayDisplayAnalog1_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayDisplayAnalog1_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayDisplayAnalog1_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayDisplayAnalog1_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayDisplayAnalog1_Sf_SwigStatic = {
    "SArrayDisplayAnalog1",
    swig_SArrayDisplayAnalog1_Sf_SwigStatic_methods,
    swig_SArrayDisplayAnalog1_Sf_SwigStatic_attributes,
    swig_SArrayDisplayAnalog1_Sf_SwigStatic_constants,
    swig_SArrayDisplayAnalog1_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayDisplayAnalog1_bases[] = {0};
static const char *swig_SArrayDisplayAnalog1_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayDisplayAnalog1 = { "SArrayDisplayAnalog1", "SArrayDisplayAnalog1", &SWIGTYPE_p_SArrayDisplayAnalog1,_proxy__wrap_new_SArrayDisplayAnalog1, swig_delete_SArrayDisplayAnalog1, swig_SArrayDisplayAnalog1_methods, swig_SArrayDisplayAnalog1_attributes, &swig_SArrayDisplayAnalog1_Sf_SwigStatic, swig_SArrayDisplayAnalog1_meta, swig_SArrayDisplayAnalog1_bases, swig_SArrayDisplayAnalog1_base_names };

static int _wrap_SArrayDisplayAnalogF_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalogF *arg1 = (SArrayDisplayAnalogF *) 0 ;
  float *arg2 ;
  
  SWIG_check_num_args("SArrayDisplayAnalogF::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalogF::bytes",1,"SArrayDisplayAnalogF *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayDisplayAnalogF::bytes",2,"float [10000]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalogF,0))){
    SWIG_fail_ptr("SArrayDisplayAnalogF_bytes_set",1,SWIGTYPE_p_SArrayDisplayAnalogF);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_float,0))){
    SWIG_fail_ptr("SArrayDisplayAnalogF_bytes_set",2,SWIGTYPE_p_float);
  }
  
  {
    memcpy(arg1->bytes, arg2, 10000);                                                                                             
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalogF_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalogF *arg1 = (SArrayDisplayAnalogF *) 0 ;
  float *result = 0 ;
  
  SWIG_check_num_args("SArrayDisplayAnalogF::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalogF::bytes",1,"SArrayDisplayAnalogF *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalogF,0))){
    SWIG_fail_ptr("SArrayDisplayAnalogF_bytes_get",1,SWIGTYPE_p_SArrayDisplayAnalogF);
  }
  
  result = (float *)(float *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_float,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalogF___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalogF *arg1 = (SArrayDisplayAnalogF *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayDisplayAnalogF::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalogF::__len",1,"SArrayDisplayAnalogF const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalogF,0))){
    SWIG_fail_ptr("SArrayDisplayAnalogF___len",1,SWIGTYPE_p_SArrayDisplayAnalogF);
  }
  
  result = (int)SArrayDisplayAnalogF___len((SArrayDisplayAnalogF const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalogF___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalogF *arg1 = (SArrayDisplayAnalogF *) 0 ;
  int arg2 ;
  float result;
  
  SWIG_check_num_args("SArrayDisplayAnalogF::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalogF::__getitem",1,"SArrayDisplayAnalogF *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayDisplayAnalogF::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalogF,0))){
    SWIG_fail_ptr("SArrayDisplayAnalogF___getitem",1,SWIGTYPE_p_SArrayDisplayAnalogF);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (float)SArrayDisplayAnalogF___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayAnalogF___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalogF *arg1 = (SArrayDisplayAnalogF *) 0 ;
  int arg2 ;
  float arg3 ;
  
  SWIG_check_num_args("SArrayDisplayAnalogF::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayAnalogF::__setitem",1,"SArrayDisplayAnalogF *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayDisplayAnalogF::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayDisplayAnalogF::__setitem",3,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayAnalogF,0))){
    SWIG_fail_ptr("SArrayDisplayAnalogF___setitem",1,SWIGTYPE_p_SArrayDisplayAnalogF);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  arg3 = (float)lua_tonumber(L, 3);
  SArrayDisplayAnalogF___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayDisplayAnalogF(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayAnalogF *result = 0 ;
  
  SWIG_check_num_args("SArrayDisplayAnalogF::SArrayDisplayAnalogF",0,0)
  result = (SArrayDisplayAnalogF *)calloc(1, sizeof(SArrayDisplayAnalogF));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayDisplayAnalogF,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayDisplayAnalogF(void *obj) {
SArrayDisplayAnalogF *arg1 = (SArrayDisplayAnalogF *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayDisplayAnalogF(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayDisplayAnalogF);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayDisplayAnalogF_attributes[] = {
    { "bytes", _wrap_SArrayDisplayAnalogF_bytes_get, _wrap_SArrayDisplayAnalogF_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayDisplayAnalogF_methods[]= {
    { "__len", _wrap_SArrayDisplayAnalogF___len},
    { "__getitem", _wrap_SArrayDisplayAnalogF___getitem},
    { "__setitem", _wrap_SArrayDisplayAnalogF___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayDisplayAnalogF_meta[] = {
    { "__len", _wrap_SArrayDisplayAnalogF___len},
    { "__getitem", _wrap_SArrayDisplayAnalogF___getitem},
    { "__setitem", _wrap_SArrayDisplayAnalogF___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayDisplayAnalogF_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayDisplayAnalogF_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayDisplayAnalogF_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayDisplayAnalogF_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayDisplayAnalogF_Sf_SwigStatic = {
    "SArrayDisplayAnalogF",
    swig_SArrayDisplayAnalogF_Sf_SwigStatic_methods,
    swig_SArrayDisplayAnalogF_Sf_SwigStatic_attributes,
    swig_SArrayDisplayAnalogF_Sf_SwigStatic_constants,
    swig_SArrayDisplayAnalogF_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayDisplayAnalogF_bases[] = {0};
static const char *swig_SArrayDisplayAnalogF_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayDisplayAnalogF = { "SArrayDisplayAnalogF", "SArrayDisplayAnalogF", &SWIGTYPE_p_SArrayDisplayAnalogF,_proxy__wrap_new_SArrayDisplayAnalogF, swig_delete_SArrayDisplayAnalogF, swig_SArrayDisplayAnalogF_methods, swig_SArrayDisplayAnalogF_attributes, &swig_SArrayDisplayAnalogF_Sf_SwigStatic, swig_SArrayDisplayAnalogF_meta, swig_SArrayDisplayAnalogF_bases, swig_SArrayDisplayAnalogF_base_names };

static int _wrap_SArrayDisplayDigital_bytes_set(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayDigital *arg1 = (SArrayDisplayDigital *) 0 ;
  ushort *arg2 ;
  
  SWIG_check_num_args("SArrayDisplayDigital::bytes",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayDigital::bytes",1,"SArrayDisplayDigital *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SArrayDisplayDigital::bytes",2,"ushort [10000]");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayDigital,0))){
    SWIG_fail_ptr("SArrayDisplayDigital_bytes_set",1,SWIGTYPE_p_SArrayDisplayDigital);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_short,0))){
    SWIG_fail_ptr("SArrayDisplayDigital_bytes_set",2,SWIGTYPE_p_unsigned_short);
  }
  
  {
    size_t ii;
    ushort *b = (ushort *) arg1->bytes;
    for (ii = 0; ii < (size_t)10000; ii++) b[ii] = *((ushort *) arg2 + ii);
  }
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayDigital_bytes_get(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayDigital *arg1 = (SArrayDisplayDigital *) 0 ;
  ushort *result = 0 ;
  
  SWIG_check_num_args("SArrayDisplayDigital::bytes",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayDigital::bytes",1,"SArrayDisplayDigital *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayDigital,0))){
    SWIG_fail_ptr("SArrayDisplayDigital_bytes_get",1,SWIGTYPE_p_SArrayDisplayDigital);
  }
  
  result = (ushort *)(ushort *) ((arg1)->bytes);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_short,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayDigital___len(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayDigital *arg1 = (SArrayDisplayDigital *) 0 ;
  int result;
  
  SWIG_check_num_args("SArrayDisplayDigital::__len",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayDigital::__len",1,"SArrayDisplayDigital const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayDigital,0))){
    SWIG_fail_ptr("SArrayDisplayDigital___len",1,SWIGTYPE_p_SArrayDisplayDigital);
  }
  
  result = (int)SArrayDisplayDigital___len((SArrayDisplayDigital const *)arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayDigital___getitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayDigital *arg1 = (SArrayDisplayDigital *) 0 ;
  int arg2 ;
  ushort result;
  
  SWIG_check_num_args("SArrayDisplayDigital::__getitem",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayDigital::__getitem",1,"SArrayDisplayDigital *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayDisplayDigital::__getitem",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayDigital,0))){
    SWIG_fail_ptr("SArrayDisplayDigital___getitem",1,SWIGTYPE_p_SArrayDisplayDigital);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (ushort)SArrayDisplayDigital___getitem(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SArrayDisplayDigital___setitem(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayDigital *arg1 = (SArrayDisplayDigital *) 0 ;
  int arg2 ;
  ushort arg3 ;
  
  SWIG_check_num_args("SArrayDisplayDigital::__setitem",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SArrayDisplayDigital::__setitem",1,"SArrayDisplayDigital *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SArrayDisplayDigital::__setitem",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("SArrayDisplayDigital::__setitem",3,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SArrayDisplayDigital,0))){
    SWIG_fail_ptr("SArrayDisplayDigital___setitem",1,SWIGTYPE_p_SArrayDisplayDigital);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (ushort)lua_tonumber(L, 3);
  SArrayDisplayDigital___setitem(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SArrayDisplayDigital(lua_State* L) {
  int SWIG_arg = 0;
  SArrayDisplayDigital *result = 0 ;
  
  SWIG_check_num_args("SArrayDisplayDigital::SArrayDisplayDigital",0,0)
  result = (SArrayDisplayDigital *)calloc(1, sizeof(SArrayDisplayDigital));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayDisplayDigital,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SArrayDisplayDigital(void *obj) {
SArrayDisplayDigital *arg1 = (SArrayDisplayDigital *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SArrayDisplayDigital(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SArrayDisplayDigital);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SArrayDisplayDigital_attributes[] = {
    { "bytes", _wrap_SArrayDisplayDigital_bytes_get, _wrap_SArrayDisplayDigital_bytes_set },
    {0,0,0}
};
static swig_lua_method swig_SArrayDisplayDigital_methods[]= {
    { "__len", _wrap_SArrayDisplayDigital___len},
    { "__getitem", _wrap_SArrayDisplayDigital___getitem},
    { "__setitem", _wrap_SArrayDisplayDigital___setitem},
    {0,0}
};
static swig_lua_method swig_SArrayDisplayDigital_meta[] = {
    { "__len", _wrap_SArrayDisplayDigital___len},
    { "__getitem", _wrap_SArrayDisplayDigital___getitem},
    { "__setitem", _wrap_SArrayDisplayDigital___setitem},
    {0,0}
};

static swig_lua_attribute swig_SArrayDisplayDigital_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SArrayDisplayDigital_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SArrayDisplayDigital_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SArrayDisplayDigital_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SArrayDisplayDigital_Sf_SwigStatic = {
    "SArrayDisplayDigital",
    swig_SArrayDisplayDigital_Sf_SwigStatic_methods,
    swig_SArrayDisplayDigital_Sf_SwigStatic_attributes,
    swig_SArrayDisplayDigital_Sf_SwigStatic_constants,
    swig_SArrayDisplayDigital_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SArrayDisplayDigital_bases[] = {0};
static const char *swig_SArrayDisplayDigital_base_names[] = {0};
static swig_lua_class _wrap_class_SArrayDisplayDigital = { "SArrayDisplayDigital", "SArrayDisplayDigital", &SWIGTYPE_p_SArrayDisplayDigital,_proxy__wrap_new_SArrayDisplayDigital, swig_delete_SArrayDisplayDigital, swig_SArrayDisplayDigital_methods, swig_SArrayDisplayDigital_attributes, &swig_SArrayDisplayDigital_Sf_SwigStatic, swig_SArrayDisplayDigital_meta, swig_SArrayDisplayDigital_bases, swig_SArrayDisplayDigital_base_names };

static int _wrap_SDisplay_analog0_set(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  SArrayDisplayAnalog0 *arg2 = (SArrayDisplayAnalog0 *) 0 ;
  
  SWIG_check_num_args("SDisplay::analog0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::analog0",1,"SDisplay *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SDisplay::analog0",2,"SArrayDisplayAnalog0 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_analog0_set",1,SWIGTYPE_p_SDisplay);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayDisplayAnalog0,0))){
    SWIG_fail_ptr("SDisplay_analog0_set",2,SWIGTYPE_p_SArrayDisplayAnalog0);
  }
  
  if (arg1) (arg1)->analog0 = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_analog0_get(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  SArrayDisplayAnalog0 *result = 0 ;
  
  SWIG_check_num_args("SDisplay::analog0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::analog0",1,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_analog0_get",1,SWIGTYPE_p_SDisplay);
  }
  
  result = (SArrayDisplayAnalog0 *)& ((arg1)->analog0);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayDisplayAnalog0,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_analog1_set(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  SArrayDisplayAnalog1 *arg2 = (SArrayDisplayAnalog1 *) 0 ;
  
  SWIG_check_num_args("SDisplay::analog1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::analog1",1,"SDisplay *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SDisplay::analog1",2,"SArrayDisplayAnalog1 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_analog1_set",1,SWIGTYPE_p_SDisplay);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayDisplayAnalog1,0))){
    SWIG_fail_ptr("SDisplay_analog1_set",2,SWIGTYPE_p_SArrayDisplayAnalog1);
  }
  
  if (arg1) (arg1)->analog1 = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_analog1_get(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  SArrayDisplayAnalog1 *result = 0 ;
  
  SWIG_check_num_args("SDisplay::analog1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::analog1",1,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_analog1_get",1,SWIGTYPE_p_SDisplay);
  }
  
  result = (SArrayDisplayAnalog1 *)& ((arg1)->analog1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayDisplayAnalog1,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_analogF_set(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  SArrayDisplayAnalogF *arg2 = (SArrayDisplayAnalogF *) 0 ;
  
  SWIG_check_num_args("SDisplay::analogF",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::analogF",1,"SDisplay *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SDisplay::analogF",2,"SArrayDisplayAnalogF *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_analogF_set",1,SWIGTYPE_p_SDisplay);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayDisplayAnalogF,0))){
    SWIG_fail_ptr("SDisplay_analogF_set",2,SWIGTYPE_p_SArrayDisplayAnalogF);
  }
  
  if (arg1) (arg1)->analogF = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_analogF_get(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  SArrayDisplayAnalogF *result = 0 ;
  
  SWIG_check_num_args("SDisplay::analogF",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::analogF",1,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_analogF_get",1,SWIGTYPE_p_SDisplay);
  }
  
  result = (SArrayDisplayAnalogF *)& ((arg1)->analogF);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayDisplayAnalogF,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_digital_set(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  SArrayDisplayDigital *arg2 = (SArrayDisplayDigital *) 0 ;
  
  SWIG_check_num_args("SDisplay::digital",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::digital",1,"SDisplay *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SDisplay::digital",2,"SArrayDisplayDigital *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_digital_set",1,SWIGTYPE_p_SDisplay);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayDisplayDigital,0))){
    SWIG_fail_ptr("SDisplay_digital_set",2,SWIGTYPE_p_SArrayDisplayDigital);
  }
  
  if (arg1) (arg1)->digital = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_digital_get(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  SArrayDisplayDigital *result = 0 ;
  
  SWIG_check_num_args("SDisplay::digital",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::digital",1,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_digital_get",1,SWIGTYPE_p_SDisplay);
  }
  
  result = (SArrayDisplayDigital *)& ((arg1)->digital);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SArrayDisplayDigital,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_samples_set(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SDisplay::samples",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::samples",1,"SDisplay *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SDisplay::samples",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_samples_set",1,SWIGTYPE_p_SDisplay);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->samples = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_samples_get(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  uint result;
  
  SWIG_check_num_args("SDisplay::samples",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::samples",1,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_samples_get",1,SWIGTYPE_p_SDisplay);
  }
  
  result = (uint) ((arg1)->samples);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_capture_set(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SDisplay::capture",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::capture",1,"SDisplay *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SDisplay::capture",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_capture_set",1,SWIGTYPE_p_SDisplay);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->capture = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_capture_get(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  uint result;
  
  SWIG_check_num_args("SDisplay::capture",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::capture",1,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_capture_get",1,SWIGTYPE_p_SDisplay);
  }
  
  result = (uint) ((arg1)->capture);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_ets_set(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SDisplay::ets",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::ets",1,"SDisplay *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SDisplay::ets",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_ets_set",1,SWIGTYPE_p_SDisplay);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->ets = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_ets_get(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  uint result;
  
  SWIG_check_num_args("SDisplay::ets",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::ets",1,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_ets_get",1,SWIGTYPE_p_SDisplay);
  }
  
  result = (uint) ((arg1)->ets);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_attr_set(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SDisplay::attr",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::attr",1,"SDisplay *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SDisplay::attr",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_attr_set",1,SWIGTYPE_p_SDisplay);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->attr = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SDisplay_attr_get(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  uint result;
  
  SWIG_check_num_args("SDisplay::attr",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SDisplay::attr",1,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SDisplay_attr_get",1,SWIGTYPE_p_SDisplay);
  }
  
  result = (uint) ((arg1)->attr);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SDisplay(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *result = 0 ;
  
  SWIG_check_num_args("SDisplay::SDisplay",0,0)
  result = (SDisplay *)calloc(1, sizeof(SDisplay));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SDisplay,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SDisplay(void *obj) {
SDisplay *arg1 = (SDisplay *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SDisplay(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SDisplay);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SDisplay_attributes[] = {
    { "analog0", _wrap_SDisplay_analog0_get, _wrap_SDisplay_analog0_set },
    { "analog1", _wrap_SDisplay_analog1_get, _wrap_SDisplay_analog1_set },
    { "analogF", _wrap_SDisplay_analogF_get, _wrap_SDisplay_analogF_set },
    { "digital", _wrap_SDisplay_digital_get, _wrap_SDisplay_digital_set },
    { "samples", _wrap_SDisplay_samples_get, _wrap_SDisplay_samples_set },
    { "capture", _wrap_SDisplay_capture_get, _wrap_SDisplay_capture_set },
    { "ets", _wrap_SDisplay_ets_get, _wrap_SDisplay_ets_set },
    { "attr", _wrap_SDisplay_attr_get, _wrap_SDisplay_attr_set },
    {0,0,0}
};
static swig_lua_method swig_SDisplay_methods[]= {
    {0,0}
};
static swig_lua_method swig_SDisplay_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SDisplay_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SDisplay_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SDisplay_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SDisplay_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SDisplay_Sf_SwigStatic = {
    "SDisplay",
    swig_SDisplay_Sf_SwigStatic_methods,
    swig_SDisplay_Sf_SwigStatic_attributes,
    swig_SDisplay_Sf_SwigStatic_constants,
    swig_SDisplay_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SDisplay_bases[] = {0};
static const char *swig_SDisplay_base_names[] = {0};
static swig_lua_class _wrap_class_SDisplay = { "SDisplay", "SDisplay", &SWIGTYPE_p_SDisplay,_proxy__wrap_new_SDisplay, swig_delete_SDisplay, swig_SDisplay_methods, swig_SDisplay_attributes, &swig_SDisplay_Sf_SwigStatic, swig_SDisplay_meta, swig_SDisplay_bases, swig_SDisplay_base_names };

static int _wrap_SAtomic_value_set(lua_State* L) {
  int SWIG_arg = 0;
  SAtomic *arg1 = (SAtomic *) 0 ;
  int arg2 ;
  
  SWIG_check_num_args("SAtomic::value",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SAtomic::value",1,"SAtomic *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SAtomic::value",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SAtomic,0))){
    SWIG_fail_ptr("SAtomic_value_set",1,SWIGTYPE_p_SAtomic);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  if (arg1) (arg1)->value = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SAtomic_value_get(lua_State* L) {
  int SWIG_arg = 0;
  SAtomic *arg1 = (SAtomic *) 0 ;
  int result;
  
  SWIG_check_num_args("SAtomic::value",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SAtomic::value",1,"SAtomic *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SAtomic,0))){
    SWIG_fail_ptr("SAtomic_value_get",1,SWIGTYPE_p_SAtomic);
  }
  
  result = (int) ((arg1)->value);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SAtomic(lua_State* L) {
  int SWIG_arg = 0;
  SAtomic *result = 0 ;
  
  SWIG_check_num_args("SAtomic::SAtomic",0,0)
  result = (SAtomic *)calloc(1, sizeof(SAtomic));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SAtomic,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SAtomic(void *obj) {
SAtomic *arg1 = (SAtomic *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SAtomic(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SAtomic);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SAtomic_attributes[] = {
    { "value", _wrap_SAtomic_value_get, _wrap_SAtomic_value_set },
    {0,0,0}
};
static swig_lua_method swig_SAtomic_methods[]= {
    {0,0}
};
static swig_lua_method swig_SAtomic_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SAtomic_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SAtomic_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SAtomic_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SAtomic_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SAtomic_Sf_SwigStatic = {
    "SAtomic",
    swig_SAtomic_Sf_SwigStatic_methods,
    swig_SAtomic_Sf_SwigStatic_attributes,
    swig_SAtomic_Sf_SwigStatic_constants,
    swig_SAtomic_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SAtomic_bases[] = {0};
static const char *swig_SAtomic_base_names[] = {0};
static swig_lua_class _wrap_class_SAtomic = { "SAtomic", "SAtomic", &SWIGTYPE_p_SAtomic,_proxy__wrap_new_SAtomic, swig_delete_SAtomic, swig_SAtomic_methods, swig_SAtomic_attributes, &swig_SAtomic_Sf_SwigStatic, swig_SAtomic_meta, swig_SAtomic_bases, swig_SAtomic_base_names };

static int _wrap_SCtxSimulate_on_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxSimulate *arg1 = (SCtxSimulate *) 0 ;
  SAtomic *arg2 = (SAtomic *) 0 ;
  
  SWIG_check_num_args("SCtxSimulate::on",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxSimulate::on",1,"SCtxSimulate *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SCtxSimulate::on",2,"SAtomic *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxSimulate,0))){
    SWIG_fail_ptr("SCtxSimulate_on_set",1,SWIGTYPE_p_SCtxSimulate);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SAtomic,0))){
    SWIG_fail_ptr("SCtxSimulate_on_set",2,SWIGTYPE_p_SAtomic);
  }
  
  if (arg1) (arg1)->on = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxSimulate_on_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxSimulate *arg1 = (SCtxSimulate *) 0 ;
  SAtomic *result = 0 ;
  
  SWIG_check_num_args("SCtxSimulate::on",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxSimulate::on",1,"SCtxSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxSimulate,0))){
    SWIG_fail_ptr("SCtxSimulate_on_get",1,SWIGTYPE_p_SCtxSimulate);
  }
  
  result = (SAtomic *)& ((arg1)->on);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SAtomic,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxSimulate_data_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxSimulate *arg1 = (SCtxSimulate *) 0 ;
  SSimulate *arg2 = (SSimulate *) 0 ;
  
  SWIG_check_num_args("SCtxSimulate::data",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxSimulate::data",1,"SCtxSimulate *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SCtxSimulate::data",2,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxSimulate,0))){
    SWIG_fail_ptr("SCtxSimulate_data_set",1,SWIGTYPE_p_SCtxSimulate);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SCtxSimulate_data_set",2,SWIGTYPE_p_SSimulate);
  }
  
  if (arg1) (arg1)->data = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxSimulate_data_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxSimulate *arg1 = (SCtxSimulate *) 0 ;
  SSimulate *result = 0 ;
  
  SWIG_check_num_args("SCtxSimulate::data",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxSimulate::data",1,"SCtxSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxSimulate,0))){
    SWIG_fail_ptr("SCtxSimulate_data_get",1,SWIGTYPE_p_SCtxSimulate);
  }
  
  result = (SSimulate *)& ((arg1)->data);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SSimulate,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxSimulate_active_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxSimulate *arg1 = (SCtxSimulate *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SCtxSimulate::active",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxSimulate::active",1,"SCtxSimulate *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxSimulate::active",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxSimulate,0))){
    SWIG_fail_ptr("SCtxSimulate_active_set",1,SWIGTYPE_p_SCtxSimulate);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->active = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxSimulate_active_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxSimulate *arg1 = (SCtxSimulate *) 0 ;
  uint result;
  
  SWIG_check_num_args("SCtxSimulate::active",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxSimulate::active",1,"SCtxSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxSimulate,0))){
    SWIG_fail_ptr("SCtxSimulate_active_get",1,SWIGTYPE_p_SCtxSimulate);
  }
  
  result = (uint) ((arg1)->active);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SCtxSimulate(lua_State* L) {
  int SWIG_arg = 0;
  SCtxSimulate *result = 0 ;
  
  SWIG_check_num_args("SCtxSimulate::SCtxSimulate",0,0)
  result = (SCtxSimulate *)calloc(1, sizeof(SCtxSimulate));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SCtxSimulate,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SCtxSimulate(void *obj) {
SCtxSimulate *arg1 = (SCtxSimulate *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SCtxSimulate(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SCtxSimulate);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SCtxSimulate_attributes[] = {
    { "on", _wrap_SCtxSimulate_on_get, _wrap_SCtxSimulate_on_set },
    { "data", _wrap_SCtxSimulate_data_get, _wrap_SCtxSimulate_data_set },
    { "active", _wrap_SCtxSimulate_active_get, _wrap_SCtxSimulate_active_set },
    {0,0,0}
};
static swig_lua_method swig_SCtxSimulate_methods[]= {
    {0,0}
};
static swig_lua_method swig_SCtxSimulate_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SCtxSimulate_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SCtxSimulate_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SCtxSimulate_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SCtxSimulate_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SCtxSimulate_Sf_SwigStatic = {
    "SCtxSimulate",
    swig_SCtxSimulate_Sf_SwigStatic_methods,
    swig_SCtxSimulate_Sf_SwigStatic_attributes,
    swig_SCtxSimulate_Sf_SwigStatic_constants,
    swig_SCtxSimulate_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SCtxSimulate_bases[] = {0};
static const char *swig_SCtxSimulate_base_names[] = {0};
static swig_lua_class _wrap_class_SCtxSimulate = { "SCtxSimulate", "SCtxSimulate", &SWIGTYPE_p_SCtxSimulate,_proxy__wrap_new_SCtxSimulate, swig_delete_SCtxSimulate, swig_SCtxSimulate_methods, swig_SCtxSimulate_attributes, &swig_SCtxSimulate_Sf_SwigStatic, swig_SCtxSimulate_meta, swig_SCtxSimulate_bases, swig_SCtxSimulate_base_names };

static int _wrap_SCtxFrame_maxMemory_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxFrame *arg1 = (SCtxFrame *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SCtxFrame::maxMemory",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxFrame::maxMemory",1,"SCtxFrame *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxFrame::maxMemory",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxFrame,0))){
    SWIG_fail_ptr("SCtxFrame_maxMemory_set",1,SWIGTYPE_p_SCtxFrame);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->maxMemory = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxFrame_maxMemory_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxFrame *arg1 = (SCtxFrame *) 0 ;
  uint result;
  
  SWIG_check_num_args("SCtxFrame::maxMemory",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxFrame::maxMemory",1,"SCtxFrame *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxFrame,0))){
    SWIG_fail_ptr("SCtxFrame_maxMemory_get",1,SWIGTYPE_p_SCtxFrame);
  }
  
  result = (uint) ((arg1)->maxMemory);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxFrame_data_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxFrame *arg1 = (SCtxFrame *) 0 ;
  SFrameData *arg2 = (SFrameData *) 0 ;
  
  SWIG_check_num_args("SCtxFrame::data",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxFrame::data",1,"SCtxFrame *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SCtxFrame::data",2,"SFrameData *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxFrame,0))){
    SWIG_fail_ptr("SCtxFrame_data_set",1,SWIGTYPE_p_SCtxFrame);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SFrameData,0))){
    SWIG_fail_ptr("SCtxFrame_data_set",2,SWIGTYPE_p_SFrameData);
  }
  
  if (arg1) (arg1)->data = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxFrame_data_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxFrame *arg1 = (SCtxFrame *) 0 ;
  SFrameData *result = 0 ;
  
  SWIG_check_num_args("SCtxFrame::data",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxFrame::data",1,"SCtxFrame *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxFrame,0))){
    SWIG_fail_ptr("SCtxFrame_data_get",1,SWIGTYPE_p_SCtxFrame);
  }
  
  result = (SFrameData *)& ((arg1)->data);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFrameData,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxFrame_received_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxFrame *arg1 = (SCtxFrame *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SCtxFrame::received",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxFrame::received",1,"SCtxFrame *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxFrame::received",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxFrame,0))){
    SWIG_fail_ptr("SCtxFrame_received_set",1,SWIGTYPE_p_SCtxFrame);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->received = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxFrame_received_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxFrame *arg1 = (SCtxFrame *) 0 ;
  uint result;
  
  SWIG_check_num_args("SCtxFrame::received",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxFrame::received",1,"SCtxFrame *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxFrame,0))){
    SWIG_fail_ptr("SCtxFrame_received_get",1,SWIGTYPE_p_SCtxFrame);
  }
  
  result = (uint) ((arg1)->received);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxFrame_frameSize_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxFrame *arg1 = (SCtxFrame *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SCtxFrame::frameSize",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxFrame::frameSize",1,"SCtxFrame *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxFrame::frameSize",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxFrame,0))){
    SWIG_fail_ptr("SCtxFrame_frameSize_set",1,SWIGTYPE_p_SCtxFrame);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->frameSize = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxFrame_frameSize_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxFrame *arg1 = (SCtxFrame *) 0 ;
  uint result;
  
  SWIG_check_num_args("SCtxFrame::frameSize",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxFrame::frameSize",1,"SCtxFrame *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxFrame,0))){
    SWIG_fail_ptr("SCtxFrame_frameSize_get",1,SWIGTYPE_p_SCtxFrame);
  }
  
  result = (uint) ((arg1)->frameSize);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SCtxFrame(lua_State* L) {
  int SWIG_arg = 0;
  SCtxFrame *result = 0 ;
  
  SWIG_check_num_args("SCtxFrame::SCtxFrame",0,0)
  result = (SCtxFrame *)calloc(1, sizeof(SCtxFrame));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SCtxFrame,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SCtxFrame(void *obj) {
SCtxFrame *arg1 = (SCtxFrame *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SCtxFrame(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SCtxFrame);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SCtxFrame_attributes[] = {
    { "maxMemory", _wrap_SCtxFrame_maxMemory_get, _wrap_SCtxFrame_maxMemory_set },
    { "data", _wrap_SCtxFrame_data_get, _wrap_SCtxFrame_data_set },
    { "received", _wrap_SCtxFrame_received_get, _wrap_SCtxFrame_received_set },
    { "frameSize", _wrap_SCtxFrame_frameSize_get, _wrap_SCtxFrame_frameSize_set },
    {0,0,0}
};
static swig_lua_method swig_SCtxFrame_methods[]= {
    {0,0}
};
static swig_lua_method swig_SCtxFrame_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SCtxFrame_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SCtxFrame_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SCtxFrame_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SCtxFrame_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SCtxFrame_Sf_SwigStatic = {
    "SCtxFrame",
    swig_SCtxFrame_Sf_SwigStatic_methods,
    swig_SCtxFrame_Sf_SwigStatic_attributes,
    swig_SCtxFrame_Sf_SwigStatic_constants,
    swig_SCtxFrame_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SCtxFrame_bases[] = {0};
static const char *swig_SCtxFrame_base_names[] = {0};
static swig_lua_class _wrap_class_SCtxFrame = { "SCtxFrame", "SCtxFrame", &SWIGTYPE_p_SCtxFrame,_proxy__wrap_new_SCtxFrame, swig_delete_SCtxFrame, swig_SCtxFrame_methods, swig_SCtxFrame_attributes, &swig_SCtxFrame_Sf_SwigStatic, swig_SCtxFrame_meta, swig_SCtxFrame_bases, swig_SCtxFrame_base_names };

static int _wrap_SCtxDisplay_data_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxDisplay *arg1 = (SCtxDisplay *) 0 ;
  SDisplay *arg2 = (SDisplay *) 0 ;
  
  SWIG_check_num_args("SCtxDisplay::data",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxDisplay::data",1,"SCtxDisplay *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SCtxDisplay::data",2,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxDisplay,0))){
    SWIG_fail_ptr("SCtxDisplay_data_set",1,SWIGTYPE_p_SCtxDisplay);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("SCtxDisplay_data_set",2,SWIGTYPE_p_SDisplay);
  }
  
  if (arg1) (arg1)->data = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxDisplay_data_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxDisplay *arg1 = (SCtxDisplay *) 0 ;
  SDisplay *result = 0 ;
  
  SWIG_check_num_args("SCtxDisplay::data",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxDisplay::data",1,"SCtxDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxDisplay,0))){
    SWIG_fail_ptr("SCtxDisplay_data_get",1,SWIGTYPE_p_SCtxDisplay);
  }
  
  result = (SDisplay *)& ((arg1)->data);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SDisplay,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SCtxDisplay(lua_State* L) {
  int SWIG_arg = 0;
  SCtxDisplay *result = 0 ;
  
  SWIG_check_num_args("SCtxDisplay::SCtxDisplay",0,0)
  result = (SCtxDisplay *)calloc(1, sizeof(SCtxDisplay));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SCtxDisplay,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SCtxDisplay(void *obj) {
SCtxDisplay *arg1 = (SCtxDisplay *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SCtxDisplay(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SCtxDisplay);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SCtxDisplay_attributes[] = {
    { "data", _wrap_SCtxDisplay_data_get, _wrap_SCtxDisplay_data_set },
    {0,0,0}
};
static swig_lua_method swig_SCtxDisplay_methods[]= {
    {0,0}
};
static swig_lua_method swig_SCtxDisplay_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SCtxDisplay_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SCtxDisplay_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SCtxDisplay_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SCtxDisplay_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SCtxDisplay_Sf_SwigStatic = {
    "SCtxDisplay",
    swig_SCtxDisplay_Sf_SwigStatic_methods,
    swig_SCtxDisplay_Sf_SwigStatic_attributes,
    swig_SCtxDisplay_Sf_SwigStatic_constants,
    swig_SCtxDisplay_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SCtxDisplay_bases[] = {0};
static const char *swig_SCtxDisplay_base_names[] = {0};
static swig_lua_class _wrap_class_SCtxDisplay = { "SCtxDisplay", "SCtxDisplay", &SWIGTYPE_p_SCtxDisplay,_proxy__wrap_new_SCtxDisplay, swig_delete_SCtxDisplay, swig_SCtxDisplay_methods, swig_SCtxDisplay_attributes, &swig_SCtxDisplay_Sf_SwigStatic, swig_SCtxDisplay_meta, swig_SCtxDisplay_bases, swig_SCtxDisplay_base_names };

static int _wrap_SCtxApi_version_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SCtxApi::version",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::version",1,"SCtxApi *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxApi::version",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_version_set",1,SWIGTYPE_p_SCtxApi);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->version = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_version_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint result;
  
  SWIG_check_num_args("SCtxApi::version",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::version",1,"SCtxApi *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_version_get",1,SWIGTYPE_p_SCtxApi);
  }
  
  result = (uint) ((arg1)->version);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_major_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SCtxApi::major",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::major",1,"SCtxApi *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxApi::major",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_major_set",1,SWIGTYPE_p_SCtxApi);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->major = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_major_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint result;
  
  SWIG_check_num_args("SCtxApi::major",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::major",1,"SCtxApi *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_major_get",1,SWIGTYPE_p_SCtxApi);
  }
  
  result = (uint) ((arg1)->major);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_minor_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SCtxApi::minor",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::minor",1,"SCtxApi *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxApi::minor",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_minor_set",1,SWIGTYPE_p_SCtxApi);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->minor = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_minor_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint result;
  
  SWIG_check_num_args("SCtxApi::minor",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::minor",1,"SCtxApi *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_minor_get",1,SWIGTYPE_p_SCtxApi);
  }
  
  result = (uint) ((arg1)->minor);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_active_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SCtxApi::active",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::active",1,"SCtxApi *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxApi::active",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_active_set",1,SWIGTYPE_p_SCtxApi);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->active = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_active_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint result;
  
  SWIG_check_num_args("SCtxApi::active",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::active",1,"SCtxApi *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_active_get",1,SWIGTYPE_p_SCtxApi);
  }
  
  result = (uint) ((arg1)->active);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_thread_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  SAtomic *arg2 = (SAtomic *) 0 ;
  
  SWIG_check_num_args("SCtxApi::thread",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::thread",1,"SCtxApi *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SCtxApi::thread",2,"SAtomic *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_thread_set",1,SWIGTYPE_p_SCtxApi);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SAtomic,0))){
    SWIG_fail_ptr("SCtxApi_thread_set",2,SWIGTYPE_p_SAtomic);
  }
  
  if (arg1) (arg1)->thread = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_thread_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  SAtomic *result = 0 ;
  
  SWIG_check_num_args("SCtxApi::thread",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::thread",1,"SCtxApi *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_thread_get",1,SWIGTYPE_p_SCtxApi);
  }
  
  result = (SAtomic *)& ((arg1)->thread);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SAtomic,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_lock_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  SSpinLock arg2 ;
  
  SWIG_check_num_args("SCtxApi::lock",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::lock",1,"SCtxApi *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxApi::lock",2,"SSpinLock");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_lock_set",1,SWIGTYPE_p_SCtxApi);
  }
  
  arg2 = (SSpinLock)lua_tonumber(L, 2);
  if (arg1) (arg1)->lock = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_lock_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  SSpinLock result;
  
  SWIG_check_num_args("SCtxApi::lock",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::lock",1,"SCtxApi *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_lock_get",1,SWIGTYPE_p_SCtxApi);
  }
  
  result = (SSpinLock) ((arg1)->lock);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_timeout_set(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SCtxApi::timeout",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::timeout",1,"SCtxApi *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SCtxApi::timeout",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_timeout_set",1,SWIGTYPE_p_SCtxApi);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->timeout = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCtxApi_timeout_get(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *arg1 = (SCtxApi *) 0 ;
  uint result;
  
  SWIG_check_num_args("SCtxApi::timeout",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SCtxApi::timeout",1,"SCtxApi *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SCtxApi_timeout_get",1,SWIGTYPE_p_SCtxApi);
  }
  
  result = (uint) ((arg1)->timeout);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SCtxApi(lua_State* L) {
  int SWIG_arg = 0;
  SCtxApi *result = 0 ;
  
  SWIG_check_num_args("SCtxApi::SCtxApi",0,0)
  result = (SCtxApi *)calloc(1, sizeof(SCtxApi));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SCtxApi,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SCtxApi(void *obj) {
SCtxApi *arg1 = (SCtxApi *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SCtxApi(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SCtxApi);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SCtxApi_attributes[] = {
    { "version", _wrap_SCtxApi_version_get, _wrap_SCtxApi_version_set },
    { "major", _wrap_SCtxApi_major_get, _wrap_SCtxApi_major_set },
    { "minor", _wrap_SCtxApi_minor_get, _wrap_SCtxApi_minor_set },
    { "active", _wrap_SCtxApi_active_get, _wrap_SCtxApi_active_set },
    { "thread", _wrap_SCtxApi_thread_get, _wrap_SCtxApi_thread_set },
    { "lock", _wrap_SCtxApi_lock_get, _wrap_SCtxApi_lock_set },
    { "timeout", _wrap_SCtxApi_timeout_get, _wrap_SCtxApi_timeout_set },
    {0,0,0}
};
static swig_lua_method swig_SCtxApi_methods[]= {
    {0,0}
};
static swig_lua_method swig_SCtxApi_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SCtxApi_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SCtxApi_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SCtxApi_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SCtxApi_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SCtxApi_Sf_SwigStatic = {
    "SCtxApi",
    swig_SCtxApi_Sf_SwigStatic_methods,
    swig_SCtxApi_Sf_SwigStatic_attributes,
    swig_SCtxApi_Sf_SwigStatic_constants,
    swig_SCtxApi_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SCtxApi_bases[] = {0};
static const char *swig_SCtxApi_base_names[] = {0};
static swig_lua_class _wrap_class_SCtxApi = { "SCtxApi", "SCtxApi", &SWIGTYPE_p_SCtxApi,_proxy__wrap_new_SCtxApi, swig_delete_SCtxApi, swig_SCtxApi_methods, swig_SCtxApi_attributes, &swig_SCtxApi_Sf_SwigStatic, swig_SCtxApi_meta, swig_SCtxApi_bases, swig_SCtxApi_base_names };

static int _wrap_SFContext_api_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SCtxApi *arg2 = (SCtxApi *) 0 ;
  
  SWIG_check_num_args("SFContext::api",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::api",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFContext::api",2,"SCtxApi *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_api_set",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SCtxApi,0))){
    SWIG_fail_ptr("SFContext_api_set",2,SWIGTYPE_p_SCtxApi);
  }
  
  if (arg1) (arg1)->api = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_api_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SCtxApi *result = 0 ;
  
  SWIG_check_num_args("SFContext::api",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::api",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_api_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (SCtxApi *)& ((arg1)->api);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SCtxApi,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_simulateOn_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SAtomic *arg2 = (SAtomic *) 0 ;
  
  SWIG_check_num_args("SFContext::simulateOn",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::simulateOn",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFContext::simulateOn",2,"SAtomic *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_simulateOn_set",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SAtomic,0))){
    SWIG_fail_ptr("SFContext_simulateOn_set",2,SWIGTYPE_p_SAtomic);
  }
  
  if (arg1) (arg1)->simulateOn = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_simulateOn_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SAtomic *result = 0 ;
  
  SWIG_check_num_args("SFContext::simulateOn",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::simulateOn",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_simulateOn_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (SAtomic *)& ((arg1)->simulateOn);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SAtomic,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_simulateData_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SSimulate *arg2 = (SSimulate *) 0 ;
  
  SWIG_check_num_args("SFContext::simulateData",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::simulateData",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFContext::simulateData",2,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_simulateData_set",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("SFContext_simulateData_set",2,SWIGTYPE_p_SSimulate);
  }
  
  if (arg1) (arg1)->simulateData = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_simulateData_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SSimulate *result = 0 ;
  
  SWIG_check_num_args("SFContext::simulateData",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::simulateData",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_simulateData_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (SSimulate *)& ((arg1)->simulateData);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SSimulate,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_frame_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SCtxFrame *arg2 = (SCtxFrame *) 0 ;
  
  SWIG_check_num_args("SFContext::frame",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::frame",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFContext::frame",2,"SCtxFrame *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_frame_set",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SCtxFrame,0))){
    SWIG_fail_ptr("SFContext_frame_set",2,SWIGTYPE_p_SCtxFrame);
  }
  
  if (arg1) (arg1)->frame = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_frame_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SCtxFrame *result = 0 ;
  
  SWIG_check_num_args("SFContext::frame",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::frame",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_frame_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (SCtxFrame *)& ((arg1)->frame);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SCtxFrame,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_functionType_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  EFunctionType arg2 ;
  
  SWIG_check_num_args("SFContext::functionType",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::functionType",1,"SFContext *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SFContext::functionType",2,"EFunctionType");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_functionType_set",1,SWIGTYPE_p_SFContext);
  }
  
  arg2 = (EFunctionType)(int)lua_tonumber(L, 2);
  if (arg1) (arg1)->functionType = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_functionType_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  EFunctionType result;
  
  SWIG_check_num_args("SFContext::functionType",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::functionType",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_functionType_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (EFunctionType) ((arg1)->functionType);
  lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_generator_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SGenerator *arg2 = (SGenerator *) 0 ;
  
  SWIG_check_num_args("SFContext::generator",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::generator",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFContext::generator",2,"SGenerator *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_generator_set",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SGenerator,0))){
    SWIG_fail_ptr("SFContext_generator_set",2,SWIGTYPE_p_SGenerator);
  }
  
  if (arg1) (arg1)->generator = *arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_generator_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SGenerator *result = 0 ;
  
  SWIG_check_num_args("SFContext::generator",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::generator",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_generator_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (SGenerator *)& ((arg1)->generator);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SGenerator,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_generatorCount_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  uint arg2 ;
  
  SWIG_check_num_args("SFContext::generatorCount",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::generatorCount",1,"SFContext *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("SFContext::generatorCount",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_generatorCount_set",1,SWIGTYPE_p_SFContext);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  if (arg1) (arg1)->generatorCount = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_generatorCount_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  uint result;
  
  SWIG_check_num_args("SFContext::generatorCount",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::generatorCount",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_generatorCount_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (uint) ((arg1)->generatorCount);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_pCallback_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  void *arg2 = (void *) 0 ;
  
  SWIG_check_num_args("SFContext::pCallback",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::pCallback",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFContext::pCallback",2,"void *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_pCallback_set",1,SWIGTYPE_p_SFContext);
  }
  
  arg2=(void *)SWIG_MustGetPtr(L,2,0,0,2,"SFContext_pCallback_set");
  if (arg1) (arg1)->pCallback = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_pCallback_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  void *result = 0 ;
  
  SWIG_check_num_args("SFContext::pCallback",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::pCallback",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_pCallback_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (void *) ((arg1)->pCallback);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_void,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_pUserData_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  void *arg2 = (void *) 0 ;
  
  SWIG_check_num_args("SFContext::pUserData",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::pUserData",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFContext::pUserData",2,"void *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_pUserData_set",1,SWIGTYPE_p_SFContext);
  }
  
  arg2=(void *)SWIG_MustGetPtr(L,2,0,0,2,"SFContext_pUserData_set");
  if (arg1) (arg1)->pUserData = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_pUserData_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  void *result = 0 ;
  
  SWIG_check_num_args("SFContext::pUserData",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::pUserData",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_pUserData_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (void *) ((arg1)->pUserData);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_void,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_usb_set(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  byte *arg2 = (byte *) 0 ;
  
  SWIG_check_num_args("SFContext::usb",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::usb",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("SFContext::usb",2,"byte *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_usb_set",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_unsigned_char,SWIG_POINTER_DISOWN))){
    SWIG_fail_ptr("SFContext_usb_set",2,SWIGTYPE_p_unsigned_char);
  }
  
  if (arg1) (arg1)->usb = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFContext_usb_get(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  byte *result = 0 ;
  
  SWIG_check_num_args("SFContext::usb",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("SFContext::usb",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("SFContext_usb_get",1,SWIGTYPE_p_SFContext);
  }
  
  result = (byte *) ((arg1)->usb);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_unsigned_char,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SFContext(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *result = 0 ;
  
  SWIG_check_num_args("SFContext::SFContext",0,0)
  result = (SFContext *)calloc(1, sizeof(SFContext));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFContext,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SFContext(void *obj) {
SFContext *arg1 = (SFContext *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SFContext(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SFContext);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SFContext_attributes[] = {
    { "api", _wrap_SFContext_api_get, _wrap_SFContext_api_set },
    { "simulateOn", _wrap_SFContext_simulateOn_get, _wrap_SFContext_simulateOn_set },
    { "simulateData", _wrap_SFContext_simulateData_get, _wrap_SFContext_simulateData_set },
    { "frame", _wrap_SFContext_frame_get, _wrap_SFContext_frame_set },
    { "functionType", _wrap_SFContext_functionType_get, _wrap_SFContext_functionType_set },
    { "generator", _wrap_SFContext_generator_get, _wrap_SFContext_generator_set },
    { "generatorCount", _wrap_SFContext_generatorCount_get, _wrap_SFContext_generatorCount_set },
    { "pCallback", _wrap_SFContext_pCallback_get, _wrap_SFContext_pCallback_set },
    { "pUserData", _wrap_SFContext_pUserData_get, _wrap_SFContext_pUserData_set },
    { "usb", _wrap_SFContext_usb_get, _wrap_SFContext_usb_set },
    {0,0,0}
};
static swig_lua_method swig_SFContext_methods[]= {
    {0,0}
};
static swig_lua_method swig_SFContext_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SFContext_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SFContext_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SFContext_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SFContext_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SFContext_Sf_SwigStatic = {
    "SFContext",
    swig_SFContext_Sf_SwigStatic_methods,
    swig_SFContext_Sf_SwigStatic_attributes,
    swig_SFContext_Sf_SwigStatic_constants,
    swig_SFContext_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SFContext_bases[] = {0};
static const char *swig_SFContext_base_names[] = {0};
static swig_lua_class _wrap_class_SFContext = { "SFContext", "SFContext", &SWIGTYPE_p_SFContext,_proxy__wrap_new_SFContext, swig_delete_SFContext, swig_SFContext_methods, swig_SFContext_attributes, &swig_SFContext_Sf_SwigStatic, swig_SFContext_meta, swig_SFContext_bases, swig_SFContext_base_names };

static int _wrap_SCallback_onFrame_set(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*arg2)(SFrameData *,int,float *,float *,void *) = (int (*)(SFrameData *,int,float *,float *,void *)) 0 ;
  
  SWIG_check_num_args("_SCallback::onFrame",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onFrame",1,"struct _SCallback *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("_SCallback::onFrame",2,"int (*)(SFrameData *,int,float *,float *,void *)");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onFrame_set",1,SWIGTYPE_p__SCallback);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_f_p_SFrameData_int_p_float_p_float_p_void__int,0))){
    SWIG_fail_ptr("SCallback_onFrame_set",2,SWIGTYPE_p_f_p_SFrameData_int_p_float_p_float_p_void__int);
  }
  
  if (arg1) (arg1)->onFrame = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onFrame_get(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*result)(SFrameData *,int,float *,float *,void *) = 0 ;
  
  SWIG_check_num_args("_SCallback::onFrame",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onFrame",1,"struct _SCallback *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onFrame_get",1,SWIGTYPE_p__SCallback);
  }
  
  result = (int (*)(SFrameData *,int,float *,float *,void *)) ((arg1)->onFrame);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_f_p_SFrameData_int_p_float_p_float_p_void__int,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onSample_set(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*arg2)(int,ishort *,ishort *,ishort *,ushort *,float *,float *,void *) = (int (*)(int,ishort *,ishort *,ishort *,ushort *,float *,float *,void *)) 0 ;
  
  SWIG_check_num_args("_SCallback::onSample",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onSample",1,"struct _SCallback *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("_SCallback::onSample",2,"int (*)(int,ishort *,ishort *,ishort *,ushort *,float *,float *,void *)");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onSample_set",1,SWIGTYPE_p__SCallback);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int,0))){
    SWIG_fail_ptr("SCallback_onSample_set",2,SWIGTYPE_p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int);
  }
  
  if (arg1) (arg1)->onSample = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onSample_get(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*result)(int,ishort *,ishort *,ishort *,ushort *,float *,float *,void *) = 0 ;
  
  SWIG_check_num_args("_SCallback::onSample",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onSample",1,"struct _SCallback *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onSample_get",1,SWIGTYPE_p__SCallback);
  }
  
  result = (int (*)(int,ishort *,ishort *,ishort *,ushort *,float *,float *,void *)) ((arg1)->onSample);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onDisplay_set(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*arg2)(SDisplay *,float *,float *,void *) = (int (*)(SDisplay *,float *,float *,void *)) 0 ;
  
  SWIG_check_num_args("_SCallback::onDisplay",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onDisplay",1,"struct _SCallback *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("_SCallback::onDisplay",2,"int (*)(SDisplay *,float *,float *,void *)");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onDisplay_set",1,SWIGTYPE_p__SCallback);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_f_p_SDisplay_p_float_p_float_p_void__int,0))){
    SWIG_fail_ptr("SCallback_onDisplay_set",2,SWIGTYPE_p_f_p_SDisplay_p_float_p_float_p_void__int);
  }
  
  if (arg1) (arg1)->onDisplay = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onDisplay_get(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*result)(SDisplay *,float *,float *,void *) = 0 ;
  
  SWIG_check_num_args("_SCallback::onDisplay",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onDisplay",1,"struct _SCallback *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onDisplay_get",1,SWIGTYPE_p__SCallback);
  }
  
  result = (int (*)(SDisplay *,float *,float *,void *)) ((arg1)->onDisplay);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_f_p_SDisplay_p_float_p_float_p_void__int,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onConfigure_set(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*arg2)(SHardware *) = (int (*)(SHardware *)) 0 ;
  
  SWIG_check_num_args("_SCallback::onConfigure",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onConfigure",1,"struct _SCallback *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("_SCallback::onConfigure",2,"int (*)(SHardware *)");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onConfigure_set",1,SWIGTYPE_p__SCallback);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_f_p_SHardware__int,0))){
    SWIG_fail_ptr("SCallback_onConfigure_set",2,SWIGTYPE_p_f_p_SHardware__int);
  }
  
  if (arg1) (arg1)->onConfigure = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onConfigure_get(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*result)(SHardware *) = 0 ;
  
  SWIG_check_num_args("_SCallback::onConfigure",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onConfigure",1,"struct _SCallback *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onConfigure_get",1,SWIGTYPE_p__SCallback);
  }
  
  result = (int (*)(SHardware *)) ((arg1)->onConfigure);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_f_p_SHardware__int,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onInit_set(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*arg2)(SFContext *) = (int (*)(SFContext *)) 0 ;
  
  SWIG_check_num_args("_SCallback::onInit",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onInit",1,"struct _SCallback *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("_SCallback::onInit",2,"int (*)(SFContext *)");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onInit_set",1,SWIGTYPE_p__SCallback);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_f_p_SFContext__int,0))){
    SWIG_fail_ptr("SCallback_onInit_set",2,SWIGTYPE_p_f_p_SFContext__int);
  }
  
  if (arg1) (arg1)->onInit = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onInit_get(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*result)(SFContext *) = 0 ;
  
  SWIG_check_num_args("_SCallback::onInit",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onInit",1,"struct _SCallback *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onInit_get",1,SWIGTYPE_p__SCallback);
  }
  
  result = (int (*)(SFContext *)) ((arg1)->onInit);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_f_p_SFContext__int,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onFunction_set(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*arg2)(ishort,ishort,ishort *) = (int (*)(ishort,ishort,ishort *)) 0 ;
  
  SWIG_check_num_args("_SCallback::onFunction",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onFunction",1,"struct _SCallback *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("_SCallback::onFunction",2,"int (*)(ishort,ishort,ishort *)");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onFunction_set",1,SWIGTYPE_p__SCallback);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_f_short_short_p_short__int,0))){
    SWIG_fail_ptr("SCallback_onFunction_set",2,SWIGTYPE_p_f_short_short_p_short__int);
  }
  
  if (arg1) (arg1)->onFunction = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onFunction_get(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*result)(ishort,ishort,ishort *) = 0 ;
  
  SWIG_check_num_args("_SCallback::onFunction",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onFunction",1,"struct _SCallback *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onFunction_get",1,SWIGTYPE_p__SCallback);
  }
  
  result = (int (*)(ishort,ishort,ishort *)) ((arg1)->onFunction);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_f_short_short_p_short__int,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onUpload_set(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*arg2)(SGenerator *,uint *) = (int (*)(SGenerator *,uint *)) 0 ;
  
  SWIG_check_num_args("_SCallback::onUpload",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onUpload",1,"struct _SCallback *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("_SCallback::onUpload",2,"int (*)(SGenerator *,uint *)");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onUpload_set",1,SWIGTYPE_p__SCallback);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_f_p_SGenerator_p_unsigned_int__int,0))){
    SWIG_fail_ptr("SCallback_onUpload_set",2,SWIGTYPE_p_f_p_SGenerator_p_unsigned_int__int);
  }
  
  if (arg1) (arg1)->onUpload = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SCallback_onUpload_get(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *arg1 = (struct _SCallback *) 0 ;
  int (*result)(SGenerator *,uint *) = 0 ;
  
  SWIG_check_num_args("_SCallback::onUpload",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SCallback::onUpload",1,"struct _SCallback *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("SCallback_onUpload_get",1,SWIGTYPE_p__SCallback);
  }
  
  result = (int (*)(SGenerator *,uint *)) ((arg1)->onUpload);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_f_p_SGenerator_p_unsigned_int__int,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SCallback(lua_State* L) {
  int SWIG_arg = 0;
  struct _SCallback *result = 0 ;
  
  SWIG_check_num_args("_SCallback::_SCallback",0,0)
  result = (struct _SCallback *)calloc(1, sizeof(struct _SCallback));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__SCallback,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SCallback(void *obj) {
struct _SCallback *arg1 = (struct _SCallback *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SCallback(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SCallback);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SCallback_attributes[] = {
    { "onFrame", _wrap_SCallback_onFrame_get, _wrap_SCallback_onFrame_set },
    { "onSample", _wrap_SCallback_onSample_get, _wrap_SCallback_onSample_set },
    { "onDisplay", _wrap_SCallback_onDisplay_get, _wrap_SCallback_onDisplay_set },
    { "onConfigure", _wrap_SCallback_onConfigure_get, _wrap_SCallback_onConfigure_set },
    { "onInit", _wrap_SCallback_onInit_get, _wrap_SCallback_onInit_set },
    { "onFunction", _wrap_SCallback_onFunction_get, _wrap_SCallback_onFunction_set },
    { "onUpload", _wrap_SCallback_onUpload_get, _wrap_SCallback_onUpload_set },
    {0,0,0}
};
static swig_lua_method swig_SCallback_methods[]= {
    {0,0}
};
static swig_lua_method swig_SCallback_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SCallback_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SCallback_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SCallback_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SCallback_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SCallback_Sf_SwigStatic = {
    "SCallback",
    swig_SCallback_Sf_SwigStatic_methods,
    swig_SCallback_Sf_SwigStatic_attributes,
    swig_SCallback_Sf_SwigStatic_constants,
    swig_SCallback_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SCallback_bases[] = {0};
static const char *swig_SCallback_base_names[] = {0};
static swig_lua_class _wrap_class_SCallback = { "SCallback", "SCallback", &SWIGTYPE_p__SCallback,_proxy__wrap_new_SCallback, swig_delete_SCallback, swig_SCallback_methods, swig_SCallback_attributes, &swig_SCallback_Sf_SwigStatic, swig_SCallback_meta, swig_SCallback_bases, swig_SCallback_base_names };

static int _wrap_SInt_value_set(lua_State* L) {
  int SWIG_arg = 0;
  struct _SInt *arg1 = (struct _SInt *) 0 ;
  int arg2 ;
  
  SWIG_check_num_args("_SInt::value",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SInt::value",1,"struct _SInt *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("_SInt::value",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("SInt_value_set",1,SWIGTYPE_p__SInt);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  if (arg1) (arg1)->value = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SInt_value_get(lua_State* L) {
  int SWIG_arg = 0;
  struct _SInt *arg1 = (struct _SInt *) 0 ;
  int result;
  
  SWIG_check_num_args("_SInt::value",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SInt::value",1,"struct _SInt *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("SInt_value_get",1,SWIGTYPE_p__SInt);
  }
  
  result = (int) ((arg1)->value);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SInt(lua_State* L) {
  int SWIG_arg = 0;
  struct _SInt *result = 0 ;
  
  SWIG_check_num_args("_SInt::_SInt",0,0)
  result = (struct _SInt *)calloc(1, sizeof(struct _SInt));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__SInt,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SInt(void *obj) {
struct _SInt *arg1 = (struct _SInt *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SInt(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SInt);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SInt_attributes[] = {
    { "value", _wrap_SInt_value_get, _wrap_SInt_value_set },
    {0,0,0}
};
static swig_lua_method swig_SInt_methods[]= {
    {0,0}
};
static swig_lua_method swig_SInt_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SInt_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SInt_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SInt_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SInt_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SInt_Sf_SwigStatic = {
    "SInt",
    swig_SInt_Sf_SwigStatic_methods,
    swig_SInt_Sf_SwigStatic_attributes,
    swig_SInt_Sf_SwigStatic_constants,
    swig_SInt_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SInt_bases[] = {0};
static const char *swig_SInt_base_names[] = {0};
static swig_lua_class _wrap_class_SInt = { "SInt", "SInt", &SWIGTYPE_p__SInt,_proxy__wrap_new_SInt, swig_delete_SInt, swig_SInt_methods, swig_SInt_attributes, &swig_SInt_Sf_SwigStatic, swig_SInt_meta, swig_SInt_bases, swig_SInt_base_names };

static int _wrap_SFloat_value_set(lua_State* L) {
  int SWIG_arg = 0;
  struct _SFloat *arg1 = (struct _SFloat *) 0 ;
  float arg2 ;
  
  SWIG_check_num_args("_SFloat::value",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SFloat::value",1,"struct _SFloat *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("_SFloat::value",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SFloat,0))){
    SWIG_fail_ptr("SFloat_value_set",1,SWIGTYPE_p__SFloat);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  if (arg1) (arg1)->value = arg2;
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_SFloat_value_get(lua_State* L) {
  int SWIG_arg = 0;
  struct _SFloat *arg1 = (struct _SFloat *) 0 ;
  float result;
  
  SWIG_check_num_args("_SFloat::value",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("_SFloat::value",1,"struct _SFloat *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SFloat,0))){
    SWIG_fail_ptr("SFloat_value_get",1,SWIGTYPE_p__SFloat);
  }
  
  result = (float) ((arg1)->value);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_new_SFloat(lua_State* L) {
  int SWIG_arg = 0;
  struct _SFloat *result = 0 ;
  
  SWIG_check_num_args("_SFloat::_SFloat",0,0)
  result = (struct _SFloat *)calloc(1, sizeof(struct _SFloat));
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__SFloat,1); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static void swig_delete_SFloat(void *obj) {
struct _SFloat *arg1 = (struct _SFloat *) obj;
free((char *) arg1);
}
static int _proxy__wrap_new_SFloat(lua_State *L) {
    assert(lua_istable(L,1));
    lua_pushcfunction(L,_wrap_new_SFloat);
    assert(!lua_isnil(L,-1));
    lua_replace(L,1); /* replace our table with real constructor */
    lua_call(L,lua_gettop(L)-1,1);
    return 1;
}
static swig_lua_attribute swig_SFloat_attributes[] = {
    { "value", _wrap_SFloat_value_get, _wrap_SFloat_value_set },
    {0,0,0}
};
static swig_lua_method swig_SFloat_methods[]= {
    {0,0}
};
static swig_lua_method swig_SFloat_meta[] = {
    {0,0}
};

static swig_lua_attribute swig_SFloat_Sf_SwigStatic_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SFloat_Sf_SwigStatic_constants[]= {
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SFloat_Sf_SwigStatic_methods[]= {
    {0,0}
};
static swig_lua_class* swig_SFloat_Sf_SwigStatic_classes[]= {
    0
};

static swig_lua_namespace swig_SFloat_Sf_SwigStatic = {
    "SFloat",
    swig_SFloat_Sf_SwigStatic_methods,
    swig_SFloat_Sf_SwigStatic_attributes,
    swig_SFloat_Sf_SwigStatic_constants,
    swig_SFloat_Sf_SwigStatic_classes,
    0
};
static swig_lua_class *swig_SFloat_bases[] = {0};
static const char *swig_SFloat_base_names[] = {0};
static swig_lua_class _wrap_class_SFloat = { "SFloat", "SFloat", &SWIGTYPE_p__SFloat,_proxy__wrap_new_SFloat, swig_delete_SFloat, swig_SFloat_methods, swig_SFloat_attributes, &swig_SFloat_Sf_SwigStatic, swig_SFloat_meta, swig_SFloat_bases, swig_SFloat_base_names };

static int _wrap_sfCreateSFloat(lua_State* L) {
  int SWIG_arg = 0;
  SFloat *result = 0 ;
  
  SWIG_check_num_args("sfCreateSFloat",0,0)
  result = (SFloat *)sfCreateSFloat();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__SFloat,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSInt(lua_State* L) {
  int SWIG_arg = 0;
  SInt *result = 0 ;
  
  SWIG_check_num_args("sfCreateSInt",0,0)
  result = (SInt *)sfCreateSInt();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__SInt,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSFContext(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *result = 0 ;
  
  SWIG_check_num_args("sfCreateSFContext",0,0)
  result = (SFContext *)sfCreateSFContext();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFContext,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSDisplay(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *result = 0 ;
  
  SWIG_check_num_args("sfCreateSDisplay",0,0)
  result = (SDisplay *)sfCreateSDisplay();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SDisplay,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSSimulate(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *result = 0 ;
  
  SWIG_check_num_args("sfCreateSSimulate",0,0)
  result = (SSimulate *)sfCreateSSimulate();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SSimulate,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSUsb(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *result = 0 ;
  
  SWIG_check_num_args("sfCreateSUsb",0,0)
  result = (SUsb *)sfCreateSUsb();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SUsb,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSHardware(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *result = 0 ;
  
  SWIG_check_num_args("sfCreateSHardware",0,0)
  result = (SHardware *)sfCreateSHardware();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SHardware,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSFx3(lua_State* L) {
  int SWIG_arg = 0;
  SFx3 *result = 0 ;
  
  SWIG_check_num_args("sfCreateSFx3",0,0)
  result = (SFx3 *)sfCreateSFx3();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFx3,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSFpga(lua_State* L) {
  int SWIG_arg = 0;
  SFpga *result = 0 ;
  
  SWIG_check_num_args("sfCreateSFpga",0,0)
  result = (SFpga *)sfCreateSFpga();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFpga,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSGenerator(lua_State* L) {
  int SWIG_arg = 0;
  SGenerator *result = 0 ;
  
  SWIG_check_num_args("sfCreateSGenerator",0,0)
  result = (SGenerator *)sfCreateSGenerator();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SGenerator,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSEeprom(lua_State* L) {
  int SWIG_arg = 0;
  SEeprom *result = 0 ;
  
  SWIG_check_num_args("sfCreateSEeprom",0,0)
  result = (SEeprom *)sfCreateSEeprom();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SEeprom,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSFrameData(lua_State* L) {
  int SWIG_arg = 0;
  SFrameData *result = 0 ;
  
  SWIG_check_num_args("sfCreateSFrameData",0,0)
  result = (SFrameData *)sfCreateSFrameData();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFrameData,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfCreateSFrameHeader(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *result = 0 ;
  
  SWIG_check_num_args("sfCreateSFrameHeader",0,0)
  result = (SFrameHeader *)sfCreateSFrameHeader();
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_SFrameHeader,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSFloat(lua_State* L) {
  int SWIG_arg = 0;
  SFloat *arg1 = (SFloat *) 0 ;
  
  SWIG_check_num_args("sfDeleteSFloat",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSFloat",1,"SFloat *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SFloat,0))){
    SWIG_fail_ptr("sfDeleteSFloat",1,SWIGTYPE_p__SFloat);
  }
  
  sfDeleteSFloat(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSInt(lua_State* L) {
  int SWIG_arg = 0;
  SInt *arg1 = (SInt *) 0 ;
  
  SWIG_check_num_args("sfDeleteSInt",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSInt",1,"SInt *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfDeleteSInt",1,SWIGTYPE_p__SInt);
  }
  
  sfDeleteSInt(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSFContext(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  
  SWIG_check_num_args("sfDeleteSFContext",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSFContext",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfDeleteSFContext",1,SWIGTYPE_p_SFContext);
  }
  
  sfDeleteSFContext(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSDisplay(lua_State* L) {
  int SWIG_arg = 0;
  SDisplay *arg1 = (SDisplay *) 0 ;
  
  SWIG_check_num_args("sfDeleteSDisplay",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSDisplay",1,"SDisplay *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("sfDeleteSDisplay",1,SWIGTYPE_p_SDisplay);
  }
  
  sfDeleteSDisplay(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSSimulate(lua_State* L) {
  int SWIG_arg = 0;
  SSimulate *arg1 = (SSimulate *) 0 ;
  
  SWIG_check_num_args("sfDeleteSSimulate",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSSimulate",1,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("sfDeleteSSimulate",1,SWIGTYPE_p_SSimulate);
  }
  
  sfDeleteSSimulate(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSUsb(lua_State* L) {
  int SWIG_arg = 0;
  SUsb *arg1 = (SUsb *) 0 ;
  
  SWIG_check_num_args("sfDeleteSUsb",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSUsb",1,"SUsb *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("sfDeleteSUsb",1,SWIGTYPE_p_SUsb);
  }
  
  sfDeleteSUsb(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSHardware(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  
  SWIG_check_num_args("sfDeleteSHardware",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSHardware",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfDeleteSHardware",1,SWIGTYPE_p_SHardware);
  }
  
  sfDeleteSHardware(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSFrameData(lua_State* L) {
  int SWIG_arg = 0;
  SFrameData *arg1 = (SFrameData *) 0 ;
  
  SWIG_check_num_args("sfDeleteSFrameData",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSFrameData",1,"SFrameData *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameData,0))){
    SWIG_fail_ptr("sfDeleteSFrameData",1,SWIGTYPE_p_SFrameData);
  }
  
  sfDeleteSFrameData(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSFx3(lua_State* L) {
  int SWIG_arg = 0;
  SFx3 *arg1 = (SFx3 *) 0 ;
  
  SWIG_check_num_args("sfDeleteSFx3",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSFx3",1,"SFx3 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFx3,0))){
    SWIG_fail_ptr("sfDeleteSFx3",1,SWIGTYPE_p_SFx3);
  }
  
  sfDeleteSFx3(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSFpga(lua_State* L) {
  int SWIG_arg = 0;
  SFpga *arg1 = (SFpga *) 0 ;
  
  SWIG_check_num_args("sfDeleteSFpga",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSFpga",1,"SFpga *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFpga,0))){
    SWIG_fail_ptr("sfDeleteSFpga",1,SWIGTYPE_p_SFpga);
  }
  
  sfDeleteSFpga(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSGenerator(lua_State* L) {
  int SWIG_arg = 0;
  SGenerator *arg1 = (SGenerator *) 0 ;
  
  SWIG_check_num_args("sfDeleteSGenerator",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSGenerator",1,"SGenerator *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SGenerator,0))){
    SWIG_fail_ptr("sfDeleteSGenerator",1,SWIGTYPE_p_SGenerator);
  }
  
  sfDeleteSGenerator(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSEeprom(lua_State* L) {
  int SWIG_arg = 0;
  SEeprom *arg1 = (SEeprom *) 0 ;
  
  SWIG_check_num_args("sfDeleteSEeprom",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSEeprom",1,"SEeprom *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SEeprom,0))){
    SWIG_fail_ptr("sfDeleteSEeprom",1,SWIGTYPE_p_SEeprom);
  }
  
  sfDeleteSEeprom(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfDeleteSFrameHeader(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  
  SWIG_check_num_args("sfDeleteSFrameHeader",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfDeleteSFrameHeader",1,"SFrameHeader *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("sfDeleteSFrameHeader",1,SWIGTYPE_p_SFrameHeader);
  }
  
  sfDeleteSFrameHeader(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfApiInit(lua_State* L) {
  int SWIG_arg = 0;
  int result;
  
  SWIG_check_num_args("sfApiInit",0,0)
  result = (int)sfApiInit();
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfApiCreateContext(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfApiCreateContext",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfApiCreateContext",1,"SFContext *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfApiCreateContext",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfApiCreateContext",1,SWIGTYPE_p_SFContext);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfApiCreateContext(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfApiDeleteContext(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int result;
  
  SWIG_check_num_args("sfApiDeleteContext",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfApiDeleteContext",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfApiDeleteContext",1,SWIGTYPE_p_SFContext);
  }
  
  result = (int)sfApiDeleteContext(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfApiVersion(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SInt *arg2 = (SInt *) 0 ;
  SInt *arg3 = (SInt *) 0 ;
  SInt *arg4 = (SInt *) 0 ;
  int result;
  
  SWIG_check_num_args("sfApiVersion",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfApiVersion",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfApiVersion",2,"SInt *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("sfApiVersion",3,"SInt *");
  if(!SWIG_isptrtype(L,4)) SWIG_fail_arg("sfApiVersion",4,"SInt *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfApiVersion",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfApiVersion",2,SWIGTYPE_p__SInt);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfApiVersion",3,SWIGTYPE_p__SInt);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,4,(void**)&arg4,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfApiVersion",4,SWIGTYPE_p__SInt);
  }
  
  result = (int)sfApiVersion(arg1,arg2,arg3,arg4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetThreadSafe(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetThreadSafe",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetThreadSafe",1,"SFContext *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetThreadSafe",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfSetThreadSafe",1,SWIGTYPE_p_SFContext);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetThreadSafe(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfIsThreadSafe(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int result;
  
  SWIG_check_num_args("sfIsThreadSafe",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfIsThreadSafe",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfIsThreadSafe",1,SWIGTYPE_p_SFContext);
  }
  
  result = (int)sfIsThreadSafe(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetActive(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetActive",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetActive",1,"SFContext *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetActive",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfSetActive",1,SWIGTYPE_p_SFContext);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetActive(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfIsActive(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int result;
  
  SWIG_check_num_args("sfIsActive",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfIsActive",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfIsActive",1,SWIGTYPE_p_SFContext);
  }
  
  result = (int)sfIsActive(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetTimeOut(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetTimeOut",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetTimeOut",1,"SFContext *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetTimeOut",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfSetTimeOut",1,SWIGTYPE_p_SFContext);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetTimeOut(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetTimeOut(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SInt *arg2 = (SInt *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetTimeOut",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetTimeOut",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfGetTimeOut",2,"SInt *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfGetTimeOut",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfGetTimeOut",2,SWIGTYPE_p__SInt);
  }
  
  result = (int)sfGetTimeOut(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfApiExit(lua_State* L) {
  int SWIG_arg = 0;
  int result;
  
  SWIG_check_num_args("sfApiExit",0,0)
  result = (int)sfApiExit();
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareOpen(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SUsb *arg2 = (SUsb *) 0 ;
  int arg3 ;
  int result;
  
  SWIG_check_num_args("sfHardwareOpen",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareOpen",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareOpen",2,"SUsb *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfHardwareOpen",3,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareOpen",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SUsb,0))){
    SWIG_fail_ptr("sfHardwareOpen",2,SWIGTYPE_p_SUsb);
  }
  
  arg3 = (int)lua_tonumber(L, 3);
  result = (int)sfHardwareOpen(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareReset(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareReset",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareReset",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareReset",1,SWIGTYPE_p_SFContext);
  }
  
  result = (int)sfHardwareReset(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareIsOpened(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SInt *arg2 = (SInt *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareIsOpened",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareIsOpened",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareIsOpened",2,"SInt *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareIsOpened",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfHardwareIsOpened",2,SWIGTYPE_p__SInt);
  }
  
  result = (int)sfHardwareIsOpened(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareConfig(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SHardware *arg2 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareConfig",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareConfig",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareConfig",2,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareConfig",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfHardwareConfig",2,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfHardwareConfig(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareCapture(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SFrameData *arg2 = (SFrameData *) 0 ;
  int arg3 ;
  int arg4 ;
  SInt *arg5 = (SInt *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareCapture",5,5)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareCapture",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareCapture",2,"SFrameData *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfHardwareCapture",3,"int");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("sfHardwareCapture",4,"int");
  if(!SWIG_isptrtype(L,5)) SWIG_fail_arg("sfHardwareCapture",5,"SInt *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareCapture",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SFrameData,0))){
    SWIG_fail_ptr("sfHardwareCapture",2,SWIGTYPE_p_SFrameData);
  }
  
  arg3 = (int)lua_tonumber(L, 3);
  arg4 = (int)lua_tonumber(L, 4);
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,5,(void**)&arg5,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfHardwareCapture",5,SWIGTYPE_p__SInt);
  }
  
  result = (int)sfHardwareCapture(arg1,arg2,arg3,arg4,arg5);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareUploadFx3(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SFx3 *arg2 = (SFx3 *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareUploadFx3",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareUploadFx3",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareUploadFx3",2,"SFx3 *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareUploadFx3",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SFx3,0))){
    SWIG_fail_ptr("sfHardwareUploadFx3",2,SWIGTYPE_p_SFx3);
  }
  
  result = (int)sfHardwareUploadFx3(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareUploadFpga(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SFpga *arg2 = (SFpga *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareUploadFpga",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareUploadFpga",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareUploadFpga",2,"SFpga *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareUploadFpga",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SFpga,0))){
    SWIG_fail_ptr("sfHardwareUploadFpga",2,SWIGTYPE_p_SFpga);
  }
  
  result = (int)sfHardwareUploadFpga(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareUploadGenerator(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SGenerator *arg2 = (SGenerator *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareUploadGenerator",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareUploadGenerator",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareUploadGenerator",2,"SGenerator *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareUploadGenerator",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SGenerator,0))){
    SWIG_fail_ptr("sfHardwareUploadGenerator",2,SWIGTYPE_p_SGenerator);
  }
  
  result = (int)sfHardwareUploadGenerator(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareEepromRead(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SEeprom *arg2 = (SEeprom *) 0 ;
  int arg3 ;
  int arg4 ;
  int result;
  
  SWIG_check_num_args("sfHardwareEepromRead",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareEepromRead",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareEepromRead",2,"SEeprom *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfHardwareEepromRead",3,"int");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("sfHardwareEepromRead",4,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareEepromRead",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SEeprom,0))){
    SWIG_fail_ptr("sfHardwareEepromRead",2,SWIGTYPE_p_SEeprom);
  }
  
  arg3 = (int)lua_tonumber(L, 3);
  arg4 = (int)lua_tonumber(L, 4);
  result = (int)sfHardwareEepromRead(arg1,arg2,arg3,arg4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareEepromReadFirmwareID(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SEeprom *arg2 = (SEeprom *) 0 ;
  int arg3 ;
  int arg4 ;
  int result;
  
  SWIG_check_num_args("sfHardwareEepromReadFirmwareID",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareEepromReadFirmwareID",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareEepromReadFirmwareID",2,"SEeprom *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfHardwareEepromReadFirmwareID",3,"int");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("sfHardwareEepromReadFirmwareID",4,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareEepromReadFirmwareID",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SEeprom,0))){
    SWIG_fail_ptr("sfHardwareEepromReadFirmwareID",2,SWIGTYPE_p_SEeprom);
  }
  
  arg3 = (int)lua_tonumber(L, 3);
  arg4 = (int)lua_tonumber(L, 4);
  result = (int)sfHardwareEepromReadFirmwareID(arg1,arg2,arg3,arg4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareReadFpgaStatus(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SInt *arg2 = (SInt *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareReadFpgaStatus",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareReadFpgaStatus",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareReadFpgaStatus",2,"SInt *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareReadFpgaStatus",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfHardwareReadFpgaStatus",2,SWIGTYPE_p__SInt);
  }
  
  result = (int)sfHardwareReadFpgaStatus(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareEepromWrite(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SEeprom *arg2 = (SEeprom *) 0 ;
  int arg3 ;
  int arg4 ;
  int result;
  
  SWIG_check_num_args("sfHardwareEepromWrite",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareEepromWrite",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareEepromWrite",2,"SEeprom *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfHardwareEepromWrite",3,"int");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("sfHardwareEepromWrite",4,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareEepromWrite",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SEeprom,0))){
    SWIG_fail_ptr("sfHardwareEepromWrite",2,SWIGTYPE_p_SEeprom);
  }
  
  arg3 = (int)lua_tonumber(L, 3);
  arg4 = (int)lua_tonumber(L, 4);
  result = (int)sfHardwareEepromWrite(arg1,arg2,arg3,arg4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareEepromErase(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareEepromErase",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareEepromErase",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareEepromErase",1,SWIGTYPE_p_SFContext);
  }
  
  result = (int)sfHardwareEepromErase(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareClose(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareClose",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfHardwareClose",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfHardwareClose",1,SWIGTYPE_p_SFContext);
  }
  
  result = (int)sfHardwareClose(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfFrameCapture(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SInt *arg2 = (SInt *) 0 ;
  SInt *arg3 = (SInt *) 0 ;
  int result;
  
  SWIG_check_num_args("sfFrameCapture",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfFrameCapture",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfFrameCapture",2,"SInt *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("sfFrameCapture",3,"SInt *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfFrameCapture",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfFrameCapture",2,SWIGTYPE_p__SInt);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfFrameCapture",3,SWIGTYPE_p__SInt);
  }
  
  result = (int)sfFrameCapture(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfFrameOutput(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SFrameData *arg2 = (SFrameData *) 0 ;
  int arg3 ;
  int result;
  
  SWIG_check_num_args("sfFrameOutput",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfFrameOutput",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfFrameOutput",2,"SFrameData *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfFrameOutput",3,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfFrameOutput",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SFrameData,0))){
    SWIG_fail_ptr("sfFrameOutput",2,SWIGTYPE_p_SFrameData);
  }
  
  arg3 = (int)lua_tonumber(L, 3);
  result = (int)sfFrameOutput(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfFrameDisplay(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SFrameData *arg2 = (SFrameData *) 0 ;
  int arg3 ;
  SDisplay *arg4 = (SDisplay *) 0 ;
  float arg5 ;
  float arg6 ;
  int result;
  
  SWIG_check_num_args("sfFrameDisplay",6,6)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfFrameDisplay",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfFrameDisplay",2,"SFrameData *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfFrameDisplay",3,"int");
  if(!SWIG_isptrtype(L,4)) SWIG_fail_arg("sfFrameDisplay",4,"SDisplay *");
  if(!lua_isnumber(L,5)) SWIG_fail_arg("sfFrameDisplay",5,"float");
  if(!lua_isnumber(L,6)) SWIG_fail_arg("sfFrameDisplay",6,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfFrameDisplay",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SFrameData,0))){
    SWIG_fail_ptr("sfFrameDisplay",2,SWIGTYPE_p_SFrameData);
  }
  
  arg3 = (int)lua_tonumber(L, 3);
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,4,(void**)&arg4,SWIGTYPE_p_SDisplay,0))){
    SWIG_fail_ptr("sfFrameDisplay",4,SWIGTYPE_p_SDisplay);
  }
  
  arg5 = (float)lua_tonumber(L, 5);
  arg6 = (float)lua_tonumber(L, 6);
  result = (int)sfFrameDisplay(arg1,arg2,arg3,arg4,arg5,arg6);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfFrameDisplayFunction(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  EFunctionType arg2 ;
  int result;
  
  SWIG_check_num_args("sfFrameDisplayFunction",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfFrameDisplayFunction",1,"SFContext *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfFrameDisplayFunction",2,"EFunctionType");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfFrameDisplayFunction",1,SWIGTYPE_p_SFContext);
  }
  
  arg2 = (EFunctionType)(int)lua_tonumber(L, 2);
  result = (int)sfFrameDisplayFunction(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfFrameDisplayCallback(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SCallback *arg2 = (SCallback *) 0 ;
  void *arg3 = (void *) 0 ;
  int result;
  
  SWIG_check_num_args("sfFrameDisplayCallback",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfFrameDisplayCallback",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfFrameDisplayCallback",2,"SCallback *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("sfFrameDisplayCallback",3,"void *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfFrameDisplayCallback",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__SCallback,0))){
    SWIG_fail_ptr("sfFrameDisplayCallback",2,SWIGTYPE_p__SCallback);
  }
  
  arg3=(void *)SWIG_MustGetPtr(L,3,0,0,3,"sfFrameDisplayCallback");
  result = (int)sfFrameDisplayCallback(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetHeader(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SFrameData *arg2 = (SFrameData *) 0 ;
  SFrameHeader *arg3 = (SFrameHeader *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetHeader",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetHeader",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfGetHeader",2,"SFrameData *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("sfGetHeader",3,"SFrameHeader *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfGetHeader",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SFrameData,0))){
    SWIG_fail_ptr("sfGetHeader",2,SWIGTYPE_p_SFrameData);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("sfGetHeader",3,SWIGTYPE_p_SFrameHeader);
  }
  
  result = (int)sfGetHeader(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetHeaderHardware(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SFrameHeader *arg2 = (SFrameHeader *) 0 ;
  SHardware *arg3 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetHeaderHardware",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetHeaderHardware",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfGetHeaderHardware",2,"SFrameHeader *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("sfGetHeaderHardware",3,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfGetHeaderHardware",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("sfGetHeaderHardware",2,SWIGTYPE_p_SFrameHeader);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetHeaderHardware",3,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetHeaderHardware(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetHeaderEts(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  uint *arg2 = (uint *) 0 ;
  uint temp2 ;
  int result;
  
  arg2 = &temp2; 
  SWIG_check_num_args("sfGetHeaderEts",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetHeaderEts",1,"SFrameHeader *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("sfGetHeaderEts",1,SWIGTYPE_p_SFrameHeader);
  }
  
  result = (int)sfGetHeaderEts(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  lua_pushnumber(L, (lua_Number) *arg2); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetHeaderTemperature(lua_State* L) {
  int SWIG_arg = 0;
  SFrameHeader *arg1 = (SFrameHeader *) 0 ;
  SFloat *arg2 = (SFloat *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetHeaderTemperature",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetHeaderTemperature",1,"SFrameHeader *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfGetHeaderTemperature",2,"SFloat *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFrameHeader,0))){
    SWIG_fail_ptr("sfGetHeaderTemperature",1,SWIGTYPE_p_SFrameHeader);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__SFloat,0))){
    SWIG_fail_ptr("sfGetHeaderTemperature",2,SWIGTYPE_p__SFloat);
  }
  
  result = (int)sfGetHeaderTemperature(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareWordCnt(lua_State* L) {
  int SWIG_arg = 0;
  int *arg1 = (int *) 0 ;
  int temp1 ;
  int result;
  
  SWIG_check_num_args("sfHardwareWordCnt",1,1)
  if(!lua_isnumber(L,1)) SWIG_fail_arg("sfHardwareWordCnt",1,"int *");
  temp1 = (int)lua_tonumber(L,1);
  arg1 = &temp1; 
  result = (int)sfHardwareWordCnt(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  lua_pushnumber(L, (lua_Number) *arg1); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfHardwareWordId(lua_State* L) {
  int SWIG_arg = 0;
  int arg1 ;
  SArrayString256 *arg2 = (SArrayString256 *) 0 ;
  int result;
  
  SWIG_check_num_args("sfHardwareWordId",2,2)
  if(!lua_isnumber(L,1)) SWIG_fail_arg("sfHardwareWordId",1,"int");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfHardwareWordId",2,"SArrayString256 *");
  arg1 = (int)lua_tonumber(L, 1);
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SArrayString256,0))){
    SWIG_fail_ptr("sfHardwareWordId",2,SWIGTYPE_p_SArrayString256);
  }
  
  result = (int)sfHardwareWordId(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetData(lua_State* L) {
  int SWIG_arg = 0;
  byte *arg1 = (byte *) 0 ;
  ishort arg2 ;
  ishort arg3 ;
  ushort arg4 ;
  byte temp1 ;
  int result;
  
  SWIG_check_num_args("sfSetData",4,4)
  if(!lua_isnumber(L,1)) SWIG_fail_arg("sfSetData",1,"byte *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetData",2,"ishort");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetData",3,"ishort");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("sfSetData",4,"ushort");
  temp1 = (byte)lua_tonumber(L,1);
  arg1 = &temp1; 
  arg2 = (ishort)lua_tonumber(L, 2);
  arg3 = (ishort)lua_tonumber(L, 3);
  SWIG_contract_assert((lua_tonumber(L,4)>=0),"number must not be negative")
  arg4 = (ushort)lua_tonumber(L, 4);
  result = (int)sfSetData(arg1,arg2,arg3,arg4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetData(lua_State* L) {
  int SWIG_arg = 0;
  uint arg1 ;
  ishort *arg2 = (ishort *) 0 ;
  ishort *arg3 = (ishort *) 0 ;
  ushort *arg4 = (ushort *) 0 ;
  ishort temp2 ;
  ishort temp3 ;
  ushort temp4 ;
  int result;
  
  SWIG_check_num_args("sfGetData",4,4)
  if(!lua_isnumber(L,1)) SWIG_fail_arg("sfGetData",1,"uint");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfGetData",2,"ishort *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfGetData",3,"ishort *");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("sfGetData",4,"ushort *");
  SWIG_contract_assert((lua_tonumber(L,1)>=0),"number must not be negative")
  arg1 = (uint)lua_tonumber(L, 1);
  temp2 = (ishort)lua_tonumber(L,2);
  arg2 = &temp2; 
  temp3 = (ishort)lua_tonumber(L,3);
  arg3 = &temp3; 
  temp4 = (ushort)lua_tonumber(L,4);
  arg4 = &temp4; 
  result = (int)sfGetData(arg1,arg2,arg3,arg4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  lua_pushnumber(L, (lua_Number) *arg2); SWIG_arg++;
  lua_pushnumber(L, (lua_Number) *arg3); SWIG_arg++;
  lua_pushnumber(L, (lua_Number) *arg4); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfIsSimulate(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int result;
  
  SWIG_check_num_args("sfIsSimulate",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfIsSimulate",1,"SFContext *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfIsSimulate",1,SWIGTYPE_p_SFContext);
  }
  
  result = (int)sfIsSimulate(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetSimulateData(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SSimulate *arg2 = (SSimulate *) 0 ;
  int result;
  
  SWIG_check_num_args("sfSetSimulateData",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetSimulateData",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfSetSimulateData",2,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfSetSimulateData",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("sfSetSimulateData",2,SWIGTYPE_p_SSimulate);
  }
  
  result = (int)sfSetSimulateData(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetSimulateData(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SSimulate *arg2 = (SSimulate *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetSimulateData",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetSimulateData",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfGetSimulateData",2,"SSimulate *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfGetSimulateData",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SSimulate,0))){
    SWIG_fail_ptr("sfGetSimulateData",2,SWIGTYPE_p_SSimulate);
  }
  
  result = (int)sfGetSimulateData(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetSimulateOnOff(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetSimulateOnOff",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetSimulateOnOff",1,"SFContext *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetSimulateOnOff",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfSetSimulateOnOff",1,SWIGTYPE_p_SFContext);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetSimulateOnOff(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSimulate(lua_State* L) {
  int SWIG_arg = 0;
  SFContext *arg1 = (SFContext *) 0 ;
  SHardware *arg2 = (SHardware *) 0 ;
  SInt *arg3 = (SInt *) 0 ;
  SInt *arg4 = (SInt *) 0 ;
  float arg5 ;
  int result;
  
  SWIG_check_num_args("sfSimulate",5,5)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSimulate",1,"SFContext *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("sfSimulate",2,"SHardware *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("sfSimulate",3,"SInt *");
  if(!SWIG_isptrtype(L,4)) SWIG_fail_arg("sfSimulate",4,"SInt *");
  if(!lua_isnumber(L,5)) SWIG_fail_arg("sfSimulate",5,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SFContext,0))){
    SWIG_fail_ptr("sfSimulate",1,SWIGTYPE_p_SFContext);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSimulate",2,SWIGTYPE_p_SHardware);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfSimulate",3,SWIGTYPE_p__SInt);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,4,(void**)&arg4,SWIGTYPE_p__SInt,0))){
    SWIG_fail_ptr("sfSimulate",4,SWIGTYPE_p__SInt);
  }
  
  arg5 = (float)lua_tonumber(L, 5);
  result = (int)sfSimulate(arg1,arg2,arg3,arg4,arg5);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDefault(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfSetDefault",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDefault",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDefault",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfSetDefault(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetFrameSize(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetFrameSize",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetFrameSize",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetFrameSize",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetFrameSize",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  result = (int)sfSetFrameSize(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetNumSamples(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetNumSamples",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetNumSamples",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetNumSamples",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetNumSamples",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  result = (int)sfSetNumSamples(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetAnalogSwitchBit(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int arg3 ;
  int result;
  
  SWIG_check_num_args("sfSetAnalogSwitchBit",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetAnalogSwitchBit",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetAnalogSwitchBit",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetAnalogSwitchBit",3,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetAnalogSwitchBit",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  arg3 = (int)lua_tonumber(L, 3);
  result = (int)sfSetAnalogSwitchBit(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetEts(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetEts",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetEts",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetEts",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetEts",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetEts(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetYRangeScaleA(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  ushort arg3 ;
  int result;
  
  SWIG_check_num_args("sfSetYRangeScaleA",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetYRangeScaleA",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetYRangeScaleA",2,"ushort");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetYRangeScaleA",3,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetYRangeScaleA",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (ushort)lua_tonumber(L, 3);
  result = (int)sfSetYRangeScaleA(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetYPositionA(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetYPositionA",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetYPositionA",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetYPositionA",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetYPositionA",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetYPositionA(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetYRangeScaleB(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  ushort arg3 ;
  int result;
  
  SWIG_check_num_args("sfSetYRangeScaleB",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetYRangeScaleB",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetYRangeScaleB",2,"ushort");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetYRangeScaleB",3,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetYRangeScaleB",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (ushort)lua_tonumber(L, 3);
  result = (int)sfSetYRangeScaleB(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetYPositionB(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetYPositionB",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetYPositionB",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetYPositionB",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetYPositionB",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetYPositionB(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetXRange(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ishort arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetXRange",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetXRange",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetXRange",2,"ishort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetXRange",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (ishort)lua_tonumber(L, 2);
  result = (int)sfSetXRange(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetControl(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetControl",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetControl",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetControl",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetControl",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  result = (int)sfSetControl(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetSampleSize(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetSampleSize",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetSampleSize",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetSampleSize",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetSampleSize",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  result = (int)sfSetSampleSize(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetTriggerSource(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetTriggerSource",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetTriggerSource",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetTriggerSource",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetTriggerSource",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetTriggerSource(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetTriggerReArm(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetTriggerReArm",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetTriggerReArm",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetTriggerReArm",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetTriggerReArm",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetTriggerReArm(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetTriggerMode(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetTriggerMode",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetTriggerMode",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetTriggerMode",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetTriggerMode",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetTriggerMode(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetTriggerSlope(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetTriggerSlope",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetTriggerSlope",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetTriggerSlope",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetTriggerSlope",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetTriggerSlope(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetTriggerPre(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetTriggerPre",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetTriggerPre",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetTriggerPre",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetTriggerPre",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  result = (int)sfSetTriggerPre(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetTriggerHis(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetTriggerHis",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetTriggerHis",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetTriggerHis",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetTriggerHis",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetTriggerHis(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetTriggerLevel(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetTriggerLevel",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetTriggerLevel",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetTriggerLevel",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetTriggerLevel",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetTriggerLevel(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetHoldoff(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetHoldoff",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetHoldoff",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetHoldoff",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetHoldoff",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  result = (int)sfSetHoldoff(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorType0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorType0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorType0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorType0",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorType0",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorType0(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorOn0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorOn0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorOn0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorOn0",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorOn0",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorOn0(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorSlope0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorSlope0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorSlope0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorSlope0",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorSlope0",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorSlope0(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorVoltage0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorVoltage0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorVoltage0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorVoltage0",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorVoltage0",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorVoltage0(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorOffset0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorOffset0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorOffset0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorOffset0",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorOffset0",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorOffset0(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorFrequency0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float arg2 ;
  float arg3 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorFrequency0",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorFrequency0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorFrequency0",2,"float");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetGeneratorFrequency0",3,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorFrequency0",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  arg3 = (float)lua_tonumber(L, 3);
  result = (int)sfSetGeneratorFrequency0(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorSquareDuty0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorSquareDuty0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorSquareDuty0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorSquareDuty0",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorSquareDuty0",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorSquareDuty0(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorType1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorType1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorType1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorType1",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorType1",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorType1(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorOn1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorOn1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorOn1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorOn1",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorOn1",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorOn1(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorSlope1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorSlope1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorSlope1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorSlope1",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorSlope1",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorSlope1(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorVoltage1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorVoltage1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorVoltage1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorVoltage1",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorVoltage1",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorVoltage1(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorOffset1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorOffset1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorOffset1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorOffset1",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorOffset1",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorOffset1(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorFrequency1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float arg2 ;
  float arg3 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorFrequency1",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorFrequency1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorFrequency1",2,"float");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetGeneratorFrequency1",3,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorFrequency1",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  arg3 = (float)lua_tonumber(L, 3);
  result = (int)sfSetGeneratorFrequency1(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetGeneratorSquareDuty1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetGeneratorSquareDuty1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetGeneratorSquareDuty1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetGeneratorSquareDuty1",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetGeneratorSquareDuty1",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  result = (int)sfSetGeneratorSquareDuty1(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalVoltage(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  double arg2 ;
  double arg3 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalVoltage",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalVoltage",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalVoltage",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetDigitalVoltage",3,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalVoltage",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  result = (int)sfSetDigitalVoltage(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalInputOutput(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int arg3 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalInputOutput",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalInputOutput",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalInputOutput",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetDigitalInputOutput",3,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalInputOutput",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  arg3 = (int)lua_tonumber(L, 3);
  result = (int)sfSetDigitalInputOutput(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalOutputBit(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int arg3 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalOutputBit",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalOutputBit",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalOutputBit",2,"int");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetDigitalOutputBit",3,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalOutputBit",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  arg3 = (int)lua_tonumber(L, 3);
  result = (int)sfSetDigitalOutputBit(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalClockDivide(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalClockDivide",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalClockDivide",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalClockDivide",2,"uint");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalClockDivide",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  result = (int)sfSetDigitalClockDivide(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetAverage(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetAverage",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetAverage",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetAverage",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetAverage",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetAverage(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalStart(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalStart",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalStart",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalStart",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalStart",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetDigitalStart(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalMode(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalMode",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalMode",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalMode",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalMode",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetDigitalMode(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalChannel(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalChannel",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalChannel",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalChannel",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalChannel",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfSetDigitalChannel(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalDelay(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  ushort arg3 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalDelay",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalDelay",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalDelay",2,"uint");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetDigitalDelay",3,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalDelay",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (ushort)lua_tonumber(L, 3);
  result = (int)sfSetDigitalDelay(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalMask(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint arg2 ;
  uint arg3 ;
  int arg4 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalMask",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalMask",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalMask",2,"uint");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetDigitalMask",3,"uint");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("sfSetDigitalMask",4,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalMask",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (uint)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (uint)lua_tonumber(L, 3);
  arg4 = (int)lua_tonumber(L, 4);
  result = (int)sfSetDigitalMask(arg1,arg2,arg3,arg4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfSetDigitalPattern(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  ushort arg3 ;
  ushort arg4 ;
  int result;
  
  SWIG_check_num_args("sfSetDigitalPattern",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfSetDigitalPattern",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfSetDigitalPattern",2,"ushort");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfSetDigitalPattern",3,"ushort");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("sfSetDigitalPattern",4,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfSetDigitalPattern",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (ushort)lua_tonumber(L, 3);
  SWIG_contract_assert((lua_tonumber(L,4)>=0),"number must not be negative")
  arg4 = (ushort)lua_tonumber(L, 4);
  result = (int)sfSetDigitalPattern(arg1,arg2,arg3,arg4);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetFrameSize(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("sfGetFrameSize",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetFrameSize",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetFrameSize",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint)sfGetFrameSize(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetNumSamples(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("sfGetNumSamples",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetNumSamples",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetNumSamples",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint)sfGetNumSamples(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetAnalogSwitch(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("sfGetAnalogSwitch",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetAnalogSwitch",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetAnalogSwitch",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort)sfGetAnalogSwitch(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetEts(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetEts",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetEts",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetEts",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetEts(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetControl(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("sfGetControl",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetControl",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetControl",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint)sfGetControl(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetYGainA(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("sfGetYGainA",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetYGainA",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetYGainA",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint)sfGetYGainA(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetYScaleA(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float result;
  
  SWIG_check_num_args("sfGetYScaleA",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetYScaleA",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetYScaleA",1,SWIGTYPE_p_SHardware);
  }
  
  result = (float)sfGetYScaleA(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetYPositionA(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetYPositionA",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetYPositionA",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetYPositionA",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetYPositionA(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetYGainB(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("sfGetYGainB",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetYGainB",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetYGainB",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint)sfGetYGainB(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetYScaleB(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float result;
  
  SWIG_check_num_args("sfGetYScaleB",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetYScaleB",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetYScaleB",1,SWIGTYPE_p_SHardware);
  }
  
  result = (float)sfGetYScaleB(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetYPositionB(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetYPositionB",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetYPositionB",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetYPositionB",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetYPositionB(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetTriggerSource(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("sfGetTriggerSource",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetTriggerSource",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetTriggerSource",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort)sfGetTriggerSource(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetTriggerMode(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("sfGetTriggerMode",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetTriggerMode",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetTriggerMode",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort)sfGetTriggerMode(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetTriggerSlope(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("sfGetTriggerSlope",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetTriggerSlope",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetTriggerSlope",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort)sfGetTriggerSlope(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetTriggerPre(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float result;
  
  SWIG_check_num_args("sfGetTriggerPre",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetTriggerPre",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetTriggerPre",1,SWIGTYPE_p_SHardware);
  }
  
  result = (float)sfGetTriggerPre(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetTriggerHis(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetTriggerHis",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetTriggerHis",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetTriggerHis",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetTriggerHis(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetTriggerLevel(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetTriggerLevel",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetTriggerLevel",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetTriggerLevel",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetTriggerLevel(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetXRange(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ishort result;
  
  SWIG_check_num_args("sfGetXRange",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetXRange",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetXRange",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ishort)sfGetXRange(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetSampleSize(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("sfGetSampleSize",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetSampleSize",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetSampleSize",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint)sfGetSampleSize(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetHoldoff(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("sfGetHoldoff",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetHoldoff",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetHoldoff",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint)sfGetHoldoff(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetAverage(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetAverage",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetAverage",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetAverage",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetAverage(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorType0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("sfGetGeneratorType0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorType0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorType0",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort)sfGetGeneratorType0(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorOn0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetGeneratorOn0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorOn0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorOn0",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetGeneratorOn0(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorSlope0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetGeneratorSlope0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorSlope0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorSlope0",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetGeneratorSlope0(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorVoltage0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetGeneratorVoltage0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorVoltage0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorVoltage0",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetGeneratorVoltage0(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorOffset0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetGeneratorOffset0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorOffset0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorOffset0",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetGeneratorOffset0(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorFrequency0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float arg2 ;
  float result;
  
  SWIG_check_num_args("sfGetGeneratorFrequency0",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorFrequency0",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfGetGeneratorFrequency0",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorFrequency0",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  result = (float)sfGetGeneratorFrequency0(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorSquareDuty0(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float result;
  
  SWIG_check_num_args("sfGetGeneratorSquareDuty0",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorSquareDuty0",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorSquareDuty0",1,SWIGTYPE_p_SHardware);
  }
  
  result = (float)sfGetGeneratorSquareDuty0(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorType1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort result;
  
  SWIG_check_num_args("sfGetGeneratorType1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorType1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorType1",1,SWIGTYPE_p_SHardware);
  }
  
  result = (ushort)sfGetGeneratorType1(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorOn1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetGeneratorOn1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorOn1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorOn1",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetGeneratorOn1(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorSlope1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetGeneratorSlope1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorSlope1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorSlope1",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetGeneratorSlope1(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorVoltage1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetGeneratorVoltage1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorVoltage1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorVoltage1",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetGeneratorVoltage1(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorOffset1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetGeneratorOffset1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorOffset1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorOffset1",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetGeneratorOffset1(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorFrequency1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float arg2 ;
  float result;
  
  SWIG_check_num_args("sfGetGeneratorFrequency1",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorFrequency1",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfGetGeneratorFrequency1",2,"float");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorFrequency1",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (float)lua_tonumber(L, 2);
  result = (float)sfGetGeneratorFrequency1(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetGeneratorSquareDuty1(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  float result;
  
  SWIG_check_num_args("sfGetGeneratorSquareDuty1",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetGeneratorSquareDuty1",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetGeneratorSquareDuty1",1,SWIGTYPE_p_SHardware);
  }
  
  result = (float)sfGetGeneratorSquareDuty1(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalStart(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetDigitalStart",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalStart",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalStart",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetDigitalStart(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalMode(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetDigitalMode",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalMode",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalMode",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetDigitalMode(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalChannel(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetDigitalChannel",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalChannel",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalChannel",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetDigitalChannel(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalDelay(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  ushort result;
  
  SWIG_check_num_args("sfGetDigitalDelay",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalDelay",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfGetDigitalDelay",2,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalDelay",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  result = (ushort)sfGetDigitalDelay(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalMask(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  ushort arg3 ;
  int result;
  
  SWIG_check_num_args("sfGetDigitalMask",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalMask",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfGetDigitalMask",2,"ushort");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfGetDigitalMask",3,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalMask",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (ushort)lua_tonumber(L, 3);
  result = (int)sfGetDigitalMask(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalPattern(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  ushort arg2 ;
  ushort arg3 ;
  ushort result;
  
  SWIG_check_num_args("sfGetDigitalPattern",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalPattern",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfGetDigitalPattern",2,"ushort");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("sfGetDigitalPattern",3,"ushort");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalPattern",1,SWIGTYPE_p_SHardware);
  }
  
  SWIG_contract_assert((lua_tonumber(L,2)>=0),"number must not be negative")
  arg2 = (ushort)lua_tonumber(L, 2);
  SWIG_contract_assert((lua_tonumber(L,3)>=0),"number must not be negative")
  arg3 = (ushort)lua_tonumber(L, 3);
  result = (ushort)sfGetDigitalPattern(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalVoltage(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  double arg2 ;
  double result;
  
  SWIG_check_num_args("sfGetDigitalVoltage",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalVoltage",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfGetDigitalVoltage",2,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalVoltage",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  result = (double)sfGetDigitalVoltage(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalInputOutput15(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetDigitalInputOutput15",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalInputOutput15",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalInputOutput15",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetDigitalInputOutput15(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalInputOutput7(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int result;
  
  SWIG_check_num_args("sfGetDigitalInputOutput7",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalInputOutput7",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalInputOutput7",1,SWIGTYPE_p_SHardware);
  }
  
  result = (int)sfGetDigitalInputOutput7(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalOutputBit(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  int arg2 ;
  int result;
  
  SWIG_check_num_args("sfGetDigitalOutputBit",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalOutputBit",1,"SHardware *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("sfGetDigitalOutputBit",2,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalOutputBit",1,SWIGTYPE_p_SHardware);
  }
  
  arg2 = (int)lua_tonumber(L, 2);
  result = (int)sfGetDigitalOutputBit(arg1,arg2);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static int _wrap_sfGetDigitalClockDivide(lua_State* L) {
  int SWIG_arg = 0;
  SHardware *arg1 = (SHardware *) 0 ;
  uint result;
  
  SWIG_check_num_args("sfGetDigitalClockDivide",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("sfGetDigitalClockDivide",1,"SHardware *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SHardware,0))){
    SWIG_fail_ptr("sfGetDigitalClockDivide",1,SWIGTYPE_p_SHardware);
  }
  
  result = (uint)sfGetDigitalClockDivide(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}


static swig_lua_attribute swig_SwigModule_attributes[] = {
    {0,0,0}
};
static swig_lua_const_info swig_SwigModule_constants[]= {
    {SWIG_LUA_CONSTTAB_INT("HARDWARE_VERSION", 2)},
    {SWIG_LUA_CONSTTAB_INT("ANALOG_FUNCTION_MEDIUM", ANALOG_FUNCTION_MEDIUM)},
    {SWIG_LUA_CONSTTAB_INT("ANALOG_FUNCTION_SUB_CH0_CH1", ANALOG_FUNCTION_SUB_CH0_CH1)},
    {SWIG_LUA_CONSTTAB_INT("ANALOG_FUNCTION_SUB_CH1_CH0", ANALOG_FUNCTION_SUB_CH1_CH0)},
    {SWIG_LUA_CONSTTAB_INT("ANALOG_FUNCTION_ADD", ANALOG_FUNCTION_ADD)},
    {SWIG_LUA_CONSTTAB_INT("ANALOG_FUNCTION_MIN", ANALOG_FUNCTION_MIN)},
    {SWIG_LUA_CONSTTAB_INT("ANALOG_FUNCTION_MAX", ANALOG_FUNCTION_MAX)},
    {SWIG_LUA_CONSTTAB_INT("ANALOG_FUNCTION_CUSTOM", ANALOG_FUNCTION_CUSTOM)},
    {SWIG_LUA_CONSTTAB_INT("ANALOG_FUNCTION_UPLOADED", ANALOG_FUNCTION_UPLOADED)},
    {SWIG_LUA_CONSTTAB_INT("CHANNEL_ATTR_B", CHANNEL_ATTR_B)},
    {SWIG_LUA_CONSTTAB_INT("CHANNEL_ATTR_A", CHANNEL_ATTR_A)},
    {SWIG_LUA_CONSTTAB_INT("CHANNEL_B_GROUND", CHANNEL_B_GROUND)},
    {SWIG_LUA_CONSTTAB_INT("CHANNEL_A_GROUND", CHANNEL_A_GROUND)},
    {SWIG_LUA_CONSTTAB_INT("CHANNEL_B_ACDC", CHANNEL_B_ACDC)},
    {SWIG_LUA_CONSTTAB_INT("CHANNEL_A_ACDC", CHANNEL_A_ACDC)},
    {SWIG_LUA_CONSTTAB_INT("CHANNEL_INTERLEAVE", CHANNEL_INTERLEAVE)},
    {SWIG_LUA_CONSTTAB_INT("CHANNEL_ETS", CHANNEL_ETS)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_CUSTOM", GENERATOR_CUSTOM)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_SIN", GENERATOR_SIN)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_COS", GENERATOR_COS)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_TRIANGLE", GENERATOR_TRIANGLE)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_RAMP_UP", GENERATOR_RAMP_UP)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_RAMP_DOWN", GENERATOR_RAMP_DOWN)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_SQUARE", GENERATOR_SQUARE)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_DELTA", GENERATOR_DELTA)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_DC", GENERATOR_DC)},
    {SWIG_LUA_CONSTTAB_INT("GENERATOR_NOISE", GENERATOR_NOISE)},
    {SWIG_LUA_CONSTTAB_INT("CONTROLL1_SHUTDOWN", CONTROLL1_SHUTDOWN)},
    {SWIG_LUA_CONSTTAB_INT("CONTROLL1_RESET", CONTROLL1_RESET)},
    {SWIG_LUA_CONSTTAB_INT("CONTROLL1_TEST", CONTROLL1_TEST)},
    {SWIG_LUA_CONSTTAB_INT("CONTROLL1_WAKEUP", CONTROLL1_WAKEUP)},
    {SWIG_LUA_CONSTTAB_INT("CONTROLL1_NORMAL", CONTROLL1_NORMAL)},
    {SWIG_LUA_CONSTTAB_INT("CONTROLL2_NORMAL", CONTROLL2_NORMAL)},
    {SWIG_LUA_CONSTTAB_INT("CONTROLL2_TEST", CONTROLL2_TEST)},
    {SWIG_LUA_CONSTTAB_INT("CONTROLL2_RESET", CONTROLL2_RESET)},
    {SWIG_LUA_CONSTTAB_INT("CALLIBRATE_1K", CALLIBRATE_1K)},
    {SWIG_LUA_CONSTTAB_INT("CALLIBRATE_5K", CALLIBRATE_5K)},
    {SWIG_LUA_CONSTTAB_INT("CALLIBRATE_10K", CALLIBRATE_10K)},
    {SWIG_LUA_CONSTTAB_INT("CALLIBRATE_100K", CALLIBRATE_100K)},
    {SWIG_LUA_CONSTTAB_INT("CALLIBRATE_200K", CALLIBRATE_200K)},
    {SWIG_LUA_CONSTTAB_INT("CALLIBRATE_500K", CALLIBRATE_500K)},
    {SWIG_LUA_CONSTTAB_INT("CALLIBRATE_1M", CALLIBRATE_1M)},
    {SWIG_LUA_CONSTTAB_INT("CALLIBRATE_2M", CALLIBRATE_2M)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_PATTERN_0", DIGITAL_PATTERN_0)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_PATTERN_1", DIGITAL_PATTERN_1)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_PATTERN_RISING", DIGITAL_PATTERN_RISING)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_PATTERN_FALLING", DIGITAL_PATTERN_FALLING)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_STAGE_0", DIGITAL_STAGE_0)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_STAGE_1", DIGITAL_STAGE_1)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_STAGE_2", DIGITAL_STAGE_2)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_STAGE_3", DIGITAL_STAGE_3)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_0", DIGITAL_BIT_0)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_1", DIGITAL_BIT_1)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_2", DIGITAL_BIT_2)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_3", DIGITAL_BIT_3)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_4", DIGITAL_BIT_4)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_5", DIGITAL_BIT_5)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_6", DIGITAL_BIT_6)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_7", DIGITAL_BIT_7)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_8", DIGITAL_BIT_8)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_9", DIGITAL_BIT_9)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_10", DIGITAL_BIT_10)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_11", DIGITAL_BIT_11)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_12", DIGITAL_BIT_12)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_13", DIGITAL_BIT_13)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_14", DIGITAL_BIT_14)},
    {SWIG_LUA_CONSTTAB_INT("DIGITAL_BIT_15", DIGITAL_BIT_15)},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_FRAME_HEADER", (1024))},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_FRAME_DATA", (512*1000*1000))},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_FRAME_PACKET", (1024*1024))},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_FRAME_MEMORY", (512*1024*1024))},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_MAX_VOLTAGE", (+511))},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_MIN_VOLTAGE", (-512))},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_DISPLAY", 10000)},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_FIRMWARE_FX3", 16384)},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_FIRMWARE_FPGA", (4*1024*1024))},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_EEPROM_BYTES", (256*1024))},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_EEPROM_FIRMWARE_NAME_BYTES", (16))},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_GENERATOR", 32768)},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_SUCCESS", 0)},
    {SWIG_LUA_CONSTTAB_INT("SCOPEFUN_FAILURE", -1)},
    {SWIG_LUA_CONSTTAB_INT("dfMax", dfMax)},
    {SWIG_LUA_CONSTTAB_INT("dfMin", dfMin)},
    {SWIG_LUA_CONSTTAB_INT("dfMedium", dfMedium)},
    {SWIG_LUA_CONSTTAB_INT("dfAdd", dfAdd)},
    {SWIG_LUA_CONSTTAB_INT("dfCh0SubCh1", dfCh0SubCh1)},
    {SWIG_LUA_CONSTTAB_INT("dfCh1SubCh0", dfCh1SubCh0)},
    {SWIG_LUA_CONSTTAB_INT("dfScript", dfScript)},
    {SWIG_LUA_CONSTTAB_INT("stSin", stSin)},
    {SWIG_LUA_CONSTTAB_INT("stCos", stCos)},
    {SWIG_LUA_CONSTTAB_INT("stInc", stInc)},
    {SWIG_LUA_CONSTTAB_INT("stDec", stDec)},
    {SWIG_LUA_CONSTTAB_INT("stConstant", stConstant)},
    {SWIG_LUA_CONSTTAB_INT("stRandom", stRandom)},
    {SWIG_LUA_CONSTTAB_INT("stSquare", stSquare)},
    {SWIG_LUA_CONSTTAB_INT("stDelta", stDelta)},
    {SWIG_LUA_CONSTTAB_INT("daETS", daETS)},
    {0,0,0,0,0,0}
};
static swig_lua_method swig_SwigModule_methods[]= {
    { "sfCreateSFloat", _wrap_sfCreateSFloat},
    { "sfCreateSInt", _wrap_sfCreateSInt},
    { "sfCreateSFContext", _wrap_sfCreateSFContext},
    { "sfCreateSDisplay", _wrap_sfCreateSDisplay},
    { "sfCreateSSimulate", _wrap_sfCreateSSimulate},
    { "sfCreateSUsb", _wrap_sfCreateSUsb},
    { "sfCreateSHardware", _wrap_sfCreateSHardware},
    { "sfCreateSFx3", _wrap_sfCreateSFx3},
    { "sfCreateSFpga", _wrap_sfCreateSFpga},
    { "sfCreateSGenerator", _wrap_sfCreateSGenerator},
    { "sfCreateSEeprom", _wrap_sfCreateSEeprom},
    { "sfCreateSFrameData", _wrap_sfCreateSFrameData},
    { "sfCreateSFrameHeader", _wrap_sfCreateSFrameHeader},
    { "sfDeleteSFloat", _wrap_sfDeleteSFloat},
    { "sfDeleteSInt", _wrap_sfDeleteSInt},
    { "sfDeleteSFContext", _wrap_sfDeleteSFContext},
    { "sfDeleteSDisplay", _wrap_sfDeleteSDisplay},
    { "sfDeleteSSimulate", _wrap_sfDeleteSSimulate},
    { "sfDeleteSUsb", _wrap_sfDeleteSUsb},
    { "sfDeleteSHardware", _wrap_sfDeleteSHardware},
    { "sfDeleteSFrameData", _wrap_sfDeleteSFrameData},
    { "sfDeleteSFx3", _wrap_sfDeleteSFx3},
    { "sfDeleteSFpga", _wrap_sfDeleteSFpga},
    { "sfDeleteSGenerator", _wrap_sfDeleteSGenerator},
    { "sfDeleteSEeprom", _wrap_sfDeleteSEeprom},
    { "sfDeleteSFrameHeader", _wrap_sfDeleteSFrameHeader},
    { "sfApiInit", _wrap_sfApiInit},
    { "sfApiCreateContext", _wrap_sfApiCreateContext},
    { "sfApiDeleteContext", _wrap_sfApiDeleteContext},
    { "sfApiVersion", _wrap_sfApiVersion},
    { "sfSetThreadSafe", _wrap_sfSetThreadSafe},
    { "sfIsThreadSafe", _wrap_sfIsThreadSafe},
    { "sfSetActive", _wrap_sfSetActive},
    { "sfIsActive", _wrap_sfIsActive},
    { "sfSetTimeOut", _wrap_sfSetTimeOut},
    { "sfGetTimeOut", _wrap_sfGetTimeOut},
    { "sfApiExit", _wrap_sfApiExit},
    { "sfHardwareOpen", _wrap_sfHardwareOpen},
    { "sfHardwareReset", _wrap_sfHardwareReset},
    { "sfHardwareIsOpened", _wrap_sfHardwareIsOpened},
    { "sfHardwareConfig", _wrap_sfHardwareConfig},
    { "sfHardwareCapture", _wrap_sfHardwareCapture},
    { "sfHardwareUploadFx3", _wrap_sfHardwareUploadFx3},
    { "sfHardwareUploadFpga", _wrap_sfHardwareUploadFpga},
    { "sfHardwareUploadGenerator", _wrap_sfHardwareUploadGenerator},
    { "sfHardwareEepromRead", _wrap_sfHardwareEepromRead},
    { "sfHardwareEepromReadFirmwareID", _wrap_sfHardwareEepromReadFirmwareID},
    { "sfHardwareReadFpgaStatus", _wrap_sfHardwareReadFpgaStatus},
    { "sfHardwareEepromWrite", _wrap_sfHardwareEepromWrite},
    { "sfHardwareEepromErase", _wrap_sfHardwareEepromErase},
    { "sfHardwareClose", _wrap_sfHardwareClose},
    { "sfFrameCapture", _wrap_sfFrameCapture},
    { "sfFrameOutput", _wrap_sfFrameOutput},
    { "sfFrameDisplay", _wrap_sfFrameDisplay},
    { "sfFrameDisplayFunction", _wrap_sfFrameDisplayFunction},
    { "sfFrameDisplayCallback", _wrap_sfFrameDisplayCallback},
    { "sfGetHeader", _wrap_sfGetHeader},
    { "sfGetHeaderHardware", _wrap_sfGetHeaderHardware},
    { "sfGetHeaderEts", _wrap_sfGetHeaderEts},
    { "sfGetHeaderTemperature", _wrap_sfGetHeaderTemperature},
    { "sfHardwareWordCnt", _wrap_sfHardwareWordCnt},
    { "sfHardwareWordId", _wrap_sfHardwareWordId},
    { "sfSetData", _wrap_sfSetData},
    { "sfGetData", _wrap_sfGetData},
    { "sfIsSimulate", _wrap_sfIsSimulate},
    { "sfSetSimulateData", _wrap_sfSetSimulateData},
    { "sfGetSimulateData", _wrap_sfGetSimulateData},
    { "sfSetSimulateOnOff", _wrap_sfSetSimulateOnOff},
    { "sfSimulate", _wrap_sfSimulate},
    { "sfSetDefault", _wrap_sfSetDefault},
    { "sfSetFrameSize", _wrap_sfSetFrameSize},
    { "sfSetNumSamples", _wrap_sfSetNumSamples},
    { "sfSetAnalogSwitchBit", _wrap_sfSetAnalogSwitchBit},
    { "sfSetEts", _wrap_sfSetEts},
    { "sfSetYRangeScaleA", _wrap_sfSetYRangeScaleA},
    { "sfSetYPositionA", _wrap_sfSetYPositionA},
    { "sfSetYRangeScaleB", _wrap_sfSetYRangeScaleB},
    { "sfSetYPositionB", _wrap_sfSetYPositionB},
    { "sfSetXRange", _wrap_sfSetXRange},
    { "sfSetControl", _wrap_sfSetControl},
    { "sfSetSampleSize", _wrap_sfSetSampleSize},
    { "sfSetTriggerSource", _wrap_sfSetTriggerSource},
    { "sfSetTriggerReArm", _wrap_sfSetTriggerReArm},
    { "sfSetTriggerMode", _wrap_sfSetTriggerMode},
    { "sfSetTriggerSlope", _wrap_sfSetTriggerSlope},
    { "sfSetTriggerPre", _wrap_sfSetTriggerPre},
    { "sfSetTriggerHis", _wrap_sfSetTriggerHis},
    { "sfSetTriggerLevel", _wrap_sfSetTriggerLevel},
    { "sfSetHoldoff", _wrap_sfSetHoldoff},
    { "sfSetGeneratorType0", _wrap_sfSetGeneratorType0},
    { "sfSetGeneratorOn0", _wrap_sfSetGeneratorOn0},
    { "sfSetGeneratorSlope0", _wrap_sfSetGeneratorSlope0},
    { "sfSetGeneratorVoltage0", _wrap_sfSetGeneratorVoltage0},
    { "sfSetGeneratorOffset0", _wrap_sfSetGeneratorOffset0},
    { "sfSetGeneratorFrequency0", _wrap_sfSetGeneratorFrequency0},
    { "sfSetGeneratorSquareDuty0", _wrap_sfSetGeneratorSquareDuty0},
    { "sfSetGeneratorType1", _wrap_sfSetGeneratorType1},
    { "sfSetGeneratorOn1", _wrap_sfSetGeneratorOn1},
    { "sfSetGeneratorSlope1", _wrap_sfSetGeneratorSlope1},
    { "sfSetGeneratorVoltage1", _wrap_sfSetGeneratorVoltage1},
    { "sfSetGeneratorOffset1", _wrap_sfSetGeneratorOffset1},
    { "sfSetGeneratorFrequency1", _wrap_sfSetGeneratorFrequency1},
    { "sfSetGeneratorSquareDuty1", _wrap_sfSetGeneratorSquareDuty1},
    { "sfSetDigitalVoltage", _wrap_sfSetDigitalVoltage},
    { "sfSetDigitalInputOutput", _wrap_sfSetDigitalInputOutput},
    { "sfSetDigitalOutputBit", _wrap_sfSetDigitalOutputBit},
    { "sfSetDigitalClockDivide", _wrap_sfSetDigitalClockDivide},
    { "sfSetAverage", _wrap_sfSetAverage},
    { "sfSetDigitalStart", _wrap_sfSetDigitalStart},
    { "sfSetDigitalMode", _wrap_sfSetDigitalMode},
    { "sfSetDigitalChannel", _wrap_sfSetDigitalChannel},
    { "sfSetDigitalDelay", _wrap_sfSetDigitalDelay},
    { "sfSetDigitalMask", _wrap_sfSetDigitalMask},
    { "sfSetDigitalPattern", _wrap_sfSetDigitalPattern},
    { "sfGetFrameSize", _wrap_sfGetFrameSize},
    { "sfGetNumSamples", _wrap_sfGetNumSamples},
    { "sfGetAnalogSwitch", _wrap_sfGetAnalogSwitch},
    { "sfGetEts", _wrap_sfGetEts},
    { "sfGetControl", _wrap_sfGetControl},
    { "sfGetYGainA", _wrap_sfGetYGainA},
    { "sfGetYScaleA", _wrap_sfGetYScaleA},
    { "sfGetYPositionA", _wrap_sfGetYPositionA},
    { "sfGetYGainB", _wrap_sfGetYGainB},
    { "sfGetYScaleB", _wrap_sfGetYScaleB},
    { "sfGetYPositionB", _wrap_sfGetYPositionB},
    { "sfGetTriggerSource", _wrap_sfGetTriggerSource},
    { "sfGetTriggerMode", _wrap_sfGetTriggerMode},
    { "sfGetTriggerSlope", _wrap_sfGetTriggerSlope},
    { "sfGetTriggerPre", _wrap_sfGetTriggerPre},
    { "sfGetTriggerHis", _wrap_sfGetTriggerHis},
    { "sfGetTriggerLevel", _wrap_sfGetTriggerLevel},
    { "sfGetXRange", _wrap_sfGetXRange},
    { "sfGetSampleSize", _wrap_sfGetSampleSize},
    { "sfGetHoldoff", _wrap_sfGetHoldoff},
    { "sfGetAverage", _wrap_sfGetAverage},
    { "sfGetGeneratorType0", _wrap_sfGetGeneratorType0},
    { "sfGetGeneratorOn0", _wrap_sfGetGeneratorOn0},
    { "sfGetGeneratorSlope0", _wrap_sfGetGeneratorSlope0},
    { "sfGetGeneratorVoltage0", _wrap_sfGetGeneratorVoltage0},
    { "sfGetGeneratorOffset0", _wrap_sfGetGeneratorOffset0},
    { "sfGetGeneratorFrequency0", _wrap_sfGetGeneratorFrequency0},
    { "sfGetGeneratorSquareDuty0", _wrap_sfGetGeneratorSquareDuty0},
    { "sfGetGeneratorType1", _wrap_sfGetGeneratorType1},
    { "sfGetGeneratorOn1", _wrap_sfGetGeneratorOn1},
    { "sfGetGeneratorSlope1", _wrap_sfGetGeneratorSlope1},
    { "sfGetGeneratorVoltage1", _wrap_sfGetGeneratorVoltage1},
    { "sfGetGeneratorOffset1", _wrap_sfGetGeneratorOffset1},
    { "sfGetGeneratorFrequency1", _wrap_sfGetGeneratorFrequency1},
    { "sfGetGeneratorSquareDuty1", _wrap_sfGetGeneratorSquareDuty1},
    { "sfGetDigitalStart", _wrap_sfGetDigitalStart},
    { "sfGetDigitalMode", _wrap_sfGetDigitalMode},
    { "sfGetDigitalChannel", _wrap_sfGetDigitalChannel},
    { "sfGetDigitalDelay", _wrap_sfGetDigitalDelay},
    { "sfGetDigitalMask", _wrap_sfGetDigitalMask},
    { "sfGetDigitalPattern", _wrap_sfGetDigitalPattern},
    { "sfGetDigitalVoltage", _wrap_sfGetDigitalVoltage},
    { "sfGetDigitalInputOutput15", _wrap_sfGetDigitalInputOutput15},
    { "sfGetDigitalInputOutput7", _wrap_sfGetDigitalInputOutput7},
    { "sfGetDigitalOutputBit", _wrap_sfGetDigitalOutputBit},
    { "sfGetDigitalClockDivide", _wrap_sfGetDigitalClockDivide},
    {0,0}
};
static swig_lua_class* swig_SwigModule_classes[]= {
&_wrap_class_SHardware,
&_wrap_class_SArrayMagic,
&_wrap_class_SArrayETS,
&_wrap_class_SArrayPaddingBefore,
&_wrap_class_SArrayHardware,
&_wrap_class_SArrayPaddingAfter,
&_wrap_class_SArrayCrc,
&_wrap_class_SFrameHeader,
&_wrap_class_SArrayString256,
&_wrap_class_SArrayFrameData,
&_wrap_class_SFrameData,
&_wrap_class_SArrayEEPROM,
&_wrap_class_SEeprom,
&_wrap_class_SGUID,
&_wrap_class_SArrayFx3,
&_wrap_class_SFx3,
&_wrap_class_SArrayFpga,
&_wrap_class_SFpga,
&_wrap_class_SArrayGeneratorAnalog0,
&_wrap_class_SArrayGeneratorAnalog1,
&_wrap_class_SArrayGeneratorDigital,
&_wrap_class_SGenerator,
&_wrap_class_SSimulate,
&_wrap_class_SUsb,
&_wrap_class_SArrayDisplayAnalog0,
&_wrap_class_SArrayDisplayAnalog1,
&_wrap_class_SArrayDisplayAnalogF,
&_wrap_class_SArrayDisplayDigital,
&_wrap_class_SDisplay,
&_wrap_class_SAtomic,
&_wrap_class_SCtxSimulate,
&_wrap_class_SCtxFrame,
&_wrap_class_SCtxDisplay,
&_wrap_class_SCtxApi,
&_wrap_class_SFContext,
&_wrap_class_SCallback,
&_wrap_class_SInt,
&_wrap_class_SFloat,
    0
};
static swig_lua_namespace* swig_SwigModule_namespaces[] = {
    0
};

static swig_lua_namespace swig_SwigModule = {
    "ScopeFun",
    swig_SwigModule_methods,
    swig_SwigModule_attributes,
    swig_SwigModule_constants,
    swig_SwigModule_classes,
    swig_SwigModule_namespaces
};
#ifdef __cplusplus
}
#endif

/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (BEGIN) -------- */

static swig_type_info _swigt__p_SArrayCrc = {"_p_SArrayCrc", "SArrayCrc *", 0, 0, (void*)&_wrap_class_SArrayCrc, 0};
static swig_type_info _swigt__p_SArrayDisplayAnalog0 = {"_p_SArrayDisplayAnalog0", "SArrayDisplayAnalog0 *", 0, 0, (void*)&_wrap_class_SArrayDisplayAnalog0, 0};
static swig_type_info _swigt__p_SArrayDisplayAnalog1 = {"_p_SArrayDisplayAnalog1", "SArrayDisplayAnalog1 *", 0, 0, (void*)&_wrap_class_SArrayDisplayAnalog1, 0};
static swig_type_info _swigt__p_SArrayDisplayAnalogF = {"_p_SArrayDisplayAnalogF", "SArrayDisplayAnalogF *", 0, 0, (void*)&_wrap_class_SArrayDisplayAnalogF, 0};
static swig_type_info _swigt__p_SArrayDisplayDigital = {"_p_SArrayDisplayDigital", "SArrayDisplayDigital *", 0, 0, (void*)&_wrap_class_SArrayDisplayDigital, 0};
static swig_type_info _swigt__p_SArrayEEPROM = {"_p_SArrayEEPROM", "SArrayEEPROM *", 0, 0, (void*)&_wrap_class_SArrayEEPROM, 0};
static swig_type_info _swigt__p_SArrayETS = {"_p_SArrayETS", "SArrayETS *", 0, 0, (void*)&_wrap_class_SArrayETS, 0};
static swig_type_info _swigt__p_SArrayFpga = {"_p_SArrayFpga", "SArrayFpga *", 0, 0, (void*)&_wrap_class_SArrayFpga, 0};
static swig_type_info _swigt__p_SArrayFrameData = {"_p_SArrayFrameData", "SArrayFrameData *", 0, 0, (void*)&_wrap_class_SArrayFrameData, 0};
static swig_type_info _swigt__p_SArrayFx3 = {"_p_SArrayFx3", "SArrayFx3 *", 0, 0, (void*)&_wrap_class_SArrayFx3, 0};
static swig_type_info _swigt__p_SArrayGeneratorAnalog0 = {"_p_SArrayGeneratorAnalog0", "SArrayGeneratorAnalog0 *", 0, 0, (void*)&_wrap_class_SArrayGeneratorAnalog0, 0};
static swig_type_info _swigt__p_SArrayGeneratorAnalog1 = {"_p_SArrayGeneratorAnalog1", "SArrayGeneratorAnalog1 *", 0, 0, (void*)&_wrap_class_SArrayGeneratorAnalog1, 0};
static swig_type_info _swigt__p_SArrayGeneratorDigital = {"_p_SArrayGeneratorDigital", "SArrayGeneratorDigital *", 0, 0, (void*)&_wrap_class_SArrayGeneratorDigital, 0};
static swig_type_info _swigt__p_SArrayHardware = {"_p_SArrayHardware", "SArrayHardware *", 0, 0, (void*)&_wrap_class_SArrayHardware, 0};
static swig_type_info _swigt__p_SArrayMagic = {"_p_SArrayMagic", "SArrayMagic *", 0, 0, (void*)&_wrap_class_SArrayMagic, 0};
static swig_type_info _swigt__p_SArrayPaddingAfter = {"_p_SArrayPaddingAfter", "SArrayPaddingAfter *", 0, 0, (void*)&_wrap_class_SArrayPaddingAfter, 0};
static swig_type_info _swigt__p_SArrayPaddingBefore = {"_p_SArrayPaddingBefore", "SArrayPaddingBefore *", 0, 0, (void*)&_wrap_class_SArrayPaddingBefore, 0};
static swig_type_info _swigt__p_SArrayString256 = {"_p_SArrayString256", "SArrayString256 *", 0, 0, (void*)&_wrap_class_SArrayString256, 0};
static swig_type_info _swigt__p_SAtomic = {"_p_SAtomic", "SAtomic *", 0, 0, (void*)&_wrap_class_SAtomic, 0};
static swig_type_info _swigt__p_SCtxApi = {"_p_SCtxApi", "SCtxApi *", 0, 0, (void*)&_wrap_class_SCtxApi, 0};
static swig_type_info _swigt__p_SCtxDisplay = {"_p_SCtxDisplay", "SCtxDisplay *", 0, 0, (void*)&_wrap_class_SCtxDisplay, 0};
static swig_type_info _swigt__p_SCtxFrame = {"_p_SCtxFrame", "SCtxFrame *", 0, 0, (void*)&_wrap_class_SCtxFrame, 0};
static swig_type_info _swigt__p_SCtxSimulate = {"_p_SCtxSimulate", "SCtxSimulate *", 0, 0, (void*)&_wrap_class_SCtxSimulate, 0};
static swig_type_info _swigt__p_SDisplay = {"_p_SDisplay", "SDisplay *", 0, 0, (void*)&_wrap_class_SDisplay, 0};
static swig_type_info _swigt__p_SEeprom = {"_p_SEeprom", "SEeprom *", 0, 0, (void*)&_wrap_class_SEeprom, 0};
static swig_type_info _swigt__p_SFContext = {"_p_SFContext", "SFContext *", 0, 0, (void*)&_wrap_class_SFContext, 0};
static swig_type_info _swigt__p_SFpga = {"_p_SFpga", "SFpga *", 0, 0, (void*)&_wrap_class_SFpga, 0};
static swig_type_info _swigt__p_SFrameData = {"_p_SFrameData", "SFrameData *", 0, 0, (void*)&_wrap_class_SFrameData, 0};
static swig_type_info _swigt__p_SFrameHeader = {"_p_SFrameHeader", "SFrameHeader *", 0, 0, (void*)&_wrap_class_SFrameHeader, 0};
static swig_type_info _swigt__p_SFx3 = {"_p_SFx3", "SFx3 *", 0, 0, (void*)&_wrap_class_SFx3, 0};
static swig_type_info _swigt__p_SGUID = {"_p_SGUID", "SGUID *", 0, 0, (void*)&_wrap_class_SGUID, 0};
static swig_type_info _swigt__p_SGenerator = {"_p_SGenerator", "SGenerator *", 0, 0, (void*)&_wrap_class_SGenerator, 0};
static swig_type_info _swigt__p_SHardware = {"_p_SHardware", "SHardware *", 0, 0, (void*)&_wrap_class_SHardware, 0};
static swig_type_info _swigt__p_SSimulate = {"_p_SSimulate", "SSimulate *", 0, 0, (void*)&_wrap_class_SSimulate, 0};
static swig_type_info _swigt__p_SUsb = {"_p_SUsb", "SUsb *", 0, 0, (void*)&_wrap_class_SUsb, 0};
static swig_type_info _swigt__p__EFunctionType = {"_p__EFunctionType", "enum _EFunctionType *|EFunctionType *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p__ESimulateType = {"_p__ESimulateType", "enum _ESimulateType *|ESimulateType *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p__SCallback = {"_p__SCallback", "struct _SCallback *|_SCallback *|SCallback *", 0, 0, (void*)&_wrap_class_SCallback, 0};
static swig_type_info _swigt__p__SFloat = {"_p__SFloat", "struct _SFloat *|SFloat *|_SFloat *", 0, 0, (void*)&_wrap_class_SFloat, 0};
static swig_type_info _swigt__p__SInt = {"_p__SInt", "SInt *|struct _SInt *|_SInt *", 0, 0, (void*)&_wrap_class_SInt, 0};
static swig_type_info _swigt__p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int = {"_p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int", "int (*)(int,short *,short *,short *,unsigned short *,float *,float *,void *)|int (*)(int,ishort *,ishort *,ishort *,ushort *,float *,float *,void *)", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_f_p_SDisplay_p_float_p_float_p_void__int = {"_p_f_p_SDisplay_p_float_p_float_p_void__int", "int (*)(SDisplay *,float *,float *,void *)", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_f_p_SFContext__int = {"_p_f_p_SFContext__int", "int (*)(SFContext *)", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_f_p_SFrameData_int_p_float_p_float_p_void__int = {"_p_f_p_SFrameData_int_p_float_p_float_p_void__int", "int (*)(SFrameData *,int,float *,float *,void *)", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_f_p_SGenerator_p_unsigned_int__int = {"_p_f_p_SGenerator_p_unsigned_int__int", "int (*)(SGenerator *,uint *)|int (*)(SGenerator *,unsigned int *)", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_f_p_SHardware__int = {"_p_f_p_SHardware__int", "int (*)(SHardware *)", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_f_short_short_p_short__int = {"_p_f_short_short_p_short__int", "int (*)(short,short,short *)|int (*)(ishort,ishort,ishort *)", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_float = {"_p_float", "float *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_int = {"_p_int", "int *|SSpinLock *|iint *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_long_long = {"_p_long_long", "long long *|ilarge *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_short = {"_p_short", "short *|ishort *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_unsigned_char = {"_p_unsigned_char", "unsigned char *|byte *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_unsigned_int = {"_p_unsigned_int", "unsigned int *|uint *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_unsigned_long_long = {"_p_unsigned_long_long", "unsigned long long *|ularge *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_unsigned_short = {"_p_unsigned_short", "unsigned short *|ushort *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_void = {"_p_void", "void *", 0, 0, (void*)0, 0};

static swig_type_info *swig_type_initial[] = {
  &_swigt__p_SArrayCrc,
  &_swigt__p_SArrayDisplayAnalog0,
  &_swigt__p_SArrayDisplayAnalog1,
  &_swigt__p_SArrayDisplayAnalogF,
  &_swigt__p_SArrayDisplayDigital,
  &_swigt__p_SArrayEEPROM,
  &_swigt__p_SArrayETS,
  &_swigt__p_SArrayFpga,
  &_swigt__p_SArrayFrameData,
  &_swigt__p_SArrayFx3,
  &_swigt__p_SArrayGeneratorAnalog0,
  &_swigt__p_SArrayGeneratorAnalog1,
  &_swigt__p_SArrayGeneratorDigital,
  &_swigt__p_SArrayHardware,
  &_swigt__p_SArrayMagic,
  &_swigt__p_SArrayPaddingAfter,
  &_swigt__p_SArrayPaddingBefore,
  &_swigt__p_SArrayString256,
  &_swigt__p_SAtomic,
  &_swigt__p_SCtxApi,
  &_swigt__p_SCtxDisplay,
  &_swigt__p_SCtxFrame,
  &_swigt__p_SCtxSimulate,
  &_swigt__p_SDisplay,
  &_swigt__p_SEeprom,
  &_swigt__p_SFContext,
  &_swigt__p_SFpga,
  &_swigt__p_SFrameData,
  &_swigt__p_SFrameHeader,
  &_swigt__p_SFx3,
  &_swigt__p_SGUID,
  &_swigt__p_SGenerator,
  &_swigt__p_SHardware,
  &_swigt__p_SSimulate,
  &_swigt__p_SUsb,
  &_swigt__p__EFunctionType,
  &_swigt__p__ESimulateType,
  &_swigt__p__SCallback,
  &_swigt__p__SFloat,
  &_swigt__p__SInt,
  &_swigt__p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int,
  &_swigt__p_f_p_SDisplay_p_float_p_float_p_void__int,
  &_swigt__p_f_p_SFContext__int,
  &_swigt__p_f_p_SFrameData_int_p_float_p_float_p_void__int,
  &_swigt__p_f_p_SGenerator_p_unsigned_int__int,
  &_swigt__p_f_p_SHardware__int,
  &_swigt__p_f_short_short_p_short__int,
  &_swigt__p_float,
  &_swigt__p_int,
  &_swigt__p_long_long,
  &_swigt__p_short,
  &_swigt__p_unsigned_char,
  &_swigt__p_unsigned_int,
  &_swigt__p_unsigned_long_long,
  &_swigt__p_unsigned_short,
  &_swigt__p_void,
};

static swig_cast_info _swigc__p_SArrayCrc[] = {  {&_swigt__p_SArrayCrc, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayDisplayAnalog0[] = {  {&_swigt__p_SArrayDisplayAnalog0, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayDisplayAnalog1[] = {  {&_swigt__p_SArrayDisplayAnalog1, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayDisplayAnalogF[] = {  {&_swigt__p_SArrayDisplayAnalogF, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayDisplayDigital[] = {  {&_swigt__p_SArrayDisplayDigital, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayEEPROM[] = {  {&_swigt__p_SArrayEEPROM, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayETS[] = {  {&_swigt__p_SArrayETS, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayFpga[] = {  {&_swigt__p_SArrayFpga, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayFrameData[] = {  {&_swigt__p_SArrayFrameData, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayFx3[] = {  {&_swigt__p_SArrayFx3, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayGeneratorAnalog0[] = {  {&_swigt__p_SArrayGeneratorAnalog0, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayGeneratorAnalog1[] = {  {&_swigt__p_SArrayGeneratorAnalog1, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayGeneratorDigital[] = {  {&_swigt__p_SArrayGeneratorDigital, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayHardware[] = {  {&_swigt__p_SArrayHardware, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayMagic[] = {  {&_swigt__p_SArrayMagic, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayPaddingAfter[] = {  {&_swigt__p_SArrayPaddingAfter, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayPaddingBefore[] = {  {&_swigt__p_SArrayPaddingBefore, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SArrayString256[] = {  {&_swigt__p_SArrayString256, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SAtomic[] = {  {&_swigt__p_SAtomic, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SCtxApi[] = {  {&_swigt__p_SCtxApi, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SCtxDisplay[] = {  {&_swigt__p_SCtxDisplay, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SCtxFrame[] = {  {&_swigt__p_SCtxFrame, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SCtxSimulate[] = {  {&_swigt__p_SCtxSimulate, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SDisplay[] = {  {&_swigt__p_SDisplay, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SEeprom[] = {  {&_swigt__p_SEeprom, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SFContext[] = {  {&_swigt__p_SFContext, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SFpga[] = {  {&_swigt__p_SFpga, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SFrameData[] = {  {&_swigt__p_SFrameData, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SFrameHeader[] = {  {&_swigt__p_SFrameHeader, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SFx3[] = {  {&_swigt__p_SFx3, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SGUID[] = {  {&_swigt__p_SGUID, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SGenerator[] = {  {&_swigt__p_SGenerator, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SHardware[] = {  {&_swigt__p_SHardware, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SSimulate[] = {  {&_swigt__p_SSimulate, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_SUsb[] = {  {&_swigt__p_SUsb, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p__EFunctionType[] = {  {&_swigt__p__EFunctionType, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p__ESimulateType[] = {  {&_swigt__p__ESimulateType, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p__SCallback[] = {  {&_swigt__p__SCallback, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p__SFloat[] = {  {&_swigt__p__SFloat, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p__SInt[] = {  {&_swigt__p__SInt, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int[] = {  {&_swigt__p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_f_p_SDisplay_p_float_p_float_p_void__int[] = {  {&_swigt__p_f_p_SDisplay_p_float_p_float_p_void__int, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_f_p_SFContext__int[] = {  {&_swigt__p_f_p_SFContext__int, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_f_p_SFrameData_int_p_float_p_float_p_void__int[] = {  {&_swigt__p_f_p_SFrameData_int_p_float_p_float_p_void__int, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_f_p_SGenerator_p_unsigned_int__int[] = {  {&_swigt__p_f_p_SGenerator_p_unsigned_int__int, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_f_p_SHardware__int[] = {  {&_swigt__p_f_p_SHardware__int, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_f_short_short_p_short__int[] = {  {&_swigt__p_f_short_short_p_short__int, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_float[] = {  {&_swigt__p_float, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_int[] = {  {&_swigt__p_int, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_long_long[] = {  {&_swigt__p_long_long, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_short[] = {  {&_swigt__p_short, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_unsigned_char[] = {  {&_swigt__p_unsigned_char, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_unsigned_int[] = {  {&_swigt__p_unsigned_int, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_unsigned_long_long[] = {  {&_swigt__p_unsigned_long_long, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_unsigned_short[] = {  {&_swigt__p_unsigned_short, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_void[] = {  {&_swigt__p_void, 0, 0, 0},{0, 0, 0, 0}};

static swig_cast_info *swig_cast_initial[] = {
  _swigc__p_SArrayCrc,
  _swigc__p_SArrayDisplayAnalog0,
  _swigc__p_SArrayDisplayAnalog1,
  _swigc__p_SArrayDisplayAnalogF,
  _swigc__p_SArrayDisplayDigital,
  _swigc__p_SArrayEEPROM,
  _swigc__p_SArrayETS,
  _swigc__p_SArrayFpga,
  _swigc__p_SArrayFrameData,
  _swigc__p_SArrayFx3,
  _swigc__p_SArrayGeneratorAnalog0,
  _swigc__p_SArrayGeneratorAnalog1,
  _swigc__p_SArrayGeneratorDigital,
  _swigc__p_SArrayHardware,
  _swigc__p_SArrayMagic,
  _swigc__p_SArrayPaddingAfter,
  _swigc__p_SArrayPaddingBefore,
  _swigc__p_SArrayString256,
  _swigc__p_SAtomic,
  _swigc__p_SCtxApi,
  _swigc__p_SCtxDisplay,
  _swigc__p_SCtxFrame,
  _swigc__p_SCtxSimulate,
  _swigc__p_SDisplay,
  _swigc__p_SEeprom,
  _swigc__p_SFContext,
  _swigc__p_SFpga,
  _swigc__p_SFrameData,
  _swigc__p_SFrameHeader,
  _swigc__p_SFx3,
  _swigc__p_SGUID,
  _swigc__p_SGenerator,
  _swigc__p_SHardware,
  _swigc__p_SSimulate,
  _swigc__p_SUsb,
  _swigc__p__EFunctionType,
  _swigc__p__ESimulateType,
  _swigc__p__SCallback,
  _swigc__p__SFloat,
  _swigc__p__SInt,
  _swigc__p_f_int_p_short_p_short_p_short_p_unsigned_short_p_float_p_float_p_void__int,
  _swigc__p_f_p_SDisplay_p_float_p_float_p_void__int,
  _swigc__p_f_p_SFContext__int,
  _swigc__p_f_p_SFrameData_int_p_float_p_float_p_void__int,
  _swigc__p_f_p_SGenerator_p_unsigned_int__int,
  _swigc__p_f_p_SHardware__int,
  _swigc__p_f_short_short_p_short__int,
  _swigc__p_float,
  _swigc__p_int,
  _swigc__p_long_long,
  _swigc__p_short,
  _swigc__p_unsigned_char,
  _swigc__p_unsigned_int,
  _swigc__p_unsigned_long_long,
  _swigc__p_unsigned_short,
  _swigc__p_void,
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (END) -------- */

/* -----------------------------------------------------------------------------
 * Type initialization:
 * This problem is tough by the requirement that no dynamic
 * memory is used. Also, since swig_type_info structures store pointers to
 * swig_cast_info structures and swig_cast_info structures store pointers back
 * to swig_type_info structures, we need some lookup code at initialization.
 * The idea is that swig generates all the structures that are needed.
 * The runtime then collects these partially filled structures.
 * The SWIG_InitializeModule function takes these initial arrays out of
 * swig_module, and does all the lookup, filling in the swig_module.types
 * array with the correct data and linking the correct swig_cast_info
 * structures together.
 *
 * The generated swig_type_info structures are assigned statically to an initial
 * array. We just loop through that array, and handle each type individually.
 * First we lookup if this type has been already loaded, and if so, use the
 * loaded structure instead of the generated one. Then we have to fill in the
 * cast linked list. The cast data is initially stored in something like a
 * two-dimensional array. Each row corresponds to a type (there are the same
 * number of rows as there are in the swig_type_initial array). Each entry in
 * a column is one of the swig_cast_info structures for that type.
 * The cast_initial array is actually an array of arrays, because each row has
 * a variable number of columns. So to actually build the cast linked list,
 * we find the array of casts associated with the type, and loop through it
 * adding the casts to the list. The one last trick we need to do is making
 * sure the type pointer in the swig_cast_info struct is correct.
 *
 * First off, we lookup the cast->type name to see if it is already loaded.
 * There are three cases to handle:
 *  1) If the cast->type has already been loaded AND the type we are adding
 *     casting info to has not been loaded (it is in this module), THEN we
 *     replace the cast->type pointer with the type pointer that has already
 *     been loaded.
 *  2) If BOTH types (the one we are adding casting info to, and the
 *     cast->type) are loaded, THEN the cast info has already been loaded by
 *     the previous module so we just ignore it.
 *  3) Finally, if cast->type has not already been loaded, then we add that
 *     swig_cast_info to the linked list (because the cast->type) pointer will
 *     be correct.
 * ----------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#if 0
} /* c-mode */
#endif
#endif

#if 0
#define SWIGRUNTIME_DEBUG
#endif


SWIGRUNTIME void
SWIG_InitializeModule(void *clientdata) {
  size_t i;
  swig_module_info *module_head, *iter;
  int init;

  /* check to see if the circular list has been setup, if not, set it up */
  if (swig_module.next==0) {
    /* Initialize the swig_module */
    swig_module.type_initial = swig_type_initial;
    swig_module.cast_initial = swig_cast_initial;
    swig_module.next = &swig_module;
    init = 1;
  } else {
    init = 0;
  }

  /* Try and load any already created modules */
  module_head = SWIG_GetModule(clientdata);
  if (!module_head) {
    /* This is the first module loaded for this interpreter */
    /* so set the swig module into the interpreter */
    SWIG_SetModule(clientdata, &swig_module);
  } else {
    /* the interpreter has loaded a SWIG module, but has it loaded this one? */
    iter=module_head;
    do {
      if (iter==&swig_module) {
        /* Our module is already in the list, so there's nothing more to do. */
        return;
      }
      iter=iter->next;
    } while (iter!= module_head);

    /* otherwise we must add our module into the list */
    swig_module.next = module_head->next;
    module_head->next = &swig_module;
  }

  /* When multiple interpreters are used, a module could have already been initialized in
     a different interpreter, but not yet have a pointer in this interpreter.
     In this case, we do not want to continue adding types... everything should be
     set up already */
  if (init == 0) return;

  /* Now work on filling in swig_module.types */
#ifdef SWIGRUNTIME_DEBUG
  printf("SWIG_InitializeModule: size %lu\n", (unsigned long)swig_module.size);
#endif
  for (i = 0; i < swig_module.size; ++i) {
    swig_type_info *type = 0;
    swig_type_info *ret;
    swig_cast_info *cast;

#ifdef SWIGRUNTIME_DEBUG
    printf("SWIG_InitializeModule: type %lu %s\n", (unsigned long)i, swig_module.type_initial[i]->name);
#endif

    /* if there is another module already loaded */
    if (swig_module.next != &swig_module) {
      type = SWIG_MangledTypeQueryModule(swig_module.next, &swig_module, swig_module.type_initial[i]->name);
    }
    if (type) {
      /* Overwrite clientdata field */
#ifdef SWIGRUNTIME_DEBUG
      printf("SWIG_InitializeModule: found type %s\n", type->name);
#endif
      if (swig_module.type_initial[i]->clientdata) {
	type->clientdata = swig_module.type_initial[i]->clientdata;
#ifdef SWIGRUNTIME_DEBUG
      printf("SWIG_InitializeModule: found and overwrite type %s \n", type->name);
#endif
      }
    } else {
      type = swig_module.type_initial[i];
    }

    /* Insert casting types */
    cast = swig_module.cast_initial[i];
    while (cast->type) {

      /* Don't need to add information already in the list */
      ret = 0;
#ifdef SWIGRUNTIME_DEBUG
      printf("SWIG_InitializeModule: look cast %s\n", cast->type->name);
#endif
      if (swig_module.next != &swig_module) {
        ret = SWIG_MangledTypeQueryModule(swig_module.next, &swig_module, cast->type->name);
#ifdef SWIGRUNTIME_DEBUG
	if (ret) printf("SWIG_InitializeModule: found cast %s\n", ret->name);
#endif
      }
      if (ret) {
	if (type == swig_module.type_initial[i]) {
#ifdef SWIGRUNTIME_DEBUG
	  printf("SWIG_InitializeModule: skip old type %s\n", ret->name);
#endif
	  cast->type = ret;
	  ret = 0;
	} else {
	  /* Check for casting already in the list */
	  swig_cast_info *ocast = SWIG_TypeCheck(ret->name, type);
#ifdef SWIGRUNTIME_DEBUG
	  if (ocast) printf("SWIG_InitializeModule: skip old cast %s\n", ret->name);
#endif
	  if (!ocast) ret = 0;
	}
      }

      if (!ret) {
#ifdef SWIGRUNTIME_DEBUG
	printf("SWIG_InitializeModule: adding cast %s\n", cast->type->name);
#endif
        if (type->cast) {
          type->cast->prev = cast;
          cast->next = type->cast;
        }
        type->cast = cast;
      }
      cast++;
    }
    /* Set entry in modules->types array equal to the type */
    swig_module.types[i] = type;
  }
  swig_module.types[i] = 0;

#ifdef SWIGRUNTIME_DEBUG
  printf("**** SWIG_InitializeModule: Cast List ******\n");
  for (i = 0; i < swig_module.size; ++i) {
    int j = 0;
    swig_cast_info *cast = swig_module.cast_initial[i];
    printf("SWIG_InitializeModule: type %lu %s\n", (unsigned long)i, swig_module.type_initial[i]->name);
    while (cast->type) {
      printf("SWIG_InitializeModule: cast type %s\n", cast->type->name);
      cast++;
      ++j;
    }
  printf("---- Total casts: %d\n",j);
  }
  printf("**** SWIG_InitializeModule: Cast List ******\n");
#endif
}

/* This function will propagate the clientdata field of type to
* any new swig_type_info structures that have been added into the list
* of equivalent types.  It is like calling
* SWIG_TypeClientData(type, clientdata) a second time.
*/
SWIGRUNTIME void
SWIG_PropagateClientData(void) {
  size_t i;
  swig_cast_info *equiv;
  static int init_run = 0;

  if (init_run) return;
  init_run = 1;

  for (i = 0; i < swig_module.size; i++) {
    if (swig_module.types[i]->clientdata) {
      equiv = swig_module.types[i]->cast;
      while (equiv) {
        if (!equiv->converter) {
          if (equiv->type && !equiv->type->clientdata)
            SWIG_TypeClientData(equiv->type, swig_module.types[i]->clientdata);
        }
        equiv = equiv->next;
      }
    }
  }
}

#ifdef __cplusplus
#if 0
{ /* c-mode */
#endif
}
#endif



/* Forward declaration of where the user's %init{} gets inserted */
void SWIG_init_user(lua_State* L );
    
#ifdef __cplusplus
extern "C" {
#endif
/* this is the initialization function
  added at the very end of the code
  the function is always called SWIG_init, but an earlier #define will rename it
*/
#if ((SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUA) || (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUAC))
LUALIB_API int SWIG_init(lua_State* L)
#else
SWIGEXPORT int SWIG_init(lua_State* L) /* default Lua action */
#endif
{
#if (SWIG_LUA_TARGET != SWIG_LUA_FLAVOR_ELUAC) /* valid for both Lua and eLua */
  int i;
  int globalRegister = 0;
  /* start with global table */
  lua_pushglobaltable (L);
  /* SWIG's internal initialisation */
  SWIG_InitializeModule((void*)L);
  SWIG_PropagateClientData();
#endif

#if ((SWIG_LUA_TARGET != SWIG_LUA_FLAVOR_ELUA) && (SWIG_LUA_TARGET != SWIG_LUA_FLAVOR_ELUAC)) || defined(SWIG_LUA_ELUA_EMULATE)
  /* add a global fn */
  SWIG_Lua_add_function(L,"swig_type",SWIG_Lua_type);
  SWIG_Lua_add_function(L,"swig_equals",SWIG_Lua_class_equal);
#endif

#if (SWIG_LUA_TARGET != SWIG_LUA_FLAVOR_ELUAC)
  /* set up base class pointers (the hierarchy) */
  for (i = 0; swig_types[i]; i++){
    if (swig_types[i]->clientdata){
      SWIG_Lua_init_base_class(L,(swig_lua_class*)(swig_types[i]->clientdata));
    }
  }
#ifdef SWIG_LUA_MODULE_GLOBAL
  globalRegister = 1;
#endif


#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_LUA)
  SWIG_Lua_namespace_register(L,&swig_SwigModule, globalRegister);
#endif

#if (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUA) || (SWIG_LUA_TARGET == SWIG_LUA_FLAVOR_ELUAC)
  for (i = 0; swig_types[i]; i++){
    if (swig_types[i]->clientdata){
      SWIG_Lua_elua_class_register_instance(L,(swig_lua_class*)(swig_types[i]->clientdata));
    }
  }
#endif

#if defined(SWIG_LUA_ELUA_EMULATE)
  lua_newtable(L);
  SWIG_Lua_elua_emulate_register(L,swig_SwigModule.ns_methods);
  SWIG_Lua_elua_emulate_register_clear(L);
  if(globalRegister) {
    lua_pushstring(L,swig_SwigModule.name);
    lua_pushvalue(L,-2);
    lua_rawset(L,-4);
  }
#endif

#endif

#if (SWIG_LUA_TARGET != SWIG_LUA_FLAVOR_ELUAC)
  /* invoke user-specific initialization */
  SWIG_init_user(L);
  /* end module */
  /* Note: We do not clean up the stack here (Lua will do this for us). At this
     point, we have the globals table and out module table on the stack. Returning
     one value makes the module table the result of the require command. */
  return 1;
#else
  return 0;
#endif
}

#ifdef __cplusplus
}
#endif


const char* SWIG_LUACODE=
  "";

void SWIG_init_user(lua_State* L)
{
  /* exec Lua code if applicable */
  SWIG_Lua_dostring(L,SWIG_LUACODE);
}

