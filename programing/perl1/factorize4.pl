use strict;
use warnings;

sub factorize {
  my ($n) = @_;
  my @array;
  print "n = '$n'\n";

  my $root = sqrt($n);
  for(my $i = 2; $i <= $root; $i++) {
    if($n % $i == 0) {
      push(@array, $i);
      $n = $n / $i;
      $i--;
    }
    else {;}
  }

  my @array = join('*', @array);
  return @array;
}

sub print_factors {
  print "arg = (". join('*', @_). ")\n";
}

1;
