use strict;
use warnings;

my %person1 = (height=>170, weight=>60);
printf "%6.2f\n", bmi(%person1);

my %person2 = (height=>155, weight=>43);
printf "%6.2f\n", bmi(%person2);

sub bmi {
  my %data = @_;
  my $m = $data{'height'}/100;
  return $data{'weight'}/$m/$m;
}
