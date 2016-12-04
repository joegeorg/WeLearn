set ns [new Simulator]
set trf [open 5.tr w]
$ns trace-all $trf
set naf [open 5.nam w]
$ns namtrace-all $naf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns make-lan "$n0 $n1 $n2 $n3 $n4" 100Mb 100ms LL Queue/DropTail Mac/802_3
$ns duplex-link $n4 $n5 1Mb 1ms DropTail

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
set sink5 [new Agent/TCPSink]
$ns attach-agent $n5 $sink5
set tcp2 [new Agent/TCP]
$ns attach-agent $n2 $tcp2
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
set sink3 [new Agent/TCPSink]
$ns attach-agent $n3 $sink3
$ns connect $tcp0 $sink5
$ns connect $tcp2 $sink3

$ftp2 set packetSize_ 600
$ftp2 set interval_ 0.001
$ftp0 set packetSize_ 500
$ftp0 set interval_ 0.0001

set f1 [open f1.tr w]
$tcp0 attach $f1
$tcp0 trace cwnd_
$tcp0 set maxcwnd_ 10
set f2 [open f2.tr w]
$tcp2 attach $f2
$tcp2 trace cwnd_

proc finish {} {
	global naf trf ns
	$ns flush-trace
	close $naf
	close $trf
	exit 0
}

$ns at 0.1 "$ftp0 start"
$ns at 5 "$ftp0 stop"
$ns at 7 "$ftp0 start"
$ns at 0.2 "$ftp2 start"
$ns at 8 "$ftp2 stop"
$ns at 14 "$ftp0 stop"
$ns at 10 "$ftp2 start"
$ns at 15 "$ftp2 stop"
$ns at 16 "finish"
$ns run