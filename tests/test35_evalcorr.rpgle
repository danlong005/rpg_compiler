**FREE
DCL-DS source QUALIFIED;
  name VARCHAR(20);
  age INT(10);
  salary PACKED(9:2);
END-DS;

DCL-DS target QUALIFIED;
  name VARCHAR(20);
  age INT(10);
  dept VARCHAR(10);
END-DS;

source.name = 'Alice';
source.age = 30;
source.salary = 75000.50;

target.dept = 'IT';

// EVAL-CORR copies matching field names
EVAL-CORR target = source;

DSPLY target.name;
DSPLY %CHAR(target.age);
DSPLY target.dept;

*INLR = *ON;
