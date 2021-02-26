**free

dcl-s field1 int(10:0);
dcl-s field2 zoned(9:2);
dcl-s field1 int(10:0) inz;
dcl-s field3 char(50);
dcl-s field4 char(50) inz;
dcl-ds ds_struct qualified;
    field7 int(10:0);
end-ds;

field1 = 7;
exec sql ;
return;
