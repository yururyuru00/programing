while(<>) {
  chomp;
  $_ =~ /(\S+\s\S+) \s* (.+)/x;
  my $name = $1;
  my $pointlist = $2;
  my $sum = 0;
  my @points = split(/\s+/, $pointlist);
  @points = sort {$a <=> $b} @points;
  for(my $i=0; $i<3; $i++) {$sum += $points[$#points-$i];}
  print "$sum";
  my $ave= $sum / 3;
  printf "%-10s :", $name;
  printf "%5.1f", $ave;
  print "\n";
}
