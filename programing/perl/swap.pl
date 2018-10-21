sub swap {
  my ($a, $b) = @_;
  my $buffo;
  $buffo = $$a;
  $$a = $$b;
  $$b = $buffo;
}

use strict;

my $x;
my $y;
print "x= ";
chomp($x = <STDIN>);
print "y= ";
chomp($y = <STDIN>);
print "($x, $y)\n";
swap(\$x, \$y);
print "($x, $y)\n";
