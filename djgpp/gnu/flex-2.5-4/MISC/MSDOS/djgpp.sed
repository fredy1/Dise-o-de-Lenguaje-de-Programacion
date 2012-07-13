s/y\.tab\./y_tab\./g
s/\.bootstrap/_bootstrap/g
s/@DEFS@/-DMS_DOS/
s/@LIBS@//
s/@srcdir@/./
s/@YACC@/bison -y/
s/@CC@/gcc/
s/@RANLIB@/ranlib/
s/@ALLOCA@//
s/@SET_MAKE@//
s/@CFLAGS@/-O2 -g/
s/@CPPFLAGS@//
s/@INSTALL@/ginstall/
s/@INSTALL_PROGRAM@/ginstall -c/
s/@INSTALL_DATA@/ginstall -m 644/
/^ *config.h *:/ d
