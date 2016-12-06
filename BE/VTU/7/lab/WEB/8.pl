#!/usr/bin/perl


# Note : Do the following before execution
# 
# $ mysql -u root -p
# root123                      (password)
# 
# > CREATE DATABASE test;
# > use test;
# > CREATE TABLE Students (name TEXT, age INT);
#

use CGI':standard';
print "content-type:text/html\n\n";

use DBI;
$dbh = DBI->connect("DBI:mysql:test","username","password");
$name=param("name");
$age=param("age");
$sql="INSERT INTO Students VALUES('$name','$age')";
$sth=$dbh->prepare($sql);
$sth->execute;

$sql = "SELECT * FROM Students";
$sth = $dbh->prepare($sql);
$sth->execute;
print "<table border size=1>
<tr>
<th>Name</th>
<th>Age</th>
</tr>
";

while(($name,$age)=$sth->fetchrow())
{
	print "<tr>
	<td>$name</td>
	<td>$age</td>
	</tr>
	";
}

$sth->finish();
$dbh->disconnect();
print"</table>";

