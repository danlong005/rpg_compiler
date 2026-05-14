**FREE

// Test 101: *USER figurative constant

DCL-S currentUser VARCHAR(10);
DCL-S msg         VARCHAR(50);

currentUser = *USER;

// Verify it's non-empty
IF currentUser <> '';
  DSPLY 'User is set';
ELSE;
  DSPLY 'User is empty';
ENDIF;

// Use *USER directly in an expression
msg = 'Hello ' + *USER;
DSPLY msg;

RETURN;
