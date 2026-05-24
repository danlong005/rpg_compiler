**FREE
DCL-S count INT(10) INZ(5);
DCL-S name CHAR(10) INZ('HELLO');
DCL-S rate PACKED(7:2) INZ(3.14);

count = count + 1;

DUMP;

*INLR = *ON;
