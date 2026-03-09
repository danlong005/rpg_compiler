**FREE
// Data structure with qualified access
DCL-DS employee QUALIFIED;
  name VARCHAR(50);
  age INT(10);
  salary PACKED(9:2);
END-DS;

employee.name = 'Alice';
employee.age = 30;
employee.salary = 75000.50;

DSPLY employee.name;
DSPLY %CHAR(employee.age);
DSPLY %CHAR(employee.salary);

// Data structure array with DIM
DCL-DS items QUALIFIED DIM(3);
  desc VARCHAR(30);
  qty INT(10);
END-DS;

items(1).desc = 'Widget';
items(1).qty = 10;
items(2).desc = 'Gadget';
items(2).qty = 20;
items(3).desc = 'Doohickey';
items(3).qty = 5;

DCL-S i INT(10);
DCL-S total INT(10);
total = 0;
FOR i = 1 TO 3;
  DSPLY items(i).desc;
  total = total + items(i).qty;
ENDFOR;
DSPLY %CHAR(total);

*INLR = *ON;
