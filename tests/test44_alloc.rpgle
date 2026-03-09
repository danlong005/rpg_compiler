**FREE
DCL-S ptr POINTER;
DCL-S numPtr POINTER;

// %ALLOC - allocate memory
ptr = %ALLOC(100);
IF ptr <> *NULL;
  DSPLY 'Allocated';
ENDIF;

// DEALLOC - free memory
DEALLOC ptr;
DSPLY 'Deallocated';

// %REALLOC
numPtr = %ALLOC(10);
numPtr = %REALLOC(numPtr : 200);
IF numPtr <> *NULL;
  DSPLY 'Reallocated';
ENDIF;
DEALLOC numPtr;

*INLR = *ON;
