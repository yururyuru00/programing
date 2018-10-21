use strict;

my $s = "This is a pen. That is a pencil. I like English.";
my $lenlist = str2lenlist($s);
print "@{$lenlist->[1]}\n";
for my $len (1..$#$lenlist) {
my $list = defined $lenlist->[$len] ? join(' ', @{$lenlist->[$len]}) : '';
print "$len: $list\n";
}

sub str2lenlist {
  print "@_";
  my $str = @_;
  print "$str\n";
  my $list = [
  [],
  [],
  [],
  [],
  [],
  [],
  [],
  ];
  my @strlist = split(/[\s,.]+/, $str);
  print "@strlist";
  for my $i (@strlist) {
    print "$i";
    push(@{$list->[length($i)-1]}, $i);
  }
  print "@{$list->[3]}\n";
  return $list;
}
