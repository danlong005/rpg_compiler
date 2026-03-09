**FREE
// Test 62: OVERLAY and POS on DS fields
DCL-DS address QUALIFIED;
  fullAddr CHAR(50);
  city CHAR(20) OVERLAY(fullAddr);
  state CHAR(2) OVERLAY(fullAddr:21);
  zip CHAR(10) OVERLAY(fullAddr:23);
END-DS;

DCL-DS record QUALIFIED;
  id INT(10) POS(1);
  name CHAR(20) POS(5);
END-DS;

// Set overlay fields directly
address.city = 'Minneapolis';
address.state = 'MN';
address.zip = '55401';
DSPLY %TRIM(address.city);
DSPLY address.state;
DSPLY %TRIM(address.zip);

// Test POS fields
record.id = 1;
record.name = 'Test Record';
DSPLY %CHAR(record.id);
DSPLY %TRIM(record.name);

*INLR = *ON;
