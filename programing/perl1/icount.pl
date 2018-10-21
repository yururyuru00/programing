use strict;
use warnings;

my $counter;

for (my $i=0; $i<8; $i++) {
  warn "n= ";
  chomp(my $n = <STDIN>);
  $counter =0;
  my @int = (1..$n);
  for my $i (@int) {
    if($i =~ /3|12/) {$counter++;}
  }
  printf "%d 回目　$n : $counter 回出現\n", $i+1;
}
