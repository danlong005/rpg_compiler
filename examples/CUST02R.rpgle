**FREE

// CUST02R — Collect email addresses and mark messages as sent
//
// Reads:   MESSAGES  (sequential — pending messages where status = ' ')
//          CUSTOMERS (keyed — look up email by customer id)
// Updates: MESSAGES  (set email and status = 'X')

DCL-F MESSAGES  DISK PREFIX(MSG_);
DCL-F CUSTOMERS DISK KEYED PREFIX(CUST_);

DCL-S custId PACKED(10:0);

READ MESSAGES;
DOW NOT %EOF(MESSAGES);

  IF MSG_STATUS = ' ';
    custId = MSG_CUSTOMER_ID;

    CHAIN custId CUSTOMERS;
    IF %FOUND(CUSTOMERS);
      MSG_EMAIL  = CUST_EMAIL;
      MSG_STATUS = 'X';
      UPDATE MESSAGES;
      DSPLY 'Email queued for ' + %TRIM(CUST_FIRST_NAME) + ': ' +
            %TRIM(CUST_EMAIL);
    ENDIF;
  ENDIF;

  READ MESSAGES;
ENDDO;

*INLR = *ON;
