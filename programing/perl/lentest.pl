

my $str = "This is a pen. That is a pencil. I like English.";
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
for my $i (@strlist) {
  push(@{$list->[length($i)-1]}, $i);
}

print "@strlist\n";
print "@{$list[3]}";
