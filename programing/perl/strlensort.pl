use strict;

my @array = qw/this that an is are apple/;

@array = sort {length($a) <=> length($b) || $a cmp $b} @array;

for(my $i=0; $i<=$#array; $i++) {
  printf "$array[$i]\n"
}
