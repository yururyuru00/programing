use strict;

my $s = "a afag";
printer($s);

sub printer {
  my $a = @_;
  print "@_\n";
  print "$$a";
}
