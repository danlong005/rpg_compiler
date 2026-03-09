**FREE
DCL-S result VARCHAR(100);
DCL-S name VARCHAR(20);
DCL-S city VARCHAR(20);
DCL-S state VARCHAR(2);

name = 'Alice';
city = 'Dallas';
state = 'TX';

// Basic concat with comma separator
result = %CONCAT(', ': name: city: state);
DSPLY result;  // Alice, Dallas, TX

// Concat with dash separator
result = %CONCAT('-': '2024': '03': '15');
DSPLY result;  // 2024-03-15

// Concat two items
result = %CONCAT(' ': 'Hello': 'World');
DSPLY result;  // Hello World

// Concat with empty separator
result = %CONCAT('': 'A': 'B': 'C');
DSPLY result;  // ABC

*INLR = *ON;
