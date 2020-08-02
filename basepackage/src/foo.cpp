#include <stdexcept>
#include <Rdefines.h>
#include <R_ext/Rdynload.h>
#include "basepackage/foo.hpp"

int foo() {
  throw std::range_error("throwing from basepackage 'foo'");
  return 0;
}



static const R_CallMethodDef CallEntries[] = {
  {"basepackage_foo", (DL_FUNC) &foo, 0},
  {NULL, NULL, 0}
};


extern "C" {
  void R_init_basepackage(DllInfo *dll) {
    R_RegisterCCallable("basepackage", "basepackage_foo", (DL_FUNC) &foo);
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
  }
}
  
