**FREE

// CUST02R — Collect email addresses and mark messages as sent
//
// Reads:   MESSAGES  (sequential — pending messages where status = ' ')
//          CUSTOMERS (keyed — look up email by customer id)
// Updates: MESSAGES  (set email and status = 'X')

DCL-F MESSAGES  DISK;
DCL-F CUSTOMERS DISK KEYED;

DCL-S custId PACKED(10:0);

READ MESSAGES;
DOW NOT %EOF(MESSAGES);

  IF MESSAGES_STATUS = ' ';
    custId = MESSAGES_CUSTOMER_ID;

    CHAIN custId CUSTOMERS;
    IF %FOUND(CUSTOMERS);
      MESSAGES_EMAIL  = CUSTOMERS_EMAIL;
      MESSAGES_STATUS = 'X';
      UPDATE MESSAGES;
      DSPLY 'Email queued for ' + %TRIM(CUSTOMERS_FIRST_NAME) + ': ' +
            %TRIM(CUSTOMERS_EMAIL);
    ENDIF;
  ENDIF;

  READ MESSAGES;
ENDDO;

*INLR = *ON;
