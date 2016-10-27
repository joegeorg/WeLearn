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
$ns make-lan "$n0 $n1 $n2 $n3 $n4" 10Mb 10ms LL Queue/DropTail Mac/802_3
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
set sink2 [new Agent/TCPSink]
$ns attach-agent $n2 $sink2
$ns connect $tcp0 $sink2

set tcp3 [new Agent/TCP]
$ns attach-agent $n3 $tcp3
set ftp3 [new Application/FTP]
$ftp3 attach-agent $tcp3
set sink4 [new Agent/TCPSink]
$ns attach-agent $n4 $sink4
$ns connect $tcp3 $sink4
#To build the congestion window
set f1 [open f1.tr w]
$tcp0 attach $f1
$tcp0 trace cwnd_
$tcp0 set maxcwnd_ 10
set f2 [open f2.tr w]
$tcp3 attach $f2
$tcp3 trace cwnd_

proc finish { } {
global naf trf ns
$ns flush-trace
close $naf
close $trf
exit 0
}
$ns at 0.1 "$ftp0 start"
$ns at 1.5 "$ftp0 stop"
$ns at 2 "$ftp0 start"
$ns at 3 "$ftp0 stop"
$ns at 0.2 "$ftp3 start"
$ns at 2 "$ftp3 stop"
$ns at 2.5 "$ftp3 start"
$ns at 4.0 "$ftp3 stop"
$ns at 6.0 "finish"
$ns run

