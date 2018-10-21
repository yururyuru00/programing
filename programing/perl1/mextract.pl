use strict;
use warnings;

my $identifier;

for(my $i=0; $i<3; $i++) {
  warn "n= ";
  chomp(my $mail = <STDIN>);

  $mail =~ /^([\w\._]+)\@([\w\._-]+)/;
    my $a = $1;
    my $b = $2;
    print "$a $b\n";

}
