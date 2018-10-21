use strict;
use warnings;

my $statement = 'x = y + 1;';
my $var;
my $operand1;
my $operand2;
my $operation;

if($statement =~ /^\s* (\w+) \s* = \s* (\w+) \s* (\+|-|\*|\/|%) \s* (\w+) \s* ; \s* $/x) {
  $var = $1;
  $operation = $3;
  $operand1 = $2;
  $operand2 = $4;
  print "$var <= $operation($operand1, $operand2)\n";
}
elsif($statement =~ /^\s* (\D+) \s* = \s* (\w+) \s* ; \s* $/x) {
  $var = $1;
  $operand1 = $2;
  print "$var <= $operand1\n";
}
else {print "syntax_error\n";}
