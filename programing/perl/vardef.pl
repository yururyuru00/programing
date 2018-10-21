#!/usr/bin/env perl
use strict;
use warnings;

my $price = 198000;
my $count = 9;
my $item = "PC";
print "$item 1台 $price　円\n";
print "$count 台買うと　". ($price*$count). " 円 \n";
$price = "$count　台以上買ってくれたらタダ";
print "でも $price\n";
