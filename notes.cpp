enum {
  NUM_TAG = 0,
  ARRAY_NUM_TAG,
  OP_TAG,
  CALL_TAG, 
  VAR_TAG,
  STR_TAG,
  BOOL_TAG,
  IF_TAG
} expr_tag_t;


/*Step 1: Create structures for each enumeration tag
  Step 2: Translate our data in the store functionalities into the structures for the specified enum tag
  Step 3: Create our recursive expression handler to do any mathematical evaluation and function definition, etc. */


typedef struct {
char const* func_name;
  expr_t* arg;
  int nargs;
} func_call_t;

typedef struct {
char const* dec_name; //Also want a field for keyword?
  double value
} dec_t;







union {
  func_call_t func;
  let_t let;
} expr_union_t;
// if e is an expr_union_t
// then    e.func = interpret e as a func_call_t, e.let = interpret as let_t

/*
To use it:


switch (expr.tag) {
case INT_TAG:
int_t e = expr.e.int;
break;
case LET_TAG:
let_t e = expr.e.let;

}
*/


typedef struct {
  expr_tag_t tag;
  expr_union_t e;
} expr_t;


