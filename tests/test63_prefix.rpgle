**FREE
// Test 63: PREFIX on DS
DCL-DS custRec QUALIFIED PREFIX(CUST_);
  id INT(10);
  name CHAR(30);
  city CHAR(20);
END-DS;

custRec.CUST_id = 100;
custRec.CUST_name = 'John Smith';
custRec.CUST_city = 'New York';

DSPLY %CHAR(custRec.CUST_id);
DSPLY %TRIM(custRec.CUST_name);
DSPLY %TRIM(custRec.CUST_city);

*INLR = *ON;
