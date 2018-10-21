#!/use/bin/env perl
use strict;
use warnings;

my $str = 'perl';
my $w;

chomp($w = <STDIN>);
print "w = '$w'\n";

if( ($w cmp $str) == -1) {print "before";}
elsif( ($w cmp $str) == 1) {print "after";}
else {print "congulatulation!";}

print "\n";
