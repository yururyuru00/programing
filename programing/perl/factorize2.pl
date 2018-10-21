#!/usr/bin/env perl
use strict;

sub factorize {
  my ($n) = @_;

  print "n = '$n'\n";

  my $root = sqrt($n);
  for(my $i = 2; $n >= $root; $i++) {
    if($n % $i == 0) {
      print "$i ";
      $n = $n / $i;
      $i--;
    }
    else {;}
  }

  print "$n \n"

}

1;
