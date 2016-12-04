set ns [new Simulator]
set trf [open 1.tr w]
$ns trace-all $trf
set namf [open 1.nam w]
$ns namtrace-all $namf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns color 1 "red"
$n0 label "source/udp0"
$n2 label "destination"

$ns duplex-link $n0 $n1 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 150kb 10ms DropTail
$ns set queue-limit $n1 $n2 5

set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

set null0 [new Agent/Null]
$ns attach-agent $n2 $null0

$udp0 set class_ 1
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.01

$ns connect $udp0 $null0

proc finish { } {
	global ns namf trf
	$ns flush-trace
	exec nam 1.nam &
	close $trf
	close $namf
	exit 0
}

$ns at 0.1 "$cbr0 start"
$ns at 9.5 "$cbr0 stop"
$ns at 10.0 "finish"
$ns run