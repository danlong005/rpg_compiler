**FREE
DCL-S a INT(10);
DCL-S b INT(10);
DCL-S result INT(10);
DCL-S floatResult PACKED(15:2);

// Bitwise AND
a = 15;   // 1111 in binary
b = 9;    // 1001 in binary
result = %BITAND(a:b);
DSPLY %CHAR(result);  // 9 (1001)

// Bitwise OR
result = %BITOR(a:b);
DSPLY %CHAR(result);  // 15 (1111)

// Bitwise XOR
a = 12;   // 1100 in binary
b = 10;   // 1010 in binary
result = %BITXOR(a:b);
DSPLY %CHAR(result);  // 6 (0110)

// Bitwise NOT (lower 8 bits for clarity)
a = 0;
result = %BITAND(%BITNOT(a):255);
DSPLY %CHAR(result);  // 255

// Exponentiation
floatResult = 2 ** 10;
DSPLY %CHAR(floatResult);  // 1024

floatResult = 3 ** 3;
DSPLY %CHAR(floatResult);  // 27

*INLR = *ON;
