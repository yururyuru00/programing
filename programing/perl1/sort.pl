use strict;


my @array = (9, 5, 7, 1, 3, 4, 6);

for(my $i=0; $i<=$#array-1; $i++) {
  for(my $j=$#array; $j>=$i+1; $j--) {
    if($array[$j-1]>$array[$j]) {
      my $str=$array[$j];
      $array[$j]=$array[$j-1];
      $array[$j-1]=$str;
    }
    else {;}
  }
}

print "\@array = (@array)\n";
