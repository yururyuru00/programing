
use strict;
use warnings;

my $identifier;

for(my $i=0; $i<4; $i++) {
  warn "n= ";
  chomp(my $mail = <STDIN>);

  if($mail =~ /\.co\.jp$/) {
    $mail =~ s/.co.jp$/.com/;
    print "$mail\n";
  }
  else {print "$mail\n";}
}
