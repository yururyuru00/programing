my $filename = 'test.txt';
open my $fh, '<', $filename or die "cannot open $filename";
my %num;
for my $i (@wordlist) {
  $num{$i} = 0;
}

while (<$fh>) {
  @wordlist = split(/[\s,.]+/, $_);

  for my $i (@wordlist) {
     ($num{$i})++;
  }
}

my $filename = 'test.csv';
open my $fh, '>', $filename or die "cannot open '$filename'";

for my $i (sort keys %num) {
    print $fh "$i = $num{$i} \n";
}
close $fh;
