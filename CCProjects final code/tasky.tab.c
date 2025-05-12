/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "tasky.y"

#include "astnode.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <ftw.h>
#include <climits>    // For LONG_MAX
#include <ctime>      // For localtime and strftime
#include <map>        // For std::map
#include <string>     // For std::string

// Removed dependency on archive.h and archive_entry.h

#ifdef __cplusplus
extern "C" int yylex();
#endif

extern FILE* yyin;
void yyerror(const char *s);
void execute(ASTNode* node);
ASTNode* make_node(const char* cmd, const char* arg1, const char* arg2, const char* arg3, int num1, int num2);

// Command implementation functions
void cmd_make_folder(const char* path, const char* name);
void cmd_place_text(const char* text, const char* file);
void cmd_add_file(const char* content, const char* file);
void cmd_remove_file(const char* file);
void cmd_remove_folder(const char* folder);
void cmd_show_files(const char* folder);
void cmd_remove_all_containing(const char* ext, const char* pattern, const char* folder);
void cmd_delete_if_contains(const char* file, const char* check_file, const char* pattern);
void cmd_change_extension(const char* ext, const char* new_ext);
void cmd_repeat_make_file(const char* filename, int start, int end);
void cmd_compress_all(const char* ext, const char* folder);
void cmd_rename_with_prefix(const char* folder, const char* prefix);
void cmd_count_in(const char* ext, const char* folder);
void cmd_run_command(const char* command);
void cmd_search_for(const char* pattern, const char* folder);
void cmd_append_to(const char* content, const char* file);
void cmd_create_from_template(const char* template_file, const char* vars_file);
void cmd_batch_process(const char* cmd, const char* pattern, const char* dir);
void cmd_file_stats(const char* extension, const char* folder);
void cmd_move_large_files(const char* src_dir, const char* dest_dir, int size_thresh);
void cmd_transform_content(const char* filename, const char* regex, const char* replacement);
void cmd_remove_lines(const char* filename, int n);
void cmd_sort_by_size(const char* ext, const char* folder);
void cmd_sort_by_date(const char* ext, const char* folder);
void cmd_conditional_move(const char* file, const char* pattern, const char* dest);
void cmd_calculate_add(int num1, int num2, const char* result_var);
void cmd_calculate_subtract(int num1, int num2, const char* result_var);
void cmd_calculate_multiply(int num1, int num2, const char* result_var);
void cmd_calculate_divide(int num1, int num2, const char* result_var);
void cmd_calculate_modulo(int num1, int num2, const char* result_var);
void cmd_calculate_power(int num1, int num2, const char* result_var);
void cmd_print_value(const char* var_name);
void cmd_calculate_var_add(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_subtract(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_multiply(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_divide(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_modulo(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_power(const char* var1, const char* var2, const char* result_var);
void cmd_store_number(int value, const char* var_name);

#line 142 "tasky.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "tasky.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAKE = 3,                       /* MAKE  */
  YYSYMBOL_NEW = 4,                        /* NEW  */
  YYSYMBOL_FOLDER = 5,                     /* FOLDER  */
  YYSYMBOL_FILEKW = 6,                     /* FILEKW  */
  YYSYMBOL_INSIDE = 7,                     /* INSIDE  */
  YYSYMBOL_NAMED = 8,                      /* NAMED  */
  YYSYMBOL_PLACE = 9,                      /* PLACE  */
  YYSYMBOL_ADD = 10,                       /* ADD  */
  YYSYMBOL_AT = 11,                        /* AT  */
  YYSYMBOL_END = 12,                       /* END  */
  YYSYMBOL_REMOVE = 13,                    /* REMOVE  */
  YYSYMBOL_SHOW = 14,                      /* SHOW  */
  YYSYMBOL_IN = 15,                        /* IN  */
  YYSYMBOL_ALL = 16,                       /* ALL  */
  YYSYMBOL_CONTAINING = 17,                /* CONTAINING  */
  YYSYMBOL_DELETE = 18,                    /* DELETE  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_CONTAIN = 20,                   /* CONTAIN  */
  YYSYMBOL_CONTENT = 21,                   /* CONTENT  */
  YYSYMBOL_OF = 22,                        /* OF  */
  YYSYMBOL_CHANGE = 23,                    /* CHANGE  */
  YYSYMBOL_EXTENSION = 24,                 /* EXTENSION  */
  YYSYMBOL_INTO = 25,                      /* INTO  */
  YYSYMBOL_REPEAT = 26,                    /* REPEAT  */
  YYSYMBOL_FROM = 27,                      /* FROM  */
  YYSYMBOL_UNTIL = 28,                     /* UNTIL  */
  YYSYMBOL_COMPRESS = 29,                  /* COMPRESS  */
  YYSYMBOL_RENAME = 30,                    /* RENAME  */
  YYSYMBOL_WITH = 31,                      /* WITH  */
  YYSYMBOL_PREFIX = 32,                    /* PREFIX  */
  YYSYMBOL_COUNT = 33,                     /* COUNT  */
  YYSYMBOL_RUN = 34,                       /* RUN  */
  YYSYMBOL_WRITE = 35,                     /* WRITE  */
  YYSYMBOL_TO = 36,                        /* TO  */
  YYSYMBOL_APPEND = 37,                    /* APPEND  */
  YYSYMBOL_SEARCH = 38,                    /* SEARCH  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_TEMPLATE = 40,                  /* TEMPLATE  */
  YYSYMBOL_VARIABLES = 41,                 /* VARIABLES  */
  YYSYMBOL_BATCH = 42,                     /* BATCH  */
  YYSYMBOL_PROCESS = 43,                   /* PROCESS  */
  YYSYMBOL_STATS = 44,                     /* STATS  */
  YYSYMBOL_LARGER = 45,                    /* LARGER  */
  YYSYMBOL_THAN = 46,                      /* THAN  */
  YYSYMBOL_TRANSFORM = 47,                 /* TRANSFORM  */
  YYSYMBOL_USING = 48,                     /* USING  */
  YYSYMBOL_REGEX = 49,                     /* REGEX  */
  YYSYMBOL_REPLACE = 50,                   /* REPLACE  */
  YYSYMBOL_EVERY = 51,                     /* EVERY  */
  YYSYMBOL_LINES = 52,                     /* LINES  */
  YYSYMBOL_SIZE = 53,                      /* SIZE  */
  YYSYMBOL_WHEN = 54,                      /* WHEN  */
  YYSYMBOL_MOVE = 55,                      /* MOVE  */
  YYSYMBOL_SORT = 56,                      /* SORT  */
  YYSYMBOL_BY = 57,                        /* BY  */
  YYSYMBOL_DATE = 58,                      /* DATE  */
  YYSYMBOL_CREATE = 59,                    /* CREATE  */
  YYSYMBOL_SUBTRACT = 60,                  /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 61,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 62,                    /* DIVIDE  */
  YYSYMBOL_CALCULATE = 63,                 /* CALCULATE  */
  YYSYMBOL_STORE = 64,                     /* STORE  */
  YYSYMBOL_RESULT = 65,                    /* RESULT  */
  YYSYMBOL_VALUE = 66,                     /* VALUE  */
  YYSYMBOL_PRINT = 67,                     /* PRINT  */
  YYSYMBOL_AND = 68,                       /* AND  */
  YYSYMBOL_MOD = 69,                       /* MOD  */
  YYSYMBOL_POWER = 70,                     /* POWER  */
  YYSYMBOL_EQUALS = 71,                    /* EQUALS  */
  YYSYMBOL_PLUS = 72,                      /* PLUS  */
  YYSYMBOL_MINUS = 73,                     /* MINUS  */
  YYSYMBOL_TIMES = 74,                     /* TIMES  */
  YYSYMBOL_DIV = 75,                       /* DIV  */
  YYSYMBOL_MODULO = 76,                    /* MODULO  */
  YYSYMBOL_POW = 77,                       /* POW  */
  YYSYMBOL_STRING = 78,                    /* STRING  */
  YYSYMBOL_IDENTIFIER = 79,                /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 80,                    /* NUMBER  */
  YYSYMBOL_81_ = 81,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_input = 83,                     /* input  */
  YYSYMBOL_command_list = 84,              /* command_list  */
  YYSYMBOL_command = 85                    /* command  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  4
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   335


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    93,    93,    96,    97,   106,   108,   110,   112,   114,
     116,   118,   120,   122,   124,   126,   128,   130,   132,   134,
     136,   138,   140,   142,   144,   146,   148,   150,   152,   154,
     156,   158,   160,   162,   164,   166,   168,   170,   172,   174,
     176,   178,   180,   182,   184
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAKE", "NEW",
  "FOLDER", "FILEKW", "INSIDE", "NAMED", "PLACE", "ADD", "AT", "END",
  "REMOVE", "SHOW", "IN", "ALL", "CONTAINING", "DELETE", "IF", "CONTAIN",
  "CONTENT", "OF", "CHANGE", "EXTENSION", "INTO", "REPEAT", "FROM",
  "UNTIL", "COMPRESS", "RENAME", "WITH", "PREFIX", "COUNT", "RUN", "WRITE",
  "TO", "APPEND", "SEARCH", "FOR", "TEMPLATE", "VARIABLES", "BATCH",
  "PROCESS", "STATS", "LARGER", "THAN", "TRANSFORM", "USING", "REGEX",
  "REPLACE", "EVERY", "LINES", "SIZE", "WHEN", "MOVE", "SORT", "BY",
  "DATE", "CREATE", "SUBTRACT", "MULTIPLY", "DIVIDE", "CALCULATE", "STORE",
  "RESULT", "VALUE", "PRINT", "AND", "MOD", "POWER", "EQUALS", "PLUS",
  "MINUS", "TIMES", "DIV", "MODULO", "POW", "STRING", "IDENTIFIER",
  "NUMBER", "':'", "$accept", "input", "command_list", "command", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,     0,   -73,   -69,    -4,     7,   -61,    -6,    -8,     5,
       6,   -54,   -53,   -49,   -45,   -11,    -5,    14,   -41,   -38,
      26,   -35,    39,   -64,   -34,   -18,    49,    -3,   -74,    45,
      47,    44,   -21,   -20,   -19,   -17,    62,    43,    56,     1,
       2,    64,    67,   -74,    48,    50,     9,    10,    11,    35,
      65,    46,    33,    66,    -7,    -1,    77,    72,   -74,   -74,
      88,    18,    85,   -74,   -74,    81,    51,    21,    22,    86,
      73,    89,    27,    28,    29,    30,    94,    79,    96,    63,
      36,    69,   -50,    76,    40,    41,    42,    52,    53,    54,
      37,    55,    57,    58,    59,    60,    68,    70,    71,   -74,
      91,    74,    95,   -74,   101,    75,    61,    78,    92,   -74,
     -74,   -74,    80,    82,    83,    84,    87,    90,   109,   110,
      93,    99,   100,   102,   103,   105,   108,   111,   112,   113,
     114,   115,   116,   -74,   -74,   118,   104,   119,   106,   107,
     117,   120,   -74,    97,   -74,   121,   -74,   123,   126,   128,
     122,   124,   134,   125,   127,   129,   130,   131,   132,   133,
     138,   139,   140,   141,   142,   135,   -74,   136,   -74,   137,
     143,   144,   145,   146,   147,   149,   148,   -74,   -74,   150,
     159,   168,   171,   172,   173,   174,   178,   184,   193,   194,
     195,   196,   -74,   -74,   151,   -74,   206,   -74,   -74,   -74,
     152,   179,   153,   154,   155,   156,   157,   158,   160,   161,
     162,   163,   164,   165,   166,   -74,   208,   -74,   167,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   169,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     4,
       0,     0,     0,     9,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,    10,     0,     0,     0,     0,     0,    17,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    37,     0,     0,     0,     0,     0,
       0,     0,    15,     0,    21,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,    11,     0,    13,     0,    16,    23,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,    30,     0,    22,
      38,    39,    40,    41,    42,    43,    31,    32,    33,    34,
      35,    36,     0,    25,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   190
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    26,    27,    28
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       1,    32,    33,   118,    29,    30,     2,     3,   119,    31,
       4,     5,    34,    36,    54,     6,    55,    37,    38,    39,
       7,    40,    41,     8,    42,    43,     9,    10,    46,    44,
      11,    12,    13,    45,    14,    15,    48,    49,    47,    16,
      50,    17,    51,    52,    18,    53,    56,    35,    57,    58,
      60,    19,    20,    21,    61,    62,    22,    63,    64,    65,
      23,    24,    68,    66,    25,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    67,    69,    72,
      71,    70,    73,    79,    74,    80,    75,    76,    77,    78,
      82,    81,    96,    83,    97,    98,    99,   100,   101,   103,
     104,   106,   105,   102,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   136,   116,   117,   120,   127,   121,   122,
     123,   139,   138,   143,   150,   151,   165,     0,   169,   172,
     124,   125,   126,     0,   167,   128,   173,   129,   130,   131,
     132,   141,   170,   176,     0,     0,   133,   196,   134,   135,
       0,     0,   137,   140,     0,     0,   142,     0,   144,   194,
     145,   146,   147,   153,   154,   179,   155,   156,   148,   157,
     149,   152,   158,   174,   203,   159,   160,   161,   162,   163,
     164,   175,   166,   204,   168,   200,   205,   206,   207,   208,
     180,   202,   181,   209,   182,   183,   184,   185,   186,   210,
     177,   171,   178,   187,   188,   189,   190,   191,   211,   212,
     213,   214,   216,   192,   193,   218,   232,    59,     0,     0,
       0,   195,     0,   197,   198,   199,   201,     0,     0,   215,
     217,   219,   220,   221,   222,   223,   224,     0,   225,   226,
     227,   228,   229,   230,   231,   233,     0,   234
};

static const yytype_int8 yycheck[] =
{
       3,     5,     6,    53,     4,    78,     9,    10,    58,    78,
      13,    14,    16,     6,    78,    18,    80,    78,    24,    27,
      23,    16,    16,    26,    78,    78,    29,    30,    39,    78,
      33,    34,    35,    78,    37,    38,    22,    78,    43,    42,
      78,    44,    16,    78,    47,     6,    80,    51,    66,     0,
       5,    54,    55,    56,     7,    11,    59,    78,    78,    78,
      63,    64,    19,    80,    67,    72,    73,    74,    75,    76,
      77,    72,    73,    74,    75,    76,    77,    15,    22,    15,
      78,    80,    15,    48,    36,    20,    36,    78,    78,    78,
      57,    45,    15,    27,    22,     7,    78,    12,    17,    78,
      78,    28,    16,    52,    15,    78,    78,    78,    78,    15,
      31,    15,    49,    22,    78,    46,    40,    80,    78,    78,
      78,    20,    27,    31,    15,    15,     8,    -1,    21,    32,
      78,    78,    78,    -1,    15,    80,    15,    80,    80,    80,
      80,    80,    25,    15,    -1,    -1,    78,     3,    78,    78,
      -1,    -1,    78,    78,    -1,    -1,    78,    -1,    78,    22,
      78,    78,    78,    64,    64,    31,    64,    64,    81,    64,
      80,    78,    64,    50,    15,    64,    64,    64,    64,    64,
      64,    55,    78,    15,    78,    36,    15,    15,    15,    15,
      65,    41,    65,    15,    65,    65,    65,    65,    65,    15,
      78,    81,    78,    65,    65,    65,    65,    65,    15,    15,
      15,    15,     6,    78,    78,    36,     8,    27,    -1,    -1,
      -1,    78,    -1,    78,    78,    78,    78,    -1,    -1,    78,
      78,    78,    78,    78,    78,    78,    78,    -1,    78,    78,
      78,    78,    78,    78,    78,    78,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     9,    10,    13,    14,    18,    23,    26,    29,
      30,    33,    34,    35,    37,    38,    42,    44,    47,    54,
      55,    56,    59,    63,    64,    67,    83,    84,    85,     4,
      78,    78,     5,     6,    16,    51,     6,    78,    24,    27,
      16,    16,    78,    78,    78,    78,    39,    43,    22,    78,
      78,    16,    78,     6,    78,    80,    80,    66,     0,    85,
       5,     7,    11,    78,    78,    78,    80,    15,    19,    22,
      80,    78,    15,    15,    36,    36,    78,    78,    78,    48,
      20,    45,    57,    27,    72,    73,    74,    75,    76,    77,
      72,    73,    74,    75,    76,    77,    15,    22,     7,    78,
      12,    17,    52,    78,    78,    16,    28,    15,    78,    78,
      78,    78,    15,    31,    15,    49,    78,    46,    53,    58,
      40,    78,    78,    78,    78,    78,    78,    80,    80,    80,
      80,    80,    80,    78,    78,    78,    22,    78,    27,    20,
      78,    80,    78,    31,    78,    78,    78,    78,    81,    80,
      15,    15,    78,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,     8,    78,    15,    78,    21,
      25,    81,    32,    15,    50,    55,    15,    78,    78,    31,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    78,    78,    22,    78,     3,    78,    78,    78,
      36,    78,    41,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    78,     6,    78,    36,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,     8,    78,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    82,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     7,     4,     6,     3,     3,
       4,     7,     8,     7,    10,     5,     7,     4,     2,     4,
       4,     5,     8,     7,     5,     9,     7,     6,     6,     6,
       8,     8,     8,     8,     8,     8,     8,     4,     8,     8,
       8,     8,     8,     8,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* input: command_list  */
#line 93 "tasky.y"
                    { execute((yyvsp[0].node)); }
#line 1347 "tasky.tab.c"
    break;

  case 3: /* command_list: command  */
#line 96 "tasky.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1353 "tasky.tab.c"
    break;

  case 4: /* command_list: command_list command  */
#line 97 "tasky.y"
                                   { 
                ASTNode *ptr = (yyvsp[-1].node); 
                while(ptr->next) ptr = ptr->next; 
                ptr->next = (yyvsp[0].node); 
                (yyval.node) = (yyvsp[-1].node); 
            }
#line 1364 "tasky.tab.c"
    break;

  case 5: /* command: MAKE NEW FOLDER INSIDE STRING NAMED STRING  */
#line 107 "tasky.y"
        { (yyval.node) = make_node("make_folder", (yyvsp[-2].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1370 "tasky.tab.c"
    break;

  case 6: /* command: PLACE STRING INSIDE STRING  */
#line 109 "tasky.y"
        { (yyval.node) = make_node("place_text", (yyvsp[-2].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1376 "tasky.tab.c"
    break;

  case 7: /* command: ADD STRING AT END OF STRING  */
#line 111 "tasky.y"
        { (yyval.node) = make_node("add_file", (yyvsp[-4].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1382 "tasky.tab.c"
    break;

  case 8: /* command: REMOVE FILEKW STRING  */
#line 113 "tasky.y"
        { (yyval.node) = make_node("remove_file", (yyvsp[0].str), NULL, NULL, 0, 0); }
#line 1388 "tasky.tab.c"
    break;

  case 9: /* command: REMOVE FOLDER STRING  */
#line 115 "tasky.y"
        { (yyval.node) = make_node("remove_folder", (yyvsp[0].str), NULL, NULL, 0, 0); }
#line 1394 "tasky.tab.c"
    break;

  case 10: /* command: SHOW FILEKW IN STRING  */
#line 117 "tasky.y"
        { (yyval.node) = make_node("show_files", (yyvsp[0].str), NULL, NULL, 0, 0); }
#line 1400 "tasky.tab.c"
    break;

  case 11: /* command: REMOVE ALL STRING CONTAINING STRING IN STRING  */
#line 119 "tasky.y"
        { (yyval.node) = make_node("remove_all_containing", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str), 0, 0); }
#line 1406 "tasky.tab.c"
    break;

  case 12: /* command: DELETE STRING IF STRING CONTAIN CONTENT OF STRING  */
#line 121 "tasky.y"
        { (yyval.node) = make_node("delete_if_contains", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[0].str), 0, 0); }
#line 1412 "tasky.tab.c"
    break;

  case 13: /* command: CHANGE EXTENSION OF ALL STRING INTO STRING  */
#line 123 "tasky.y"
        { (yyval.node) = make_node("change_extension", (yyvsp[-2].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1418 "tasky.tab.c"
    break;

  case 14: /* command: REPEAT FROM NUMBER UNTIL NUMBER ':' MAKE FILEKW NAMED STRING  */
#line 125 "tasky.y"
        { (yyval.node) = make_node("repeat_make_file", (yyvsp[0].str), NULL, NULL, (yyvsp[-7].num), (yyvsp[-5].num)); }
#line 1424 "tasky.tab.c"
    break;

  case 15: /* command: COMPRESS ALL STRING IN STRING  */
#line 127 "tasky.y"
        { (yyval.node) = make_node("compress_all", (yyvsp[-2].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1430 "tasky.tab.c"
    break;

  case 16: /* command: RENAME ALL IN STRING WITH PREFIX STRING  */
#line 129 "tasky.y"
        { (yyval.node) = make_node("rename_with_prefix", (yyvsp[-3].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1436 "tasky.tab.c"
    break;

  case 17: /* command: COUNT STRING IN STRING  */
#line 131 "tasky.y"
        { (yyval.node) = make_node("count_in", (yyvsp[-2].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1442 "tasky.tab.c"
    break;

  case 18: /* command: RUN STRING  */
#line 133 "tasky.y"
        { (yyval.node) = make_node("run_command", (yyvsp[0].str), NULL, NULL, 0, 0); }
#line 1448 "tasky.tab.c"
    break;

  case 19: /* command: WRITE STRING TO STRING  */
#line 135 "tasky.y"
        { (yyval.node) = make_node("place_text", (yyvsp[-2].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1454 "tasky.tab.c"
    break;

  case 20: /* command: APPEND STRING TO STRING  */
#line 137 "tasky.y"
        { (yyval.node) = make_node("append_to", (yyvsp[-2].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1460 "tasky.tab.c"
    break;

  case 21: /* command: SEARCH FOR STRING IN STRING  */
#line 139 "tasky.y"
        { (yyval.node) = make_node("search_for", (yyvsp[-2].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1466 "tasky.tab.c"
    break;

  case 22: /* command: CREATE FILEKW FROM TEMPLATE STRING WITH VARIABLES STRING  */
#line 141 "tasky.y"
        { (yyval.node) = make_node("create_from_template", (yyvsp[-3].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1472 "tasky.tab.c"
    break;

  case 23: /* command: BATCH PROCESS STRING WITH STRING IN STRING  */
#line 143 "tasky.y"
        { (yyval.node) = make_node("batch_process", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str), 0, 0); }
#line 1478 "tasky.tab.c"
    break;

  case 24: /* command: STATS OF STRING IN STRING  */
#line 145 "tasky.y"
        { (yyval.node) = make_node("file_stats", (yyvsp[-2].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1484 "tasky.tab.c"
    break;

  case 25: /* command: MOVE ALL LARGER THAN NUMBER IN STRING TO STRING  */
#line 147 "tasky.y"
        { (yyval.node) = make_node("move_large_files", (yyvsp[-2].str), (yyvsp[0].str), NULL, (yyvsp[-4].num), 0); }
#line 1490 "tasky.tab.c"
    break;

  case 26: /* command: TRANSFORM STRING USING REGEX STRING REPLACE STRING  */
#line 149 "tasky.y"
        { (yyval.node) = make_node("transform_content", (yyvsp[-5].str), (yyvsp[-2].str), (yyvsp[0].str), 0, 0); }
#line 1496 "tasky.tab.c"
    break;

  case 27: /* command: REMOVE EVERY NUMBER LINES FROM STRING  */
#line 151 "tasky.y"
        { (yyval.node) = make_node("remove_lines", (yyvsp[0].str), NULL, NULL, (yyvsp[-3].num), 0); }
#line 1502 "tasky.tab.c"
    break;

  case 28: /* command: SORT STRING BY SIZE IN STRING  */
#line 153 "tasky.y"
        { (yyval.node) = make_node("sort_by_size", (yyvsp[-4].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1508 "tasky.tab.c"
    break;

  case 29: /* command: SORT STRING BY DATE IN STRING  */
#line 155 "tasky.y"
        { (yyval.node) = make_node("sort_by_date", (yyvsp[-4].str), (yyvsp[0].str), NULL, 0, 0); }
#line 1514 "tasky.tab.c"
    break;

  case 30: /* command: WHEN STRING CONTAIN STRING ':' MOVE TO STRING  */
#line 157 "tasky.y"
        { (yyval.node) = make_node("conditional_move", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[0].str), 0, 0); }
#line 1520 "tasky.tab.c"
    break;

  case 31: /* command: CALCULATE NUMBER PLUS NUMBER STORE RESULT IN STRING  */
#line 159 "tasky.y"
        { (yyval.node) = make_node("calculate_add", NULL, (yyvsp[0].str), NULL, (yyvsp[-6].num), (yyvsp[-4].num)); }
#line 1526 "tasky.tab.c"
    break;

  case 32: /* command: CALCULATE NUMBER MINUS NUMBER STORE RESULT IN STRING  */
#line 161 "tasky.y"
        { (yyval.node) = make_node("calculate_subtract", NULL, (yyvsp[0].str), NULL, (yyvsp[-6].num), (yyvsp[-4].num)); }
#line 1532 "tasky.tab.c"
    break;

  case 33: /* command: CALCULATE NUMBER TIMES NUMBER STORE RESULT IN STRING  */
#line 163 "tasky.y"
        { (yyval.node) = make_node("calculate_multiply", NULL, (yyvsp[0].str), NULL, (yyvsp[-6].num), (yyvsp[-4].num)); }
#line 1538 "tasky.tab.c"
    break;

  case 34: /* command: CALCULATE NUMBER DIV NUMBER STORE RESULT IN STRING  */
#line 165 "tasky.y"
        { (yyval.node) = make_node("calculate_divide", NULL, (yyvsp[0].str), NULL, (yyvsp[-6].num), (yyvsp[-4].num)); }
#line 1544 "tasky.tab.c"
    break;

  case 35: /* command: CALCULATE NUMBER MODULO NUMBER STORE RESULT IN STRING  */
#line 167 "tasky.y"
        { (yyval.node) = make_node("calculate_modulo", NULL, (yyvsp[0].str), NULL, (yyvsp[-6].num), (yyvsp[-4].num)); }
#line 1550 "tasky.tab.c"
    break;

  case 36: /* command: CALCULATE NUMBER POW NUMBER STORE RESULT IN STRING  */
#line 169 "tasky.y"
        { (yyval.node) = make_node("calculate_power", NULL, (yyvsp[0].str), NULL, (yyvsp[-6].num), (yyvsp[-4].num)); }
#line 1556 "tasky.tab.c"
    break;

  case 37: /* command: PRINT VALUE OF STRING  */
#line 171 "tasky.y"
        { (yyval.node) = make_node("print_value", (yyvsp[0].str), NULL, NULL, 0, 0); }
#line 1562 "tasky.tab.c"
    break;

  case 38: /* command: CALCULATE STRING PLUS STRING STORE RESULT IN STRING  */
#line 173 "tasky.y"
        { (yyval.node) = make_node("calculate_var_add", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[0].str), 0, 0); }
#line 1568 "tasky.tab.c"
    break;

  case 39: /* command: CALCULATE STRING MINUS STRING STORE RESULT IN STRING  */
#line 175 "tasky.y"
        { (yyval.node) = make_node("calculate_var_subtract", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[0].str), 0, 0); }
#line 1574 "tasky.tab.c"
    break;

  case 40: /* command: CALCULATE STRING TIMES STRING STORE RESULT IN STRING  */
#line 177 "tasky.y"
        { (yyval.node) = make_node("calculate_var_multiply", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[0].str), 0, 0); }
#line 1580 "tasky.tab.c"
    break;

  case 41: /* command: CALCULATE STRING DIV STRING STORE RESULT IN STRING  */
#line 179 "tasky.y"
        { (yyval.node) = make_node("calculate_var_divide", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[0].str), 0, 0); }
#line 1586 "tasky.tab.c"
    break;

  case 42: /* command: CALCULATE STRING MODULO STRING STORE RESULT IN STRING  */
#line 181 "tasky.y"
        { (yyval.node) = make_node("calculate_var_modulo", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[0].str), 0, 0); }
#line 1592 "tasky.tab.c"
    break;

  case 43: /* command: CALCULATE STRING POW STRING STORE RESULT IN STRING  */
#line 183 "tasky.y"
        { (yyval.node) = make_node("calculate_var_power", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[0].str), 0, 0); }
#line 1598 "tasky.tab.c"
    break;

  case 44: /* command: STORE NUMBER IN STRING  */
#line 185 "tasky.y"
        { (yyval.node) = make_node("store_number", (yyvsp[0].str), NULL, NULL, (yyvsp[-2].num), 0); }
#line 1604 "tasky.tab.c"
    break;


#line 1608 "tasky.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 188 "tasky.y"


ASTNode *make_node(const char *cmd, const char *arg1, const char *arg2, const char *arg3, int num1, int num2) {
    ASTNode *n = (ASTNode*)calloc(1, sizeof(ASTNode));
    n->cmd = strdup(cmd);
    if(arg1) n->arg1 = strdup(arg1);
    if(arg2) n->arg2 = strdup(arg2);
    if(arg3) n->arg3 = strdup(arg3);
    n->num1 = num1;
    n->num2 = num2;
    n->next = NULL;
    return n;
}

// Helper function to ensure directory exists for a file
void ensure_directory(const char *path) {
    char *dir_path = strdup(path);
    char *dir = dirname(dir_path);
    
    // Check if directory exists
    struct stat st = {0};
    if (stat(dir, &st) == -1) {
        // Create directory recursively
        char cmd[1024];
        snprintf(cmd, sizeof(cmd), "mkdir -p %s", dir);
        system(cmd);
    }
    
    free(dir_path);
}

// Command implementations
void cmd_make_folder(const char* path, const char* name) {
    char full_path[1024];
    snprintf(full_path, sizeof(full_path), "%s/%s", path, name);
    
    printf("Creating folder: %s\n", full_path);
    
    // Create directory with rwx permissions for user
    if (mkdir(full_path, 0755) != 0) {
        if (errno != EEXIST) {
            perror("Error creating folder");
        } else {
            printf("Folder already exists\n");
        }
    } else {
        printf("Folder created successfully\n");
    }
}
void cmd_create_from_template(const char* template_file, const char* vars_file) {
    printf("Creating file from template '%s' with variables from '%s'\n", template_file, vars_file);
    
    // Read template file
    FILE* tf = fopen(template_file, "r");
    if (!tf) {
        perror("Cannot open template file");
        return;
    }
    
    // Read variables file
    FILE* vf = fopen(vars_file, "r");
    if (!vf) {
        perror("Cannot open variables file");
        fclose(tf);
        return;
    }
    
    // Get output filename from template (remove .template extension)
    char out_filename[256];
    strcpy(out_filename, template_file);
    char* dot = strrchr(out_filename, '.');
    if (dot && strcmp(dot, ".template") == 0) {
        *dot = '\0';
    } else {
        strcat(out_filename, ".output");
    }
    
    // Open output file
    FILE* of = fopen(out_filename, "w");
    if (!of) {
        perror("Cannot create output file");
        fclose(tf);
        fclose(vf);
        return;
    }
    
    // Read variables into memory
    char vars[50][256];
    char values[50][256];
    int var_count = 0;
    
    char line[512];
    while (fgets(line, sizeof(line), vf) && var_count < 50) {
        // Trim newline
        char* nl = strchr(line, '\n');
        if (nl) *nl = '\0';
        
        // Split by = sign
        char* eq = strchr(line, '=');
        if (eq) {
            *eq = '\0';
            strcpy(vars[var_count], line);
            strcpy(values[var_count], eq + 1);
            var_count++;
        }
    }
    
    // Process template file line by line
    while (fgets(line, sizeof(line), tf)) {
        // Process variables
        for (int i = 0; i < var_count; i++) {
            char var_token[300];
            sprintf(var_token, "{{%s}}", vars[i]);
            
            char* pos;
            while ((pos = strstr(line, var_token)) != NULL) {
                // Replace variable token with its value
                char before[512] = {0};
                strncpy(before, line, pos - line);
                
                char after[512] = {0};
                strcpy(after, pos + strlen(var_token));
                
                sprintf(line, "%s%s%s", before, values[i], after);
            }
        }
        
        // Write processed line to output
        fputs(line, of);
    }
    
    fclose(tf);
    fclose(vf);
    fclose(of);
    
    printf("Created file: %s\n", out_filename);
}

void cmd_batch_process(const char* cmd, const char* pattern, const char* dir) {
    printf("Batch processing files matching '%s' in '%s' with command '%s'\n", pattern, dir, cmd);
    
    DIR* d = opendir(dir);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    int files_processed = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            if (strstr(entry->d_name, pattern)) {
                char full_path[512];
                sprintf(full_path, "%s/%s", dir, entry->d_name);
                
                // Create and execute command
                char full_cmd[1024];
                sprintf(full_cmd, "%s \"%s\"", cmd, full_path);
                printf("Executing: %s\n", full_cmd);
                
                int result = system(full_cmd);
                if (result == 0) {
                    files_processed++;
                } else {
                    printf("Command failed with code %d\n", result);
                }
            }
        }
    }
    
    closedir(d);
    printf("Processed %d files\n", files_processed);
}

void cmd_file_stats(const char* extension, const char* folder) {
    printf("Gathering stats for files with extension '%s' in '%s'\n", extension, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    int file_count = 0;
    long total_size = 0;
    long smallest = LONG_MAX;
    long largest = 0;
    char smallest_file[256] = {0};
    char largest_file[256] = {0};
    
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            // Check if file has the right extension
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, extension) == 0) {
                char full_path[512];
                sprintf(full_path, "%s/%s", folder, entry->d_name);
                
                struct stat st;
                if (stat(full_path, &st) == 0) {
                    file_count++;
                    total_size += st.st_size;
                    
                    if (st.st_size < smallest) {
                        smallest = st.st_size;
                        strcpy(smallest_file, entry->d_name);
                    }
                    
                    if (st.st_size > largest) {
                        largest = st.st_size;
                        strcpy(largest_file, entry->d_name);
                    }
                }
            }
        }
    }
    
    closedir(d);
    
    printf("Statistics for '.%s' files in '%s':\n", extension, folder);
    printf("Total files: %d\n", file_count);
    printf("Total size: %ld bytes\n", total_size);
    if (file_count > 0) {
        printf("Average size: %ld bytes\n", total_size / file_count);
        printf("Smallest file: %s (%ld bytes)\n", smallest_file, smallest);
        printf("Largest file: %s (%ld bytes)\n", largest_file, largest);
    }
}

void cmd_move_large_files(const char* src_dir, const char* dest_dir, int size_thresh) {
    printf("Moving files larger than %d bytes from '%s' to '%s'\n", size_thresh, src_dir, dest_dir);
    
    // Make sure destination directory exists
    struct stat st = {0};
    if (stat(dest_dir, &st) == -1) {
        printf("Creating destination directory '%s'\n", dest_dir);
        if (mkdir(dest_dir, 0755) != 0) {
            perror("Failed to create destination directory");
            return;
        }
    }
    
    DIR* d = opendir(src_dir);
    if (!d) {
        perror("Cannot open source directory");
        return;
    }
    
    int files_moved = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            char src_path[512];
            sprintf(src_path, "%s/%s", src_dir, entry->d_name);
            
            struct stat file_stat;
            if (stat(src_path, &file_stat) == 0) {
                if (file_stat.st_size > size_thresh) {
                    char dest_path[512];
                    sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);
                    
                    printf("Moving %s (%ld bytes) to %s\n", src_path, file_stat.st_size, dest_path);
                    
                    if (rename(src_path, dest_path) == 0) {
                        files_moved++;
                    } else {
                        perror("Failed to move file");
                    }
                }
            }
        }
    }
    
    closedir(d);
    printf("Moved %d files\n", files_moved);
}

void cmd_transform_content(const char* filename, const char* regex_str, const char* replacement) {
    printf("Transforming content in '%s' using regex '%s' replacing with '%s'\n", 
           filename, regex_str, replacement);
    
    // Read file content
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("Cannot open file");
        return;
    }
    
    // Read entire file into memory
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    char* buffer = (char*)malloc(file_size + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(f);
        return;
    }
    
    size_t bytes_read = fread(buffer, 1, file_size, f);
    buffer[bytes_read] = '\0';
    fclose(f);
    
    // Simple string replace (not a full regex implementation)
    int replacements = 0;
    char* result = (char*)malloc(file_size * 2); // Allow for growth
    char* result_ptr = result;
    char* current = buffer;
    
    while (*current) {
        char* found = strstr(current, regex_str);
        if (found) {
            // Copy up to the match
            size_t len = found - current;
            strncpy(result_ptr, current, len);
            result_ptr += len;
            
            // Add replacement
            strcpy(result_ptr, replacement);
            result_ptr += strlen(replacement);
            
            // Move past the match
            current = found + strlen(regex_str);
            replacements++;
        } else {
            // Copy the rest
            strcpy(result_ptr, current);
            result_ptr += strlen(current);
            break;
        }
    }
    
    // Write back to file
    f = fopen(filename, "w");
    if (!f) {
        perror("Cannot open file for writing");
        free(buffer);
        free(result);
        return;
    }
    
    fputs(result, f);
    fclose(f);
    
    printf("Made %d replacements in the file\n", replacements);
    
    free(buffer);
    free(result);
}

void cmd_remove_lines(const char* filename, int n) {
    printf("Removing every %d lines from file '%s'\n", n, filename);
    
    // Read file content
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("Cannot open file");
        return;
    }
    
    char temp_filename[256];
    sprintf(temp_filename, "%s.tmp", filename);
    FILE* out = fopen(temp_filename, "w");
    if (!out) {
        perror("Cannot create temporary file");
        fclose(f);
        return;
    }
    
    int line_count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        line_count++;
        if (line_count % n != 0) {
            fputs(line, out);
        }
    }
    
    fclose(f);
    fclose(out);
    
    // Replace original with temp file
    if (rename(temp_filename, filename) != 0) {
        perror("Failed to replace original file");
        return;
    }
    
    printf("Processed file, removed lines\n");
}

typedef struct {
    char name[256];
    long size;
    time_t mtime;
} FileInfo;

int compare_by_size(const void* a, const void* b) {
    const FileInfo* fa = (const FileInfo*)a;
    const FileInfo* fb = (const FileInfo*)b;
    return fb->size - fa->size; // Descending order
}

int compare_by_date(const void* a, const void* b) {
    const FileInfo* fa = (const FileInfo*)a;
    const FileInfo* fb = (const FileInfo*)b;
    return fb->mtime - fa->mtime; // Descending order
}

void cmd_sort_by_size(const char* ext, const char* folder) {
    printf("Sorting files with extension '%s' in '%s' by size\n", ext, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    // Count matching files first
    int file_count = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, ext) == 0) {
                file_count++;
            }
        }
    }
    
    rewinddir(d);
    
    // Allocate array for file info
    FileInfo* files = (FileInfo*)malloc(file_count * sizeof(FileInfo));
    if (!files) {
        perror("Memory allocation failed");
        closedir(d);
        return;
    }
    
    // Fill array with file info
    int idx = 0;
    while ((entry = readdir(d)) != NULL && idx < file_count) {
        if (entry->d_type == DT_REG) {
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, ext) == 0) {
                char full_path[512];
                sprintf(full_path, "%s/%s", folder, entry->d_name);
                
                struct stat st;
                if (stat(full_path, &st) == 0) {
                    strcpy(files[idx].name, entry->d_name);
                    files[idx].size = st.st_size;
                    files[idx].mtime = st.st_mtime;
                    idx++;
                }
            }
        }
    }
    
    closedir(d);
    
    // Sort by size
    qsort(files, idx, sizeof(FileInfo), compare_by_size);
    
    // Display results
    printf("Files sorted by size (largest first):\n");
    for (int i = 0; i < idx; i++) {
        printf("%d. %s - %ld bytes\n", i+1, files[i].name, files[i].size);
    }
    
    free(files);
}

void cmd_sort_by_date(const char* ext, const char* folder) {
    printf("Sorting files with extension '%s' in '%s' by date\n", ext, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    // Count matching files first
    int file_count = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, ext) == 0) {
                file_count++;
            }
        }
    }
    
    rewinddir(d);
    
    // Allocate array for file info
    FileInfo* files = (FileInfo*)malloc(file_count * sizeof(FileInfo));
    if (!files) {
        perror("Memory allocation failed");
        closedir(d);
        return;
    }
    
    // Fill array with file info
    int idx = 0;
    while ((entry = readdir(d)) != NULL && idx < file_count) {
        if (entry->d_type == DT_REG) {
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, ext) == 0) {
                char full_path[512];
                sprintf(full_path, "%s/%s", folder, entry->d_name);
                
                struct stat st;
                if (stat(full_path, &st) == 0) {
                    strcpy(files[idx].name, entry->d_name);
                    files[idx].size = st.st_size;
                    files[idx].mtime = st.st_mtime;
                    idx++;
                }
            }
        }
    }
    
    closedir(d);
    
    // Sort by date
    qsort(files, idx, sizeof(FileInfo), compare_by_date);
    
    // Display results
    printf("Files sorted by date (newest first):\n");
    for (int i = 0; i < idx; i++) {
        char date_str[64];
        struct tm* timeinfo = localtime(&files[i].mtime);
        strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", timeinfo);
        printf("%d. %s - %s\n", i+1, files[i].name, date_str);
    }
    
    free(files);
}

void cmd_conditional_move(const char* file, const char* pattern, const char* dest) {
    printf("Checking if '%s' contains '%s', if yes, moving to '%s'\n", file, pattern, dest);
    
    // Check if file exists
    FILE* f = fopen(file, "r");
    if (!f) {
        perror("Cannot open file");
        return;
    }
    
    // Read file content
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    char* buffer = (char*)malloc(file_size + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(f);
        return;
    }
    
    size_t bytes_read = fread(buffer, 1, file_size, f);
    buffer[bytes_read] = '\0';
    fclose(f);
    
    // Check if pattern is in file
    if (strstr(buffer, pattern)) {
        printf("Pattern found in file, moving...\n");
        
        // Make sure destination directory exists
        struct stat st = {0};
        if (stat(dest, &st) == -1) {
            printf("Creating destination directory '%s'\n", dest);
            if (mkdir(dest, 0755) != 0) {
                perror("Failed to create destination directory");
                free(buffer);
                return;
            }
        }
        
        // Get filename part
const char* filename_const = strrchr(file, '/');
char* filename = filename_const ? const_cast<char*>(filename_const) : const_cast<char*>(file);

        if (filename) {
            filename++; // Skip the '/'
        } else {
            filename = (char*)file; // No path separator, use the whole string
        }
        
        char dest_path[512];
        sprintf(dest_path, "%s/%s", dest, filename);
        
        if (rename(file, dest_path) == 0) {
            printf("Moved '%s' to '%s'\n", file, dest_path);
        } else {
            perror("Failed to move file");
        }
    } else {
        printf("Pattern not found in file, no action taken\n");
    }
    
    free(buffer);
}

void cmd_place_text(const char* text, const char* file) {
    printf("Writing text to file: %s\n", file);
    
    ensure_directory(file);
    
    FILE *fp = fopen(file, "w");
    if (!fp) {
        perror("Error opening file for writing");
        return;
    }
    
    fprintf(fp, "%s", text);
    fclose(fp);
    printf("Text written successfully\n");
}

void cmd_add_file(const char* content, const char* file) {
    printf("Appending text to file: %s\n", file);
    
    ensure_directory(file);
    
    FILE *fp = fopen(file, "a");
    if (!fp) {
        perror("Error opening file for appending");
        return;
    }
    
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("Text appended successfully\n");
}

void cmd_remove_file(const char* file) {
    printf("Removing file: %s\n", file);
    
    if (unlink(file) != 0) {
        perror("Error removing file");
    } else {
        printf("File removed successfully\n");
    }
}

void cmd_remove_folder(const char* folder) {
    printf("Removing folder: %s\n", folder);
    
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "rm -rf %s", folder);
    if (system(cmd) != 0) {
        perror("Error removing folder");
    } else {
        printf("Folder removed successfully\n");
    }
}

void cmd_show_files(const char* folder) {
    printf("Listing files in: %s\n", folder);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(folder);
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') {
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    } else {
        perror("Error opening directory");
    }
}

void cmd_remove_all_containing(const char* ext, const char* pattern, const char* folder) {
    printf("Removing all %s files containing '%s' in %s\n", ext, pattern, folder);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(folder);
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, ext) != NULL) {
                char file_path[1024];
                snprintf(file_path, sizeof(file_path), "%s/%s", folder, dir->d_name);
                
                // Check if file contains pattern
                FILE *fp = fopen(file_path, "r");
                if (fp) {
                    char buffer[4096];
                    size_t bytes_read = fread(buffer, 1, sizeof(buffer)-1, fp);
                    buffer[bytes_read] = '\0';
                    fclose(fp);
                    
                    if (strstr(buffer, pattern) != NULL) {
                        printf("Removing file: %s\n", file_path);
                        unlink(file_path);
                    }
                }
            }
        }
        closedir(d);
    } else {
        perror("Error opening directory");
    }
}

void cmd_delete_if_contains(const char* file, const char* check_file, const char* pattern_file) {
    printf("Checking if %s contains content of %s to delete %s\n", check_file, pattern_file, file);
    
    // Read pattern file
    FILE *pattern_fp = fopen(pattern_file, "r");
    if (!pattern_fp) {
        perror("Error opening pattern file");
        return;
    }
    
    char pattern[4096];
    size_t pattern_len = fread(pattern, 1, sizeof(pattern)-1, pattern_fp);
    pattern[pattern_len] = '\0';
    fclose(pattern_fp);
    
    // Read check file
    FILE *check_fp = fopen(check_file, "r");
    if (!check_fp) {
        perror("Error opening check file");
        return;
    }
    
    char check_content[4096];
    size_t check_len = fread(check_content, 1, sizeof(check_content)-1, check_fp);
    check_content[check_len] = '\0';
    fclose(check_fp);
    
    // Check if content matches
    if (strstr(check_content, pattern) != NULL) {
        printf("Match found, deleting %s\n", file);
        unlink(file);
    } else {
        printf("No match found, keeping %s\n", file);
    }
}

void cmd_change_extension(const char* ext, const char* new_ext) {
    printf("Changing extension from %s to %s in current directory\n", ext, new_ext);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char *file_ext = strrchr(dir->d_name, '.');
            if (file_ext && strcmp(file_ext, ext) == 0) {
                char new_name[1024];
                int name_len = file_ext - dir->d_name;
                strncpy(new_name, dir->d_name, name_len);
                new_name[name_len] = '\0';
                strcat(new_name, new_ext);
                
                printf("Renaming %s to %s\n", dir->d_name, new_name);
                rename(dir->d_name, new_name);
            }
        }
        closedir(d);
    } else {
        perror("Error opening directory");
    }
}

void cmd_repeat_make_file(const char* filename_template, int start, int end) {
    printf("Creating files from %d to %d with template %s\n", start, end, filename_template);
    
    for (int i = start; i <= end; i++) {
        char filename[1024];
        const char *hash_pos = strchr(filename_template, '#');
        
        if (hash_pos) {
            // Replace # with the current number
            int prefix_len = hash_pos - filename_template;
            strncpy(filename, filename_template, prefix_len);
            filename[prefix_len] = '\0';
            sprintf(filename + prefix_len, "%d%s", i, hash_pos + 1);
        } else {
            // Just append number to the filename
            sprintf(filename, "%s%d", filename_template, i);
        }
        
        printf("Creating file: %s\n", filename);
        
        // Make sure the directory exists
        ensure_directory(filename);
        
        // Create the file
        FILE *fp = fopen(filename, "w");
        if (!fp) {
            perror("Error creating file");
            continue;
        }
        
        fprintf(fp, "File %d in sequence\n", i);
        fclose(fp);
    }
}


void cmd_compress_all(const char* ext, const char* folder) {
    printf("Compressing all %s files in %s\n", ext, folder);
    
    // Modified to use tar directly instead of libarchive
    char cmd[1024];
    char archive_name[1024];
    snprintf(archive_name, sizeof(archive_name), "%s_archive.tar.gz", ext+1);
    snprintf(cmd, sizeof(cmd), "find %s -name \"*%s\" -print0 | tar -czvf %s --null -T -", 
             folder, ext, archive_name);
    
    if (system(cmd) != 0) {
        perror("Error compressing files");
    } else {
        printf("Files compressed to %s\n", archive_name);
    }
}

void cmd_rename_with_prefix(const char* folder, const char* prefix) {
    printf("Renaming files in %s with prefix %s\n", folder, prefix);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(folder);
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') {
                char old_path[1024];
                char new_path[1024];
                snprintf(old_path, sizeof(old_path), "%s/%s", folder, dir->d_name);
                snprintf(new_path, sizeof(new_path), "%s/%s%s", folder, prefix, dir->d_name);
                
                printf("Renaming %s to %s\n", old_path, new_path);
                rename(old_path, new_path);
            }
        }
        closedir(d);
    } else {
        perror("Error opening directory");
    }
}

void cmd_count_in(const char* ext, const char* folder) {
    printf("Counting %s files in %s\n", ext, folder);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(folder);
    int count = 0;
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char *file_ext = strrchr(dir->d_name, '.');
            if (file_ext && strcmp(file_ext, ext) == 0) {
                count++;
            }
        }
        closedir(d);
        printf("Found %d files with extension %s\n", count, ext);
    } else {
        perror("Error opening directory");
    }
}

void cmd_run_command(const char* command) {
    printf("Executing command: %s\n", command);
    
    int result = system(command);
    if (result != 0) {
        printf("Command returned non-zero exit code: %d\n", result);
    } else {
        printf("Command executed successfully\n");
    }
}

void cmd_search_for(const char* pattern, const char* folder) {
    printf("Searching for '%s' in %s\n", pattern, folder);
    
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "grep -r \"%s\" %s", pattern, folder);
    system(cmd);
}

void cmd_append_to(const char* content, const char* file) {
    printf("Appending to file: %s\n", file);
    
    ensure_directory(file);
    
    FILE *fp = fopen(file, "a");
    if (!fp) {
        perror("Error opening file for appending");
        return;
    }
    
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("Content appended successfully\n");
}
// Global map for variable storage
std::map<std::string, int> variables;

void cmd_store_number(int value, const char* var_name) {
    if (!var_name) return;
    std::string name(var_name);
    variables[name] = value;
    printf("Stored value %d in variable '%s'\n", value, var_name);
}

int get_value(const char* var_name) {
    if (!var_name) return 0;
    std::string name(var_name);
    auto it = variables.find(name);
    if (it != variables.end()) {
        return it->second;
    }
    printf("Warning: Variable '%s' not found, using 0\n", var_name);
    return 0;
}

void cmd_print_value(const char* var_name) {
    if (!var_name) return;
    std::string name(var_name);
    auto it = variables.find(name);
    if (it != variables.end()) {
        printf("Value of variable '%s' is: %d\n", var_name, it->second);
    } else {
        printf("Variable '%s' not found\n", var_name);
    }
}

void cmd_calculate_add(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    int result = num1 + num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d + %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_subtract(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    int result = num1 - num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d - %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_multiply(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    int result = num1 * num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d * %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_divide(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    if (num2 == 0) {
        printf("Error: Division by zero!\n");
        return;
    }
    int result = num1 / num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d / %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_modulo(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    if (num2 == 0) {
        printf("Error: Modulo by zero!\n");
        return;
    }
    int result = num1 % num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d %% %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_power(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    int result = 1;
    for (int i = 0; i < num2; i++) {
        result *= num1;
    }
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d ^ %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_var_add(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    int result = val1 + val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) + %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_subtract(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    int result = val1 - val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) - %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_multiply(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    int result = val1 * val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) * %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_divide(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    if (val2 == 0) {
        printf("Error: Division by zero!\n");
        return;
    }
    int result = val1 / val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) / %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_modulo(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    if (val2 == 0) {
        printf("Error: Modulo by zero!\n");
        return;
    }
    int result = val1 % val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) %% %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_power(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    int result = 1;
    for (int i = 0; i < val2; i++) {
        result *= val1;
    }
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) ^ %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}
void execute(ASTNode *node) {
    while(node) {
        printf("\n-----------------------------------------------------\n");
        printf("Executing: %s\n", node->cmd);
        
        if (strcmp(node->cmd, "make_folder") == 0) {
            cmd_make_folder(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "place_text") == 0) {
            cmd_place_text(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "add_file") == 0) {
            cmd_add_file(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "remove_file") == 0) {
            cmd_remove_file(node->arg1);
        } else if (strcmp(node->cmd, "remove_folder") == 0) {
            cmd_remove_folder(node->arg1);
        } else if (strcmp(node->cmd, "show_files") == 0) {
            cmd_show_files(node->arg1);
        } else if (strcmp(node->cmd, "remove_all_containing") == 0) {
            cmd_remove_all_containing(node->arg1, node->arg2, node->arg3);
        } else if (strcmp(node->cmd, "delete_if_contains") == 0) {
            cmd_delete_if_contains(node->arg1, node->arg2, node->arg3);
        } else if (strcmp(node->cmd, "change_extension") == 0) {
            cmd_change_extension(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "repeat_make_file") == 0) {
            cmd_repeat_make_file(node->arg1, node->num1, node->num2);
        } else if (strcmp(node->cmd, "compress_all") == 0) {
            cmd_compress_all(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "rename_with_prefix") == 0) {
            cmd_rename_with_prefix(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "count_in") == 0) {
            cmd_count_in(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "run_command") == 0) {
            cmd_run_command(node->arg1);
        } else if (strcmp(node->cmd, "search_for") == 0) {
            cmd_search_for(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "append_to") == 0) {
            cmd_append_to(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "create_from_template") == 0) {
            cmd_create_from_template(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "batch_process") == 0) {
            cmd_batch_process(node->arg1, node->arg2, node->arg3);
        } else if (strcmp(node->cmd, "file_stats") == 0) {
            cmd_file_stats(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "move_large_files") == 0) {
            cmd_move_large_files(node->arg1, node->arg2, node->num1);
        } else if (strcmp(node->cmd, "transform_content") == 0) {
            cmd_transform_content(node->arg1, node->arg2, node->arg3);
        } else if (strcmp(node->cmd, "remove_lines") == 0) {
            cmd_remove_lines(node->arg1, node->num1);
        } else if (strcmp(node->cmd, "sort_by_size") == 0) {
            cmd_sort_by_size(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "sort_by_date") == 0) {
            cmd_sort_by_date(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "conditional_move") == 0) {
            cmd_conditional_move(node->arg1, node->arg2, node->arg3);
        }else if (strcmp(node->cmd, "calculate_add") == 0) {
            cmd_calculate_add(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_subtract") == 0) {
            cmd_calculate_subtract(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_multiply") == 0) {
            cmd_calculate_multiply(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_divide") == 0) {
            cmd_calculate_divide(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_modulo") == 0) {
            cmd_calculate_modulo(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_power") == 0) {
            cmd_calculate_power(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "print_value") == 0) {
            cmd_print_value(node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_var_add") == 0) {
            cmd_calculate_var_add(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_subtract") == 0) {
            cmd_calculate_var_subtract(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_multiply") == 0) {
            cmd_calculate_var_multiply(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_divide") == 0) {
            cmd_calculate_var_divide(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_modulo") == 0) {
            cmd_calculate_var_modulo(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_power") == 0) {
            cmd_calculate_var_power(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "store_number") == 0) {
            cmd_store_number(node->num1, node->arg1);
        }else {
            printf("Unknown command: %s\n", node->cmd);
        }
        
        printf("-----------------------------------------------------\n");
        node = node->next;
    }
}
// Add these to the yyerror function in tasky.y
void yyerror(const char *s) {
    extern char *yytext;
    fprintf(stderr, "Parse error: %s near token '%s'\n", s, yytext);
}

// Enhanced parsing diagnostic helper
void debug_token(const char* token_text, int token_type) {
    printf("TOKEN: '%s', TYPE: %d\n", token_text, token_type);
}
