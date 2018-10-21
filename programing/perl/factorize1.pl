#!/use/bin/env perl
use strict;
use warnings;

my $n;
warn "$n = 整数";
chomp($n = <STDIN>);
print "n = '$n'\n";

my $root = sqrt($n);
for(my $i = 2; $i <= $root; $i++) {
  if($n % $i == 0) {
    print "$i ";
    $n = $n / $i;
    $i--;
  }
  else {;}
}

print "$n \n"
