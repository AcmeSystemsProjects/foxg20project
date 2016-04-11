# init the autotool system
AC_INIT([foxg20project], [1.0], [foxg20@acmesystems.it])

# init the automake system
AM_INIT_AUTOMAKE([foreign dist-xz])

# select the compiler
AC_PROG_CC

# check for libzmq reachability
AC_CHECK_LIB( [zmq], [zmq_errno], [], [
  AC_MSG_ERROR([unable to find the zmq])
])

AC_SEARCH_LIBS( [zstr_recv], [czmq], [], [
  AC_MSG_ERROR([unable to find the zstr_recv() function])
])


# generates makefiles
AC_OUTPUT([Makefile])
