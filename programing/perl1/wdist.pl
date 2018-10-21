use strict;
use warnings;

my $s = 'this is a pen that is a pencil that he used';
wdist($s);

sub wdist {
 my ($strings) = @_;
 my @string = split(/ /, $strings);

 my %num;

 for my $i (@string) {
   print "$i ";
 }
 print "\n";

 for my $i (@string) {
   $num{$i} = 0;
 }


 for my $i (@string) {
    ($num{$i})++;
  }

  for my $i (sort keys %num) {
     print "$i = $num{$i} \n";
   }

  print "\n";
}
