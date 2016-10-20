set ns [new Simulator]
set nf [open pro3.nam w]
$ns namtrace-all $nf
set tf [open pro3.tr w]
$ns trace-all $tf
proc finish {} {
	global ns nf tf
	$ns flush-trace
	close $nf
	close $tf
	exec nam pro3.nam &
	exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]

$ns duplex-link $n1 $n0 100mb 10ms DropTail
$ns duplex-link $n2 $n0 1mb 10ms DropTail
$ns duplex-link $n3 $n0 10mb 10ms DropTail
$ns duplex-link $n4 $n0 1mb 10ms DropTail
$ns duplex-link $n5 $n0 100kb 10ms DropTail
$ns duplex-link $n6 $n0 100kb 11ms DropTail

Agent/Ping instproc recv {from  rtt} {
	$self instvar node_
	puts "node [$node_ id] recieved pin answer from node
	$from round-trip-time $rtt ms"
}
set p1 [new Agent/Ping]
set p2 [new Agent/Ping]
set p3 [new Agent/Ping]
set p4 [new Agent/Ping]
set p5 [new Agent/Ping]
set p6 [new Agent/Ping] 

$ns attach-agent $n1 $p1
$ns attach-agent $n2 $p2
$ns attach-agent $n3 $p3
$ns attach-agent $n4 $p4
$ns attach-agent $n5 $p5
$ns attach-agent $n6 $p6

$ns queue-limit $n0 $n4 1
$ns queue-limit $n0 $n5 2
$ns queue-limit $n0 $n6 2

$p1 set packetSize_ 5000
$p1 set interval_ 0.0001
$p2 set packetSize_ 6000
$p2 set interval_ 0.00001
$p3 set packetSize_ 700
$p3 set interval_ 0.001

$ns connect $p1 $p4
$ns connect $p2 $p5
$ns connect $p3 $p6

$ns at 0.1 "$p1 send"
$ns at 0.2 "$p1 send"
$ns at 0.3 "$p1 send"
$ns at 0.4 "$p1 send"
$ns at 0.5 "$p1 send"
$ns at 0.6 "$p2 send"
$ns at 0.7 "$p1 send"
$ns at 0.8 "$p4 send"
$ns at 0.9 "$p1 send"
$ns at 1.0 "$p5 send"
$ns at 1.2 "$p1 send"
$ns at 1.3 "$p4 send"
$ns at 1.4 "$p1 send"
$ns at 0.6 "$p4 send"
$ns at 1.5 "$p6 send"
$ns at 2.0 "finish"
$ns run