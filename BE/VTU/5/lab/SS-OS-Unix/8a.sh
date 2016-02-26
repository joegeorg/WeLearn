ls -l $1| cut -d " " -f1>file1per
ls -l $2| cut -d " " -f1>file2per
if cmp file1per file2per
then
echo "$1 and $2 are having same permission"
cat file1per
else
echo "$1 and $2 having different permission"
echo "$1 permission are"
cat file1per
echo "$2 permission are"
cat file2per
fi
