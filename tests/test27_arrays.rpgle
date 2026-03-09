**FREE
DCL-S numbers INT(10) DIM(5);
DCL-S names VARCHAR(20) DIM(3);
DCL-S i INT(10);
DCL-S total INT(10);
DCL-S count INT(10);

// Set array values
numbers(1) = 10;
numbers(2) = 20;
numbers(3) = 30;
numbers(4) = 40;
numbers(5) = 50;

// Sum the array
total = 0;
FOR i = 1 TO 5;
  total = total + numbers(i);
ENDFOR;
DSPLY %CHAR(total);

// %ELEM returns array size
count = %ELEM(numbers);
DSPLY %CHAR(count);

// String arrays
names(1) = 'Alice';
names(2) = 'Bob';
names(3) = 'Charlie';

FOR i = 1 TO %ELEM(names);
  DSPLY names(i);
ENDFOR;

// Modify and read back
numbers(3) = 99;
DSPLY %CHAR(numbers(3));

*INLR = *ON;
