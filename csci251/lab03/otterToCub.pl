#!/usr/bin/perl
# Udp line echo client 
# terminates when "CLOSE\n" is sent
# Peter Walsh csci 251


use IO::Socket;

$sock = new IO::Socket::INET (
                              PeerAddr => '192.168.18.45',
                              PeerPort => '7072',
                              Proto => 'udp',
                              Reuse => 1
                              );
die "Could not create socket: $!\n" unless $sock;

print "Enter text to be sent to server followed by crlf\n";
print "Enter CLOSE followed by crlf to close the connection\n";

$line=<>;
while ($line ne "CLOSE\n") {
   $sock->send($line);
   $sock->send($buff);
   $line=<>;
}

close($sock);
