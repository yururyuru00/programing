#!/use/bin/env perl
use strict;
use warnings;

require "factorize.pl";

chomp(my $n = <STDIN>);
factorize($n);
