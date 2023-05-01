#include <stdlib.h>
#include <iostream>
#include "storage.h"
#include <string>

using namespace std;

using namespace std;

def_t* var_def_constructor(type_t* t, char const* name, expr_t* e){
   def_t* d = new def_t();
   d->tag = VAR_DEF_TAG;
   d->u.vd.t = t;
   d->u.vd.name = name;
   d->u.vd.expr = e;
   return d;
}

expr_t* op_constructor(expr_t* e1, expr_t* e2, const char* opname){
   expr_t* e = new expr_t();
   e->tag = OP_TAG;
   e->u.op.arg_left = e1;
   e->u.op.arg_right = e2;
   e->u.op.opName = opname;
   return e;
}

expr_t* var_constructor(const char* name){
   expr_t* e = new expr_t();
   e->tag = VAR_TAG;
   e->u.var.name = name;
   return e;
}

expr_t* num_lit_constructor(double n){
   expr_t* e = new expr_t();
   e->tag = NUM_TAG;
   string s = to_string(n);
   e->u.num.name = s.c_str();
   return e;
}

type_t* kw_to_type(string kw){
   type_t type;
   if(kw == "int" || kw == "integer"){
   	type = NUM_TYPE;
   }
   if(kw == "dec" || kw == "decimal"){
   	type = NUM_TYPE;
   }
   if(kw == "str" || kw == "string"){
   	type = STR_TYPE;
   }
   if(kw == "bool" || kw == "boolean"){
   	type = BOOL_TYPE;
   }
   type_t* type_ptr = &type;
   return type_ptr;
}



   
