**FREE
// DCL-F declares a file - we stub it as a placeholder
DCL-F CUSTFILE DISK;
DCL-F RPTFILE PRINTER;

// We can still use other features alongside file declarations
DCL-S msg VARCHAR(50);
msg = 'File declarations parsed';
DSPLY msg;

*INLR = *ON;
