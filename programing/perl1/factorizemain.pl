#!/usr/bin/env perl
use strict;
use warnings;
require "factorize3.pl";
warn "n = ";
chomp(my $n = <STDIN>);
factorize($n);
