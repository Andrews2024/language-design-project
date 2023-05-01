#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

struct expr_t;

enum expr_tag_t {
  NUM_TAG,
  OP_TAG,
  CALL_TAG, 
  VAR_TAG,
  IF_TAG
};

enum def_tag_t {
   VAR_DEF_TAG,
   FUNC_DEF_TAG
};

enum type_t{
   NUM_TYPE,
   STR_TYPE,
   BOOL_TYPE,
   ARRAY_NUM_TAG
};

typedef struct{
   char const* name;
}var_t;

typedef struct{
   char const* name;
}num_t;

typedef struct{
   char const* opName;
   expr_t* arg_left;
   expr_t* arg_right;
}op_t;

typedef struct{
   type_t* t;
   char const* name;
   expr_t* expr;
}var_def_t;

typedef struct{
   def_tag_t tag;
   union{
      //func_def fd;
      var_def_t vd;
   }u;
}def_t;


struct expr_t{
   expr_tag_t tag;
   union{
      var_t var;
      num_t num;
      op_t op;
   }u;
};


def_t* var_def_constructor(type_t*, char const*, expr_t*);

expr_t* op_constructor(expr_t*, expr_t*, const char*);

expr_t* var_constructor(const char*);

expr_t* num_lit_constructor(double);

type_t* kw_to_type(string kw);

