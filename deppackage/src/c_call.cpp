#include <Rdefines.h>
#include <stdexcept>
#include "basepackage/foo.hpp"


extern "C" {

SEXP call_foo_no_catch() {
  typedef int FOO_FUNC();
  FOO_FUNC *foo = (FOO_FUNC*) R_GetCCallable("basepackage", "basepackage_foo");

  foo();
  
  return R_NilValue;
}



SEXP call_foo_catch() {
  typedef int FOO_FUNC();
  FOO_FUNC *foo = (FOO_FUNC*) R_GetCCallable("basepackage", "basepackage_foo");

  try {
    foo();
  } catch (const std::range_error& re) {
    SEXP ab;
    ab = PROTECT(allocVector(REALSXP, 2));
    REAL(ab)[0] = 123.45;
    REAL(ab)[1] = 67.89;
    UNPROTECT(1);
    return ab;
  }
    
  return R_NilValue;
}

}
