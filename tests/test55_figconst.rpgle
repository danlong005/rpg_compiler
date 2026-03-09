**FREE
// Test 55: Figurative Constants - *ALL'x'
DCL-S stars CHAR(10);
DCL-S dashes CHAR(5);
DCL-S pattern CHAR(6);

stars = *ALL'*';
DSPLY stars;

dashes = *ALL'-';
DSPLY dashes;

pattern = *ALL'AB';
DSPLY pattern;

*INLR = *ON;
