**free

// Test 107: SQL via rpgc.conf — no explicit EXEC SQL CONNECT or DISCONNECT

dcl-s name varchar(50);

exec sql create table emp107 (
  id   integer primary key,
  name varchar(50)
);

exec sql insert into emp107 values(1, 'Alice');
exec sql insert into emp107 values(2, 'Bob');
exec sql insert into emp107 values(3, 'Carol');

exec sql declare c1 cursor for
  select name from emp107 order by id;

exec sql open c1;
exec sql fetch next from c1 into :name;
dow sqlstate < '02000';
  dsply %trim(name);
  exec sql fetch next from c1 into :name;
enddo;
exec sql close c1;

exec sql drop table emp107;

*inlr = *on;
