use strict;
use warnings;

my $identifier;

for(my $i=0; $i<4; $i++) {
  warn "n= ";
  chomp(my $mail = <STDIN>);

  if($mail =~ /-/) {
    $mail =~ s/-//g;
    print "$mail\n";
  }
  else {print "$mail\n";}
}
