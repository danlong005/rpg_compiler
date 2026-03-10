**free


dcl-ds row qualified;
  id packed(10:0);
  firstName varchar(100);
  lastName varchar(100);
end-ds;

dcl-s connectionString varchar(100);

connectionString = 'Driver={PostgreSQL};Server=localhost;Port=5432;Database=cobol;Uid=admin;Pwd=password;';

exec sql connect using :connectionString;

exec sql declare c1 cursor for 
         select id, fname, lname
         from employees;

exec sql open c1;

exec sql fetch next from c1 into :row;
dow sqlstate < '02000';
  dsply 'Id: ' + %trim(%char(row.id)) + ', First Name: ' + %trim(row.firstName); 
  exec sql fetch next from c1 into :row;
enddo;

exec sql close c1;

*inlr = *on;
return;