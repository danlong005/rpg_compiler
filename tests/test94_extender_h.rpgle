**FREE
// Test 94: EVAL(H) — half-adjust (round)
DCL-S a PACKED(7:1) INZ(7.0);
DCL-S b PACKED(7:0) INZ(2);
DCL-S result INT(10);

EVAL(H) result = a / b;   // 3.5 → rounds to 4
IF result = 4;
  DSPLY 'HALF ADJUST OK';
ELSE;
  DSPLY 'HALF ADJUST FAIL';
ENDIF;

// Also test combinations: (MH) and (HR) are equivalent to (H)
DCL-S result2 INT(10);
EVAL(MH) result2 = a / b;
IF result2 = 4;
  DSPLY 'COMBO EXT OK';
ELSE;
  DSPLY 'COMBO EXT FAIL';
ENDIF;

*INLR = *ON;
