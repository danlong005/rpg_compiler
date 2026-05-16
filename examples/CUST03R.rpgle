**FREE

// CUST03R — Mark orders as thanked for all completed messages
//
// Reads:   MESSAGES (sequential — finds messages with status = 'X')
// Updates: ORDERS   (keyed — sets thanked = 'Y')

DCL-F MESSAGES DISK;
DCL-F ORDERS   DISK KEYED;

DCL-S orderId PACKED(10:0);

READ MESSAGES;
DOW NOT %EOF(MESSAGES);

  IF MESSAGES_STATUS = 'X';
    orderId = MESSAGES_ORDER_ID;

    CHAIN orderId ORDERS;
    IF %FOUND(ORDERS);
      ORDERS_THANKED = 'Y';
      UPDATE ORDERS;
      DSPLY 'Order ' + %CHAR(%INT(orderId)) + ' marked as thanked';
    ENDIF;
  ENDIF;

  READ MESSAGES;
ENDDO;

*INLR = *ON;
