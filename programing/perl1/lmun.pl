my $buffo = 0;
while(<>) {
  $buffo++;
  print "$buffo: ";
  print $_;
}
