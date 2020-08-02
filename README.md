~~~ R
.Call("call_foo_catch")
.Call("call_foo_no_catch")


## Under Linux:

## > .Call("call_foo_catch")
## [1] 123.45  67.89
## > .Call("call_foo_no_catch")
## terminate called after throwing an instance of 'std::range_error'
##   what():  throwing from basepackage 'foo'

## Process R:2 aborted (core dumped) at Sun Aug  2 12:17:56 2020
~~~
