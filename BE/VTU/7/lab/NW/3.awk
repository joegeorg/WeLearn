BEGIN{	
}{
event = $1;
if(event == "d"){
count++;
}
}
END{
printf("No of packets dropped %d \n\n", count);
}