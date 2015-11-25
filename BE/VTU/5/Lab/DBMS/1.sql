/*
Creating tables
*/

CREATE TABLE student(snum int(20),sname varchar(20),major varchar(20),LEVEL varchar(3),age int(3),PRIMARY key(snum));

CREATE TABLE faculty(fid int,fname varchar(20),deptid int(4),PRIMARY key(fid));

CREATE TABLE class(name varchar(20),meetsat varchar(20),room varchar(3),fid int,PRIMARY key(name),
						FOREIGN key(fid)REFERENCES faculty(fid));

CREATE TABLE enrolled(snum int,cname varchar(20),PRIMARY key(snum,cname),
						FOREIGN key(snum) REFERENCES student(snum),
						FOREIGN key(cname) REFERENCES class(name));

/* 
i) Find the names of all Juniors (level = JR) who are enrolled in a class taught by Prof. Harshith
*/

SELECT DISTINCT S.SNAME
FROM STUDENT S,
	CLASS C,
	ENROLLED E,
	FACULTY F
WHERE S.SNUM=E.SNUM
  AND E.CNAME = C.NAME
  AND C.FID = F.FID
  AND F.FNAME='Prof.Harshith'
  AND S.LEVEL = 'JR';



/*
ii) Find the names of all classes that either meet in room R128 or have five or more Students enrolled.
*/

SELECT C.NAME
FROM CLASS C
WHERE C.ROOM = 'R128'
  OR C.NAME IN
    (SELECT E.CNAME
	FROM ENROLLED E
	GROUP BY E.CNAME
	HAVING COUNT(*)>=5);


/*
iii) Find the names of all students who are enrolled in two classes that meet at the same time.
*/

SELECT C.CNO,
       T.ISBN,
       T.TITLE
FROM COURSE C,ADOPT A,TEXT T
WHERE C.CNO=A.CNO
	AND C.DEPT='CSE'
	AND A.ISBN=T.ISBN
	AND EXISTS
    (SELECT COUNT(A1.CNO)
	FROM ADOPT A1
	WHERE A1.CNO=C.CNO
	GROUP BY A1.CNO
	HAVING COUNT(*)>2)
ORDER BY C.CNO,
		T.ISBN,
		T.TITLE;


/*
iv) Find the names of faculty members who teach in every room in which some class is taught.
*/

SELECT FNAME
FROM FACULTY F,
	CLASS C
WHERE F.FID=C.FID
GROUP BY C.FID
HAVING COUNT(DISTINCT ROOM) =
  (SELECT COUNT(DISTINCT ROOM)
   FROM CLASS);

/*
v) Find the names of faculty members for whom the combined enrollment of the courses that they teach is less than five.
*/

SELECT DISTINCT F.FNAME
FROM FACULTY F
WHERE 5 >
    (SELECT COUNT(E.SNUM)
	FROM CLASS C,
		ENROLLED E
	WHERE C.NAME = E.CNAME
       AND C.FID = F.FID);