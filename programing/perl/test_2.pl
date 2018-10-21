my $filename = 'test.txt';
open my $fh, '<', $filename or die "cannot open ’$filename’";
while (<$fh>) {
print;
}
close $fh;
