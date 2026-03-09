**FREE
DCL-DS Employee QUALIFIED DIM(*VAR:10);
  DCL-SUBF name VARCHAR(20);
  DCL-SUBF age INT(10);
END-DS;

DCL-S i INT(10);
DCL-S count INT(10);

// Resize to 3 entries
%ELEM(Employee) = 3;

Employee(1).name = 'Alice';
Employee(1).age = 30;
Employee(2).name = 'Bob';
Employee(2).age = 25;
Employee(3).name = 'Charlie';
Employee(3).age = 35;

count = %ELEM(Employee);
DSPLY %CHAR(count);  // 3

// Display entries
FOR i = 1 TO count;
  DSPLY Employee(i).name;
ENDFOR;

// Resize down
%ELEM(Employee) = 2;
count = %ELEM(Employee);
DSPLY %CHAR(count);  // 2

*INLR = *ON;
