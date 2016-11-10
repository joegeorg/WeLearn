set ns [new Simulator]
set trf [open 8.tr w]
$ns trace-all $trf
set namf [open 8.nam w]
$ns namtrace-all $namf
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
$ns color 1 "red"
$ns color 2 "green"
$n0 label "source1-tcp-ftp"
$n1 label "source2-udp-cbr"
$n2 label "Router"
$n3 label "destination"
$ns duplex-link $n0 $n2 100kb 1ms DropTail
$ns duplex-link $n1 $n2 100kb 1ms DropTail
$ns duplex-link $n2 $n3 100kb 1ms DropTail
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
set sink3 [new Agent/TCPSink]
$ns attach-agent $n3 $sink3
set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
set nul3 [new Agent/Null]
$ns attach-agent $n3 $nul3
$ftp0 set packetSize_ 200
$ftp0 set interval_ 0.1
$cbr1 set packetSize_ 200
$cbr1 set interval_ 0.1
$tcp0 set class_ 1
$udp1 set class_ 2
$ns connect $tcp0 $sink3
$ns connect $udp1 $nul3
proc finish { } {
	global ns namf trf
	$ns flush-trace
	close $namf
	close $trf
	exit 0
}
$ns at 0.1 "$cbr1 start"
$ns at 0.3 "$ftp0 start"
$ns at 9.0 "$cbr1 stop"
$ns at 9.3 "$ftp0 stop"
$ns at 10.0 "finish"
$ns run

