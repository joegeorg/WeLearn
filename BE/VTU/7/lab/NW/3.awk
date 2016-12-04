BEGIN{	
}{
if($1 == "d"){
count++;
}
}
END{
printf("No of packets dropped %d \n\n", count);
}