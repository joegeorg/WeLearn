#!/usr/bin/perl
use CGI':standard';
print "Content-type:text/html\n\n";
print "Server Name : $ENV{'SERVER_NAME'}\n";
print "Server Port : $ENV{'SERVER_PORT'}\n";
print "Server Software : $ENV{'SERVER_SOFTWARE'}\n";
print "Server Interface : $ENV{'SERVER_INTERFACE'}\n";
print "Gateway Interface : $ENV{'GATEWAY_INTERFACE'}\n";
print "Server Protocol : $ENV{'SERVER_PROTOCOL'}\n";