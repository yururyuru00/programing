use strict;

my @array = (1..19);

@array = grep { ($_%2) == 1} @array;
@array = map {$_*$_} @array;

for my $i (0..$#array) {
  printf "\$array[$i] == $array[$i]\n";
}
