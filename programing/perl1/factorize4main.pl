#!/usr/bin/env perl
use strict;
use warnings;

require "factorize4.pl";

print_factors(1..5);

warn "n = ";
chomp(my $n = <STDIN>);
my @factors = factorize($n);
print_factors(@factors);
