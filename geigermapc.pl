#!/usr/bin/perl

my %param = (
	id      => "abc",
	key     => "xxxxxxxxxx",
	url     => "http://drumsoft.com/gm/",
	readusb => "./read-usb-geiger"
);

use strict;
use warnings;

use LWP::UserAgent;
use Digest::SHA1;
use CGI::Util;

sub main() {
	my ($usb, $result, $pid);
	local $/; undef $/;

	$pid = open($usb, "$param{'readusb'} |") or die "cannot open $param{'readusb'}";
	$SIG{ALRM} = sub { kill 9, $pid; die "$param{'readusb'} timeouted."; };
	alarm(10);
	$result = <$usb>;
	alarm(0);
	close($usb);

	if ($result =~ /(\d+),(\d+),(\d+)/) {
		post($1, $2, $3);
	}else{
		die "$param{'readusb'} error: $result";
	}
}

sub post($$$){
	my ($measured_time, $mcount, $mtime) = @_;
	my %send = (
		action => "Post",
		id     => $param{"id"},
		measured_time => $measured_time,
		count  => $mcount,
		time   => $mtime,
		hash   => createhash($param{"id"},$measured_time,$mcount,$mtime,$param{"key"})
	);

	my $url = $param{"url"} . "?" . encodeparameters(\%send);
	my $ua = LWP::UserAgent->new;
	$ua->timeout(50);
	my $response = $ua->get($url);

	if (!$response->is_success) {
		die "server error: " . $response->content;
	}
}

sub encodeparameters($) {
	my $hash = shift;
	return join '&', map {
		CGI::Util::escape($_) . '=' . CGI::Util::escape($hash->{$_})
	} keys %$hash;
}

sub createhash(@) {
	return Digest::SHA1::sha1_hex(join ':', @_);
}

main();
