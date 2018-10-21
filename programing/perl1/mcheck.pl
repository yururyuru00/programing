use strict;
use warnings;

my $identifier;

for(my $i=0; $i<5; $i++) {
  warn "n= ";
  $identifier=1;
  chomp(my $mail = <STDIN>);
  my @parts = split(/\@/, $mail);

  if($#parts >1) {$identifier=0;}
  else {;}
  if($mail =~ /(\W)(\W+)/) {$identifier=0;}
  else {;}
  printf "$mail :";
  if($identifier==1) {printf "true\n";}
  else {printf "false\n";}
}
