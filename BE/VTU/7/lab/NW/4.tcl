set ns [new Simulator]
set trf [open 4.tr w]
$ns trace-all $trf
set naf [open 4.nam w]
$ns namtrace-all $naf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]

$ns make-lan "$n0 $n1 $n2 $n3" 100Mb 300ms LL 
Queue/DropTail Mac/802_3
$ns make-lan "$n4 $n5 $n6 $n7" 100Mb 300ms LL 
Queue/DropTail Mac/802_3
$ns duplex-link $n3 $n4 100Mb 300ms DropTail
$ns duplex-link-op $n3 $n4 color "green"

set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
set null7 [new Agent/Null]
$ns attach-agent $n7 $null7

$ns connect $udp1 $null7
$cbr1 set packetSize_ 1000
$cbr1 set interval_ 0.0001
$cbr1 set fid_ 0
set err [new ErrorModel]
$ns lossmodel $err $n3 $n4
$err set rate_ 0.1

proc finish {} {
global naf ns trf
close $naf
close $trf
exit 0
}

$ns at 0.1 "$cbr1 start"
$ns at 5.4 "$cbr1 stop"
$ns at 6.0 "finish"
$ns run
