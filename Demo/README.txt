

This file aims at showing how to use the pvs2c translator on two set of demo files:

This folder should contain:
 - the pvs2c .lisp files :
     Canalysis.lisp
     Ctypes.lisp
     Ccode.lisp
     Cutils.lisp 
     Cprimop.lisp
     pvs2c.lisp
     Main.lisp
 - the C files for garbage collection:
     GC.c
     GC.h
 - the files for the first demo:
     demoC.c
     demoC.h
     demoPVS.pvs
     demo.pvs
 - the files for the second demo:
     bigint.pvs


To run the first demo :
 - Start PVS in the current folder "Demo"
 - Open the "demo.pvs" file     --> C-x C-f  demo.pvs)
 - Typecheck it                 --> M-x tcp
 - Switch to the *pvs* buffer   --> C-x b  *pvs*)
 - Load the "Main.pvs" file      -- (load "Main")
 - Use pvs2c to generate C code  -- (generate-C-for-pvs-file "demo")
      demo.C and demo.h are generated
 - Edit "demo.c" to print the result of some function calls
 - Compile demo.c               >> gcc -O2 -o demo demo.c GC.c -lgmp
 - Execute demo                 >> ./demo
 - You can compare performance with the execution of demoPVS.pvs using the pvs ground evaluator
       >> C-x C-f demoPVS
      --> M-x tc
      --> M-x pvs-ground-evaluator
       >> tsort
Rq : the ground evaluator won't run demo.pvs for some reasons... (involving the use of the rem function)
 - You can also compare with the same implementation of the program in C by compiling and running it


To run the second demo :
Same as before except that there is no C implementation of the pvs code provided and the ground evaluator does't seem to run the pvs file...


